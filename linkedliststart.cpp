# include<iostream>
using namespace std;
class node{
    public:
    int info;
    node* next;

    node(int val){
        info = val;
        next=NULL;
    }

};
void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next=head;
    head=n;
}
void insertAtTail(node* &head, int val){
    node* n= new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while (temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    
}
void display(node* head){
    node* temp =head;
    while(temp != NULL){
        cout<<temp->info<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
bool search(node* head, int key){
    node* temp=head;
    while ((temp != NULL))
    {
        if(temp->info==key){
            return true;
        }
       temp=temp->next;
    }
    return false;
    
    
}
int main(){

    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtHead(head, 9);
    display(head);
    cout<<search(head,6);




    return 0;

}