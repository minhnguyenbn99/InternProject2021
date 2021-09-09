#include "GSPlay.h"
#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include "Sprite2D.h"
#include "ObjectObstacle.h"
#include <string>
#include <stdio.h>
#include <iostream>

GSPlay::GSPlay()
	: GameStateBase(StateType::STATE_PLAY), m_score(0), m_spawnEnemyTime(0.f), scoregame(0), difficultgame(0), nocollision(true)
{
}


GSPlay::~GSPlay()
{
}


void GSPlay::Init()
{
	
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("BGcar5.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// barrel
	texture = ResourceManagers::GetInstance()->GetTexture("barrel.tga");
	m_barrel = std::make_shared<Sprite2D>(model, shader, texture);
	m_barrel->Set2DPosition(40, 80);
	m_barrel->SetSize(70, 90);
	// block
	texture = ResourceManagers::GetInstance()->GetTexture("block.tga");
	m_block = std::make_shared<Sprite2D>(model, shader, texture);
	m_block->Set2DPosition(50, 200);
	m_block->SetSize(100, 40);
	
	// carplayer
	texture = ResourceManagers::GetInstance()->GetTexture("audi1.tga");
	m_objectplayer = std::make_shared<Sprite2D>(model, shader, texture);
	m_objectplayer->Set2DPosition(300, 650);
	m_objectplayer->SetSize(70, 100);

	

	// button close
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	
	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	m_score = std::make_shared< Text>(shader, font, "score: 0", TextColor::BLUE, 1.0);
	m_score->Set2DPosition(Vector2(5, 25));
	

}

void GSPlay::Exit()
{
}


void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}


void GSPlay::HandleEvents()
{
}
void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	if(bIsPressed == true) {
		switch (key) {
		case'A':
			m_keyPressed |= KEY_MOVE_LEFT;
			break;
		case'D':
			m_keyPressed |= KEY_MOVE_RIGHT;
			break;
		case'W':
			m_keyPressed |= KEY_MOVE_FORWORD;
			break;
		case'S':
			m_keyPressed |= KEY_MOVE_BACKWORD;
			break;
		default:
			break;
		}
	}
	else {
	switch (key) {
	case'A':
		m_keyPressed ^= KEY_MOVE_LEFT;
		break;
	case'D':
		m_keyPressed ^= KEY_MOVE_RIGHT;
		break;
	case'W':
		m_keyPressed ^= KEY_MOVE_FORWORD;
		break;
	case'S':
		m_keyPressed ^= KEY_MOVE_BACKWORD;
	default:
		break;
	}
	}
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if(button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSPlay::HandleMouseMoveEvents(int x, int y)
{
}


void GSPlay::Update(float deltaTime)
{
	Vector3 currentObjectPos = m_objectplayer->GetPosition();

	
	if (m_keyPressed & KEY_MOVE_LEFT ) {
	if ( currentObjectPos.x >= 170 & nocollision){
		
		m_objectplayer->Set2DPosition(Vector2(currentObjectPos.x - 2, currentObjectPos.y));
		//PlaySound(TEXT("beep.wav"), NULL, SND_FILENAME);
	}
	}
	if (m_keyPressed & KEY_MOVE_RIGHT ) {
		if (currentObjectPos.x <= 430 & nocollision)
			
		m_objectplayer->Set2DPosition(Vector2(currentObjectPos.x + 2, currentObjectPos.y));
		//PlaySound(TEXT("beep.wav"), NULL, SND_FILENAME);
	}
	if (m_keyPressed & KEY_MOVE_FORWORD ) {
		if (currentObjectPos.y >= 50 & nocollision)
			
		m_objectplayer->Set2DPosition(Vector2(currentObjectPos.x, currentObjectPos.y - 2));
		//PlaySound(TEXT("beep.wav"), NULL, SND_FILENAME);
	}
	if (m_keyPressed & KEY_MOVE_BACKWORD ) {
		if (currentObjectPos.y <= 650 & nocollision)
			
		m_objectplayer->Set2DPosition(Vector2(currentObjectPos.x, currentObjectPos.y + 2));
		//PlaySound(TEXT("beep.wav"), NULL, SND_FILENAME);
	}
	
	

	m_spawnEnemyTime -= deltaTime;
	if (m_spawnEnemyTime <= 0) {
		std::shared_ptr<ObjectObstacle> obsobj;
		auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
		auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
		auto texture = ResourceManagers::GetInstance()->GetTexture("obs2.tga");
		obsobj = std::make_shared<ObjectObstacle>(model, shader, texture);
		obsobj->SetSize(70, 100);
		obsobj->Set2DPosition(170 + 85 * (rand() % 4), -50);
		m_listObsObj.push_back(obsobj);
		if (scoregame <= 50) {
			m_spawnEnemyTime = 5.0f;
		}
		if(scoregame>50){ m_spawnEnemyTime = 2.0f; }
		
	}

	for (int i = 0; i < m_listObsObj.size(); i++)
	{
		Vector3 currentObstaclePos = m_listObsObj[i]->GetPosition();
		
		if (isCollision(m_objectplayer, m_listObsObj[i])) {
			m_listObsObj[i]->Set2DPosition(currentObstaclePos.x, currentObstaclePos.y);
			nocollision = false;
			break;
		}

		if (scoregame > 60) {
			difficultgame = 0.2;
			m_listObsObj[i]->Update(deltaTime * (1 - difficultgame));
		}
		m_listObsObj[i]->Update(deltaTime * (1 - difficultgame));
		//Vector3 currentObstaclePos = m_listObsObj[i]->GetPosition();
		if (currentObstaclePos.y == 700) {
			scoregame+=10;
			m_score->SetText("score :" + std::to_string(scoregame));
		}
		if (currentObstaclePos.y > 750) {
			removeobs(i);
		}
	}
	
	if (scoregame > 100) {
		
		changecar();
	}

	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSPlay::removeobs(int numerobs) {
	m_listObsObj.erase(m_listObsObj.begin()+numerobs);
}
void  GSPlay::changecar() {
	Vector3 currentObjectPos = m_objectplayer->GetPosition();
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("audi2.tga");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_objectplayer = std::make_shared<Sprite2D>(model, shader, texture);
	m_objectplayer->SetSize(70, 100);
	m_objectplayer->Set2DPosition(currentObjectPos.x, currentObjectPos.y);
}
bool GSPlay::isCollision(std::shared_ptr<Sprite2D> object1, std::shared_ptr<Sprite2D> object2)
{
	if (object1->GetPosition().x - object1->getWidth() / 2 + 10 > object2->GetPosition().x + object2->getWidth() / 2
		|| object1->GetPosition().x + object1->getWidth() / 2 < object2->GetPosition().x - object2->getWidth() / 2 + 10
		|| object1->GetPosition().y - object1->getHeight() / 2 + 5 > object2->GetPosition().y + object2->getHeight() / 2
		|| object1->GetPosition().y + object1->getHeight() / 2 < object2->GetPosition().y - object2->getHeight() / 2 + 5
		)
	{
		return false;
	}

	return true;
	
}
void GSPlay::Draw()
{
	m_background->Draw();
	m_objectplayer->Draw();
	m_barrel->Draw();
	m_block->Draw();
	for (auto it : m_listObsObj)
	{
		it->Draw();
	}
	m_score->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	
}