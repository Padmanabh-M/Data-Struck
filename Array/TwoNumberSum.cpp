// Two Number Sum
// Write a program that, given an array A[] of n numbers and another number x,
// determines whether or not there exist two elements in A whose sum is exactly x.


#include<vector>
#include<iostream>
using namespace std;
#include<unordered_set> // for unordered_set
#include<algorithm> //for sort function


// O(n^2) Time | O(1) Space
vector<int> twoNumberSum(vector<int> array, int target) {
    for (int i = 0; i < array.size() - 1; i++){
        int first = array[i];
        for (int j = i+1; j < array.size(); j++){
            int second = array[j];
            if (first + second == target){
                return vector<int> {first, second};
            }
        }

    }
    
    return {};

}


// Unordered set vs maps.......
// They are nearly identical. unordered_set only contains keys,
// and no values. There is no mapping from a key to a value, so no need for an operator[].
// unordered_map maps a key to a value.

// O(n) Time | O(n) Space
vector<int> twoNumberSum(vector<int> array, int target){
    unordered_set<int> maps;
    for (int num : array){
        if (maps.find(target - num) != maps.end()){
            return vector<int> {target - num, num} ;
        }
        else{
            maps.insert(num);
        }
    }
    return {};

}





// O(nlog(n) Time .....cause of the sort function, | O(1) Space
vector<int> twoNumberSum(vector<int> array, int target){
    sort(array.begin(), array.end());
    int left = 0;
    int right = array.size() - 1;
    while (left < right){
        int current = array[left] + array[right];
        if (current == target){
            return vector<int> {array[left], array[right]};
        }
        else if (current < target){
            left++;
        }
        else if (current > target){
            right--;
        }

    }
    return {};
}



