// c++ program to construct tree using 
// inorder and levelorder traversals
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int key;
        Node *left, *right;
        Node(int x) {
            key = x;
            left = nullptr;
            right = nullptr;
        }
};

// Function to find the index of an element.
int searchValue(vector<int> in, int value, int s, int e) {
    
    for (int i=s; i<=e; i++) {
        if (in[i] == value)
            return i;
    }
    return -1;
}

// Recursive function to build the binary tree.
Node* buildTreeRecur(vector<int> in, 
                     vector<int> level, int s, int e) {
    
    // For empty array, return null
    if (s>e) {
        return nullptr;
    }
    
    // create the root Node
    Node* root = new Node(level[0]);
    
    // find the index of first element of level array
    // in the in-order array.
    int index = searchValue(in, level[0], s, e);
    
    int lCnt = index-s, rCnt = e - index;
    
    // Level order array for left and right subtree.
    vector<int> lLevel(lCnt);
    vector<int> rLevel(rCnt);
    
    // add the left and right elements to lLevel and 
    // rLevel
    int l = 0, r = 0;
    for (int i = 1; i< e-s+1; i++) {
        int j = searchValue(in, level[i], s, e);
        
        // If the value is present in
        // left subtree.
        if (j<index)
            lLevel[l++] = level[i];
        
        // else it will be present in 
        // right subtree.
        else 
            rLevel[r++] = level[i];
    }
    
    // Recursively create the left and right subtree.
    root->left = buildTreeRecur(in, lLevel, s, index-1);
    root->right = buildTreeRecur(in, rLevel, index+1, e);
    
    return root;
}

Node* buildTree(vector<int> inorder, vector<int> level, int n) {
    
    // Build the tree recursively.
    Node* root = buildTreeRecur(inorder, level, 0, n-1);
    
    return root;
}

void printInorder(Node* head) {
    Node* curr = head;
    if (curr == nullptr)
        return;
    printInorder(curr->left);
    cout << curr->key << " ";
    printInorder(curr->right);
}

int main() {
    vector<int> in = { 4, 8, 10, 12, 14, 20, 22 };
    vector<int> level = { 20, 8, 22, 4, 12, 10, 14 };
    int n = level.size();
    Node* root = buildTree(in, level, n);

    printInorder(root);

    return 0;
}
