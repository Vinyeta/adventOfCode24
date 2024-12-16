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

        int totalXmas = 0;

        for(int i = 0; i < data.size()-1; i++) {
            for(int j = 0; j < data[i].size()-1; j++) {
                if((i < data.size()-1 && j < data[i].size()-1) || (i > 0 && j > 0)) {
                    if(data[i][j] == 'A') {
                        if(data[i+1][j+1] == 'S' && data[i-1][j-1] == 'M') {
                            totalXmas++;
                        }
                    }
                }
            }
        }
        cout << "r: " << totalXmas;
    }
}