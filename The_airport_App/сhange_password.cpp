#include "сhange_password.h"
#include "functions.h"

// формы для перехода
#include "admin_menu.h"

// сменить пароль
System::Void practical_work::сhange_password::button1_Click(System::Object^  sender, System::EventArgs^  e)
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
		fptr = fopen("password.txt","rt");
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

	if( strcmp(pas,Convert_String_to_char(old_pas->Text)) == 0 )
	{
		if( strlen(Convert_String_to_char(new_pas->Text)) > 0 && strlen(Convert_String_to_char(new_pas->Text)) < 201 )
		{
			fptr = fopen("password.txt","wt");
			if( fptr == NULL )
			{
				MessageBox::Show("Не удалось открыть файл password.txt.","Ошибка");
				fclose(fptr);
				Application::Exit(); // закрытие формы
			}
			else
			{
				rewind(fptr);
				fprintf(fptr,"%s", Convert_String_to_char(new_pas->Text));
				fclose(fptr);
				old_pas->Text = "";
				new_pas->Text = "";
				MessageBox::Show("Ваш пароль успешно сменен!.","Смена пароля");
			}
		}
		else
		{
			old_pas->Text = "";
			new_pas->Text = "";
			MessageBox::Show("Вы ввели новый пароль не допустимого размера. Он должен быть   ( > 0 или <= 200 ) символов.","Ошибка");
		}
	}
	else
	{
		old_pas->Text = "";
		new_pas->Text = "";
		MessageBox::Show("Вы ввели не правильный старый пароль!","Ошибка");
	}
}
// вернуться в меню администратора
System::Void practical_work::сhange_password::вернутьсяВМенюАдминистратораToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	admin_menu^ form = gcnew admin_menu();
	this->Hide();
	form->Show();
}
// выйти из программы
System::Void practical_work::сhange_password::выйтиИзПрограммыToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	Application::Exit();
}
// об окне
System::Void practical_work::сhange_password::обОкнеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	MessageBox::Show("В этом окне вы можите сменить пароль для входа в режим администратора, для это вам надо ввести старый пароль администратора, а затем новый пароль, он должен быть ( > 0 или <= 200 ) символов.","Об окне");
}