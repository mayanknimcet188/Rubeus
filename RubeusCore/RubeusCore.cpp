// RubeusCore.cpp : Defines the entry point for the application.
//

#include "RubeusCore.h"

std::map<unsigned int, Rubeus::RMasterComponent *> Rubeus::RMasterComponent::m_ComponentMap;

int main()
{
	using namespace Rubeus;
	using namespace GraphicComponents;
	using namespace RML;
	RWindowComponent GameWindow("Hello World",
								1280, 720,
								EWindowParameters::WINDOWED_MODE,
								EWindowParameters::NON_RESIZABLE_WINDOW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	RShaderComponent shader("Shaders/basic.vertexshader", "Shaders/basic.fragmentshader");
	shader.enableShader();
	shader.setUniformMat4("proj_matrix", Matrix4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f));

	RRenderableObject sprite(RML::Vector3D(5, 5, 0), RML::Vector2D(3, 3), RML::Vector4D(1, 0, 1, 1), shader);
	RSimpleRendererComponent renderer;

	auto x = ((RWindowComponent *) (RMasterComponent::m_ComponentMap[GameWindow.getComponentID()]));
	x->setWindowTitle("Hey I just changed the title");

	while(!GameWindow.closed())
	{
		GameWindow.clearWindow();

		renderer.submit(&sprite);
		renderer.flush();

		GameWindow.updateWindow();
	}

	return 0;
}
