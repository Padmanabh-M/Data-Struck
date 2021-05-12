// Given an array of positive integers representing the values of coins in your possession, write a function that returns the minimum
// amount of change (the minimum sum of money) that you cannot create. The given coins can have any positive integer value and aren't
// necessarily unique (i.e., you can have multiple coins of the same value).

// For example, if you're given coins = [1, 2, 5] . the minimum amount of change that you can't create is 4 . If you're given no coins,
// the minimum amount of change that you can't create is 1.



#include<vector>
#include<algorithm> //for sort
using namespace std;

// O(nlogn) time......logn cause of the sort algorithm | O(1) Space
int NonConst(vector<int> coins){
    sort(coins.begin(), coins.end());

    int current = 0;      //The current change created 

    for (int coin : coins){
        if (coin > current + 1){
            
            return current + 1;

        }

        current += coin;
            
        
    }
    return current + 1;
}


