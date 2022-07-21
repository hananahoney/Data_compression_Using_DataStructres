#include "priorityqueue.h"
#include <iostream>
using namespace std;

struct MinHeapNode
{
    char ch;
    int freq;
    MinHeapNode* left, * right;
};
struct Minimum_Heap
{
    int size;
    int capacity;
    MinHeapNode** array;
};




Minimum_Heap* Create_Minimum_Heap(int capacity)
{
    Minimum_Heap* Min_Heap = (Minimum_Heap*)malloc(sizeof(Minimum_Heap));
    Min_Heap->size = 0;
    Min_Heap->capacity = capacity;
    Min_Heap->array = (MinHeapNode**)malloc(Min_Heap->capacity * sizeof(MinHeapNode*));
    return Min_Heap;
}






void swapNode(MinHeapNode** var1, MinHeapNode** var2)
{

    MinHeapNode* temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}






MinHeapNode* newNode(char ch, unsigned freq)
{
    MinHeapNode* temp = (MinHeapNode*)malloc(sizeof(MinHeapNode));

    temp->left = NULL;
    temp->right = NULL;
    temp->ch = ch;
    temp->freq = freq;

    return temp;
}



void Minimum_Heapify(Minimum_Heap* Min_H, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < Min_H->size && Min_H->array[left]->freq < Min_H->array[smallest]->freq)
    {
        smallest = right;
    }

    if (right < Min_H->size && Min_H->array[right]->freq < Min_H->array[smallest]->freq)
    {
        smallest = left;
    }

    if (smallest != i)
    {
        swapNode(&Min_H->array[smallest], &Min_H->array[i]);
        Minimum_Heapify(Min_H, smallest);
    }
}




MinHeapNode* Extraction_of_Minimum(Minimum_Heap* Min_H)
{

    MinHeapNode* temp = Min_H->array[0];
    Min_H->array[0] = Min_H->array[Min_H->size - 1];

    --Min_H->size;
    Minimum_Heapify(Min_H, 0);

    return temp;
}




void Create_Minimum_Hp(Minimum_Heap* Min_H)
{
    int m = Min_H->size - 1;
    for (int i = (m - 1) / 2; i >= 0; --i)
    {
        Minimum_Heapify(Min_H, i);
    }
}




void Insertion_of_Minimum_Heap(Minimum_Heap* Min_H, MinHeapNode* Min_Node)
{
    ++Min_H->size;
    int i = Min_H->size - 1;

    while (i && Min_Node->freq < Min_H->array[(i - 1) / 2]->freq)
    {
        Min_H->array[i] = Min_H->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    Min_H->array[i] = Min_Node;
}




void displayArr(int arr[], int n)
{
    cout<<" ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i];
    }
    cout << endl;
}



Minimum_Heap* Create_Minimum_Hp(char data[], int freq[], int size)
{

    Minimum_Heap* Min_H = Create_Minimum_Heap(size);

    for (int i = 0; i < size; ++i)
    {
        Min_H->array[i] = newNode(data[i], freq[i]);
    }
    Min_H->size = size;
    Create_Minimum_Hp(Min_H);

    return Min_H;
}




MinHeapNode* HuffmanTree(char data[], int freq[], int size)
{
    MinHeapNode* right, * left, * head;
    Minimum_Heap* Min_H = Create_Minimum_Hp(data, freq, size);

    while (!(Min_H->size==1))
    {
        left = Extraction_of_Minimum(Min_H);
        right = Extraction_of_Minimum(Min_H);
        head = newNode('\0', left->freq + right->freq);

        head->left = left;
        head->right = right;

        Insertion_of_Minimum_Heap(Min_H, head);
    }
    return Extraction_of_Minimum(Min_H);
}




void Display(MinHeapNode* node, int data[], int len , int &divi)
{
    if (node->left)
    {
        data[len] = 0;
        Display(node->left, data, len + 1, divi);
    }
    if (node->right)
    {
        data[len] = 1;
        Display(node->right, data, len + 1, divi);
    }
    if (!(node->left) && !(node->right))
    {
        cout << node->ch;
        divi += node->freq*len;
        displayArr(data, len);
    }
}




void Huffman(PriorityQueue queue)
{
    int N = 0;
    int size = queue.getCounter();
    char* data = new char[size];
    int* freq = new int[size];

    Node* temp = queue.getHead();
    for (int i = 0; i < size; i++)
    {
        data[i] = temp->ch;
        temp = temp->next;
    }

    temp = queue.getHead();

    // queue.display();

    queue.sort();

    // queue.display();
    
    for (int i = 0; i < size; i++)
    {
        freq[i] = temp->priority;
        N += freq[i];
        temp = temp->next;
    }

    // for (int i = 0; i < size; i++)
    // {
    //    cout<<arr[i]<<" "<<freq[i]<<endl;
    // }

    MinHeapNode* root = HuffmanTree(data, freq, size);

    int arr[100], top = 0;


    int ABR_divident=0;
    Display(root, arr, top , ABR_divident);

    float ABR = float(ABR_divident)/float(N);

    cout<<"Compression ratio is: "<<ABR<<endl;

}