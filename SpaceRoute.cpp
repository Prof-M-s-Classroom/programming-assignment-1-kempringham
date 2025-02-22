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
    int length = 0; // Added length value

public:
    SpaceRoute() { // Constructor
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    ~SpaceRoute() { // Destructor
        Node<T>* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void addWaypointAtBeginning(T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) { // checks if list is empty
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            head->prev = nullptr;
        }
        length++;
    }
    void addWaypointAtEnd(T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (tail == nullptr) { // checks if list is empty
            tail = newNode;
            head = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            tail->next = nullptr;
        }
        length++;
    }
    void addWaypointAtIndex(int index, T& data) {
        if (index < 0 || index > length) { // checks if index is out of bounds
            cout << "Index is out of bounds." << endl;
        }
        if (index == 0) { // checks if list is empty
            addWaypointAtBeginning(data);
        }
        if (index == length) { // checks if the index is at the end of the list(adding tail)
            addWaypointAtEnd(data);
        }
        Node<T>* newNode = new Node<T>(data);
        Node<T> * temp = getWaypoint(index - 1);
        newNode->next = temp->next;
        temp->next->prev = newNode;
        newNode->prev = temp;
        temp->next = newNode;
        length++;
    }
    void removeWaypointAtBeginning() {
        Node<T>* temp = head;
        if (length == 0) { // checks if list is empty
            return;
        }
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }
    void removeWaypointAtEnd() {
        Node<T>* temp = head;
        if (length == 0) {
            return;
        }
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
            }
        delete temp;
        length--;
    }
    void removeWaypointAtIndex(int index) {
        if (index < 0 || index >= length) {
            return;
        }
        if (index == 0) {
            removeWaypointAtBeginning();
            return;
        }
        if (index == length - 1) {
            removeWaypointAtEnd();
            return;
        }
        Node<T> *prev = getWaypoint(index - 1);
        Node<T>* temp = prev->next;
        prev->next = temp->next;
        temp->next->prev = prev;
        delete temp;
        length--;
    }

    void traverseForward() {
        Node<T> *temp = head;
        while (temp) {
            temp = temp->next;
        }

    }
    void traverseBackward() {
        Node<T> * pre;
        Node<T> * curr;
        Node<T> * next;
        pre = nullptr;
        curr = head;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }

    }
    Node<T>* getWaypoint(int index) {
        Node<T> *temp = head;
        if (index < 0 || index >= length) {
            return nullptr;
        }
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

