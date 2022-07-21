#include <iostream>
using namespace std;

struct Node
{
    Node* next;
    char ch;
    int priority;
};



class linkedList
{
private:
    Node* head;
    Node* tail;
    int counter = 0;
public:
    linkedList()
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
            cout << temp->ch << ": " << temp->priority <<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

};
