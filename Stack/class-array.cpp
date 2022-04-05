#include<iostream>
using namespace std;

class Process
{
    int process_name;
    int arrival_time;
    int burst_time;
    int div;

    public:
    
        Process(int pn, int at, int bt)
        {
            this->process_name = pn;
            arrival_time = at;
            burst_time = bt;
            div = arrival_time/burst_time;
        }

        void display()
        {
            cout << process_name << " ";
            cout << arrival_time << " ";
            cout << burst_time << " ";
            cout << div << " ";
        }
};

int main()
{
    Process p[3] = {{1,2,3}, {4,5,6}, {7,8,9}};  
    for(int i = 0; i < 3; i++)
    {
        p[i].display();
        cout << endl;
    }

    return 0;
}