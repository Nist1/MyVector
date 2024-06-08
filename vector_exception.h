#pragma once

#include <string>


class VectorException {
	public:
		virtual std::string what() const = 0;
};

class VectorNegativeSize : public VectorException {
	public:
		VectorNegativeSize(int size_) : size(size_){}
		std::string what() const override;
	private:
		int size;
};	

class VectorBiggerThanBuffer : public VectorException {
	public:
		VectorBiggerThanBuffer(int size_) : size(size_){}
		std::string what() const override;
	private:
		int size;
};

class VectorNegativeIndex : public VectorException {
	public:
		VectorNegativeIndex(int index_) : index(index_){}
		std::string what() const override;
	private:
		int index;
};

class VectorIndexBiggerThanSize : public VectorException {
	public:
		VectorIndexBiggerThanSize(int index_) : index(index_){}
		std::string what() const override;
	private:
		int index;
};
