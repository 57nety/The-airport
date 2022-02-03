#pragma once

namespace practical_work {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ adding_flights
	/// </summary>
	public ref class adding_flights : public System::Windows::Forms::Form
	{
	public:
		adding_flights(void)
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
		~adding_flights()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  выходToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  вернутьс€¬ћенюјдминистратораToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  выйти»зѕрограммыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  обќкнеToolStripMenuItem;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вернутьс€¬ћенюјдминистратораToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выйти»зѕрограммыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->обќкнеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(37, 47);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(409, 59);
			this->button1->TabIndex = 0;
			this->button1->Text = L"ƒобавить рейсы";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &adding_flights::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(37, 147);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(409, 59);
			this->button2->TabIndex = 1;
			this->button2->Text = L"”далить все рейсы";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &adding_flights::button2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Location = System::Drawing::Point(35, 42);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(480, 243);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"¬ыберите действие";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->выходToolStripMenuItem, 
				this->обќкнеToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(560, 28);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->вернутьс€¬ћенюјдминистратораToolStripMenuItem, 
				this->выйти»зѕрограммыToolStripMenuItem});
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(65, 24);
			this->выходToolStripMenuItem->Text = L"¬ыход";
			// 
			// вернутьс€¬ћенюјдминистратораToolStripMenuItem
			// 
			this->вернутьс€¬ћенюјдминистратораToolStripMenuItem->Name = L"вернутьс€¬ћенюјдминистратораToolStripMenuItem";
			this->вернутьс€¬ћенюјдминистратораToolStripMenuItem->Size = System::Drawing::Size(327, 24);
			this->вернутьс€¬ћенюјдминистратораToolStripMenuItem->Text = L"¬ернутьс€ в ћеню администратора";
			this->вернутьс€¬ћенюјдминистратораToolStripMenuItem->Click += gcnew System::EventHandler(this, &adding_flights::вернутьс€¬ћенюјдминистратораToolStripMenuItem_Click);
			// 
			// выйти»зѕрограммыToolStripMenuItem
			// 
			this->выйти»зѕрограммыToolStripMenuItem->Name = L"выйти»зѕрограммыToolStripMenuItem";
			this->выйти»зѕрограммыToolStripMenuItem->Size = System::Drawing::Size(327, 24);
			this->выйти»зѕрограммыToolStripMenuItem->Text = L"¬ыйти из программы";
			this->выйти»зѕрограммыToolStripMenuItem->Click += gcnew System::EventHandler(this, &adding_flights::выйти»зѕрограммыToolStripMenuItem_Click);
			// 
			// обќкнеToolStripMenuItem
			// 
			this->обќкнеToolStripMenuItem->Name = L"обќкнеToolStripMenuItem";
			this->обќкнеToolStripMenuItem->Size = System::Drawing::Size(78, 24);
			this->обќкнеToolStripMenuItem->Text = L"ќб окне";
			this->обќкнеToolStripMenuItem->Click += gcnew System::EventHandler(this, &adding_flights::обќкнеToolStripMenuItem_Click);
			// 
			// adding_flights
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(560, 322);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(578, 369);
			this->MinimumSize = System::Drawing::Size(578, 369);
			this->Name = L"adding_flights";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"¬вод рейсов";
			this->groupBox1->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

// вернутьс€ в меню администратора
private: System::Void вернутьс€¬ћенюјдминистратораToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
// выйти из программы
private: System::Void выйти»зѕрограммыToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
// об окне
private: System::Void обќкнеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
// добавить рейсы
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
// удалить все рейсы
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);

};
}
