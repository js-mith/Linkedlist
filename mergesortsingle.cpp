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
node *merge(node *left , node *right){
  if (left == NULL) {
    return right;
  }
  if (right == NULL) {
    return left;
  }

  node *ans = new node(-1);
  node *temp = ans;

  while (left != NULL && right != NULL) {
    if (left->data < right->data) {
      temp->next = left;
      temp = left;
      left = left->next;
    } else {
      temp->next = right;
      temp = right;
      right = right->next;
    }
  }

    while (left != NULL) {
      temp->next = left;
      temp = left;
      left = left->next;
    }
    while (right != NULL) {
      temp->next = right;
      temp = right;
      right = right->next;
    }
  

  ans = ans->next;
  return ans;
  }

  node *mergeSort(node * head) {

    // Write your code here
    if(head == NULL || head -> next == NULL){
      return head;
    }
    node *mid = midPoint(head);
    node *left = head;
    node *right = mid -> next;
    mid -> next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    node *result = merge(left , right);
    return result;

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

head = mergeSort(head);
		print(head);


  
    return 0;
}