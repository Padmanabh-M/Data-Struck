// Write a function that takes in an array of at least 3 integers and without sorting the input
// array, returns a sorted array of the 3 largest integers in the input array.
// The function should return duplicate integers if necessary: for example, 
// it should return [10, 10, 12] for an input array of
// [10, 5, 9, 10, 12] .

// Sample Input
// array = [141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7]

// Sample Output
// [18, 141, 541]



#include<vector>
#include <climits>
using namespace std;



void updateLargest(vector<int> &threeLargest, int num);
void shiftAndUpdate(vector<int> &largest, int num, int idx);


// O(n) Time | O(1) Space
vector<int> findThreeLargestNumbers(vector<int> array){
    vector<int> threeLargest{INT_MIN, INT_MIN, INT_MIN};
    for(int num : array){
        updateLargest(threeLargest, num);
    }

    return threeLargest;
}


void updateLargest(vector<int> &threeLargest, int num){
    if (threeLargest[2] < num){
        shiftAndUpdate(threeLargest, num, 2); 
    }

    else if (num > threeLargest[1]){
        shiftAndUpdate(threeLargest, num, 1);
    }

    else if (num > threeLargest[0]){
        shiftAndUpdate(threeLargest, num, 0);
    }
}



void shiftAndUpdate(vector<int> &array, int num, int idx){
    for (int i = 0; i <= idx; i++){
        if (i == idx){
            array[i] = num;
        }
        else {
            array[i] = array[i+1];
        }
    }
}