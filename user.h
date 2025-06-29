#pragma once
#include"Messages_stack.h"
#include<iostream>
#include<ctime>
#include<string>
#include"stack.h"
#include"queue.h"
#include"graph.h"
using namespace std;
struct gnode;                         //Forward declaration
class insta;
class user
{
	string password;
public:
	void message_inbox(user* temp,int current);
	string last_login;                     //To display Account is active or not
	Messages_stack* messages;
	user* left,*right;
	string name;
	string city;
	stack post;
	stack Feed;
	void print_feed(user*,string& name);
	queue Requests,notifications;
	void pending_Requests_printer(user* root);
	void send_request(user*&,string& ,string&);
	void messages_send(user*,string,string,string&,int current);
	void post_uploader(user*,user*,string&,string&);
	void mine_post_check();
	void search(user*,string);
	void reset(user*, string,string);
	user* Root_finder(user* root,string user_name);
	user(string name, string password, string city);
	void insertion(user*& root, string, string, string,gnode* temp,int count);
	void makenull(user*&);
	user* login_helper(user* root, string& name, string& password);
	~user();
};
