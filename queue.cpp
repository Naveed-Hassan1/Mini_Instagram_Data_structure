#include "queue.h"

qnode::qnode(string message)
{
    this->message = message;
    this->next = nullptr;
}
void queue::delete_from_center(qnode*& head, string& target)
{
    if (isempty()) return;
    if (head->message == target)
    {
        qnode* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    qnode* current = head;
    qnode* prev = nullptr;
    while (current != nullptr && current->message != target)
    {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) return; // Target not found
    prev->next = current->next;
    delete current;
}

queue::queue()
{
    head = nullptr;
}

bool queue::isempty()
{
    return head == nullptr;
}

void queue::enqueue(qnode*& head, string message)
{
    qnode* new_node = new qnode(message);
    if (head == nullptr)
    {
        head = new_node;
        return;
    }
    qnode* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void queue::dequeue()
{
    if (isempty()) return;
    qnode* temp = head;
    head = head->next;
    delete temp;
}

qnode* queue::front()
{
    return head;
}

void queue::print(qnode* head)
{
    if (isempty())
    {
        cout << "This section is empty.\n";
        return;
    }
    qnode* temp = head;
    while (temp != nullptr)
    {
        cout <<temp->message << '\n';
        temp = temp->next;
    }
}

queue::~queue()
{
    while (head != nullptr)
    {
        qnode* temp = head->next;
        delete head;
        head = temp;
    }
}