#ifndef ERRORS_H
#define ERRORS_H
#include <exception>
#include <chrono>
#include <ctime>
#include <string>

class baseError : public std::exception
{
private:
    std::chrono::time_point<std::chrono::system_clock> timePoint;
    std::string fileName;
    std::string className;
    std::string method;

public:
    baseError(std::chrono::time_point<std::chrono::system_clock> time,
              std::string file, std::string classn, std::string met) :
                                  timePoint(time),
                                  fileName(std::move(file)),
                                  className(std::move(classn)),
                                  method(std::move(met)){}

    virtual const char* what() const noexcept override
    {
        std::string error = "Some error\n" + info();
        return error.c_str();
    }

    virtual std::string info() const
    {
        auto time = std::chrono::system_clock::to_time_t(timePoint);
        return "\nFILE:" + fileName + "\nCLASS:" + className \
                + "\nMETHOD:" + method + "\nTIME:" + std::ctime(&time);
    }

};

class memError : public baseError
{
public:
    using baseError::baseError;
    const char* what()  const noexcept override
    {
        std::string error = "A memory allocation error" + baseError::info();
        std::cout << error.c_str();
        return error.c_str();
    }
};

class rangeError : public baseError
{
public:
    using baseError::baseError;
    const char* what()  const noexcept override
    {
        std::string error = "List is out of range" + baseError::info();
        std::cout << error.c_str();
        return error.c_str();
    }
};

class emptyError : public baseError
{
public:
    using baseError::baseError;
    const char* what()  const noexcept override
    {
        std::string error = "Attempt to work with empty list or empty element" + baseError::info();
        std::cout << error.c_str();
        return error.c_str();
    }
};


#endif // ERRORS_H
