#include<iostream>
#include <queue>
#include <stack>
using namespace std;

class Node
{
    public: 
        int data;
        Node *left;
        Node *right;

        Node(int d)
        {
            this->data = d;
            left = nullptr;
            right = nullptr;
        }
};

class Tree
{
    Node *root = nullptr;

    public:
        Tree(int arr[], int n)
        {
            root = new Node(arr[0]);

            queue<Node *> que;
            que.push(root);

            int i = 1;
            while(i < n)
            {
                Node *p = que.front();
                que.pop();

                if(i < n){
                    Node *t = new Node(arr[i]);
                    que.push(t);
                    p->left = t;
                    i++;
                }

                if(i < n)
                {
                    Node *t = new Node(arr[i]);
                    que.push(t);
                    p->right = t;
                    i++;
                }
            }
        }

        // void preOrder()
        // {
        //     preOrderRev(root);
        // }

        // void preOrderRev(Node *p)
        // {
        //     if(p != nullptr)
        //     {
        //         cout << p->data << " ";
        //         preOrderRev(p->left);
        //         preOrderRev(p->right);
        //     }
        // }

        void preOrder()
        {
            
        }

        void levelOrder()
        {
            Node *p = root;
            queue<Node *> que;
            que.push(root);
            while(!que.empty())
            {
                Node *q = que.front();
                que.pop();
                cout << q->data << " ";
                if(q->left)
                    que.push(q->left);
                
                if(q->right)
                    que.push(q->right);
            }
        }

        void postOrder()
        {
            Node *p = root;
            stack<Node *> st1;
            stack<Node *> st2;

            st1.push(p);
            while(!st1.empty())
            {
                Node *t = st1.top();
                st1.pop();

                st2.push(t);
                if(t->left)
                    st1.push(t->left);
                if(t->right)
                    st1.push(t->right);
            }
            while(!st2.empty())
            {
                cout << st2.top()->data << " ";
                st2.pop();
            }
        }

        void reverseOrder()
        {
            queue<Node *> q;
            stack<Node *> st;
            q.push(root);

            while(!q.empty())
            {
                Node *p = q.front();
                q.pop();
                if(p->right)
                    q.push(p->right);
                if(p->left)
                    q.push(p->left);

                st.push(p);
            }

            while(!st.empty())
            {
                cout << st.top()->data << " ";
                st.pop();
            }
        }

        int maxLevel()
        {
            queue<Node *> q;
            q.push(root);
            q.push(nullptr);
            int sum = 0;
            int max_sum = 0;
            while(!q.empty())
            {
                Node *p = q.front();
                q.pop();

                if(p == nullptr)
                {

                    if(sum > max_sum)
                        max_sum = sum;
                    sum = 0;
                    if(q.empty())
                        break;
                    q.push(nullptr);
                }
                else
                {
                    sum += p->data;
                    if(p->left)
                        q.push(p->left);
                    if(p->right)
                        q.push(p->right);
                }
            }

            return max_sum;
        }

        int height()
        {
            int h = heightRec(root);
            return h;
        }

        int heightRec(Node *p)
        {

            if(p == nullptr)
                return 0;

            int left = heightRec(p->left);
            int right = heightRec(p->right);

            if(left > right)
                return left+1;
            
            return right+1;
        }

        void spiralOrder()
        {
            spiralOrderRec(root);
        }

        void printGivenLevel(Node *p, int level, bool itr)
        {
            if(p == nullptr)
                return;
            if(level == 1)
                cout << p->data << " ";
            else if(level > 1)
            {
                if(itr)
                {
                    printGivenLevel(p->left, level - 1, itr);
                    printGivenLevel(p->right, level - 1, itr);
                }
                else
                {
                    printGivenLevel(p->right, level-1, itr);
                    printGivenLevel(p->left, level-1, itr);
                }
            }
        }

        void spiralOrderRec(Node * p)
        {
            int h = height();
            bool itr = false;
            int i;

            for(int i = 1; i <= h; i++)
            {
                printGivenLevel(p, i, itr);
                itr = !itr;
            }
        }

};


int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    Tree tree(arr, 10);

    tree.levelOrder();
    cout << endl;
    tree.postOrder();
    cout << endl;
    tree.reverseOrder();
    cout << endl;
    cout << tree.height();
    cout << endl;
    tree.spiralOrder();


    return 0;
}