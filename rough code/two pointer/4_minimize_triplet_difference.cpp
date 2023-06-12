/*
Question:
  Minimize absolute difference of a triplet
    Given 3 sorted arrays, find the minimum absolute difference of max(a,b,c) and min(a,b,c), where 'a' belongs to A, 'b' belongs to B and 'c' belongs to C.
    
    You need to select one element from each of the arrays and then find max and min of those elements and then take absolute difference. The task is to select elements in such a way that the difference is minimum.

    You need to minimize the value of |max(a,b,c)-min(a,b,c)|
    The elements can be repeated and sorted in non-decreasing order

Solved on:
    12-06-2023

Link:
  https://youtu.be/ijKmiFqjzi4?t=1554
  https://www.geeksforgeeks.org/smallest-difference-triplet-from-three-arrays/
    
*/

// Time Complexity:  O(|A|+|B|+|C) where A,B,C are the given arrays
// Space Complexity: O(1)

/*
APPROACH
  1. use two pointer approach, but with 3 pointers, i,j,k, all at first indices of respective arrays.
  2. Pointers will move in forward direction.
  3. loop until any of the pointers reaches end of its array.
  4. find min and max of the selected elements.
  5. if difference is less than previous stored diff, update it.
  6. now increment the pointer which points to element equal to min.
  7. in step 6, equal elements will also be taken care of automatically.
*/



#include<iostream>
#include<vector>
using namespace std;

// returns max of 3 numbers
int max3(int x, int y, int z) {
  return max(max(x,y), z);
}
// returns min of 3 numbers
int min3(int x, int y, int z) {
  return min(min(x,y), z);
}

// returns the minimum absolute difference of a triplet
int minimizeMinMaxDifference(vector<int> &v1, vector<int> &v2, vector<int> &v3){
  // array sizes
  int n1 = v1.size(), n2 = v2.size(), n3 = v3.size();

  // pointers for the arrays
  int i = 0, j = 0, k = 0;

  // to store the triplet with minimum difference of max and min
  int l,m,n;

  // initially take difference to be maximum possible value
  int diff = INT_MAX;

  // loop until any one of the arrays end
  while(i<n1 && j<n2 && k<n3) {
    // select the values at i,j,k
    int x = v1[i], y = v2[j], z = v3[k];

    // get max and min
    int maxi = max3(x,y,z);
    int mini = min3(x,y,z);

    // if current diff is less than previous stored diff, update
    if(min(diff, maxi-mini) < diff){
      diff = min(diff, maxi-mini);
      l=x, m=y, n=z;
    }

    // move first pointer forward if it was at minimum element
    if(mini == x) i++;

    // move second pointer forward if it was at minimum element
    if(mini == y) j++;

    // move third pointer forward if it was at minimum element
    if(mini == z) k++;
  }

  // display triplet that had minimum difference of max and min
  cout << l << " " << m << " " << n << ": ";

  // return answer
  return diff;
}


int main(int argc, char const *argv[]) {
  // test case
  vector<int> A = {1,4,5,8,10,100};
  vector<int> B = {6,9,10,15,200};
  vector<int> C = {2,3,6,10,6,300};

  int res = minimizeMinMaxDifference(A, B, C);
  cout << res << endl;

  return 0;
}
