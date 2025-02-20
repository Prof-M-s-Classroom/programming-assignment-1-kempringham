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
    int length; // Added length function for insertion of waypoints

public:
    SpaceRoute(); // Constructor
    ~SpaceRoute(); // Destructor

    void prepend(T* value) {
        Node<T> newNode = new Node<T>(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void addWaypointAtBeginning(T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (length == 0) { // handling edge case for empty list
            head = newNode;
            tail = newNode;
            tail->next = head;
        }
        else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
            length++;
        }
    //void addWaypointAtEnd(T& data);
    //void addWaypointAtIndex(int index, T& data);
    //void removeWaypointAtBeginning();
    //void removeWaypointAtEnd();
    //void removeWaypointAtIndex(int index);
    //void traverseForward();
    //void traverseBackward();
    //Node<T>* getWaypoint(int index);
    //void setWaypoint(int index, T& data);
    void print(){

            Node<T>* current = head;
            while (current) {
                current->print();
                current = current->next;
            }
            cout << endl;
        }

};

