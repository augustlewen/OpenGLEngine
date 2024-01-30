#pragma once

#include "Mesh.h"
#include "Material.h"


class Triangle
{
	Mesh* mesh;
	Material* material;

public:
	float red, green, blue;

	Triangle(Material* _material, Mesh* _mesh)
	{
		mesh = _mesh;
		material = _material;
	}
	void Render()
	{
		material->use();
		mesh->Render();
	}
	void setRGB(const std::string& name, float red, float green, float blue) const
	{
		glGetUniformLocation(red, "red");
		glGetUniformLocation(green, "green");
		glGetUniformLocation(blue, "blue");
	}
};

