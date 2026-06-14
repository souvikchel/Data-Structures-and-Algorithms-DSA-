#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>

using namespace std;

void printUnion(vector<int> arr1,vector<int> arr2){
  unordered_set<int> s;
  for(int el: arr1){
    s.insert(el);
  }
  for(int el: arr2){
    s.insert(el);
  }
  for(int el: s){
    cout<<el<<" ";
  }
}



int main(){
  vector<int> arr1={7,3,9};
  vector<int> arr2={6,3,9,6,2,4};

  printUnion(arr1,arr2);


  return 0;
}