[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

void addWaypointAtBeginning(T& data)
This method adds a new waypoint to the beginning of the linked list. 
The tightest upperbound is O(1) because the method only includes comparisons and assignments, which are all constant 
time(each has a cost of 1).

void addWaypointAtEnd(T& data)
This method adds a new waypoint to the end of the linked list.
The tightest upperbound is O(1) because the method only includes comparisons and assignments, which are all constant
time(each has a cost of 1).

void addWaypointAtIndex(int index, T& data)
This method adds a new waypoint to a specified index of the linked list.
The tightest upperbound is O(N) because the method calls on the getWaypoint method, which uses a for loop to find 
the node at the specified index. This means that it must traverse through each element in the list until it reaches 
the specified index.

void removeWaypointAtBeginning()
This method removes the first waypoint in the linked list.
The tightest upperbound is O(1) because the method only includes comparisons and assignments, which are all constant
time(each has a cost of 1).

void removeWaypointAtEnd()
This method removes the last waypoint in the linked list.
The tightest upperbound is O(1) because the method only includes comparisons and assignments, which are all constant
time(each has a cost of 1).

void removeWaypointAtIndex(int index)
This method removes a waypoint at a specified index of the linked list.
The tightest upperbound is O(N) because the method calls on the getWaypoint method, which uses a for loop to find
the node at the specified index. This means that it must traverse through each element in the list until it reaches
the specified index.

void traverseForward()
This method prints all the waypoints from the first to the last.
The tightest upperbound is O(N) because it uses a while loop to traverse through each element in the list and prints 
them out.

void traverseBackward()
This method prints all the waypoints in reverse order from the last to the first.
The tightest upperbound is O(N) because it uses a while loop to traverse through each element in the list and prints
them out.

Node<T>* getWaypoint(int index)
This method retrieves a waypoint at a specified index.
The tightest upperbound is O(N) because it uses a for loop to traverse through each element in the linked list until it 
finds the element at the specified index and assigns it to temp.

void setWaypoint(int index, T& data)
This method modifies the details of a waypoint at a specified index.
The tightest upperbound is O(N) because the method calls on the getWaypoint method, which uses a for loop to find
the node at the specified index. This means that it must traverse through each element in the list until it reaches
the specified index.

void print()
This method displays the entire route.
The tightest upperbound is O(N) because it uses a while loop to traverse through each element in the list and prints 
them out.