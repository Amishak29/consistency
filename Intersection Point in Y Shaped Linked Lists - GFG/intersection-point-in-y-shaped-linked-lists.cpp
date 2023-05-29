//{ Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    int count1=0, count2=0;
    
    if(head1 == NULL || head2 == NULL)
        return -1;
    
    Node *start1 = head1;
    Node *start2 = head2;
    
    while(start1 != NULL) {
        start1 = start1->next;
        count1++;
    }
    
    while(start2 != NULL) {
        start2 = start2->next;
        count2++;
    }
    
    Node* start=NULL, *tmp = NULL;
    int diff = abs(count1 - count2);

    if(count1 > count2) {
        start = head1;
        tmp = head2;
    } else {
        start = head2;
        tmp = head1;
    }
    
    while(start != NULL && diff > 0) {
        start = start->next;
        diff--;
    }
        
    while(start != NULL && tmp != NULL){
        if(start == tmp)
            return start->data;
        start = start->next;
        tmp = tmp->next;
    }
    
    
    return -1;
}
