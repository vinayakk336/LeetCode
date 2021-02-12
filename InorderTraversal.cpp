#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorderHelper(TreeNode* root, vector<int> &trav);
vector<int> inorderTraversal(TreeNode* root);

void inorderHelper(TreeNode* root, vector<int> &trav) {
    if(root) {
        if(root->left)
            inorderHelper(root->left, trav);
        trav.push_back(root->val);
        if(root->right)
            inorderHelper(root->right, trav);
    }
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> traversal;
    inorderHelper(root, traversal);
    return traversal;
}

int main() {
    /*
       1
        \
         2
        /
       3
     Expected output: 1 3 2
     */
    TreeNode* tree1 = new TreeNode(1);
    tree1->right = new TreeNode(2);
    tree1->right->left = new TreeNode(3);
    
    vector<int> soln = inorderTraversal(tree1);
    
    for(int e : soln)
        cout << e << ' ';
    
    return 0;
}
