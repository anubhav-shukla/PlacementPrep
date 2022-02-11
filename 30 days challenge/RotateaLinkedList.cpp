#include<bits/stdc++.h>
using namespace std;
class node{
     public:
         int num;
         node* next;
         node(int a){
             num=a;
             next=NULL;
         }
 };
 void insertNode(node* &head,int val) {
    node* newNode = new node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

 node* rotateRight(node* head, int k){
     if(head == NULL || head->next == NULL||k==0) return head;
     node* temp = head;
     int length = 1;
     while(temp->next != NULL){
         ++length;
         temp = temp->next;

     }
     temp ->next = head;
     k=k%length;
     int end = length-k;
     while(end--) temp = temp->next;

     head = temp->next;
     temp->next =NULL;

     return head;
 }

 void printList(node* head){
     while(head->next != NULL){
         cout<<head->num<<"->";
         head = head = head->next;
     }
     cout<<head->num<<endl;
     return;
 }

 int main(){
     node* head = NULL;
     insertNode(head,1);
     insertNode(head,2);
     insertNode(head,3);
     insertNode(head,4);
     insertNode(head,5);
     insertNode(head,6);
     insertNode(head,7);

     cout<<"Original List: ";
     printList(head);

     int k=2;
     node* newHead = rotateRight(head,k);
     cout<<"After "<<k<<"iterations: ";
     printList(newHead);
     return 0;
 }