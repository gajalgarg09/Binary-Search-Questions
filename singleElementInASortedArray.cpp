// You are given a sorted array consisting of only integers where every element appears exactly twice, 
// except for one element which appears exactly once.
// Return the single element that appears only once.
// Your solution must run in O(log n) time and O(1) space.

#include<iostream>
#include<vector>
using namespace std;

// BRUTE FORCE - USING XOR - O(N)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int  ans = 0;

        for(int i =0; i<n; i++){
            ans ^= nums[i];
        }
        return ans;
    }
};

// OPTIMAL APPRAOCH - BINARY SEARCH - log(N)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 1 , e = n-2;

        // edge cases 
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        while(s <= e){
            int mid = s + (e-s)/2;

            // checking of the mid is the answer
            if(nums[mid -1] != nums[mid] && nums[mid] != nums[mid+1]){
                return  nums[mid];
            }
            // elimination part
            else{
                if((mid % 2 == 0 && nums[mid+1] == nums[mid]) || (mid % 2 == 1 && nums[mid-1] == nums[mid])){
                    // eliminate left part
                    s = mid+1;
                }
                else{
                    e = mid-1;
                }
            }
        }
    return -1;
    }
};