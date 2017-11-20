#include "TestThisFile.h"

TestThisFile::TestThisFile(int squareThis) :squareThis(squareThis) {}

TestThisFile::~TestThisFile() {}

int TestThisFile::calculateResult() {
	return squareThis*squareThis;
}
