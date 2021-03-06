#include "Tester.h"
#include "DebugAction.h"

Tester* Tester::instance = nullptr;
Tester * Tester::GetInstance() {
	if (instance == nullptr)
		instance = new Tester();
	return instance;
}

int Tester::TestEverthing()
{
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "-------------Testing Code-------------" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << std::endl;

	int numberOfFailedTests = 0;
	for (unsigned int i = 1; i < functions.size() + 1; i++)
	{
		std::pair<std::string, std::function<int(void)>> func = functions[i - 1];


		DebugAction* actionTimeCounter = DebugAction::GetAction(func.first);
		actionTimeCounter->_bind();
		int res = func.second();
		actionTimeCounter->_unbind();

		TimeRepresentation time = actionTimeCounter->GetAverage();

		if (res == 0) {
			std::cout << "\t" << "Test " << i << "/" << functions.size() << ":   " << func.first << std::endl;
			std::cout << "\t" << "Test number " << i << " passed! " << time << std::endl;
		}
		else {
			std::cout << std::endl;
			std::cout << "\t\\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/ " << std::endl;
			std::cout << std::endl;
			std::cout << "\t\t" << "Test " << i << "/" << functions.size() << ":   " << func.first << " failed!" << std::endl;
			std::cout << "\t\t" << "Failure number: " << res << std::endl;
			std::cout << "\t\t" << time << res << std::endl;
			std::cout << std::endl;
			std::cout << "\t/\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\ " << std::endl;
			std::cout << std::endl;
			numberOfFailedTests++;
		}
		std::cout << std::endl;
	}

	if (numberOfFailedTests == 0) {
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "---------All tests passed!---------" << std::endl;
		std::cout << "-----------------------------------" << std::endl;
	}
	else {
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "\t" << numberOfFailedTests << "/" << functions.size() << " tests failed!" << std::endl;
		std::cout << "-----------------------------------" << std::endl;
	}
	return numberOfFailedTests;

}

void Tester::RegisterTest(std::pair<std::string, std::function<int(void)>> func)
{
	functions.push_back(func);
}
