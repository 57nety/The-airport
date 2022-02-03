#include "edit_type_selection.h"

// подключаю формы дл€ перехода
#include "admin_menu.h"
#include "edit_specific_field.h"
#include "delete_a_specific_flight.h"

// вернутьс€ в меню администратора
System::Void practical_work::edit_type_selection::вернуть¬ћенюјдминистратораToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	admin_menu^ form = gcnew admin_menu();
	this->Hide();
	form->Show();
}
// выйти из программы
System::Void practical_work::edit_type_selection::выйти»зѕрограммыToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	Application::Exit();
}
// об окне
System::Void practical_work::edit_type_selection::обќкнеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	MessageBox::Show("¬ данном окне вы можите выбрать то действие, которое вы хотите сделать с базой данных.“акже вы можите вернутьс€ в ћеню администратора, или выйти из программы.","ќб окне");
}
// редактировать определЄнное поле в рейсе
System::Void practical_work::edit_type_selection::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	edit_specific_field^ form = gcnew edit_specific_field();
	this->Hide();
	form->Show();
}
// удалить определЄнный рейс
System::Void practical_work::edit_type_selection::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	delete_a_specific_flight^ form = gcnew delete_a_specific_flight();
	this->Hide();
	form->Show();
}