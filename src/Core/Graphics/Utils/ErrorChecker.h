#ifndef ERROR_CHECKER_H
#define ERROR_CHECKER_H

#include <GL/glew.h>

//template <typename F, typename ...Args>
//void call(
//	const char *text,
//	int line,
//	const char *file,
//	F && f, Args &&... args
//	)
//{
//	std::forward<F>(f)(std::forward<Args>(args)...);
//	auto err = glGetError();
//	if (err != 0) 
//		throw;
//		//_throw_error(text, err, line, file);
//}

#define ALLOW_CHECK_GL 1

class GLErrorSimpleCheckerImpl
{
public:
	GLErrorSimpleCheckerImpl()
	{
		auto err = glGetError();
		if (err != 0)
		{
#ifdef _DEBUG
			__debugbreak();
#endif
		}
	}
};

#if defined(_DEBUG) && defined(ALLOW_CHECK_GL)
#define TEST_GL_ERROR() {GLErrorSimpleCheckerImpl __temp;(void)__temp;}
#else
	TEST_GL_ERROR()
#endif

#endif //ERROR_CHECKER_H