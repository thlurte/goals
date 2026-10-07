// ==============================================================================
// 🥋 Drill 01 (Week 01 / Day 001): Information Theory — Entropy & Mutual
// Information
//
// 📖 READING SOURCES:
// - Thomas M. Cover & Joy A. Thomas: Elements of Information Theory (Ch 1 &
// Ch 2.1–2.3)
//
// 🎯 CORE LESSON:
// 1. Shannon Entropy: H(X) = - sum_{x} p(x) * log2(p(x))
//    Measures the average information content (in bits) of a discrete
//    probability distribution.
// 2. Guarding against 0 * log2(0): By continuity, lim_{p -> 0} p * log2(p) = 0.
// 3. Mutual Information: I(X; Y) = H(X) + H(Y) - H(X, Y)
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra -Wconversion
// drill_01_day001_information_theory_entropy.cpp -o drill01 && ./drill01
// ==============================================================================

#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

// TODO 1: Implement Shannon Entropy in bits (base 2)
// For each probability p in probs:
// If p > 0: sum -= p * log2(p)
// Ignore p == 0 (since 0 * log2(0) = 0)
double shannon_entropy(const std::vector<double> &probs) {
  // [YOUR CODE HERE]
  double sum{0.0};
  for (size_t i = 0; i < probs.size(); ++i) {
    if (probs[i] > 0) {
      sum -= probs[i] * std::log2(probs[i]);
    }
  }
  return sum;
}

// TODO 2: Compute Mutual Information I(X; Y)
// I(X; Y) = H(X) + H(Y) - H(X, Y)
double mutual_information(const std::vector<double> &prob_x,
                          const std::vector<double> &prob_y,
                          const std::vector<double> &joint_prob_xy) {
  // [YOUR CODE HERE]
  if (prob_x.size() * prob_y.size() != joint_prob_xy.size()) {
    throw std::invalid_argument("Dimension mismatch: joint_prob_xy size must "
                                "equal prob_x.size() * prob_y.size()!");
  }
  double h_x = shannon_entropy(prob_x);
  double h_y = shannon_entropy(prob_y);
  double h_xy = shannon_entropy(joint_prob_xy);
  return h_x + h_y - h_xy;
}

int main() {
  std::cout
      << "--- Week 01 Drill 01: Information Theory & Shannon Entropy ---\n\n";

  // Fair coin: p = [0.5, 0.5] -> H(X) = 1.0 bit
  std::vector<double> fair_coin = {0.5, 0.5};
  double h_fair = shannon_entropy(fair_coin);
  std::cout << "Fair Coin Entropy: " << h_fair << " bits (Expected: 1.0)\n";
  assert(std::abs(h_fair - 1.0) < 1e-6);

  // Biased coin: p = [0.9, 0.1] -> H(X) approx 0.468995 bits
  std::vector<double> biased_coin = {0.9, 0.1};
  double h_biased = shannon_entropy(biased_coin);
  std::cout << "Biased Coin Entropy: " << h_biased << " bits\n";
  assert(std::abs(h_biased - 0.468995) < 1e-4);

  // Uniform 4-state: p = [0.25, 0.25, 0.25, 0.25] -> H(X) = 2.0 bits
  std::vector<double> uniform4 = {0.25, 0.25, 0.25, 0.25};
  assert(std::abs(shannon_entropy(uniform4) - 2.0) < 1e-6);

  std::cout << "\n✓ Week 01 Drill 01 Passed Successfully!\n";
  return 0;
}
