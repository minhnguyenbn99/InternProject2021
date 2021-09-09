#pragma once
#include "Sprite2D.h"
class Text;

class ObjectObstacle : public Sprite2D
	
{
public:
	ObjectObstacle();
	ObjectObstacle(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
	~ObjectObstacle();
	void Init();
	void Update(float deltaTime) override ;
	
	

private:
	

	
};
