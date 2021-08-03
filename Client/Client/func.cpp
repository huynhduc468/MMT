#include"Client.h"

bool LogIn(SOCKET ConnectServer) {
	int isUsername, isPassword, recvSizeName = Size, recvSizePass = Size;
	char choosen[1];
	do {
		choosen[0] = { '0' };
		char isName[Size] = { "0" }, isPass[Size] = { "0" };
		char username[100] = { "0" }, password[100] = { "0" };
		cout << "\nUsername: ";
		cin.getline(username, 100);
		cout << "\nPassword: ";
		cin.getline(password, 100);

		send(ConnectServer, username, (int)strlen(username), 0);
		isUsername = recv(ConnectServer, isName, recvSizeName, 0);
		cout << endl << isName;
		if ((string)isName == "1") {
			send(ConnectServer, password, (int)strlen(password), 0);
			isPassword = recv(ConnectServer, isPass, recvSizePass, 0);
			if ((string)isPass == "1") {
				cout << "\nLogged in successfully !!!";
				send(ConnectServer, "0", 1, 0);
				return 1;
			}
			else {
				cout << "\nPassword not correct.";
				cout << "\nEnter 1 if you want continue or 0 if you want stop\n";
				cin.getline(choosen, 1);
				int byte = send(ConnectServer, choosen, 1, 0);
				cout << endl << byte;
			}
		}
		else {

			cout << "\nUsername haven't exist.";
			cout << "\nEnter 1 if you want continue or 0 if you want stop\n";
			cin.getline(choosen, 1);
			int byte = send(ConnectServer, choosen, 1, 0);
			cout << endl << byte;
		}
	} while (choosen[0] == '1');

	return 0;
}