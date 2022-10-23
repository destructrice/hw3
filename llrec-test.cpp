#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------





int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file and a pivot value"<< endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------

    /***
   Test cases consist of   {
       1 - setup block
       2 - running the under-test functionality
       3 - checking the results (assertions block) - will need a framework like GTEST
   }
    ***/

    /***
    *   Test llpivot
    *
    **/
    //1. set up block

    Node* smaller; //smaller and larger can contain garbage initially
    Node* larger;

    /***
    *   2 - Test cases:
    *   Test-1: llpivot with a real list
    *
    **/
    Node* head= readList(argv[1]);;
    cout << "Original list: ";
    print(head);
    //int pivot = stoi(argv[2]);
    cout << "Testing llpivot with a real list ";
		int pivot = 10;
    cout << "Pivot value: "<<pivot<<endl;
    llpivot(head, smaller, larger, pivot);
    cout << "Items smaller than pivot: "<<endl;
    print(smaller);
    cout << "Items larger than pivot:  "<<endl;
    print(larger);
    dealloc(head);
    // dealloc(smaller);
    // dealloc(larger);
    head=NULL;

    //Test 2: Testing llpivot with empty list

    llpivot(head, smaller, larger, pivot);
    cout << "Testing llpivot with an empty list ";
    cout << "Pivot value: "<<pivot<<endl;
    cout << "Items less than or equal to pivot: "<<endl;
    print(smaller);
    cout << "Items larger than pivot:  "<<endl;
    print(larger);

    // Test filter
    cout << "Reading the filter test file: ";
    head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    Comp evenTest;
    // Filter the given list by retailing only the odd numbers
    llfilter(head,evenTest);
    cout << "Filtered list: ";
    print(head);
    dealloc(head);

    
    return 0;

}
