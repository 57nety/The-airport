#include "user_choice.h"

// подключаю формы дл€ перехода
#include "administrator_identification.h"
#include "visitor_menu.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	practical_work::user_choice form;
	Application::Run(%form);
}
// выйти из программы
System::Void practical_work::user_choice::выйти»зѕрограммыToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	Application::Exit(); // закрытие формы
}
// информаци€ об окне
System::Void practical_work::user_choice::обќкнеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	MessageBox::Show("ƒл€ работы с программой вам надо выбрать пользовател€, в режиме которого вы хотите войти в программу. –ежим администратора позвол€ет вам редактировать список рейсов. –ежим пользовател€ позвол€ет вам только ознакомитьс€ с имеющимс€ списком рейсов, а так же сыграть в игру.","ќб окне");
}
// перейти в режим администратора
System::Void practical_work::user_choice::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	administrator_identification^ form = gcnew administrator_identification(); // создаю новую форму
	this->Hide(); // закрываю текущую форму
	form->Show(); // показываю созданную форму
}
// перейти в режим посетител€
System::Void practical_work::user_choice::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	visitor_menu^ form = gcnew visitor_menu();
	this->Hide();
	form->Show();
}