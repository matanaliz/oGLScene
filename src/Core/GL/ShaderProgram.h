#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include <string>

#if USE_GLM_LIB
#include <glm/glm.hpp>
#endif


class ShaderProgram
{
public:
	enum GLSLShaderType {
		VERTEX, FRAGMENT
	};

	ShaderProgram();

	unsigned int getShaderProgram();

	void linkProgram();
	
	bool compileShaderFromString( const std::string & source, ShaderProgram::GLSLShaderType type );
	void use();
	void release();

	//these two function should only be called before linking the program
	void bindAttribLocation( unsigned int location, const char * name);
	void bindFragDataLocation( unsigned int location, const char * name );

#if USE_GLM_LIB
	void setUniform(const glm::mat4& matr, const std::string& name);
	void setUniform(const glm::mat3& matr, const std::string& name);
	void setUniform(const glm::vec2& vec, const std::string& name);
	void setUniform(const glm::vec3& vec, const std::string& name);
	void setUniform(const glm::vec4& vec, const std::string& name);
#endif
	void setUniform(float matr, const std::string& name);
	void setUniform(int matr, const std::string& name);
	void setUniform(bool matr, const std::string& name);

	static std::string readShader(const std::string& path);
	void printActiveAttribs();
	void printActiveUniforms();
private:
	unsigned int m_vaoHandle;
	unsigned int m_programHandle;
	unsigned int m_vertextProgram;
	unsigned int m_fragmentProgram;

	std::string m_fragment;
	std::string m_vertex;
};


#endif // SHADER_PROGRAM_H