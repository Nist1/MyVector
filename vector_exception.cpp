#include "vector_exception.h"

std::string VectorNegativeSize::what() const {
	std::string errMsg = "Bad vector size = ";
	errMsg += std::to_string(size);
	return errMsg;
}

std::string VectorBiggerThanBuffer::what() const {
	std::string errMsg = "Bad vector size = ";
	errMsg += std::to_string(size);
	return errMsg;
}

std::string VectorNegativeIndex::what() const {
	std::string errMsg = "Bad vector index = ";
	errMsg += std::to_string(index);
	return errMsg;
}

std::string VectorIndexBiggerThanSize::what() const {
	std::string errMsg = "Bad vector index = ";
	errMsg += std::to_string(index);
	return errMsg;
}
