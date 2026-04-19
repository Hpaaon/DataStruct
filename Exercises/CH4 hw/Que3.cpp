// Que3. HDU2594—两串的最长相同前后缀

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream inFile("in.txt");

    string s1, s2;
    inFile >> s1 >> s2;
    inFile.close();

    string combined = s1 + '#' + s2;
    int n = combined.length();

    int* pi = new int[n];
    for (int i = 0; i < n; i++) { pi[i] = 0; }
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && combined[i] != combined[j])
        {
            j = pi[j - 1];
        }
        if (combined[i] == combined[j])
        {
            j++;
        }
        pi[i] = j;
    }
    int resLen = pi[n - 1];

    if(resLen == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        for (int i = 0; i < resLen; i++) 
        {
            cout << s1[i];
        }
        cout << " " << resLen << endl;
    }
    delete[] pi;
    return 0;
}