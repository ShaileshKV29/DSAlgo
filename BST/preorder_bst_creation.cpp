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

    public:
    Node *root;
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

        // int find(int key)
        // {
        //     return find(root, key);
        // }

        int find(int key)
        {
            Node *p = root;
            while(p != nullptr)
            {
                if(key < p->data)
                    p = p->lchild;
                else if(key > p->data)
                    p = p->rchild;
                else if(key == p->data)
                    return p->data;
            }

            return -1;
        }


        Node * delete_node(int key)
        {
            return delete_node(root, key);
        }

        Node * delete_node(Node *p, int key)
        {
            if(key < p->data)
                p->lchild = delete_node(p->lchild, key);
            else if(key > p->data)
                p->rchild = delete_node(p->rchild, key);
            else
            {
                if(height(p->lchild) > height(p->rchild))
                {
                    Node *q = InorderPredecessor(p);
                    p->data = q->data;
                    p->lchild = delete_node(p->lchild, q->data);
                }
                else
                {
                    Node *q = InorderSuccessor(p);
                    p->data = q->data;
                    p->rchild = delete_node(p->rchild, q->data);
                }
            }
            return p;
        }

        Node * InorderPredecessor(Node *p)
        {
            if(p == nullptr)
                return nullptr;
            Node *q;
            p = p->lchild;
            while(p != nullptr)
                q = p;
                p = p->rchild;
            return q;
        }

        Node * InorderSuccessor(Node *p)
        {
            if(p == nullptr)
                return nullptr;
            Node *q = nullptr;
            p = p->rchild;
            while(p != nullptr)
            {
                q = p;
                p = p->lchild;
            }
            return q;
        }

        int height(Node *p)
        {
            int x, y;
            if(p == nullptr) return 0;

            x = height(p->lchild);
            y = height(p->rchild);

            return x > y ? x+1 : y+1;
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
    b.RInsert(40);
    b.RInsert(50);
    b.display();
    cout << b.find(30) << endl;
    // b.delete_node(30);
    cout << b.InorderPredecessor(b.root)->data << endl;

    return 0;
}