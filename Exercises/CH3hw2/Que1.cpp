#include <iostream>
#include <string>

using namespace std;

template <typename T>
class ManualQueue 
{
private:
    struct Node 
    {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* m_front; 
    Node* m_rear;  
    size_t m_size;

public:
    ManualQueue() : m_front(nullptr), m_rear(nullptr), m_size(0) {}

    bool empty() const { return m_front == nullptr; }

    size_t size() const { return m_size; }

    void push(const T& value) 
    {
        Node* newNode = new Node(value);
        if (empty()) 
        {
            m_front = m_rear = newNode;
        } 
        else 
        {
            m_rear->next = newNode;
            m_rear = newNode;
        }
        m_size++;
    }

    void pop() 
    {
        if (empty()) return;
        Node* temp = m_front;
        m_front = m_front->next;
        delete temp; 
        m_size--;
        if (m_front == nullptr) {
            m_rear = nullptr;
        }
    }

    T front() const {
        if (empty()) throw std::runtime_error("Queue empty");
        return m_front->data;
    }

};

struct Point {
    int x;    
    int y;     
    int dist; 
};


int knightMinSteps(std::string startPos, std::string endPos) {
    int startX = startPos[0] - 'a';
    int startY = startPos[1] - '1';
    int targetX = endPos[0] - 'a';
    int targetY = endPos[1] - '1';

    if (startX == targetX && startY == targetY) return 0;

    bool visited[8][8] = {false};
    
    const int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    ManualQueue<Point> q;
    q.push({startX, startY, 0});
    visited[startX][startY] = true;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !visited[nx][ny]) {
                if (nx == targetX && ny == targetY) {
                    return curr.dist + 1;
                }

                visited[nx][ny] = true;
                q.push({nx, ny, curr.dist + 1});
            }
        }
    }
    return -1; 
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << knightMinSteps(s1, s2) <<endl;
    return 0;
}