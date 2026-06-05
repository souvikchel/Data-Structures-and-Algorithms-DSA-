#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Car {
public:
    int idx;
    int distSq;

    Car(int idx, int distSq) {
        this->idx = idx;
        this->distSq = distSq;
    }

    bool operator<(const Car& obj) const {
        return this->distSq > obj.distSq;
    }
};

void nearbyCars(vector<pair<int, int>> pos, int k) {
    priority_queue<Car> pq;

    for (int i = 0; i < pos.size(); i++) {
        int distSq = pos[i].first * pos[i].first +
                     pos[i].second * pos[i].second;

        pq.push(Car(i, distSq));
    }

    for (int i = 0; i < k; i++) {
        cout << "Car Index: " << pq.top().idx << endl;
        pq.pop();
    }
}

int main() {
    vector<pair<int, int>> pos;

    pos.push_back(make_pair(3, 3));
    pos.push_back(make_pair(5, -1));
    pos.push_back(make_pair(-2, 4));

    int k = 2;

    nearbyCars(pos, k);

    return 0;
}