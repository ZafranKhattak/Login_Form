#include <iostream>
#include <string>
using namespace std;

int main() {
    string username[10];
    string password[10];
    string currentUser ;
    int save = 0;
    int choice;

    while (true) {
        cout << "\nEnter your Choice\n"
             << "1: SignUp\n"
             << "2: SignIn\n"
             << "3: End" << endl;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter your name: ";
            cin >> username[save];
            cout << "Enter password: ";
            cin >> password[save];
            cout << "SignUp successfully!" << endl;
            save++;
        }

        else if (choice == 2) {
            string user ;
            string pass;
            int attempt = 0;
            bool loggedIn = false;

            while (attempt < 3 && !loggedIn) {
                cout << "Enter your name: ";
                cin >> user;
                cout << "Enter your password: ";
                cin >> pass;

                for (int i = 0; i < save; i++) {
                    if (username[i] == user && password[i] == pass) {
                        cout << "Login Successfully!" << endl;
                        loggedIn = true;
                        break;
                    }
                }

                if (!loggedIn) {
                    attempt++;
                    if (attempt < 3)
                        cout << "Invalid username or password\n";
                    else
                        cout << "Account blocked\n";
                }
                }
                


        }

        else if (choice == 3) {
            cout << "Good bye" << endl;
            break;
        }

        else {
            cout << "Invalid choice!" << endl;
        }

    }

    return 0;
}
