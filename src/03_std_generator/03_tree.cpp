#include <coroutine>
#include <generator>
#include <iostream>

template <typename T>
struct Tree {
  T value;
  Tree* left{};
  Tree* right{};

  std::generator<const T&> InorderTraverse() const {
    if (left) {
      co_yield std::ranges::elements_of(left->InorderTraverse());
    }

    co_yield value;

    if (right) {
      co_yield std::ranges::elements_of(right->InorderTraverse());
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

  for (char x : tree->InorderTraverse()) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
}
