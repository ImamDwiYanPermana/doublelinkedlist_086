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

int main()
{
    std::cout << "Hello World!\n";
}


