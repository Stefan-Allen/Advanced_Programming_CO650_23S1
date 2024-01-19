#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>
#include <string>

class Exception : public std::exception {
public:
    // Constructors
    Exception(const std::string& message, int errorCode = 0) : message(message), errorCode(errorCode) {}

    // Method to provide detailed error information
    const char* what() const noexcept override {
        if (errorCode != 0) {
            return (message + " Error Code: " + std::to_string(errorCode)).c_str();
        } else {
            return message.c_str();
        }
    }

    // Getter for the error code
    int GetErrorCode() const {
        return errorCode;
    }

private:
    // Private members
    std::string message;
    int errorCode;
};

#endif // EXCEPTION_H
