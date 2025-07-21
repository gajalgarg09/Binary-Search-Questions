// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. 
// The returned integer should be non-negative as well.
// You must not use any built-in exponent function or operator.

#include<iostream>
using namespace std;

// BRUTE FORCE - LINEAR SEARCH O(N)
class Solution {
public:
    int mySqrt(int x) {
        int ans = 1;
        
        if(x == 0 || x == 1) return x;
 
        for(int i = 2; i<x; i++){
            
            if((long long)i*i <= x){
                ans = i;
            }
            else{
                break;
            }
        }
        return ans;
    }
};

// OPTIMAL APPROACH - BINARY SEARCH 
class Solution {
public:
    int mySqrt(int x) {
        if (x ==0 || x == 1) return x;
        int s = 1 , e = x/2;

        while(s<= e){
            int mid = s + (e-s)/2;
            if((long long)mid*mid == x) return mid;
            else if((long long)mid*mid >= x){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return s-1;
    }
};