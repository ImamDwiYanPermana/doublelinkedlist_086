#include <string>
#include <iostream>
using namespace std;

class Node {
public :
    int noMhs;
    string name;
    Node* next;
    Node* prev;
};

class doubleleLinkedList {
private:
    Node* START = NULL;
public:
    void addNode();
    bool search(int tollNo, Node** previouse, Node** current);
    bool deletNode(int rollNo);
    bool listEmpty();
    void traverse();
    void revtraverse();
    void hapus();
    void searchData();
};
void doubleleLinkedList::addNode() {
    int nim;
    string nm;
    cout << "\n ENter teh roll nmber of the student: ";
    cin >> nim;
    cout << "\n enter the name of student: ";
    cin >> nm;

    Node* newNode = new Node(); // step1
    newNode->noMhs = nim;//step 2
    newNode->name = nm;//step 2}

    /*insert a node in teh beging of  a doubly - linked list*/
    if (START == NULL || nim <= START->noMhs) { // chek if data null
        if (START != NULL && nim == START->noMhs) {
            cout << "\n duplicate not allowed" << endl;
            return;
        }
        newNode->next = START; // STep 3
        if (START != NULL) 
            START->prev = newNode; // Step 4
        newNode->prev = NULL; // Step 5
        START = newNode; /// Step 6
        return;
    }
    /*Inserting a node Between Two node in the list*/
    Node* current = START; // 1.d
    Node* previouse = NULL;// 1.b
    while (current->next != NULL && nim == current->next->noMhs < nim)// step 1c
    {
        cout << "Duplicate roll number not allowed " << endl;
        return;
    }
    newNode->next = current->next; // step 4
    newNode -> prev = current; // step 5
    if (current->next != NULL)
        current->next->prev = newNode;//step 6
    current->next = newNode;// step 7
}

bool doubleleLinkedList::search(int rollNo, Node** previouse, Node** current) {
    *previouse = NULL; // step 1.a
    *current = START; // 1.b
    while (*current != NULL && (*current)->noMhs != rollNo) {
        *previouse = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}

bool doubleleLinkedList::deletNode(int rollNo) {
    Node* previouse, *current;
    previouse = current = NULL;
    if (search(rollNo, &previouse, &current) == false)
        return false;
    if (current->next != NULL)
        current->next->prev = previouse; //step 2
    if (previouse != NULL)
        previouse->next = current->next; //step 3
    else
        START = current->next;
    delete current; //step 4
    return true;
}
bool doubleleLinkedList::listEmpty() {
    return (START == NULL);
}
void doubleleLinkedList::traverse(){
    if (listEmpty())
        cout << "\nList is empty" << endl;
    else {
        cout << "\nRecords in ascending order of roll number are: " << endl;
        Node* currentNode = START;
        while (currentNode != NULL) {
            cout << currentNode->noMhs << " " << currentNode->name << endl;
            currentNode = currentNode->next;
        }
    }
}
void doubleleLinkedList::revtraverse(){
    if (listEmpty()) {
        cout << "\nList is empty" << endl;
    }
    else {
        cout << "\nRecords in descending order of roll number are: " << endl;
        Node* currentNode = START;
        while (currentNode->next != NULL)
            currentNode = currentNode->next;
        while (currentNode != NULL) {
            cout << currentNode->noMhs << " " << currentNode->name << endl;
            currentNode = currentNode->prev;
        }
    }

}
void doubleleLinkedList::hapus() {
    if (listEmpty()) {
        cout << "\nList is empty" << endl;

    }
    cout << "\nEnter the roll number of the student whose record is to deleted: ";
    int rollNo;
    cin >> rollNo;
    cout << endl;
    if (doubleleLinkedList::deletNode(rollNo) == false)
        cout << "Record not found" << endl;
    else
        cout << "Record with roll number " << rollNo << " deleted" << endl;
}
void doubleleLinkedList::searchData() {
    if (listEmpty() == true) {
        cout << "\nList is empty" << endl;

    }
    Node* prev, * curr;
    prev = curr = NULL;
    cout << "\nEnter the roll number of the student whose record you want to search: ";
    int num;
    cin >> num;
    if (doubleleLinkedList::search(num, &prev, &curr) == false)
        cout << "\nRecord not found" << endl;
    else {
        cout << "\nRecord found" << endl;
        cout << "\nRecord number: " << curr->noMhs << endl;
        cout << "\nName: " << curr->name << endl;
    }
}
int main()
{
    doubleleLinkedList obj;
    while (true) {
        try {
            cout << "\nMenu" << endl;
            cout << "1. Add a record to the list" << endl;
            cout << "2. Delete a record from the list" << endl;
            cout << "3. View all record in the ascending order of roll numbers" << endl;
            cout << "4. View all record in the descending order of roll numbers" << endl;
            cout << "5. Search for a record in the list" << endl;
            cout << "6. Exit" << endl;
            cout << "\nEnter tour choice (1-6): ";
            char ch;
            cin >> ch;
            switch (ch) {
            case '1':
                obj.addnode();
                break;
            case '2':
                obj.hapus();
                break;
            case '3':
                obj.traverse();
                break;
            case '4':
                obj.revtraverse();
                break;
            case '5':
                obj.searchData();
                break;
            case '6':
                return 0;
            default:
                cout << "\nInvalid option" << endl;
                break;
            }
        }
        catch (exception& e) {
            cout << "check for the values entered." << endl;
        }
    }
}
}


