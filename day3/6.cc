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

        int totalMul = 0;

        vector<string::const_iterator> dos;
        vector<string::const_iterator> donts;
        dos.push_back(data.cbegin());

        regex rgxdo("do\\(\\)");
        smatch domatch;
        string::const_iterator text_iter = data.cbegin();        
        string::const_iterator text_end = data.cend();

        while(regex_search(text_iter,text_end, domatch,rgxdo)) {
            text_iter = domatch[0].second;
            dos.push_back(domatch[0].second);
        }

        text_iter = data.cbegin();
        regex rgxdont("don\\'t\\(\\)");
        smatch dontmatch;

        while(regex_search(text_iter,text_end,dontmatch,rgxdont)) {
            text_iter = dontmatch[0].second;
            donts.push_back(dontmatch[0].second);
        }

        donts.push_back(text_end);
        smatch match;
        regex rgx("mul\\([0-9]{1,3}\\,[0-9]{1,3}\\)");
        int i = 0;
        while( i < dos.size()) {

            text_iter = dos[i];
            int k = 0;
            while( donts[k] < dos[i]) {
                ++k;
            }

            while(regex_search(text_iter,donts[k], match, rgx)) {
                text_iter = match[0].second;
                regex nrgx("[0-9]{1,3}");
                smatch nmatch;
                string::const_iterator number_iter = string(match[0].first, match[0].second).cbegin();
                string::const_iterator number_end = string(match[0].first, match[0].second).cend();
                int j = 0;
                int n1;
                int n2;

                while(regex_search(number_iter,number_end, nmatch, nrgx) && j < 2) { 
                    number_iter = nmatch[0].second;
                    if (j == 0)  n1 = stoi(string(nmatch[0].first, nmatch[0].second));
                    else n2 = stoi(string(nmatch[0].first, nmatch[0].second));
                    j++;
                }
                totalMul += n1*n2;

            }
            while(dos[i] < donts[k]) i++;
        }
        cout << totalMul;
    }
}