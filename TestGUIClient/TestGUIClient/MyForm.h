#pragma once
#include"Client.h"

namespace TestGUIClient {

	static SOCKET ConnectSocket;

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
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ IPBox;
	private: System::Windows::Forms::Button^ connectButton;
	private: System::Windows::Forms::Button^ exitButton;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->IPBox = (gcnew System::Windows::Forms::TextBox());
			this->connectButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(143, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(595, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Covid-19 epidemic information in countries";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(48, 171);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(323, 29);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Enter the Server\'s IP address";
			// 
			// IPBox
			// 
			this->IPBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->IPBox->Location = System::Drawing::Point(431, 168);
			this->IPBox->Name = L"IPBox";
			this->IPBox->Size = System::Drawing::Size(340, 34);
			this->IPBox->TabIndex = 2;
			// 
			// connectButton
			// 
			this->connectButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->connectButton->Location = System::Drawing::Point(149, 285);
			this->connectButton->Name = L"connectButton";
			this->connectButton->Size = System::Drawing::Size(151, 70);
			this->connectButton->TabIndex = 3;
			this->connectButton->Text = L"Connect";
			this->connectButton->UseVisualStyleBackColor = true;
			this->connectButton->Click += gcnew System::EventHandler(this, &MyForm::connectButton_Click);
			// 
			// exitButton
			// 
			this->exitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exitButton->Location = System::Drawing::Point(587, 285);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(151, 70);
			this->exitButton->TabIndex = 4;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &MyForm::exitButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(838, 472);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->connectButton);
			this->Controls->Add(this->IPBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Client";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void connectButton_Click(System::Object^ sender, System::EventArgs^ e) {
		//Convert from System::String^ to std::string
		string IP = msclr::interop::marshal_as<std::string>(System::Convert::ToString(IPBox->Text));
		char* IPServer = (char*)IP.c_str();
		WSADATA wsaData;
		struct addrinfo* result = NULL, * ptr = NULL, hints;
		int iResult;
		int recvbuflen = DEFAULT_BUFLEN;

		// Initialize Winsock
		iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (iResult != 0) {
			MessageBox::Show("WSAStartup failed with error: " + System::Convert::ToString(iResult), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			Application::Exit();
		}

		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;

		iResult = getaddrinfo((PCSTR)IPServer, PORT, &hints, &result);
		if (iResult != 0) {
			MessageBox::Show("Getaddrinfo failed: " + System::Convert::ToString(iResult), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			WSACleanup();
			Application::Exit();
		}

		// Attempt to connect to an address until one succeeds
		for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

			// Create a SOCKET for connecting to server
			ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
				ptr->ai_protocol);
			if (ConnectSocket == INVALID_SOCKET) {
				MessageBox::Show("Socket failed with error: " + System::Convert::ToString(WSAGetLastError()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				WSACleanup();
				Application::Exit();
			}

			// Connect to server.
			iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
			if (iResult == SOCKET_ERROR) {
				closesocket(ConnectSocket);
				ConnectSocket = INVALID_SOCKET;
				continue;
			}
			break;
		}

		freeaddrinfo(result);

		if (ConnectSocket == INVALID_SOCKET) {
			MessageBox::Show("Unable to connect to server !!!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			WSACleanup();
			Application::Exit();
		}
		else MessageBox::Show("Connect Successfully !!!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);

	}
	private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	};
}
