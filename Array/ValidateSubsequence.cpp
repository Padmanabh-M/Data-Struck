// ValidateSubsequence
// Given two non-empty arrays of integers, find if first is a subsequence of second

#include<iostream>
#include<vector>
using namespace std;


// O(n) Time | O(1) Space
bool Validate(vector<int> array, vector<int> subseq){
    int arrid = 0;
    int seqid = 0;
    while (arrid < array.size() && seqid < subseq.size()){
        if (array[arrid] == subseq[seqid]){
            seqid++;
        }
        arrid++;
    }
    return seqid == subseq.size();
}




// O(n) Time | O(1) Space
bool Validate(vector<int> array, vector<int> subseq){
    int seqid = 0;
    for (int arr : array){            //same as saying for i in array like in python
        if (seqid == subseq.size()){
            break;
        }
        if (subseq[seqid] == arr){
            seqid++;
        }
    
   }
    return seqid == subseq.size();
}