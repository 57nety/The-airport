#include "delete_a_specific_flight.h"
#include "functions.h"

// подключаю формы для перехода
#include "edit_type_selection.h"
#include "admin_menu.h"

// вернуться в Выбор типа редактирования
System::Void practical_work::delete_a_specific_flight::вернутьсяВToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	edit_type_selection^ form = gcnew edit_type_selection();
	this->Hide();
	form->Show();
}
// выйти из программы
System::Void practical_work::delete_a_specific_flight::выйтиИзПрограммыToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	Application::Exit();
}
// об окне
System::Void practical_work::delete_a_specific_flight::обОкнеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	MessageBox::Show("Для того, чтобы удалить поределённый рейс из базы данных, вам надо нажать на любую ячейку в строке, которую хотите удалить, а затем нажать на кнопку Удалить рейс.","Об окне");
}
// вывод рейсов при загрузке формы
System::Void practical_work::delete_a_specific_flight::delete_a_specific_flight_Shown(System::Object^  sender, System::EventArgs^  e)
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
void practical_work::delete_a_specific_flight::Header()
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
void practical_work::delete_a_specific_flight::Show()
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
// удалить рейс
System::Void practical_work::delete_a_specific_flight::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	FILE *fptr, *fp;
	char flight_number[SIZE] = {},destination[SIZE] = {},departure_date[SIZE] = {},departure_time[SIZE] = {},total_number_of_seats[SIZE] = {},ticket_price[SIZE] = {};
	int i, number_of_flights, index = Convert::ToInt32(dataGridView->CurrentCellAddress.Y);
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
			fp = fopen("new_flight.txt","wt");
			if( fptr == NULL)
			{
				fclose(fp);
				fclose(fptr);
				MessageBox::Show("Не удалось открыть файл new_flight.txt","Ошибка");
				this->Hide();
			}
			else
			{
				rewind(fptr);
				number_of_flights = 0;
				i = 0;
				while( fscanf(fptr,"%s%s%s%s%s%s", flight_number,destination,departure_date,departure_time,total_number_of_seats,ticket_price) != EOF )
				{
					if( i != index )
					{
						number_of_flights++;
						fprintf(fp," %s %s %s %s %s %s \n", flight_number,destination,departure_date,departure_time,total_number_of_seats,ticket_price);
					}
					i++;
				}
				fclose(fp);
				fclose(fptr);
				remove("flight_schedule.txt");
				rename("new_flight.txt","flight_schedule.txt");
			}
		}
	}

	if( number_of_flights > 0 )
	{
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
	else
	{
		// чистка строчек и столбцов
		dataGridView->Rows->Clear();
		dataGridView->Columns->Clear();

		// шапка таблицы рейсов
		Header();

		// выравнивание таблицы
		dataGridView->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		dataGridView->AutoResizeColumns();

		MessageBox::Show("Список рейсов пуст!","Внимание");
		admin_menu^ form = gcnew admin_menu();
		this->Hide();
		form->Show();
	}
}