// Includes the entire std library for C++
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    int t = 0;
    map <int, set<int>> adj; //adjacency map "graph"

    //get input
    cin >> n >> t;
    int dummy = 0;
    for (int i=1; i<n; i++)
    {
        cin >> dummy;
        adj[dummy].insert(i);
    }
    vector<int> traitors;
    for (int i=0; i<t; i++)
    {
        cin >> dummy;
        traitors.push_back(dummy);
    }

    //print debug
    for (auto [key,val] : adj)
    {
        cout << endl << key << " : {";
        for (auto x : val)
        {
            cout << x << " ";
        }
        cout << "}";
    }
    cout << "\nT: ";
    for (auto tr : traitors)
        cout << tr << " ";

    //////////
    //////////
    // for (auto [key,val] : adj)
    // {
    //     for (int tr : traitors)
    //     {
    //         val.erase(tr);
    //     }
    // }
    for (int tr : traitors)
        adj.erase(tr);
    for (auto it = adj.begin(); it != adj.end(); ++it)
    {
        for (int tr : traitors)
        {
            it->second.erase(tr);
        }
    }

    for (auto [key,val] : adj)
    {
        cout << endl << key << " : {";
        for (auto x : val)
        {
            cout << x << " ";
        }
        cout << "}";
    }
    
    map <int, set<int>> comp = adj; //connected components

    for (auto [key, val] : adj)
    {
        for (auto x : val)
        {
            auto it = adj.find(x);
            if (it != adj.end())
            {
                comp.erase(x);
                for (auto y : adj[x])
                {
                    comp[key].insert(y);
                }
            }
        }
    }
    cout << "\nfinal tree:";
    for (auto [key,val] : comp)
    {
        cout << endl << key << " : {";
        for (auto x : val)
        {
            cout << x << " ";
        }
        cout << "}";
    }
    set<int> sizes;
    for (auto [key,val] : comp)
    {
        sizes.insert(1 + val.size()); //root + connected components
    }
    cout << *sizes.rbegin();
}
