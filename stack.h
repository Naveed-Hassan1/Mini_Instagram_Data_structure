#pragma once
#include<iostream>
#include<ctime>
#include<time.h>
#include<string>
using namespace std;
struct node
{
    string text;
    string time;
    node* next;
    node(string text,string);
};

class stack
{
public:
    node* head;
    void print(node* head);
    stack();
    bool isempty();
    void push(node*& data,string,string);
    void pop();
    node* top();
    ~stack();
};
