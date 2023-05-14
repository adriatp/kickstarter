#include <bits/stdc++.h>

using namespace std;

double get_angle(double v, double d) {
    double rad = (asin((d*9.8)/(pow(v,2)))/2);
    return ((rad != rad) ? 45 : rad * (180 / M_PI));
}

int main() {
    int n, v, d;
    double angle;
    vector<double> responses;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> v >> d;
        responses.push_back(get_angle(v,d));
    }
    for (int i = 0; i < responses.size(); i++) {
        cout << fixed << setprecision(9) << "Case #" << (i+1) << ": " << responses[i] << endl;
    }
    return 0;
}