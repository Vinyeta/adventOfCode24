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

        for(int i = 0; i < data.size(); i++) {
            for(int j = 0; j < data[i].size(); j++) {
                if(data[i][j] == 'X') {
                    if(j < data[i].size()-3 && data[i][j+1] == 'M' && data[i][j+2] == 'A' && data[i][j+3] == 'S') totalXmas++;
                    if(i < data.size()-3 && data[i+1][j] == 'M' && data[i+2][j] == 'A' && data[i+3][j] == 'S') totalXmas++;
                    if(i < data.size()-3 && j < data[i].size()-3 && data[i+1][j+1] == 'M' && data[i+2][j+2] == 'A' && data[i+3][j+3] == 'S') totalXmas++;
                    if(j > 2 && data[i][j-1] == 'M' && data[i][j-2] == 'A' && data[i][j-3] == 'S') totalXmas++;
                    if(i > 2 && data[i-1][j] == 'M' && data[i-2][j] == 'A' && data[i-3][j] == 'S') totalXmas++;
                    if(i > 2 && j < data[i].size()-3 && data[i-1][j+1] == 'M' && data[i-2][j+2] == 'A' && data[i-3][j+3] == 'S') totalXmas++;
                    if(i > 2 && j > 2 && data[i-1][j-1] == 'M' && data[i-2][j-2] == 'A' && data[i-3][j-3] == 'S') totalXmas++;
                    if(i < data.size()-3 && j > 2 && data[i+1][j-1] == 'M' && data[i+2][j-2] == 'A' && data[i+3][j-3] == 'S') totalXmas++;  
                }
            }
        }
        cout << totalXmas;
    }
}