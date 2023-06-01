/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
     Node* flatten(Node* head) {
        Node* temp= head;
        stack<Node*> st;
     while(head){
          if(head->child){
              if(head->next)st.push(head->next);
              head->next=head->child;
              head->next->prev=head;
              head->child=NULL;
          }else if(head->next==NULL&& !st.empty()){
                head->next=st.top();
                st.pop();
                head->next->prev=head;
          }
       head=head->next;
     }
     return temp;
     }
};