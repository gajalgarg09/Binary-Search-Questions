// You are given an m x n integer matrix matrix with the following two properties:
// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

#include<iostream>
#include<vector>
using namespace std;

// BRUTE FORCE
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(matrix[i][j] == target){
                    return true;
                }
            }
        }
        return false;
    }
};

// OPTIMAL SOLUTION - BINARY SEARCH - here we assume to convert the matrix into a 1D array
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int s = 0;
        int e = (m*n)-1;

        while(s<=e){
            int mid = s+(e-s)/2;

            int row = mid / n;
            int col = mid % n;

            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return false;
    }
};
