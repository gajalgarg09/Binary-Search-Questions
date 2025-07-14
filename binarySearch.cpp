#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ITERATIVE APPROACH 
int binarySearch(vector<int> nums , int target){

    int s = 0;
    int e = nums.size() - 1;

    while(s <= e){
        int mid = s + (e-s)/2;

        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return -1;
}

// RECURSIVE APPROACH
int binarySearchRecursive(vector<int> nums , int s , int e , int target){

    while(s <= e){
        int mid = s + (e-s)/2;

        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            return binarySearchRecursive(nums , mid+1, e , target);
        }
        else{
            return binarySearchRecursive(nums , s , mid-1, target);
        }
    }
}

int main(){

    vector<int> nums = {2,5,7,9,34,78,90,126};
    int ans = binarySearch(nums , 78);
    cout << "Iterative approach : " << ans << endl;

    int ans2 = binarySearchRecursive(nums , 0 , 7 , 78);
    cout << "Recursive approach : " << ans2 << endl;
    return 0;
}