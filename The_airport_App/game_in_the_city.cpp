#include "game_in_the_city.h"
#include "functions.h"


// подключаю формы для перехода
#include "visitor_menu.h"

// вернуться в меню посетителя
System::Void practical_work::game_in_the_city::вернутьсяВВыборНомераИгрокаToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	FILE *fptr;
	fptr = fopen("use_town.txt","wt");
	if( fptr == NULL )
	{
		fclose(fptr);
		this->Hide();
		MessageBox::Show("Не удалось открыть файл use_town.txt! Программа закончила свою работу.","Ошибка");
	}
	else
	{
		fclose(fptr);
		remove("use_town.txt");
		visitor_menu^ form = gcnew visitor_menu();
		this->Hide();
		form->Show();
	}
}
// выйти из программы
System::Void practical_work::game_in_the_city::выйтиИзПрограммыToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	FILE *fptr;
	fptr = fopen("use_town.txt","wt");
	if( fptr == NULL )
	{
		fclose(fptr);
		this->Hide();
		MessageBox::Show("Не удалось открыть файл use_town.txt! Программа закончила свою работу.","Ошибка");
	}
	else
	{
		fclose(fptr);
		remove("use_town.txt");
		Application::Exit();
	}
}
// об окне
System::Void practical_work::game_in_the_city::обОкнеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	MessageBox::Show("В окне \"Игра в города\" вы играете в города с компьютером, и являетесь первым игроком, то вам надо ввести название города из России, затем когда компьютер ответит вам, вам надо подобрать такое слово, которое бы начиналось на ту букву, на которую заканчивается название города, названное компьютером. Затем нажать на кнопку Ответить. Также вы можите вернуться в онко Выбора номера игрока или выйти из программы.","Об окне");
}
// сдаться
System::Void practical_work::game_in_the_city::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	FILE *fptr;
	fptr = fopen("use_town.txt","wt");
	if( fptr == NULL )
	{
		fclose(fptr);
		this->Hide();
		MessageBox::Show("Не удалось открыть файл use_town.txt! Программа закончила свою работу.","Ошибка");
	}
	else
	{
		fclose(fptr);
		remove("use_town.txt");
		visitor_menu^ form = gcnew visitor_menu();
		this->Hide();
		form->Show();
		MessageBox::Show("Так как вы сдались, значит ПОБЕДИЛ КОМПЬЮТЕР. Удачи вам в следующих играх.","Вы сдались!");
	}
}
// ответить
System::Void practical_work::game_in_the_city::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	char *input_town, *output_town;
	char use_town[SIZE] = {}, end_simbol[4] = {};
	int counter;

	end_simbol[0] = end_simbol[2] = '\'';
	end_simbol[3] = '\0';

	input_town = Convert_String_to_char(input->Text);
	output_town = Convert_String_to_char(output->Text);

	FILE *fptr;
	fptr = fopen("use_town.txt","at");
	if( fptr == NULL )
	{
		fclose(fptr);
		this->Hide();
		MessageBox::Show("Не удалось открыть файл use_town.txt! Программа закончила свою работу.","Ошибка");
	}
	fclose(fptr);
	fptr = fopen("use_town.txt","rt");
	if( fptr == NULL )
	{
		fclose(fptr);
		this->Hide();
		MessageBox::Show("Не удалось открыть файл use_town.txt! Программа закончила свою работу.","Ошибка");
	}
	else
	{
		counter = 0;
		while( fscanf(fptr,"%s",use_town) != EOF )
			counter++;
		fclose(fptr);
	}

	if( input->Text == "" && counter == 0 )
	{
		info->Text = "Введите название любого Российского города";
	}
	else if( input->Text == "" && counter != 0 )
	{
		end_simbol[1] = output_town[strlen(output_town)-1] - 32;
		info->Text = "Введите название любого Российского города, который ещё не использовался  на букву " + Convert_string_to_String((std::string)end_simbol);
	}
	else
	{
		if( strlen(output_town) > 0 )
			end_simbol[1] = output_town[strlen(output_town)-1];
		else
			end_simbol[1] = 0;

		switch(city_check(input_town,end_simbol))
		{
			case -5:
				input->Text = "";
				info->Text = "Я не знаю такого города в России";
				break;
			case -4:
				input->Text = "";
				info->Text = "Данный город уже использовался";
				break;
			case -3:
				input->Text = "";
				end_simbol[1] = end_simbol[1] - 32;
				info->Text = "Вы ввели название города не на букву " + Convert_string_to_String((std::string)end_simbol);
				break;
			case -2:
				this->Hide();
				MessageBox::Show("Не удалось открыть файл use_town.txt! Программа закончила свою работу.","Ошибка");
				break;
			case -1:
				this->Hide();
				MessageBox::Show("Не удалось открыть файл cities.txt! Программа закончила свою работу.","Ошибка");
				break;
			case  0:
				switch(city_search(input_town,output_town))
				{
					case -2:
						this->Hide();
						MessageBox::Show("Не удалось открыть файл use_town.txt! Программа закончила свою работу.","Ошибка");
						break;
					case -1:
						this->Hide();
						MessageBox::Show("Не удалось открыть файл cities.txt! Программа закончила свою работу.","Ошибка");
						break;
					case  0:
						input->Text = "";
						output->Text = Convert_string_to_String((std::string)output_town);
						end_simbol[1] = output_town[strlen(output_town)-1] - 32;
						info->Text = "Введите название любого Российского города, который ещё не использовался  на букву " + Convert_string_to_String((std::string)end_simbol);
						break;
					case  1:
						remove("use_town.txt");
						visitor_menu^ form = gcnew visitor_menu();
						this->Hide();
						form->Show();
						MessageBox::Show("Поздравляю ВЫ ПОБЕДИЛИ!","Победа");
						break;
				}
				break;
		}
	}
}
// первое отображение формы
System::Void practical_work::game_in_the_city::game_in_the_city_Shown(System::Object^  sender, System::EventArgs^  e)
{
	info->Text = "Введите название любого Российского города";
}