#include "admin_menu.h"
#include "functions.h"

// подключаю формы для перехода
#include "user_choice.h"
#include "adding_flights.h"
#include "edit_type_selection.h"
#include "flight_output.h"
#include "flight_output_on_request.h"
#include "сhange_password.h"

// вернуться в выбор пользователя
System::Void practical_work::admin_menu::вернутьсяВВыборПользователяToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	user_choice^ form = gcnew user_choice();
	this->Hide();
	form->Show();
}
// выйти из программы
System::Void practical_work::admin_menu::выйтиИзПрограммыToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	Application::Exit();
}
// информация об окне
System::Void practical_work::admin_menu::обОкнеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	MessageBox::Show("Вы в режиме администратора. Выберите действие, которое хотите сделать, или вы можите во вкладке ВЫХОД вернуться в Выбор пользователя, или закрыть программу.","Об окне");
}
// ввод рейсов
System::Void practical_work::admin_menu::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	adding_flights^ form = gcnew adding_flights();
	this->Hide();
	form->Show();
}
// редактирование имеющихся рейсов
System::Void practical_work::admin_menu::button2_Click(System::Object^  sender, System::EventArgs^  e)
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
			if( number_of_flights == 0 )
			{
				MessageBox::Show("Список рейсов пуст!","Ошибка");
			}
			else
			{
				edit_type_selection^ form = gcnew edit_type_selection();
				this->Hide();
				form->Show();
			}
		}
	}
}
// вывод имеющихся рейсов
System::Void practical_work::admin_menu::button3_Click(System::Object^  sender, System::EventArgs^  e)
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
			if( number_of_flights == 0 )
			{
				MessageBox::Show("Список рейсов пуст!","Ошибка");
			}
			else
			{
				flight_output^ form = gcnew flight_output();
				this->Hide();
				form->Show();
			}
		}
	}
}
// вывод рейсов по запросу
System::Void practical_work::admin_menu::button4_Click(System::Object^  sender, System::EventArgs^  e)
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
			if( number_of_flights == 0 )
			{
				MessageBox::Show("Список рейсов пуст!","Ошибка");
			}
			else
			{
				flight_output_on_request^ form = gcnew flight_output_on_request();
				this->Hide();
				form->Show();
			}
		}
	}
}
// сменить пароль
System::Void practical_work::admin_menu::button5_Click(System::Object^  sender, System::EventArgs^  e)
{
	сhange_password^ form = gcnew сhange_password();
	this->Hide();
	form->Show();
}