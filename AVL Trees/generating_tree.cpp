#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        int height;
        Node *left;
        Node *right;

        Node(int data, int height)
        {
            this->data = data;
            this->height = height;
            left = right = nullptr;
        }

        Node(int data)
        {
            this->data = data;
            left = right = nullptr;
        }
};

class AVLTree
{
    Node *root = nullptr;

    public:
    
    void Insert(int key)
    {
        root = RInsert(root, key);
    }

    Node* RInsert(Node *p, int key)
    {
        if(p == nullptr)
        {
            Node *t = new Node(key, 0);
            return t;
        }

        if(key > p->data)
            p->right = RInsert(p->right, key);
        else if(key < p->data)
            p->left = RInsert(p->left, key);
        

        p->height = NodeHeight(p);
        // cout << p->height << endl;

        if(balanceFactor(p) == 2 && balanceFactor(p->left) == 1)
            LLRotation(p);
        else if(balanceFactor(p) == 2 && balanceFactor(p->left) == -1)
            LRRotation(p);
        else if(balanceFactor(p) == -2 && balanceFactor(p->right) == 1)
            RLRotation(p);
        else if(balanceFactor(p) == -2 && balanceFactor(p->right) == -1)
        {
            cout << "RR Rotation if" << endl;
            RRRotation(p);
        }

        return p;
    }

    Node *LLRotation(Node *p)
    {
        Node *pl = p->left;
        Node *plr = pl->right;

        pl->right = p;
        p->left = plr;

        p->height = NodeHeight(p);
        pl->height = NodeHeight(pl);

        if(p == this->root)
            root = pl;
        
        return pl;
    }

    Node *LRRotation(Node *p)
    {
        Node *pl = p->left;
        Node *plr = pl->right;

        pl->right = plr->left;
        p->left = plr->right;

        plr->left = pl;
        plr->right = p;

        p->height = NodeHeight(p);
        pl->height = NodeHeight(pl);
        plr->height = NodeHeight(plr);

        if(p == root)
            root = plr;

        return plr;
    }

    Node *RRRotation(Node *p)
    {
        cout << "Inside RR" << endl;
        Node *pr = p->right;
        Node *prl = pr->left;

        pr->left = p;
        p->right = prl;

        p->height = NodeHeight(p);
        pr->height = NodeHeight(pr);

        if(p == this->root)
            root = pr;
        
        return pr;
    }

    Node *RLRotation(Node *p)
    {
        Node *pr = p->right;
        Node *prl = pr->left;

        p->right = prl->left;
        pr->left = prl->right;

        prl->left = p;
        prl->right = pr;

        p->height = NodeHeight(p);
        pr->height = NodeHeight(pr);
        prl->height = NodeHeight(prl);

        if(p == this->root)
            root = prl;
        
        return prl;
    }

    int balanceFactor(Node *root)
    {
        if(root == nullptr)
            return 0;
        
        int left = 0;
        int right = 0;
        
        if(root->left)
            left = root->left->height;
        
        if(root->right)
            right = root->right->height;

        return left - right;
    }

    int NodeHeight(Node *root)
    {
        if(root == nullptr)
            return 0;

        int left = -1;
        int right = -1;
        
        if(root->left)
            left = root->left->height;
        
        if(root->right)
            right = root->right->height;

        return max(left, right) + 1;
    }

    int max(int a, int b)
    {
        if(a > b)
            return a;
        return b;
    }

    void preOrder()
    {
        PreOrder(root);
    }

    void PreOrder(Node *root)
    {
        if(root)
        {
            cout << root->data << " ";
            PreOrder(root->left);
            PreOrder(root->right);
        }
    }

    void inOrder()
    {
        InOrder(root);
    }

    void InOrder(Node *root)
    {
        if(root)
        {
            InOrder(root->left);
            cout << root->data << " ";
            InOrder(root->right);
        }
    }
};

int main()
{
    int arr[7] = {10, 20, 30, 25, 28, 27, 5};
    AVLTree tree;
    // for(int i = 0; i < 3; i++)
    // {
    //     tree.Insert(arr[i]);
    // }
    tree.Insert(10);
    tree.Insert(20);
    tree.Insert(30);
    tree.inOrder();
    cout << endl;
    tree.preOrder();

    return 0;
}