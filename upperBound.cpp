// Given a sorted array arr[] and a number target, the task is to find the upper bound of the target in this given array.
// The upper bound of a number is defined as the smallest index in the sorted array where the element is greater than the given number.
// Note: If all the elements in the given array are smaller than or equal to the target, the upper bound will be the length of the array.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int upperBound(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        int ans = nums.size();
        
        while(s <= e){
            int mid = s + (e-s)/2;
            
            
            if(nums[mid] > target){
                ans = mid;
                e = mid -1;
            }
            else{
                s= mid + 1;
            }
        }
        return ans;
    }
};
