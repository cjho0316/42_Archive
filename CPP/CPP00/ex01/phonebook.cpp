#include "phonebook.hpp"
#include "contact.hpp"
#include <iomanip>

/* phonelist table*/
//1. check data is valid (not null) -> setter function prevention

//2.1 check if sentence length is more than 10char
//2.2 if yes replace last word into '.'

//3. append in phonelist
PhoneBook::PhoneBook(void){
	this->idx = 0;
}

PhoneBook::~PhoneBook(void){}

int PhoneBook::GetIdx(void){
	return this->idx;
}

void PhoneBook::SetIdx(int idx){
	this->idx = idx;
}

void PhoneBook::Search(void)
{
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;

	for (int i = 0; i < GetIdx(); i++)
	{
		std::cout << "|" << std::setfill(' ') << std::setw(10) << (i + 1) << "|";
		std::cout << std::setfill(' ') << std::setw(10) << phonelist[i].GetFirstname() << "|";
		std::cout << std::setfill(' ') << std::setw(10) << phonelist[i].GetLastname() << "|";
		std::cout << std::setfill(' ') << std::setw(10) << phonelist[i].GetNickname() << "|";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void PhoneBook::Add(void)
{
	/* initialize member stuff */
	Contact contact;
	std::string str;
	
	int index = GetIdx();

	std::cout << "[------- Please fill out below informations -------]" << std::endl;
	std::cout << "1. What is your first name?" << std::endl;
	std::getline(std::cin, str);
	contact.SetFirstname(str);
	
	std::cout << "2. What is your last name?" << std::endl;
	std::getline(std::cin, str);
	contact.SetLastname(str);

	std::cout << "3. What is your nickname?" << std::endl;
	std::getline(std::cin, str);
	contact.SetNickname(str);

	std::cout << "4. What is your phone number?" << std::endl;
	std::getline(std::cin, str);
	contact.SetPhonenumber(str);

	std::cout << "5. What is your darkest secret?" << std::endl;
	std::getline(std::cin, str);
	contact.SetSecret(str);

	// go back to first and push it back / else just append
	if (idx == 8)
	{
		for (int i = 1; i < 8; i++)
			this->phonelist[i - 1] = this->phonelist[i];
		this->phonelist[index - 1] = contact;
	}
	else
	{
		this->phonelist[index] = contact;
		SetIdx(index + 1);
	}
}
