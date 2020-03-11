
///////////////////////       Linked List        //////////////////////////
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    class Node* next;
};
class Node* head;
void print(){
    Node* temp=head;
    while (temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void Insert(int data,int pos){
    Node* temp1=new Node;
    temp1->data=data;
    temp1->next=nullptr;
    if(pos==1){
        temp1->next=head;
        head=temp1;
        return;
    }
    Node* temp2 = head;
    for(int i=1;i<pos-1;i++){
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
}
void deleteNode(int pos){
    class Node* temp1=head;
    if(pos==1){
        head=temp1->next;
        free(temp1);
        return;
    }
    for(int i=1;i<pos-1;i++){
        temp1=temp1->next;
       // cout<<i;
    }
    class Node* temp2=temp1->next;
    temp1->next=temp2->next;
    free(temp2);
}
void reverseList(){
    class Node *current, *prev , *next;
    current = head;
    prev= nullptr;
    while(current!=nullptr){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}
int main(){
    head=nullptr;
    Insert(1,1);
    Insert(2,2);
    Insert(3,3);
    Insert(4,4);
    Insert(7,1);
    print();
    deleteNode(5);
    print();
    reverseList();
    print();
    return 0;
}

/*
7 1 2 3 4
7 1 2 3
3 2 1 7
*/
