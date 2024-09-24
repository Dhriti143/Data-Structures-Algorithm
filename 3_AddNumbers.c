//Addition of two numbers using linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

//create linked list
Node* createList(int data){
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = data;
    head->next = NULL;
    return head;
}

//inserts at end to get rev linked list
Node* newNode(Node* head, int value){
    Node* p = head;
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->data = value;
    ptr->next = NULL;
    while(p->next!=NULL) p=p->next;
    p->next = ptr;
    return head;
}

//number to linked list
Node* linkedList(int n){
    int mod = n%10; n/=10;
    Node* list = createList(mod);
    while(n!=0){
        mod = n%10; n/=10;
        list = newNode(list,mod);
    }
    return list;
}

//add two linked list
Node* addTwoList(Node* first, Node* second){
    int a,r;
    a=(first->data+second->data); r=a%10; a/=10;
    Node* result = createList(r);
    first=first->next; second = second->next;
    while(first!=NULL && second!=NULL){
        a+=(first->data+second->data);
        r=a%10; a/=10;
        result = newNode(result,r);
        first=first->next; second = second->next;
    }
    if(first!=NULL){
        while(first->next!=NULL){
            a+=(first->data);
            r=a%10; a/=10;
            result=newNode(result,r);
            first=first->next;
        }
        a+=first->data; r=a%10; a/=10;
        result=newNode(result,r);
        if(a!=0) result=newNode(result,a);
    }else if(second!=NULL){
        while(second->next!=NULL){
            a=(second->data);
            r=a%10; a/=10;
            result=newNode(result,r);
            second=second->next;
        }
        a+=second->data; r=a%10; a/=10;
        result=newNode(result,r);
        if(a!=0) result=newNode(result,a);
    }
    return result;
}

//prints result: result is stored in reverse order
void printList(Node* head){
    if(head==NULL) return;
    printList(head->next);
    printf("%d"
    ,head->data);
}

//driver's code
int main(){
    int a,b;
    //user input of first number
    printf("Enter first number: "); scanf("%d",&a);
    Node* list1 = linkedList(a);
    //user input of second number
    printf("Enter second number: "); scanf("%d",&b);
    Node* list2 = linkedList(b);
    //addition of two numbers
    Node* result = addTwoList(list1,list2);
    //displaying result
    printList(result);

    return 0;
}
