#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;
 template <class T>
class Node{
 public:
  T data;
  Node* next;
  
  Node(T val){
    data=val;
    next=NULL;
  }

};

//create stack using LL
template <class T>
class Stack{
  Node<T>* head;
  public:
  Stack(){
    head=NULL;
  }
  void push(T val){
    //push_front
    Node<T>* newNode=new Node<T>(val);
    if(head==NULL){
      head=newNode;
    }else{
      newNode->next=head;
      head=newNode;
    }
  }
  void pop(){
    Node<T>*temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
  }
  T top(){
    //return ll.front();
    return head->data;
  }
  bool isEmpty(){
    //return ll.size()==0;
    return head==NULL;
  }
};

int main(){
  //STL Stack

  //Stack <int>s;
  stack<int> s;
  s.push(3);  
  s.push(2);
  s.push(1);

  while(!s.empty()){
    cout<<s.top()<<endl;
    s.pop();
  }
  

  return 0;
}