// Includes the entire std library for C++
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int lds(int, vector<int>&, vector<int> &);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;
    int dummy = 0;
    vector<int> vals;
    
    //init
    vector<int> res(n, -1);
    int i = 0;
    while(i++ < n)
    {
        cin >> dummy;
        vals.push_back(dummy);
    }

    int answer = 0;
    for(int i=0; i<n; i++)
    {
        res[i] = lds(i, res, vals);
        if(res[i] > answer)
            answer = res[i];
    }

    cout << answer;
}


int lds(int i, vector<int> &res, vector<int> &vals)
{
    if(res[i] != -1)
        return res[i];

    int best = 1;
    for(int j=0; j<i; j++)
    {
        if(vals[j] > vals[i])
        {
            best = max(best, 1 + lds(j, res, vals));
        }
    }
    res[i] = best;
    return res[i];
}
