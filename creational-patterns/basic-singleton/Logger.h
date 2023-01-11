/**
 * Rule of three: If a class has ownership semantics it should implement assignment
 * operator, copy constructor and destructor. From C++11 its rule of five and need
 * to implement move constructor and move assignment. Not doing in this example
 * though as its global so move not needed.
*/

#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Logger
{
private:
    // Eager instance. It is created even before Main function is invoked.
    static Logger m_instance;
    fstream m_logFile;
    // Default is faster. Notice the private constructor.
    Logger() = default;

public:
    /**
     * Delete copy constructor and assignment to force users to use references.
     * Why not simply use pointers instead of refences ? because then users can
     * call delete on them and users will also need to null check the pointers.
     * On the other hand, references can't be null. Users can also dereference the
     * pointer and try to create a copy.
    */
    Logger(const Logger&) = delete;
    Logger& operator = (const Logger &) = delete;
    static Logger &getInstance();
    void LOG(string msg);
    ~Logger() = default;
};
