#pragma once
class TestThisFile {
public:
	TestThisFile(int squareThis);
	~TestThisFile();

	int calculateResult();

private:
	int squareThis = 0;
};