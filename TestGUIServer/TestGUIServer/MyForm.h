﻿#pragma once
#include "Server.h"

namespace TestGUIServer {

	static SOCKET ClientSocket = INVALID_SOCKET;
	static SOCKET ListenSocket = INVALID_SOCKET;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ openButton;
	private: System::Windows::Forms::Button^ exitButton;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: bool CheckSame(string A, string B) {
		return(A == B);
	}
	public: bool LognIn() {
		char acc[100] = { "0" }, pass[100] = { "0" };
		fstream fCheck("User.txt", ios_base::in);
		int isResult = recv(ClientSocket, acc, 100, 0);
		if (isResult != 0) {
			int temp = 0;

			stringstream line;
			string tmp, uNameTmp, PassTmp;

			while (getline(fCheck, tmp)) {
				line.clear();
				line.str(tmp);
				getline(line, uNameTmp, ',');
				getline(line, PassTmp, '\n');
				if (CheckSame((string)acc, uNameTmp) == 1) {
					temp = 1;
					send(ClientSocket, "1", 1, 0);
					isResult = recv(ClientSocket, pass, 100, 0);
					if (isResult != 0) {
						if (CheckSame((string)pass, PassTmp) == 1) {
							send(ClientSocket, "1", 1, 0);
							fCheck.close();
							return 1;
						}
						else {
							send(ClientSocket, "0", 1, 0);
							fCheck.close();
							return 0;
						}
					}
					else {
						send(ClientSocket, "0", 1, 0);
						fCheck.close();
						return 0;
					}
				}
			}
			if (temp == 0) {
				send(ClientSocket, "0", 1, 0);
				fCheck.close();
				return 0;
			}
		}
		else {
			send(ClientSocket, "0", 1, 0);
			fCheck.close();
			return 0;
		}

		fCheck.close();
		return 0;
	}
	private: void WriteToFile(string path, string username, string password) {
		ofstream fout;
		fout.open(path, ios::app);
		if (fout.is_open() == false)
			MessageBox::Show("File User.txt cannot open", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else {
			fout << username << "," << password;
			fout << endl;
		}
		fout.close();
	}
	private: bool checkInformation(string path, string username, string password) {
		ifstream fin;
		fin.open(path);
		stringstream s;
		string str;
		string temp;

		//flag true if username, password exist.
		bool flag = false;

		if (fin.is_open() == false) MessageBox::Show("File User.txt cannot open", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else {
			while (getline(fin, str)) {
				if (str != "") {
					s.clear();
					s.str(str);

					getline(s, temp, ',');
					if (temp == username) {
						flag = true;
						break;
					}
				}
			}
		}
		fin.close();
		return flag;
	}
	public: void registration() {
		char acc[DEFAULT_BUFLEN] = { "0" }, pass[DEFAULT_BUFLEN] = { "0" };
		int iResult = 0;
		string username = "", password = "";

		recv(ClientSocket, acc, DEFAULT_BUFLEN, 0);
		username = string(acc);
		recv(ClientSocket, pass, DEFAULT_BUFLEN, 0);
		password = string(pass);

		string path = "User.txt";

		if (checkInformation(path, username, password) == false) {
			//Send message true to client to announce that the account existed.
			iResult = send(ClientSocket, "1", 1, 0);
			if (iResult == SOCKET_ERROR)
				MessageBox::Show("Send failed with error: " + System::Convert::ToString(WSAGetLastError()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

			WriteToFile(path, username, password);
			return;
		}
		else {
			iResult = send(ClientSocket, "0", 1, 0);
			if (iResult == SOCKET_ERROR)
				MessageBox::Show("Send failed with error: " + System::Convert::ToString(WSAGetLastError()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	}
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->openButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(133, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(595, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Covid-19 epidemic information in countries";
			// 
			// openButton
			// 
			this->openButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->openButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->openButton->Location = System::Drawing::Point(128, 194);
			this->openButton->Name = L"openButton";
			this->openButton->Size = System::Drawing::Size(179, 100);
			this->openButton->TabIndex = 1;
			this->openButton->Text = L"Open Server";
			this->openButton->UseVisualStyleBackColor = false;
			this->openButton->Click += gcnew System::EventHandler(this, &MyForm::openButton_Click);
			// 
			// exitButton
			// 
			this->exitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exitButton->Location = System::Drawing::Point(580, 194);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(148, 99);
			this->exitButton->TabIndex = 2;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &MyForm::exitButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(838, 472);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->openButton);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"MyForm";
			this->Text = L"Server";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private: System::Void openButton_Click(System::Object^ sender, System::EventArgs^ e) {
		WSADATA wsaData;
		int iResult;

		DWORD threadID;
		HANDLE threadStatus;

		struct addrinfo* result = NULL;
		struct addrinfo hints;

		int iSendResult;
		char recvbuf[DEFAULT_BUFLEN];
		int recvbuflen = DEFAULT_BUFLEN;

		// Initialize Winsock
		iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (iResult != 0) {
			MessageBox::Show("WSAStartup failed with error: " + System::Convert::ToString(iResult), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			Application::Exit();
		}

		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
		hints.ai_flags = AI_PASSIVE;

		if (getaddrinfo(NULL, PORT, &hints, &result) != 0) {
			MessageBox::Show("Getaddrinfo failed: ", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			WSACleanup();
			Application::Exit();
		}

		ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
		if (ListenSocket == INVALID_SOCKET) {
			MessageBox::Show("Error at socket(): " + System::Convert::ToString(WSAGetLastError()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			WSACleanup();
			Application::Exit();
		}

		iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
		if (iResult == SOCKET_ERROR) {
			MessageBox::Show("Bind failed with error: " + System::Convert::ToString(WSAGetLastError()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			freeaddrinfo(result);
			closesocket(ListenSocket);
			WSACleanup();
			Application::Exit();
		}

		freeaddrinfo(result);

		if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
			MessageBox::Show("Listen failed with error: " + System::Convert::ToString(WSAGetLastError()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			closesocket(ListenSocket);
			WSACleanup();
			Application::Exit();
		}

		ClientSocket = accept(ListenSocket, NULL, NULL);
		if (ClientSocket == INVALID_SOCKET) {
			MessageBox::Show("Accept failed: " + System::Convert::ToString(WSAGetLastError()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			closesocket(ListenSocket);
			WSACleanup();
			Application::Exit();
		}

		closesocket(ListenSocket);

		char tmp[1] = { '0' };
		recv(ClientSocket, tmp, 1, 0);
		do {
			switch (tmp[0]) {
			case '1':
				if (MyForm::LognIn() == 1) {
					char country[20] = { "0" };
					recv(ClientSocket, country, 20, 0);
					if (country[0] == '0') break;
					else {
						string CountryTmp = string(country);
						exportCovidInfo(ClientSocket, CountryTmp);
						break;
					}
				}
				break;
			case '2':
				MyForm::registration();
				break;
			}
			recv(ClientSocket, tmp, 1, 0);
		} while ((tmp[0] != '0'));
	}
	
	private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (shutdown(ClientSocket, SD_SEND) == SOCKET_ERROR) {
			if (shutdown(ListenSocket, SD_SEND) == SOCKET_ERROR) {
				MessageBox::Show("Shutdown failed with error: " + System::Convert::ToString(WSAGetLastError()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				closesocket(ListenSocket); 
				WSACleanup();
				Application::Exit();
			}
			/*MessageBox::Show("Shutdown failed with error: " + System::Convert::ToString(WSAGetLastError()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			closesocket(ClientSocket);
			WSACleanup();*/
		}
		MessageBox::Show("Server closed !!!", "Notify", MessageBoxButtons::OK, MessageBoxIcon::Information);

		// cleanup
		closesocket(ListenSocket);
		closesocket(ClientSocket);
		WSACleanup();
		Application::Exit();
	}
	};
}
