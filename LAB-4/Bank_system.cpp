#include <iostream>
using namespace std;

struct MoneyBundle {
    string serialNumber;
    string currencyType;
    int billCounts[3];
};

struct MoneyNode {
    MoneyBundle data;
    MoneyNode* next;
};

class MoneyStack {
private:
    MoneyNode* top;

public:
    MoneyStack() {
        top = NULL;
    }

    void push(MoneyBundle m) {
        MoneyNode* temp = new MoneyNode;
        temp->data = m;
        temp->next = top;
        top = temp;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack empty\n";
            return;
        }
        MoneyNode* temp = top;
        top = top->next;
        delete temp;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void display() {
        MoneyNode* temp = top;
        cout << "\nMoney Stack:\n";
        while (temp != NULL) {
            cout << temp->data.serialNumber << " "
                 << temp->data.currencyType << " "
                 << temp->data.billCounts[0] << " "
                 << temp->data.billCounts[1] << " "
                 << temp->data.billCounts[2] << endl;
            temp = temp->next;
        }
    }
};

struct Customer {
    string customerName;
    string transactionType;
};

class CircularQueue {
private:
    int front, rear;
    Customer arr[5];

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isFull() {
        return (rear + 1) % 5 == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(Customer c) {
        if (isFull()) {
            cout << "Queue full\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % 5;
        }
        arr[rear] = c;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue empty\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % 5;
        }
    }

    Customer getFront() {
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "\nQueue empty\n";
            return;
        }
        cout << "\nCustomer Queue:\n";
        int i = front;
        while (true) {
            cout << arr[i].customerName << " "
                 << arr[i].transactionType << endl;
            if (i == rear) break;
            i = (i + 1) % 5;
        }
    }
};

int main() {
    MoneyStack ms;
    CircularQueue cq;
    int choice;

    do {
        cout << "\n1.Push Money\n2.Add Customer\n3.Process\n4.Display\n0.Exit\n";
        cin >> choice;

        if (choice == 1) {
            MoneyBundle m;
            cin >> m.serialNumber;
            cin >> m.currencyType;
            cin >> m.billCounts[0] >> m.billCounts[1] >> m.billCounts[2];
            ms.push(m);
        }

        else if (choice == 2) {
            Customer c;
            cin >> c.customerName;
            cin >> c.transactionType;
            cq.enqueue(c);
        }

        else if (choice == 3) {
            if (ms.isEmpty() || cq.isEmpty()) {
                cout << "Cannot process\n";
            } else {
                Customer c = cq.getFront();
                cout << "Serving " << c.customerName << endl;
                cq.dequeue();
                ms.pop();
            }
        }

        else if (choice == 4) {
            ms.display();
            cq.display();
        }

    } while (choice != 0);

    return 0;
}