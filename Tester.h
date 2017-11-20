#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
class Tester {
public:
	static Tester* GetInstance();

	int TestEverthing();
	void RegisterTest(std::pair<std::string, std::function<int(void)>> func);
private:
	Tester() {};
	std::vector<std::pair<std::string, std::function<int(void)>>> functions;
	static Tester * instance;
};

#define Test Tester::GetInstance()->RegisterTest(std::pair<std::string, std::function<int(void)>>