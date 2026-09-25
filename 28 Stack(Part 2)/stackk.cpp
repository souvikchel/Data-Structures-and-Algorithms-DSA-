#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

bool isValid(string str){
  stack<char> s;
  for (int i=0;i<str.size();i++){
    char ch=str[i];
    if(ch=="(" || ch=="{" || ch=="["){
      s.push(ch);
    }else{
      int top=s.top();
      if(top=="(" && ch==")")
    }
  }
}



int main(){
  string str1="([}])";
  cout<<isValid(str1)<<endl;
  return 0;

}