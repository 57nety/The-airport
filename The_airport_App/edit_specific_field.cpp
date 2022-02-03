#include "edit_specific_field.h"
#include "functions.h"

// подключаю формы для перехода
#include "edit_type_selection.h"

// вернуться в выбор типа редактирования
System::Void practical_work::edit_specific_field::вернутьсяВToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	edit_type_selection^ form = gcnew edit_type_selection();
	this->Hide();
	form->Show();
}
// выйти из программы
System::Void practical_work::edit_specific_field::выйтиИзПрограммыToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	Application::Exit();
}
// об окне
System::Void practical_work::edit_specific_field::обОкнеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	MessageBox::Show("Для редактирования определённой ячейкм, вам надо щёлкнуть по ней, ввести новую информацию в соотщетствующее поле и нажать кнопку Сохранить изменения","Об окне");
}
// вывод рейсов из базы данных при загрузке формы
System::Void practical_work::edit_specific_field::edit_specific_field_Shown(System::Object^  sender, System::EventArgs^  e)
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
void practical_work::edit_specific_field::Header()
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
void practical_work::edit_specific_field::Show()
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
// сохранить изменения
System::Void practical_work::edit_specific_field::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	int number_column = Convert::ToInt32(dataGridView->CurrentCellAddress.X), flag;

	flag = 0;
	if( new_info->Text == "" )
	{
		MessageBox::Show("Вы не ввели в соответствующее поле ту информацию, на которую хотите заменить имеющуюся в выбранной ячейке.","Ошибка");
	}
	else
	{
		if( number_column == 2 || number_column == 3 || number_column == 4 || number_column == 5 )
		{
			if( letter_entry_protection( Convert_String_to_char( new_info->Text ) ) )
			{
				MessageBox::Show("Новая информация, которую вы хотите ввести в выбранную ячейку, не должна содержать букв.","Ошибка");
				new_info->Text = "";
			}
			else
			{
				if( number_column == 2 )
				{
					if( strlen( Convert_String_to_char( new_info->Text ) ) != 10 || Convert_String_to_char( new_info->Text )[2] != '.' || Convert_String_to_char( new_info->Text )[5] != '.' )
					{
						MessageBox::Show("Поле даты отправления должно иметь вид (дд.мм.гггг).","Ошибка");
						new_info->Text = "";
					}
					else
					{
						flag = 1;
						dataGridView->CurrentCell->Value = new_info->Text;
						new_info->Text = "";
					}
				}
				else
				{
					flag = 1;
					dataGridView->CurrentCell->Value = new_info->Text;
					new_info->Text = "";
				}
			}
		}
		else
		{
			flag = 1;
			dataGridView->CurrentCell->Value = new_info->Text;
			new_info->Text = "";
		}
	}

	if( flag == 1 )
	{
		FILE *fptr;
		fptr = fopen("new_flight.txt","wt");
		if( fptr == NULL )
		{
			fclose(fptr);
			MessageBox::Show("Не удалось открыть файл new_flight.txt","Ошибка");
			this->Hide();
		}
		else
		{
			for( int i = 0; i < dataGridView->RowCount; i++ )
			{
				fprintf(fptr," %s ",Convert_String_to_char(dataGridView->Rows[i]->Cells[0]->Value->ToString()));
				fprintf(fptr," %s ",Convert_String_to_char(dataGridView->Rows[i]->Cells[1]->Value->ToString()));
				fprintf(fptr," %s ",Convert_String_to_char(dataGridView->Rows[i]->Cells[2]->Value->ToString()));
				fprintf(fptr," %s ",Convert_String_to_char(dataGridView->Rows[i]->Cells[3]->Value->ToString()));
				fprintf(fptr," %s ",Convert_String_to_char(dataGridView->Rows[i]->Cells[4]->Value->ToString()));
				fprintf(fptr," %s \n",Convert_String_to_char(dataGridView->Rows[i]->Cells[5]->Value->ToString()));
			}
			fclose(fptr);
			remove("flight_schedule.txt");
			rename("new_flight.txt","flight_schedule.txt");
		}
	}
}