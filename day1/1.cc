#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    vector<int> list1;
    vector<int> list2;

    int x;
    int y;

    while (cin >> x, cin >> y) {
        list1.push_back(x);
        list2.push_back(y);
    }
    
    int totalDistance = 0;
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    for(int i = 0; i < list1.size(); i++) {
        totalDistance += abs(list1[i] - list2[i]);
    }

    cout << totalDistance;
}