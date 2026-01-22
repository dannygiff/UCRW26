// Includes the entire std library for C++
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void mergeSort(vector<int>&, int, int);
void merge(vector<int>&, int, int, int);

int candies = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;
    int dummy = 0;
    vector<int> vals;
    while(n--)
    {
        cin >> dummy;
        vals.push_back(dummy);
    }

    cout << "before: ";
    for(auto x : vals)
        cout << x << " ";

    mergeSort(vals, 0, vals.size() - 1);
    cout << "\nafter: ";
    for(auto x : vals)
        cout << x << " ";
    
    cout << "\ncandies: " << candies;
}

void mergeSort(vector<int> & arr, int l, int r)
{
    //base case
    if (l >= r)
    {
        return;
    }

    int m = l + (r - l) / 2; //middle
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

void merge(vector<int> &arr, int l, int m, int r)
{
    cout << "\ncalled merge(arr, " << l << ", " << m << ", " << r << ") ";

    int nLeft = m - l + 1;
    vector<int> left(nLeft);
    for(int i=0; i<nLeft; i++)
    {
        left[i] = arr[l + i];
    }

    cout << "\nleft: ";
    for (auto x : left)
        cout << x << " ";

    int nRight = r - m;
    vector<int> right(nRight);
    for(int i=0; i<nRight; i++)
    {
        right[i] = arr[m + i + 1]; //off by 1?
    }

    cout << "\nright: ";
    for (auto x : right)
        cout << x << " ";

    int it1 = 0;//i
    int it2 = 0;//j
    int it3 = l;//k

    while (it1 < nLeft && it2 < nRight){
        if(left[it1] < right[it2])
        {
            arr[it3] = left[it1];
            it1++;
        }else{
            arr[it3] = right[it2];
            it2++;
        }
        it3++;
    }

    while (it1 < nLeft){
        arr[it3] = left[it1];
        it1++;
        it3++;
    }

    while (it2 < nRight){
        arr[it3] = right[it2];
        it2++;
        it3++;
    }

    //merge done, find candies
    cout << "\nmerge done ";
    int min = *min_element(left.begin(), left.end());
    int temp = *min_element(right.begin(), right.end());
    if (temp < min)
        min = temp;

    int max = *max_element(left.begin(), left.end());
    temp = *max_element(right.begin(), right.end());
    if (temp > max)
        max = temp;
    int diff = max - min;
    cout << "\nadding " << diff << " candies";
    candies += diff;
}
