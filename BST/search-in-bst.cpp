#include<iostream>
#include<queue>
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
    Node *root = nullptr;

    public:
        void create_tree()
        {
            // You are getting this error becaue you are naming Queue 'q', which is same in Node * q;
            Node *p, *t;
            int root_data;
            cout << "Enter the value of Root: " << endl;
            cin >> root_data;
            root = new Node(root_data);

            queue<Node *> q;
            q.push(root);

            while(!q.empty())
            {
                int lchild;
                int rchild;
                p = q.front();
                q.pop();
                cout << "Parent is: " << p->data << endl;

                cout << "Enter Left Child Value: ";
                cin >> lchild;

                if(lchild != -1)
                {
                    t = new Node(lchild);
                    p->lchild = t;
                    q.push(t);
                }

                cout << "Enter Right Child Value: ";
                cin >> rchild;

                if(rchild != -1)
                {
                    t = new Node(rchild);
                    p->rchild = t;
                    q.push(t);
                }
            }
        }
};

int main()
{
    BST bst;
    bst.create_tree();   

    return 0;
}