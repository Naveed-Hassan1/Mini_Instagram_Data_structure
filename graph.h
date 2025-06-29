#pragma once
#include<iostream>
#include <string>
#include"user.h"
using namespace std;

struct gnode
{
    string vertex;   //Name of a vertex
    string status;  //Blocked or not etc
    string type;  //Friends or Best Friends etc
    gnode* next;
    gnode* edge;   //Edge willl be connecting with that
public:
    gnode(string vertex);
};

class graph
{
    gnode* head;
public:
    friend class user;
    void FEED_UPLOADER(string& text, string& time, string name,user* Main_root);
    gnode* ROOT();
    graph();
    void print_follower_list(string temp);
    void print_following_list(gnode*);
    gnode* vertex_finder(user* name);
    void vertex_insertion(string vertex);
    void edge_insertion_directed(string from, string to, string type, string status);
    ~graph();
    void display();
};