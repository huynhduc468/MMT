// Server function
#include"pch.h"
#include"Server.h"
#include<Windows.h>
#include<WinSock2.h>
#include <Ws2tcpip.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include</single_include/nlohmann/json.hpp>
using namespace std;


// This function write new account to file.
void WriteToFile(string path, string username, string password)
{
	ofstream fout;
	fout.open(path, ios::end);
	if (fout.is_open() == false)
	{
		cout << "File User.txt cannot open" << endl;
	}
	else
	{
		fout << username << "," << password;
		fout << endl;
	}
	fout.close();
}


// This function send and receive account from client
void sendRecvacc(SOCKET ClientSocket, string& username, string& password)
{
	char msg[DEFAULT_BUFLEN];
	int iResult;

	// Send msg and receive username from client
	strcpy_s(msg, "Username: ");
	iResult = send(ClientSocket, msg, strlen(msg), 0);
	if (iResult == SOCKET_ERROR)
		cout << "send failed with error: " << WSAGetLastError() << endl;

	iResult = recv(ClientSocket, msg, DEFAULT_BUFLEN, 0);
	if (iResult < 0) cout << "receive message fail (username), error: " << WSAGetLastError();
	msg[iResult] = '\0';
	username = string(msg);


	// Send msg and receive password from client
	strcpy_s(msg, "Password: ");
	iResult = send(ClientSocket, msg, strlen(msg), 0);
	if (iResult == SOCKET_ERROR)
		cout << "send failed with error: " << WSAGetLastError() << endl;

	iResult = recv(ClientSocket, msg, DEFAULT_BUFLEN, 0);
	if (iResult < 0) cout << "receive message fail (password), error: " << WSAGetLastError();
	msg[iResult] = '\0';
	password = string(msg);

}
// Check if username & password registered existed (return true if existed)
bool checkInformation(string path, string username, string password)
{
	ifstream fin;
	fin.open(path);
	stringstream s;
	string str;
	string temp;

	//flag true if username, password exist.
	bool flag = false;
	if (fin.is_open() == false)
	{
		cout << "File User.txt cannot open" << endl;
	}
	else
	{
		while (!fin.eof())
		{
			getline(fin, str);
			if (str != "")
			{
				s = stringstream(str);
				getline(s, temp, ',');
				if (temp == username)
				{
					flag = true; break;
				}
				getline(s, temp, ',');
				if (temp == password) {
					flag = true;
					break;
				}
			}

		}
	}
	fin.close();
	return flag;
}


// Registration function client.
bool registration(SOCKET ClientSocket)
{
	//Send message to client
	char msg[DEFAULT_BUFLEN];
	int iResult = 0;
	string username = "", password = "";

	strcpy_s(msg, "Registration");
	iResult = send(ClientSocket, msg, strlen(msg), 0);
	if (iResult == SOCKET_ERROR)
		cout << "send failed with error: " << WSAGetLastError() << endl;

	sendRecvacc(ClientSocket, username, password);
	
	string path = "User.txt";

	if (checkInformation(path, username, password) == true)
	{//Send message true to client to announce that the account existed.
		strcpy_s(msg, "Your registration is successful!");
		iResult = send(ClientSocket, msg, (int)strlen(msg), 0);
		if (iResult == SOCKET_ERROR)
		cout << "send failed with error: " << WSAGetLastError() << endl;

		WriteToFile(path, username, password);
		return true;
	}
	else
	{
		strcpy_s(msg, "Someone used this account. Registration failed!");
		iResult = send(ClientSocket, msg, (int)strlen(msg), 0);
		if (iResult == SOCKET_ERROR)
			cout << "send failed with error: " << WSAGetLastError() << endl;
		return false;
	}


}



// This function find the covid information of a particular country
void exportCovidInfo(string file_name)
{
	nlohmann::json value;
	string temp="";

	ifstream file("file_out.json", ios::binary);
	if (file.is_open() == false) {
		cout << "Cannot open file";
	}
	else
	{
		getline(file, temp);
	}
	


	stringstream ss(temp);
	string jsonObject;
	getline(ss, jsonObject, '[');
	getline(ss, jsonObject, '}');
	jsonObject += '}';
	stringstream(jsonObject) >> value;



	cout << endl;
	string country="";
	cout << "Input the country: ";
	getline(cin, country);



	while (jsonObject != "") {
		getline(ss, jsonObject, ',');
		if (jsonObject == "]") break;
		getline(ss, jsonObject, '}');
		jsonObject += '}';
		stringstream(jsonObject) >> value;
		if (country == value["country"]) 
		{ cout << "Country: " << value["country"] << endl;
			cout << "Cases: " << value["cases"] << endl;
			cout << "Today cases: " << value["todayCases"] << endl;
			cout << "Deaths: " << value["deaths"] << endl;
			cout << "Today deaths: " << value["todayDeaths"] << endl;
			cout << "Recovered: " << value["recovered"] << endl;
			cout << "Active: " << value["active"] << endl;
			cout << "Critical: " << value["critical"] << endl;
			cout << "Cases per one million: " << value["casesPerOneMillion"] << endl;
			cout << "Deaths per one million: " << value["deathsPerOneMillion"] << endl;
			cout << "Total test: " << value["totalTests"] << endl;
			cout << "Test Per one million: " << value["testsPerOneMillion"] << endl;
		}
	}


	system("pause");
}