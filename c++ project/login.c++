#include <iostream>
#include <fstream>
using namespace std;

class temp
{
    string userName, email, password;
    string searchname, searchpass, searchemail;
    fstream file;

public:
    void login();
    void signup();
    void forgot();
} obj;

int main()
{
    char choice;
    cout << "\n 1- login";
    cout << "\n 2- signup";
    cout << "\n 3- forgot password";
    cout << "\n 4- Exit";
    cout << "\n Enter your choice :: ";

    cin >> choice;
    cin.ignore();  // Clear the input buffer

    switch (choice)
    {
    case '1':
        obj.login();
        break;

    case '2':
        obj.signup();
        break;

    case '3':
        obj.forgot();
        break;

    case '4':
        return 0;
        break;

    default:
        cout << "Invalid selection...!";
    }
}

void temp::signup()
{
    cout << "\nEnter Your User Name: ";
    getline(cin, userName);
    cout << "Enter your email address: ";
    getline(cin, email);
    cout << "Enter the password: ";
    getline(cin, password);

    file.open("logindata.txt", ios::out | ios::app);
    file << userName << "*" << email << "*" << password << endl;
    file.close();
}

void temp::login()
{
    cout << "----------login--------- " << endl;
    cout << "Enter your user name: ";
    getline(cin, searchname);
    cout << "Enter your password: ";
    getline(cin, searchpass);

    file.open("logindata.txt", ios::in);

    while (getline(file, userName, '*') && getline(file, email, '*') && getline(file, password, '\n'))
    {
        if (userName == searchname)
        {
            if (password == searchpass)
            {
                cout << "\n Account login successful.....";
                cout << "\nUsername: " << userName << endl;
                cout << "\nEmail: " << email << endl;
                file.close();
                return;
            }
            else
            {
                cout << "Password is incorrect...!";
                file.close();
                return;
            }
        }
    }

    cout << "User not found...!";
    file.close();
}

void temp::forgot()
{
    cout << "\nEnter the Username: ";
    getline(cin, searchname);
    cout << "\nEnter your Email Address: ";
    getline(cin, searchemail);

    file.open("logindata.txt", ios::in);

    while (getline(file, userName, '*') && getline(file, email, '*') && getline(file, password, '\n'))
    {
        if (userName == searchname)
        {
            if (email == searchemail)
            {
                cout << "\n Account Found....!";
                cout << "Your password: " << password << endl;
                file.close();
                return;
            }
            else
            {
                cout << "Email does not match...!";
                file.close();
                return;
            }
        }
    }

    cout << "User not found...!";
    file.close();
}
