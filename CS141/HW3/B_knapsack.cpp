// Includes the entire std library for C++
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int knap(int, int, vector<vector<int>>&, vector<pair<int,int>>);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int w = 0;
    cin >> w;
    int n = 0;
    cin >> n;
    int sz = n;
    int dumW = 0;
    int dumV = 0;
    vector<int> value;
    vector<int> weight;
    vector<pair<int,int>> item;
    while(n--)
    {
        cin >> dumW;
        weight.push_back(dumW);
        cin >> dumV;
        value.push_back(dumV);
        item.push_back({dumW, dumV});
    }

    int total = 0;

    for (auto x : item)
    {
        cout << endl << x.first << " " << x.second;
    }
    cout << "\nsort?";
    sort(item.begin(), item.end());
    for (auto x : item)
    {
        cout << endl << x.first << " " << x.second;
    }
    cout << endl;
    vector<vector<int>> res;
    for(int i=0; i<sz; i++)
    {
        vector<int> temp(w,-1);
        res.push_back(temp);
        cout << "w";
    }
    for(int i=0; i<sz; i++)
    {
        cout << endl;
        for(int j=0; j<w; j++)
        {
            res[i][j] = knap(i,j,res,item);
            cout << res[i][j] << " ";
        }
    }

}

int knap(int i, int j, vector<vector<int>>&res, vector<pair<int,int>> item)
{
    if(res[i][j] != -1) //already calculated
        return res[i][j];
    
    bool invalid = (i<1 || j <0);
    if (invalid)
        return 0;
    
    return max(knap(i-1, j - item[i].first, res, item) + item[i].second, knap(i-1, j, res, item));
    return 0;
}
