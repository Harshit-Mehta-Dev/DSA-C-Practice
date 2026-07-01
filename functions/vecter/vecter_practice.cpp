/*#include<iostream>
#include<vector> //vector is a function which is used to store the values in the form of array
using namespace std;
int main(){
    vector<int> v(5,10); //creates a vector of size 5 with all values 10
    v.push_back(6); //adds value to the last
    v.pop_back(); //removes value from the last
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    return 0;
}*/

/*#include <vector>
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
};*/

//given a sorted element find the first-occurence of target arr {1,3,3,3,5,7,9} output = 1 target = 3 hint: when you find the target don't stop try searching for left most:
#include<iostream>
using namespace std;
int firstOccurrence(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    int ans = -1; 
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            ans = mid;         
            right = mid - 1;   
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}
int main(){
    int arr[] = {1,3,3,3,5,7,9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 3;
    int result = firstOccurrence(arr, size, target);
    cout<<"The first occurrence of "<<target<<"is at index "<<result<<endl;
    return 0;
}
