#include <iostream>

#include "generator.hpp"

Generator<int> FibonacciLazy() {
  int a = 0;
  int b = 1;
  while (true) {
    co_yield a;
    int next = a + b;
    a = b;
    b = next;
  }
}

void PrintFibonacci(int limit) {
  for (int x : FibonacciLazy()) {
    if (x > limit) {
      break;
    }
    std::cout << x << ' ';
  }
  std::cout << '\n';
}


int main() {
  PrintFibonacci(10);
}
