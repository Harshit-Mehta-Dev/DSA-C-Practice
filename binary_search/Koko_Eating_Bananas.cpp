/*
===========================================================================
PROBLEM: Koko Eating Bananas (LeetCode 875)
===========================================================================

UNDERSTANDING THE PROBLEM:
--------------------------
Koko loves to eat bananas. There are 'n' piles of bananas, where the i-th 
pile has piles[i] bananas. The guards have left and will return in 'h' hours.

- Koko can decide her eating speed: 'k' bananas per hour.
- Each hour, she chooses one pile and eats up to 'k' bananas from it.
- If the pile has fewer than 'k' bananas, she finishes the pile and WAITS 
  until the next hour (she cannot carry over her eating speed to another pile).
- She wants to finish all bananas before the guards return (in 'h' hours).

GOAL: Find the MINIMUM eating speed 'k' so that Koko eats all the bananas 
within 'h' hours.


THE APPROACH: BINARY SEARCH ON ANSWER SPACE
-------------------------------------------
Why use Binary Search here? Because the problem has a "monotonic" property:
- If Koko can finish all bananas at speed 'k', she can definitely finish 
  them at speed k+1, k+2, etc. (Any faster speed is also valid).
- If Koko CANNOT finish at speed 'k', she definitely cannot finish at 
  speed k-1, k-2, etc. (Any slower speed is invalid).

Since there is a clear breaking point between "too slow" and "fast enough",
we can search for the perfect speed using Binary Search!

1. Define the Boundaries:
   - Minimum Speed (low): 1 banana per hour.
   - Maximum Speed (high): The largest pile size in the array (max(piles)).
     (Eating faster than the largest pile doesn't save any time, because 
     she can only eat from ONE pile per hour anyway).

2. Binary Search Logic:
   - Calculate `mid` (our guessed speed).
   - Calculate how many hours it takes to eat all bananas at speed `mid`.
     - Hours for a pile = ceil(pile_size / mid)
   - If total hours <= h (She is fast enough):
       This speed works! Save it as a potential answer.
       Try to find a SLOWER speed that might also work (high = mid - 1).
   - If total hours > h (She is too slow):
       She must eat FASTER (low = mid + 1).

TIME COMPLEXITY:
----------------
- Finding the max element: O(N)
- Binary Search runs O(log(Max Pile Size)) times.
- Calculating hours takes O(N) each time.
- Total Time Complexity: O(N * log M), where M is the maximum pile size.

===========================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    // Helper function to calculate total hours required at a given speed 'k'
    long long calculateHours(const vector<int>& piles, int k) {
        long long totalHours = 0;
        for (int pile : piles) {
            // (pile + k - 1) / k is a clever integer-math way to do ceil(pile / (double)k)
            totalHours += (pile + k - 1) / k; 
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        
        // Find the maximum pile to set as our highest possible eating speed
        int high = *max_element(piles.begin(), piles.end());
        int ans = high; // Default answer is the maximum speed

        // Binary Search on the speed
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hours = calculateHours(piles, mid);

            if (hours <= h) {
                ans = mid;        // This speed works! Save it.
                high = mid - 1;   // Let's see if she can afford to eat even slower
            } else {
                low = mid + 1;    // Too slow, she needs to eat faster
            }
        }
        
        return ans;
    }
};

// Driver code to test the solution
int main() {
    Solution sol;
    
    // Example 1
    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    cout << "Example 1:" << endl;
    cout << "Piles: [3, 6, 7, 11], Guards return in: " << h1 << " hours." << endl;
    cout << "Minimum Eating Speed: " << sol.minEatingSpeed(piles1, h1) << " bananas/hour" << endl;
    // Expected output: 4
    
    cout << "---------------------------------" << endl;

    // Example 2
    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;
    cout << "Example 2:" << endl;
    cout << "Piles: [30, 11, 23, 4, 20], Guards return in: " << h2 << " hours." << endl;
    cout << "Minimum Eating Speed: " << sol.minEatingSpeed(piles2, h2) << " bananas/hour" << endl;
    // Expected output: 30

    return 0;
}
