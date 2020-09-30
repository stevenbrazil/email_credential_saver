#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Email
{
public:
    void Get_Access()
    {
        cout << "WELCOME\n\nEnter Username and Password for access\n\n";
        cout << "Enter Username\n";
        cin >> Access_UPG_user;
        cout << "Enter Password\n";
        cin >> Access_UPG_pass;

        if (Access_UPG_user == "bluesclues" && Access_UPG_pass == "1234ScoobyDoo")
        {
            Email start_program;
            cout << "Access Granted\n";
            start_program.Begin_App();
        }
        else
        {
            cout << "You are not authorized...\n";
        }
    }

    void Begin_App()
    {
        Email creds;
        char adduserpass;
        char checkuserpass;
        cout << "Add email credentials?\n[Y] or [N]\n";
        cin >> adduserpass;
        if (adduserpass == 'y' || adduserpass == 'Y')
        {
            creds.AddEmailCreds();
        }
        else if (adduserpass == 'n' || adduserpass == 'N')
        {
            cout << "Credentials not added\n";
        }

        cout << "Check Credentials?\n[Y] or [N]\n";
        cin >> checkuserpass;
        if (checkuserpass == 'y' || checkuserpass == 'Y')
        {

            creds.GetEmailCreds(checkuserpass);
        }
        else if (checkuserpass == 'n' || checkuserpass == 'N')
        {
            cout << "Did not retrieve credentials\n";
        }
    }

    void GetEmailCreds(char checkuserpass)
    {

        ifstream read_Email_info;

        if (checkuserpass == 'y' || checkuserpass == 'Y')
        {

            read_Email_info.open("gmailinfo.txt");
            read_Email_info >> user;

            cout << "Current Username is : " << user << endl;

            read_Email_info >> password;

            cout << "Current Password is : " << password << endl;
        }
        else if (checkuserpass == 'n' || checkuserpass == 'N')
        {
            cout << "File not accessed\n";
        }

        else
        {
            cout << "Invalid Input, please enter Y or N\n";
        }

        read_Email_info.close();
    }

    void AddEmailCreds()
    {

        ofstream MyGmail;
        MyGmail.open("gmailinfo.txt");

        cout << "Enter username\n";
        cin >> user;
        MyGmail << user << endl;

        cout << "Enter Password\n";
        cin >> password;
        cin.ignore();
        MyGmail << password << endl;

        MyGmail.close();
    }

private:
    string user;
    string password;
    string Access_UPG_user = "bluesclues";
    string Access_UPG_pass = "1234ScoobyDoo";
};

int main()
{
    Email creds;
    creds.Get_Access();
    return 0;
}
