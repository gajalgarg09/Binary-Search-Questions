// You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then returns -1.

#include<iostream>
using namespace std;

class Solution {
  public:
    int power(int mid , int n){
        long long ans = 1;
        for(int i =1; i<=n; i++){
            ans *= mid;
        }
       return ans;
    }
    
    int nthRoot(int n, int m) {
        int s = 1 , e = m;
        while(s <= e){
            
            int mid = s +(e-s)/2;
            
            if(power(mid , n) == m) return mid;
            else if(power(mid , n) >= m) {
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        
        return -1;
    }
};