//array tiverse implement if condition check linear search of array {16,17,19,26,8}
/*#include<iostream>
using namespace std;
int main(){
    int arr[] = {16,17,19,26,8};
    int size = 5;
    for(int i = 0; i < size; i+1){
        if(arr[i] == 26){
            cout<<"so the element function index: "<<i<<endl;
        }
    }
    return 0;
}*/

/*//binary search:
#include<iostream>
using namespace std;
int binarySearch(int arr[], int size, int target){
    int start = 0;
    int end = size -1;
    while(start<=end){
        int mid = (start+end)/2;
        // condition 1:
        if(arr[mid]==target){
            return mid;
        }
        // condition 2:
        else if(arr[mid]<target){
            start = mid+1;
        }
        // condition 3:
        else{
            end = mid-1;
        }
    }
    return -1; // element not found
}
int main(){
    int arr[]={2,5,8,12,16,23,38,56,72,91};
    int size = 10;
    int target;
    cout<<"enter the number to search"<<endl;
    cin>>target;
    int result = binarySearch(arr,size,target);
    cout<<"we got the element at index"<<result<<endl;
    return 0;
}*/
/*Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.You must write an algorithm with O(log n) runtime complexity.
Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
Constraints:
1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order.*/
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
};
