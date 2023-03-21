//Elif Yildiz 211101046
#include <stdio.h>
#include <stdlib.h>


struct listNode { 
    int data;     // each node contains an int 
    struct listNode *nextPtr;  // pointer to next node 
}; 
 
typedef struct listNode ListNode;    
typedef ListNode *ListNodePtr;

//Methods
ListNode * createNode(int data);
void insertAtBeginning(ListNodePtr *head, int data);
void insertAtEnd(ListNodePtr *head, int data);
void insertAtPosition(ListNodePtr *head, int data, int position);
void deleteNode(ListNodePtr *head, int data);
void reverseList(ListNodePtr *head);
void printList(ListNodePtr head);



int main(){

    //1.
    ListNodePtr head = NULL;
    ListNodePtr *headPtr = &head;

    //2.
    /*
    insertAtBeginning(&head, 11);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    */
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 11);
   

    printList(head);
    
    //3.
    insertAtEnd(&head,13);
    printList(head);

    //4.
    insertAtPosition(&head,17,3);
    printList(head);

    //5.
    insertAtBeginning(&head,19);
    printList(head);

    //6.
    deleteNode(&head,19);
    printList(head);

    //7.
    reverseList(&head);
    printList(head);

    //8.
    printList(head);


    return 0;
}

ListNode * createNode(int data){

    ListNodePtr newNode;
    newNode =(ListNodePtr) malloc(sizeof(ListNode));
    newNode->data = data;
    return newNode;

}

void insertAtBeginning(ListNodePtr *head, int data){

    ListNodePtr newNode = createNode(data);
    newNode->nextPtr = (*head);
    *head = newNode;
}

void insertAtEnd(ListNodePtr *head, int data){

    ListNodePtr newNode = createNode(data);
    newNode->nextPtr = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    ListNodePtr temp = *head;

    while(temp->nextPtr != NULL){

        temp = temp->nextPtr;
    }

    temp->nextPtr = newNode;
}

void insertAtPosition(ListNodePtr *head, int data, int position){

    if(position == 0){
        insertAtBeginning(head,data);
        return;
    }

    ListNodePtr newNode = createNode(data);
    ListNodePtr temp = *head;

    for(int i=1; i < position; i++) {//2

        if(temp->nextPtr != NULL) {
            temp = temp->nextPtr;
        }
    }


    newNode->nextPtr = temp->nextPtr;
    temp->nextPtr = newNode;

}

void deleteNode(ListNodePtr *head, int data){//free!!! (d)

    ListNodePtr temp = *head;
    ListNodePtr temp1 = temp->nextPtr;
    
    // Check if the node to be deleted is the first node
    if(temp->data == data){

        *head = temp->nextPtr;
        free(temp); 
        return;//ends there

    }

    while(temp != NULL){ 

        if(temp1->data == data){

            temp->nextPtr= temp->nextPtr->nextPtr;
            free(temp1); 
            break;

        }

        temp = temp->nextPtr;

        if(temp != NULL) { 
            temp1 = temp->nextPtr;
        }
    }
}



void reverseList(ListNodePtr *head){

    ListNodePtr prev = NULL;
    ListNodePtr current = *head;
    ListNodePtr next = NULL;

    while (current != NULL) {
        
        next = current->nextPtr;
 
        
        current->nextPtr = prev;
 
        prev = current;
        current = next;
    }

    *head = prev;
}



void printList(ListNodePtr p) {

  while (p != NULL) {

    printf("%d ", p->data);
    p = p->nextPtr;

  }

  printf("\n");
}
