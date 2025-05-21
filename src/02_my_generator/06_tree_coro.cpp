#include <coroutine>
#include <iostream>

#include "generator.hpp"
 
template<typename T>
struct Tree {
  T value;
  Tree* left{};
  Tree* right{};

  Generator<const T&> traverse_inorder() const {
    if (left) {
      for (const auto& val : left->traverse_inorder()) {
        co_yield val;
      }
    }

    co_yield value;

    if (right) {
      for (const auto& val : right->traverse_inorder()) {
        co_yield val;
      }
    }
  }
};
 
int main() {
  Tree<char> tree[]
  {
                                  {'D', tree + 1, tree + 2},
      //                            │
      //            ┌───────────────┴────────────────┐
      //            │                                │
                  {'B', tree + 3, tree + 4},       {'F', tree + 5, tree + 6},
      //            │                                │
      //  ┌─────────┴─────────────┐      ┌───────────┴─────────────┐
      //  │                       │      │                         │
        {'A'},                  {'C'}, {'E'},                    {'G'}
  };
 
  for (char x : tree->traverse_inorder()) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
}
