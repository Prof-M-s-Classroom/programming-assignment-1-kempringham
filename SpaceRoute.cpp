#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T& data;
    Node* next;
    Node* prev;

    Node(T& d) : data(d), next(nullptr), prev(nullptr) {}
    void print() { cout << data << " "; }
};

class CelestialNode {
private:
    string name;
    double distance_from_earth;
    string mission_log;

public:
    CelestialNode(const string& n, double d, const string& log);
    const string& getName() const;
    double getDistance() const;
    const string& getMissionLog() const;
    void print() const { cout << name << " (" << distance_from_earth << " AU) - " << mission_log << endl; }
};

template <typename T>
class SpaceRoute {
private:
    Node<T>* head;
    Node<T>* tail;
    int length = 0; //ADDED LENGTH??

public:
    SpaceRoute(); // Constructor
    ~SpaceRoute(); // Destructor

    void addWaypointAtBeginning(T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            newNode->prev = tail;
            head = newNode;
        }
        length++;
    }
    void addWaypointAtEnd(T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (tail == nullptr) {
            tail = newNode;
            head = newNode;
        }
        else {
            newNode->prev = tail;
            newNode->next = head;
            tail = newNode;
        }
        length++;
    }
    void addWaypointAtIndex(int index, T& data) {
        if (index < 0 || index > length) {
            cout << "Index is out of bounds." << endl;
        }
        if (index == length) {
            addWaypointAtEnd(data);
        }
        // UPDATE FOR DOUBLY LINKED
        Node<T>* newNode = new Node<T>(data);
        Node<T> * temp = getWaypoint(index - 1);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
    }
    void removeWaypointAtBeginning() {
        if (length == 0) {
            return;
        }
        Node<T>* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
        }
        delete temp;
        delete--;
    }
    //void removeWaypointAtEnd();
    //void removeWaypointAtIndex(int index);
    //void traverseForward();
    //void traverseBackward();
    Node<T>* getWaypoint(int index) {
        if (index < 0 || index >= length) {
            return nullptr;
        }
        Node<T> *temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }

    void setWaypoint(int index, T& data) {
        Node<T> *temp = getWaypoint(index,data);
        if (temp) {
            temp->data = data;
        }
    }
    void print(){

            Node<T>* current = head;
            while (current) {
                current->print();
                current = current->next;
            }
            cout << endl;
        }

};

