#pragma once

#include "Camera.h"
#include "Mesh.h"
#include "Material.h"
#include "Object.h"
#include "Texture.h"
#include "../Maths/Matrix4x4.h"

class GameObject : public Object
{
	const Mesh* mesh;
	Material* material;
	Texture* texture;

public:
	float red, green, blue;
	GameObject(Material* _material, const Mesh* _mesh, Texture* _texture = nullptr)
	{
		mesh = _mesh;
		material = _material;
		texture = _texture;
	}
	void render(Camera* camera)
	{
		material->use();


		int tintLocation = glGetUniformLocation(
			material->shaderProgram, "tintColor");
		glUniform4f(tintLocation, red, green, blue, 1.0);

		Matrix4x4 modelMatrix = calculateModelMatrix();
		unsigned int modelLoc = glGetUniformLocation(material->shaderProgram, "transform");
		glUniformMatrix4fv(modelLoc, 1, GL_TRUE, &modelMatrix.m11);
		
		Matrix4x4 view = camera->viewMatrix();
		unsigned int viewLoc = glGetUniformLocation(material->shaderProgram, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_TRUE, &view.m11);

		Matrix4x4 projection = camera->projectionMatrix();
		unsigned int projectionLoc = glGetUniformLocation(material->shaderProgram, "projection");
		glUniformMatrix4fv(projectionLoc, 1, GL_TRUE, &projection.m11);

		// float fov = 45.0f / 360 * 2 * 3.141593;
		// float aspectRatio = 800/600;
		// Matrix4x4 projection = Matrix4x4::Perspective(fov, aspectRatio, 0.1f, 100.0f );
		// unsigned int projectionLoc = glGetUniformLocation(material->shaderProgram, "projection");
		// glUniformMatrix4fv(projectionLoc, 1, GL_TRUE, &projection.m11);

		

		int diffuseLocation = glGetUniformLocation(material->shaderProgram, "diffuseTexture");
		glUniform1i(diffuseLocation, 0);
		glActiveTexture(GL_TEXTURE0);
		if(texture != nullptr)
			glBindTexture(GL_TEXTURE_2D, texture->textureId);
		else
			glBindTexture(GL_TEXTURE_2D, 0);

		

		mesh->render();
	}
	
};

