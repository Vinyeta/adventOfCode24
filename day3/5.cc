#include <iostream>
#include <regex>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    string data = "";
    ifstream in("input.txt");

    if (in) {
        string line;

        while (getline(in, line)) {
            data += line;
            
        }
        regex rgx("mul\\([0-9]{1,3}\\,[0-9]{1,3}\\)");
        smatch match;
        if (regex_search(data, match, rgx)) {
            for (auto x:match) {
                cout << "match: " << x << '\n';
            }
        }
    }

}
