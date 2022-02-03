#include "administrator_identification.h"
#include <string.h>
#include <iostream>
#include "functions.h"

// подключаю формы для перехода
#include "user_choice.h"
#include "admin_menu.h"

// вернуться в выбор пользователя
System::Void practical_work::administrator_identification::вернутьсяВВыборПользователяToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	user_choice^ form = gcnew user_choice();
	this->Hide();
	form->Show();
}
// выйти из программы
System::Void practical_work::administrator_identification::выйтиИзПрограммыToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	Application::Exit(); // закрытие формы
}
// информация об окне
System::Void practical_work::administrator_identification::обОкнеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	MessageBox::Show("Для того, что бы войти в режим администратора, вам надо ввести правильный пароль (по умолчанию это 0000). Во вкладе ВЫХОД вы можите закрыть программу, или вернуться в Выбор пользователя.","Об окне");
}
// вход в режим администратора
System::Void practical_work::administrator_identification::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	char pas[256] = {};
	FILE *fptr;
    fptr = fopen("password.txt","at");
	if( fptr == NULL)
	{
		MessageBox::Show("Не удалось открыть файл password.txt.","Ошибка");
		fclose(fptr);
		this->Hide(); // закрытие формы
	}
	else
	{
		fclose(fptr);
		fptr = fopen("password.txt","r");
		if( fptr == NULL)
		{
			MessageBox::Show("Не удалось открыть файл password.txt.","Ошибка");
			fclose(fptr);
			this->Hide(); // закрытие формы
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
		admin_menu^ form = gcnew admin_menu();
		this->Hide();
		form->Show();
	}
	else
	{
		password->Text = "";
		MessageBox::Show("Вы ввели не правильный пароль!","Ошибка");
	}
}