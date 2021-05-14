// Write a function that takes a list sorted in non-decreasing order and deletes any duplicate nodes from the list.
// The list should only be traversed once. For example if the linked list is 11->11->11->21->43->43->60 
// then removeDuplicates() should convert the list to 11->21->43->60.



#include<iostream>
#include<vector>
using namespace std;



class LinkedList{
    public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int val){
        value = val;
    }
};


LinkedList *RemoveDuplicates(LinkedList *linkedlist){
    LinkedList *currentnode = linkedlist;
    while (currentnode != nullptr){

        LinkedList *nextDistinctnode = currentnode->next;
        while (nextDistinctnode != nullptr && nextDistinctnode->value == currentnode->value){
            nextDistinctnode = nextDistinctnode->next;
        }

        currentnode->next = nextDistinctnode;
        currentnode = nextDistinctnode;
    }

    return linkedlist;
}