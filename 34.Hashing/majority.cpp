#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

void majority(vector<int> nums){
    unordered_map<int,int> m;

    for(int x : nums){
        m[x]++;
    }


  for(pair<int,int> p: m){
    if(p.second>nums.size()/3){
      cout<<p.first<<" ";
    }
  }
  cout<<endl;
}

int main(){
  vector<int> nums={1,3,2,5,1,3,1,5,1};
  vector<int> nums2={1,2};

  majority(nums);
  return 0;
}
