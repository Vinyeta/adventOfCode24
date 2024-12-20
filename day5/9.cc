#include <iostream>
#include <regex>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    vector<string> data;
    ifstream in("input.txt");

    if (in) {
        string line;
        int lineSize;

        while (getline(in, line)) {
            lineSize = line.size();
            data.push_back(line);
        }

        vector<string>::iterator it = find(data.begin(), data.end(), "");
        int separator = distance(data.begin(), it);
        
        for (int i = separator +1; i < data.size(); i++) {
            if()
        }
        
    }
}