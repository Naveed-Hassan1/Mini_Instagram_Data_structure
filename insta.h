#pragma once
#include"graph.h"
#include <cstdlib>
#include <ctime>
#include<iostream>
#include<fstream>
#include<string> 
class insta
{
	user* root;
public:
	friend class user;
	graph* GRAPH_ROOT_ACESS();
	graph GRAPH;
	int current;
	void feed(string& name);//Print posts of its following
	~insta();
	void print_Following_list(user* root);
	insta();
	void print_Follower_list(string& name);
	void print_Graph();
	void Decision_Requests(user*);
	void send_request(user*&,string&,string&);
	void message_sendd(string& mine);
	void vertex_print();
	void resset();
	user* login();
	void search();
	void signup();//To signup with a new account
	void automatic();//that function will create old objects vased on previous use
	void pre_order(user*);
	user* Root_finder();
	user*& Root();
};
