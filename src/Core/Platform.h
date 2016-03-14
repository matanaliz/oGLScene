#ifndef Core_PLATFORM_H
#define Core_PLATFORM_H

#ifdef CORE_EXPORTS
#define CORE_API __declspec(dllexport)
#else
#define CORE_API __declspec(dllimport)
#endif


#endif //Core_PLATFORM_H