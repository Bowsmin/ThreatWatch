/***************************************************************
* Name        : Invalid Threat Exception
* Author      : Josiah Anderson
* Created     : 4/30/2022
***************************************************************/

#pragma once
#ifndef INVALIDTHREATSC_H
#define INVALIDTHREATSC_H
#include <string>

class invalidThreatScException
{
private:
	std::string msg_;
public:
	invalidThreatScException(const std::string& msg) :
		msg_(msg) {
	}

	invalidThreatScException();
	~invalidThreatScException() {}

	std::string getMessage() const {
		return (msg_);
	}
};

#endif // INVALIDTHREATSC_H

