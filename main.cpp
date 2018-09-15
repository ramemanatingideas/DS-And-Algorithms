#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstdlib>

using namespace std;


struct ListNode {
    int data;
    ListNode *next;
};

ListNode *head;


struct ListNode *createNode(int data) {
   // struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
    ListNode* node = new ListNode();
    if (!node) {
        cout << "no mem available";
    }
    node->next = NULL;
    node->data = data;

    return node;
}


void insertAtBegin(int data) {

    ListNode *temp = createNode(data);
    temp->next = head;
    head = temp;
}

void insertAtEnd(int data) {
    ListNode *temp = createNode(data);
    ListNode *current = head;

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
    temp = current;

}

void insertAtPosition(int data, int n) {
    ListNode *temp1 = createNode(data);

    if (n == 1) {
        temp1->next = head;
        head = temp1;
        return;
    } else {
        ListNode *temp2 = head;

        for (int i = 0; i < n - 2; ++i) {
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
    }
}


int ListLength(ListNode *head) {
    int length = 0;
    if (head == NULL) {
        return 0;
    } else {
        while (head != NULL) {
            length += 1;
            head = head->next;
        }
    }

    return length;
}

void Delete(int position){
    ListNode* temp1 = head;
    if(position==1){
        head = temp1->next;
        free(temp1);
        return;
    }
    for (int i = 0; i <position-2; ++i) {
        temp1 = temp1->next;
    }
    ListNode* temp2 = temp1->next; //nth node
    temp1->next = temp2->next; //make temp1 to point to n+1th node
    free(temp2);
}

void PrintList() {
    ListNode *temp = head;

    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;

    }

}

void ReversePrint(ListNode* temp){

    if(temp==NULL){
        head = temp;
        return;
    }

    else{
         ReversePrint(temp->next);
         cout<<temp->data<<"->";
    }
}

void ReverseList(ListNode* temp){
    if(temp==NULL)
    {
        head = temp;
        return;
    }

    else{
        ReverseList(temp->next);
        ListNode* p = temp->next;
        p->next=temp;
        temp->next=NULL;

    }
}



int main() {

    head = NULL;
    int n = 5;

    for (int i = 0; i < n; ++i) {
        insertAtBegin(i);
    }
    PrintList();
    cout << "after inserting in the end"<<endl;


    insertAtEnd(3);
    insertAtEnd(7);

    PrintList();

    cout << "after inserting at nth position" << endl;
    insertAtPosition(10, 5);
    PrintList();

    Delete(3);
    cout<<"after deleting"<<endl;
    PrintList();

    cout<<endl;
    ReversePrint(head);

    //ReverseList(head);

//    for (int i = 0; i < n; ++i) {
//        Delete(i);
//    }

    return 0;
}


