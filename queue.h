#pragma once
#include <iostream>
#include <string>
using namespace std;
struct qnode
{
    string message;
    qnode* next;
    qnode(string message);
};
class queue
{
private:

public:
    void delete_from_center(qnode*&, string&);
    qnode* head;
    queue();
    bool isempty();
    void enqueue(qnode*& head, string message);
    void dequeue();
    qnode* front();
    void print(qnode* head);
    ~queue();
};