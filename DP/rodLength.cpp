#include<iostream>
#include<vector>
using namespace std;

int rodCutting(vector<int> prices, vector<int> length,int rodLength){
  int n=length.size();

  vector<vector<int>> dp(n+1,vector<int>(rodLength+1,0));
  for(int i=1;i<n+1;i++){
    for(int j=1;j<rodLength+1;j++){
      if(length[i-1]<=j){
        dp[i][j]=max(prices[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
      }else{
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  return dp[n][rodLength];
}


int main(){

  vector<int> prices={1,5,8,9,10,17,17,20};
  vector<int> length={1,2,3,4,5,6,7,8};

  int rodLength=8;

  cout<<rodCutting(prices,length,rodLength);
  return 0;
}