#pragma once

#include "Mesh.h"
#include "Material.h"


class Triangle
{
	Mesh* mesh;
	Material* material;

public:
	float red, green, blue;
	float offsetX, offsetY;

	Triangle(Material* _material, Mesh* _mesh)
	{
		mesh = _mesh;
		material = _material;
	}
	void Render()
	{
		material->use();


		int tintLocation = glGetUniformLocation(
			material->shaderProgram, "tintColor");
		glUniform4f(tintLocation, red, green, blue, 1.0);

		int offsetLocation = glGetUniformLocation(material->shaderProgram, "offset");
		glUniform2f(offsetLocation, offsetX, offsetY);

		int diffuseLocation = glGetUniformLocation(material->shaderProgram, "diffuseTexture");
		glUniform1i(diffuseLocation, 0);

		int blendLocation = glGetUniformLocation(material->shaderProgram, "blendTexture");
		glUniform1i(blendLocation, 1);

		mesh->Render();
	}
	
};

