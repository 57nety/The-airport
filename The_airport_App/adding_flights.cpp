#include "adding_flights.h"
#include "functions.h"

// подключаю формы для перехода
#include "admin_menu.h"
#include "flight_input.h"
#include "delete_all_flights.h"

// вернуться в меню администратора
System::Void practical_work::adding_flights::вернутьсяВМенюАдминистратораToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	admin_menu^ form = gcnew admin_menu();
	this->Hide();
	form->Show();
}
// выйти из программы
System::Void practical_work::adding_flights::выйтиИзПрограммыToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	Application::Exit();
}
// об окне
System::Void practical_work::adding_flights::обОкнеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	MessageBox::Show("В этом окне вы можите добавить рейсы к существующим, или удалить все рейсы из базы данных (для этого надо знать пароль от режима администратора), и заполнить базу данных заново. Так же вы можите вернуться в Меню администратора, или выйти из программы.","Об окне");
}
// добавить рейсы
System::Void practical_work::adding_flights::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	flight_input^ form = gcnew flight_input();
	this->Hide();
	form->Show();
}
// удалить все рейсы
System::Void practical_work::adding_flights::button2_Click(System::Object^  sender, System::EventArgs^  e)
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
				delete_all_flights^ form = gcnew delete_all_flights();
				form->ShowDialog();
			}
		}
	}
}