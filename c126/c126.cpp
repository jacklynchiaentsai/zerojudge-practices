#include <bits/stdc++.h>
using namespace std;

// global variables
int first;
string preorder, inorder;

struct Node{
  char data;
  struct Node *left;
  struct Node *right;
};

void postorder(Node *curr){
  // otherwise will have segmentation fault
  if (curr!= NULL){
    postorder(curr->left);
    postorder(curr-> right);
    cout<< curr->data;
  }
}

// index of left and right boundaries in inorder
Node* buildTree(int left, int right){
  // index of middle node in inorder string
  int mid;
  Node *binNode = new Node;
  binNode->data = preorder[first++];
  
  // if there is still child nodes (not leaf node)
  if (left<right){
    for(int i = left; i<=right; i++){
      if (binNode-> data == inorder[i]){
        mid = i;
        break;
      }
    }
    // there is still nodes left in left subtree
    if (left< mid){
      binNode->left = buildTree(left, mid - 1);
    } else{
      binNode->left = NULL;
    }

    // there is still nodes left in right subtree
    if (right > mid){
      binNode->right = buildTree(mid+1, right);
    } else{
      binNode-> right = NULL;
    }
    
  } else{
    // leaf node
    binNode->right = NULL;
    binNode->left = NULL;
  }
  
  return binNode;
}

int main() {
  while (cin>> preorder>>inorder){
    first = 0;
    int treelength = preorder.length();
    Node* root = buildTree(0, treelength - 1);
    postorder(root);
    cout<< endl;
  }
}
