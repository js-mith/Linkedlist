#include <iostream>
using namespace std;
#include "node.cpp"

node *mergesort(node *head1 , node *head2)
{
        //Write your code here
 if(head1 == NULL){
	 return head2;
 }
 if(head2 == NULL){
	 return head1;
 }

 node *ans = new node(-1);
 node *temp =ans;

 while(head1 != NULL && head2 != NULL){
	 if(head1 -> data < head2 -> data){
		 temp -> next =  head1;
		 temp = head1;
		 head1 =head1 -> next;
         } else {
           temp->next = head2;
           temp = head2;
           head2 = head2->next;
         }
 }

         while(head1 != NULL){
           temp->next = head1;
           temp = head1;
           head1 = head1->next;
         }
		 while(head2 != NULL){
                   temp->next = head2;
                   temp = head2;
                   head2 = head2->next;
                 }
 
 ans = ans -> next;
 return ans;
}


node* takeinput_better(){
int data ;
cin>>data;
node *head = NULL;
node *tail = NULL;
while(data != -1){
   node *newnode =new  node(data);
   if(head == NULL){
   head = newnode;
   tail = newnode;
   }
   else{
      tail ->next = newnode;
      tail = tail -> next;
   
      
      //node *temp = head;
    //  while(temp -> next != NULL){
       //  temp = temp -> next;
    //  }

      //temp -> next = newnode;
   }

   cin>>data;
}

return head;
}


void print(node *head){

   // node *temp = head;
    
    while(head  != NULL){
       cout << head -> data <<" ";
       
        head = head -> next;
        
    }
    cout << endl;
    /*
    temp =head;
       while(head != NULL){
        cout << head -> data <<" ";
        head = head -> next;
        
      }
      */
}
int main()
{
node *head = takeinput_better();

print(head);
        node *head1 = takeinput_better();
		node *head2 = takeinput_better();
		node *head3 = mergesort(head1, head2);
		print(head3);



  
    return 0;
}