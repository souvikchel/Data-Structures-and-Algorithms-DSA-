#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(){
  priority_queue<int,vector<string>,greater<string>> pq;

 /* pq.push(5);
  pq.push(10);
  pq.push(9);
  pq.push(7);
  pq.push(3);*/
  pq.push("Helloworld");
  pq.push("apnacollege");
  pq.push("C++");
  

  while(!pq.empty()){
    cout<<"top : "<<pq.top()<<endl;
    pq.pop();
  }
  return 0;
}