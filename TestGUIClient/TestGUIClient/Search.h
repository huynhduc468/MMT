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
			char country[20] = { "0" };
			recv(ConnectSocket, country, 20, 0);
			Search::view->Items->Add("Country")->SubItems->Add(gcnew String(country));
			//Search::Country->Text = System::Convert::ToString(country);

			char cases[30] = { "0" };
			recv(ConnectSocket, cases, 30, 0);
			Search::view->Items->Add("Cases")->SubItems->Add(gcnew String(cases));
			//Search::Case->Text = System::Convert::ToString(cases);

			char todayCases[30] = { "0" };
			recv(ConnectSocket, todayCases, 30, 0);
			Search::view->Items->Add("Today cases")->SubItems->Add(gcnew String(todayCases));
			//Search::TodayCase->Text = System::Convert::ToString(todayCases);

			char deaths[30] = { "0" };
			recv(ConnectSocket, deaths, 30, 0);
			Search::view->Items->Add("Deaths")->SubItems->Add(gcnew String(deaths));
			//Search::Deaths->Text = System::Convert::ToString(deaths);

			char todayDeaths[30] = { "0" };
			recv(ConnectSocket, todayDeaths, 30, 0);
			Search::view->Items->Add("Today deaths")->SubItems->Add(gcnew String(todayDeaths));
			//Search::TodayDeaths->Text = System::Convert::ToString(todayDeaths);

			char recovered[30] = { "0" };
			recv(ConnectSocket, recovered, 30, 0);
			Search::view->Items->Add("Recovered")->SubItems->Add(gcnew String(recovered));
			//Search::Recovered->Text = System::Convert::ToString(recovered);

			char active[30] = { "0" };
			recv(ConnectSocket, active, 30, 0);
			Search::view->Items->Add("Active")->SubItems->Add(gcnew String(active));
			//Search::Active->Text = System::Convert::ToString(active);

			char critical[30] = { "0" };
			recv(ConnectSocket, critical, 30, 0);
			Search::view->Items->Add("Critical")->SubItems->Add(gcnew String(critical));
			//Search::Critical->Text = System::Convert::ToString(critical);

			char casesPerOneMillion[30] = { "0" };
			recv(ConnectSocket, casesPerOneMillion, 30, 0);
			Search::view->Items->Add("CPOM")->SubItems->Add(gcnew String(casesPerOneMillion));
			//Search::CPOM->Text = System::Convert::ToString(casesPerOneMillion);

			char DeathsPerOneMillion[30] = { "0" };
			recv(ConnectSocket, DeathsPerOneMillion, 30, 0);
			Search::view->Items->Add("DPOM")->SubItems->Add(gcnew String(DeathsPerOneMillion));
			//Search::DPOM->Text = System::Convert::ToString(DeathsPerOneMillion);

			char totalTests[30] = { "0" };
			recv(ConnectSocket, totalTests, 30, 0);
			Search::view->Items->Add("Total tests")->SubItems->Add(gcnew String(totalTests));
			//Search::TotalTest->Text = System::Convert::ToString(totalTests);

			char testPerOneMillion[30] = { "0" };
			recv(ConnectSocket, testPerOneMillion, 30, 0);
			Search::view->Items->Add("TPOM")->SubItems->Add(gcnew String(testPerOneMillion));
			//Search::TPOM->Text = System::Convert::ToString(testPerOneMillion);
			
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
	private: System::Windows::Forms::ColumnHeader^ Creative;
	private: System::Windows::Forms::ColumnHeader^ Data;
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
			this->view = (gcnew System::Windows::Forms::ListView());
			this->Creative = (gcnew System::Windows::Forms::ColumnHeader());
			this->Data = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// view
			// 
			this->view->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->Creative, this->Data });
			this->view->Dock = System::Windows::Forms::DockStyle::Fill;
			this->view->HideSelection = false;
			this->view->Location = System::Drawing::Point(0, 0);
			this->view->Name = L"view";
			this->view->Size = System::Drawing::Size(1172, 290);
			this->view->TabIndex = 7;
			this->view->UseCompatibleStateImageBehavior = false;
			this->view->View = System::Windows::Forms::View::Details;
			// 
			// Creative
			// 
			this->Creative->Text = L"Creative";
			// 
			// Data
			// 
			this->Data->Text = L"Data";
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

};
}
