//
// Created by Sriya Kuruppath on 10/2/22.
//

#include "llrec.h"
#include <iostream>
using namespace std;
//*********************************************
// Provide your implementation of llpivot below
//*********************************************
//helper function
void append(Node*& head, Node*& dest) {
        head->next=dest;
        dest=head;
}
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
	//set everything to null at first
    if(head == nullptr){
        smaller=NULL;
        larger=NULL;
    }
    else if (head->val > pivot) {
			//recursive call first
        llpivot(head->next, smaller, larger, pivot);
				//append after recursive call
        append(head, larger);
    }else {

			//recursive call first

        llpivot(head ->next, smaller, larger, pivot);
			//append after recursive call
        append(head, smaller);
    }
}