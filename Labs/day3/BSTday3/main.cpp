#include <iostream>
using namespace std;

struct node {
    int id;
    node* left;
    node* right;
};
class BST {
private:
    node* root;

    node* findParent(int id) {
        node* temp = root;
        node* parent = NULL;
        while (temp != NULL) {
            parent = temp;
            if (id < temp->id) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        return parent;
    }

    void inOrder(node* r) {
        if (r == NULL)
            return;
        inOrder(r->left);
        cout << r->id << endl;
        inOrder(r->right);
    }

public:
    BST() { root = NULL; }

    void add(int id) {
        node* temp = new node();
        temp->id = id;
        temp->left = NULL;
        temp->right = NULL;
        if (root == NULL) {
            root = temp;
        } else {
            node* p = findParent(id);
            if (id < p->id)
                p->left = temp;
            else
                p->right = temp;
        }
    }

    void inOrder() {
        inOrder(root);
    }
};

int main() {
    BST tree;

    tree.add(5);
    tree.add(3);
    tree.add(7);
    tree.inOrder();
    return 0;
}
