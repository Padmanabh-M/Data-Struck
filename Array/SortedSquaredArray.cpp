// Write a function that takes in a non-empty array of integers
// that are sorted in ascending order and returns a new array of the same
// length with the squares of the original integers also sorted in ascending order.

// Sample Input
// array = [1, 2, 3, 5, 6, 8, 9]

// Sample Output
// [1, 4, 9, 25, 36, 64, 81]



#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>     //for abs
#include <cstdlib>
using namespace std;

// O(n) time | O(n) Space
vector<int> sorta(vector<int> Sarray){
    vector<int> sortedSQ(Sarray.size(), 0 );
    int smaller = 0;
    int larger = Sarray.size() - 1;

    for (int id = Sarray.size() - 1; id >= 0 ; id--){

        int smallerval = Sarray[smaller];
        int largerval = Sarray[larger];

        if (abs(smallerval) > abs(largerval) ){

            sortedSQ[id] = smallerval*smallerval ;
            smaller++;
        }
        else{
            sortedSQ[id] = largerval*largerval ;
            larger--;
        }

    }
    return sortedSQ;
}
