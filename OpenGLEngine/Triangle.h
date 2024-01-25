#pragma once

#include "Mesh.h"
#include "Material.h"


class Triangle
{
	Mesh* mesh;
	Material* material;

public:
	Triangle(Material* material, Mesh* mesh)
	{
		this->mesh = mesh;
		this->material = material;
	}
	void Render()
	{
		material->use();
		mesh->Render();
	}
};

