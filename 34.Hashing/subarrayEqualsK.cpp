#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include<vector>
using namespace std;

    int subarraySum(vector<int> nums, int k) {
        unordered_map<int, int> mp;
        
        int result = 0;
        int cumSum = 0;

        // Important: base case
        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++) {
            cumSum += nums[i];

            // Check if (cumSum - k) exists
            if(mp.find(cumSum - k) != mp.end()) {
                result += mp[cumSum - k];
            }

            // Store current cumulative sum
            mp[cumSum]++;
        }

        return result;
    }






int main(){

  vector<int> arr={1,2,3};
  int k=3;

  cout<<subarraySum(arr,k);

  return 0;
}