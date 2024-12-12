#include <iostream>
#include <regex>
#include <fstream>

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
        string::const_iterator text_iter = data.cbegin();
        string::const_iterator text_end = data.cend();
        int totalMul = 0;
        while(regex_search(text_iter,text_end, match, rgx)) {
            text_iter = match[0].second;
            regex nrgx("[0-9]{1,3}");
            smatch nmatch;
            string::const_iterator number_iter = string(match[0].first, match[0].second).cbegin();
            string::const_iterator number_end = string(match[0].first, match[0].second).cend();
            int i = 0;
            int n1;
            int n2;
            while(regex_search(number_iter,number_end, nmatch, nrgx) && i < 2) { 
                number_iter = nmatch[0].second;
                if (i == 0)  n1 = stoi(string(nmatch[0].first, nmatch[0].second));
                else n2 = stoi(string(nmatch[0].first, nmatch[0].second));
                i++;
            }
            totalMul += n1*n2;
        }
        cout << totalMul;
    }

}
