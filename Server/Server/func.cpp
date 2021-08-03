#include"Server.h"

bool CheckSame(string A, string B) {
	return(A == B);
}

bool CheckLogIn(SOCKET ClientSocket) {
	int uNameSize = 100, passSize = 100, isStop;
	char iStop[1];
	do {
		char username[100] = { "0" }, password[100]{ "0" };
		iStop[0] = { '0' };
		cout << "\n1\n";
		int isRecv = recv(ClientSocket, username, uNameSize, 0);
		cout << username << endl;
		if (isRecv != 0) {
			cout << "\n2";
			cout << endl << username << endl;
			int temp = 0;
			fstream fCheck("User.txt");

			stringstream line;
			string tmp, uNameTmp, PassTmp;

			while (getline(fCheck, tmp)) {
				line.clear();
				line.str(tmp);
				getline(line, uNameTmp, ',');
				getline(line, PassTmp, '\n');
				if (CheckSame((string)username, uNameTmp) == 1) {
					temp = 1;
					send(ClientSocket, "1", 1, 0);
					isRecv = recv(ClientSocket, password, passSize, 0);
					cout << password << endl;
					if (isRecv != 0) {
						if (CheckSame((string)password, PassTmp) == 1) {
							send(ClientSocket, "1", 1, 0);
							isStop = recv(ClientSocket, iStop, 1, 0);
							return 1;
						}
						else {
							send(ClientSocket, "0", 1, 0);
							isStop = recv(ClientSocket, iStop, 1, 0);
							break;
						}
					}
					else {
						send(ClientSocket, "0", 1, 0);
						isStop = recv(ClientSocket, iStop, 1, 0);
						break;
					}
				}
			}
			if (temp == 1) {
				break;
			}
			else {
				send(ClientSocket, "0", 1, 0);
				isStop = recv(ClientSocket, iStop, 1, 0);
			}
		}
		else {
			send(ClientSocket, "0", 1, 0);
			isStop = recv(ClientSocket, iStop, 1, 0);
			cout << iStop;
		}
	} while (iStop[0] == '1');

	return 0;
}