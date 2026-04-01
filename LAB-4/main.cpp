#include <iostream>
using namespace std;

#define MAX 10

struct Package{
	string PackageID;
	string DestinationCity;
	int Dimensions[5];
	Package *next;
};

struct Courier{
	string CourierName;
	string VehicleType;
};

void push(string ID, string city, int dim[5]);
Package* pop();
void displayStack();
void enqueue(string Name, string Vehicle);
Courier deQueue;
void displayQueue();
void dispatch();

int main(){
	
}

void push(string ID, string city, int dim[5]){
	int i;
	Package* newPackage = new Package;
	newPackage -> packageID = id;
	newPackage -> destinationCity = city;

	for (i=0; i<3; i++){
		newPackage -> dimensions[i] = dim[i];

	newPackage->next = top;
	top = newPackage;

	cout << "Package " << id << " added to the stack.\n";
}

Package* pop(){
	if (top == nullptr) {
		cout << "No package available at the moment.\n";
		return nullptr;
	}
	
	Package* temp=top;
	top = top->next;
	return temp;
}

void displayStack() {
	cout <<
cout << "\n--- Package Stack ---\n";

    if (top == nullptr) {
        cout << "Stack is empty.\n";
        return;
    }

    Package* temp = top;

    while (temp != nullptr) {
        cout << "ID: " << temp->packageID
             << " |\ City: " << temp->destinationCity
             << " |\ Dimensions: ["
             << temp->dimensions[0] << ", "
             << temp->dimensions[1] << ", "
	     << temp->dimensions[2] << ", "
	     << temp->dimensions[3] << ", "
	     << temp->dimensions[4] << "]\n";

        temp = temp->next;
    }
}


Courier queue[MAX];
int front = -1, rear = -1;

void enqueue(string Name, string Vehicle) {
    if ((rear + 1) % MAX == front) {
        cout << "Queue is full!\n";
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;

    queue[rear].CourierName = Name;
    queue[rear].VehicleType = Vehicle;

    cout << "Courier " << Name << " is added to queue.\n";
}

Courier dequeue() {
    Courier empty = {"", ""};

    if (front == -1) {
        cout << "No courier available!\n";
        return empty;
    }

    Courier temp = queue[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    return temp;
}

void displayQueue() {
    cout << "\n--- Courier Queue ---\n";

    if (front == -1) {
        cout << "Queue is empty.\n";
        return;
    }

    int i = front;

    while (true) {
        cout << "Name: " << queue[i].courierName
             << " || Vehicle: " << queue[i].vehicleType << endl;

        if (i == rear)
            break;

	i += 1 % MAX;
        }
}

void dispatch() {
    if (top == nullptr) {
        cout << "No package to dispatch!\n";
    }

    if (front == -1) {
        cout << "No courier available!\n";
        return;
    }

    Package* pkg = pop();

    cout << "\n=== DISPATCH ===\n";
    cout << "Courier " << Courier.CourierName
         << " (" << Courier.VehicleType << ") takes package "
         << Package->PackageID
         << " to " << Package->DestinationCity << endl;
}
