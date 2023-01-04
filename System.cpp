#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    int a, i = 0;
    string old, text, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];
    cout << "______Security System______" << endl;
    cout << "___________________________" << endl;
    cout << "|     1.Register          |" << endl;
    cout << "|     2.Login             |" << endl;
    cout << "|     3.Change Password   |" << endl;
    cout << "|_____4.End Program_______|" << endl;
    do
    {
        cout << endl
             << endl;
        cout << "Enter your choice: " << endl;
        cin >> a;
        switch (a)
        {
        case 1:
        {
            cout << "_____________________________" << endl
                 << endl;
            cout << "|---------Register----------|" << endl;
            cout << "|___________________________|" << endl
                 << endl;
            cout << "Enter UserName:-" << endl;
            cin >> name;
            cout << "Enter Password:-" << endl;
            cin >> password0;
            cout << "Enter Age:-" << endl;
            cin >> age;
            ofstream of1;
            of1.open("file.txt");
            if (of1.is_open())
            {
                of1 << name << "\n";
                of1 << password0 << "\n";
                cout << "Registraion Successful" << endl;
            }
            break;
        }
        case 2:
        {
            i = 0;

            cout << "-----------Login------------" << endl;

            ifstream of2;
            of2.open("file.txt");
            cout << "Enter UserName:-" << endl;
            cin >> user;
            cout << "Enter Password:-" << endl;
            cin >> pass;
            if (of2.is_open())
            {
                while (!of2.eof())
                {
                    while (getline(of2, text)) // read the file line by line.

                    {
                        istringstream iss(text); // to stream the string and store it using the extraction operator.
                        iss >> word;             // extraction operator is store a string.
                        creds[i] = word;
                        i++;
                    }
                    if (user == creds[0] && pass == creds[1])
                    {
                        cout << "----------Log in Successfull----------";
                        cout << endl;
                        cout << "Details: " << endl;
                        cout << "Username: " + name << endl;
                        cout << "Password: " + pass << endl;
                        cout << "Age: " + age << endl;
                    }
                    else
                    {
                        cout << endl;
                        cout << "Incorrect credentials" << endl;
                        cout << "|       1. Press 2 to Login           |" << endl;
                        cout << "|       2. Press 3 to change password |" << endl;
                        break;
                    }
                }
            }
            break;
        }
        case 3:
        {
            i = 0;
            cout << "----------------Change Password---------------" << endl;
            ifstream of0;
            of0.open("file.txt");
            cout << "Enter Old Password: ";
            cin >> old;
            if (of0.is_open())
            {
                while (of0.eof())
                {
                    while (getline(of0, text))
                    {
                        istringstream iss(text);
                        iss >> word1;
                        cp[i] = word1;
                        i++;
                    }
                    if (old == cp[1])
                    {
                        of0.close();
                        ofstream of1;
                        if (of1.is_open())
                        {
                            cout << "Enter your new password: ";
                            cin >> password1;
                            cout << "Enter your password again:";
                            cin >> password2;
                            if (password1 == password2)
                            {
                                of1 << cp[0] << "\n";
                                of1 << password1;
                                cout << "Password Changed" << endl;
                            }
                            else
                            {
                                of1 << cp[0] << "\n";
                                of1 << old;
                                cout << "Password not matched";
                            }
                        }
                    }
                    else
                    {
                        cout << "Please enter a valid password" << endl;
                        break;
                    }
                }
            }
            break;
        }
        case 4:
        {
            cout << "____________Thank You____________";
            break;
        }
        default:
            cout << "Enter a valid Choice";
        }
    } while (a != 4);
    return 0;
}