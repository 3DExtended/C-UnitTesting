#include <iostream>
#include "Tester.h"


//include every component of the engine you wanna test
#include "Example/TestThisFile.h"

void buildTests() {

	Test("TestThisFile.h - Test the sqare function.", [] {
		for (int i = 0; i < 1000; i++) {
			TestThisFile *temp = new TestThisFile(i);

			if (temp->calculateResult() != i * i) {
				return 1;
			}
		}

		return 0;
	}));
}


int main(int argc, char *argv[]) {

	buildTests();

	return Tester::GetInstance()->TestEverthing();
}