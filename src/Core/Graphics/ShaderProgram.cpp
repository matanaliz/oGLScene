#include <iostream>
#include <fstream>
#include <streambuf>

#include "GL/glew.h"
#include <GL/gl.h>
#include <GL/glu.h>


#include "ShaderProgram.h"


ShaderProgram::ShaderProgram():
	m_programHandle(0),
	m_vertextProgram(0),
	m_fragmentProgram(0),
	m_vaoHandle(0),
	m_vertex(),
	m_fragment()
{
}


GLuint ShaderProgram::getShaderProgram()
{
	return m_programHandle;
}


void ShaderProgram::linkProgram()
{
	if( m_programHandle <= 0)
		return; //TODO tell something more informative

	glLinkProgram(m_programHandle);

	GLint status;
	glGetProgramiv( m_programHandle, GL_LINK_STATUS, &status );
	if( GL_FALSE == status ) {
		std::cout << "Failed to link shader program!\n";
		GLint logLen;
		glGetProgramiv(m_programHandle, GL_INFO_LOG_LENGTH,
			&logLen);
		if( logLen > 0 )
		{
			char * log = new char[logLen];
			GLsizei written;
			glGetProgramInfoLog(m_programHandle, logLen,
				&written, log);
			std::cout << "Program log: " << log << "\n";
			delete[] log;
		}
	}
}

void ShaderProgram::use() const
{
	if( m_programHandle <= 0)
		return; //TODO tell something more informative
	glUseProgram( m_programHandle );
}

void ShaderProgram::unUse() const
{
	if( m_programHandle <= 0)
		return; //TODO tell something more informative
	glUseProgram( 0 );
}


void ShaderProgram::release()
{
	if( m_programHandle <= 0 || m_vertextProgram <= 0 || m_fragmentProgram <= 0)
		return; //TODO tell something more informative
	
	glDeleteShader(m_vertextProgram);
	m_vertextProgram = 0;
	glDeleteShader(m_fragmentProgram);
	m_fragmentProgram = 0;
	glUseProgram(0);
	glDeleteProgram(m_programHandle);
	m_programHandle = 0;
}

#if USE_GLM_LIB
void ShaderProgram::setUniform(const glm::mat4& matr, const std::string& name )
{
	GLint location = glGetUniformLocation(m_programHandle, name.c_str());
	if( location >= 0 )
	{
		glUniformMatrix4fv(location, 1, GL_FALSE, &matr[0][0]);
	}
}

void ShaderProgram::setUniform( const glm::mat3& matr, const std::string& name )
{
	throw std::exception("Not implemented");
}

void ShaderProgram::setUniform( const glm::vec2& vec, const std::string& name )
{
	throw std::exception("Not implemented");
}

void ShaderProgram::setUniform( const glm::vec3& vec, const std::string& name )
{
	GLint location = glGetUniformLocation(m_programHandle, name.c_str());
	if( location >= 0 )
	{
		glUniform3f(location, vec[0], vec[1], vec[2]);
	}
}

void ShaderProgram::setUniform( const glm::vec4& vec, const std::string& name )
{
	GLint location = glGetUniformLocation(m_programHandle, name.c_str());
	if( location >= 0 )
	{
		glUniform4f(location, vec[0], vec[1], vec[2], vec[3]);
	}
}
#endif

void ShaderProgram::setUniform( float value, const std::string& name )
{
	GLint location = glGetUniformLocation(m_programHandle, name.c_str());
	if( location >= 0 )
	{
		glUniform1f(location, value);
	}
}

void ShaderProgram::setUniform( int matr, const std::string& name )
{
	throw std::exception("Not implemented");
}

void ShaderProgram::setUniform( bool matr, const std::string& name )
{
	throw std::exception("Not implemented");
}


std::string ShaderProgram::readShader(const std::string& path)
{
	std::ifstream t(path);
	std::string str((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());

	return str;
}


void ShaderProgram::bindAttribLocation( GLuint location, const char * name)
{
	glBindAttribLocation(m_programHandle, location, name);
}


void ShaderProgram::bindFragDataLocation( GLuint location, const char * name )
{
	glBindFragDataLocation(m_programHandle, location, name);
}


bool ShaderProgram::compileShaderFromString( const std::string & source, ShaderProgram::GLSLShaderType type )
{
	if( m_programHandle <= 0 ) {
		m_programHandle = glCreateProgram();
		if( m_programHandle == 0) {
			std::cout << "Unable to create shader program.";
			return false;
		}
	}

	GLuint shaderHandle = 0;

	switch( type ) {
	case ShaderProgram::VERTEX:
		{
			shaderHandle = m_vertextProgram = glCreateShader(GL_VERTEX_SHADER);
			break;
		}
	case ShaderProgram::FRAGMENT:
		{
			shaderHandle = m_fragmentProgram = glCreateShader(GL_FRAGMENT_SHADER);
			break;
		}
	default:
		return false; //TODO tell something more informative
	}

	const char * c_code = source.c_str();
	glShaderSource( shaderHandle, 1, &c_code, NULL );

	// Compile the shader
	glCompileShader(shaderHandle );

	// Check for errors
	int result;
	glGetShaderiv( shaderHandle, GL_COMPILE_STATUS, &result );
	if( GL_FALSE == result )
	{
		std::cout << "Shader compilation failed!\n";
		GLint logLen;
		glGetShaderiv( shaderHandle, GL_INFO_LOG_LENGTH, &logLen );
		if( logLen > 0 )
		{
			char * log = new char[logLen];
			GLsizei written;
			glGetShaderInfoLog(shaderHandle, logLen, &written, log);
			std::cout << "Shader log: " << log << "\n";
			delete[] log;
		}
		return false;
	} else {
		// Compile succeeded, attach shader and return true
		glAttachShader(m_programHandle, shaderHandle);
		return true;
	}
}


void ShaderProgram::printActiveUniforms() 
{
	std::cout << "Uniforms\n";
	GLint nUniforms, size, location, maxLen;
	GLsizei written;
	GLenum type;

	glGetProgramiv( m_programHandle, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxLen);
	glGetProgramiv( m_programHandle, GL_ACTIVE_UNIFORMS, &nUniforms);

	GLchar * name = new GLchar[maxLen];

	printf(" Location | Name\n");
	printf("------------------------------------------------\n");
	for( int i = 0; i < nUniforms; ++i ) {
		glGetActiveUniform( m_programHandle, i, maxLen, &written, &size, &type, name );
		location = glGetUniformLocation(m_programHandle, name);
		printf(" %-8d | %s\n",location, name);
	}

	delete[] name;
}


void ShaderProgram::printActiveAttribs() 
{
	std::cout << "Attribs\n";
	GLint written, size, location, maxLength, nAttribs;
	GLenum type;

	glGetProgramiv(m_programHandle, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxLength);
	glGetProgramiv(m_programHandle, GL_ACTIVE_ATTRIBUTES, &nAttribs);

	GLchar * name = new GLchar[maxLength];

	printf(" Index | Name\n");
	printf("------------------------------------------------\n");
	for( int i = 0; i < nAttribs; i++ ) {
		glGetActiveAttrib( m_programHandle, i, maxLength, &written, &size, &type, name );
		location = glGetAttribLocation(m_programHandle, name);
		printf(" %-5d | %s\n",location, name);
	}

	delete[] name;
}

int ShaderProgram::GetAttributeLocation(const std::string& location)
{
	return glGetAttribLocation(m_programHandle, location.c_str());
}

