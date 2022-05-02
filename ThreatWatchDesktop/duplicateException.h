#pragma once
#ifndef DUPLICATELVL_H
#define DUPLICATELVL_H
#include <string>

class duplicateException
{
private:
	std::string msg_;
public:
	duplicateException(const std::string& msg) :
		msg_(msg) {
	}

	duplicateException();
	~duplicateException() {}

	std::string getMessage() const {
		return (msg_);
	}
};

#endif // DUPLICATELVL_H
