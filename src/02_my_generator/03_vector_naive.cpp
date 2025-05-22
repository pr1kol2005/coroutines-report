#include <iostream>
#include <vector>

template <typename T>
std::vector<T> MergeVectors(const std::vector<T>& lhs,
                            const std::vector<T>& rhs) {
  std::vector<T> result;
  result.reserve(lhs.size() + rhs.size());

  for (const auto& elem : lhs) {
    result.push_back(elem);
  }
  for (const auto& elem : rhs) {
    result.push_back(elem);
  }

  return result;
}

template <typename T>
std::vector<T> InterleaveVectors(const std::vector<T>& lhs,
                                 const std::vector<T>& rhs) {
  std::vector<T> result;
  result.reserve(lhs.size() + rhs.size());

  size_t n = std::max(lhs.size(), rhs.size());
  for (size_t i = 0; i < n; ++i) {
    if (i < lhs.size()) {
      result.push_back(lhs[i]);
    }
    if (i < rhs.size()) {
      result.push_back(rhs[i]);
    }
  }

  return result;
}

int main() {
  std::vector<int> first{0, 0, 0};
  std::vector<int> second{1, 1, 1};

  for (const auto& elem : MergeVectors(first, second)) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';

  for (const auto& elem : InterleaveVectors(first, second)) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
}
