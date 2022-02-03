#pragma once

namespace practical_work {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ delete_a_specific_flight
	/// </summary>
	public ref class delete_a_specific_flight : public System::Windows::Forms::Form
	{
	public:
		delete_a_specific_flight(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~delete_a_specific_flight()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox4;
	protected: 

	private: System::Windows::Forms::Button^  button1;


	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  выходToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  вернутьс€¬ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  выйти»зѕрограммыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  обќкнеToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^  dataGridView;


	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вернутьс€¬ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выйти»зѕрограммыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->обќкнеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->dataGridView);
			this->groupBox4->Location = System::Drawing::Point(12, 40);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(1132, 545);
			this->groupBox4->TabIndex = 13;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"¬се имеющиес€ рейсы";
			// 
			// dataGridView
			// 
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Location = System::Drawing::Point(6, 21);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->ReadOnly = true;
			this->dataGridView->RowTemplate->Height = 24;
			this->dataGridView->Size = System::Drawing::Size(1120, 518);
			this->dataGridView->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(270, 603);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(563, 62);
			this->button1->TabIndex = 12;
			this->button1->Text = L"”далить рейс";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &delete_a_specific_flight::button1_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->выходToolStripMenuItem, 
				this->обќкнеToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1156, 28);
			this->menuStrip1->TabIndex = 11;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->вернутьс€¬ToolStripMenuItem, 
				this->выйти»зѕрограммыToolStripMenuItem});
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(65, 24);
			this->выходToolStripMenuItem->Text = L"¬ыход";
			// 
			// вернутьс€¬ToolStripMenuItem
			// 
			this->вернутьс€¬ToolStripMenuItem->Name = L"вернутьс€¬ToolStripMenuItem";
			this->вернутьс€¬ToolStripMenuItem->Size = System::Drawing::Size(367, 24);
			this->вернутьс€¬ToolStripMenuItem->Text = L"¬ернутьс€ в ¬ыбор типа редактировани€";
			this->вернутьс€¬ToolStripMenuItem->Click += gcnew System::EventHandler(this, &delete_a_specific_flight::вернутьс€¬ToolStripMenuItem_Click);
			// 
			// выйти»зѕрограммыToolStripMenuItem
			// 
			this->выйти»зѕрограммыToolStripMenuItem->Name = L"выйти»зѕрограммыToolStripMenuItem";
			this->выйти»зѕрограммыToolStripMenuItem->Size = System::Drawing::Size(367, 24);
			this->выйти»зѕрограммыToolStripMenuItem->Text = L"¬ыйти из программы";
			this->выйти»зѕрограммыToolStripMenuItem->Click += gcnew System::EventHandler(this, &delete_a_specific_flight::выйти»зѕрограммыToolStripMenuItem_Click);
			// 
			// обќкнеToolStripMenuItem
			// 
			this->обќкнеToolStripMenuItem->Name = L"обќкнеToolStripMenuItem";
			this->обќкнеToolStripMenuItem->Size = System::Drawing::Size(78, 24);
			this->обќкнеToolStripMenuItem->Text = L"ќб окне";
			this->обќкнеToolStripMenuItem->Click += gcnew System::EventHandler(this, &delete_a_specific_flight::обќкнеToolStripMenuItem_Click);
			// 
			// delete_a_specific_flight
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1156, 687);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1174, 734);
			this->MinimumSize = System::Drawing::Size(1174, 734);
			this->Name = L"delete_a_specific_flight";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"”даление рейса";
			this->Shown += gcnew System::EventHandler(this, &delete_a_specific_flight::delete_a_specific_flight_Shown);
			this->groupBox4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
// вернутьс€ в ¬ыбор типа редактировани€
private: System::Void вернутьс€¬ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
// выйти из программы
private: System::Void выйти»зѕрограммыToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
// об окне
private: System::Void обќкнеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
// вывод рейсов при загрузке формы
private: System::Void delete_a_specific_flight_Shown(System::Object^  sender, System::EventArgs^  e);
// шапка таблицы
private: void Header();
// вывод рейсов в таблицу
private: void Show();
// удалить рейс
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
};
}
