#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include <algorithm>
using namespace std;

int mountainRanges(int n){
  vector<int> dp(n+1,0);

  dp[0]=dp[1]=1;

  for(int i=2;i<=n;i++){
    for(int j=0;j<i;j++){
      dp[i]+=dp[j]*dp[i-j-1];
    }
  }
  return dp[n];
}



int main(){
  int pairs=3;
  cout<<mountainRanges(pairs)<<endl;

  return 0;
}