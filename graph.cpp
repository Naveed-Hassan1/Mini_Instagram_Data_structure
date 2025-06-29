#include"graph.h"

gnode::gnode(string vertex)
{
    this->vertex = vertex;
    status = "Active";
    type = "Friend";
    edge = next = NULL;
}

graph::graph()
{
    head = NULL;
}


void graph::print_following_list(gnode* root)
{
    cout << "Following list : \n";
    while (root->edge != NULL)
    {
        root = root->edge;
        cout<<root->vertex<<"  ";
    }
}
gnode* graph::ROOT()
{
    return head;
}

void graph::vertex_insertion(string data)
{
    if (head == NULL)
    {
        head = new gnode(data);
    }
    else
    {
        gnode* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new gnode(data);
    }
}


void graph::edge_insertion_directed(string from, string to, string type, string status)
{
    gnode* temp = head;
    while (temp->vertex != from)
    {
        temp = temp->next;
    }
    gnode* from_gnode = temp;

    temp = head;  
    while (temp->vertex != to)
    {
        temp = temp->next;
    }
    gnode* to_gnode = new gnode(temp->vertex);
    gnode* t = from_gnode->edge;   // t is the previous edge if it is connected through this vertex
    from_gnode->edge = to_gnode;
    to_gnode->edge = t;
    to_gnode->status=status ; 
    to_gnode->type = type ;
}

graph::~graph()
{
    gnode* temp;
    while (head != NULL)
    {
        temp = head->next;
        gnode* t = head->edge;
        while (t != NULL)
        {
            gnode* temp2 = t->next;
            delete t;
            t = temp2;
        }
        delete head;
        head = temp;
    }
}
gnode* graph::vertex_finder(user* input)
{
    gnode* temp = head;
    while (temp != NULL)
    {
        if (temp->vertex == input->name)
        {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void graph::display()
{
    gnode* temp = head;
    while (temp != NULL)
    {
        gnode* t = temp->edge;
        cout << temp->vertex<< "   ";
        cout << "Following the accounts  : ";
        if (t == NULL) cout << " Empty\n";
        while (t != NULL)
        {
            cout << "Name : " << t->vertex << "  status : "<< t->status<<"   type : "<<t->type<<"  .";
            t = t->edge;
        }
        cout << endl;
        temp = temp->next;
    }
}

void graph::print_follower_list(string name)
{
    gnode* temp = head;
    cout << "Follwers are  : ";
    while (temp != NULL)
    {
        gnode* t = temp->edge;
        while (t != NULL)
        {
            if (t->vertex == name)
            {
                cout << temp->vertex << "\t";
            }
            t = t->next;
        }
        cout << endl;
        temp = temp->next;
    }

}

void graph::FEED_UPLOADER(string& text, string& time, string name,user* Main_root)
{
    gnode* temp = head;
    user* used = NULL;
    cout << "Your post reached till your followers .\n";
    while (temp != NULL)
    {
        gnode* t = temp->edge;
        while (t != NULL)
        {
            if (t->vertex == name)
            {
                used = Main_root->Root_finder(Main_root, temp->vertex);
                used->Feed.push(used->Feed.head, text, time);
            }
            t = t->next;
        }
        cout << endl;
        temp = temp->next;
    }
}
