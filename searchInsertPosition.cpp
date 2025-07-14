// Given a sorted array of distinct integers and a target value, return the index if the target is found. 
// If not, return the index where it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int s = 0;
        int e = n-1;
        int ans = n;

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