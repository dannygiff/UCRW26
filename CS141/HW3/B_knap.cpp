// Includes the entire std library for C++
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int knap(int, int, vector<vector<int>>&, vector<pair<int,int>>&);

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
    
    vector<pair<int,int>> item;
    while(sz--)
    {
        cin >> dumW;
        cin >> dumV;
        item.push_back({dumW, dumV});
    }

    sort(item.begin(), item.end());

    //initialize
    vector<vector<int>> res(w+1, vector<int>(n+1, -1));

    int answer = knap(w,n,res,item);
    cout << endl << answer;
}

int knap(int i, int j, vector<vector<int>>&res, vector<pair<int,int>> &item)
{
    // j:item count  i:remaining budget
    if(i <= 0 || j <= 0)
    {
        //res[i][j] = 0;
        return 0;
    }

    if(res[i][j] != -1) //already calculated
        return res[i][j];
    
    
    int best = knap(i, j-1, res, item);//we dont pick the item

    if (i >= item[j-1].first)
    {
        int temp = knap(i - item[j-1].first, j-1, res, item) + item[j-1].second;//we pick the item
        best = max(best,temp);
    }
    res[i][j] = best;
    return res[i][j];
}
