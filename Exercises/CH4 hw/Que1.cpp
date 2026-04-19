//Que1. LeetCode443—压缩字符串
#include <iostream>
#include <fstream>
using namespace std;

void writeCount(char* chars, int& write, int count)
{
    int start = write;
    while (count > 0)
    {
        chars[write++] = (count % 10) + '0';
        count /= 10;
    }
    int end = write - 1;
    while (start < end) {
        char temp = chars[start];
        chars[start] = chars[end];
        chars[end] = temp;
        start++;
        end--;
    }
}
int main()
{
    ifstream inFile("in.txt");
    char chars[1000];
    int n = 0;
    char ch;

    while(inFile >> ch)
    {
        chars[n++] = ch;
    }
    inFile.close();

    int write = 0;
    int read = 0;

    while(read < n)
    {
        char curChar = chars[read];
        int count = 0;

        while (read < n && chars[read] == curChar)
        {
            read++;
            count++;
        }

        chars[write++] = curChar;

        if (count > 1)
        {
            writeCount(chars, write, count);
        }
        
    }

    for (int i = 0; i < write; i++) {
        cout << chars[i] << " ";
    }
    cout << endl;

    return 0;
}