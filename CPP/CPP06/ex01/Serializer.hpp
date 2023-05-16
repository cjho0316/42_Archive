# ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <iostream>
#include <cstdint>
#include "Data.hpp"

class Serializer {
	private:
        /* OCF */
		Serializer();
		Serializer(const Serializer &copy);
		~Serializer();
		Serializer &operator=(const Serializer &copy);
	
	public:
		/* member functions */
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};


#endif
