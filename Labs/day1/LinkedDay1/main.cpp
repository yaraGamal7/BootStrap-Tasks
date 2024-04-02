#include <iostream>
#include <string.h> // C+
using namespace std;

struct emp {
    int id;
    char name[10];
};

struct node {
    emp data;
    node *next;
    node *prev;
};

class LinkedL {
    node *head;
    node *tail;

    node* PrivSearch_by_id(int id) {
        node* temp = head;
        while (temp != NULL) {
            if (temp->data.id == id)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

public:
    LinkedL() { head = tail = NULL; }

    void append(int id, char* name) {
        node* temp = new node();
        temp->data.id = id;
        strcpy(temp->data.name, name);
        temp->prev = NULL;
        temp->next = NULL;

        if (head == NULL) {
            head = tail = temp;
        } else {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }

    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data.id << " " << temp->data.name << endl;
            temp = temp->next;
        }
    }

    emp PubSearch_By_id(int id) {
        node* temp = PrivSearch_by_id(id);
        if (temp != NULL) {
            return temp->data;
        } else {
            emp n;
            n.id = -1;
            strcpy(n.name, "");
            return n;
        }
    }

    int Count() {
        int n = 0;
        node* temp = head;
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }
        return n;
    }

    void delete_By_Id(int id) {
        node* t = PrivSearch_by_id(id);
        if (t == NULL)
            return;

        if (head == tail) {
            head = tail = NULL;
        } else if (t == head) {
            head = head->next;
            head->prev = NULL;
        } else if (t == tail) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            t->prev->next = t->next;
            t->next->prev = t->prev;
        }
        delete t;
    }

    void Insert_After_Id(int afterId, int newId, char* name) {
    if (head == NULL) {

        append(newId, name);
        return;
    }

    node* current = head;
    while (current != NULL && current->data.id != afterId) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "ID " << afterId << " not found. Insertion aborted." << endl;
        return;
    }

    node* temp = new node();
    temp->data.id = newId;
    strcpy(temp->data.name, name);


    temp->next = current->next;
    temp->prev = current;
    if (current->next != NULL) {
        current->next->prev = temp;
    } else {
        tail = temp;
    }
    current->next = temp;
}


};

int main() {
    LinkedL ll;
    ll.append(1, "Yara");
    ll.append(2, "Mohamed");

    cout << "Displaying List Before Deletion:" << endl;
    ll.display();

    cout << "............................." << endl;


    cout << "Deleting ID" << endl;
    ll.delete_By_Id(1);

    cout << "Displaying List After Deletion:" << endl;
    ll.display();

    cout << "............................." << endl;

     cout << "Inserting new node after ID 2..." << endl;
    ll.Insert_After_Id(2, 3, "Buthina");

    cout << "............................." << endl;
    cout << "Displaying List After Insertion:" << endl;
    ll.display();

    return 0;
};
