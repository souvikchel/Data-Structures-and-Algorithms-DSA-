#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

void stockSpan(vector<int> stock,vector<int> span){
  stack<int> s;
  s.push(0);
  span[0]=1;

  for(int i=0;i<stock.size();i++){
    int currPrice=stock[i];

    while(!s.empty() && currPrice>=stock[s.top()]){
      s.pop()
    }
    if(s.empty()){
      span[i]=i+1;
    }else{
      int prevHigh=s.top();
      span[i]=i-prevHigh;
    }
    for(int i)
  }
}



int main(){
  vector<int> stack={100,80,60,70,60,85,100};
  vector<int> span={0,0,0,0,0,0,0};
  stockSpanProblem(stack,span);
  return 0;
}