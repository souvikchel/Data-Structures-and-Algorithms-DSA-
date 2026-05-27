#include<iostream>
#include<vector>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node*right;

  Node(int data){
    this->data=data;
    left=right=NULL;
  }
};

Node* insert(Node* root,int val){//O(logn)
  if(root==NULL){
    root=new Node(val);
    return root;
  }
  if(val<root->data){
    root->left=insert(root->left,val);
  }else{
    root->right=insert(root->right,val);
  }
  return root;
}

Node* buildBST(int arr[],int n){
  Node* root=NULL;

  for(int i=0;i<n;i++){
    root=insert(root,arr[i]);
  }
  return root;
}

void inorder(Node* root){
  if(root==NULL){
    return;    
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

bool search(Node* root,int key){
  if(root==NULL){
    return false;
  }
  if(root->data==key){
    return true;
  }
  if(root->data > key){
    return search(root->left,key);
  }else{
    return search(root->right,key);
  }
}

Node* getInorderSuccessor(Node* root){
  while(root->left!=NULL){
    root=root->left;
  }
  return root;
}


Node* delNode(Node*root,int val){
  if(root==NULL){
    return NULL;
  }
  if(val<root->data){
    root->left=delNode(root->left,val);
  }else if(val>root->data){
    root->right=delNode(root->right,val);
  }else{
    //root==val
    //case1:0 child
    if(root->left==NULL && root->right==NULL){
      delete root;
      return NULL;
    }
    //case2:1 child
    if(root->left==NULL || root->right==NULL){
      return root->left==NULL?root->right:root->left;
    }
    Node*IS=getInorderSuccessor(root->right);
    root->data=IS->data;
    root->right=delNode(root->right,IS->data);//case1,case2
    return root;
  }
  return root;
}

void printInRange(Node* root,int start,int end){
  if(root==NULL){
    return;
  }
  if(start<=root->data&& root->data<=end){
    cout<<root->data<<" ";
    printInRange(root->left,start,end);
    printInRange(root->right,start,end);
  }else if(root->data<start){
    printInRange(root->right,start,end);
  }else{
    printInRange(root->right,start,end);
  }
}

void printPath(vector<int>path){
  cout<<"path : ";
  for(int i=0;i<path.size();i++){
    cout<<path[i]<<" ";
  }
  cout<<endl;
}

void pathHelper(Node* root,vector<int>& path){

  if(root==NULL)  return;
    path.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
      //leaf
      printPath(path);
      path.pop_back();
      return;
    }
    pathHelper(root->left,path);
    pathHelper(root->right,path);

    path.pop_back();
}

void roottoLeaf(Node* root){
  vector<int> path;
  pathHelper(root,path);

}

bool validateHelper(Node* root,Node* min,Node* max){
  if(root==NULL){
    return true;
  }

  if(min!=NULL && root->data<min->data){
    return false;
  }
  if(max!=NULL && root->data>max->data){
    return false;
  }

  return validateHelper(root->left,min,root)
          &&validateHelper(root->right,root,max);

}

bool validateBST(Node* root){
  validateHelper(root,NULL,NULL);
}

Node* buildBSTfromSorted(int arr[],int st,int end){
  if(st>end){
    return NULL;
  }

  int mid=st+(end-st)/2;
  Node*curr=new Node(arr[mid]);
  curr->left=buildBSTfromSorted(arr,st,mid-1);
  curr->right=buildBSTfromSorted(arr,mid+1,end);

  return curr;
}

void preorder(Node* root){
  if(root==NULL){
    return;
  }

  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}




int main(){
  int arr[6]={5,1,3,4,2,7};
  int arr2[9]={8,5,3,1,4,6,10,11,14};
  int arr3[7]={3,4,5,6,7,8,9};
  Node*root=buildBSTfromSorted(arr3,0,6);
  preorder(root);
  cout<<endl;

  //Node* root=buildBST(arr,6);
 // Node* root=buildBST(arr2,9);
 /* inorder(root);
  delNode(root,4);
  inorder(root);*/

  /*printInRange(root,5,12);
  roottoLeaf(root);

  cout<<validateBST(root)<<endl;*/


  //cout<<search(root,5);
  //inorder(root);
  cout<<endl;

  return 0;
}