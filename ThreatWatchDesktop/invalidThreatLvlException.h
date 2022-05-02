#pragma once
#ifndef INVALIDTHREATLVL_H
#define INVALIDTHREATLVL_H
#include <string>

class invalidThreatLvlException
{
private:
	std::string msg_;
public:
	invalidThreatLvlException(const std::string& msg) :
		msg_(msg) {
	}

	invalidThreatLvlException();
	~invalidThreatLvlException() {}

	std::string getMessage() const {
		return (msg_);
	}
};

#endif // INVALIDTHREATLVL_H

