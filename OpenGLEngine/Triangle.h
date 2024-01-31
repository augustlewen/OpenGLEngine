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
	
};

