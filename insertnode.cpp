#include <iostream>
using namespace std;
#include "node.cpp"

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

node *insertnode(node *head , int i , int data){
    node *newnode = new node(data);
    int count =0;
    node *temp =head;
    if(i == 0){
        newnode -> next = head;
        head = newnode;
        return head;
    }
    while(temp != NULL && count < i-1){
        temp = temp -> next;
        count++;
    }
    if(temp != NULL){
    node *a = temp -> next;
    temp -> next = newnode;
    newnode -> next = a;
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
int i , data;
cin >> i >> data;

head = insertnode(head , i , data);
print(head);



   /*
    // statically

    node n1(1);

    node *head = &n1;

    node n2(2);
    node n3(3);
    node n4(4);
    node n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head);
    



           n1.next = &n2;

      // cout << n1.data << " " << n2.data <<endl;

       cout << head -> data;
       //dynamically
      node *n3 = new node(10);

      node *head = n3;
      node *n4 = new node(20);

      n3 -> next = n4;

      */
     
    return 0;
}