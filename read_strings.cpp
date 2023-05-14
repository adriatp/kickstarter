#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    std::vector<string> words;
    string str;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> m;
        getline(cin, str);
        for (int j=0; j<m; j++) {
            getline(cin, str);
            words.push_back(str);
        }
    }
    for (auto i = words.begin(); i != words.end(); i++) {
        cout << *i << endl;
    }
    return 0;
}
