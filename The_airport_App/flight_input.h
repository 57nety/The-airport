#pragma once

namespace practical_work {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ flight_input
	/// </summary>
	public ref class flight_input : public System::Windows::Forms::Form
	{
	public:
		flight_input(void)
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
		~flight_input()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  flight_number;
	protected: 

	protected: 

	protected: 
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  destination;

	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TextBox^  departure_date;

	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::TextBox^  departure_time;

	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::TextBox^  total_number_of_seats;

	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::TextBox^  ticket_price;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  выходToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  обќкнеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  вернутьс€¬¬вод–ейсовToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  выйти»зѕрограммыToolStripMenuItem;

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
			this->flight_number = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->destination = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->departure_date = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->departure_time = (gcnew System::Windows::Forms::TextBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->total_number_of_seats = (gcnew System::Windows::Forms::TextBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->ticket_price = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вернутьс€¬¬вод–ейсовToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выйти»зѕрограммыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->обќкнеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// flight_number
			// 
			this->flight_number->Location = System::Drawing::Point(46, 31);
			this->flight_number->Name = L"flight_number";
			this->flight_number->Size = System::Drawing::Size(252, 22);
			this->flight_number->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->flight_number);
			this->groupBox1->Location = System::Drawing::Point(46, 42);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(330, 78);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"¬ведите номер рейса";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->destination);
			this->groupBox2->Location = System::Drawing::Point(46, 126);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(330, 78);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"¬ведите пункт назначени€";
			// 
			// destination
			// 
			this->destination->Location = System::Drawing::Point(46, 31);
			this->destination->Name = L"destination";
			this->destination->Size = System::Drawing::Size(252, 22);
			this->destination->TabIndex = 0;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->departure_date);
			this->groupBox3->Location = System::Drawing::Point(46, 210);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(330, 78);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"¬ведите дату отправлени€";
			// 
			// departure_date
			// 
			this->departure_date->Location = System::Drawing::Point(46, 31);
			this->departure_date->Name = L"departure_date";
			this->departure_date->Size = System::Drawing::Size(252, 22);
			this->departure_date->TabIndex = 0;
			this->departure_date->TextChanged += gcnew System::EventHandler(this, &flight_input::departure_date_TextChanged);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->departure_time);
			this->groupBox4->Location = System::Drawing::Point(46, 294);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(330, 78);
			this->groupBox4->TabIndex = 4;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"¬ведите врем€ отправлени€";
			// 
			// departure_time
			// 
			this->departure_time->Location = System::Drawing::Point(46, 31);
			this->departure_time->Name = L"departure_time";
			this->departure_time->Size = System::Drawing::Size(252, 22);
			this->departure_time->TabIndex = 0;
			this->departure_time->TextChanged += gcnew System::EventHandler(this, &flight_input::departure_time_TextChanged);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->total_number_of_seats);
			this->groupBox5->Location = System::Drawing::Point(46, 378);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(330, 78);
			this->groupBox5->TabIndex = 2;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"¬ведите общее количество мест";
			// 
			// total_number_of_seats
			// 
			this->total_number_of_seats->Location = System::Drawing::Point(46, 31);
			this->total_number_of_seats->Name = L"total_number_of_seats";
			this->total_number_of_seats->Size = System::Drawing::Size(252, 22);
			this->total_number_of_seats->TabIndex = 0;
			this->total_number_of_seats->TextChanged += gcnew System::EventHandler(this, &flight_input::total_number_of_seats_TextChanged);
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->ticket_price);
			this->groupBox6->Location = System::Drawing::Point(46, 462);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(330, 78);
			this->groupBox6->TabIndex = 5;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"¬ведите цену за один билет";
			// 
			// ticket_price
			// 
			this->ticket_price->Location = System::Drawing::Point(46, 31);
			this->ticket_price->Name = L"ticket_price";
			this->ticket_price->Size = System::Drawing::Size(252, 22);
			this->ticket_price->TabIndex = 0;
			this->ticket_price->TextChanged += gcnew System::EventHandler(this, &flight_input::ticket_price_TextChanged);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(46, 580);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(330, 66);
			this->button1->TabIndex = 6;
			this->button1->Text = L"ƒобавить рейс";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &flight_input::button1_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->выходToolStripMenuItem, 
				this->обќкнеToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(424, 28);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->вернутьс€¬¬вод–ейсовToolStripMenuItem, 
				this->выйти»зѕрограммыToolStripMenuItem});
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(65, 24);
			this->выходToolStripMenuItem->Text = L"¬ыход";
			// 
			// вернутьс€¬¬вод–ейсовToolStripMenuItem
			// 
			this->вернутьс€¬¬вод–ейсовToolStripMenuItem->Name = L"вернутьс€¬¬вод–ейсовToolStripMenuItem";
			this->вернутьс€¬¬вод–ейсовToolStripMenuItem->Size = System::Drawing::Size(253, 24);
			this->вернутьс€¬¬вод–ейсовToolStripMenuItem->Text = L"¬ернутьс€ в ¬вод рейсов";
			this->вернутьс€¬¬вод–ейсовToolStripMenuItem->Click += gcnew System::EventHandler(this, &flight_input::вернутьс€¬¬вод–ейсовToolStripMenuItem_Click);
			// 
			// выйти»зѕрограммыToolStripMenuItem
			// 
			this->выйти»зѕрограммыToolStripMenuItem->Name = L"выйти»зѕрограммыToolStripMenuItem";
			this->выйти»зѕрограммыToolStripMenuItem->Size = System::Drawing::Size(253, 24);
			this->выйти»зѕрограммыToolStripMenuItem->Text = L"¬ыйти из программы";
			this->выйти»зѕрограммыToolStripMenuItem->Click += gcnew System::EventHandler(this, &flight_input::выйти»зѕрограммыToolStripMenuItem_Click_1);
			// 
			// обќкнеToolStripMenuItem
			// 
			this->обќкнеToolStripMenuItem->Name = L"обќкнеToolStripMenuItem";
			this->обќкнеToolStripMenuItem->Size = System::Drawing::Size(78, 24);
			this->обќкнеToolStripMenuItem->Text = L"ќб окне";
			this->обќкнеToolStripMenuItem->Click += gcnew System::EventHandler(this, &flight_input::обќкнеToolStripMenuItem_Click);
			// 
			// flight_input
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(424, 669);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(442, 716);
			this->MinimumSize = System::Drawing::Size(442, 716);
			this->Name = L"flight_input";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ƒобавление рейса";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

// информаци€ об окне
private: System::Void обќкнеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
// вернутьс€ в ввод рейсов
private: System::Void вернутьс€¬¬вод–ейсовToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
// выйти из программы
private: System::Void выйти»зѕрограммыToolStripMenuItem_Click_1(System::Object^  sender, System::EventArgs^  e);
// добавить рейс
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
// дата отправлени€
private: System::Void departure_date_TextChanged(System::Object^  sender, System::EventArgs^  e);
// врем€ отправлени€
private: System::Void departure_time_TextChanged(System::Object^  sender, System::EventArgs^  e);
// общее количество мест
private: System::Void total_number_of_seats_TextChanged(System::Object^  sender, System::EventArgs^  e);
// цена за билет
private: System::Void ticket_price_TextChanged(System::Object^  sender, System::EventArgs^  e);

};
}
