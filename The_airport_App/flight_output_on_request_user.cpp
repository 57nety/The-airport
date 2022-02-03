#include "flight_output_on_request_user.h"
#include "functions.h"

// подключаю формы для перехода
#include "visitor_menu.h"
#include "found_flights.h"

// вернуться в меню администратора
System::Void practical_work::flight_output_on_request_user::вернутьсяВToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	remove("look_for.txt");
	visitor_menu^ form = gcnew visitor_menu();
	this->Hide();
	form->Show();
}
// выйти из программы
System::Void practical_work::flight_output_on_request_user::выйтиИзПрограммыToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	remove("look_for.txt");
	Application::Exit();
}
// об окне
System::Void practical_work::flight_output_on_request_user::обОкнеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	MessageBox::Show("Для того, чтобы произвести вывод рейсов по запросу, вам надо ввести в соответствующие поля ту информацию, которую хотите, чтобы содержали найденные рейсы. Также вы можите вернуться в Меню администратора или выйти из программы.","Об окне");
}
// вывод рейсов при загрузке формы
System::Void practical_work::flight_output_on_request_user::flight_output_on_request_user_Shown(System::Object^  sender, System::EventArgs^  e)
{
	FILE *fptr;
	char flight_number[SIZE] = {},destination[SIZE] = {},departure_date[SIZE] = {},departure_time[SIZE] = {},total_number_of_seats[SIZE] = {},ticket_price[SIZE] = {};
	int number_of_flights;
    fptr = fopen("flight_schedule.txt","at");
	if( fptr == NULL)
	{
		fclose(fptr);
		MessageBox::Show("Не удалось открыть файл flight_schedule.txt","Ошибка");
		this->Hide();
	}
	else
	{
		fclose(fptr);
		fptr = fopen("flight_schedule.txt","rt");
		if( fptr == NULL)
		{
			fclose(fptr);
			MessageBox::Show("Не удалось открыть файл flight_schedule.txt","Ошибка");
			this->Hide();
		}
		else
		{
			rewind(fptr);
			number_of_flights = 0;
			while( fscanf(fptr,"%s%s%s%s%s%s", flight_number,destination,departure_date,departure_time,total_number_of_seats,ticket_price) != EOF )
				number_of_flights++;
			fclose(fptr);
		}
	}
	// чистка строчек и столбцов
	dataGridView->Rows->Clear();
	dataGridView->Columns->Clear();

	// шапка таблицы рейсов
	Header();

	// размер таблицы
	dataGridView->RowCount = number_of_flights;
	dataGridView->ColumnCount = 6;

	// вывод таблицы
	Show();

	// выравнивание таблицы
	dataGridView->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView->AutoResizeColumns();
}
// шапка таблицы
void practical_work::flight_output_on_request_user::Header()
{
	DataGridViewTextBoxColumn^ c1 = gcnew DataGridViewTextBoxColumn();
	c1->Name = "flight_number";
	c1->HeaderText = "Номер рейса";
	c1->Width = 150;
	dataGridView->Columns->Add(c1);

	DataGridViewTextBoxColumn^ c2 = gcnew DataGridViewTextBoxColumn();
	c2->Name = "destination";
	c2->HeaderText = "Пункт назначения";
	c2->Width = 150;
	dataGridView->Columns->Add(c2);

	DataGridViewTextBoxColumn^ c3 = gcnew DataGridViewTextBoxColumn();
	c3->Name = "departure_date";
	c3->HeaderText = "Дата отправления";
	c3->Width = 150;
	dataGridView->Columns->Add(c3);

	DataGridViewTextBoxColumn^ c4 = gcnew DataGridViewTextBoxColumn();
	c4->Name = "departure_time";
	c4->HeaderText = "Время отправления";
	c4->Width = 150;
	dataGridView->Columns->Add(c4);

	DataGridViewTextBoxColumn^ c5 = gcnew DataGridViewTextBoxColumn();
	c5->Name = "total_number_of_seats";
	c5->HeaderText = "Общее количество мест";
	c5->Width = 150;
	dataGridView->Columns->Add(c5);

	DataGridViewTextBoxColumn^ c6 = gcnew DataGridViewTextBoxColumn();
	c6->Name = "ticket_price";
	c6->HeaderText = "Цена билета";
	c6->Width = 150;
	dataGridView->Columns->Add(c6);

	dataGridView->TopLeftHeaderCell->Value = "Номер строчки";
	dataGridView->AutoResizeColumns(); // выравнивание колонок
}
// вывод рейсов в таблицу
void practical_work::flight_output_on_request_user::Show()
{
	FILE *fptr;
	char flight_number[SIZE] = {},destination[SIZE] = {},departure_date[SIZE] = {},departure_time[SIZE] = {},total_number_of_seats[SIZE] = {},ticket_price[SIZE] = {};
	int i;
    fptr = fopen("flight_schedule.txt","at");
	if( fptr == NULL)
	{
		fclose(fptr);
		MessageBox::Show("Не удалось открыть файл flight_schedule.txt","Ошибка");
		this->Hide();
	}
	else
	{
		fclose(fptr);
		fptr = fopen("flight_schedule.txt","rt");
		if( fptr == NULL)
		{
			fclose(fptr);
			MessageBox::Show("Не удалось открыть файл flight_schedule.txt","Ошибка");
			this->Hide();
		}
		else
		{
			rewind(fptr);
			i = 0;
			while( fscanf(fptr,"%s%s%s%s%s%s", flight_number,destination,departure_date,departure_time,total_number_of_seats,ticket_price) != EOF )
			{
				dataGridView->Rows[i]->HeaderCell->Value = Convert::ToString(i+1);
				// вывод данных в ячейки
				dataGridView->Rows[i]->Cells[0]->Value = Convert_string_to_String((std::string)flight_number);
				dataGridView->Rows[i]->Cells[1]->Value = Convert_string_to_String((std::string)destination);
				dataGridView->Rows[i]->Cells[2]->Value = Convert_string_to_String((std::string)departure_date);
				dataGridView->Rows[i]->Cells[3]->Value = Convert_string_to_String((std::string)departure_time);
				dataGridView->Rows[i]->Cells[4]->Value = Convert_string_to_String((std::string)total_number_of_seats);
				dataGridView->Rows[i]->Cells[5]->Value = Convert_string_to_String((std::string)ticket_price);
				i++;
			}
			fclose(fptr);
		}
	}
}
// желаемая дата
System::Void practical_work::flight_output_on_request_user::t3_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if( letter_entry_protection( Convert_String_to_char( t3->Text ) ) )
	{
		MessageBox::Show("Поле желаемой даты отправления не должно содержать букв.","Ошибка");
		t3->Text = "";
	}
}
// желаемое время
System::Void practical_work::flight_output_on_request_user::t4_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if( letter_entry_protection( Convert_String_to_char( t4->Text ) ) )
	{
		MessageBox::Show("Поле желаемого времени отправления не должно содержать букв.","Ошибка");
		t4->Text = "";
	}
}
// желаемое количество мест
System::Void practical_work::flight_output_on_request_user::t5_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if( letter_entry_protection( Convert_String_to_char( t5->Text ) ) )
	{
		MessageBox::Show("Поле желаемого общего числа посадочных мест не должно содержать букв.","Ошибка");
		t5->Text = "";
	}
}
// желаемая цена
System::Void practical_work::flight_output_on_request_user::t6_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if( letter_entry_protection( Convert_String_to_char( t6->Text ) ) )
	{
		MessageBox::Show("Поле желаемой цены за билет не должно содержать букв.","Ошибка");
		t6->Text = "";
	}
}
// применить фильтр
System::Void practical_work::flight_output_on_request_user::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	FILE *fptr;
	int flag, k, counter;
	char s1[SIZE] = {}, s2[SIZE] = {};
	if( t1->Text == "" && t2->Text == "" && t3->Text == "" && t4->Text == "" && t5->Text == "" && t6->Text == "" )
	{
		MessageBox::Show("Для того, чтобы применить фильтр, вам надо ввести хотя бы в одно поле желаемые данные!","Ошибка");
	}
	else
	{
		if( t3->Text != "" )
		{
			if( strlen( Convert_String_to_char( t3->Text ) ) != 10 || Convert_String_to_char( t3->Text )[2] != '.' || Convert_String_to_char( t3->Text )[5] != '.' )
			{
				MessageBox::Show("Поле даты отправления должно иметь вид (дд.мм.гггг).","Ошибка");
				t3->Text = "";
				return System::Void();
			}
		}
		counter = 0;
		fptr = fopen("look_for.txt","wt");
		if( fptr == NULL )
		{
			MessageBox::Show("Не удалось открыть файл look_for.txt.","Ошибка");
			fclose(fptr);
			this->Hide(); // закрытие формы
		}
		else
		{
			for( int i = 0; i < dataGridView->RowCount; i++ )
			{
				flag = 0;
				if( strlen(Convert_String_to_char(t1->Text)) > 0 && flag == 0 )
				{
					if( strcmp(Convert_String_to_char(t1->Text),Convert_String_to_char(dataGridView->Rows[i]->Cells[0]->Value->ToString())) == 0 )
					{
						flag = 0;
					}
					else
					{
						flag = 1;
					}
				}
				if( strlen(Convert_String_to_char(t2->Text)) > 0 && flag == 0 )
				{
					if( strcmp(Convert_String_to_char(t2->Text),Convert_String_to_char(dataGridView->Rows[i]->Cells[1]->Value->ToString())) == 0 )
					{
						flag = 0;
					}
					else
					{
						flag = 1;
					}
				}
				if( strlen(Convert_String_to_char(t3->Text)) > 0 && flag == 0 )
				{
					k = 0;
					for(int j = 6; j < 10; j++ )
					{
						s1[k] = Convert_String_to_char(t3->Text)[j];
						k++;
					}
					for(int j = 3; j < 5; j++ )
					{
						s1[k] = Convert_String_to_char(t3->Text)[j];
						k++;
					}
					for(int j = 0; j < 2; j++ )
					{
						s1[k] = Convert_String_to_char(t3->Text)[j];
						k++;
					}
					s1[k] = '\0';
					k = 0;
					for(int j = 6; j < 10; j++ )
					{
						s2[k] = Convert_String_to_char(dataGridView->Rows[i]->Cells[2]->Value->ToString())[j];
						k++;
					}
					for(int j = 3; j < 5; j++ )
					{
						s2[k] = Convert_String_to_char(dataGridView->Rows[i]->Cells[2]->Value->ToString())[j];
						k++;
					}
					for(int j = 0; j < 2; j++ )
					{
						s2[k] = Convert_String_to_char(dataGridView->Rows[i]->Cells[2]->Value->ToString())[j];
						k++;
					}
					s2[k] = '\0';

					if( strcmp(s1,s2) >= 0 )
						flag = 0;
					else
						flag = 1;
				}
				if( strlen(Convert_String_to_char(t4->Text)) > 0 && flag == 0 )
				{
					if( strcmp(Convert_String_to_char(t4->Text),Convert_String_to_char(dataGridView->Rows[i]->Cells[3]->Value->ToString())) >= 0 )
					{
						flag = 0;
					}
					else
					{
						flag = 1;
					}
				}
				if( strlen(Convert_String_to_char(t5->Text)) > 0 && flag == 0 )
				{
					if( Convert::ToDouble(t5->Text) <= Convert::ToDouble(dataGridView->Rows[i]->Cells[4]->Value->ToString()) )
					{
						flag = 0;
					}
					else
					{
						flag = 1;
					}
				}
				if( strlen(Convert_String_to_char(t6->Text)) > 0 && flag == 0 )
				{
					if( Convert::ToDouble(t6->Text) >= Convert::ToDouble(dataGridView->Rows[i]->Cells[5]->Value->ToString()) )
					{
						flag = 0;
					}
					else
					{
						flag = 1;
					}
				}
				if( flag == 0 )
				{
					counter++;
					fprintf(fptr," %s ",Convert_String_to_char(dataGridView->Rows[i]->Cells[0]->Value->ToString()));
					fprintf(fptr," %s ",Convert_String_to_char(dataGridView->Rows[i]->Cells[1]->Value->ToString()));
					fprintf(fptr," %s ",Convert_String_to_char(dataGridView->Rows[i]->Cells[2]->Value->ToString()));
					fprintf(fptr," %s ",Convert_String_to_char(dataGridView->Rows[i]->Cells[3]->Value->ToString()));
					fprintf(fptr," %s ",Convert_String_to_char(dataGridView->Rows[i]->Cells[4]->Value->ToString()));
					fprintf(fptr," %s \n",Convert_String_to_char(dataGridView->Rows[i]->Cells[5]->Value->ToString()));
				}
			}
			fclose(fptr);
		}
		if( counter > 0 )
		{
			found_flights^ form = gcnew found_flights();
			form->Show();
		}
		else
		{
			MessageBox::Show("Не удалось найти рейсов, подходящих под ваш запрос.","Ошибка!");
		}
	}
	t1->Text = "";
	t2->Text = "";
	t3->Text = "";
	t4->Text = "";
	t5->Text = "";
	t6->Text = "";
}