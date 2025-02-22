#include <iostream>
#include <string>
#include "SpaceRoute.cpp"

using namespace std;

int main() {
    string mars = "Mars";
    string jupiter = "Jupiter";
    string saturn = "Saturn";
    string earth = "Earth";
    string venus = "Venus";

    SpaceRoute<string> voyagerRoute;

    voyagerRoute.addWaypointAtEnd(mars);
    voyagerRoute.addWaypointAtEnd(jupiter);
    voyagerRoute.addWaypointAtEnd(saturn);
    voyagerRoute.addWaypointAtBeginning(earth);
    voyagerRoute.addWaypointAtIndex(2, venus);

    cout << "Voyager Route (Forward):\n";
    voyagerRoute.traverseForward();

    cout << "\nVoyager Route (Backward):\n";
    voyagerRoute.traverseBackward();

    cout << "\nPrinting Route: \n";
    voyagerRoute.print();

    voyagerRoute.removeWaypointAtIndex(2);
    cout << "\nAfter Removing Venus: \n";
    voyagerRoute.print();

    // Added tests for remove at beginning & end

    voyagerRoute.removeWaypointAtEnd();
    cout << "\nAfter Removing Last Waypoint: \n";
    voyagerRoute.print();

    voyagerRoute.removeWaypointAtBeginning();
    cout << "\nAfter Removing First Waypoint: \n";
    voyagerRoute.print();

    // Added tests for set & get

    string mercury = "Mercury";
    voyagerRoute.setWaypoint(1, mercury);
    cout << "\nReplacing index one with Venus: \n";
    voyagerRoute.print();

    Node<string>* waypointNode = voyagerRoute.getWaypoint(1);
    if (waypointNode != nullptr) {
        cout << "\nGetting index one:\n" << waypointNode->data;
    }

    return 0;
}
