#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "contact.hpp"
/* PhoneBook header file */
class PhoneBook
{
	private:
		Contact phonelist[8];
		int idx;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		
		int GetIdx(void);
		void SetIdx(int idx);

		void Search(void);
		void Add(void);
};

#endif