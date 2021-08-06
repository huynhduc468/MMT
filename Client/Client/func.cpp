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

void registration(SOCKET ConnectSocket)
{
	char msg[DEFAULT_BUFLEN];
	int msgLen;
	int iResult = 0;

	// Receive message from server: 1."Registration" 2."Username" 3."Password"
	iResult = recv(ConnectSocket, msg, DEFAULT_BUFLEN, 0);
	if (iResult < 0) cout << "fail to receive, error: " << WSAGetLastError() << endl;
	msg[iResult] = '\0';
	cout << msg << endl;

	// Receive and send again username & password
	for (int i = 0; i < 2; i++)
	{
		iResult = recv(ConnectSocket, msg, DEFAULT_BUFLEN, 0);
		if (iResult < 0) cout << "fail to receive, error: " << WSAGetLastError() << endl;
		msg[iResult] = '\0';
		cout << msg;

		cin.getline(msg, 100);
		iResult = send(ConnectSocket, msg, strlen(msg), 0);
		if (iResult == SOCKET_ERROR) cout << "fail to send msg" << endl;
	}


	// Receive announcement from server if account exist, msg="true" means yes.
	iResult = recv(ConnectSocket, msg, DEFAULT_BUFLEN, 0);
	if (iResult < 0) cout << "fail to receive, error: " << WSAGetLastError() << endl;
	msg[iResult] = '\0';
	cout << "accout exist? " << msg;
	cout << endl;

	while (strcmp(msg, "true") == 0)
	{
		// Receive message from server: 1."Registration" 2."Username" 3."Password"
		iResult = recv(ConnectSocket, msg, DEFAULT_BUFLEN, 0);
		if (iResult < 0) cout << "fail to receive, error: " << WSAGetLastError() << endl;
		msg[iResult] = '\0';
		cout << msg;
		cout << endl;
		// Receive and send again username & password
		for (int i = 0; i < 2; i++)
		{
			iResult = recv(ConnectSocket, msg, DEFAULT_BUFLEN, 0);
			if (iResult < 0) cout << "fail to receive , error: " << WSAGetLastError() << endl;
			msg[iResult] = '\0';
			cout << msg;

			cin.ignore(1000, '\0');
			cin.getline(msg, 100);
			iResult = send(ConnectSocket, msg, strlen(msg), 0);
			if (iResult == SOCKET_ERROR) cout << "fail to send msg , error: " << WSAGetLastError() << endl;
		}

		// Receive the result of register.
		iResult = recv(ConnectSocket, msg, DEFAULT_BUFLEN, 0);
		if (iResult < 0) cout << "fail to receive, error: " << WSAGetLastError() << endl;
		msg[iResult] = '\0';
	}

	// Receive annoucement successfull registration from server

	iResult = recv(ConnectSocket, msg, DEFAULT_BUFLEN, 0);
	if (iResult < 0) cout << "fail to receive, error: " << WSAGetLastError() << endl;
	msg[iResult] = '\0';
	cout << msg << endl;
	return;
}

void DoSomeThing(SOCKET ConnectServer) {
	char dt[20] = { "0" };
	cin.getline(dt, 20);

	send(ConnectServer, dt, (int)strlen(dt), 0);
	char msg[1] = { '0' };
	recv(ConnectServer, msg, 1, 0);
	if (msg[0] == '1') {
		char country[100] = { "0" };
		recv(ConnectServer, country, 100, 0);
		cout << country << endl;

		char cases[100] = { "0" };
		recv(ConnectServer, cases, 100, 0);
		cout << cases << endl;

		char todayCases[100] = { "0" };
		recv(ConnectServer, todayCases, 100, 0);
		cout << todayCases << endl;

		char deaths[100] = { "0" };
		recv(ConnectServer, deaths, 100, 0);
		cout << deaths << endl;

		char todayDeaths[100] = { "0" };
		recv(ConnectServer, todayDeaths, 100, 0);
		cout << todayDeaths << endl;

		char recovered[100] = { "0" };
		recv(ConnectServer, recovered, 100, 0);
		cout << recovered << endl;

		char active[100] = { "0" };
		recv(ConnectServer, active, 100, 0);
		cout << active << endl;

		char critical[100] = { "0" };
		recv(ConnectServer, critical, 100, 0);
		cout << critical << endl;

		char casesPerOneMillion[100] = { "0" };
		recv(ConnectServer, casesPerOneMillion, 100, 0);
		cout << casesPerOneMillion << endl;

		char DeathsPerOneMillion[100] = { "0" };
		recv(ConnectServer, DeathsPerOneMillion, 100, 0);
		cout << DeathsPerOneMillion << endl;

		char totalTests[100] = { "0" };
		recv(ConnectServer, totalTests, 100, 0);
		cout << totalTests << endl;

		char testPerOneMillion[100] = { "0" };
		recv(ConnectServer, testPerOneMillion, 100, 0);
		cout << testPerOneMillion << endl;

		char msg[1] = { '0' };
		recv(ConnectServer, msg, 1, 0);
		if (msg[0] == '1') {
			cout << "\nSuccessfully";
		}
		else cout << "\nFailed\n";
	}
	else {
		cout << "\nThe country you entered does not exist\n";
	}
}	  