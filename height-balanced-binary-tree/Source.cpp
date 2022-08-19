#include <iostream>
#include <vector>

using namespace std;


// This is an input class. Do not edit.
class BinaryTree {
public:
    int value;
    BinaryTree* left = nullptr;
    BinaryTree* right = nullptr;

    BinaryTree(int value) { this->value = value; }
};

struct TreeInfo
{
    bool isBalanced;
    int height;
};


TreeInfo getTreeInfo(BinaryTree* node);
bool heightBalancedBinaryTree(BinaryTree* tree);

int main()
{
    auto root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->left = new BinaryTree(4);
    root->left->right = new BinaryTree(5);
    root->right->right = new BinaryTree(6);
    root->left->right->left = new BinaryTree(7);
    root->left->right->right = new BinaryTree(8);

    cout << boolalpha << heightBalancedBinaryTree(root) << " ";
    return 0;
}

bool heightBalancedBinaryTree(BinaryTree* tree) {
    // Write your code here.

    auto treeInfo = getTreeInfo(tree);
    return treeInfo.isBalanced;
}

TreeInfo getTreeInfo(BinaryTree* node)
{
    if (node == nullptr)
        return TreeInfo{ true, 1 };

    auto leftSubtreeInfo = getTreeInfo(node->left);
    auto rightSubtreeInfo = getTreeInfo(node->right);

    bool isBalanced = leftSubtreeInfo.isBalanced && rightSubtreeInfo.isBalanced &&
        abs(leftSubtreeInfo.height - rightSubtreeInfo.height) <= 1;

    int height = max(leftSubtreeInfo.height, rightSubtreeInfo.height) + 1;
    return TreeInfo{ isBalanced, height };
}

