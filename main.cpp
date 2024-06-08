#include <iostream>
#include "vector_v.h"
#include "test_vector.h"

template<class V>
std::ostream& operator<<(std::ostream& out, const V & v) {
	out << v.dump(4);
	return out;
}


int main() {
	RunVectorDoubleTests();
	return 0;
}
