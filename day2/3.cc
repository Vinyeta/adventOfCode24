#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    vector<vector<int>> reports;
    int x;
    ifstream in("input.txt");

    if (in) {
        string line;

        while (getline(in, line)) {
            istringstream row(line);
            int field;
            vector<int> report;
            while (row >> field) {
                report.push_back(field);
            }
            reports.push_back(report);
        }
    }

    int totalSafe = 0;
    for(int i = 0; i < reports.size(); i++) {
        bool safe = true;
        bool increasing;
        if(reports[i][0] > reports[i][1]) increasing = true;
        else increasing = false;
        for(int j = 0; j < reports[i].size()-1; j++) {
            int difference = abs(reports[i][j] - reports[i][j+1]);
            if( difference < 1 || difference > 3) {
                safe =false;
                break;
            }
            if((increasing && reports[i][j] < reports[i][j+1]) || (!increasing && reports[i][j] > reports[i][j+1])) {
                safe = false;
                break;
            }
        }
        if(safe) totalSafe++;
    }
    cout << totalSafe;
}