/*
Question:
  11. Container With Most Water

    You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

    Find two lines that together with the x-axis form a container, such that the container contains the most water.
    Return the maximum amount of water a container can store.
    Notice that you may not slant the container.

Solved on:
    12-06-2023

Link:
  https://youtu.be/ijKmiFqjzi4?t=2600
  https://leetcode.com/problems/container-with-most-water/    
*/

// Time Complexity:  O(N) where N is size of array
// Space Complexity: O(1)

/*
APPROACH
  1. use two pointer approach, i at 0, j at n-1.
  2. Pointers will move in opposite direction.
  3. loop until the pointers cross.
  4. find min of elements at the pointers.
  5. calculate the distance between the pointers to get width.
  6. calculate the area, and update the stored area if current area is more than stored value.
  7. if arr[i] had minimum value, increment i, else decrement j.
*/

#include <iostream>
#include <vector>
using namespace std;

// calculates max area of water between the bars
int maxArea(vector<int>& height) {
  int n = height.size();    // size of the array
  int area = 0;         // store the area
  int i = 0, j = n-1;   // pointers

  int x,y;  // to store the heights of required pair of heights

  // loop until the pointers cross
  while(i < j) {
    // get minimum of the two heights
    int mini = min(height[i], height[j]);

    // calculate the area. width is difference of the pointers
    int a = mini * (j-i);

    // if the current area is greater, update values
    if(a > area) {
      area = a;
      x = height[i];
      y = height[j];
    }

    // if left height is minimum, increment left pointer
    if(height[i] == mini) i++;

    // decrement right pointer, if right height is minimum or both heights are equal
    else j--;
  }

  // print the bars just for reference
  cout << "Bars: " << x << ", " << y << endl;

  // return the area
  return area;
}

int main(int argc, char const *argv[]) {
  // test case
  vector<int> heights = {1,8,6,2,5,4,8,3,7};
  
  int ans = maxArea(heights);
  cout << "Max area: " << ans << endl;
  return 0;
}
