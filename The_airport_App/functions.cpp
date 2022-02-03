#include "functions.h"

// защита от ввода букв
int letter_entry_protection(char string[])
{
    int    x = 0,   // длинна полученной строки
          ok = 0;   // возвращаемое значение
    x = strlen(string);
    ok = 0;
    for( int i = 0; i < x; i++ )
        if( string[i] < 46 || string[i] > 58 || string[i] == 47 )
        {
            ok = 1;
            break;
        }
    return ok;
}

/* функции преобразовани€ типов */

// из std::string в System::string^
System::String^ Convert_string_to_String(std::string& os, System::String^ s)
{
	s = gcnew System::String(os.c_str());

	return s;
}

// из std::string в System::string^
System::String^ Convert_string_to_String(std::string& os)
{
	System::String^ s = gcnew System::String(os.c_str());

	return s;
}

// из System::String^ в char*
char* Convert_String_to_char(System::String^ string)
{
	using namespace System::Runtime::InteropServices;

	return (char*)(void*)Marshal::StringToHGlobalAnsi(string);
}

// из char* в System::String^
System::String^ Convert_char_to_String(char* ch)
{
	char* chr = new char();
	chr = ch;
	System::String^ str;
	for( int i = 0; chr[i] != '\0'; i++ )
	{
		str += wchar_t(ch[i]);
	}

	return str;
}

// проверка города
int city_check(char input_town[],char end_simbol[])
{
	FILE *fptr, *t_fptr;
	char use_town[SIZE] = {}, town_file[SIZE] = {};
	int flag;

	from_uppercase_to_lowercase(input_town);

	fptr = fopen("cities.txt","rt");
	if( fptr == NULL )
	{
		fclose(fptr);
		return -1;
	}

	flag = 0;

	rewind(fptr);
	while( fscanf(fptr,"%s",town_file) != EOF )
	{
		from_uppercase_to_lowercase(town_file);
		if( strcmp(input_town,town_file) == 0 )
		{
			flag = 1;
			if( end_simbol[1] != 0 )
			{
				if( end_simbol[1] == input_town[0] )
				{
					t_fptr = fopen("use_town.txt","rt");
					if( t_fptr == NULL )
					{
						fclose(t_fptr);
						fclose(fptr);
						return -2;
					}
					else
					{
						rewind(t_fptr);
						while( fscanf(t_fptr,"%s",use_town) != EOF )
						{
							from_uppercase_to_lowercase(use_town);
							if( strcmp(input_town,use_town) == 0 )
							{
								fclose(t_fptr);
								fclose(fptr);
								return -4;
							}
						}
						fclose(t_fptr);
						t_fptr = fopen("use_town.txt","at");
						if( t_fptr == NULL )
						{
							fclose(t_fptr);
							fclose(fptr);
							return -2;
						}
						else
						{
							fprintf(t_fptr,"%s ", input_town);
							fclose(t_fptr);
							fclose(fptr);
							return 0;
						}
					}
				}
				else
				{
					fclose(fptr);
					return -3;
				}
			}
			else
			{
				t_fptr = fopen("use_town.txt","at");
				if( t_fptr == NULL )
				{
					fclose(t_fptr);
					fclose(fptr);
					return -2;
				}
				else
				{
					fprintf(t_fptr,"%s ", input_town);
					fclose(t_fptr);
					fclose(fptr);
					return 0;
				}
			}	
		}
	}

	if( flag == 0 )
	{
		return -5;
	}

}
// поиск города
int city_search(char input_town[],char output_town[])
{
	FILE *fptr, *t_fptr;
	char extreme_character = input_town[strlen(input_town)-1], use_town[SIZE] = {}, town_file[SIZE] = {};
	int flag;

	
	fptr = fopen("cities.txt","rt");
	if( fptr == NULL )
	{
		fclose(fptr);
		return -1;
	}

	t_fptr = fopen("use_town.txt","rt");
	if( t_fptr == NULL )
	{
		fclose(fptr);
		fclose(t_fptr);
		return -2;
	}

	rewind(fptr);
	while( fscanf(fptr,"%s",town_file) != EOF )
	{
		from_uppercase_to_lowercase(town_file);
		flag = 0;
		rewind(t_fptr);
		while( fscanf(t_fptr,"%s",use_town) != EOF )
		{
			from_uppercase_to_lowercase(use_town);
			if( strcmp(town_file,use_town) == 0 )
			{
				flag = 1;
			}
		}
		if( flag == 0 )
		{
			if( extreme_character == town_file[0] )
			{
				fclose(t_fptr);
				t_fptr = fopen("use_town.txt","at");
				if( t_fptr == NULL )
				{
					fclose(t_fptr);
					fclose(fptr);
					return -2;
				}
				else
				{
					strcpy(output_town,town_file);
					fprintf(t_fptr,"%s ", output_town);
					fclose(t_fptr);
					fclose(fptr);
					output_town[0] = output_town[0] - 32;
					return 0;
				}
			}
		}
	}

	fclose(t_fptr);
	fclose(fptr);
	return 1;
}
// перевод заглавных букв в строчные
void from_uppercase_to_lowercase(char town[])
{
	int x = strlen(town);
	for( int i = 0; i < x; i++ )
		for( char j = 'ј'; j < 'я'+1; j++ )
			if( town[i] == j )
				town[i] = j + 32;
}