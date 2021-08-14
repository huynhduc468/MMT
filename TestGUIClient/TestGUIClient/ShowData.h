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
	/// Summary for ShowData
	/// </summary>
	public ref class ShowData : public System::Windows::Forms::Form
	{
	public:
		ShowData(void)
		{
			InitializeComponent();

			char country[20] = { "0" };
			recv(ConnectSocket, country, 20, 0);
			ShowData::view->Items->Add("Country")->SubItems->Add(gcnew String(country));

			char cases[30] = { "0" };
			recv(ConnectSocket, cases, 30, 0);
			ShowData::view->Items->Add("Cases")->SubItems->Add(gcnew String(cases));

			char todayCases[30] = { "0" };
			recv(ConnectSocket, todayCases, 30, 0);
			ShowData::view->Items->Add("Today cases")->SubItems->Add(gcnew String(todayCases));

			char deaths[30] = { "0" };
			recv(ConnectSocket, deaths, 30, 0);
			ShowData::view->Items->Add("Deaths")->SubItems->Add(gcnew String(deaths));

			char todayDeaths[30] = { "0" };
			recv(ConnectSocket, todayDeaths, 30, 0);
			ShowData::view->Items->Add("Today deaths")->SubItems->Add(gcnew String(todayDeaths));

			char recovered[30] = { "0" };
			recv(ConnectSocket, recovered, 30, 0);
			ShowData::view->Items->Add("Recovered")->SubItems->Add(gcnew String(recovered));

			char active[30] = { "0" };
			recv(ConnectSocket, active, 30, 0);
			ShowData::view->Items->Add("Active")->SubItems->Add(gcnew String(active));

			char critical[30] = { "0" };
			recv(ConnectSocket, critical, 30, 0);
			ShowData::view->Items->Add("Critical")->SubItems->Add(gcnew String(critical));

			char casesPerOneMillion[30] = { "0" };
			recv(ConnectSocket, casesPerOneMillion, 30, 0);
			ShowData::view->Items->Add("Cases per one million")->SubItems->Add(gcnew String(casesPerOneMillion));

			char DeathsPerOneMillion[30] = { "0" };
			recv(ConnectSocket, DeathsPerOneMillion, 30, 0);
			ShowData::view->Items->Add("Deaths per one million")->SubItems->Add(gcnew String(DeathsPerOneMillion));

			char totalTests[30] = { "0" };
			recv(ConnectSocket, totalTests, 30, 0);
			ShowData::view->Items->Add("Total tests")->SubItems->Add(gcnew String(totalTests));

			char testPerOneMillion[30] = { "0" };
			recv(ConnectSocket, testPerOneMillion, 30, 0);
			ShowData::view->Items->Add("Test per one million")->SubItems->Add(gcnew String(testPerOneMillion));
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ShowData()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::ListView^ view;
	private: System::Windows::Forms::ColumnHeader^ Creative;
	private: System::Windows::Forms::ColumnHeader^ Data;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->view = (gcnew System::Windows::Forms::ListView());
			this->Creative = (gcnew System::Windows::Forms::ColumnHeader());
			this->Data = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(235, 295);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(87, 32);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Back";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ShowData::button1_Click);
			// 
			// view
			// 
			this->view->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->Creative, this->Data });
			this->view->Dock = System::Windows::Forms::DockStyle::Fill;
			this->view->HideSelection = false;
			this->view->Location = System::Drawing::Point(0, 0);
			this->view->Name = L"view";
			this->view->Size = System::Drawing::Size(334, 339);
			this->view->TabIndex = 11;
			this->view->UseCompatibleStateImageBehavior = false;
			this->view->View = System::Windows::Forms::View::Details;
			// 
			// Creative
			// 
			this->Creative->Text = L"Creative";
			this->Creative->Width = 107;
			// 
			// Data
			// 
			this->Data->Text = L"Data";
			this->Data->Width = 84;
			// 
			// ShowData
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(334, 339);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->view);
			this->Name = L"ShowData";
			this->Text = L"ShowData";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Form::Close();
	}
	};
}
