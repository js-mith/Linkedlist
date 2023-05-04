#include <iostream>
using namespace std;
#include "node.cpp"

node *midPoint(node *head)
{
    // Write your code here
	if(head == NULL){
		return NULL;
	}
	node *slow = head;
	node *fast = head -> next;
	while(fast != NULL && fast -> next != NULL){
		fast = fast -> next -> next;
		slow =slow -> next;
	}
	return slow;
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
 node *mid =  midPoint(head);
if (mid != NULL)
		{
			cout << mid->data;
		}



  
    return 0;
}