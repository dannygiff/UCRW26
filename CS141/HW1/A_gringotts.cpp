// Includes the entire std library for C++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // // Fast IO
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    // int t = 1;
    // cin >> t; // Keep this line if there are multiple test cases per input 
    // while (t--) {
    //     // Write the rest of the logic in here
    // }

    int k = 0;
    cin >> k;

    int sickles = k / 29;
    k %= 29;

    int galleons = sickles / 17;
    sickles %= 17;

    cout << galleons << " " << sickles << " " << k << endl;
}
