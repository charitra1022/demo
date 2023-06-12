/*
Question:
  75. Sort Colors
    Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
    You must solve this problem without using the library's sort function.

Solved on:
  12-06-2023

Link:
  https://leetcode.com/problems/sort-colors/description/

*/

// Time Complexity:  O(N)
// Space Complexity: O(1)

/*
APPROACH
  1. use two pointer approach, s at 0, e at n-1.
  2. s will be for positioning 0's, e will be for positioning 2's
  3. Pointers will move in opposite direction.
  4. third pointer i=0 will be needed to iterate the array.
  5. loop until the i and e pointers cross (i<=e). (here <= comparison is needed, not <, as there could be a 0 at e, which will be taken care of in step 6).
  6. if arr[i]==0, swap with arr[s], increment s and increment i.
  7. if arr[i]==1, increment i.
  8. if arr[i]==2, swap with arr[e], decrement e. we won't increment i as there could have been 0 at e previously, so, it will be automatically taken care of in the next iteration of i.
*/

#include <iostream>
#include <vector>
using namespace std;

// sorts the colors in-place
void sortColors(vector<int>& nums) {
  // pointers to keep track of 0 and 2
  int s = 0, e = nums.size()-1;

  // iterator pointer
  int i = 0;

  // loop till iterator pointer crosses 2's pointer, as 2 are already placed, so no need to move ahead it
  while(i <= e) {
    // if 0 is found
    if(nums[i] == 0) {
      // swap it with element at s and increment s
      swap(nums[i], nums[s]);
      s++;
    } 
    
    // if 2 is found
    else if(nums[i] == 2) {
      // swap it with element at e and decrement e
      swap(nums[i], nums[e]);
      e--;

      // we dont increment i as may be there was a 0 at e previously
      // so, we'll take care of this case in next iteration
      continue;
    }
    i++;
  }
}

int main(int argc, char const *argv[]) {
  // test case
  vector<int> nums = {1,1,1,1,2,2,2,0,0,1};

  sortColors(nums);
  for(int i: nums) cout << i << " ";
  cout << endl;
  return 0;
}

