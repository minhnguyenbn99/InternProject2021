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
#include "AnimationSprite.h"
#include "ParallelBG.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

GSPlay::GSPlay()
	: GameStateBase(StateType::STATE_PLAY), m_score(0), m_spawnEnemyTime(4.f), scoregame(0), difficultgame(0), nocollision(true), m_spawnAwardTime(5.f)
	, endgame(false), m_time(0.0f)
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
	m_background = std::make_shared<ParallelBG>(model, shader, texture, 100.0f);
	
	// barrel
	texture = ResourceManagers::GetInstance()->GetTexture("barrel.tga");
	m_barrel = std::make_shared<ObjectObstacle>(model, shader, texture);
	m_barrel->Set2DPosition(40, 80);
	m_barrel->SetSize(70, 90);
	// block
	texture = ResourceManagers::GetInstance()->GetTexture("block.tga");
	m_block = std::make_shared<ObjectObstacle>(model, shader, texture);
	m_block->Set2DPosition(40, 200);
	m_block->SetSize(100, 40);
	
	// carbg
	texture = ResourceManagers::GetInstance()->GetTexture("audi3.tga");
	m_carbg = std::make_shared<ObjectObstacle>(model, shader, texture);
	m_carbg->Set2DPosition(550, -100);
	m_carbg->SetSize(70, 100);

	// carplayer
	texture = ResourceManagers::GetInstance()->GetTexture("audi1.tga");
	m_objectplayer = std::make_shared<Sprite2D>(model, shader, texture);
	m_objectplayer->Set2DPosition(300, 650);
	m_objectplayer->SetSize(70, 100);

	//coins
	texture = ResourceManagers::GetInstance()->GetTexture("coins.tga");
	shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_coins = std::make_shared<AnimationSprite>(model, shader, texture, 10, 0.1f);
	m_coins->Set2DPosition(550,100);
	m_coins->SetSize(70, 70);

	// button close
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_MENU);
		});
	m_listButton.push_back(button);

	// restart
	texture = ResourceManagers::GetInstance()->GetTexture("btn_restart.tga");
	std::shared_ptr<GameButton> button2 = std::make_shared<GameButton>(model, shader, texture);
	button2->Set2DPosition(540, 180);
	button2->SetSize(60, 60);
	button2->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY);
		});
	m_listButton.push_back(button2);
	
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
	for (auto button : m_listButton1)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
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
	if(!endgame){
		m_background->Update(deltaTime);
		m_coins->Update(deltaTime);
		m_block->Update(deltaTime);
		m_barrel->Update(deltaTime);
		m_carbg->Update(deltaTime);
	}
	
	
	Vector3 currentObjectPos = m_objectplayer->GetPosition();
	
	if (m_keyPressed & KEY_MOVE_LEFT ) {
	if ( currentObjectPos.x >= 170 && nocollision){
		
		m_objectplayer->Set2DPosition(Vector2(currentObjectPos.x - deltaTime*200, currentObjectPos.y));
		
	}
	}
	if (m_keyPressed & KEY_MOVE_RIGHT ) {
		if (currentObjectPos.x <= 430 && nocollision )
			
		m_objectplayer->Set2DPosition(Vector2(currentObjectPos.x + deltaTime * 200, currentObjectPos.y));
		
	}
	if (m_keyPressed & KEY_MOVE_FORWORD ) {
		if (currentObjectPos.y >= 50 && nocollision )
			
		m_objectplayer->Set2DPosition(Vector2(currentObjectPos.x, currentObjectPos.y - deltaTime * 200));
		
	}
	if (m_keyPressed & KEY_MOVE_BACKWORD ) {
		if (currentObjectPos.y <= 650 && nocollision)
			
		m_objectplayer->Set2DPosition(Vector2(currentObjectPos.x, currentObjectPos.y + deltaTime * 200));
		
	}
	
	
	spawnObstacle(deltaTime);
	
	
	
	for (int i = 0; i < m_listObsObj.size(); i++)
	{
		Vector3 currentObstaclePos = m_listObsObj[i]->GetPosition();
		Vector3	currentPlayerPos = m_objectplayer->GetPosition();
		if (isCollision(m_objectplayer, m_listObsObj[i]) && !(m_listObsObj[i]->GetCoin())) {
			m_listObsObj[i]->Set2DPosition(currentObstaclePos.x, currentObstaclePos.y);
			nocollision = false;
			endgame = true;
			m_time += deltaTime;
				auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
				auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
				auto texture = ResourceManagers::GetInstance()->GetTexture("EndGame.tga");
				m_endgame = std::make_shared<Sprite2D>(model, shader, texture);
				m_endgame->SetSize(350, 350);
				m_endgame->Set2DPosition(300, 200);
				std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Squirk-RMvV.ttf");
				shader = ResourceManagers::GetInstance()->GetShader("TextShader");
				m_gameover = std::make_shared< Text>(shader, font, "Game Over", TextColor::RED, 1.5f);
				m_gameover->Set2DPosition(210, 140);
				m_endgamecurrentscore = std::make_shared< Text>(shader, font, "Your Score:  " + std::to_string(scoregame), TextColor::RED, 1.2f);
				m_endgamecurrentscore->Set2DPosition(210, 200);
			
		}
		
	}
	
	if (!endgame) {
		for (int i = 0; i < m_listAwdObj.size(); i++)
		{
			
			if (scoregame > 60) {
				difficultgame = 0.5;
			}
			m_listAwdObj[i]->Update(deltaTime* (1 + difficultgame + 0.2));

		}
	}
	
	
	if (!endgame) {
		for (int i = 0; i < m_listObsObj.size(); i++)
		{
			Vector3 currentObstaclePos = m_listObsObj[i]->GetPosition();
			if (scoregame > 60) {
				difficultgame = 0.5;
			}
			m_listObsObj[i]->Update(deltaTime * (1 + difficultgame + 0.2));


		}
	}	
	for (int i = 0; i < m_listObsObj.size(); i++)
	{
	Vector3 currentObstaclePos = m_listObsObj[i]->GetPosition();
	bool checkcollisioncoin = isCollision(m_objectplayer, m_listObsObj[i]) && m_listObsObj[i]->GetCoin();
	bool checkpassscreen = currentObstaclePos.y >= 750 && !(m_listObsObj[i]->GetCoin());
	if ( checkpassscreen || checkcollisioncoin) {			
		scoregame += 10;
		m_score->SetText("score :" + std::to_string(scoregame));
		if (checkpassscreen ) { removeobs(i); }
		if (checkcollisioncoin) { removeobs(i); }
						}			
		}
			
		
	
	
	if (scoregame == 60) {
		
		changecar(1);
	}
	if (scoregame == 150) {

		changecar(2);
	}
	if (scoregame == 200) {

		changecar(3);
	}
	if (scoregame == 250) {

		changecar(4);
	}
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSPlay::spawnObstacle(float deltaTime) {
	if (!endgame) {
		m_spawnEnemyTime -= deltaTime;
		std::shared_ptr<AnimationSprite> obsobj;
		auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
		auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
		if (scoregame <= 50) {
			if (m_spawnEnemyTime <= 0) {

				auto texture = ResourceManagers::GetInstance()->GetTexture("obs2.tga");
				obsobj = std::make_shared<AnimationSprite>(model, shader, texture,1,0.0f);
				obsobj->SetSize(70, 100);
				obsobj->Set2DPosition(170 + 85 * (rand() % 4), -100);
				m_listObsObj.push_back(obsobj);
				m_spawnEnemyTime = 3.f;
				obsobj->SetCoin(false);
			}
		}
		else if (scoregame > 50) {
			if (m_spawnEnemyTime <= 0) {
				if (rand() % 3 == 0) {
					auto texture = ResourceManagers::GetInstance()->GetTexture("obs2.tga");
					obsobj = std::make_shared<AnimationSprite>(model, shader, texture,1,0.0f);
					obsobj->SetSize(70, 100);
					obsobj->Set2DPosition(170 + 85 * (rand() % 4), -100);
					m_listObsObj.push_back(obsobj);
					m_spawnEnemyTime = 2.0f;
					obsobj->SetCoin(false);
				}
				else if (rand() % 3 == 1) {
					auto texture = ResourceManagers::GetInstance()->GetTexture("block.tga");
					obsobj = std::make_shared<AnimationSprite>(model, shader, texture,1,0.0f);
					obsobj->SetSize(170, 40);
					obsobj->Set2DPosition(130 + 85 * (2 * (rand() % 2) + 1), -100);
					m_listObsObj.push_back(obsobj);
					m_spawnEnemyTime = 2.0f;
					obsobj->SetCoin(false);
				}
				else if (rand() % 3 == 2) {
				auto	texture = ResourceManagers::GetInstance()->GetTexture("coins.tga");
					shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
					obsobj = std::make_shared<AnimationSprite>(model, shader, texture, 10, 0.1f);
					obsobj->SetSize(70, 70);
					obsobj->Set2DPosition(170 + 85 * (rand() % 4), -100);
					m_listObsObj.push_back(obsobj);
					m_spawnEnemyTime = 2.0f;
					obsobj->SetCoin(true);
				}
			}
		}
	}
}

void GSPlay::removeobs(int numerobs) {
	m_listObsObj.erase(m_listObsObj.begin()+numerobs);
}

void  GSPlay::changecar(int numberchange) {
	Vector3 currentObjectPos = m_objectplayer->GetPosition();
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	int numberchangecar = numberchange;
	if (numberchangecar == 1) {
		auto texture = ResourceManagers::GetInstance()->GetTexture("audi2.tga");
		m_objectplayer = std::make_shared<Sprite2D>(model, shader, texture);
		m_objectplayer->SetSize(70, 100);
		m_objectplayer->Set2DPosition(currentObjectPos.x, currentObjectPos.y);
	}
	if (numberchangecar == 2) {
		auto texture = ResourceManagers::GetInstance()->GetTexture("audi3.tga");
		m_objectplayer = std::make_shared<Sprite2D>(model, shader, texture);
		m_objectplayer->SetSize(70, 100);
		m_objectplayer->Set2DPosition(currentObjectPos.x, currentObjectPos.y);
	}
	if (numberchangecar == 3) {
		auto texture = ResourceManagers::GetInstance()->GetTexture("audi4.tga");
		m_objectplayer = std::make_shared<Sprite2D>(model, shader, texture);
		m_objectplayer->SetSize(70, 100);
		m_objectplayer->Set2DPosition(currentObjectPos.x, currentObjectPos.y);
	}
	if (numberchangecar == 4) {
		auto texture = ResourceManagers::GetInstance()->GetTexture("audi5.tga");
		m_objectplayer = std::make_shared<Sprite2D>(model, shader, texture);
		m_objectplayer->SetSize(70, 100);
		m_objectplayer->Set2DPosition(currentObjectPos.x, currentObjectPos.y);
	}
	
}
bool GSPlay::isCollision(std::shared_ptr<Sprite2D> object1, std::shared_ptr<Sprite2D> object2)
{
	if (object1->GetPosition().x - object1->getWidth() / 2 + 15 > object2->GetPosition().x + object2->getWidth() / 2
		|| object1->GetPosition().x + object1->getWidth() / 2 < object2->GetPosition().x - object2->getWidth() / 2 + 15
		|| object1->GetPosition().y - object1->getHeight() / 2 + 5 > object2->GetPosition().y + object2->getHeight() / 2
		|| object1->GetPosition().y + object1->getHeight() / 2 < object2->GetPosition().y - object2->getHeight() / 2 + 5
		)
	{
		return false;
	}

	return true;
	
}
bool GSPlay::isCollision(std::shared_ptr<AnimationSprite> object1, std::shared_ptr<Sprite2D> object2)
{
	if (object1->GetPosition().x - object1->getWidth() / 2 + 15 > object2->GetPosition().x + object2->getWidth() / 2
		|| object1->GetPosition().x + object1->getWidth() / 2 < object2->GetPosition().x - object2->getWidth() / 2 + 15
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
	m_coins->Draw();
	m_carbg->Draw();
	
	if (endgame) {
		m_endgame->Draw();
		m_endgamecurrentscore->Draw();
		m_gameover->Draw();
	}

	if (!endgame) {
		for (auto it : m_listObsObj)
		{
			it->Draw();
		}
		for (auto it : m_listBlkObj)
		{
			it->Draw();
		}
		for (auto it : m_listAwdObj)
		{
			it->Draw();
		}
	}
	
	
	m_score->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	
}
