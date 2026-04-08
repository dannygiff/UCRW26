// Includes the entire std library for C++
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int edd(int, int, vector<vector<int>>&, vector<char>&, vector<char>&);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;
    int i = n;

    vector<char>key;
    vector<char>input;
    char temp = '0';

    while(i--)
    {
        cin >> temp;
        key.push_back(temp);//"sheldon's answers"
    }
    i = n;
    while(i--)
    {
        cin >> temp;
        input.push_back(temp);//"raj's answers"
    }

    //initialize
    vector<vector<int>> res(n+1, vector<int>(n+1, -1));

    int answer = edd(n,n,res,key,input);
    cout << answer;
}

int edd(int i, int j, vector<vector<int>> &res, vector<char> &key, vector<char> &input)
{
    if(res[i][j] != -1)
    {
        return res[i][j];
    }

    if(i==0 || j==0)
    {
        res[i][j] = max(i,j);
    }else if(key[i-1] == input[j-1]){
        //check if the characters at the end match
        // -1 to not go out of bounds
        res[i][j] = edd(i-1, j-1, res, key, input);
    }else{
        int first = edd(i-1, j, res, key, input) + 1;
        int second = edd(i, j-1, res, key, input) + 1;
        int both = edd(i-1, j-1, res, key, input) + 1;
        res[i][j] = min({first, second, both});
    }

    return res[i][j];
}
