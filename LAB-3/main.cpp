#include <iostream>
using namespace std;

struct Song {
    string title;
    string artist;
    int ratings[3];
    
    Song* next;
    Song* prev;
};

Song* head = NULL;
Song* current = NULL

void addSong(string title, string artist, int s1, int s2, int s3){
    Song* newSong = new Song{title, artist, {s1,s2,s3}, NULL, NULL};
    
    if (head == NULL) {
        head = newSong;
        current = newSong;
        return;
    }
    
    Song* temp = head;
    
    
    while (temp->next != NULL){
        temp = temp-> next;
    }
    
    temp->next = newSong;
    newSong->prev = temp;
}

void nextSong() {
    if (current == NULL && current->next != NULL){
        cout < "No next songs!"
    }
    else{
        current = current -> next;
    }
}

void prevSong() {
    if (current == NULL && current->prev == NULL) {
        cout << "No previous song!\n";
    } else {
        current = current->prev;
    }
}

void deleteCurrentSong() {
    if (current == NULL) return;
    
    Song* toBeDeleted = current;
    
    if (toBeDeleted == head) {
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
            current = head;
        } 
        else {
            toBeDeleted->prev->next = toBeDeleted->next;
            
            if (toBeDeleted->next != nullptr) {
                toBeDeleted->next->prev = toBeDeleted->prev;
            }
            
            current = toBeDeleted->prev; 
        }
}

int main()
{
    
    return 0;
}
