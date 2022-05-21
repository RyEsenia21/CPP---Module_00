#include <iostream>
char *returnStr(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
	}
	return (str);
}

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}	
	int i;

	for (i = 1; i < argc; i++)
	{
		returnStr(argv[i]);
		std::cout << argv[i] << std::endl;
	}


	return (0);
}
/*
** std это пространство имен (для того что бы одноименные функции не путались)
** cout - поток вывода (как printf) универсальный и он автоматически опредяет тип данных
** cin - поток ввода (как scanf) универсальный
** :: - синтаксис, указывает принадлежность к пространству имен или классу.
** << - (оператор) манипулятор потока
** >> - используется для cin ввода информации (из файла или стандартного потока ввода)
** endl - это "\n"
*/