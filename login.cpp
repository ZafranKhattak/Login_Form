
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

while (true)
{

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
}
int main() {


    signUp() ;

    return 0;
}

