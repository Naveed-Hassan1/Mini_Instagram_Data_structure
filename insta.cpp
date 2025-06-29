#include"insta.h"
void insta::message_sendd(string& mine)
{
    string to,message;
    cout << "Enter the reciever id : ";
    cin >> to;
    cout << "Enter the message :  \n";
    cin >> message;
    root->messages_send(root, to, mine,message,current);
}

void insta::print_Following_list(user* root)
{
    gnode* temp = GRAPH.vertex_finder(root);
    GRAPH.print_following_list(temp);
}

void insta::print_Follower_list(string& name)
{
    GRAPH.print_follower_list(name);
}

void insta::feed(string& name)
{
    root->print_feed(root,name);
}

graph* insta::GRAPH_ROOT_ACESS()
{
    return &GRAPH;
}

void insta::vertex_print()
{
    GRAPH.display();
}

insta::insta()
{
    root = NULL;
    current = 0;
}
void insta::automatic()
{
	string password,user_name="0",city;
    ifstream in("password.txt");
    while (in >> user_name >> password >> city)
    {
        if (user_name != "0")
        {
            ++current;
            cout << "Account created (based onprevious use) for : " << user_name << '\n';
            GRAPH.vertex_insertion(user_name);             //creating the vertex in the edge
            gnode* temp = GRAPH.ROOT();
            root->insertion(root, user_name, password, city,temp,current);
        }
    }
}

void insta::search()
{
    string temp;
    cout << "Enter the user_name to search : \n";
    cin >> temp;
    root->search(root,temp);
}
user* insta::login()
{
    cout << "Enter the name of Account : \n";
    string name,password;
    cin >> name;
    cout << "Enter the password : \n";
    cin >> password;
    return(root->login_helper(root, name,password));
}


user*& insta::Root()
{
    return root;
}

void insta::resset()
{
    string city,user_name;
    cout << "Enter the city name of lost account : \n";
    cin >> city;
    cout << "Enter the user name of lost account : \n";
    cin >> user_name;
    root->reset(root,user_name,city);
}

insta::~insta()
{
    root->makenull(root);
    cout << "ALL - Accounts closed .\n";
}
void insta::pre_order(user* root)
{
    if (root != NULL)
    {
        cout << "\n--------------------------------------\n";
        cout << "User Name : " << root->name << '\n';
        cout << "City : " << root->city << '\n';
        cout << "Last login info : " << root->last_login << '\n';
        pre_order(root->left);
        pre_order(root->right);

    }
}

void insta::print_Graph()
{
    GRAPH.display();
}
void insta::Decision_Requests(user* Root)
{
    Root->pending_Requests_printer(Root);
    cout << "Enter the 1 To accept Request and 0 to cancel Request .\n";
    int choice;
    cin >> choice;
    string reciever_temporary_name = Root->name; //To give a notification to it 
    if (choice == 0)
    {
        string target;
        cout << "Enter the id to Cancel its request : \n";
        cin >> target;
        Root->Requests.delete_from_center(Root->Requests.head, target);
    }
    else if(choice == 1)
    {
        string temp,to;
        cout << "Enter the id to Accept its request : \n";
        cin >> temp;
        to = Root->name;
        GRAPH.edge_insertion_directed(temp, to, "Friend", "Active");
        Root->Requests.delete_from_center(Root->Requests.head, temp);
        Root = Root->Root_finder(root,temp);
        string t = "Your request is accepted by ";
        t += reciever_temporary_name;
        Root->notifications.enqueue(Root->notifications.head, t);
    }

}

void insta::send_request(user*& root,string& destination,string& From)
{
    root->send_request(root,destination,From);
}





user* insta::Root_finder()
{
    cout << "Enter the name of account to help us to confirm its really you trying to sign in .\n";
    string name;
    cin >> name;
    return(root->Root_finder(root,name));
}
void insta::signup()
{
    ++current;
	string password,user_name,city;
	int temp = 0;
	cout << "Enter the user name to create account : ";
	cin >> user_name;
    if (user_name.length() < 5)
    {
        cout << "\nYour username is not unique, it is being set to a new one.\n";
        srand(time(0));
        for (int i = 0; i < 3; ++i) 
        {
            int temp = 65 + rand() % 26; 
            user_name += char(temp);
        }
    }
    ofstream out("password.txt",ios::app);      //Opeining the file in append mode so it will not override above value
    out << user_name<<'\n';
    cout << "Enter the password to set : \n";
    cin >> password;
    while (password.length() < 5)
    {
        cout << "Enter th password again it is too short : \n";
        cin >> password;
    }
    out << password << '\n';
    cout << "Enter the city name : \n";
    cin >> city;
    out << city<<'\n';
	cout << "username : "<<user_name << '\n';
    cout << "Your password is setted to : " << password << '\n';
    cout << "your city is : " << city << '\n';
    GRAPH.vertex_insertion(user_name);
    gnode* t = GRAPH.ROOT();
    root->insertion(root,user_name, password, city,t,current);
}