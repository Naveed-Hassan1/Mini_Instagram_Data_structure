#pragma once
#include <iostream>
#include <string>
using namespace std;
struct msgnode
{
    string message;
    msgnode* next;
    msgnode(string message);
};
class Messages_stack
{
private:
public:
    string person_name;
    msgnode* head;
    Messages_stack();
    bool isempty();
    void push(msgnode*& head,string message);
    void pop();
    msgnode* top();
    void print(msgnode* head);
    ~Messages_stack();
};
