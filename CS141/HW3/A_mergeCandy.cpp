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

    sort(vals.begin(), vals.end());
    for (auto x : vals)
    {
        cout << x << " ";
    }
    cout << endl;
    int count = 0;
    int sz = vals.size();
    // for(int i=0; i<sz - 1; i++)
    // {
    //     cout << "\ncounting " << vals[0] << " + (c: " << count << ")";
    //     count += vals[0];  //x
    //     cout << "\ncounting  " << vals[1] << " + (c: " << count << ")";
    //     count += vals[1];  //y
    //     cout << "\nmerging " << vals[0] << " + " << vals[1];
    //     vals[1] += vals[0];
    //     cout << "\ncounting " << vals[1] << " + (c: " << count << ")";
    //     count += vals[1];
    //     cout << "\nerasing " << vals[0];
    //     vals.erase(vals.begin());
    //     cout <<"\ndone, vals[0]: " << vals[0] << "   c: " << count << endl;
    // }

    vector<int>res;
    while(vals.size() > 1)
    {
        count = 0;
        count += vals[0];  //x
        count += vals[1];  //y
        vals[1] += vals[0];
        vals.erase(vals.begin());
        count += vals[0];
        res.push_back(count);
    }
    count = 0;
    for(auto x : res)
        count += x;
    cout << count;
}