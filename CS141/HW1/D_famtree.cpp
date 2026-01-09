// Includes the entire std library for C++
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

void connect(map<int,set<int>>&);

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

    //DEBUG
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

    //remove traitors from graph
    for (int tr : traitors)
        adj.erase(tr);
    for (auto it = adj.begin(); it != adj.end(); ++it)
    {
        for (int tr : traitors)
        {
            it->second.erase(tr);
        }
    }
   
    //DEBUG
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

    // //find connected components
    // for (auto [key, val] : adj)
    // {
    //     for (auto x : val)
    //     {
    //         auto it = comp.find(x);
    //         if (it != comp.end())
    //         {
    //             comp.erase(x);
    //             auto it2 = comp.find(key);
    //             if (it2 != comp.end())
    //             {
    //                 for (auto y : adj[x])
    //                 {
    //                     comp[key].insert(y);
    //                 }
    //             }
    //         }
    //     }
    // }

    connect(comp);

    //DEBUG
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

    //find largest size
    set<int> sizes;
    for (auto [key,val] : comp)
    {
        sizes.insert(1 + val.size()); //root + connected components
    }
    cout << *sizes.rbegin();
}

void connect(map<int,set<int>> &m){
    for (auto [key, val] : m)
    {
        for (auto x : val)
        {
            auto it = m.find(x);
            if (it != m.end()) //x is a key in the map
            {
                for (auto y : m[x]) //for every y at the found key
                {
                    if (y != key)
                        m[key].insert(y);
                }
                m.erase(x);
                connect(m);
                // comp.erase(x);
                // auto it2 = comp.find(key);
                // if (it2 != comp.end())
                // {
                //     for (auto y : adj[x])
                //     {
                //         comp[key].insert(y);
                //     }
                // }
            }
        }
    }
}