#include "Messages_stack.h"
msgnode::msgnode(string message)
{
    this->message = message;
    this->next = nullptr;
}
Messages_stack::Messages_stack()
{
    this->person_name = "Empty";
    head = nullptr;
}

bool Messages_stack::isempty()
{
    return head == nullptr;
}

void Messages_stack::push(msgnode*& head,string message)
{
    msgnode* new_node = new msgnode(message);
    new_node->next = head;
    head = new_node;
}

void Messages_stack::pop()
{
    if (isempty()) return;
    msgnode* temp = head;
    head = head->next;
    delete temp;
}

msgnode* Messages_stack::top()
{
    return head;
}

void Messages_stack::print(msgnode* head)
{
    if (isempty())
    {
        cout << "This section is empty.\n";
        return;
    }
    msgnode* temp = head;
    while (temp != nullptr)
    {
        cout << "Message: " << temp->message << '\n';
        temp = temp->next;
    }
}

Messages_stack::~Messages_stack()
{
    while (head != nullptr)
    {
        msgnode* temp = head->next;
        delete head;
        head = temp;
    }
}
