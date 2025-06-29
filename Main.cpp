#include<iostream>
#include"insta.h"
using namespace std;

//Added security to send follow request only once
//Added security that the password line will be displayed
int main()
{
	int choice;
	insta obj;
	user* root = obj.Root();
	user*& Main_root = obj.Root();
	obj.automatic();
	do
	{
		cout << "\n---------------> Social Media App Menu <----------------\n";
		cout << "1. Signup\n";    //Done
		cout << "2. Login\n";     //Done
		cout << "3. Reset Password\n";   //Done
		cout << "4. Preorder Traversal of users\n";      //Done
		cout << "5. Printing all the vertex \n";//Done
		cout << "0. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			obj.signup();
			break;
		}
		case 2:
		{
			root = obj.login();
			if (root!=NULL)
			{
				int subchoice;
				do
				{
					cout << "\n---------------> Login Menu <----------------\n";
					cout << "1. View Pending Follow Requests\n";  //Done
					cout << "2. Accept/Cancel Follow Requests\n";  //Done
					cout << "3. View Timeline (Posts from Followers)\n";//Done
					cout << "4. View Notifications\n";       //Done
					cout << "5. Send Message\n";           //Done
					cout << "6. Search Users\n";           //Done
					cout << "7. View Followers List\n";    //Done
					cout << "8. View Your Posts (Newsfeed)\n";  //Done
					cout << "9. Upload Your Posts\n";      //Done
					cout << "10. Display the message inbox .\n";       //Done
					cout << "11. View the Following list .\n";   //Done
					cout << "12.Send Follow request .\n";  //Done
					cout << "13.Print the Graph .\n";         //Done
					cout << "0. Logout\n";            //Done
					cout << "Enter your choice: ";
					cin >> subchoice;

					switch (subchoice)
					{
					case 1:
						cout << "\nView Pending Follow Requests selected.\n";
						root->pending_Requests_printer(root);
						break;
					case 2:
						cout << "\nAccept/Cancel Follow Requests selected.\n";
						obj.Decision_Requests(root);
						break;
					case 3:
						cout << "\nView Timeline(Post From Followers) selected.\n";
						obj.feed(root->name);
						break;
					case 4: //Notification of a login ,request recieving,message recieving,request accepted will come 
						cout << "\nView Notifications selected.\n";
						cout << "Your notificationa are : \n";
						root->notifications.print(root->notifications.head);
						break;
					case 5:
						cout << "\nSend Message selected.\n";
						obj.message_sendd(root->name);
						break;
					case 6:
						cout << "\nSearch Users selected.\n";
						obj.search();
						break;
					case 7:
						cout << "\nView Followers List selected.\n";
						obj.print_Follower_list(root->name);
						break;
					case 8:
						cout << "\nView Your Posts selected.\n";
						root->mine_post_check();
						break;
					case 9:
					{
						cout << "\nPost Uploader selected .\n";
						//Main root is requireed to post it in their followes list
						string text;
						cout << "Enter the text that you want to upload : \n";
						cin >> text;
						string ttime;
						time_t now = time(0); //Getting current time
						ttime = ctime(&now); // Converting time_t to string using ctime
						root->post_uploader(root, Main_root,text,ttime);
						obj.GRAPH.FEED_UPLOADER(text,ttime,root->name,Main_root);
					}
						break;
					case 10:
					{
						cout << "\nMessage inbox selected .\n";
						root->message_inbox(root,obj.current);
						break;
					}
					case 11:
					{
						cout << "\nFollowing List selected .\n";
						obj.print_Following_list(root);
						break;
					}
					case 12:
					{
						cout << "Enter the name of person to send request :\n";
						string temp;
						cin >> temp;
						obj.send_request(Main_root,temp,root->name);
						//Functionality of sending the follow request
						break;
					}
					case 13:
					{
						cout << "Print the graph selected .\n";
						obj.print_Graph();
						break;
					}
					case 0:
						cout << "Logging out...\n";
						root=NULL;
						break;
					default:
						cout << "Invalid choice! Please try again.\n";
						break;
					}
				} while (root);
			}
			break;
		}
		case 3:
		{
			obj.resset();
			break;
		}
		case 4:
		{
			obj.pre_order(Main_root);
			break;
		}
		case 5:
		{
			obj.vertex_print();
			break;
		}
		case 0:
		{
			cout << "Exiting the application.goodbye!\n";
			break;
		}
		default:
		{
			cout << "Invalid choice! ,Enter the valid choice .\n";
		}
		}


	} while (choice != 0);

	return 0;
}
