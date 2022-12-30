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

        int size()
        {
            return size(root);
        }

        int size(Node *p)
        {
            if(p)
            {
                int left = size(p->left);
                int right = size(p->right);
                return left + 1 + right;
            }

            return 0;
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

        int max_value()
        {
            Node *p = root;
            return max_value_rec(p);
        }
        
        int max_value_rec(Node *p)
        {
            int root_max, max = 0, left, right;
            if(p != nullptr)
            {
                root_max = p->data;
                left = max_value_rec(p->left);
                right = max_value_rec(p->right);

                if(left > right)
                    max = left;
                else
                    max = right;
                
                if(root_max > max)
                    max = root_max;
            }
            return max;
        }

        bool find_element(int key)
        {
            return find_element_rec(root, key);
        }

        bool find_element_rec(Node *p, int key)
        {
            bool found = false, left, right;
            if(p != nullptr)
            {
                if(p->data == key)
                    return true;
                else
                {
                    left = find_element_rec(p->left, key);
                    right = find_element_rec(p->right, key);

                    if(left || right)
                        found = true;
                }
            }
            return found;
        }

};


int main()
{
    int arr[10] = {1,2,3,4,5,6,77,8,9,10};
    Tree tree(arr, 10);

    tree.levelOrder();
    cout << endl;
    cout << tree.max_value();
    cout << endl;
    if(tree.find_element(9))
        cout << "Element Found" << endl;
    else
        cout << "Element Not Found" << endl;

    cout << tree.size() << endl;

    return 0;
}