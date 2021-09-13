#include "ObjectObstacle.h"
#include "ResourceManagers.h"
#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Text.h"
#include "Application.h"

ObjectObstacle::ObjectObstacle()
{
	Init();
}
ObjectObstacle::ObjectObstacle(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	: Sprite2D(model, shader, texture)
{
	
}

ObjectObstacle::~ObjectObstacle()
{
	
}

void ObjectObstacle::Init()
{
	
}

void ObjectObstacle::Update(float deltaTime)
{
	
		Set2DPosition(this->GetPosition().x, this->GetPosition().y + 100 * deltaTime);
		Vector3 currentPos = this->GetPosition();
		if (this->GetPosition().y >= 750) {
			Set2DPosition(currentPos.x, -100);
		}

}
	