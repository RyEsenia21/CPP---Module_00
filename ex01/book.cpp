/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   book.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryesenia <ryesenia@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:34:23 by ryesenia          #+#    #+#             */
/*   Updated: 2022/06/11 18:52:23 by ryesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RED "\033[38;05;203m"
# define GREEN "\033[38;05;84m"
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

class Contact
{
	public:
	void setName(std::string name);
	void setLName(std::string lname);
	void setNName(std::string nname);
	void setDark(std::string dark);
	void setPhone(std::string num);

	std::string getName();
	std::string getLName();
	std::string getNName();
	std::string getDark();
	std::string getPhone();

	private:
	std::string name;
	std::string lastName;
	std::string nickname;
	std::string dark;
	std::string num;
};

void Contact::setName(std::string name){this->name = name;}
void Contact::setLName(std::string lname){this->lastName = lname;}
void Contact::setNName(std::string nname){this->nickname = nname;}
void Contact::setDark(std::string dark){this->dark = dark;}
void Contact::setPhone(std::string num){this->num = num;}

std::string Contact::getName(){return this->name;}
std::string Contact::getLName(){return this->lastName;}
std::string Contact::getNName(){return this->nickname;}
std::string Contact::getDark(){return this->dark;}
std::string Contact::getPhone(){return this->num;}

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

std::string check(std::string stroka)
{
	stroka.size();
	if (stroka.size() >= 10)
	{
		stroka.erase(10);
		stroka[9] = '.';
	}
	return (stroka);
} 

	void tabl()
	{
		int c;
		int index;
		for (c = 0; c < i; c++)
		{	
			std::cout << c << "|" << std::setw(10) << check(contacts[c].getName());
			std::cout <<  "|" << std::setw(10) << check(contacts[c].getLName());
			std::cout <<  "|" << std::setw(10) << check(contacts[c].getNName());
			std::cout <<  "|" << std::setw(10) << check(contacts[c].getDark()) << std::endl;
			

		}
		std::cin >> index;
		if (index < 0 && index > 7)
		{
			std::cerr << "ERROR INDEX" << std::endl;
		}
		else
		{
			std::cout << contacts[c].getName() << std::endl;
			std::cout << contacts[c].getLName() << std::endl;
			std::cout << contacts[c].getNName() << std::endl;
			std::cout << contacts[c].getDark() << std::endl;
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
	
	std::string command;
	std::cout << RED"ПРИВЕТ ДОБРО ПОЖАЛОВАТЬ В ТВОЮ ТЕЛЕФОННУЮ КНИГУ !!!" << std::endl;

	while(command != "EXIT" || command != "exit")
	{
		std::cout << "ВВЕДИТЕ КОММАНДУ: ADD | SEASRCH | EXIT" << std::endl;
		std::cin >> command;
		if(command == "ADD" || command == "add")
		{
			std::string n;
			std::cout << "ENTER YOUR NAME ?" << std::endl;
			std::cin >> n;
			contact.setName(n);
			std::cout << "ENTER YOUR LAST_NAME ?" << std::endl;
			std::cin >> n;
			contact.setLName(n);
			std::cout << "ENTER YOUR NICKNAME ?" << std::endl;
			std::cin >> n;
			contact.setNName(n);
			std::cout << "ENTER YOUR DARK ?" << std::endl;
			std::cin >> n;
			contact.setDark(n);
			std::cout << "ENTER YOUR PHONE_NUMBER ?" << std::endl;
			std::cin >> n;
			contact.setPhone(n);
			book.addContact(contact);
			std::cout << "НОВЫЙ КОНТАКТ ДОБАВЛЕН" << std::endl;
			
		}
		else if (command == "SEARCH" || command == "search")
		{
			int i;
			book.tabl();
			std::cout << "НАЙДИ ДРУГА :)))" << std::endl;
			std::cin >> i;
			std::cout << "First name:     " << book.contacts[i].getName() << std::endl;
    		std::cout << "Last name:      " << book.contacts[i].getLName() << std::endl;
    		std::cout << "Nickname:       " << book.contacts[i].getNName() << std::endl;
    		std::cout << "Phone number:   " << book.contacts[i].getPhone() << std::endl;
    		std::cout << "Darkest secret: " << book.contacts[i].getDark() << std::endl;
		}
		else if (command == "EXIT" || command == "exit")
		{
			break ;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
return (0);	
}