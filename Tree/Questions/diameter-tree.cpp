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

        int leafNodeCount()
        {
            int count = 0;
            stack<Node *> st;
            st.push(this->root);
            while(!st.empty())
            {
                Node *p = st.top();
                st.pop();

                if(!p->left && !p->right)
                    count++;
                if(p->right)
                    st.push(p->right);
                if(p->left)
                    st.push(p->left);
            }
            return count;
        }

        int height()
        {
            return height(root);
        }

        int height(Node *p)
        {
            if(p)
            {
                int left = height(p->left);
                int right = height(p->right);

                if(left > right)
                    return left + 1;
                
                return right + 1;
            }
            return 0;
        }

        int diameter()
        {
            return diameter(root);
        }

        int diameter(Node *p)
        {
            if(p)
            {
                int op1 = diameter(p->left);
                int op2 = diameter(p->right);
                int op3 = height(p->left) + 1 + height(p->right);

                return max(op3, max(op1, op2));
            }
            return 0;
        }

        int max(int a, int b)
        {
            if(a>b)
                return a;
            return b;
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
    cout << tree.size() << endl;
    cout << tree.diameter() << endl;

    return 0;
}