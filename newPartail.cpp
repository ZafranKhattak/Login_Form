#include <iostream>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

const int MAX_USERS = 1000;

struct ChatApplication
{
    string username[MAX_USERS];
    string password[MAX_USERS];
    int userCount = 0;
    string currentUser = "";
};

void SignUp(ChatApplication &chat)
{

    ofstream signUpUser("signup.txt", ios::app);
    string user;
    cout << "Enter username: ";
    cin >> user;

    for (int i = 0; i < chat.userCount; i++)
    {
        if (user == chat.username[i])
        {

            cout << "User Already Available! Choose different name Please" << endl;
            return;
        }
    }

    // duplicate check if program is closed even

    ifstream readFile("signup.txt");
    string u, p;

    while (readFile >> u >> p)
    {
        if (u == user)
        {
            cout << "User Already Exists in the system! Choose another username.\n";
            readFile.close();
            return;
        }
    }
    readFile.close();

    string pass;
    cout << "Enter password: ";
    cin >> pass;

    string confrimPassword;
    cout << "Enter confirm password: ";
    cin >> confrimPassword;

    // CHECK PASSWORD MATCH

    if (confrimPassword != pass)
    {

        cout << "password does not match! retype it please" << endl;
        return;
    }
    else
    {
        cout << "SignUp successfully! now you can SignIn" << endl;

        chat.username[chat.userCount] = user;
        chat.password[chat.userCount] = pass;

        chat.userCount++;

        signUpUser << user << " " << pass << endl;
    }

    signUpUser.close();
}

void SignIn(ChatApplication &chat)
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
                chat.currentUser = youname;
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
        signInUser.close();
        return;
    }

    signInUser.close();
}

void StartChatting(ChatApplication &chat)
{

    ifstream signInUser("signup.txt");

    string yourName, p;
    cout << "Enter your Name: ";
    cin >> yourName;
    string FileName;

    bool iExisted = false;

    while (signInUser >> FileName >> p)
    {
        if (yourName == FileName)
        {
            iExisted = true;
            break;
        }
    }

    if (!iExisted)
    {
        cout << "User not SignUp\n";
        return;
    }

    string friendName;
    cout << "Enter your Friend Name: ";
    cin >> friendName;

    if (yourName == friendName)
    {

        cout << "Cannot Chat with yourself\n";
        return;
    }
    string fileFriend, p1;
    bool isExisted = false;

    while (signInUser >> fileFriend >> p1)
    {
        if (friendName == fileFriend)
        {
            isExisted = true;
            break;
        }
    }
    if (!isExisted)
    {
        cout << "User Not SignUp\n";
        return;
    }

    cout << "\n--- CHAT STARTED. TYPE exit TO END THE CHAT ---\n";

    ofstream msgStoring("msg.txt", ios::app);

    string msg1, msg2;

    cin.ignore();

    while (signInUser)
    {
        cout << "[<<" << yourName << ">>]: ";
        getline(cin, msg1);
        msgStoring << yourName << " : " << msg1 << endl;
        if (msg1 == "exit")
            break;

        cout << "[<<" << friendName << ">>]: ";
        getline(cin, msg2);

        msgStoring << friendName << " : " << msg2 << endl;
        if (msg2 == "exit")
            break;
    }

    signInUser.close();
    cout << "\n--- CHAT ENDED ---\n";
}

void whoIam(ChatApplication &chat)
{

    if (chat.currentUser == "")
    {

        cout << "You are not logged in . Please log in first" << endl;

        return;
    }
    else
    {

        cout << "You are logged in as: " << chat.currentUser << endl;
    }
}

void logOut(ChatApplication &chat)
{

    {
        bool logedOUT = true;

        if (chat.currentUser == "")
        {

            cout << "No user currently logged In . Thanks" << endl;
            logedOUT = true;
        }
        else
        {

            cout << "You are logged out as a user: " << chat.currentUser << endl;
            chat.currentUser = "";
            return;
        }
    }
}

int main()
{

    ChatApplication chat;

    cout << "==================================================\n";
    cout << "      W E L C O M E   T O  CHAT APPLICATION \n";
    cout << "==================================================\n";
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

            SignUp(chat);
        }

        else if (choice == 2)
        {

            SignIn(chat);
        }
        else if (choice == 3)
        {

            StartChatting(chat);
        }

        else if (choice == 4)
        {
            ifstream msgStoring("msg.txt");
            cout << "CHAT HISTORY NOT APPLICATBLE YET\n";
            continue;
        }

        else if (choice == 5)
        {
            whoIam(chat);
        }
        else if (choice == 6)
        {
            logOut(chat);
        }

        else if (choice == 7)
        {
            cout << "Good Bye!\nHave a nice day";
            break;
        }

        else
        {

            cout << "Please enter a valid choice!" << endl;
        }
    }
    return 0;
}