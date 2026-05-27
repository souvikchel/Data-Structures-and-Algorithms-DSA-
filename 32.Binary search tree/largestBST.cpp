#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

class info{
public:
    bool isBST;
    int min;
    int max;
    int Sz;

    info(bool isBST, int min, int max, int Sz){
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->Sz = Sz;
    }
};

int maxSize = 0;
Node* largestRoot= NULL;

info* largestBST(Node* root){

    // Base case
    if(root == NULL){
        return new info(true, INT_MAX, INT_MIN, 0);
    }

    


    // Leaf node
    if(root->left == NULL && root->right == NULL){
       
        return new info(true, root->data, root->data, 1);
    }

    info* leftInfo = largestBST(root->left);
    info* rightInfo = largestBST(root->right);

    int currMin = min(root->data,
                     min(leftInfo->min, rightInfo->min));

    int currMax = max(root->data,
                     max(leftInfo->max, rightInfo->max));

    int currSz = leftInfo->Sz + rightInfo->Sz + 1;

    // Check BST condition
    if(leftInfo->isBST &&
       rightInfo->isBST &&
       root->data > leftInfo->max &&
       root->data < rightInfo->min){

        maxSize = max(maxSize, currSz);
        largestRoot=root;

        return new info(true, currMin, currMax, currSz);
    }

    return new info(false, currMin, currMax, currSz);
}

int main(){

    Node* root = new Node(50);

    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->left->left = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    largestBST(root);

    cout << maxSize << " ";
    cout<<largestRoot->data<<" ";

    return 0;
}