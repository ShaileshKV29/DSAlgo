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

        int sum_nodes(){return sum_nodes(root);}
        int sum_nodes(Node *p)
        {
            int x,y;
            if(p)
            {
                x = sum_nodes(p->lchild);
                y = sum_nodes(p->rchild);
                return x + y + p->data;
            }
            return 0;
        }

        int count_nodes(){return count_nodes(root);}
        int count_nodes(Node *p)
        {
            int x,y;
            if(p)
            {
                x = count_nodes(p->lchild);
                y = count_nodes(p->rchild);
                return x + y + 1;
            }
            return 0;
        }

        void preorder(){preorder(root);}
        void postorder(){postorder(root);}
        void inorder(){inorder(root);}

        void preorder_iterative(){preorder_iterative(root);}
        void inorder_iterative(){inorder_iterative(root);}

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

        void inorder_iterative(Node *t)
        {
            stack<Node *> st;

            while(t != nullptr || !st.empty())
            {
                if(t != nullptr)
                {
                    st.push(t);
                    t = t->lchild;
                }
                else
                {
                    t = st.top();
                    cout << t->data << " ";
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

        void levelOrder()
        {
            queue<Node *> q;
            q.push(root);
            cout << root->data << " ";
            Node *p;
            while(!q.empty())
            {
                p = q.front();
                q.pop();
                if(p->lchild)
                {
                    cout << p->lchild->data << " ";
                    q.push(p->lchild);
                }
                if(p->rchild)
                {
                    cout << p->rchild->data << " ";
                    q.push(p->rchild);
                }
            }
        }
};

int main()
{
    Tree tree;
    tree.create_tree();
    cout << tree.count_nodes() << endl;
    tree.preorder();
    cout << endl;
    cout << tree.sum_nodes() << endl;

    return 0;
}