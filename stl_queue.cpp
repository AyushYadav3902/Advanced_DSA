// write an c++ program using STL queue to perform push, pop, front, back, size, empty operations on queue.
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;

    // Push elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Queue elements are inserted." << endl;
    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;
    cout << "Size of queue: " << q.size() << endl;
    q.pop();
    cout << "After pop, front element: " << q.front() << endl;
    if (q.empty())
        cout << "Queue is empty." << endl;
    else
        cout << "Queue is not empty." << endl;

    return 0;
}