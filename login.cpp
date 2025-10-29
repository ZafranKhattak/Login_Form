// using online compiler programiz
#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string username[10] ;
    string password[10] ;
    int save = 0 ;
    int choice ;
    
    while (true) {
        
        cout <<"Enter your Choice\n"
            << "1: SignUp\n"
            <<"2: SignIn\n"
            <<"3: End" << endl;
        cin >> choice ;
        
        if (choice == 1) {
            cout <<"Enter your name: " ;
            cin >>username[save] ;
            cout <<"Enter password: " ;
            cin >> password[save] ;
            cout <<"SignUp successfully"<<endl ;
            save++;
        }
        else if (choice == 2) {
            string user ;
            string pass;
            cout <<"Enter your name: " ;
            cin >> user;
            cout <<"Enter your password: " ;
            cin >>pass;
            bool logedIn = false;
            
            for (int i=0 ; i<save; i++) {
                if (username[i]==user && password[i]==pass) {
                    cout <<"Login Successfully" << endl;
                    break;
                }
            cout <<"Invalid" <<endl;
            break ;
            }
        }
        else if (choice == 3) {
            cout <<"Visit Again" ;
            break ;
        }
    }
    return 0;
}