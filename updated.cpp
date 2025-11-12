#include <iostream>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

const int MAX_USERS = 10;

int main()
{
    string username[MAX_USERS];
    string password[MAX_USERS];
    int userCount = 0;

    string currentUser;

    string currentUserSignUp;

    cout << "=========================================\n";
    cout << "      W E L C O M E   T O  CHAT APPLICATION \n";
    cout << "=========================================\n";
    cout << " If you're new here, choose '1' to Register.\n";
    cout << " If you already have an account, choose '2' to Log in.\n";
    cout << " You can log out anytime from the menu.\n\n";

    while (true)
    {
        cout << "\n===== Main Menu =====\n";
        cout << "1) Sign Up\n";
        cout << "2) Login \n";
        cout << "3) Start Chatting\n";
        cout << "4) Who am I?\n";
        cout << "5) Logout\n";
        cout << "6) Exit\n";
        cout << "Enter choice (1 <--->6 ): ";

        int choice;
        cin >> choice;

        if (choice == 1)
        {

            ofstream signUpUser("signup.txt", ios::app);
            bool alreadyAvailable = false;
            string user;
            cout << "Enter username: ";
            cin >> user;

            for (int i = 0; i < userCount; i++)
            {
                if (user == username[i])
                {

                    cout << "User Already Available! Choose different name Please" << endl;
                    alreadyAvailable = true;
                }
            }

            if (!alreadyAvailable)
            {
                string pass;
                cout << "Enter password: ";
                cin >> pass;

                string confrimPassword;
                cout << "Enter confirm password: ";
                cin >> confrimPassword;

                if (confrimPassword != pass)
                {

                    cout << "password does not match! retype it please" << endl;
                }
                else
                {
                    cout << "SignUp successfully! now you can SignIn" << endl;

                    username[userCount] = user;
                    password[userCount] = pass;

                    currentUserSignUp = user;
                    userCount++;

                    signUpUser << user << " " << pass << endl;
                }
            }
        }

        else if (choice == 2)
        {
            ifstream signInUser("signup.txt");

            string youname;
            cout << "Enter your name: ";
            cin >> youname;

            string yourpass;
            cout << "Enter your pass: ";
            cin >> yourpass;

            bool foundName = false;
            string User;
            string Pass;

            while (signInUser >> User >> Pass)
            {
                if (youname == User)
                {
                    foundName = true;
                    if (yourpass == Pass)
                    {
                        cout << "SignIn successfully! Welcome Dear " << youname << endl;
                        currentUser = youname;
                    }
                    else
                    {
                        cout << "Invalid password! Try again" << endl;
                    }
                    break;
                }
            }

            if (!foundName)
            {
                cout << "User not found. SignUp please" << endl;
            }
        }
        else if (choice == 3)
        {

            if (currentUser.empty())
            {
                cout << "You are not logged in. Please log in first." << endl;
                continue;
            }

            string yourName;
            cout << "Enter your name: ";
            cin >> yourName;

            bool youExists = false;
            for (int i = 0; i < userCount; i++)
            {
                if (yourName == username[i])
                {
                    youExists = true;
                    break;
                }
            }
            if (!youExists)
            {
                cout << "This user is not signed up." << endl;
                continue;
            }

            string friendName;
            cout << "Enter your Friend Name: ";
            cin >> friendName;

            bool friendExists = false;
            for (int i = 0; i < userCount; i++)
            {
                if (friendName == username[i])
                {
                    friendExists = true;
                    break;
                }
            }
            if (!friendExists)
            {
                cout << "This friend is not signed up." << endl;
                continue;
            }

            if (yourName == friendName)
            {
                cout << "You cannot chat with yourself!" << endl;
                continue;
            }

            cout << "\n--- CHAT STARTED. TYPE exit TO END THE CHAT ---\n";

            string subChoice;
            cin.ignore(); 

            while (true)
            {
                cout << "[<<" << yourName << ">>]: ";
                getline(cin, subChoice);

                if (subChoice == "exit")
                    break;

                cout << "[<<" << friendName << ">>]: ";
                string reply;
                getline(cin, subChoice);

                if (subChoice == "exit")
                    break;
            }

            cout << "\n--- CHAT ENDED ---\n";
        }

        else if (choice == 4)
        {

            bool logedIn = true;

            // string youname ;
            // cout <<"Enter your name: " ;
            // cin >> youname ;

            if (currentUser == "")
            {

                cout << "You are not logged in . Please logged in first" << endl;

                logedIn = false;
            }
            else
            {

                cout << "You are logged in as: " << currentUser << endl;
            }
        }
        else if (choice == 5)
        {
            bool logedOUT = true;

            if (currentUser == "")
            {

                cout << "No user currently logged In . Thanks" << endl;
                logedOUT = true;
            }
            else
            {

                cout << "You are logged out as a user: " << currentUser << endl;
            }
        }

        else if (choice == 6)
        {

            cout << "Good Bye! Come Again" << endl;
            break;
        }

        else
        {

            cout << "Please enter a valid choice!" << endl;
        }
    }

    return 0;
}
