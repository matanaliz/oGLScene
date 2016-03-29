#ifndef _AUXILARY_H
#define _AUXILARY_H

#include <exception>
#include <string>

inline void ERROR_NOT_IMPL(const std::string& text)
{
#ifdef _DEBUG
	__debugbreak();
#endif
	throw std::exception(text.c_str());
}


#endif