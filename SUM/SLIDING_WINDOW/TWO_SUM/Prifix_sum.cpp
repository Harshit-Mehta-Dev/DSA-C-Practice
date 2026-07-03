/*#include<bits/stdc++.h>
using namespace std;
vector<int> buildPrifixSum(vector<int>&arr){ 
    int n=arr.size(); //to store the size of the array
    vector<int> prefix(n); //to store the prefix sum
    prefix[0]=arr[0]; //to store the first element of the prefix sum
    for(int i=1;i<n;i++){ //to store the prefix sum
        prefix[i]=prefix[i-1]+arr[i];
    }
    return prefix;
}
int rangSum(vector<int>& prefix ,int start,int end){ 
    if(start==0){ //to store the sum of the range
        return prefix[end];
    }
    return prefix[end]-prefix[start-1]; //to store the sum of the range
}
int main(){ //to store the sum of the range
    vector<int>arr={4,2,-3,6,1,-2}; //to store the sum of the range
    vector<int>prefix=buildPrifixSum(arr); //to store the sum of the range
    cout<<"sum from index 0 to 2"<<rangSum(prefix,0,2)<<endl; //to store the sum of the range
}*/

//Find the sum in the array where the sum of elements in the left equals sum of element in right [-7,1,5,2,-4,3,0]
#include <iostream>
#include <vector>
using namespace std;
int findEquilibriumIndex(const vector<int>& arr) {
    int totalSum = 0;
    // Calculate total sum of the array
    for (int num : arr) {
        totalSum += num;
    }
    int leftSum = 0;
    for (int i = 0; i < arr.size(); i++) {
        // rightSum is totalSum - leftSum - arr[i]
        int rightSum = totalSum - leftSum - arr[i];
        if (leftSum == rightSum) {
            return i;
        }
        // Add current element to leftSum for the next iteration
        leftSum += arr[i];
    }
    return -1; // Return -1 if no equilibrium index is found
}
int main() {
    vector<int> arr = {-7, 1, 5, 2, -4, 3, 0};
    int index = findEquilibriumIndex(arr);
    if (index != -1) {
        cout << "The equilibrium index is: " << index << endl;
        cout << "The value at this index is: " << arr[index] << endl;
    } else {
        cout << "No equilibrium index found." << endl;
    }
    return 0;
}
