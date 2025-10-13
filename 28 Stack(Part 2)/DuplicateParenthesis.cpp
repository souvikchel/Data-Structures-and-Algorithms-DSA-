#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

int isDuplicate(string str){//O(n)
  stack<char> s;
  for(int i=0;i<str.size();i++){
    char ch=str[i];
    if(ch!=')'){
      s.push(ch);
    }else{//closing
      if(s.top()=='('){
        return true;//DUPLICATE
      }
      while(s.top()!='('){
        s.pop(); 
      }
      s.pop();
    }
  }
  return false;
}

int main(){
  string str1="((a+b))";
  cout<<isDuplicate(str1)<<endl;
  return 0;
}