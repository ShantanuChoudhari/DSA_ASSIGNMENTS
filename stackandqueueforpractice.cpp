/*#include <iostream>
using namespace std;

// ---------------------------- Stack Class ----------------------------
class Stack {
    int arr[100];
    int top;
    int size;

public:
    Stack(int s = 100) {
        size = s;
        top = -1;
    }

    // Push operation
    void push(int value) {
        if (top == size - 1) {
            cout << "Stack Overflow! Cannot push.\n";
            return;
        }
        arr[++top] = value;
        cout << "Pushed " << value << " onto stack.\n";
    }

    // Pop operation
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow! Cannot pop.\n";
            return;
        }
        cout << "Popped " << arr[top--] << " from stack.\n";
    }

    // Display stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

// ---------------------------- Queue Class ----------------------------
class Queue {
    int arr[100];
    int front, rear;
    int size;

public:
    Queue(int s = 100) {
        size = s;
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (rear == size - 1) {
            cout << "Queue Overflow! Cannot enqueue.\n";
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = value;
        cout << "Enqueued " << value << " into queue.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! Cannot dequeue.\n";
            return;
        }
        cout << "Dequeued " << arr[front++] << " from queue.\n";
        if (front > rear)
            front = rear = -1; // Reset after last element
    }

    // Display queue
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front to rear): ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

// ---------------------------- Main Menu ----------------------------
int main() {
    Stack s;
    Queue q;
    int mainChoice, subChoice, value;

    while (true) {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Stack Operations\n";
        cout << "2. Queue Operations\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                while (true) {
                    cout << "\n---- Stack Menu ----\n";
                    cout << "1. Push\n";
                    cout << "2. Pop\n";
                    cout << "3. Display\n";
                    cout << "4. Back to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> subChoice;

                    if (subChoice == 4) break;

                    switch (subChoice) {
                        case 1:
                            cout << "Enter value to push: ";
                            cin >> value;
                            s.push(value);
                            break;
                        case 2:
                            s.pop();
                            break;
                        case 3:
                            s.display();
                            break;
                        default:
                            cout << "Invalid choice!\n";
                    }
                }
                break;

            case 2:
                while (true) {
                    cout << "\n---- Queue Menu ----\n";
                    cout << "1. Enqueue\n";
                    cout << "2. Dequeue\n";
                    cout << "3. Display\n";
                    cout << "4. Back to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> subChoice;

                    if (subChoice == 4) break;

                    switch (subChoice) {
                        case 1:
                            cout << "Enter value to enqueue: ";
                            cin >> value;
                            q.enqueue(value);
                            break;
                        case 2:
                            q.dequeue();
                            break;
                        case 3:
                            q.display();
                            break;
                        default:
                            cout << "Invalid choice!\n";
                    }
                }
                break;

            case 3:
                cout << "Exiting program. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
*/


/*#include <iostream>
using namespace std;

// ---------------------------- Node Structure ----------------------------
struct Node {
    int data;
    Node* next;
};

// ---------------------------- Stack Class ----------------------------
class Stack {
    Node* top;

public:
    Stack() { top = NULL; }

    // Push operation
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << " onto stack.\n";
    }

    // Pop operation
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty! Cannot pop.\n";
            return;
        }
        Node* temp = top;
        cout << "Popped " << top->data << " from stack.\n";
        top = top->next;
        delete temp;
    }

    // Display stack
    void display() {
        if (top == NULL) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

// ---------------------------- Queue Class ----------------------------
class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Enqueued " << value << " into queue.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty! Cannot dequeue.\n";
            return;
        }

        Node* temp = front;
        cout << "Dequeued " << front->data << " from queue.\n";
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    // Display queue
    void display() {
        if (front == NULL) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front to rear): ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

// ---------------------------- Main Menu ----------------------------
int main() {
    Stack s;
    Queue q;
    int mainChoice, subChoice, value;

    while (true) {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Stack Operations\n";
        cout << "2. Queue Operations\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                while (true) {
                    cout << "\n---- Stack Menu ----\n";
                    cout << "1. Push\n";
                    cout << "2. Pop\n";
                    cout << "3. Display\n";
                    cout << "4. Back to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> subChoice;

                    if (subChoice == 4) break;

                    switch (subChoice) {
                        case 1:
                            cout << "Enter value to push: ";
                            cin >> value;
                            s.push(value);
                            break;
                        case 2:
                            s.pop();
                            break;
                        case 3:
                            s.display();
                            break;
                        default:
                            cout << "Invalid choice!\n";
                    }
                }
                break;

            case 2:
                while (true) {
                    cout << "\n---- Queue Menu ----\n";
                    cout << "1. Enqueue\n";
                    cout << "2. Dequeue\n";
                    cout << "3. Display\n";
                    cout << "4. Back to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> subChoice;

                    if (subChoice == 4) break;

                    switch (subChoice) {
                        case 1:
                            cout << "Enter value to enqueue: ";
                            cin >> value;
                            q.enqueue(value);
                            break;
                        case 2:
                            q.dequeue();
                            break;
                        case 3:
                            q.display();
                            break;
                        default:
                            cout << "Invalid choice!\n";
                    }
                }
                break;

            case 3:
                cout << "Exiting program. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
*/
