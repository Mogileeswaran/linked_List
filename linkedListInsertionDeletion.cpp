
///////////////////////       Linked List Insertion & Deletion      //////////////////////////
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
    }
    class Node* temp2=temp1->next;
    temp1->next=temp2->next;
    free(temp2);
}
int main(){
    head=nullptr;
    Insert(1,1);
    Insert(2,2);
    Insert(3,3);
    Insert(4,1);
    Insert(7,2);
    print();
    deleteNode(4);
    print();
    return 0;
}
/*
4 7 1 2 3
4 7 1 3
*/
