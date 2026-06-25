#include<iostream>
using namespace std;
void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    int arr[]={64,34,25,12,22};
    int n=5;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    insertionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

/* 
// LeetCode Vector version of Insertion Sort
#include <vector>

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int key = nums[i];
            int j = i - 1;
            
            // Move elements of nums[0..i-1], that are greater than key, 
            // to one position ahead of their current position
            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = key;
        }
        return nums;
    }
};

int main_leetcode() {
    Solution sol;
    vector<int> nums = {5, 2, 3, 1};
    
    cout << "Input: ";
    for(int num : nums) cout << num << " ";
    cout << "\n";
    
    sol.sortArray(nums);
    
    cout << "Output: ";
    for(int num : nums) cout << num << " ";
    cout << "\n";
    
    return 0;
}
*/