#include<iostream>
#include<vector>
using namespace std;
int fib(int n){
  if(n==0 || n==1){
    return n;

  }
  return fib(n-1)+fib(n-2);
}

int fibDP(int n,vector<int>& f){
  if(n==0 || n==1){
    return n;

  }
  if(f[n]!=-1){
    return f[n];
  }
  f[n]= fibDP(n-1,f)+fibDP(n-2,f);
  return f[n];
}

int fibTab(int n){
  vector<int> fib(n+1,0);
    fib[0]=0;
    fib[1]=1;

    for(int i=2;i<=n;i++){
      fib[i]=fib[i-1]+fib[i-2];
    }
    return fib[n];
  }
  int countWays(int n){
    if(n==0 || n==1){
      return 1;
    }
    return countWays(n-1)+countWays(n-2);
  }
  int countWaysMem(int n,vector<int>& dp){
    if(n==0 || n==1){
      return 1;
    }
    if(dp[n]!=-1){
      return dp[n];
    }
    dp[n]= countWaysMem(n-1,dp)+countWaysMem(n-2,dp);
    return dp[n];
  }
  int countWaysTab(int n){
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=n;i++){
      dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];


  }


int main(){
  int n=4;
  vector<int> dp(n+1,-1);
  
 /* vector<int>f(n+1,-1);

  cout<<fibDP(n,f)<<endl;
  cout<<fibTab(n)<<endl;*/
  cout<<countWaysMem(n,dp)<<endl;
  cout<<countWaysTab(n)<<endl;

  return 0;
}