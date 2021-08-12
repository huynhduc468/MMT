#pragma once
#include"Client.h"

namespace TestGUIClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class SignUp : public System::Windows::Forms::Form
	{
	public:
		SignUp(void)
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
		~SignUp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ signupPanel;
	protected:
	private: System::Windows::Forms::Button^ backButton2;
	private: System::Windows::Forms::Button^ signupButton2;
	private: System::Windows::Forms::TextBox^ passwordBox;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ usernameBox;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SignUp::typeid));
			this->signupPanel = (gcnew System::Windows::Forms::Panel());
			this->backButton2 = (gcnew System::Windows::Forms::Button());
			this->signupButton2 = (gcnew System::Windows::Forms::Button());
			this->passwordBox = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->usernameBox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->signupPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// signupPanel
			// 
			this->signupPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->signupPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"signupPanel.BackgroundImage")));
			this->signupPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->signupPanel->Controls->Add(this->backButton2);
			this->signupPanel->Controls->Add(this->signupButton2);
			this->signupPanel->Controls->Add(this->passwordBox);
			this->signupPanel->Controls->Add(this->label10);
			this->signupPanel->Controls->Add(this->usernameBox);
			this->signupPanel->Controls->Add(this->label8);
			this->signupPanel->Controls->Add(this->label9);
			this->signupPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->signupPanel->ForeColor = System::Drawing::SystemColors::Control;
			this->signupPanel->Location = System::Drawing::Point(0, 0);
			this->signupPanel->Name = L"signupPanel";
			this->signupPanel->Size = System::Drawing::Size(627, 374);
			this->signupPanel->TabIndex = 8;
			// 
			// backButton2
			// 
			this->backButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->backButton2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->backButton2->Location = System::Drawing::Point(467, 256);
			this->backButton2->Name = L"backButton2";
			this->backButton2->Size = System::Drawing::Size(113, 67);
			this->backButton2->TabIndex = 6;
			this->backButton2->Text = L"Back";
			this->backButton2->UseVisualStyleBackColor = true;
			this->backButton2->Click += gcnew System::EventHandler(this, &SignUp::backButton2_Click);
			// 
			// signupButton2
			// 
			this->signupButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->signupButton2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->signupButton2->Location = System::Drawing::Point(332, 256);
			this->signupButton2->Name = L"signupButton2";
			this->signupButton2->Size = System::Drawing::Size(113, 67);
			this->signupButton2->TabIndex = 5;
			this->signupButton2->Text = L"Sign Up";
			this->signupButton2->UseVisualStyleBackColor = true;
			this->signupButton2->Click += gcnew System::EventHandler(this, &SignUp::signupButton2_Click);
			// 
			// passwordBox
			// 
			this->passwordBox->BackColor = System::Drawing::Color::LightGray;
			this->passwordBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordBox->Location = System::Drawing::Point(32, 199);
			this->passwordBox->Name = L"passwordBox";
			this->passwordBox->PasswordChar = '*';
			this->passwordBox->Size = System::Drawing::Size(394, 30);
			this->passwordBox->TabIndex = 4;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(33)));
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(27, 171);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(98, 25);
			this->label10->TabIndex = 3;
			this->label10->Text = L"Password";
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
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(33)));
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(27, 96);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(110, 25);
			this->label8->TabIndex = 1;
			this->label8->Text = L"User Name";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(33)));
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(26, 29);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(123, 36);
			this->label9->TabIndex = 0;
			this->label9->Text = L"Sign Up";
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(627, 374);
			this->Controls->Add(this->signupPanel);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->signupPanel->ResumeLayout(false);
			this->signupPanel->PerformLayout();
			this->ResumeLayout(false);
		}

#pragma endregion
	private: System::Void signupButton2_Click(System::Object^ sender, System::EventArgs^ e) {
		string username = msclr::interop::marshal_as<std::string>(System::Convert::ToString(usernameBox->Text));
		char* Acc = (char*)username.c_str();
		string password = msclr::interop::marshal_as<std::string>(System::Convert::ToString(passwordBox->Text));
		char* Pass = (char*)password.c_str();
		send(ConnectSocket, Acc, strlen(Acc), 0);
		this_thread::sleep_for(0.5s);
		send(ConnectSocket, Pass, strlen(Pass), 0);
		char isOk[1] = { '0' };
		recv(ConnectSocket, isOk, 1, 0);
		if (isOk[0] == '1') {
			MessageBox::Show("Sign up successfully", "Notify", MessageBoxButtons::OK, MessageBoxIcon::Information);
			Form::Close();
		}
		else {
			MessageBox::Show("Sign up unsuccessful", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			Form::Close();
		}
	}
	private: System::Void backButton2_Click(System::Object^ sender, System::EventArgs^ e) {
		Form::Close();
	}
};
}
