#include<iostream>
#include<vector>
using namespace std;

int firstOccurence(vector<int>arr,int i,int target){

    if(i==arr.size()){
        return -1;
    }

    if(arr[i]==target){
        return i;
    }

    return firstOccurence(arr,i+1,target);
}

int lastOccur(vector<int>arr,int target,int i){
    if(i==arr.size()){
        return -1;
    }

    int idxfound=lastOccur(arr,target,i+1);
    if(idxfound==-1 && arr[i]==target){
            return i;
        }
        return idxfound;
    }

    #include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 2, 4, 2};
    int n = 6;
    int target = 2;

    int first = -1, last = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }

    cout << "First occurrence: " << first << endl;
    cout << "Last occurrence: " << last << endl;

    return 0;
}


int main(){
    vector<int>arr={1,2,3,3,3,4};
    //cout<<firstOccurence(arr,0,3)<<endl;
    cout<<lastOccur(arr,3,0)<<endl;
    return 0;
}