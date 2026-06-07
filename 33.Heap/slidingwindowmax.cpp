#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void slidingWindowMax(vector<int> arr,int k){
  priority_queue<pair<int,int>> pq;

  for(int i=0;i<k;i++){
    pq.push(make_pair(arr[i],i));
  }

  cout<<"output : "<<pq.top().first<<endl;

  for(int i=k;i<arr.size();i++){
    while(!pq.empty() && pq.top().second<=(i-k)){
      pq.pop();
    }
    pq.push(make_pair(arr[i],i));
    cout<<pq.top().first<<" ";
  }
  cout<<endl;

}



int main(){
  vector<int> arr={1,3,-1,-3,5,3,6,7};
  int k=3;
  slidingWindowMax(arr,k);

  return 0;
}