// Given a sorted matrix mat[n][m] and an element ‘x’. Find the position of x in the matrix if it is present,
// else print -1. Matrix is sorted in a way such that all elements in a row are sorted in increasing order
// and for row ‘i’, where 1 <= i <= n-1, the first element of row ‘i’ is greater than or equal to the last
// element of row ‘i-1’. The approach should have O(log n + log m) time complexity.

// Sample Input
// matrix = [
// [1, 4, 7, 12, 15, 1000],

// [2, 5, 19, 31, 32, 1001],
// [3, 8, 24, 33, 35, 1002],
// [40, 41, 42, 44, 45, 1003],
// [99, 100, 103, 106, 128, 1004],

// target = 44
// Sample Output
// [3, 3]



#include<iostream>
#include<vector>
using namespace std;


vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target){
    int row = 0;
    int col = matrix[0].size() - 1 ;

    while (row < matrix.size() && col >= 0){
        if (matrix[row][col] > target){
            col--;
        }
        else if (matrix[row][col] < target){
            row++;
        }

        else{
            return vector<int>{row, col};
        }
        return {-1,-1};
    } 
}