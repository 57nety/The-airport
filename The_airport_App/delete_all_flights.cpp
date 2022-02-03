#include "delete_all_flights.h"
#include "functions.h"

// об окне
System::Void practical_work::delete_all_flights::обОкнеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	MessageBox::Show("Если вы хотите удалить все рейсы из базы данных, то введите пароль от режима администратора, и нажмите кнопку Удалить все рейсы. Если вы передумали это делать, то вы можите нажать кнопку отмена, или просто закрыть окно, нажав на крестик.","Об окне");
}
// удалить все рейсы
System::Void practical_work::delete_all_flights::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	char pas[256] = {};
	FILE *fptr;
    fptr = fopen("password.txt","at");
	if( fptr == NULL)
	{
		MessageBox::Show("Не удалось открыть файл password.txt.","Ошибка");
		fclose(fptr);
		Application::Exit(); // закрытие формы
	}
	else
	{
		fclose(fptr);
		fptr = fopen("password.txt","r");
		if( fptr == NULL)
		{
			MessageBox::Show("Не удалось открыть файл password.txt.","Ошибка");
			fclose(fptr);
			Application::Exit(); // закрытие формы
		}
		else
		{
			rewind(fptr);
			fscanf(fptr,"%s", &pas);
			fclose(fptr);
		}
	}
	if( strcmp(pas,Convert_String_to_char(password->Text)) == 0 )
	{
		fptr = fopen("flight_schedule.txt","wt");
		if( fptr == NULL)
		{
			MessageBox::Show("Не удалось открыть файл flight_schedule.txt.","Ошибка");
			fclose(fptr);
			Application::Exit(); // закрытие формы
		}
		else
		{
			fclose(fptr);
		}
		password->Text = "";
		MessageBox::Show("Вы удалили все рейсы из базы данных.","Удаление всех рейсов");
		this->Hide();
	}
	else
	{
		password->Text = "";
		MessageBox::Show("Вы ввели не правильный пароль!","Ошибка");
	}
}
// отмена
System::Void practical_work::delete_all_flights::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Hide();
}