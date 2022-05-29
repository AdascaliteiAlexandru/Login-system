#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool loggedIn(string username, string password) {
	string user, pass;

	ifstream in("data" + username + ".txt");
	getline(in, user);
	getline(in, pass);

	if (username == user && pass == password)
		return true;
	else
		return false;
}

int main() {
	cout << "Press a key and enter to continue:\n\n";
	cout << "1.Register\n2.Login\n3.Exit\n";

	int choice;
	string username, password;
	cin >> choice;
	if (choice == 1) {
		cout << "your username: ";
		cin >> username;

		cout << "your passwork: ";
		cin >> password;

		if (loggedIn(username, password)) {
            cout << "This account already exists!\n";
            main();
		}

        ofstream out;
        out.open("data" + username + ".txt");
        out << username << '\n' << password << '\n' << 0;
        out.close();

		main();
	}
	else if (choice == 2) {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

		if (!loggedIn(username, password))
            cout << "Incorrect username or password\n";
        else {

            cout << "Succesfully logged in!\n\n";
            cout << "Welcome, " << username << "!\n\n";
            cout << "1.Back\n2.Exit\n\n";

            cin >> choice;

            if (choice == 1)
                main();
            else {
                cout << "Program closed!";
                return 0;
            }
        }
	}
	else {
        cout << "Program closed!";
		return 0;
	}
}
