#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  public:
  Node(int val){
    data=val;
    next=NULL;
  }

  ~Node(){
    //cout<<"destructor of node\n for data= "<<data<<endl;
    if(next!=NULL){
      
      delete next;
      next=NULL;
    }
  }
};

class List{
  public:
  Node*head;
  Node*tail;

  public:
  List(){

    
    head=NULL;
    tail=NULL;
  }

  ~List(){
    //cout<<"destructor of list\n";
    if(head!=NULL){
      delete head;
      head=NULL;
    }
  }

  void push_front(int val){
    Node *newNode=new Node(val);//dynamic
    //Node* newNode(val); static

    if(head==NULL){
      head=tail=newNode;
    }else{
      newNode->next=head;
      head=newNode;
    }
  }

  void push_back(int val){
    Node *newNode=new Node(val);
    if(head==NULL){
      head=tail=newNode;
    }else{
      tail->next=newNode;
      tail=newNode;
    }
  }

  void printList(){
    Node *temp=head;
    while(temp!=NULL){
      cout<<temp->data<<"->";
      temp=temp->next;
    }
    cout<<"NULL\n";
  }

  void insert(int val,int pos){
    Node *newNode=new Node(val);
    Node* temp=head;
    for(int i=0;i<pos-1;i++){
      if(temp==NULL){
        cout<<"position is Invalid\n";
        return;
      }
      temp=temp->next;

    }

    //temp is now at pos-1 i.e. prev/left
    newNode->next=temp->next;
    temp->next=newNode;

  }

  void pop_front(){
    if(head==NULL){
      cout<<"LL is empty\n";
      return;
    }
    Node* temp=head;

    head=head->next;
    temp->next=NULL;
    delete temp;
  }

  void pop_back(){
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;
    delete tail;
    tail=temp;
  }

  int searchItr(int key){//O(n)
    Node *temp=head;
    int idx=0;
    while(temp!=NULL){
      if(temp->data==key){
        return idx;
      }
      temp=temp->next;
      idx++;
    }
    return -1;
  }
  int helper(Node *temp,int key){
    if(temp==NULL){
      return -1;
    }

    if(temp->data==key){
      return 0;
    }
    int idx=helper(temp->next,key);
    if(idx==-1){
      return -1;
    }
    return idx+1;

  }
  int searchRec(int key){
    return helper(head,key);

  }

  void reverse(){
    Node* curr=head;
    Node* prev=NULL;
    tail=head; 

    while(curr!=NULL){
      Node *next=curr->next;
      curr->next=prev;

      //updation
      prev=curr;
      curr=next;

    }
    head=prev;
  }
  int getsize(){
    int sz=0;
    Node *temp=head;
    while(temp!=NULL){
      temp=temp->next;
      sz++;
    }
    return sz;

  }
  void removeNth(int n){
    int size=getsize();

    Node* prev=head;
    for(int i=1;i<(size-n);i++){
      prev=prev->next;
    }
    Node *toDel=prev->next;
    cout<<"delete"<<toDel->data<<endl;
    prev->next=prev->next->next;
  }
};

int main(){
  List ll;
  ll.push_front (5);
  ll.push_front (4);
  ll.push_front (3);
  ll.push_front (2);
  ll.push_front (1);

  //1->2->3>NULL


  //ll.push_back(4);
  //ll.push_back(5);
  

  //ll.insert(100,2);
  //ll.printList();
  //ll.pop_front();
  //ll.pop_back();
  ll.printList();
  //ll.reverse();
  //ll.printList();
  ll.removeNth(2);
  ll.printList();

  //cout<<ll.searchItr(4)<<endl;
  //cout<<ll.searchRec(4)<<endl;
  return 0;
}