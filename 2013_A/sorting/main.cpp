#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec_cases;
    int n,m,l;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> m;
        vector<int> vec_cases, vec_odds, vec_evens, results;
        vector<bool> vec_is_even(m,false);
        for (int j=0; j<m; j++) {
            cin >> l;
            vec_cases.push_back(l);
        }
        for (int j=0; j<vec_cases.size(); j++) {
            if (vec_cases[j] % 2 == 0) {
                vec_evens.push_back(vec_cases[j]);
                vec_is_even[j] = true;
            }
            else
                vec_odds.push_back(vec_cases[j]);
        }
        sort(vec_odds.begin(), vec_odds.end());
        reverse(vec_odds.begin(), vec_odds.end());
        sort(vec_evens.begin(), vec_evens.end());
        for (int j=0; j<vec_cases.size(); j++) {
            if (vec_is_even[j]) {
                results.push_back(vec_evens.back());
                vec_evens.pop_back();
            }
            else  {
                results.push_back(vec_odds.back());
                vec_odds.pop_back();
            }
        }
        cout << "Case #" << (i+1) << ":";
        for (auto r : results)    cout << " " << r;
        cout << endl;
    }
    return 0;
}