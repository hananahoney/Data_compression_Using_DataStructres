#include <iostream>
using namespace std;

struct Node
{
    Node* next;
    char ch;
    int priority;
};



class PriorityQueue
{
private:
    Node* head;
    Node* tail;
    int counter = 0;
public:
    PriorityQueue()
    {
        head = NULL;
        tail = NULL;
    }
    Node* getHead()
    {
        return head;
    }

    void insert(char ch, int reps)
    {
        Node* newnode = new Node;
        newnode->ch = ch;
        newnode->priority = reps;
        newnode->next = NULL;
        counter++;
        if (head == NULL && tail == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {

            tail->next = newnode;
            tail = tail->next;
        }
    }
    int getCounter()
    {
        return counter;
    }
    void display()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->ch << ": " << temp->priority << " ";
            temp = temp->next;
        }
        cout<<endl;
    }
    void sort()
    {
            Node* cur1 = head;
            Node* cur2 = head;

        for (int i = 0; i < getCounter(); i++) {
            for (int j = 0; j < getCounter() - 1; j++) {
                if (cur1->priority < cur2->priority) {
                    char temp = cur1->ch;
                    cur1->ch = cur2->ch;
                    cur2->ch = temp;

                    int temp1 = cur1->priority;
                    cur1->priority = cur2->priority;
                    cur2->priority = temp1;

                }
                cur2 = cur2->next;
            }
            cur2 = head;
            cur1 = head->next;
            for (int k = 0; k < i; k++) {
                    cur1 = cur1->next;
            }
        }
    }
    // void display()
    // {
    //     Node* cur1 = head;
    //     while(cur1)
    //     {
    //         cout<<cur1->ch<<" ";
    //         cur1 = cur1->next;
    //     }

    //     cout<<endl;
    // }
};
