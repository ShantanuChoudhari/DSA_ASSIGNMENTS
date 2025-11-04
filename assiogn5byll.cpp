#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    int priority;
    Node* next;
};

// Class for Priority Queue
class PriorityQueue {
private:
    Node* front;

public:
    PriorityQueue() {
        front = nullptr;
    }

    // Function to insert an element into the priority queue
    void push(int data, int priority) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->priority = priority;
        newNode->next = nullptr;

        // If the queue is empty or new node has higher priority than front
        if (front == nullptr || priority > front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            // Traverse and find the position to insert
            Node* temp = front;
            while (temp->next != nullptr && temp->next->priority >= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Remove the highest priority element
    void pop() {
        if (front == nullptr) {
            cout << "Priority Queue is empty.\n";
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;
    }

    // Peek at the element with highest priority
    int peek() {
        if (front == nullptr) {
            cout << "Priority Queue is empty.\n";
            return -1;
        }
        return front->data;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display queue (for debugging)
    void display() {
        Node* temp = front;
        cout << "Priority Queue: ";
        while (temp != nullptr) {
            cout << "(" << temp->data << ", p=" << temp->priority << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Driver code
int main() {
    PriorityQueue pq;

    pq.push(10, 2);
    pq.push(5, 1);
    pq.push(20, 3);
    pq.push(15, 2);

    pq.display();

    cout << "Top element: " << pq.peek() << endl;

    pq.pop();
    pq.display();

    pq.pop();
    pq.display();

    return 0;
}
