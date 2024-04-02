#include <iostream>
#include<string.h>

using namespace std;

struct node{
    int id;
    char name[10];
    node*prev;

};
class Stack{

node*tos;

public:
    Stack(){tos=NULL;}

    void Push(int id, char* name){
        node*temp=new node();
        temp->id=id;
        strcpy(temp->name,name);
        temp->prev=tos;
        tos=temp;

    }

    node pop(){
        node res;
        res.id=-1;
        if(tos!=NULL){
            res.id=tos->id;
            strcpy(res.name,tos->name);
            node *temp=tos;
            tos=tos->prev;
            delete temp;
        }
        return res;
    }

    int isEmpty(){
        return tos==NULL;
    }

    int isFull(){
    node*temp=new node();
    if(temp==NULL)
        return 1;
    else{
        delete temp;
        return 0;
    }
    }

    ~Stack(){
     cout<<"destrctor";
    }
};
int main() {
    Stack myStack;


    myStack.Push(1, "Yara");
    myStack.Push(2, "Basma");
    myStack.Push(3, "Nora");
    myStack.Push(4, "Mohamed");

    while (!myStack.isEmpty()) {
        node poppedNode = myStack.pop();
        if (poppedNode.id != -1) {
            cout << "Popped: ID = " << poppedNode.id << ", Name = " << poppedNode.name << endl;
        } else {
            cout << "Stack is empty!" << endl;
        }
    }

    return 0;
};
