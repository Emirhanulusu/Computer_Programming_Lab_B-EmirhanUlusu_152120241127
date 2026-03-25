
#include <iostream>
#include <string>
using namespace std;

struct Page {
    string url;
    string title;
    int accessTime[3];
    Page* next;
    Page* prev;
};

void visit(Page*& head, Page*& tail, Page*& current,
           string url, string title, int h, int m, int s) {

    Page* newPage = new Page;

    newPage->url = url;
    newPage->title = title;

    newPage->accessTime[0] = h;
    newPage->accessTime[1] = m;
    newPage->accessTime[2] = s;

    newPage->next = NULL;
    newPage->prev = NULL;

    if (head == NULL) {
        head = newPage;
        tail = newPage;
        current = newPage;
    }
    else {
        tail->next = newPage;
        newPage->prev = tail;
        tail = newPage;
        current = newPage;
    }
}

void goBack(Page*& current) {
    if (current == NULL) return;

    if (current->prev != NULL) {
        current = current->prev;
    }
    else {
        cout << "cannot go back\n";
    }
}

void goForward(Page*& current) {
    if (current == NULL) return;

    if (current->next != NULL) {
        current = current->next;
    }
    else {
        cout << "cannot go forward\n";
    }
}

void deleteCurrent(Page*& head, Page*& tail, Page*& current) {

    if (current == NULL) return;

    Page* temp = current;

    if (head == tail) {
        head = NULL;
        tail = NULL;
        current = NULL;
    }
    else if (current == head) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        current = head;
    }
    else if (current == tail) {
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        }
        current = tail;
    }
    else {
        Page* p = current->prev;
        Page* n = current->next;

        p->next = n;
        n->prev = p;

        current = n;
    }

    delete temp;
}

void display(Page* head, Page* current) {

    Page* temp = head;

    if (temp == NULL) {
        cout << "empty\n";
        return;
    }

    cout << "\nHistory:\n";

    while (temp != NULL) {

        if (temp == current) {
            cout << "* ";
        }
        else {
            cout << "- ";
        }

        cout << temp->title << " " << temp->url << " ";

        for (int i = 0; i < 3; i++) {
            cout << temp->accessTime[i];
            if (i != 2) cout << ":";
        }

        cout << endl;

        temp = temp->next;
    }
}

void clearHistory(Page*& head) {

    Page* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {

    Page* head = NULL;
    Page* tail = NULL;
    Page* current = NULL;

    int choice = 0;

    while (1) {

        cout << "\n1 visit\n2 back\n3 forward\n4 delete\n5 show\n6 exit\n";
        cin >> choice;

        if (choice == 1) {

            string url, title;
            int h, m, s;

            cout << "url: ";
            cin >> url;

            cout << "title: ";
            cin >> title;

            cout << "time: ";
            cin >> h >> m >> s;

            visit(head, tail, current, url, title, h, m, s);
        }
        else if (choice == 2) {
            goBack(current);
        }
        else if (choice == 3) {
            goForward(current);
        }
        else if (choice == 4) {
            deleteCurrent(head, tail, current);
        }
        else if (choice == 5) {
            display(head, current);
        }
        else if (choice == 6) {
            clearHistory(head);
            break;
        }
        else {
            cout << "wrong\n";
        }
    }

    return 0;
}

