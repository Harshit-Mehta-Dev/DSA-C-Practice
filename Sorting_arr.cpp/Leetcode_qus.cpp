/* SORT AN ARRAY:-
Given an array of integers nums, sort the array in ascending order and return it.
You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
Example 1:
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.
Constraints:
1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104*/
//---------------------------------------------------------------------------------//

//Bubble Sort
/*class Solution {
public:
    vector<int> sortArray(vector<int>& nums){
        int n = nums.size();
        for (int i=0;i<n-1;++i){
            bool swapped = false;
            for (int j=0;j<n-i-1;j++){
                if (nums[j]>nums[j+1]){
                    int temp=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=temp;
                    swapped=true;
                }
            }
            if (!swapped){
                break;
            }
        }
        return nums;
    }
};*/

//Insertion Sort
/*class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i=1;i<n;i++){
            int key=nums[i];
            int j=i-1;
            while (j>=0 && nums[j]>key){
                nums[j+1]=nums[j];
                j--;
            }
            nums[j+1]=key;
        }
        return nums;
    }
};*/

//Selection Sort
/*class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i=0;i<n-1;i++){
            int minIndex = i;
            for (int j=i+1;j<n;j++){
                if (nums[j]<nums[minIndex]){
                    minIndex = j;
                }
            }
            if (minIndex !=i){
                int temp=nums[i];
                nums[i]=nums[minIndex];
                nums[minIndex]=temp;
            }
        }
        return nums;
    }
};*/

//Merge Sort
class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<int> L(n1), R(n2);
        for (int i = 0; i < n1; i++) L[i] = nums[left + i];
        for (int j = 0; j < n2; j++) R[j] = nums[mid + 1 + j];
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) nums[k++] = L[i++];
            else nums[k++] = R[j++];
        } 
        while (i < n1) nums[k++] = L[i++];
        while (j < n2) nums[k++] = R[j++];
    }
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

//count the accurance in a string ous:-