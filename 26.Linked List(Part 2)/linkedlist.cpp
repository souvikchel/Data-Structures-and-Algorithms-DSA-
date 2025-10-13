#include<iostream>
#include<list>

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
};
    void printList(Node* head){
    Node *temp=head;
    while(temp!=NULL){
      cout<<temp->data<<"->";
      temp=temp->next;
    }
    cout<<"NULL\n";
  }

  bool isCycle(Node* head){
    Node *slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
      slow=slow->next;
      fast=fast->next->next;

      if(slow==fast){
        cout<<"cycle exists\n";
        return true;
      }
    }
    cout<<"cycle doesn't exists\n";
    return false;
  }

  void removeCycle(Node* head){
    //detect cycle
     Node *slow=head;
    Node* fast=head;
    bool isCycle=false;

    while(fast!=NULL && fast->next!=NULL){
      slow=slow->next;
      fast=fast->next->next;

      if(slow==fast){
        cout<<"cycle exists\n";
        isCycle=true;
        break;
      }
  }
  if(!isCycle){
    cout<<"cycle doesn't exists\n";
    return;
  }

  slow=head;
  if(slow==fast){//tail->head
    while(fast->next!=slow){
      fast=fast->next;
    }
    fast->next=NULL;//remove cycle;
  }else{
    Node *prev=fast;
    while(slow!=fast){
      slow=slow->next;
      prev=fast;
      fast=fast->next;
    }
    prev->next=NULL;//remove cycle
  }

}

Node *splitAtMid(Node* head){
  Node *slow=head;
  Node *fast=head;
  Node* prev=NULL;

  while(fast!=NULL && fast->next!=NULL){
    prev=slow;
    slow=slow->next;
    fast=fast->next->next;
  }

  if(prev!=NULL){
    prev->next=NULL;
  }
  return slow;//slow=rightHead
}

Node* merge(Node*left,Node* right){
  List ans;
  Node* i=left;
  Node* j=right;

  while(i!=NULL && j!=NULL){
    if(i->data<=j->data){
      ans.push_back(i->data);
      i=i->next;
    }else{
      ans.push_back(j->data);
      j=j->next;
    }
  }

  while(i!=NULL){
    ans.push_back(i->data);
      i=i->next;
  }
  while(j!=NULL){
    ans.push_back(j->data);
      j=j->next;
  }

  return ans.head;
}

Node*  mergeSort(Node *head){

  if(head==NULL || head->next==NULL){
    return head;
  }
  Node* rightHead=splitAtMid(head);
  Node* left=mergeSort(head);
  Node * right=mergeSort(rightHead);
  return merge(left,right);//head or sorted linked list
}

Node* reverse(Node* head){
  Node* prev=NULL;
  Node* curr=head;
  Node* next=NULL;

  while(curr!=NULL){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
  }
  return prev;
}

Node* zigZag(Node* head){
  Node* rightHead=splitAtMid(head);
  Node* rightHeadRev=reverse(rightHead);
  //alternate merging:1st head=head,2nd head=rightHeadRev

  Node* left=head;
  Node* right=rightHeadRev;
  Node* tail=NULL;

  while(left!=NULL && right!=NULL){
    Node* nextLeft=left->next;
    Node* nextRight=right->next;
    left->next=right;
    right->next=nextLeft;

    tail=right;

    left=nextLeft;
    right=nextRight;


  }

  if(right!=NULL){
    tail->next=right;
  }
  return head;
}


int main(){
  List ll;
  ll.push_front(5);
  ll.push_front(4);
  ll.push_front(3);
  ll.push_front(2);
  ll.push_front(1);
  //ll.tail->next=ll.head;//1->2->3->4->1

  //isCycle(ll.head);
  //removeCycle(ll.head);
  printList(ll.head);

  //ll.head=mergeSort(ll.head);

  ll.head=zigZag(ll.head);
  printList(ll.head);
  return 0;
}
