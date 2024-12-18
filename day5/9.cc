#include <iostream>
#include <regex>
#include <fstream>

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
        
    }
}