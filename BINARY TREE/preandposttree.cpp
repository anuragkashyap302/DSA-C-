// C++ code for construction of full binary tree 

#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

// A recursive function to construct Full from pre[] and post[]. 
// preIndex is used to keep track of index in pre[].
// l is low index and h is high index for the current 
// subarray in post[]
Node* constructTreeUtil (vector<int> &pre, vector<int> &post, int &preIndex,
                          int l, int h, int size) {
  
    if (preIndex >= size || l > h)
        return nullptr;

    // The first node in preorder traversal is root. 
      // So take the node at preIndex from preorder and make it root,
      // and increment preIndex
    Node* root = new Node(pre[preIndex]);
    ++preIndex;

    // If the current subarray has only one element, 
      // no need to recur
    if (l == h)
        return root;

    // Search the next element of pre[] in post[]
    int i;
    for (i = l; i <= h; ++i)
        if (pre[preIndex] == post[i])
            break;

    // Use the index of element found in 
      // postorder to divide postorder array in two parts:
      // left subtree and right subtree
    if (i <= h) {
        root->left = constructTreeUtil(pre, post, 
                                       preIndex, l, i, size);
        root->right = constructTreeUtil(pre, post, 
                                        preIndex, i + 1, h - 1, size);
    }

    return root;
}

// The main function to construct Full Binary Tree from given preorder and 
// postorder traversals. This function mainly uses constructTreeUtil()
Node *constructTree (vector<int> &pre, vector<int> &post) {
    int preIndex = 0;
    int size = pre.size();
    return constructTreeUtil(pre, post, preIndex, 
                             0, size - 1, size);
}

// A utility function to print inorder 
// traversal of a Binary Tree
void print (Node* curr) {
    if (curr == nullptr)
        return;
    print(curr->left);
    printf("%d ", curr->data);
    print(curr->right);
}

int main () {
  
    vector<int> pre = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    vector<int> post = {8, 9, 4, 5, 2, 6, 7, 3, 1};

    Node *root = constructTree(pre, post);

    print(root);

    return 0;
}
