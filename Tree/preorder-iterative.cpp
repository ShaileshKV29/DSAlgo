#include<iostream>
#include<queue>
#include<stack>
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
    Node *root;
    public:
        Tree(){root = nullptr;}

        void create_tree()
        {
            Node *p, *t;
            int x;
            queue<Node *> q;
            cout << "Enter root value: ";
            cin >> x;
            root = new Node;
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

        void preorder(){preorder(root);}
        void postorder(){postorder(root);}
        void inorder(){inorder(root);}

        void preorder_iterative(){preorder_iterative(root);}

        void preorder_iterative(Node *t)
        {
            stack<Node *> st;

            while(t != nullptr || !st.empty())
            {
                if(t != nullptr)
                {
                    cout << t->data << " ";
                    st.push(t);
                    t = t->lchild;
                }
                else
                {
                    t = st.top();
                    st.pop();
                    t = t->rchild;
                }
            }
        }

        void preorder(Node *p)
        {
            if(p)
            {
                cout << p->data << " ";
                preorder(p->lchild);
                preorder(p->rchild);
            }
        }

        void postorder(Node *p)
        {
            if(p)
            {
                postorder(p->lchild);
                postorder(p->rchild);
                cout << p->data << " ";
            }
        }

        void inorder(Node *p)
        {
            if(p)
            {
                inorder(p->lchild);
                cout << p->data << " ";
                inorder(p->rchild);
            }
        }
};

int main()
{
    Tree tree;
    tree.create_tree();
    tree.preorder_iterative();

    return 0;
}