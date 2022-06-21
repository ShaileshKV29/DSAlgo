#include<iostream>
using namespace std;

class Node
{
    public:
        Node *lchild;
        int data;
        Node *rchild;

        Node(int data)
        {
            this->data = data;
            lchild = rchild = nullptr;
        }
};

class BST
{
    Node *root;

    public:
        BST()
        {
            root = nullptr;
        }

        Node * RInsert(int key)
        {
            if(root == nullptr)
            {
                Node *t = new Node(key);
                this->root = t;
                return root;
            }
            return RInsert(this->root, key);
        }

        Node * RInsert(Node *p, int key)
        {
            if(p == nullptr)
            {
                Node *t = new Node(key);
                return t;
            }

            if(key > p->data)
                p->rchild = RInsert(p->rchild, key);
            else if(key < p->data)
                p->lchild = RInsert(p->lchild, key);

            return p;
        }

        void display()
        {
            display(root);
            cout << endl;
        }

        void display(Node *p)
        {
            if(p != nullptr)
            {
                display(p->lchild);
                cout << p->data << " ";
                display(p->rchild);
            }
        }
};

int main()
{
    BST b = BST();
    b.RInsert(10);
    b.RInsert(20);
    b.RInsert(30);
    b.display();

    return 0;
}