// Includes the entire std library for C++
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n = 0;
    cin >> n;
    int dummy = 0;
    vector<int> vals;
    while(n--)
    {
        cin >> dummy;
        vals.push_back(dummy);
    }

    int count = 0;

    while (vals.size() > 1)
    {
        auto xPos = min_element(vals.begin(), vals.end());
        int x = *xPos;
        count += x;
        //cout << "\nfound " << x << "  c: " << count;
        vals.erase(xPos);

        auto yPos = min_element(vals.begin(), vals.end());
        int y = *yPos;
        count += y;
        //cout << "\nfound " << y << "  c: " << count;

        int sum = x + y;
        count += sum;

        vals.erase(yPos);
        vals.push_back(sum);

        // cout << "\nvals: ";
        // for (auto x : vals)
        //     cout << x << " ";
        // cout << endl;
    }

    cout << count;
}