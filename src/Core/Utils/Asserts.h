#ifndef ASSERTS_H
#define ASSERTS_H

#include <assert.h>

inline void SIMPLE_ASSERT(bool condition)
{
	assert(condition);
}

#endif