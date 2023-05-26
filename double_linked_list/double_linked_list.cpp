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
    bool deletNode(int roolNo);
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

}

int main()
{
    std::cout << "Hello World!\n";
}


