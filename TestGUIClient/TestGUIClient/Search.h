#pragma once
#include"Client.h"
#include"ShowData.h"

namespace TestGUIClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Search
	/// </summary>
	public ref class Search : public System::Windows::Forms::Form
	{
	public:
		Search(void)
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
		~Search()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ searchPanel;
	protected:
	private: System::Windows::Forms::Button^ backButton2;
	private: System::Windows::Forms::Button^ searchButton;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;

	protected:

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Search::typeid));
			this->searchPanel = (gcnew System::Windows::Forms::Panel());
			this->backButton2 = (gcnew System::Windows::Forms::Button());
			this->searchButton = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->searchPanel->SuspendLayout();
			this->SuspendLayout();
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
			this->searchPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->searchPanel->Location = System::Drawing::Point(0, 0);
			this->searchPanel->Name = L"searchPanel";
			this->searchPanel->Size = System::Drawing::Size(634, 370);
			this->searchPanel->TabIndex = 8;
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
			this->backButton2->Click += gcnew System::EventHandler(this, &Search::backButton2_Click);
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
			this->searchButton->Click += gcnew System::EventHandler(this, &Search::searchButton_Click);
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
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
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
			// Search
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(634, 370);
			this->Controls->Add(this->searchPanel);
			this->Name = L"Search";
			this->Text = L"Search";
			this->searchPanel->ResumeLayout(false);
			this->searchPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void searchButton_Click(System::Object^ sender, System::EventArgs^ e) {
		send(ConnectSocket, "1", 1, 0);
		string tmp = msclr::interop::marshal_as<std::string>(comboBox1->SelectedItem->ToString());
		char* country = (char*)tmp.c_str();
		send(ConnectSocket, country, strlen(country), 0);
		this_thread::sleep_for(0.1s);
		char msg[1] = { '0' };
		recv(ConnectSocket, msg, 1, 0);
		if (msg[0] == '1') {
			ShowData^ show = gcnew ShowData;
			show->Show();
		}
		else
			MessageBox::Show("The country not eixst !!!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	private: System::Void backButton2_Click(System::Object^ sender, System::EventArgs^ e) {
		send(ConnectSocket, "0", 1, 0);
		Form::Close();
	}
};
}
