#include <iostream>   //ADD SEARCH EXIT
#include <string>
#include <iomanip>
#include <limits>

class Contact
{
	public:
	std::string name;
	std::string lastName;
	std::string nickname;
	std::string dark;
	std::string num;
};

class PhoneBook
{
	public: 
	Contact contacts[8];
	int i;
	void addContact(Contact contact)
	{
		contacts[i] = contact;
		i = (i + 1) % 8;	
	}
	PhoneBook()
	{
		i = 0;
	}
	void tabl()
	{
		int c;
		int index;
		for (c = 0; c < i; c++)
		{	
			std::cout << c << "|" << std::setw(10) << contacts[c].name;
			std::cout <<  "|" << std::setw(10) << contacts[c].lastName;
			std::cout <<  "|" << std::setw(10) << contacts[c].nickname;
			std::cout <<  "|" << std::setw(10) << contacts[c].dark << std::endl;
			

		}
		std::cin >> index;
		if (index < 0 && index > 7)
		{
			std::cerr << "ERROR INDEX" << std::endl;
		}
		else
		{
			std::cout << contacts[c].name << std::endl;
			std::cout << contacts[c].lastName << std::endl;
			std::cout << contacts[c].nickname << std::endl;
			std::cout << contacts[c].dark << std::endl;
		}
	}

};

/* 
** Написать функцию которая считает количество символов 
** она возвращает строку которая урезана и вместо последнего символа стои точка. при условии что их больше 10,
** И функция которая принимает строку и изменяет ее.
** что бы найти кол-во символов нужно использовать .size()
*/ 


int main()
{
	PhoneBook book;
	Contact contact;
	while(100)
	{
		std::string command;
		std::cin >> command;
		std::cout << command << std::endl;
		if(command == "ADD" || command == "add")
		{
			std::cout << "NAME?" << std::endl;
			std::cin >> contact.name;
			std::cout << "LAST_NAME?" << std::endl;
			std::cin >> contact.lastName;
			std::cout << "NICKNAME?" << std::endl;
			std::cin >> contact.nickname;
			std::cout << "DARK?" << std::endl;
			std::cin >> contact.dark;
			std::cout << "PHONE_NUMBER?" << std::endl;
			std::cin >> contact.num;
			book.addContact(contact);
		}
		else if (command == "SEARCH")
		{
			book.tabl();			
		}
		else if (command == "EXIT")
		{
			break ;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
return (0);	
}