// Write a function that takes in a sorted array of integers as well as a target integer.
// The function should use the Binary Search algorithm to determine if the target integer
// is contained in the array and should return its index if it is, otherwise -1.




// Recursive
#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target);
int binarySearchHelper(vector<int> array, int target, int left, int right);

// O(log(n)) time | O(log(n)) Space
int binarySearch(vector<int> array, int target){
    return binarySearchHelper(array, target, 0, array.size() - 1);
}


int binarySearchHelper(vector<int> array, int target, int left, int right){
    if (left > right){
        return -1;
    }

    int middle = (left + right) / 2;
    int potentialMatch = array[middle];

    if (potentialMatch == target){
        return middle;
    }

    else if (target < potentialMatch){
        return binarySearchHelper(array, target, left, middle-1);
    }

    else{
        return binarySearchHelper(array, target, middle+1, right);
    }


}









// Iterative
// O(log(n)) Time | O(1) Space
int binarySearch(vector<int> array, int target){
    int left = 0;
    int right = array.size() - 1;
   
   while(left <= right){

    int middle = (left + right) / 2;
    int potentialMatch = array[middle];

    if (potentialMatch == target){
        return middle;
    }

    else if (target < potentialMatch){
        right = middle-1;
    }

    else{
        left = middle+1;
    }

   }

   return -1;

}