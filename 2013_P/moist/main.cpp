#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m, changes;
    std::vector<string> words;
    std::vector<int> responses;
    string str;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> m;
        getline(cin, str);
        for (int j=0; j<m; j++) {
            getline(cin, str);
            words.push_back(str);
        }
        if (m > 0) {
            string max_string = words[0];
            changes = 0;
            for (auto k = words.begin(); k < words.end(); k++) {
                string actual_word = *k;
                if (max_string.compare(actual_word) > 0)
                    changes++;
                else
                    max_string = actual_word;
            }
            responses.push_back(changes);
        }
        words.clear();
    }
    for (int i = 0; i < responses.size(); i++) {
        cout << "Case #" << (i+1) << ": " << responses[i] << endl;   
    }

    return 0;
}