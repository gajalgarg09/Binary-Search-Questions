// Given a sorted array arr[] and an integer x, find the index (0-based) of the largest element in arr[] 
// that is less than or equal to x. This element is called the floor of x. If such an element does not exist, return -1.
// Note: In case of multiple occurrences of ceil of x, return the index of the last occurrence.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:

    int findFloor(vector<int>& arr, int x) {
        // Your code here
        int s = 0, e = arr.size() - 1;
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] <= x) {
            ans = mid;      // Possible floor (update to current mid)
            s = mid + 1;    // But try to find further right
        } else {
            e = mid - 1;
        }
    }

    return ans; 
    }
};
