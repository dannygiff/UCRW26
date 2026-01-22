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

    mergeSort(vals, 0, vals.size() - 1);
    
    cout << candies;
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
    int nLeft = m - l + 1;
    vector<int> left(nLeft);
    for(int i=0; i<nLeft; i++)
    {
        left[i] = arr[l + i];
    }

    int nRight = r - m;
    vector<int> right(nRight);
    for(int i=0; i<nRight; i++)
    {
        right[i] = arr[m + i + 1]; //off by 1?
    }

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
    int min = *min_element(left.begin(), left.end());
    int temp = *min_element(right.begin(), right.end());
    if (temp < min)
        min = temp;

    int max = *max_element(left.begin(), left.end());
    temp = *max_element(right.begin(), right.end());
    if (temp > max)
        max = temp;
        
    int diff = max - min;
    candies += diff;
}
