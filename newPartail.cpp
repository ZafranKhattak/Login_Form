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
        cout << "4) Chat History\n";
        cout << "5) Who am I?\n";
        cout << "6) Logout\n";
        cout << "7) Exit\n";
        cout << "Enter choice (1 <---> 7 ): ";

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

            if (currentUser == "")
            {
                cout << "You are not logged in. Please log in first." << endl;
                continue;
            }

                ifstream signInUser("signup.txt") ;
                ofstream msgStoring("msg.txt" , ios::app) ;

                string yourName;
                cout << "Enter your name: ";
                cin >> yourName;

                string User1 , Pass1 ;
                bool youExist = false;
                while(signInUser >> User1 >> Pass1){
                for (int i = 0; i < userCount; i++)
                {
                    if (yourName == User1)
                    {
                        youExist = true;
                        break;
                    }
                }
                if (!youExist)
                {
                    cout << "This user is not signed up." << endl;
                    continue;
                }
            }
                signInUser.clear();
                signInUser.seekg(0) ;
                string friendName;
                cout << "Enter your Friend Name: ";
                cin >> friendName;
                string User2 , Pass;
                bool friendExists = false;
                while(signInUser >> User2 >> Pass1) {

                for (int i = 0; i < userCount; i++)
                {
                    if (friendName == User2)
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
            }
            
            cout << "\n--- CHAT STARTED. TYPE exit TO END THE CHAT ---\n";

            string msg1, msg2;

            cin.ignore();

            while (true)
            {
                cout << "[<<" << yourName << ">>]: ";
                getline(cin, msg1);
                msgStoring << yourName << " : " << msg1 << endl;
                if (msg1 == "exit")
                    break;

                cout << "[<<" << friendName << ">>]: ";
                getline(cin, msg2);

                msgStoring << (friendName) << " : " << msg2 << endl;
                if (msg2 == "exit")

                    break;
            }
            signInUser.close();
            cout << "\n--- CHAT ENDED ---\n";
        }
        else if (choice == 4) {
            cout <<"CHAT HISTORY NOT APPLICATBLE YET\n";
            continue;
        }

        else if (choice == 5)
        {

            bool logedIn = true;

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
        else if (choice == 6)
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

        else if (choice == 7)
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
