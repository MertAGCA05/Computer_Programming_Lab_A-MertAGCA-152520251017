#include <iostream>
#include <string>

using namespace std;

typedef struct Node{
    string data;
    Node* next;

    Node(string data2){
        data = data2;
        next = nullptr;
    }
};

Node* typeTheWord(Node* head, string nextWord);
Node* undoTheWord(Node* head);
void showTheWordList(Node* head);

int main()
{
    Node* head = NULL;
    Node* temp = head;
    string Word;
    cout << "Welcome to the text editor" << endl;
    cout << "Type: TYPE, Reverse: UNDO, Exit : EXIT, Show List: SHOW" << endl;
    cout << "Please type the required action: " << endl << endl;

    while (true){
        cin >> Word;
        if(Word == "TYPE"){
            typeTheWord(head, Word);
        }

        if (Word == "UNDO"){
            undoTheWord(head);
        }

        if (Word == "SHOW"){
            showTheWordList(head);
        }

        if (Word == "EXIT"){
            return 0;
        }
    }
}


Node* typeTheWord(Node* head, string nextWord){
    Node* newNode = new Node(nextWord);
    newNode->data = nextWord;

    if (head == NULL){
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL){
        temp= temp->next;
    }
    temp->next = newNode;

    return head;
}

Node* undoTheWord(Node* head){
    Node* temp = head;
    if(head->next->next != NULL)
        head = head->next;

    if (head == NULL)
        return NULL;
    if (head->next == NULL){
        delete head;
        return NULL;
    }

    delete temp->next;
    temp->next = NULL;

    return head;
}

void showTheWordList(Node* head){
    Node* temp = head;
    while (temp != NULL) {
        cout << "[" << temp->data << "] -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
