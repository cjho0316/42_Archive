#include "contact.hpp"
#include <string>

/* Contact cpp file */
Contact::Contact(void){}

std::string Contact::GetFirstname(void) {
	return this->firstname;
}

std::string Contact::GetLastname(void) {
	return this->lastname;
}

std::string Contact::GetNickname(void) {
	return this->nickname;
}

std::string Contact::GetPhonenumber(void) {
	return this->phonenumber;
}

std::string Contact::GetSecret(void) {	
	return this->secret;
}

void Contact::SetFirstname(std::string str) {
	if (str.length() > 9 && str.length() != 0)
	{
		str.replace(9, 1, ".");
		str = str.substr(0, 10);
	}
	this->firstname = str;
}

void Contact::SetLastname(std::string str) {
	if (str.length() > 9 && str.length() != 0)
	{
		str.replace(9, 1, ".");
		str = str.substr(0, 10);
	}
	this->lastname = str;
}

void Contact::SetNickname(std::string str) {
	if (str.length() > 9 && str.length() != 0)
	{
		str.replace(9, 1, ".");
		str = str.substr(0, 10);
	}
	this->nickname = str;
}

void Contact::SetPhonenumber(std::string str) {
	if (str.length() > 9 && str.length() != 0)
	{
		str.replace(9, 1, ".");
		str = str.substr(0, 10);
	}
	this->phonenumber = str;
}

void Contact::SetSecret(std::string str) {
	if (str.length() > 9 && str.length() != 0)
	{
		str.replace(9, 1, ".");
		str = str.substr(0, 10);
	}
	this->secret = str;
}

Contact::~Contact(void){}