//Que1. 2026春(1)第1题：链表实现联接运算（A班）
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename T>
struct RowNode // 存放一行数据
{
    T* data;
    RowNode* next;
    RowNode(int cols)
    {
        data = new T[cols];
        next = nullptr;
    }
};

template <typename T>
class TableList
{
public:
    RowNode<T>* m_dummy;
    RowNode<T>* m_tail;
    int rows, cols;

    TableList(int r, int c) : rows(r), cols(c)
    {
        m_dummy = new RowNode<T>(0); 
        m_tail = m_dummy;
    }

    void addRow(T* rowData)
    {
        RowNode<T>* newNode = new RowNode<T>(cols);
        for(int i = 0; i < cols; i++)
        {
            newNode->data[i] = rowData[i];
        }
        m_tail->next = newNode;
        m_tail = newNode;
    }
};

template <typename T>
void Solution(ifstream& inFile, ofstream& outFile)
{
    int m1, n1, m2, n2;
    inFile >> m1 >> n1;
    T* tempData = new T[n1];
    TableList<T> R(m1, n1);
    for(int i = 0; i < m1; i++)
    {
        for(int j = 0; j < n1; j++)
        {
            inFile >> tempData[j];
        }
        R.addRow(tempData);
    }
    delete[] tempData;

    inFile >> m2 >> n2;
    tempData = new T[n2];
    TableList<T> S(m2, n2);
    for(int i = 0; i < m2; i++)
    {
        for(int j = 0; j < n2; j++)
        {
            inFile >> tempData[j];
        }
        S.addRow(tempData);
    }
    delete[] tempData;
    int targetI, targetJ;
    inFile >> targetI >> targetJ;
    if(targetI < 1 || targetI > n1 || targetJ < 1 || targetJ > n2)
    {
        outFile << "列号超出范围!" << endl;
        return;
    }

    for(RowNode<T>* curR = R.m_dummy->next; curR != nullptr; curR = curR->next)
    {
        for(RowNode<T>* curS = S.m_dummy->next; curS != nullptr; curS = curS->next)
        {
            if(curR->data[targetI -1] > curS->data[targetJ - 1])
            {
                for(int k = 0; k < n1; k++) outFile << curR->data[k] << " ";
                for(int k = 0; k < n2; k++) 
                {
                    outFile << curS->data[k] << (k == n2 - 1 ? "" : " ");
                }
                outFile << endl;
            }
        }
    }
}


int main()
{
    ifstream inFile("in.txt");
    ofstream outFile("out.txt");
    int k;
    inFile >> k;
    for (int caseIdx = 1; caseIdx <= k; caseIdx++)
    {
        string type;
        inFile >> type;
        if (caseIdx > 1) outFile << endl;
        outFile << "第" << caseIdx << "个" << type << "样例:" << endl;
        if(type == "int")
        {
            Solution<int>(inFile, outFile);
        }
        else if(type == "char")
        {
           Solution<char>(inFile, outFile);
        }
        else
        {
           int i, j;
           inFile >> i >> j;
           outFile <<  "未知的数据类型: " << type << endl;
        }
    }

    return 0;
}