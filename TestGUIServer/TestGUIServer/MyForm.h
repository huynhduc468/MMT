#pragma once
#include "Server.h"

namespace TestGUIServer {

	static SOCKET ClientSocket = INVALID_SOCKET;

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

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
	public: DWORD WINAPI Execution(SOCKET ClientSocket) {

		MessageBox::Show("Connect Successfully !!!", "Notify", MessageBoxButtons::OK, MessageBoxIcon::Information);

		return 0;
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
			  this->openButton->Location = System::Drawing::Point(336, 199);
			  this->openButton->Name = L"openButton";
			  this->openButton->Size = System::Drawing::Size(179, 100);
			  this->openButton->TabIndex = 1;
			  this->openButton->Text = L"Open Server";
			  this->openButton->UseVisualStyleBackColor = false;
			  this->openButton->Click += gcnew System::EventHandler(this, &MyForm::openButton_Click);
			  // 
			  // MyForm
			  // 
			  this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			  this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			  this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			  this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			  this->ClientSize = System::Drawing::Size(838, 472);
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

		SOCKET ListenSocket = INVALID_SOCKET;
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

	//	do{
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

		SOCKET* ClientSocket = new SOCKET[5];
		for (int i = 0;i < 5;i++) {
			if (listen(ListenSocket, 5) == SOCKET_ERROR) {
				MessageBox::Show("Listen failed with error: " + System::Convert::ToString(WSAGetLastError()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				closesocket(ListenSocket);
				WSACleanup();
				Application::Exit();
			}

			ClientSocket[i] = accept(ListenSocket, NULL, NULL);
			if (ClientSocket[i] == INVALID_SOCKET) {
				MessageBox::Show("Accept failed: " + System::Convert::ToString(WSAGetLastError()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				closesocket(ListenSocket);
				WSACleanup();
				Application::Exit();
			}
		}
			closesocket(ListenSocket);
			for (int i=0;i<5;i++)
			TestGUIServer::MyForm::Execution(ClientSocket[i]);


			delete[] ClientSocket;
		//	MyForm exe;
		//	SOCKET* hConnected = new SOCKET();
		//	*hConnected = ClientSocket;
		//	threadStatus = CreateThread(NULL, 0, &MyForm::Execution, hConnected, 0, &threadID);
		//} while (1);
	}
	};
}
