// ==============================================================================
// 🥋 Drill 12 (Day 34.4): Modern C++ RAII — POSIX `mmap` Zero-Copy File View
//
// 📖 READING SOURCES:
// - Kerrisk: The Linux Programming Interface (Ch 49: Memory Mappings & mmap)
// - Love: Linux System Programming (Ch 4: Advanced File I/O)
//
// 🎯 CORE LESSON:
// 1. RAII wrapper around file descriptor (`open`/`close`) and virtual memory mapping (`mmap`/`munmap`).
// 2. `MAP_SHARED` vs `MAP_PRIVATE`, `PROT_READ`, and `madvise` page cache hints (`MADV_SEQUENTIAL`, `MADV_WILLNEED`).
// 3. Exception-safe resource cleanup: if `mmap` fails, the open fd must be closed without leaking.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_12_day034_raii_posix_mmap.cpp -o drill12 && ./drill12
// ==============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <cassert>
#include <cstring>
#include <utility>
#include <span>

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

class MMapFile {
public:
    MMapFile() noexcept = default;

    explicit MMapFile(const std::string& path) {
        open_and_map(path);
    }

    ~MMapFile() noexcept {
        unmap_and_close();
    }

    // Non-copyable
    MMapFile(const MMapFile&) = delete;
    MMapFile& operator=(const MMapFile&) = delete;

    // TODO 1: Implement Move Constructor
    // - Steal addr_, length_, and fd_ from other using std::exchange
    // - Leave other in a valid empty state (addr_ = nullptr, length_ = 0, fd_ = -1)
    MMapFile(MMapFile&& other) noexcept 
        // [YOUR CODE HERE]
        : addr_(nullptr), length_(0), fd_(-1) {}

    // TODO 2: Implement Move Assignment Operator
    // - Check for self-assignment (this != &other)
    // - Unmap and close existing resources (unmap_and_close())
    // - Steal resources from other using std::exchange
    MMapFile& operator=(MMapFile&& other) noexcept {
        // [YOUR CODE HERE]
        return *this;
    }

    void open_and_map(const std::string& path) {
        unmap_and_close();

        fd_ = ::open(path.c_str(), O_RDONLY);
        if (fd_ == -1) {
            throw std::runtime_error("MMapFile: Failed to open file: " + path);
        }

        struct stat sb;
        if (::fstat(fd_, &sb) == -1) {
            ::close(fd_);
            fd_ = -1;
            throw std::runtime_error("MMapFile: Failed to fstat file: " + path);
        }

        length_ = static_cast<size_t>(sb.st_size);
        if (length_ == 0) {
            return; // Empty file
        }

        void* mapped = ::mmap(nullptr, length_, PROT_READ, MAP_SHARED, fd_, 0);
        if (mapped == MAP_FAILED) {
            ::close(fd_);
            fd_ = -1;
            length_ = 0;
            throw std::runtime_error("MMapFile: Failed to mmap file: " + path);
        }

        addr_ = static_cast<uint8_t*>(mapped);
        ::madvise(addr_, length_, MADV_SEQUENTIAL);
    }

    void unmap_and_close() noexcept {
        if (addr_ != nullptr && addr_ != MAP_FAILED) {
            ::munmap(addr_, length_);
            addr_ = nullptr;
        }
        if (fd_ != -1) {
            ::close(fd_);
            fd_ = -1;
        }
        length_ = 0;
    }

    [[nodiscard]] const uint8_t* data() const noexcept { return addr_; }
    [[nodiscard]] size_t size() const noexcept { return length_; }
    [[nodiscard]] bool is_open() const noexcept { return addr_ != nullptr; }

    [[nodiscard]] std::span<const uint8_t> span() const noexcept {
        return {addr_, length_};
    }

private:
    uint8_t* addr_{nullptr};
    size_t length_{0};
    int fd_{-1};
};

int main() {
    std::cout << "--- Drill 12: RAII POSIX mmap File Mapping ---\n\n";

    // 1. Create a dummy test binary file
    const std::string test_file = "test_mmap_dummy.bin";
    {
        std::ofstream ofs(test_file, std::ios::binary);
        const uint32_t magic = 0xDEADBEEF;
        const float payload[] = {1.5f, 2.5f, 3.5f, 4.5f};
        ofs.write(reinterpret_cast<const char*>(&magic), sizeof(magic));
        ofs.write(reinterpret_cast<const char*>(payload), sizeof(payload));
    }

    // 2. Open via RAII MMapFile
    {
        MMapFile file(test_file);
        assert(file.is_open());
        assert(file.size() == sizeof(uint32_t) + 4 * sizeof(float));

        uint32_t read_magic = *reinterpret_cast<const uint32_t*>(file.data());
        assert(read_magic == 0xDEADBEEF);
        std::cout << "✓ Read magic header: 0x" << std::hex << read_magic << std::dec << "\n";

        // Move ownership
        MMapFile moved_file = std::move(file);
        assert(!file.is_open());
        assert(moved_file.is_open());
        std::cout << "✓ Move semantics verified for mmap file!\n";
    }

    // Clean up file
    std::remove(test_file.c_str());
    std::cout << "\n✓ Drill 12 Passed: RAII mmap fully operational with 0 leaks!\n";
    return 0;
}
