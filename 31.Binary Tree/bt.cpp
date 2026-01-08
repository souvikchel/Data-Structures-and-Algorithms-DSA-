#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;

  Node(int data){
    this->data=data;
    left=right=NULL;
  }
};
static int idx=-1;
Node* buildTree(vector<int> nodes){
  idx++;
  if(nodes[idx]==-1){
    return NULL;
  }

  Node* currNode=new Node(nodes[idx]);
  currNode->left=buildTree(nodes);
  currNode->right=buildTree(nodes);

  return currNode;
}

void preorder( Node* root){

  if(root == NULL){
    return;
  }


  cout<<"root ="<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);

}

void inorder(Node* root){
  if(root == NULL){
    return;
  }

  //left
  inorder(root->left);
  //root
  cout<<root->data<<" ";
  //right
  inorder(root->right);
}

void postorder(Node* root){
   if(root == NULL){
    return;
  }

  //left
  postorder(root->left);
  
  //right
  postorder(root->right);

  //root
  cout<<root->data<<" ";
}


void levelOrder(Node* root){
  if(root==NULL){
    return;
  }
  queue<Node*> Q;
  Q.push(root);
  Q.push(NULL);
  while(!Q.empty()){
    Node*curr=Q.front();
    Q.pop();
    if(curr==NULL){
      cout<<endl;
      if(Q.empty()){
        break;
      }
      Q.push(NULL);
    }else{

    cout<<curr->data<<" ";
    if(curr->left!=NULL){
      Q.push(curr->left);
    }

    if(curr->right!=NULL){
      Q.push(curr->right);
    }
  }
}
  cout<<endl;
}

int height(Node* root){

  if(root==NULL){
    return 0;
  }

  int leftHt=height(root->left);
  int rightHt=height(root->right);

  int currHt=max(leftHt,rightHt)+1;
  return currHt;
}


int count(Node* root){
  if(root==NULL){
    return 0;
  }
  int leftCount=count(root->left);
  int rightCount= count(root->right);
  return leftCount+rightCount+1;
}

int sum(Node* root){
  if(root==NULL){
    return 0;
  }

  int leftSum=sum(root->left);
  int rightSum=sum(root->right);
  int currSum= leftSum+rightSum+root->data;
  cout<<"sum : "<<currSum<<endl;
  return currSum;

}

int diam1(Node* root){
  if(root==NULL){
    return 0;
  }

  int currDiam=height(root->left)+height(root->right)+1;//O(n)
  int leftDiam=diam1(root->left);
  int rightDiam=diam1(root->right);

  return max(currDiam,max(leftDiam,rightDiam));
}


pair<int,int> diam2(Node* root){//O(n)
  if(root==NULL){
    return make_pair(0,0);
  }


  pair<int,int> leftInfo=diam2(root->left);//LD,LH
  pair<int,int> rightInfo=diam2(root->right);//RD,RH

  int currDiam=leftInfo.second+rightInfo.second+1;
  int finalDiam=max(currDiam,max(leftInfo.first,rightInfo.first));
  int finalHt=max(leftInfo.second,rightInfo.second)+1;

  return make_pair(finalDiam,finalHt);

}

bool isIdentical(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL){
    return true;
  }else if(root1==NULL || root2==NULL){
    return false;
  }


  if(root1->data!=root2->data){
    return false;
  }

  return isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right);
}




bool isSubtree(Node* root,Node* subRoot){
  if(root==NULL && subRoot==NULL){
    return true;
  }else if(root==NULL || subRoot==NULL){
    return false;
  }

  if(root->data==subRoot->data){
    if(isIdentical(root,subRoot))
        return true;
  }
  int isLeftSubtree=isSubtree(root->left,subRoot);
  if(!isLeftSubtree){
    return isSubtree(root->right,subRoot);
  }
  return true;
}

void topView(Node* root){
  queue<pair<Node*,int>> Q;//(node,HD)
  map<int,int> m;//(HD,node->data)

  Q.push(make_pair(root,0));
  while(!Q.empty()){
    pair<Node*,int> curr=Q.front();
    Q.pop();

    Node* currNode=curr.first;
    int currHD=curr.second;

    if(m.count(currHD)==0){//HD is unique
      m[currHD]=currNode->data;

    }
    if(currNode->left!=NULL){
      pair<Node*,int> left=make_pair(currNode->left,currHD-1);
      Q.push(left);
    }
    if(currNode->right!=NULL){
      pair<Node*,int> right=make_pair(currNode->right,currHD+1);
      Q.push(right);
    }

  }

  for(auto it:m){
    cout<<it.second<<" ";
  }
  cout<<endl;
}

int main(){
  vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
  Node* root=buildTree(nodes);//1

 // cout<<"root= "<<root->data<<endl;

 //preorder(root);
 //cout<<endl;

 //inorder(root);
 //cout<<endl;

 //postorder(root);
 //cout<<endl;

 //levelOrder(root);
 //cout<<"height : "<<height(root)<<endl;
 /*cout<<"Count : "<<count(root)<<endl;

 Node* root2=new Node(5);
 root2->left=new Node(3);
 root2->right=new Node(4);

 cout<<"Count : "<<count(root2)<<endl;

 cout<<"sum of nodes : "<<sum(root)<<endl;*/

 //cout<<"diameter : "<<diam2(root).first<<endl;

 /*Node* subRoot=new Node(2);
 subRoot->left=new Node(4);
 //subRoot->right=new Node(5);

 cout<<isSubtree(root,subRoot)<<endl;*/
  topView(root);

  return 0;
}
