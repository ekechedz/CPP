#include "Serializer.hpp"
#include <iostream>

int main() {
	Data data = {"Example", 42};

	uintptr_t raw = Serializer::serialize(&data);
	Data* deserializedData = Serializer::deserialiacze(raw);

	std::cout << "Original Data Address: " << &data << "\n";
	std::cout << "Serialized Value: " << raw << "\n";
	std::cout << "Deserialized Data Address: " << deserializedData << "\n";

	if (deserializedData == &data) {
		std::cout << "Success: Data correctly serialized and deserialized!\n";
	} else {
		std::cout << "Error: Data mismatch!\n";
	}

	uintptr_t invalidRaw = raw + 100;
	Data* wrongData = Serializer::deserialiacze(invalidRaw);

	std::cout << "\nWrong Example:" << "\n";
	std::cout << "Invalid Serialized Value: " << invalidRaw << "\n";
	std::cout << "Deserialized Invalid Data Address: " << wrongData << "\n";

	if (wrongData == &data) {
		std::cout << "Unexpected Success: This should not happen!\n";
	} else {
		std::cout << "Correctly detected invalid deserialization!\n";
	}

	return 0;
}
