// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.

#include<iostream>
#include<vector>
using namespace std;

// BRUTE FORCE - O(N)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);

        int n = nums.size();
        int first = -1;
        int last = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                ans[0] = i;
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == target) {
                ans[1] = i;
                break;
            }
        }
        return ans;
    }
};

// BRUTE FORCE - O(N)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1, last = -1;

        for(int i =0; i<n; i++){
            if(nums[i] == target){
                if(first == -1){
                    first = i;
                }
                last = i;
            }
        }
        return {first , last};
    }
};

//OPTIMAL APPROACH - BINARY SEARCH
class Solution {
private:
    int lowerBound(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        int ans = nums.size();

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] >= target) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }

    int upperBound(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        int ans = nums.size();

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] > target) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums, target);
        int last = upperBound(nums, target) - 1;

        if (first <= last && first < nums.size() && nums[first] == target) {
            return {first, last};
        }
        return {-1, -1};
    }
};