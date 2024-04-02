#include <iostream>
#include <cstring>
using namespace std;

struct node {
    int id;
    char name[10];
    node* next;
};

class Queue {
    node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }
void enQueue(int id ,char* name){
node* temp=new node();
temp->id=id;
strcpy(temp->name, name);
temp->next=NULL;
if(front==NULL){
    front=rear=temp;
}else{
    rear->next=temp;
    rear=temp;
}
}
node deQueue(){
node res;
res.id=-1;
if(front !=NULL)
{
   res.id=front->id;
   strcpy(res.name,front->name);
   node* temp=front;
   front=front->next;
   delete temp;
   if(front==NULL){
    rear=NULL;
   }
}
   return res;
}
};

int main() {
    Queue q1;

    q1.enQueue(1, "Yara");
    q1.enQueue(2, "basam");


    node dequeued = q1.deQueue();
    cout << "Dequeued Node: ID=" << dequeued.id << ", Name=" << dequeued.name << endl;

    return 0;
}
