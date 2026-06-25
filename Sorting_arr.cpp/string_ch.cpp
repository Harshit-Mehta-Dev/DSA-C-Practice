/*#include <iostream>
using namespace std;
int main(){
    string str="hello I don't Know DSA and I am Not Willing To learn"; 
    for(int i=0;i<str.length();i++){
    cout<<str[i]<<" ";
    }
    return 0;
}*/


/*
#include<iostream>
using namespace std;
bool checkPalindrome(int arr[], int size){
    int left = 0;
    int right = size -1;
    while(left <= right){
        if(arr[left] != arr[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}
int main(){
    int arr[]= {8,9,7,9,8};
    int size = 5;
    bool ans = checkPalindrome(arr, size);
    cout<<"the given array is palindrome: "<<ans<<endl;
    return 0;
}
*/

/*#include<iostream>
#include<string>
using namespace std;
bool checkPalindromeString(string str){
    int left = 0;
    int right = str.length() - 1;
    while(left <= right){
        if(str[left] != str[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}
int main(){
    string str = "RACECAR";
    bool ans = checkPalindromeString(str);
    cout << "the given string is palindrome: " << ans << endl;
    return 0;
}*/

/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.
Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
Constraints:
1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/
//-------------------------------------------------------------------//

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // Fix 1: Removed the extra 'int' before 'right'
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (!isalnum(s[left])) {
                left++;
            } 
            else if (!isalnum(s[right])) {
                right--;
            }
            else {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                left++;
                right--;
            }
        }
        // Fix 2: Moved 'return true;' outside the while loop
        return true;
    }
};
int main() {
    Solution sol;
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = " ";
    cout << "Is '" << s1 << "' a palindrome? " << (sol.isPalindrome(s1) ? "true" : "false") << endl;
    cout << "Is '" << s2 << "' a palindrome? " << (sol.isPalindrome(s2) ? "true" : "false") << endl;
    cout << "Is '" << s3 << "' a palindrome? " << (sol.isPalindrome(s3) ? "true" : "false") << endl;
    
    return 0;
}


