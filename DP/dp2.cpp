#include<iostream>
#include<vector>
using namespace std;

int knapSackRec(vector<int> val,vector<int> wt, int W,int n){
  if(n==0 || W==0){
    return 0;
  }

  int itemWt=wt[n-1];
  int itemVal=val[n-1];

  if(itemWt<=W){
    //inlcude
    int ans1=knapSackRec(val,wt,W-itemWt,n-1)+itemVal;

    //exclude
    int ans2=knapSackRec(val,wt,W,n-1);
    return max(ans1,ans2);

  }else{
    return knapSackRec(val,wt,W,n-1);
  }
}

int knapSackMem(vector<int> val,vector<int> wt, int W,int n,vector<vector<int>> &dp){
  if(n==0 || W==0){
    return 0;
  }

  if(dp[n][W]!=-1){
    return dp[n][W];
  }

  int itemWt=wt[n-1];
  int itemVal=val[n-1];

  if(itemWt<=W){
    //inlcude
    int ans1=knapSackMem(val,wt,W-itemWt,n-1,dp)+itemVal;

    //exclude
    int ans2=knapSackMem(val,wt,W,n-1,dp);
    dp[n][W]= max(ans1,ans2);

  }else{
    dp[n][W] =knapSackMem(val,wt,W,n-1,dp);
  }
  return dp[n][W];
} 

int knapSackTab(vector<int> val,vector<int> wt,int W,int n){
  vector<vector<int>> dp(n+1,vector<int>(W+1,0));
  for(int i=1;i<n+1;i++){
    for(int j=1;j<W+1;j++){
      int itemWt=wt[i-1];
      int itemVal=val[i-1];

      if(itemWt<=j){
        dp[i][j]=max(itemVal+dp[i-1][j-itemWt],dp[i-1][j]);
      }else{
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  return dp[n][W];
}

bool targetSum(vector<int> nums,int target){
  int n=nums.size();
  vector<vector<int>> dp(n+1,vector<int>(target+1,0));

  for(int i=1;i<=n;i++){
    for(int j=1;j<=target;j++){
      if(nums[i-1]<=j){
        dp[i][j]=max(nums[i-1]+dp[i-1][j-nums[i-1]],dp[i-1][j]);
      }else{
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  for(int i=0;i<=n;i++){
    for(int j=0;j<=target;j++){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }
  return dp[n][target]==target;
}




int main(){

  vector<int> val={15,14,10,45,30};
  vector<int> wt={2,5,1,3,4};
  int W=7;
  int n=5;

  cout<<knapSackRec(val,wt,W,n)<<endl;

  vector<vector<int>> dp(n+1,vector<int>(W+1,-1));

  cout<<knapSackMem(val,wt,W,n,dp)<<endl;
  for(int i=0;i<n+1;i++){
    for(int j=0;j<W+1;j++){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<knapSackTab(val,wt,W,n)<<endl;

  vector<int> nums={4,2,7,1,3};
  int target=10;

  cout<<targetSum(nums,target)<<endl;

  return 0;
}