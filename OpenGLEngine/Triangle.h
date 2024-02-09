#pragma once

#include "Mesh.h"
#include "Material.h"
#include "Texture.h"
#include "../Maths/Matrix4x4.h"

class Triangle
{
	Mesh* mesh;
	Material* material;
	Texture* texture;

public:
	float red, green, blue;
	float offsetX, offsetY, offsetZ;
	Vector3 offset{0, 0, 0};
	Vector3 rotation{ 0, 0, 0 };
	Vector3 scale{ 1, 1, 1};
	Triangle(Material* _material, Mesh* _mesh, Texture* _texture = nullptr)
	{
		mesh = _mesh;
		material = _material;
		texture = _texture;
	}
	void Render()
	{
		material->use();


		int tintLocation = glGetUniformLocation(
			material->shaderProgram, "tintColor");
		glUniform4f(tintLocation, red, green, blue, 1.0);


		double pi = 2 * acos(0.0);
		Matrix4x4 transformMatrix = Matrix4x4::Translation(offset);
		Matrix4x4 rotationMatrix = Matrix4x4::Rotation(rotation * pi / 2);
		Matrix4x4 scaleMatrix = Matrix4x4::Scale(scale);

		Matrix4x4 matrix = transformMatrix * rotationMatrix * scaleMatrix;

		unsigned int transformLoc = glGetUniformLocation(material->shaderProgram, "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_TRUE, &matrix.m11);



		int diffuseLocation = glGetUniformLocation(material->shaderProgram, "diffuseTexture");
		glUniform1i(diffuseLocation, 0);
		glActiveTexture(GL_TEXTURE0);
		if(texture != nullptr)
			glBindTexture(GL_TEXTURE_2D, texture->textureId);
		else
			glBindTexture(GL_TEXTURE_2D, 0);

		

		mesh->Render();
	}
	
};

