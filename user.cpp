#include"user.h"
user::~user()
{
	delete[]messages;
}
user::user(string name, string password, string city)
{
	time_t now = time(0); //Getting current time
	this->last_login = ctime(&now); // Converting time_t to string using ctime
	this->name = name;
	this->password = password;
	this->city = city;
	left = right = NULL;
	messages = new Messages_stack[10];
}
void user::insertion(user*& root ,string name, string password, string city,gnode* temp,int count)
{
	if (root == NULL)
	{
		root = new user(name, password, city);
		//Creating the messages stack for the every id created
		for (int i = 0; i < count; ++i)
		{
				root->messages[i].person_name = temp->vertex;
				temp = temp->next;
		}
		return;
	}
	if (name > root->name)
	{
		insertion(root->right, name, password, city,temp,count);
	}
	else if (name < root->name)
	{
		insertion(root->left, name, password, city,temp,count);
	}
	else if (name == root->name)
	{
		cout << "Duplicate user_name Found .\n";
	}
}
void user::search(user* root,string name)
{
	if (root == NULL)
	{
		cout << "User Not Found .\n";
		return;
	}
	if (name > root->name)
	{
		search(root->right,name);
	}
	else if (name < root->name)
	{
		search(root->left,name);
	}
	else 
	{
		cout << "User Found successfully .\n";
		cout << "User name is : " << root->name << '\n';
		cout << "User city is : " << root->city << '\n';
		cout << "User Last login is : " << root->last_login << '\n';
	}
}

void user::makenull(user*& root)
{
	if (root != NULL)
	{
		makenull(root->left);
		makenull(root->right);
		delete root;
	}
}

user* user::login_helper(user* root, string& name, string& password)
{
	if (root == NULL)
	{
		cout << "User Not Found .\n";
		return NULL;
	}
	if (name > root->name)
	{
		return(login_helper(root->right, name,password));
	}
	else if (name < root->name)
	{
		return(login_helper(root->left, name,password));
	}
	else if(root->name==name&& root->password==password)
	{
		cout << "Logged in succesfully .\n";
		string temp = "You are logged in an new device .\n";
		root->notifications.enqueue(root->notifications.head, temp);       //A notifications will b erecieved og login
		return root;
	}
	else
	{
		cout << "PASSWORD OR USER_NAME IS INCORRECT ! \n";
		return NULL;
	}
	
}

void user::reset(user* root, string user_name,string city)
{
	if (root == NULL)
	{
		cout << "Accurrent with following details not found .\n";
		return;
	}
	if (name > root->name)
	{
		reset(root->right,user_name,city);
	}
	else if (name < root->name)
	{
		reset(root->left,user_name,city);
	}
	else
	{
		if (root->name == user_name && city == root->city)
		{
			cout << "You have succesfully Found Your Lost password .\n";
			cout << "Old password is : " << root->password << '\n';
			cout << "Enter the new password : \n";
			cin >> root->password;
		}
	}
}

void user::messages_send(user* root,string To,string from, string& message,int current)
{
	user* temp = Root_finder(root,To);
	for (int i = 0; i < current; ++i)
	{
		if (temp->messages[i].person_name == from)
		{
			temp->messages[i].push(temp->messages[i].head,message);
			string help;
			help = "You have recieved a message from ";
			help += from;
			temp->notifications.enqueue(temp->notifications.head, help);//Notification of a message
		}
	}
}

void user::send_request(user*& root,string& destination,string& From)
{

	user* To = Root_finder(root,destination);
	if (To == NULL)
	{
		cout << "User Not Found .\n";
	}
	else
	{

		if(To->Requests.front() != NULL && To->Requests.front()->message == From)
		{
			cout << "You have already sent the request .\n";
			return;
		}
		cout << "Request is SuccessFully sended to " << To->name << '\n';
		To->Requests.enqueue(To->Requests.head,From);
		string temp;
		temp = "You have a new friend request from ";
		temp += From;
	    To->notifications.enqueue(To->notifications.head,temp);//A notification will go to a person of new request
	}

}
void user::pending_Requests_printer(user* root)
{
	cout << "Request are From : \n";
	root->Requests.print(root->Requests.head);
}


user* user::Root_finder(user* root,string name)
{
	if (root == NULL)
	{
		cout << "User Not Found .\n";
		return NULL;
	}
	if (name > root->name)
	{
		return(Root_finder(root->right, name));
	}
	else if (name < root->name)
	{
		return(Root_finder(root->left, name));
	}
	else
	{
		return root;
	}
}


//To check a accurrent its posts
void user::mine_post_check()
{
	post.print(post.head);
}

//Main root is requireed to post it in their followes list
void user::post_uploader(user* root,user* Main_root,string& text,string& ttime)
{
 	
	root->post.push(post.head,text, ttime);
	//app->GRAPH.FEED_UPLOADER(text,ttime,root->name,Main_root);
}

void user::message_inbox(user* temp,int current)
{
	cout << "Messages inbox : \n";
	for (int i = 0; i < current; ++i)
	{
		cout << temp->messages[i].person_name << " : \n";
		messages[i].print(temp->messages[i].head);
	}
}

void user::print_feed(user* root,string& name)
{
	user* temp = Root_finder(root, name);
	temp->Feed.print(temp->Feed.head);
}