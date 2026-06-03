#include <iostream>
#include <vector>
#include<queue>
using namespace std;

class Heap {
    vector<int> vec; // Max Heap

public:
    void push(int val) {
        vec.push_back(val);

        int x = vec.size() - 1;
        int parI = (x - 1) / 2;

        while (x > 0 && vec[x] > vec[parI]) {
            swap(vec[x], vec[parI]);
            x = parI;
            parI = (x - 1) / 2;
        }
    }

    void heapify(int i) {
        if (i >= vec.size()) {
            return;
        }

        int l = 2 * i + 1;
        int r = 2 * i + 2;

        int maxI = i;

        if (l < vec.size() && vec[l] > vec[maxI]) {
            maxI = l;
        }

        if (r < vec.size() && vec[r] > vec[maxI]) {
            maxI = r;
        }

        if (maxI != i) {
            swap(vec[i], vec[maxI]);
            heapify(maxI);
        }
    }

    void pop() {
        if (empty()) return;

        swap(vec[0], vec[vec.size() - 1]);
        vec.pop_back();

        if (!empty()) {
            heapify(0);
        }
    }

    int top() {
        return vec[0];
    }

    bool empty() {
        return vec.empty();
    }
};

class Student {//"<" overload
  public:
  string name;
  int marks;
  Student(string name,int marks){
    this->name=name;
    this->marks=marks;
  }

  bool operator < (const Student &obj) const{
    return this->marks < obj.marks;
  }
};

struct ComaprePair{
  bool operator()(pair<string,int>&p1,pair<string,int>&p2){
  return p1.second<p2.second;
  }
};

int main() {
    /*Heap heap;

    heap.push(50);
    heap.push(10);
    heap.push(100);

    while (!heap.empty()) {
        cout << heap.top() << endl;
        heap.pop();
    }

    priority_queue<Student> pq;

    pq.push(Student("aman",85));
    pq.push(Student("bhumika",95));
    pq.push(Student("chetan",65));

    while(!pq.empty()){
      cout<<"top : "<<pq.top().name<<","<<pq.top().marks<<endl;
      pq.pop();
    }*/
    priority_queue<pair<string,int>,vector<pair<string,int>>,ComaprePair> pq;

    pq.push(make_pair("aman",85));
    pq.push(make_pair("bhumika",95));
    pq.push(make_pair("chetan",65));

    while(!pq.empty()){
      cout<<"top : "<<pq.top().first<<","<<pq.top().second<<endl;
      pq.pop();
    }



    return 0;
}