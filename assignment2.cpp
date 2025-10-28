/*"Implementing Queues and Stacks Using Linked Lists for Real-
World Task Management Systems"
This problem involves designing and implementing queues and stacks
using linked lists, focusing on their practical applications in real-world
scenarios such as:
• Task Scheduling System (Queue): Managing tasks in a first-in,
first-out (FIFO) order, such as print job scheduling or process
management in an operating system.
• Undo/Redo Functionality (Stack): Implementing an undo/redo
feature in text editors or design software using a last-in, first-out (LIFO)
approach.
NAME = SHANTANU CHOUDHARI
ROLL = 23304*/
#include <iostream>
#include <string>
using namespace std;

// Node structure for both Queue and Stack
struct Node {
    string data;
    Node* next;
    Node(string val) : data(val), next(nullptr) {}
};

// ================== Queue Implementation ==================
class Queue {
private:
    Node *front, *rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue operation (Insert at rear)
    void enqueue(string task) {
        Node* temp = new Node(task);
        if (!rear) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        cout << "Enqueued task: " << task << endl;
    }

    // Dequeue operation (Remove from front)
    void dequeue() {
        if (!front) {
            cout << "Queue is empty! No task to process.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr; // Queue became empty
        cout << "Dequeued task (processed): " << temp->data << endl;
        delete temp;
    }

    // Display the queue
    void display() {
        Node* temp = front;
        cout << "Queue (Task Scheduling): ";
        if (!temp) {
            cout << "EMPTY\n";
            return;
        }
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// ================== Stack Implementation ==================
class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}

    // Push operation (Insert at top)
    void push(string action) {
        Node* temp = new Node(action);
        temp->next = top;
        top = temp;
        cout << "Pushed action: " << action << endl;
    }

    // Pop operation (Remove from top)
    void pop() {
        if (!top) {
            cout << "Stack is empty! No action to undo.\n";
            return;
        }
        Node* temp = top;
        cout << "Popped action (undo): " << temp->data << endl;
        top = top->next;
        delete temp;
    }

    // Display the stack
    void display() {
        Node* temp = top;
        cout << "Stack (Undo/Redo): ";
        if (!temp) {
            cout << "EMPTY\n";
            return;
        }
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// ================== Main Program ==================
int main() {
    // -------- Queue Demo: Task Scheduling --------
    cout << "===== Task Scheduling System (Queue) =====\n";
    Queue taskQueue;
    taskQueue.enqueue("Print Job 1");
    taskQueue.enqueue("Print Job 2");
    taskQueue.enqueue("Print Job 3");
    taskQueue.display();
    taskQueue.dequeue();
    taskQueue.display();

    cout << "\n---------------------------------\n";

    // -------- Stack Demo: Undo/Redo --------
    cout << "===== Undo/Redo System (Stack) =====\n";
    Stack mystack;
    mystack.push("Type 'Hello'");
    mystack.push("Delete 'o'");
    mystack.push("Insert 'World'");
    mystack.display();
    mystack.pop();
    mystack.display();

    return 0;
}
/*===== Task Scheduling System (Queue) =====
Enqueued task: Print Job 1
Enqueued task: Print Job 2
Enqueued task: Print Job 3
Queue (Task Scheduling): Print Job 1 -> Print Job 2 -> Print Job 3 -> NULL
Dequeued task (processed): Print Job 1
Queue (Task Scheduling): Print Job 2 -> Print Job 3 -> NULL

---------------------------------
===== Undo/Redo System (Stack) =====
Pushed action: Type 'Hello'
Pushed action: Delete 'o'
Pushed action: Insert 'World'
Stack (Undo/Redo): Insert 'World' -> Delete 'o' -> Type 'Hello' -> NULL
Popped action (undo): Insert 'World'
Stack (Undo/Redo): Delete 'o' -> Type 'Hello' -> NULL*/
