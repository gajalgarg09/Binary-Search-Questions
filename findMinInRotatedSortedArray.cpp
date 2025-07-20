// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. 
// For example, the array nums = [0,1,2,4,5,6,7] might become:
// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
// Given the sorted rotated array nums of unique elements, return the minimum element of this array.
// You must write an algorithm that runs in O(log n) time.

#include<iostream>
#include<vector>
using namespace std;

// BRUTE FORCE - O(N)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int min = INT_MAX;

        for(int i =0; i<n; i++){
            if(nums[i] < min){
                min = nums[i];
            }
        }
    return min;
    }
};

// OPTIMAL APPROACH - BINARY SEARCH - O(log N)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0 , e = n-1;
        int ans = INT_MAX;

        while(s <= e){
            int mid = s + (e-s)/2;

            // left sorted array
            if(nums[s] <= nums[mid]){
                ans = min(ans , nums[s]); // finding the min on the sorted part
                s = mid+1; // eliminating the sorted part
            }




            // right sorted array
            else{
                ans = min(ans , nums[mid]);
                e = mid-1;
            }
        }
        return ans;
    }
};
