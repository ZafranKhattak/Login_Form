#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

const int MAX_USERS = 1000;

struct ChatApplication
{
    string username[MAX_USERS];
    string password[MAX_USERS];
    string groupChat[MAX_USERS];
    int userCount = 0;
    string currentUser = "";
};

// SignUp section
void SignUp(ChatApplication &chat)
{

    ofstream signUpUser("signup.txt", ios::app);
    string user;
    cout << "Enter username: ";
    cin >> user;

    // duplicate check if program is closed even

    ifstream readFile("signup.txt");
    string u, p;

    while (readFile >> u >> p)
    {
        if (u == user)
        {
            cout << "User Already Exists in the system! Choose another username.\n";
            readFile.close();
            cout << "Enter username: ";
            cin >> user;
        }
    }
    readFile.close();

    cout << "Password Must contain at least 8 character\n";

    string pass;
    cout << "Enter password: ";
    cin >> pass;

    while (pass.length() < 8)
    {

        cout << "Password should Atleast 8 character\n";
        cout << "Enter password again: ";
        cin >> pass;
    }

    string confrimPassword;
    cout << "Enter confirm password: ";
    cin >> confrimPassword;

    // CHECK PASSWORD MATCH
    while (confrimPassword != pass)
    {

        cout << "password does not match! retype it please: ";
        cin >> confrimPassword;
    }

    {
        cout << "SignUp successfully! now you can SignIn" << endl;

        chat.username[chat.userCount] = user;
        chat.password[chat.userCount] = pass;

        chat.userCount++;

        signUpUser << user << " " << pass << endl;
    }

    signUpUser.close();
}

// SignUp Function is Below

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

// Chatting section for two person

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
        cout << yourName << " IS currently offline" << endl;
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
        cout << friendName << " IS currently offline" << endl;
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

// Group Chatting Section

void GroupChatting(ChatApplication &chat)
{
    ifstream signInUser("signup.txt");

    string p1;  // person name
    string ps1; // person password

    cout << "Enter your Person 1: ";
    cin >> p1;

    bool P1Existed = false;
    string pr1;

    while (signInUser >> pr1 >> ps1)
    {
        if (p1 == pr1)
        {
            P1Existed = true;
            break;
        }
    }

    if (!P1Existed)
    {

        cout << "This is currently offline\n";
    }

    string p2, ps2;

    cout << "Enter your second Friend: ";
    cin >> p2;

    if (p2 == p1)
    {
        cout << "You cannot chat with yourself! Thank you\n";
        return;
    }

    string pr2; // person 2
    bool P2Existed = false;
    while (signInUser >> pr2 >> ps2)
    {
        if (p2 == pr2)
        {
            P2Existed = true;
            break;
        }
    }

    if (!P2Existed)
    {
        cout << "This is currently offline\n";
    }

    // 
    
    string person3;  // person name
    string pass3; // person password

    cout << "Enter your Person 1: ";
    cin >> person3;

    bool P3Existed = false;
    string pr3;

    while (signInUser >> pr3 >> pass3)
    {
        if (person3 == pr3)
        {
            P3Existed = true;
            break;
        }
    }

    if (!P3Existed)
    {

        cout << "This is currently offline\n";
        return;
    }

    string p4;  // person 4 name
    string ps4; // person password

    cout << "Enter your Person 4: ";
    cin >> p4;

    if (p4 == person3 || p4 == p2 || p4 == p1)
    {
        cout << "You cannot chatt with your self bro! Thank you\n";
        return;
    }

    bool P4Existed = false;
    string pr4;

    while (signInUser >> pr4 >> ps4)
    {
        if (p4 == pr4)
        {
            P1Existed = true;
            break;
        }
    }

    if (!P4Existed)
    {

        cout << "This is currently offline\n";
        return;
    }

    cout << "\n--- CHAT STARTED. TYPE exit TO END THE CHAT ---\n";

    ofstream groupMsgStoring("gmsg.txt", ios::app);

    string msg1, msg2, msg3, msg4;

    cin.ignore();

    while (signInUser)
    {
        cout << "[<<" << p1 << ">>]: ";
        getline(cin, msg1);
        groupMsgStoring << p1 << " : " << msg1 << endl;
        if (msg1 == "exit")
            break;

        cout << "[<<" << person3 << ">>]: ";
        getline(cin, msg3);
        groupMsgStoring << person3 << " : " << msg2 << endl;
        if (msg3 == "exit")
            break;

        cout << "[<<" << p2 << ">>]: ";
        getline(cin, msg2);
        groupMsgStoring << p2 << " : " << msg1 << endl;
        if (msg2 == "exit")
            break;

        cout << "[<<" << p4 << ">>]: ";
        getline(cin, msg4);
        groupMsgStoring << p4 << " : " << msg2 << endl;
        if (msg4 == "exit")
            break;
    }

    signInUser.close();
    cout << "\n--- CHAT ENDED ---\n";
}

// Who am I SECTION

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

// LGOUT OUT SECTION CURRENT USER

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

// CHAT HISTORY OF TWO PERSON;

void chatHistory(ChatApplication &chat)
{
    ifstream msgStoring("msg.txt");

    string msg;
    bool found = false;

    while (getline(msgStoring, msg))
    {

        cout << msg << endl;
        found = true;
    }

    if (!found)
    {
        cout << "No chat history found!" << endl;
        return;
    }
}

// MAIN SECTION 

int main()
{

    ChatApplication chat;

    cout << setw(95) << "==================================================\n";
    cout << setw(95) << "      W E L C O M E   T O   C H A T   A P P       \n";
    cout << setw(95) << "==================================================\n\n";
    cout << setw(87) << " If you're new here, choose '1' to Register.\n";
    cout << setw(97) << " If you already have an account, choose '2' to Log in.\n";
    cout << setw(83) << " You can log out anytime from the menu.\n\n";

    while (true)
    {
        cout << setw(80) << "====== Main Menu ======\n";
        cout << setw(69) << "1) Sign Up\n\n";
        cout << setw(67) << "2) Login\n\n";
        cout << setw(76) << "3) Start Chatting\n\n";
        cout << setw(76) << "4) Group Chatting\n\n";
        cout << setw(74) << "5) Chat History\n\n";
        cout << setw(71) << "6) Who am I?\n\n";
        cout << setw(68) << "7) Logout\n\n";
        cout << setw(66) << "8) Exit\n\n";
        cout << setw(84) << "Enter choice (1 <---> 8): ";

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
            GroupChatting(chat);
        }

        else if (choice == 5)
        {
            chatHistory(chat);
        }

        else if (choice == 6)
        {
            whoIam(chat);
        }
        else if (choice == 7)
        {
            logOut(chat);
        }

        else if (choice == 8)
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