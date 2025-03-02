[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

void addWaypointAtBeginning(T& data)
This method adds a new node to the beginning of the linked list. If the list is empty, it makes the new node become both
the head and the tail. If the list is not empty, it makes the new node become the head and the original head becomes the
head's next node. The tightest upperbound is O(1) because the method only includes comparisons and assignments, which 
are all constant time(each has a cost of 1).

void addWaypointAtEnd(T& data)
This method adds a new node to the end of the linked list. If the list is empty, it makes the new node become both the 
head and the tail. If the list is not empty, it makes the new node become the tail and the original tail becomes the
tail's previous node. The tightest upperbound is O(1) because the method only includes comparisons and assignments, 
which are all constant time(each has a cost of 1).

void addWaypointAtIndex(int index, T& data)
This method adds a new node to a specified index of the linked list. It begins by checking the edge cases. If the
index is invalid, it will output that the index is out of bounds. If the index is zero, it calls the 
addWaypointAtBeginning(data) method. If the index is the last index, it calls the addWaypointAtEnd(data) method. If the
index is not an edge case, the method inserts the new node at the specified index by creating a temporary node that is 
set to the node prior to the node at the specified index and reassigns the pointers so that temporary node's next node 
is the new node and the temporary node's original next node is the new node's next node. The tightest upperbound is O(N) 
because the method calls on the getWaypoint method, which uses a for loop to find the node at the specified index. This 
means that it must traverse through each element in the list until it reaches the specified index.

void removeWaypointAtBeginning()
This method removes the first node in the linked list. If the list is empty, it doesn't do anything. If the list
only contains one node, the list becomes empty. Otherwise, the head becomes the head's next node and the original head 
gets deleted. The tightest upperbound is O(1) because the method only includes comparisons and assignments, which are 
all constant time(each has a cost of 1).

void removeWaypointAtEnd()
This method removes the last node in the linked list. If the list is empty, it doesn't do anything. If the list only 
contains one node, the list becomes empty. Otherwise, the tail becomes the tail's previous node and the original tail 
gets deleted. The tightest upperbound is O(1) because the method only includes comparisons and assignments, which are 
all constant time(each has a cost of 1).

void removeWaypointAtIndex(int index)
This method removes a node at a specified index of the linked list. It begins by checking the edge cases. If the index 
is invalid, it will output that the index is out of bounds. If the index is zero, it calls the 
removeWaypointAtBeginning(data) method. If the index is the last index, it calls the removeWaypointAtEnd(data) method.
If the index is not an edge case, the method deletes the node at the specified index by creating a temporary node that 
is set to the node prior to the node at the specified index and reassigns the pointers so that the node after the one 
that gets removed is the next node after the temporary node. The tightest upperbound is O(N) because the method calls on 
the getWaypoint method, which uses a for loop to find the node at the specified index. This means that it must traverse 
through each element in the list until it reaches the specified index.

void traverseForward()
This method prints all the nodes from the first to the last. The tightest upperbound is O(N) because it uses a while 
loop to traverse through each element in the list and prints them out.

void traverseBackward()
This method prints all the nodes in reverse order from the last to the first. The tightest upperbound is O(N) because it 
uses a while loop to traverse through each element in the list and prints them out.

Node<T>* getWaypoint(int index)
This method retrieves a node at a specified index. If the index is invalid, it outputs that the index is out of bounds. 
Otherwise, it iterates through the list until it reaches the node at the specified index and returns this node. The 
tightest upperbound is O(N) because it uses a for loop to traverse through each element in the linked list until it 
finds the element at the specified index and assigns it to temp.

void setWaypoint(int index, T& data)
This method modifies the details of a waypoint at a specified index. The tightest upperbound is O(N) because the method 
calls on the getWaypoint method, which uses a for loop to find the node at the specified index. This means that it must 
traverse through each element in the list until it reaches the specified index.

void print()
This method prints all the nodes from the first to the last. The tightest upperbound is O(N) because it uses a while 
loop to traverse through each element in the list and prints them out.