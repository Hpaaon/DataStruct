// Que4. 串的模式匹配

#include <iostream>
#include <string>

using namespace std;

int main()
{

    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.length();
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
    int count = 0;
    for(int i = m + 1; i < n; i++)
    {
        if(pi[i] == m) { count++; }
    }
    cout << count << endl;
    return 0;
}