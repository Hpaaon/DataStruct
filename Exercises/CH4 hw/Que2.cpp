//Que2. LeetCode28—实现strStr()

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Solution
{
public:
    int strStr(string s, string t)
    {
        int n = s.length();
        int m = t.length();

        for(int i = 0; i <= n - m; i++)
        {
            int j = 0;
            while(j < m && s[i + j] == t[j])
            {
                j++;
            }
            if(j == m)
            {
                return i;
            }
        }
        return -1;

    }
};

int main()
{
    ifstream inFile("in.txt");
    string s, t;
    getline(inFile, s);
    getline(inFile, t);
    Solution sol;
    cout << sol.strStr(s, t) << endl;
    inFile.close();


    return 0;
}