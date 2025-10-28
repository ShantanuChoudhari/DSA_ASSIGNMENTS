#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node {
    string description;
    Node* next;
};
class TaskQueue {
private:
    Node* front;
    Node* rear;

public:
    TaskQueue() : front(nullptr), rear(nullptr) {}

    void enqueue(string desc) {
        Node* newTask = new Node{desc, nullptr};
        if (rear == nullptr) {
            front = rear = newTask;
        } else {
            rear->next = newTask;
            rear = newTask;
        }
    }

    string dequeue() {
        if (front == nullptr) {
            return "";
        }
        Node* temp = front;
        string desc = temp->description;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
        return desc;
    } 

    bool isEmpty() {
        return front == nullptr;
    }

    void clear() {
        while (!isEmpty()) dequeue();
    }

    void showQueue(string name) {
        cout << name << " Queue (Front -> Rear): ";
        if (front == nullptr) {
            cout << "EMPTY";
        } else {
            Node* temp = front;
            while (temp != nullptr) {
                cout << temp->description << " ";
                temp = temp->next;
            }
        }
        cout << endl;
    }
};

class TaskStack {
private:
    Node* top;

public:
    TaskStack() : top(nullptr) {}

    void push(string desc) {
        Node* newTask = new Node{desc, top};
        top = newTask;
    }

    string pop() {
        if (top == nullptr) {
            return "";
        }
        Node* temp = top;
        string desc = temp->description;
        top = top->next;
        delete temp;
        return desc;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    string getString() {
        string rev = "";
        Node* temp = top;
        while (temp != nullptr) {
            rev = temp->description + rev;
            temp = temp->next;
        }
        return rev;
    }

    void clear() {
        while (!isEmpty()) pop();
    }

    void showStack(string name) {
        cout << name << " Stack (Top -> Bottom): ";
        if (top == nullptr) {
            cout << "EMPTY";
        } else {
            Node* temp = top;
            while (temp != nullptr) {
                cout << temp->description << " ";
                temp = temp->next;
            }
        }
        cout << endl;
    }
};

int main() {
    TaskQueue queue, undoQueue, redoQueue;
    TaskStack undoStack, redoStack;

    int mainChoice, queueChoice, stackChoice;
    string task;

    do {
        cout << "\n========= MAIN MENU =========\n";
        cout << "1. Queue (Task Scheduling + Undo/Redo)\n";
        cout << "2. Stack (Undo/Redo System)\n";
        cout << "0. Exit\n";
        cout << "Select Data Structure: ";
        cin >> mainChoice;
        cin.ignore(); 

        switch (mainChoice) {
            // ================= QUEUE SYSTEM =================
            case 1:
                do {
                    cout << "\n--- Queue: Task Scheduling ---\n";
                    cout << "1. Add Task\n";
                    cout << "2. Process Task (Dequeue)\n";
                    cout << "3. Undo Last Dequeue\n";
                    cout << "4. Redo Last Undo\n";
                    cout << "0. Back to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> queueChoice;
                    cin.ignore();

                    switch (queueChoice) {
                        case 1:
                            cout << "Enter task description: ";
                            getline(cin, task);
                            queue.enqueue(task);
                            cout << "Task added.\n";
                            break;
                        case 2: {
                            string removed = queue.dequeue();
                            if (removed != "") {
                                cout << "Processed: " << removed << endl;
                                undoQueue.enqueue(removed);
                                redoQueue.clear(); 
                            } else {
                                cout << "No tasks to process.\n";
                            }
                            break;
                        }
                        case 3: { // Undo dequeue
                            string lastUndo = undoQueue.dequeue();
                            if (lastUndo != "") {
                                queue.enqueue(lastUndo);
                                redoQueue.enqueue(lastUndo);
                                cout << "Undo: restored " << lastUndo << endl;
                            } else {
                                cout << "Nothing to undo.\n";
                            }
                            break;
                        }
                        case 4: { // Redo
                            string lastRedo = redoQueue.dequeue();
                            if (lastRedo != "") {
                                queue.enqueue(lastRedo);
                                cout << "Redo: re-added " << lastRedo << endl;
                            } else {
                                cout << "Nothing to redo.\n";
                            }
                            break;
                        }
                        case 0:
                            break;
                        default:
                            cout << "Invalid choice.\n";
                    }

                    // Always show current state
                    queue.showQueue("Current");
                    undoQueue.showQueue("Undo");
                    redoQueue.showQueue("Redo");

                } while (queueChoice != 0);
                break;

            // ================= STACK SYSTEM =================
            case 2:
                do {
                    cout << "\n--- Stack: Undo/Redo System ---\n";
                    cout << "1. Type Text (Push each character)\n";
                    cout << "2. Undo Last Character\n";
                    cout << "3. Redo Last Character\n";
                    cout << "0. Back to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> stackChoice;
                    cin.ignore();

                    switch (stackChoice) {
                        case 1:
                            cout << "Enter text: ";
                            getline(cin, task);
                            for (char c : task) {
                                string s(1, c);
                                undoStack.push(s);
                            }
                            redoStack.clear();
                            cout << "Text recorded.\n";
                            break;
                        case 2:
                            if (!undoStack.isEmpty()) {
                                string removed = undoStack.pop();
                                redoStack.push(removed);
                                cout << "Undo: removed '" << removed << "'\n";
                            } else {
                                cout << "Nothing to undo.\n";
                            }
                            break;
                        case 3:
                            if (!redoStack.isEmpty()) {
                                string redone = redoStack.pop();
                                undoStack.push(redone);
                                cout << "Redo: added '" << redone << "'\n";
                            } else {
                                cout << "Nothing to redo.\n";
                            }
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Invalid choice.\n";
                    }

                    cout << "Current Text: " << undoStack.getString() << endl;
                    undoStack.showStack("Undo");
                    redoStack.showStack("Redo");

                } while (stackChoice != 0);
                break;

            case 0:
                cout << "Exiting Program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (mainChoice != 0);

    return 0;
}
