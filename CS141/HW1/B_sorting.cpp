// Includes the entire std library for C++
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    string name;
    string house;

    map<string, set<string>> roster;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> name;
        cin >> house;

        roster[house].insert(name);
    }

    for (auto [key, val] : roster)
    {
        cout << key << endl;

        for (auto n : val)
        {
            cout << n << endl;
        }
    }
}
