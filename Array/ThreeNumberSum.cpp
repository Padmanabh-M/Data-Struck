// Given an array and a value,find if there is a triplet in array whose sum is equal to the given value. 
// If there is such a triplet present in array, then print the triplet


// Sample Input
// array = [12, 3, 1, 2, -6, 5, -8, 6]
// targetSum = 0

// Sample Output

// [[-8, 2, 6], [-8, 3, 5], [-6, 1, 5]]



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;





// vector< vector<int> >  a vector of vectors.


// O(n^2) time | O(n) Space
vector<vector<int>> threeNumSum(vector<int> array, int target){
    sort(array.begin(), array.end());
    vector<vector<int>> triplets;

    for (int i = 0; i < array.size() - 2; i++){

        int left = i+1;
        int right = array.size() - 1;

        while (left < right){

            int currentsum = array[i] + array[left] + array[right] ;

            if (currentsum == target){
                
                triplets.push_back({array[i], array[left], array[right]});
                left++;
                right--;

            }
            else if (currentsum < target){
                left++;
            }
            else if (currentsum > target){
                right--;
            }

        }

    }

    return triplets;
}

