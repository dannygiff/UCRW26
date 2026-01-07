// Includes the entire std library for C++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // int t = 1;
    // cin >> t; // Keep this line if there are multiple test cases per input 
    // while (t--) {
    //     // Write the rest of the logic in here
    // }

    int n = 0;
    cin >> n; // 5 <= n <= 10^4
    vector<int> vals;
    int dummy = 0;
    for (int i=0; i<n; i++)
    {
        cin >> dummy;
        vals.push_back(dummy);
    }
    int sz = vals.size();
    int diff = vals[1] - vals[0];
    int diff2 = vals[2] - vals[1];

    if (diff != diff2)
    {
        diff = vals[4] - vals[3];
    }
    for(int i=1; i<sz; i++)
    {
        if ((vals[i] - vals[i-1]) != diff)
        {
            if (i==1)
            {
                if (vals[0] + (2*diff) != vals[2])
                {
                    cout << "1";
                }else{
                    cout << "2";
                }
            }else{
                cout << i+1;
            }
            
            break;
        }
    }
}
