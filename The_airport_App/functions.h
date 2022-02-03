#include <stdio.h>
#include <string.h>
#include <iostream>

#define SIZE 256

// защита от ввода букв
int letter_entry_protection(char string[]);

/* функции преобразования типов */

// из std::string в System::string^
System::String^ Convert_string_to_String(std::string& os, System::String^ s);

// из std::string в System::string^
System::String^ Convert_string_to_String(std::string& os);

// из System::String^ в char*
char* Convert_String_to_char(System::String^ string);

// из char* в System::String^
System::String^ Convert_char_to_String(char* ch);

// проверка города
int city_check(char input_town[],char end_simbol[]);
// поиск города
int city_search(char input_town[],char output_town[]);
// перевод заглавных букв в строчные
void from_uppercase_to_lowercase(char town[]);