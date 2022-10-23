//
// Created by Sriya Kuruppath on 10/2/22.
//

#include "llrec.h"
#include <iostream>
using namespace std;
//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void append(Node*& head, Node*& dest) {
        head->next=dest;
        dest=head;
}
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    if(head == nullptr){
        smaller=NULL;
        larger=NULL;
    }
    else if (head->val > pivot) {
      // head=head->next;
        llpivot(head->next, smaller, larger, pivot);
        append(head, larger);
    }else {
       // head=head->next;

        llpivot(head ->next, smaller, larger, pivot);
        append(head, smaller);
    }
}