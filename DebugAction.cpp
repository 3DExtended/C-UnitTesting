#include "DebugAction.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <time.h>
#endif

std::map<std::string, DebugAction*> DebugAction::actions = std::map<std::string, DebugAction*>();

#if _WIN32
LARGE_INTEGER sFrequency; //is initialized with 0
#endif

void DebugAction::_bind()
{
	writeTimeStamp(boundTime);
}

void DebugAction::_unbind()
{
	writeTimeStamp(tempTimeStamp);
	//difference between boundTime and tempTimeStamp is the time used
	//TODO
	TimeRepresentation temp;
	temp = *tempTimeStamp - *boundTime;
	eachTime.push_back(temp);

	if (eachTime.size() > NUMBEROFSTOREDTIMESTAMPS) {
		eachTime.erase(eachTime.begin());
		numberOfEvents--;
	}

	//std::cout << "Secs: " << temp.secs << ", NanoSecs: " << temp.nsecs << std::endl;

	numberOfEvents++;
}

DebugAction * DebugAction::GetAction(std::string name)
{
#if _WIN32
	if (sFrequency.QuadPart == 0)
		QueryPerformanceFrequency(&sFrequency);
#endif
	DebugAction *action = nullptr;

	std::map<std::string, DebugAction*>::iterator it = actions.find(name);

	if (it == actions.end()) {
		action = new DebugAction(name);
		actions.insert(std::pair<std::string, DebugAction*>(name, action));
	}
	else {
		action = it->second;
	}

	return action;
}

DebugAction::DebugAction(std::string name) :name(name)
{
}

DebugAction::~DebugAction()
{
	delete boundTime;
}

TimeRepresentation DebugAction::GetAverage()
{
	TimeRepresentation average;
	for (size_t i = 0; i < eachTime.size(); i++) {
		average = average + eachTime[i];
	}

	return average / numberOfEvents;
}

void DebugAction::DestroyAllActions()
{
}

void DebugAction::writeTimeStamp(TimeRepresentation * timeStamp)
{
#ifdef _WIN32
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	timeStamp->secs = int32_t(time.QuadPart / sFrequency.QuadPart);
	timeStamp->nsecs = int32_t((time.QuadPart % sFrequency.QuadPart) * 1000000000LL / sFrequency.QuadPart);
#else
	struct timespec t;
	clock_gettime(CLOCK_MONOTONIC, &t);
	timeStamp->secs = t.tv_sec;
	timeStamp->nsecs = t.tv_nsec;
#endif
}
