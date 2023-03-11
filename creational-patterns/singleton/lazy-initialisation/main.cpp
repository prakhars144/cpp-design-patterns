#include "Logger.h"

using namespace std;

int main()
{
    /**
     * if we dont use an instance of Logger then copy constructor will be called.
     * Since we have not defined copy constructor compiler will define it for us and do the shallow copy of object.
     * This will be problematic because now two Logger object can share the same resource like a FILE stream and may
     * crash program at runtime. Or create other issues like dangling pointer
     */
    Logger &logOne = Logger::getInstance();
    Logger &logTwo = Logger::getInstance();
    logOne.LOG("1");
    logTwo.LOG("a");
    logOne.LOG("2");
    logOne.LOG("3");
    logTwo.LOG("b");
    logTwo.LOG("c");
    return 0;
}