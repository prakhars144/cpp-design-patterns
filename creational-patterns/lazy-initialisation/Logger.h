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
#include <memory>

using namespace std;

class Logger
{
private:
    // nested struct so that it can access private members
    struct Deleter
    {
        // functor, making Delete callable
        void operator()(Logger *p)
        {
            delete p;
        }
    };
    // Eager instance. It is created even before Main function is invoked.
    fstream m_logFile;
    // Default is faster. Notice the private constructor.
    Logger();
    /**
     * users can call delete on our Logger pointer but that will cause
     * undefined bahaviour. Making Destructor private solves this issue.
     * But if its private how smart pointer will delete it ? So we introduce
     * our own deleter
     */
    ~Logger();
    /**
     * inline static introduced in CPP17 allows to initialise static members
     * inside the class itself. If we don't use smart pointer here then m_pInstance
     * destructor will never be called because delete was not called for m_pInstance.
     */
    inline static unique_ptr<Logger, Deleter> m_pInstance{};

public:
    /**
     * Delete copy constructor and assignment to force users to use references.
     * Why not simply use pointers instead of refences ? because then users can
     * call delete on them and users will also need to null check the pointers.
     * On the other hand, references can't be null. Users can also dereference the
     * pointer and try to create a copy.
     */
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;
    static Logger &getInstance();
    void LOG(string msg);
};
