// Que2. 2026春(1)第2题：堆栈在表达式求值的应用（A班）

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// 手动实现栈
template <typename T>
class Stack
{
public:
    struct Node
    {
        T data;
        Node* next;
        Node(const T& val, Node* p = nullptr) : data(val), next(p) {}
    };
    Node* m_top;
    int m_size;

    Stack() : m_top(nullptr), m_size(0) {}
    ~Stack(){ clear(); }

    void push(const T& val)
    {
        Node* newNode = new Node(val, m_top);
        m_top = newNode;
        m_size++;
    }

    void pop()
    {
       Node* temp = m_top;
       m_top = m_top->next;
       delete[] temp;
    }

    T top() { return m_top->data; }

    bool empty() { return m_top == nullptr; }

    void clear()
    {
        while(!empty())
        {
            pop();
        }
    }
};

bool isNum(char data) { return (data >= '0' && data <= '9'); }
bool isAlp(char data) { return (data >= 'a' && data <= 'z'); }
bool isCAlp(char data) { return (data >= 'A' && data <= 'Z'); }
bool isLeft(char data) { return data == '('; }
bool isRight(char data) { return data == ')'; }
bool isOp(char data) { return (data == '+' || data == '-' || data == '*' || data == '/'); }

// 1.判断是否合法
bool checkValid(string exp)
{
    Stack<char> s;
    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];
        if(isLeft(c)) { s.push(c); }
        else if(isRight(c))
        {
            if(s.empty()) return false;
            s.pop();
        }

        if (i < exp.length() - 1)
        {
            char next = exp[i + 1];
            if(isOp(c))
            {
                if(isOp(next) || isRight(next)) return false;
            }
            else if(isLeft(c))
            {
                if(isOp(next) || isRight(next)) return false;
            }
        }
    }

    if (isOp(exp[0]) || isOp(exp.back())) return false;

    return s.empty();
}


// 2.中缀转后缀
int getPriority(char op)
{
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
}





void Transform(string exp, string& Bexp)
{
    Stack<char> ops;
    for(int i = 0; i < exp.length(); i++)
    {
        if (isNum(exp[i]) || isAlp(exp[i]) || isCAlp(exp[i])) { Bexp += exp[i]; }
        else if (isLeft(exp[i])) { ops.push(exp[i]); }
        else if (isRight(exp[i]))
        {
            while (!ops.empty() && ops.top() != '(')
            {
                Bexp += ops.top();
                ops.pop();
            }
            ops.pop();
        }
        else
        {
            while (!ops.empty() && ops.top() != '(' && getPriority(ops.top()) >= getPriority(exp[i]))
            {
                Bexp += ops.top();
                ops.pop();
            }
            ops.push(exp[i]);
        }
    }
    while (!ops.empty())
    {
        Bexp += ops.top();
        ops.pop();
    }
}

// 3.后缀求值
int getValue(char data)
{
    if(isNum(data)) { return (int) (data - '0'); }
    if(isAlp(data)) { return (int) (data - 'a' + 10); }
    if(isCAlp(data)) { return (int) (data - 'A' + 36); }
}

int caculate(string Bexp, int& ans)
{
    Stack<int> stack;
    for (int i = 0; i < Bexp.length(); i++)
    {
        char c = Bexp[i];
        if(isNum(c) || isAlp(c) || isCAlp(c))
        {
            stack.push(getValue(c));
        }
        else
        {
            int v2 = stack.top(); 
            stack.pop();
            int v1 = stack.top();
            stack.pop();

            if(c == '+') { stack.push(v1 + v2); }
            else if(c == '-') { stack.push(v1 - v2); }
            else if(c == '*') { stack.push(v1 * v2); }
            else
            {
                if(v2 == 0) return 2;
                stack.push(v1 / v2);
            }
        }
    }
    ans = stack.top();
    return 0;
}




int main()
{
    ifstream inFile("in.txt");
    ofstream outFile("out.txt");
    int n;
    inFile >> n;
    string exp1, exp2;
    for(int caseIdx = 1; caseIdx <= n; caseIdx++)
    {
        inFile >> exp1 >> exp2;
        string Bexp1 = "";
        string Bexp2 = "";
        int ans1 = 0;
        int ans2 = 0;
        outFile << "测试用例" << caseIdx << "：";
        if(!checkValid(exp1) || !checkValid(exp2))
        {
            if(!checkValid(exp1)) { outFile << "表达式1无效！" ; }
            if(!checkValid(exp2)) { outFile << "表达式2无效！"; }
            outFile << endl;
        }
        else
        {
            Transform(exp1, Bexp1);
            Transform(exp2, Bexp2);
            if(caculate(Bexp1, ans1) == 2 || caculate(Bexp2, ans2) == 2)
            {
                if(caculate(Bexp1, ans1) == 2) { outFile << "表达式1除0出错！"; }
                if(caculate(Bexp2, ans2) == 2) { outFile << "表达式2除0出错！"; }
                outFile << endl;
            }
            else
            {
                if(ans1 == ans2) { outFile << "TRUE" << endl; }
                else { outFile << "FALSE" << endl; }
            }
        }
        
    }
    return 0;
}