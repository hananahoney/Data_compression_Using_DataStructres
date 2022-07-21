#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "huffman.h"
using namespace std;

int main()
{
    fstream file;
    string str = "";
    char ch;
    file.open("huffman_input.txt");
    while (!file.eof())
    {
        file.get(ch);
        str.push_back(ch);
    }

    file.close();
    str.push_back('\0');
    cout << str;

    int count[26] = { 0 };

    int i = 0;
    while (str[i])
    {
        for (int j = 0; j <= 26; j++)
        {
            if (int(str[i]) == j + 65 || int(str[i]) == j + 97)
                count[j]++;
        }

        i++;
    }
    cout << endl;

    PriorityQueue queue;

    for (int i = 0; i < 26; i++)
    {
        if (count[i] != 0)
        {
            queue.insert(char(i + 97), count[i]);
        }

    }

    cout<<"The Optimal Huffman Code is: "<<endl;

    Huffman(queue);

    cout<<endl;

    return 0;
}
