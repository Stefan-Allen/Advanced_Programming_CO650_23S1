#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>
#include <string>

class Exception : public std::exception {
public:
    Exception(const std::string& message, int errorCode = 0) : message(message), errorCode(errorCode) {}

    const char* what() const noexcept override {
        if (errorCode != 0) {
            return (message + " Error Code: " + std::to_string(errorCode)).c_str();
        } else {
            return message.c_str();
        }
    }

    int GetErrorCode() const {
        return errorCode;
    }

private:
    std::string message;
    int errorCode;
};

#endif // EXCEPTION_H
