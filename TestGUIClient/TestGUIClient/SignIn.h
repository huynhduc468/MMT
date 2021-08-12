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
			searchPanel->Hide();
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
	private: System::Windows::Forms::Panel^ searchPanel;

	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ backButton2;
	private: System::Windows::Forms::Button^ searchButton;
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
			this->searchPanel = (gcnew System::Windows::Forms::Panel());
			this->backButton2 = (gcnew System::Windows::Forms::Button());
			this->searchButton = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->signinButton2 = (gcnew System::Windows::Forms::Button());
			this->passBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->usernameBox = (gcnew System::Windows::Forms::TextBox());
			this->label = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->signinPanel->SuspendLayout();
			this->searchPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// signinPanel
			// 
			this->signinPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->signinPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"signinPanel.BackgroundImage")));
			this->signinPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->signinPanel->Controls->Add(this->searchPanel);
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
			// searchPanel
			// 
			this->searchPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"searchPanel.BackgroundImage")));
			this->searchPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->searchPanel->Controls->Add(this->backButton2);
			this->searchPanel->Controls->Add(this->searchButton);
			this->searchPanel->Controls->Add(this->comboBox1);
			this->searchPanel->Controls->Add(this->label1);
			this->searchPanel->Controls->Add(this->label3);
			this->searchPanel->Location = System::Drawing::Point(0, 0);
			this->searchPanel->Name = L"searchPanel";
			this->searchPanel->Size = System::Drawing::Size(627, 374);
			this->searchPanel->TabIndex = 7;
			// 
			// backButton2
			// 
			this->backButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->backButton2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->backButton2->Location = System::Drawing::Point(501, 128);
			this->backButton2->Name = L"backButton2";
			this->backButton2->Size = System::Drawing::Size(89, 34);
			this->backButton2->TabIndex = 5;
			this->backButton2->Text = L"Back";
			this->backButton2->UseVisualStyleBackColor = true;
			this->backButton2->Click += gcnew System::EventHandler(this, &SignIn::backButton2_Click);
			// 
			// searchButton
			// 
			this->searchButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->searchButton->Location = System::Drawing::Point(332, 128);
			this->searchButton->Name = L"searchButton";
			this->searchButton->Size = System::Drawing::Size(89, 34);
			this->searchButton->TabIndex = 4;
			this->searchButton->Text = L"Search";
			this->searchButton->UseVisualStyleBackColor = true;
			this->searchButton->Click += gcnew System::EventHandler(this, &SignIn::searchButton_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->comboBox1->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(222) {
				L"USA", L"India", L"Brazil", L"Russia", L"France",
					L"UK", L"Turkey", L"Argentina", L"Colombia", L"Spain", L"Italy", L"Iran", L"Germany", L"Indonesia", L"Mexico", L"Poland", L"South Africa",
					L"Ukraine", L"Peru", L"Netherlands", L"Iraq", L"Czechia", L"Philippines", L"Chile", L"Canada", L"Bangladesh", L"Malaysia", L"Belgium",
					L"Sweden", L"Romania", L"Pakistan", L"Japan", L"Portugal", L"Israel", L"Hungary", L"Jordan", L"Thailand", L"Serbia", L"Switzerland",
					L"Nepal", L"UAE", L"Morocco", L"Austria", L"Kazakhstan", L"Tunisia", L"Lebanon", L"Saudi Arabia", L"Greece", L"Ecuador", L"Bolivia",
					L"Paraguay", L"Belarus", L"Cuba", L"Georgia", L"Panama", L"Bulgaria", L"Costa Rica", L"Kuwait", L"Slovakia", L"Guatemala", L"Uruguay",
					L"Croatia", L"Azerbaijan", L"Dominican Republic", L"Sri Lanka", L"Myanmar", L"Denmark", L"Palestine", L"Venezuela", L"Ireland",
					L"Honduras", L"Oman", L"Lithuania", L"Egypt", L"Ethiopia", L"Bahrain", L"Libya", L"Moldova", L"Slovenia", L"Armenia", L"Qatar",
					L"Kenya", L"S.Korea", L"Bosniaand Herzegovina", L"Vietnam", L"Zambia", L"Algeria", L"Nigeria", L"Mongolia", L"Kyrgyzstan", L"North Macedonia",
					L"Afghanistan", L"Norway", L"Latvia", L"Uzbekistan", L"Estonia", L"Albania", L"Mozambique", L"Botswana", L"Namibia", L"Zimbabwe",
					L"Finland", L"Ghana", L"Cyprus", L"Montenegro", L"Uganda", L"El Salvador", L"Cameroon", L"Cambodia", L"Maldives", L"Rwanda",
					L"Luxembourg", L"Senegal", L"Singapore", L"Malawi", L"Jamaica", L"DRC", L"Ivory Coast", L"Angola", L"Madagascar", L"R├⌐union",
					L"Trinidadand Tobago", L"Sudan", L"Fiji", L"Australia", L"Malta", L"Cabo Verde", L"French Guiana", L"Eswatini", L"Mauritania",
					L"Guinea", L"Syria", L"Suriname", L"Gabon", L"Guadeloupe", L"Martinique", L"Guyana", L"French Polynesia", L"Haiti", L"Mayotte",
					L"Seychelles", L"Papua New Guinea", L"Togo", L"Somalia", L"Taiwan", L"Tajikistan", L"Bahamas", L"Andorra", L"Mali", L"Belize",
					L"Cura├ºao", L"Burkina Faso", L"Lesotho", L"Congo", L"Aruba", L"Hong Kong", L"Djibouti", L"Timor - Leste", L"South Sudan", L"Nicaragua",
					L"Channel Islands", L"Equatorial Guinea", L"Iceland", L"Benin", L"Gambia", L"Laos", L"Burundi", L"CAR", L"Yemen", L"Eritrea",
					L"Sierra Leone", L"Saint Lucia", L"Niger", L"Liberia", L"Isle of Man", L"San Marino", L"Gibraltar", L"Chad", L"Guinea - Bissau",
					L"Mauritius", L"Barbados", L"Comoros", L"Liechtenstein", L"Monaco", L"Sint Maarten", L"New Zealand", L"Saint Martin", L"Bermuda",
					L"Bhutan", L"Turks and Caicos", L"British Virgin Islands", L"Sao Tome and Principe", L"St.Vincent Grenadines", L"Caribbean Netherlands",
					L"St.Barth", L"Antigua and Barbuda", L"Tanzania", L"Faeroe Islands", L"Diamond Princess", L"Cayman Islands", L"Saint Kitts and Nevis",
					L"Wallis and Futuna", L"Dominica", L"Brunei", L"Greenland", L"Grenada", L"New Caledonia", L"Anguilla", L"Falkland Islands", L"Macao",
					L"Saint Pierre Miquelon", L"Vatican City", L"Montserrat", L"Solomon Islands", L"Western Sahara", L"MS Zaandam", L"Vanuatu", L"Marshall Islands",
					L"Samoa", L"Saint Helena", L"Micronesia", L"China"
			});
			this->comboBox1->Location = System::Drawing::Point(276, 72);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(218, 30);
			this->comboBox1->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(33)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(75, 72);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(173, 24);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Enter the Country";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(33)));
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(56, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(511, 29);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Covid-19 epidemic information in countries";
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
			this->searchPanel->ResumeLayout(false);
			this->searchPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void signinButton2_Click(System::Object^ sender, System::EventArgs^ e) {
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
				MessageBox::Show("Sign up successfully", "Notify", MessageBoxButtons::OK, MessageBoxIcon::Information);
				searchPanel->Show();
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
	private: System::Void searchButton_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show(System::Convert::ToString(comboBox1->SelectedItem));
		string tmp = msclr::interop::marshal_as<std::string>(comboBox1->SelectedItem->ToString());
		char* country = (char*)tmp.c_str();
		send(ConnectSocket, country, strlen(country), 0);
		this_thread::sleep_for(0.1s);
		char msg[1] = { '0' };
		recv(ConnectSocket, msg, 1, 0);
		if (msg[0] == '1') {
			Search^ search = gcnew Search;
			search->Show();
		}
		else {
			MessageBox::Show("The country not eixst !!!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	private: System::Void backButton2_Click(System::Object^ sender, System::EventArgs^ e) {
		send(ConnectSocket, "0", 1, 0);
		searchPanel->Hide();
	}
};
}