//{ Driver Code Starts
//

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

// } Driver Code Ends
/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{
  public:
    Node *sortedInsert(struct Node* head, int data) {
        Node* temp=new Node(data);
        if(head==NULL){
            return temp;
        }
        if(head->next==NULL){
            if(temp->data<head->data){
                temp->next=head;
                return temp;
            }
            else{
                head->next=temp;
                return head;
            }
        }
        if(temp->data<head->data){
            temp->next=head;
            return temp;
        }
        Node* curr=head;
        Node* n=head->next;
        bool flag=false;
        while(curr&&n){
            if(temp->data>=curr->data&&temp->data<n->data){
                curr->next=temp;
                temp->next=n;
                flag=true;
                break;
            }
            curr=n;
            n=n->next;
        }
        if(flag==false){
            curr->next=temp;
        }
        return head;
    }
};


//{ Driver Code Starts.
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
        
		int data;
		cin>>data;
		
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		int k;
		cin>>k;
		Solution obj;
		head = obj.sortedInsert(head,k);
		printList(head); 
	}
	return 0; 
} 

// } Driver Code Ends