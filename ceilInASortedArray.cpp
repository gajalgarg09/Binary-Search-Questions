// Given a sorted array arr[] and an integer x, find the index (0-based) of the smallest element in arr[] 
// that is greater than or equal to x. This element is called the ceil of x. If such an element does not exist, return -1.
// Note: In case of multiple occurrences of ceil of x, return the index of the first occurrence.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int findCeil(vector<int>& nums, int target) {
        int n = nums.size();

        int s = 0;
        int e = n-1;
        int ans = -1;

        while(s <= e){
            int mid = s+(e-s)/2;

            if(nums[mid] >= target){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid + 1;
            }
        }

        return ans;
    }
};