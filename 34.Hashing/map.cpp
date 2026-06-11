#include<iostream>

#include<map>
using namespace std;

int main(){
  map<string,int> m;

  m["China"]=150;
  m["India"]=150;
  m["Us"]=50;
  m["Us"]=250;

  for(pair<string,int> country : m){
    cout<<country.first<<","<<country.second<<endl;
  }

  if(m.count("Nepal")){
    cout<<"exist";
  }else{
    cout<<"Not exist";
  }

  m.erase("china");
  if(m.count("china")){
    cout<<"exist";
  }else{
    cout<<"Not exist";
  }
  return 0;
}