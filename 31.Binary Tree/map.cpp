#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
  map<int,string> m;

  m[101]="Rahul";
  m[110]="Neha";
  m[131]="Rahul";

  m[101]="Rajat";//overwrite

  cout<<m[101]<<endl;

  cout<<m.count(101)<<endl;

  for(auto it:m){
    cout<<"key = "<<it.first<<","<<"value = "<<it.second<<endl;
    cout<<"double = "<<it.first * 2 <<endl;
  }
  return 0; 
}