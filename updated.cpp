#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int MAX_USERS = 10;

int main() {
    string username[MAX_USERS];
    string password[MAX_USERS];
    int userCount = 0;


    cout << "=========================================\n";
    cout << "      W E L C O M E   T O   S Y S T E M  \n";
    cout << "=========================================\n";
    cout << "• If you're new here, choose '1' to Register.\n";
    cout << "• If you already have an account, choose '2' to Log in.\n";
    cout << "• You can log out anytime from the menu.\n\n";

    // while (true) {
        cout << "\n===== Main Menu =====\n";
        cout << "1) Register (Sign Up)\n";
        cout << "2) Login (Sign In)\n";
        cout << "3) Who am I?\n";
        cout << "4) Logout\n";
        cout << "5) Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin>>choice;
    // }

    return 0;
}
