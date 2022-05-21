#include <iostream>   //ADD SEARCH EXIT
#include <string>

class Contact
{
	public:
	std::string name;
	std::string lastName;
	std::string nickname;
	std::string dark;
	int num;
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

};


int main()
{
	PhoneBook book;
	Contact contact;
	while(100)
	{
		std::string command;
		std::cin >> command;
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
			
		}
		else if (command == "EXIT")
		{
			break ;
		}
		
	}
return (0);	
}