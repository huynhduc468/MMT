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
	private: System::Windows::Forms::ListView^ view;
	protected:

	protected:
	private: System::Windows::Forms::ColumnHeader^ Country;
	private: System::Windows::Forms::ColumnHeader^ Case;
	private: System::Windows::Forms::ColumnHeader^ TodayCase;
	private: System::Windows::Forms::ColumnHeader^ Deaths;
	private: System::Windows::Forms::ColumnHeader^ TodayDeaths;
	private: System::Windows::Forms::ColumnHeader^ Recovered;
	private: System::Windows::Forms::ColumnHeader^ Active;
	private: System::Windows::Forms::ColumnHeader^ Critical;
	private: System::Windows::Forms::ColumnHeader^ CPOM;
	private: System::Windows::Forms::ColumnHeader^ DPOM;
	private: System::Windows::Forms::ColumnHeader^ TotalTest;
	private: System::Windows::Forms::ColumnHeader^ TPOM;

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
			this->view = (gcnew System::Windows::Forms::ListView());
			this->Country = (gcnew System::Windows::Forms::ColumnHeader());
			this->Case = (gcnew System::Windows::Forms::ColumnHeader());
			this->TodayCase = (gcnew System::Windows::Forms::ColumnHeader());
			this->Deaths = (gcnew System::Windows::Forms::ColumnHeader());
			this->TodayDeaths = (gcnew System::Windows::Forms::ColumnHeader());
			this->Recovered = (gcnew System::Windows::Forms::ColumnHeader());
			this->Active = (gcnew System::Windows::Forms::ColumnHeader());
			this->Critical = (gcnew System::Windows::Forms::ColumnHeader());
			this->CPOM = (gcnew System::Windows::Forms::ColumnHeader());
			this->DPOM = (gcnew System::Windows::Forms::ColumnHeader());
			this->TotalTest = (gcnew System::Windows::Forms::ColumnHeader());
			this->TPOM = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// view
			// 
			this->view->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(12) {
				this->Country, this->Case, this->TodayCase,
					this->Deaths, this->TodayDeaths, this->Recovered, this->Active, this->Critical, this->CPOM, this->DPOM, this->TotalTest, this->TPOM
			});
			this->view->HideSelection = false;
			this->view->Location = System::Drawing::Point(2, -1);
			this->view->Name = L"view";
			this->view->Size = System::Drawing::Size(1170, 293);
			this->view->TabIndex = 7;
			this->view->UseCompatibleStateImageBehavior = false;
			this->view->View = System::Windows::Forms::View::Details;
			this->view->SelectedIndexChanged += gcnew System::EventHandler(this, &Search::listView1_SelectedIndexChanged);
			// 
			// Country
			// 
			this->Country->Text = L"Country";
			this->Country->Width = 77;
			// 
			// Case
			// 
			this->Case->Text = L"Case";
			this->Case->Width = 69;
			// 
			// TodayCase
			// 
			this->TodayCase->Text = L"Today case";
			this->TodayCase->Width = 90;
			// 
			// Deaths
			// 
			this->Deaths->Text = L"Deaths";
			this->Deaths->Width = 75;
			// 
			// TodayDeaths
			// 
			this->TodayDeaths->Text = L"Today deaths";
			this->TodayDeaths->Width = 100;
			// 
			// Recovered
			// 
			this->Recovered->Text = L"Recovered";
			this->Recovered->Width = 85;
			// 
			// Active
			// 
			this->Active->Text = L"Active";
			this->Active->Width = 73;
			// 
			// Critical
			// 
			this->Critical->Text = L"Critical";
			this->Critical->Width = 78;
			// 
			// CPOM
			// 
			this->CPOM->Text = L"Cases per one million";
			this->CPOM->Width = 143;
			// 
			// DPOM
			// 
			this->DPOM->Text = L"Deaths per one million";
			this->DPOM->Width = 148;
			// 
			// TotalTest
			// 
			this->TotalTest->Text = L"Total test";
			this->TotalTest->Width = 92;
			// 
			// TPOM
			// 
			this->TPOM->Text = L"Test Per one million";
			this->TPOM->Width = 135;
			// 
			// Search
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1172, 290);
			this->Controls->Add(this->view);
			this->Name = L"Search";
			this->Text = L"Search";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		char country[20] = { "0" };
		recv(ConnectSocket, country, 20, 0);
		Country->Text = System::Convert::ToString(country);

		char cases[30] = { "0" };
		recv(ConnectSocket, cases, 30, 0);
		Case->Text = System::Convert::ToString(cases);

		char todayCases[30] = { "0" };
		recv(ConnectSocket, todayCases, 30, 0);
		TodayCase->Text = System::Convert::ToString(todayCases);

		char deaths[30] = { "0" };
		recv(ConnectSocket, deaths, 30, 0);
		Deaths->Text = System::Convert::ToString(deaths);

		char todayDeaths[30] = { "0" };
		recv(ConnectSocket, todayDeaths, 30, 0);
		TodayDeaths->Text = System::Convert::ToString(todayDeaths);

		char recovered[30] = { "0" };
		recv(ConnectSocket, recovered, 30, 0);
		Recovered->Text = System::Convert::ToString(recovered);

		char active[30] = { "0" };
		recv(ConnectSocket, active, 30, 0);
		Active->Text = System::Convert::ToString(active);

		char critical[30] = { "0" };
		recv(ConnectSocket, critical, 30, 0);
		Critical->Text = System::Convert::ToString(critical);

		char casesPerOneMillion[30] = { "0" };
		recv(ConnectSocket, casesPerOneMillion, 30, 0);
		CPOM->Text = System::Convert::ToString(casesPerOneMillion);

		char DeathsPerOneMillion[30] = { "0" };
		recv(ConnectSocket, DeathsPerOneMillion, 30, 0);
		DPOM->Text = System::Convert::ToString(DeathsPerOneMillion);

		char totalTests[30] = { "0" };
		recv(ConnectSocket, totalTests, 30, 0);
		TotalTest->Text = System::Convert::ToString(totalTests);

		char testPerOneMillion[30] = { "0" };
		recv(ConnectSocket, testPerOneMillion, 30, 0);
		TPOM->Text = System::Convert::ToString(testPerOneMillion);
	}
};
}
