#include "GSMenu.h"
#include "Camera.h"

GSMenu::GSMenu() : GameStateBase(StateType::STATE_MENU), 
	m_background(nullptr), m_listButton(std::list<std::shared_ptr<GameButton>>{}), m_textGameName(nullptr)
{
}


GSMenu::~GSMenu()
{
}



void GSMenu::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("BGcar5.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// startline
	texture = ResourceManagers::GetInstance()->GetTexture("startLine.tga");
	m_startLine = std::make_shared<Sprite2D>(model, shader, texture);
	m_startLine->Set2DPosition(Globals::screenWidth / 2, 200);
	m_startLine->SetSize(325, 40);

	// carplay1
	texture = ResourceManagers::GetInstance()->GetTexture("audi1.tga");
	m_carplay1 = std::make_shared<Sprite2D>(model, shader, texture);
	m_carplay1->Set2DPosition(240, 280);
	m_carplay1->SetSize(70, 100);

	// carplay2
	texture = ResourceManagers::GetInstance()->GetTexture("audi2.tga");
	m_carplay2 = std::make_shared<Sprite2D>(model, shader, texture);
	m_carplay2->Set2DPosition(360, 280);
	m_carplay2->SetSize(70, 100);

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

	// play button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_play.tga");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2+100);
	button->SetSize(150, 150);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY);
		});
	m_listButton.push_back(button);


	// GS Credit
	texture = ResourceManagers::GetInstance()->GetTexture("btn_help.tga");
	std::shared_ptr<GameButton> buttoncredit = std::make_shared<GameButton>(model, shader, texture);
	buttoncredit->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2 + 280);
	buttoncredit->SetSize(100, 100);
	buttoncredit->SetOnClick(
		[]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_CREDIT);
		}
	);
	m_listButton.push_back(buttoncredit);
	
	// exit button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		exit(0);
		});
	m_listButton.push_back(button);

	// game title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Squirk-RMvV.ttf");
	m_textGameName = std::make_shared< Text>(shader, font, "CAR OBSTACLE", TextColor::RED, 2.f);
	m_textGameName->Set2DPosition(Vector2(160, 150));
}

void GSMenu::Exit()
{
}


void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}


void GSMenu::HandleEvents()
{
}

void GSMenu::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSMenu::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSMenu::HandleMouseMoveEvents(int x, int y)
{
}

void GSMenu::Update(float deltaTime)
{
	m_background->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSMenu::Draw()
{
	
	m_background->Draw();
	m_startLine->Draw();
	m_carplay1->Draw();
	m_carplay2->Draw();
	m_barrel->Draw();
	m_block->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_textGameName->Draw();
}
