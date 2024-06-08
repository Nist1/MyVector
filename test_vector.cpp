#include "vector_v.h"
#include "vector_exception.h"
#include <iostream> 
#include <cmath>

using namespace std;

#define EXPECT_EQUAL(expected, actual)\
	if (expected == actual.dump(4)) {\
		OkMsg();\
	} else ErrorMsg(expected, actual.dump(4));
	
#define EXPECT_NEAR(expected, actual, precision)\
	if (fabs(expected - actual) < precision) {\
		OkMsg();\
	} else ErrorMsg(expected, actual);
	
#define EXPECT_THROW(expected, actual)\
	bool res = false;\
	try {\
		actual;\
	}\
	catch (expected e) {\
		res = true;\
		cout << e.what() << endl;\
	}\
	cout << (res ? "OK\n" : "FAILED\n");

void OkMsg() {
	cout << "OK \n";
}

void ErrorMsg(string expected, string actual) {
	cout << "FAILED\n" << "\texpected: " << expected << '\n' << "\tactual: " << actual << '\n';
}

void ErrorMsg(double expected, double actual) {
	cout << "FAILED\n" << "\texpected: " << expected << '\n' << "\tactual: " << actual << '\n';
}

void TestVectorDoubleConstructNormal() {
	cout << "Running TestVectorDoubleConstructNormal \n";
	Vector<double> v(5,20.25);
	string expected = "{20.25, 20.25, 20.25, 20.25, 20.25}";
	EXPECT_EQUAL(expected, v);
}

void TestVectorDoubleConstructZero() {
	cout << "Running TestVectorDoubleConstructZero \n";
	Vector<double> v(0,20.25);
	string expected = "{}";
	EXPECT_EQUAL(expected, v);
}

void TestVectorDoubleConstructBiggerThanBuffer() {
	cout << "Running TestVectorDoubleConstructBiggerThanBuffer \n";
	EXPECT_THROW(VectorBiggerThanBuffer, Vector<double>(105, 20.25));
}

void TestVectorDoubleConstructNegative() {
	cout << "Running TestVectorDoubleConstructNegative \n";
	EXPECT_THROW(VectorNegativeSize, Vector<double>(-5, 20.));
}


void RunVectorDoubleConstructTests() {
	TestVectorDoubleConstructNormal(); 
	TestVectorDoubleConstructZero();
	TestVectorDoubleConstructBiggerThanBuffer();
	TestVectorDoubleConstructNegative();
}

void TestVectorDoubleAtEqual() {
	cout << "Running TestVectorDoubleAtEqual \n";
	Vector<double> v(5, 20.);
	EXPECT_NEAR(20., v[3], 0.0001);
}

void TestVectorDoubleConstAtNegativeIndex() {
	cout << "Running TestVectorDoubleAtNegativeIndex \n";
	const Vector<double> v(5, 20.);
	EXPECT_THROW(VectorNegativeIndex, v[-1]);
}

void TestVectorDoubleConstAtIndexBiggerThanSize() {
	cout << "Running TestVectorDoubleAtIndexBiggerThanSize \n";
	const Vector<double> v(5, 20.);
	EXPECT_THROW(VectorIndexBiggerThanSize, v[7]);
}

void RunVectorDoubleAtTests() {
	TestVectorDoubleAtEqual();
	TestVectorDoubleConstAtNegativeIndex();
	TestVectorDoubleConstAtIndexBiggerThanSize();
}

void RunVectorDoubleTests() {
	RunVectorDoubleConstructTests();
	RunVectorDoubleAtTests();
}















