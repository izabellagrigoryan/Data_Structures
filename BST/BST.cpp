
// BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BST 
{
public:
    TreeNode* root;

    TreeNode* insertHelper(TreeNode* root, int key) {
        if (root == NULL)
            return new TreeNode(key);
        if (key < root->val)
            root->left = insertHelper(root->left, key);
        else if (key > root->val)
            root->right = insertHelper(root->right, key);
        return root;
    }
 
    BST() {
        root = NULL;
    }

    void insert(int key) 
    {
        root = insertHelper(root, key);
    }

    TreeNode* search(TreeNode* root, int key) 
    {
        if (root == NULL || root->val == key)
            return root;
        if (key < root->val)
            return search(root->left, key);

        return search(root->right, key);
    }

    void preorder(TreeNode* root) 
    {
        if (root != NULL) 
        {
            cout << root->val << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(TreeNode* root) 
    {
        if (root != NULL) 
        {
            inorder(root->left);
            cout << root->val << " ";
            inorder(root->right);
        }
    }

    void postorder(TreeNode* root) 
    {
        if (root != NULL) 
        {
            postorder(root->left);
            postorder(root->right);
            cout << root->val << " ";
        }
    }

    void dfs(TreeNode* root) 
    {
        if (root != NULL)
        {
            dfs(root->left);
            dfs(root->right);
            cout << root->val << " ";
        }
    }
};

int main() {
    BST bst;
    bst.insert(16);
    bst.insert(12);
    bst.insert(20);
    bst.insert(10);
    bst.insert(14);
    bst.insert(18);
    bst.insert(22);
    bst.insert(9);
    bst.insert(11);
    bst.insert(13);
    bst.insert(15);
    bst.insert(17);
    bst.insert(19);
    bst.insert(21);
    bst.insert(23);

    bst.dfs(bst.root);

    cout << endl;
    cout << "Inorder traversal: ";
    bst.inorder(bst.root);
    cout << endl;
    cout << "Preorder traversal: ";
    bst.preorder(bst.root);
    cout << endl;
    cout << "Postorder traversal: ";
    bst.postorder(bst.root);
    cout << endl;
    int search_value = 30;
    TreeNode* result = bst.search(bst.root, search_value);
    if (result)
        cout << search_value << " found in the BST." << endl;
    else
        cout << search_value << " not found in the BST." << endl;

    return 0;
}
