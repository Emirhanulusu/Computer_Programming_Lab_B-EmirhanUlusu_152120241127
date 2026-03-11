#include <iostream>
#include <string>

using namespace std;

struct Node {
    string title;
    Node* next;
};

Node* head = NULL;

void addSong(string song) {
    Node* newNode = new Node;
    newNode->title = song;
    newNode->next = head;
    head = newNode;

    cout << "Song added!\n";
}

void searchSong(string song) {
    Node* temp = head;

    while(temp != NULL) {
        if(temp->title == song) {
            cout << "Song found!\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Song not found.\n";
}

void listSongs() {
    Node* temp = head;
    int index = 1;

    if(temp == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }

    while(temp != NULL) {
        cout << index << ". " << temp->title << endl;
        temp = temp->next;
        index++;
    }
}

int main() {
    int choice;
    string song;

    do {
        cout << "\n1. Add Song\n";
        cout << "2. Search Song\n";
        cout << "3. List Songs\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        cin.ignore();

        switch(choice) {
            case 1:
                cout << "Enter song title: ";
                getline(cin, song);
                addSong(song);
                break;

            case 2:
                cout << "Enter song to search: ";
                getline(cin, song);
                searchSong(song);
                break;

            case 3:
                listSongs();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 4);

    return 0;
}