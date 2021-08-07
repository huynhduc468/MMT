#include"Client.h"

bool LogIn(SOCKET ConnectServer) {

	char isName[1] = { '0' }, isPass[1] = { '0' };
	char username[100] = { "0" }, password[100] = { "0" };
	cin.clear();
	cout << "\nUsername: ";
	cin.getline(username, 100);
	cout << "Password: ";
	cin.getline(password, 100);

	send(ConnectServer, username, (int)strlen(username), 0);
	recv(ConnectServer, isName, 1, 0);
	if (isName[0] == '1') {
		send(ConnectServer, password, (int)strlen(password), 0);
		recv(ConnectServer, isPass, 1, 0);
		if (isPass[0] == '1') {
			cout << "\nLogged in successfully !!!\n";
			return 1;
		}
		else {
			cout << "\nPassword not correct.\n";
			return 0;
		}
	}
	else {
		cout << "\nUsername haven't exist.\n";
		return 0;
	}

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
	char ch[2] = { "0" };
	char tmp[100] = { "0" };
	do {
		char dt[20] = { "0" };
		cout << "\tEnter country name(Capitalize first letter): ";
		cin.clear();
		cin.getline(dt, 20, '\n');

		send(ConnectServer, dt, (int)strlen(dt), 0);
		char msg[1] = { '0' };
		recv(ConnectServer, msg, 1, 0);
		if (msg[0] == '1') {
			char country[100] = { "0" };
			recv(ConnectServer, country, 100, 0);
			cout << "Country: " << country << endl;

			char cases[100] = { "0" };
			recv(ConnectServer, cases, 100, 0);
			cout << "Cases: " << cases << endl;

			char todayCases[100] = { "0" };
			recv(ConnectServer, todayCases, 100, 0);
			cout << "Today cases: " << todayCases << endl;

			char deaths[100] = { "0" };
			recv(ConnectServer, deaths, 100, 0);
			cout << "Deaths: " << deaths << endl;

			char todayDeaths[100] = { "0" };
			recv(ConnectServer, todayDeaths, 100, 0);
			cout << "Today deaths: " << todayDeaths << endl;

			char recovered[100] = { "0" };
			recv(ConnectServer, recovered, 100, 0);
			cout << "Recovered: " << recovered << endl;

			char active[100] = { "0" };
			recv(ConnectServer, active, 100, 0);
			cout << "Active: " << active << endl;

			char critical[100] = { "0" };
			recv(ConnectServer, critical, 100, 0);
			cout << "Critical: " << critical << endl;

			char casesPerOneMillion[100] = { "0" };
			recv(ConnectServer, casesPerOneMillion, 100, 0);
			cout << "Cases per one million: " << casesPerOneMillion << endl;

			char DeathsPerOneMillion[100] = { "0" };
			recv(ConnectServer, DeathsPerOneMillion, 100, 0);
			cout << "Deaths per one million: " << DeathsPerOneMillion << endl;

			char totalTests[100] = { "0" };
			recv(ConnectServer, totalTests, 100, 0);
			cout << "Total test: " << totalTests << endl;

			char testPerOneMillion[100] = { "0" };
			recv(ConnectServer, testPerOneMillion, 100, 0);
			cout << "Test Per one million: " << testPerOneMillion << endl;
		}
		else cout << "\nThe country you entered does not exist\n\n";

		cout << "\n\t\t\t=============MENU=============\n";
		cout << "\t\t\t\t1. Search information\n";
		cout << "\t\t\t\t0. Exit\n";
		do {
			cout << "Enter yout opt: ";
			cin.getline(tmp, 100);
		} while (strlen(tmp) >= 2 && (tmp[0] != '0' || tmp[0] != '1'));
		ch[0] = tmp[0];
		ch[1] = '\n';
		send(ConnectServer, ch, 2, 0);
	} while (ch[0] != '0');
}