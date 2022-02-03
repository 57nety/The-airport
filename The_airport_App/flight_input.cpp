#include "flight_input.h"
#include "functions.h"

// подключаю формы для перехода
#include "adding_flights.h"

// вернуться в ввод рейсов
System::Void practical_work::flight_input::вернутьсяВВводРейсовToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	adding_flights^ form = gcnew adding_flights();
	this->Hide();
	form->Show();
}
// выйти из программы
System::Void practical_work::flight_input::выйтиИзПрограммыToolStripMenuItem_Click_1(System::Object^  sender, System::EventArgs^  e)
{
	Application::Exit();
}
// информация об окне
System::Void practical_work::flight_input::обОкнеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	MessageBox::Show("В данном режиме ввода рейсов, вы заполняете базу данных с начала, то есть вы удаляете свою старую базу данных и вводите новую.Если вы хотите добавить рейсов к существующей базе данных, тогда сделайте так: Меню администратора -> Редактирование имеющихся рейсов -> Добавить определённое число рейсов. Заполните все поля и нажмите добавить рейс для того, чтобы добавить его в БД. Формат ввода полей: номер рейса, пункт назначения - набор символов, дата - дд.мм.гггг, время,число пассажирских мест,цена за билет - только цифры и символы(.или:). Во вкладке ВЫХОД вы можите вернуться в Меню адмнистратора или Выйти из программы.","Об окне");
}
// дата отправления
System::Void practical_work::flight_input::departure_date_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if( letter_entry_protection( Convert_String_to_char( departure_date->Text ) ) )
	{
		MessageBox::Show("Поле даты отправления не должно содержать букв.","Ошибка");
		departure_date->Text = "";
	}
}
// время отправления
System::Void practical_work::flight_input::departure_time_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if( letter_entry_protection( Convert_String_to_char( departure_time->Text ) ) )
	{
		MessageBox::Show("Поле времени отправления не должно содержать букв.","Ошибка");
		departure_time->Text = "";
	}
}
// общее количество мест
System::Void practical_work::flight_input::total_number_of_seats_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if( letter_entry_protection( Convert_String_to_char( total_number_of_seats->Text ) ) )
	{
		MessageBox::Show("Поле общего числа посадочных мест не должно содержать букв.","Ошибка");
		total_number_of_seats->Text = "";
	}
}
// цена за билет
System::Void practical_work::flight_input::ticket_price_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if( letter_entry_protection( Convert_String_to_char( ticket_price->Text ) ) )
	{
		MessageBox::Show("Поле цены за билет не должно содержать букв.","Ошибка");
		ticket_price->Text = "";
	}
}
// добавить рейс
System::Void practical_work::flight_input::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	FILE *fptr;
	if( strlen( Convert_String_to_char( flight_number->Text ) ) == 0 || strlen( Convert_String_to_char( destination->Text ) ) == 0 || strlen( Convert_String_to_char( departure_date->Text ) ) == 0 || strlen( Convert_String_to_char( departure_time->Text ) ) == 0 || strlen( Convert_String_to_char( total_number_of_seats->Text ) ) == 0 || strlen( Convert_String_to_char( ticket_price->Text ) ) == 0 )
	{
		MessageBox::Show("Для того, чтобы добавить рейс в базу данных, вы должны заполнить все поля.","Ошибка");
	}
	else
	{
		if( strlen( Convert_String_to_char( departure_date->Text ) ) != 10 || Convert_String_to_char( departure_date->Text )[2] != '.' || Convert_String_to_char( departure_date->Text )[5] != '.' )
		{
			MessageBox::Show("Поле даты отправления должно иметь вид (дд.мм.гггг).","Ошибка");
			departure_date->Text = "";
		}
		else
		{
			fptr = fopen("flight_schedule.txt","at");
			if( fptr == NULL)
			{
				fclose(fptr);
				MessageBox::Show("Не удалось открыть файл flight_schedule.txt.","Ошибка");
				this->Hide(); // закрытие формы
			}
			else
			{
				fprintf(fptr," %s %s %s %s %s %s \n",Convert_String_to_char(flight_number->Text),Convert_String_to_char(destination->Text),Convert_String_to_char(departure_date->Text),Convert_String_to_char(departure_time->Text),Convert_String_to_char(total_number_of_seats->Text),Convert_String_to_char(ticket_price->Text));
				fclose(fptr);
				flight_number->Text = "";
				destination->Text = "";
				departure_date->Text = "";
				departure_time->Text = "";
				total_number_of_seats->Text = "";
				ticket_price->Text = "";
				MessageBox::Show("Рейс успешно добавлен в базу данных (в файл flight_schedule.txt).","Добавление рейса");
			}
		}
	}
}