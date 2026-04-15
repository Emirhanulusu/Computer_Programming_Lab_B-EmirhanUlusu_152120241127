#include <iostream>
using namespace std;

#define SIZE 100

struct Stack {
    int arr[SIZE];
    int top;
};

struct Queue {
    int arr[SIZE];
    int front, rear;
};

void push(Stack* s, int val) {
    s->arr[++s->top] = val;
}

int pop(Stack* s) {
    return s->arr[s->top--];
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

void enqueue(Queue* q, int val) {
    q->arr[++q->rear] = val;
}

int dequeue(Queue* q) {
    return q->arr[q->front++];
}

bool isEmptyQ(Queue* q) {
    return q->front > q->rear;
}

void transferStack(Stack* source, Stack* destination) {
    Queue q;
    q.front = 0;
    q.rear = -1;

    while (!isEmpty(source)) {
        enqueue(&q, pop(source));
    }

    while (!isEmptyQ(&q)) {
        push(destination, dequeue(&q));
    }
}

void printStack(Stack s) {
    while (s.top != -1) {
        cout << s.arr[s.top--] << " ";
    }
    cout << endl;
}

int main() {
    Stack stackA, stackB;
    stackA.top = -1;
    stackB.top = -1;

    int x;

    cout << "5 sayi giriniz: ";
    for (int i = 0; i < 5; i++) {
        cin >> x;
        push(&stackA, x);
    }

    cout << "Stack A: ";
    printStack(stackA);

    transferStack(&stackA, &stackB);

    cout << "Stack B: ";
    printStack(stackB);

    return 0;
}