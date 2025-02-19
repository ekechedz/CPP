#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer {
private:
	Serializer(void);
	Serializer(const Serializer &src);
	Serializer &operator=(const Serializer &src);
	~Serializer(void);

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialiacze(uintptr_t raw);
};

#endif
