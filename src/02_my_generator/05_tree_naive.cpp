#include <iostream>

#include "generator.hpp"

template <typename T>
struct Tree {
  T value;
  Tree* left{};
  Tree* right{};

  struct InorderIterator;

  InorderIterator begin() { return InorderIterator(this); }
  InorderIterator end() { return InorderIterator(nullptr); }
};

template <typename T>
struct Tree<T>::InorderIterator {
  Tree* current;
  std::stack<Tree*> path;

  explicit InorderIterator(Tree* root) : current(root) { PushLeft(current); }

  void PushLeft(Tree* node) {
    while (node) {
      path.push(node);
      node = node->left;
    }
    if (!path.empty()) {
      current = path.top();
    } else {
      current = nullptr;
    }
  }

  const T& operator*() const { return current->value; }

  InorderIterator& operator++() {
    if (path.empty()) {
      current = nullptr;
      return *this;
    }

    Tree* node = path.top();
    path.pop();

    if (node->right) {
      PushLeft(node->right);
    } else if (!path.empty()) {
      current = path.top();
    } else {
      current = nullptr;
    }

    return *this;
  }

  bool operator!=(const InorderIterator& other) const {
    return current != other.current;
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

  for (auto it = tree->begin(); it != tree->end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << '\n';
}
