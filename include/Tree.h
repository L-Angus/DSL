#ifndef __TREE_HPP__
#define __TREE_HPP__

#include <functional>
#include <iostream>
#include <vector>

// // 定义树节点
// template <typename T> struct TreeNode {
//   T value;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode(T val) : value(val), left(nullptr), right(nullptr) {}
// };
// template <typename T, typename Compare = std::less<T>> class BSTree {
// public:
//   BSTree() : root(nullptr) {}
//   ~BSTree() {}

//   void NonRecursiveInsert(T val) {
//     // if root is null, create a new node and set it as root
//     if (root == nullptr) {
//       root = new TreeNode<T>(val);
//       return;
//     } else {
//       TreeNode<T> *parent = nullptr;
//       TreeNode<T> *current = root;
//       while (current) {
//         if (!Compare(current->value, val)) {
//           parent = current;
//           current = current->left;
//         } else if (Compare(current->value, val)) {
//           parent = current;
//           current = current->right;
//         } else {
//           return; // 值已存在，不插入
//         }
//       }
//       if (!Compare(parent->value, val)) {
//         parent->left = new TreeNode<T>(val);
//       } else {
//         parent->right = new TreeNode<T>(val);
//       }
//     }
//   }

// private:
//   TreeNode<T> *root; //根节点
// };

// struct TreeNode {
//   int value;
//   int parent;
//   TreeNode(int val, int par) : value(val), parent(par) {}
// };
// void addNode(std::vector<TreeNode> &tree, int value, int parentIndex) {
//   tree.emplace_back(value, parentIndex);
// }

// void TestParent() {
//   std::vector<TreeNode> tree;
//   // 创建根结点，根结点的父节点为-1
//   addNode(tree, 1, -1); // 索引 0
//   addNode(tree, 2, 0);  // 索引 1
//   addNode(tree, 3, 0);  // 索引 2
//   addNode(tree, 4, 1);  // 索引 3
//   addNode(tree, 5, 1);  // 索引 4

//   for (size_t i = 0; i < tree.size(); ++i) {
//     std::cout << "Node value: " << tree[i].value;
//     if (tree[i].parent != -1) {
//       std::cout << ", parent value: " << tree[tree[i].parent].value;
//     } else {
//       std::cout << ", This is the root node.";
//     }
//     std::cout << std::endl;
//   }

//   return;
// }

// struct TreeNode {
//   int value; // 节点的值, 可以是任意类型，这里使用int作为演示
//   std::vector<TreeNode *> children; // 子节点列表，存储当前所有子节点的指针
//   TreeNode(int val) : value(val) {}
// };

// void addNode(TreeNode *parent, TreeNode *child) {
//   parent->children.push_back(child);
// }

// void TestChildren() {
//   TreeNode *root = new TreeNode(1);
//   TreeNode *child1 = new TreeNode(2);
//   TreeNode *child2 = new TreeNode(3);
//   TreeNode *child3 = new TreeNode(4);
//   TreeNode *child4 = new TreeNode(5);
//   TreeNode *child5 = new TreeNode(6);
//   TreeNode *child6 = new TreeNode(7);
//   TreeNode *child7 = new TreeNode(8);
//   // 构建树
//   addNode(root, child1);
//   addNode(root, child2);
//   addNode(root, child3);
//   addNode(child2, child4);
//   addNode(child2, child5);
//   addNode(child1, child6);
//   addNode(child3, child7);

//   std::vector<TreeNode *> nodes;
//   nodes.push_back(root);
//   nodes.push_back(child1);
//   nodes.push_back(child2);
//   nodes.push_back(child3);

//   // 输出根节点的子节点值
//   for (auto node : nodes) {
//     for (auto child : node->children) {
//       std::cout << "parent value: " << node->value
//                 << ", Child value: " << child->value << std::endl;
//     }
//   }

//   // 释放内存（在实际应用中应注意内存管理）
//   delete root;
//   delete child1;
//   delete child2;
//   delete child3;
//   delete child4;
//   delete child5;
//   delete child6;
//   delete child7;
//   return;
// }

struct TreeNode {
  int value; // 节点的值, 可以是任意类型，这里使用int作为演示
  TreeNode *firstChild;
  TreeNode *nextSibling;
  TreeNode(int val) : value(val), firstChild(nullptr), nextSibling(nullptr) {}
};

void addChild(TreeNode *parent, TreeNode *child) {
  if (!parent->firstChild) {
    parent->firstChild = child;
  } else {
    TreeNode *current = parent->firstChild;
    while (current->nextSibling) {
      current = current->nextSibling;
    }
    current->nextSibling = child;
  }
}

void PrintTree(TreeNode *node) {
  if (!node)
    return;
  std::cout << "node value: " << node->value;
  if (node->firstChild) {
    std::cout << ", " << node->value << " has child: ";
    std::cout << node->firstChild->value;
    TreeNode *sibling = node->firstChild->nextSibling;
    while (sibling) {
      std::cout << ", " << sibling->value;
      sibling = sibling->nextSibling;
    }
  } else {
    std::cout << ", " << node->value << " has no child!";
  }
  std::cout << std::endl;
  PrintTree(node->firstChild);
  PrintTree(node->nextSibling);
}

void TestSibling() {
  // 创建节点
  TreeNode *root = new TreeNode(1);
  TreeNode *child1 = new TreeNode(2);
  TreeNode *child2 = new TreeNode(3);
  TreeNode *child3 = new TreeNode(4);
  TreeNode *child1_1 = new TreeNode(5);
  TreeNode *child2_1 = new TreeNode(6);
  TreeNode *child2_2 = new TreeNode(7);
  TreeNode *child2_3 = new TreeNode(8);
  TreeNode *child3_1 = new TreeNode(9);

  // 构建树
  addChild(root, child1);
  addChild(root, child2);
  addChild(root, child3);
  addChild(child1, child1_1);
  addChild(child2, child2_1);
  addChild(child2, child2_2);
  addChild(child2, child2_3);
  addChild(child3, child3_1);

  // 打印
  PrintTree(root);

  // 释放内存（在实际应用中应注意内存管理）
  delete root;
  delete child1;
  delete child2;
  delete child3;
  delete child1_1;
  delete child2_1;
  delete child2_2;
  delete child2_3;
  delete child3_1;

  return;
}

#endif