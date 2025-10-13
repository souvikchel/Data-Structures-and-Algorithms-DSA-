#include<iostream>
#include<list>
#include<iterator>
using namespace std;



void printList(list<int>ll){
  list<int>::iterator itr;
  for(itr=ll.begin();itr!=ll.end();itr++){
      cout<<(*itr)<<"->";
  }
  cout<<"NULL\n";
}

int main(){
  list<int> ll;//vector<int>arr

  ll.push_front(2);
  ll.push_front(1);//1->2

  ll.push_back(3);//1->2->3
  ll.push_back(4);//1->2->3->4

  printList(ll);
  cout<<ll.size()<<endl;

  cout<<"head= "<<ll.front();
  cout<<"tail= "<<ll.back();

  ll.pop_front();
  ll.pop_back();
  printList(ll);

  
  return 0;
}