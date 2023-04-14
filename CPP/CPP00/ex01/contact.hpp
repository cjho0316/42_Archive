#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <string>
/* Contact header file */
class Contact
{
	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phonenumber;
		std::string secret;
	
	public:
		Contact(void);
		~Contact(void);
		std::string GetFirstname(void);
		std::string GetLastname(void);
		std::string GetNickname(void);
		std::string GetPhonenumber(void);
		std::string GetSecret(void);
		
		void SetFirstname(std::string str);
		void SetLastname(std::string str);
		void SetNickname(std::string str);
		void SetPhonenumber(std::string str);
		void SetSecret(std::string str);
};

#endif