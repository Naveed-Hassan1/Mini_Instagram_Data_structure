#include "stack.h"
node::node(string text,string time)
{
    this->text = text;
    this->time = time;
    this->next = NULL;
}
void stack::print(node* head)
{
    if (head == NULL)
    {
        cout << "Your post section is empty .\n";
        return;
    }
    node* temp = head;
    while (temp != nullptr)
    {
        cout << "Text: " << temp->text << ", Time: " << temp->time << endl;
        temp = temp->next;
    }
}
stack::stack()
{
    head = nullptr;
}

bool stack::isempty()
{
    return head == nullptr;
}

void stack::push(node*& head,string text,string time)
{
    if (head == NULL)
    {
        head = new node(text,time);
        return;
    }
    node* temp = new node(text,time);
    temp->next = head;
    head = temp;
}

void stack::pop()
{
    if (isempty()) return;
    node* temp = head;
    head = head->next;
    delete temp;
}

node* stack::top()
{
    return head;
}

stack::~stack()
{
    node* temp;
    while (head != nullptr)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
}
