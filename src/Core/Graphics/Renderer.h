#ifndef RENDERER_H
#define RENDERER_H

class ShaderProgram;
class Mesh;

class Renderer
{
public:
	void render(const ShaderProgram& shaderProgram, const Mesh& mesh);
private:
};

#endif //RENDERER_H	