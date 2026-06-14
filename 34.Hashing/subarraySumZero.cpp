#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include<vector>
using namespace std;


int largestSubarray0Sum(vector<int> arr){
  unordered_map<int,int>m;
  int sum=0;
  int ans=0;

  for(int j=0;j<arr.size();j++){
    sum+=arr[j];
  
  if(m.count(sum)){
    int currLength=j-m[sum];
    ans=max(ans,currLength);
  }else{
    m[sum]=j;
  }
}
  return ans;
}


int main(){
  vector<int> arr={15,-2,2,-8,1,7,10};
  cout<<largestSubarray0Sum(arr);


  return 0;
}