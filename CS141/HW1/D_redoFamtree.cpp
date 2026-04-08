// BFS & Queue implementation
// keep track of queue size to find max connections
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
    set<int> traitors;
    for (int i=0; i<t; i++)
    {
        cin >> dummy;
        traitors.insert(dummy);
    }


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

    map<int,bool> visited;
    queue<int>roots;
    for (auto [key, val] : adj)
    {
        roots.push(key);
        while (!roots.empty()){
            int loc = roots.front();
            visited[loc] = true;
            roots.pop();
        }
    }

    //connect(adj); //connect components

    //find largest size
    int sz = 0;
    for (auto [key,val] : adj)
    {
        if ((1 + val.size()) > sz)
            sz = 1 + val.size();
    }
    cout << sz;
}

void connect(map<int,set<int>> &m){
    for (auto [key, val] : m)
    {
        for (auto x : val)
        {
            if ( m.find(x) != m.end()) //x is a key in the map
            {
                for (auto y : m[x]) //for every y at the found key
                {
                    m[key].insert(y);
                }
                m.erase(x);
                connect(m);
            }
        }
    }
}