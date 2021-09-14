#include "ParallelBG.h"
#include "Shader.h"
#include "Model.h"
#include "Camera.h"
#include "Texture.h"
#include "Application.h"
ParallelBG::ParallelBG() : m_time(0.0f), m_speed(0.0f)
{
}
ParallelBG::ParallelBG(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, GLfloat speed)
	: BaseObject(0,model, shader, texture), m_time(0.0f), m_speed(speed)
{
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight+6);
	m_background1 = std::make_shared<Sprite2D>(model, shader, texture);
	m_background1->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2 + Globals::screenHeight);
	m_background1->SetSize(Globals::screenWidth, Globals::screenHeight+6);

	Init();
}
void ParallelBG::Init()
{
	SetCamera(Application::GetInstance()->GetCamera());
	CalculateWorldMatrix();
}

void ParallelBG::Draw()
{
	m_background->Draw();
	m_background1->Draw();
}

void ParallelBG::Update(GLfloat deltatime)
{
	m_time += deltatime;
	Vector2 deltaMove = Vector2(0, 1) * m_speed * deltatime;
	m_background->Set2DPosition(m_background->GetPosition().x + deltaMove.x, m_background->GetPosition().y + deltaMove.y);

	if (m_background->GetPosition().y > Globals::screenHeight / 2 + Globals::screenHeight) {
		m_background->Set2DPosition(m_background->GetPosition().x, - Globals::screenHeight / 2);
	}
	m_background1->Set2DPosition(m_background1->GetPosition().x + deltaMove.x, m_background1->GetPosition().y + deltaMove.y);
	if (m_background1->GetPosition().y > Globals::screenHeight / 2 + Globals::screenHeight) {
		m_background1->Set2DPosition(m_background1->GetPosition().x, - Globals::screenHeight / 2);
	}
	
}