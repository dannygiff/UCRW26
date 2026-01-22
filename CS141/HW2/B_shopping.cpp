// Includes the entire std library for C++
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k = 0;
    cin >> k;
    int n = 0;
    cin >> n;
    int dummy = 0;
    vector<int> vals;
    while(n--)
    {
        cin >> dummy;
        vals.push_back(dummy);
    }

    sort(vals.begin(), vals.end());

    int count = 0;
    while (k - vals[count] >= 0)
    {
        k -= vals[count++];
    }
    cout << count;
}

