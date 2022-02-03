#pragma once

namespace practical_work {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ сhange_password
	/// </summary>
	public ref class сhange_password : public System::Windows::Forms::Form
	{
	public:
		сhange_password(void)
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
		~сhange_password()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  old_pas;
	protected: 

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  new_pas;
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
			this->old_pas = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->new_pas = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вернутьс€¬ћенюјдминистратораToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выйти»зѕрограммыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->обќкнеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(41, 253);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(470, 62);
			this->button1->TabIndex = 0;
			this->button1->Text = L"—менить пароль";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &сhange_password::button1_Click);
			// 
			// old_pas
			// 
			this->old_pas->Location = System::Drawing::Point(20, 32);
			this->old_pas->Name = L"old_pas";
			this->old_pas->Size = System::Drawing::Size(432, 22);
			this->old_pas->TabIndex = 1;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->old_pas);
			this->groupBox1->Location = System::Drawing::Point(41, 45);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(470, 80);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"¬ведите старый пароль";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->new_pas);
			this->groupBox2->Location = System::Drawing::Point(41, 152);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(470, 80);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"¬ведите новый пароль";
			// 
			// new_pas
			// 
			this->new_pas->Location = System::Drawing::Point(20, 32);
			this->new_pas->Name = L"new_pas";
			this->new_pas->Size = System::Drawing::Size(432, 22);
			this->new_pas->TabIndex = 1;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->выходToolStripMenuItem, 
				this->обќкнеToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(558, 28);
			this->menuStrip1->TabIndex = 5;
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
			this->вернутьс€¬ћенюјдминистратораToolStripMenuItem->Click += gcnew System::EventHandler(this, &сhange_password::вернутьс€¬ћенюјдминистратораToolStripMenuItem_Click);
			// 
			// выйти»зѕрограммыToolStripMenuItem
			// 
			this->выйти»зѕрограммыToolStripMenuItem->Name = L"выйти»зѕрограммыToolStripMenuItem";
			this->выйти»зѕрограммыToolStripMenuItem->Size = System::Drawing::Size(327, 24);
			this->выйти»зѕрограммыToolStripMenuItem->Text = L"¬ыйти из программы";
			this->выйти»зѕрограммыToolStripMenuItem->Click += gcnew System::EventHandler(this, &сhange_password::выйти»зѕрограммыToolStripMenuItem_Click);
			// 
			// обќкнеToolStripMenuItem
			// 
			this->обќкнеToolStripMenuItem->Name = L"обќкнеToolStripMenuItem";
			this->обќкнеToolStripMenuItem->Size = System::Drawing::Size(78, 24);
			this->обќкнеToolStripMenuItem->Text = L"ќб окне";
			this->обќкнеToolStripMenuItem->Click += gcnew System::EventHandler(this, &сhange_password::обќкнеToolStripMenuItem_Click);
			// 
			// сhange_password
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(558, 345);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(576, 392);
			this->MinimumSize = System::Drawing::Size(576, 392);
			this->Name = L"сhange_password";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"—менить пароль";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

// сменить пароль
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
// вернутьс€ в меню администратора
private: System::Void вернутьс€¬ћенюјдминистратораToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
// выйти из программы
private: System::Void выйти»зѕрограммыToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
// об окне
private: System::Void обќкнеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

};
}
