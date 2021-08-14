#pragma once
#include"Client.h"
#include"Search.h"

namespace TestGUIClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for SignIn
	/// </summary>
	public ref class SignIn : public System::Windows::Forms::Form
	{
	public:

		SignIn(void)
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
		~SignIn()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ signinPanel;
	protected:
	private: System::Windows::Forms::Button^ backButton;
	private: System::Windows::Forms::Button^ signinButton2;
	private: System::Windows::Forms::TextBox^ passBox;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ usernameBox;
	private: System::Windows::Forms::Label^ label;
	private: System::Windows::Forms::Label^ label5;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SignIn::typeid));
			this->signinPanel = (gcnew System::Windows::Forms::Panel());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->signinButton2 = (gcnew System::Windows::Forms::Button());
			this->passBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->usernameBox = (gcnew System::Windows::Forms::TextBox());
			this->label = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->signinPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// signinPanel
			// 
			this->signinPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->signinPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"signinPanel.BackgroundImage")));
			this->signinPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->signinPanel->Controls->Add(this->backButton);
			this->signinPanel->Controls->Add(this->signinButton2);
			this->signinPanel->Controls->Add(this->passBox);
			this->signinPanel->Controls->Add(this->label6);
			this->signinPanel->Controls->Add(this->usernameBox);
			this->signinPanel->Controls->Add(this->label);
			this->signinPanel->Controls->Add(this->label5);
			this->signinPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->signinPanel->ForeColor = System::Drawing::SystemColors::Control;
			this->signinPanel->Location = System::Drawing::Point(0, 0);
			this->signinPanel->Name = L"signinPanel";
			this->signinPanel->Size = System::Drawing::Size(627, 374);
			this->signinPanel->TabIndex = 5;
			// 
			// backButton
			// 
			this->backButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->backButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->backButton->Location = System::Drawing::Point(467, 256);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(113, 67);
			this->backButton->TabIndex = 6;
			this->backButton->Text = L"Back";
			this->backButton->UseVisualStyleBackColor = true;
			this->backButton->Click += gcnew System::EventHandler(this, &SignIn::backButton_Click);
			// 
			// signinButton2
			// 
			this->signinButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->signinButton2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->signinButton2->Location = System::Drawing::Point(332, 256);
			this->signinButton2->Name = L"signinButton2";
			this->signinButton2->Size = System::Drawing::Size(113, 67);
			this->signinButton2->TabIndex = 5;
			this->signinButton2->Text = L"Sign In";
			this->signinButton2->UseVisualStyleBackColor = true;
			this->signinButton2->Click += gcnew System::EventHandler(this, &SignIn::signinButton2_Click);
			// 
			// passBox
			// 
			this->passBox->BackColor = System::Drawing::Color::LightGray;
			this->passBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passBox->Location = System::Drawing::Point(32, 199);
			this->passBox->Name = L"passBox";
			this->passBox->PasswordChar = '*';
			this->passBox->Size = System::Drawing::Size(394, 30);
			this->passBox->TabIndex = 4;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(33)));
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(27, 171);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(98, 25);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Password";
			// 
			// usernameBox
			// 
			this->usernameBox->BackColor = System::Drawing::Color::Gainsboro;
			this->usernameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usernameBox->Location = System::Drawing::Point(32, 128);
			this->usernameBox->Name = L"usernameBox";
			this->usernameBox->Size = System::Drawing::Size(394, 30);
			this->usernameBox->TabIndex = 2;
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(33)));
			this->label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label->Location = System::Drawing::Point(27, 96);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(110, 25);
			this->label->TabIndex = 1;
			this->label->Text = L"User Name";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(33)));
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(55, 38);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(109, 36);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Sign In";
			// 
			// SignIn
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(627, 374);
			this->Controls->Add(this->signinPanel);
			this->Name = L"SignIn";
			this->Text = L"SignIn";
			this->signinPanel->ResumeLayout(false);
			this->signinPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void signinButton2_Click(System::Object^ sender, System::EventArgs^ e) {
		send(ConnectSocket, "1", 1, 0);
		string username = msclr::interop::marshal_as<std::string>(System::Convert::ToString(usernameBox->Text));
		char* Acc = (char*)username.c_str();
		string password = msclr::interop::marshal_as<std::string>(System::Convert::ToString(passBox->Text));
		char* Pass = (char*)password.c_str();
		char isName[1] = { '0' }, isPass[1] = { '0' };
		send(ConnectSocket, Acc, strlen(Acc), 0);
		recv(ConnectSocket, isName, 1, 0);
		if (isName[0] == '1') {
			send(ConnectSocket, Pass, strlen(Pass), 0);
			recv(ConnectSocket, isPass, 1, 0);
			if (isPass[0] == '1') {
				MessageBox::Show("Sign in successfully", "Notify", MessageBoxButtons::OK, MessageBoxIcon::Information);
				Form::Close();
				Search^ search = gcnew Search;
				search->Show();
			}
			else {
				MessageBox::Show("Password incorrect", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				Form::Close();
			}
		}
		else {
			MessageBox::Show("User Name incorrect", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			Form::Close();
		}
	}
	private: System::Void backButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Form::Close();
	}
};
}