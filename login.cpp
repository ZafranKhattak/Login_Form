
// Online C++ compiler to run C++ program online
#include <iostream>
#include "string"
using namespace std;

void signUp()
{
    string username[10] ;
    string password[10] ;
    string user;
    string pass ;
    int save = 0 ;
    int choice ;

while (true)
{
    cout <<"Enter your Choice\n"
         <<"1: SigUp\n"
         <<"2: Sign In\n"
         <<"3: Start Chatting\n"
         <<"4: LogOut\n"
         <<"5: End the Program\n" ;

         cin >> choice ;

         if (choice == 1) {
    cout <<"Enter your Name: " ;
    cin >> user;

    string pass ;
    cout <<"Enter your password: " ;
    cin >> pass ;

  bool found = false;

    for (int i=0; i<save; i++) {


        if (username[i] == user) {

            cout <<"User Already Existed !Enter unregistered user\n" ;

            found = true ;
            break;
        }
        
    }

    if (!found){
        username[save] = user ;
        password[save] = save ;
        save++;
        cout<<"SignUp successfully\n" ;
    }
}

else if (choice == 2) {

    bool existUser = false ;

    string enterUser;
    cout <<"Enter your name: " ;
    cin >> enterUser ;
    string enterPass ;
    cout <<"Enter your pass: " ;
    cin >> enterPass ;

    int attempt = 0 ;

    while (attempt <3){

    for (int i=0; i<save; i++) {

        if (enterUser == username[i] && enterPass == password[i]) {

            cout <<"SignIn successully" << endl;

            existUser = true ;
            break;
        }
        else {
            cout <<"Invalid username or password" << endl;
        }
        attempt++ ;
    }
    
}
}
}
}

int main() {


    signUp() ;

    return 0;
}

