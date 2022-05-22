#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
        Node* lchild;
        int data;
        Node* rchild;
};

class Tree
{
    public:

        void create_tree()
        {
            Node *p, *t;
            int x;
            queue<Node *> q;
            cout << "Enter root value: ";
            cin >> x;
            Node *root = new Node;
            root->data = x;
            root->lchild = nullptr;
            root->rchild = nullptr;
            q.push(root);

            while(!q.empty())
            {
                p = q.front();
                q.pop();
                int lchild;
                int rchild;
                cout << endl;
                cout << "Parent: " << p->data << endl; 
                cout << "Enter the value of Left Child: ";
                cin >> lchild;
                if(lchild != -1)
                {
                    t = new Node;
                    t->data = lchild;
                    t->lchild = nullptr;
                    t->rchild = nullptr;
                    p->lchild = t;
                    q.push(t);
                }
                cout << "Enter the value of Right Child: ";
                cin >> rchild;
                if(rchild != -1)
                {
                    t = new Node;
                    t->data = rchild;
                    t->lchild = nullptr;
                    t->rchild = nullptr;
                    p->rchild = t;
                    q.push(t);
                }
            }
        }
};

int main()
{
    Tree tree;
    tree.create_tree();

    return 0;
}