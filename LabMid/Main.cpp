
#include <iostream>
#include <string>
using namespace std;

struct DeploymentManager {
    int id;
    string service;
    string status;
};

struct Node {
    DeploymentManager data;
    Node* next;
};

class CloudManager {
private:
    Node* top;

public:
    // Constructor
    CloudManager() {
        top = nullptr;
    }

    // Destructor
    ~CloudManager() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Add deployment (Push)
    void addDeployment(int id, string service, string status) {
        Node* newNode = new Node;

        newNode->data.id = id;
        newNode->data.service = service;
        newNode->data.status = status;

        newNode->next = top;
        top = newNode;

        cout << "Data Added Successfully: " << id << endl;
    }

    // Remove latest deployment (Pop)
    void rollbackDeployment() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;

        cout << "Deployment deleted successfully: "
             << temp->data.id << endl;

        delete temp;
    }

    // Display deployment history
    void History() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = top;

        cout << "\n--- Deployment History (Top to Bottom) ---\n";

        while (temp != nullptr) {
            cout << "ID: " << temp->data.id
                 << ", Service: " << temp->data.service
                 << ", Status: " << temp->data.status << endl;

            temp = temp->next;
        }
    }
};

int main() {
    CloudManager c1;
    int choice;

    c1.addDeployment(101, "service1", "done");
    c1.addDeployment(102, "service2", "pending");
    c1.addDeployment(103, "service3", "partial complete");

    cout << "\nCurrent Deployment History:\n";
    c1.History();

    cout << "\nRolling Back Latest Deployment:\n";
    c1.rollbackDeployment();

    cout << "\nUpdated Deployment History:\n";
    c1.History();

    return 0;
}