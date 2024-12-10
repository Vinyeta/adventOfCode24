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
    
    int totalSimilarity = 0;
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    for(int i = 0; i < list1.size(); i++) {
        int count = 0;
        for(int j = 0; j < list2.size(); j++){
            if (list1[i] == list2[j]) count++;
            else if (list2[j] > list1[i]) break;
        }
        totalSimilarity += count*list1[i];
    }

    cout << totalSimilarity;

}