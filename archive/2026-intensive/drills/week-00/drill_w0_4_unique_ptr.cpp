#include <iostream>
#include <typeinfo>
template <typename T> void my_swap(T &a, T &b) {
  auto q = a;
  a = b;
  b = q;
}

template <typename T> class Box {
public:
  explicit Box(T val) : box_(val) {};

  const T &get() const { return box_; }

  void set(T val) { box_ = val; }

private:
  T box_;
};

int main() {

  Box<int> a = 16;
  std::cout << a.get() << std::endl;
  std::cout << typeid(a.get()).name();
  return 0;
}
