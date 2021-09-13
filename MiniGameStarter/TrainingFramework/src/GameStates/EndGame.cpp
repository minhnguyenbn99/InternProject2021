#include "EndGame.h"
#include "Camera.h"
#include <fstream>
#include <iostream>

using namespace std;
EndGame::EndGame()
{
}


EndGame::~EndGame()
{
}



void EndGame::Init()
{
    auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
    auto texture = ResourceManagers::GetInstance()->GetTexture("BGCar5.tga");

    // background
    auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
    m_background = std::make_shared<Sprite2D>(model, shader, texture);
    m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
    m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

    texture = ResourceManagers::GetInstance()->GetTexture("btn_restart.tga");
    std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
    button->Set2DPosition(300, 500);
    button->SetSize(80, 80);
    button->SetOnClick([]() {
        GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY);
        });
    m_listButton.push_back(button);
   /* int yourscorenumber[100];
    ifstream yourscore ("scorestore.txt");
    for(int i=1; i<=10; i++){
        yourscore >> yourscorenumber[i];
    }*/
   
    texture = ResourceManagers::GetInstance()->GetTexture("EndGame.tga");
    m_endgame = std::make_shared<Sprite2D>(model, shader, texture);
    m_endgame->SetSize(350, 350);
    m_endgame->Set2DPosition(300, 200);
    std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Squirk-RMvV.ttf");
    shader = ResourceManagers::GetInstance()->GetShader("TextShader");
    m_endgamecurrentscore = std::make_shared< Text>(shader, font, "Your Score:", TextColor::RED, 1.1f);
    m_endgamecurrentscore->Set2DPosition(170, 100);
    m_endgamehighscore = std::make_shared< Text>(shader, font, "High Score:", TextColor::RED, 1.1f);
    m_endgamehighscore->Set2DPosition(170, 115);
    

    //std::to_string(scoregame)
}

void EndGame::Exit()
{
}


void EndGame::Pause()
{
}

void EndGame::Resume()
{
}


void EndGame::HandleEvents()
{
}

void EndGame::HandleKeyEvents(int key, bool bIsPressed)
{

}

void EndGame::HandleTouchEvents(int x, int y, bool bIsPressed)
{
    for (auto button : m_listButton)
    {
        if (button->HandleTouchEvents(x, y, bIsPressed))
        {
            break;
        }
    }
}

void EndGame::HandleMouseMoveEvents(int x, int y)
{
}

void EndGame::Update(float deltaTime)
{
    m_background->Update(deltaTime);
    for (auto it : m_listButton)
    {
        it->Update(deltaTime);
    }
}

void EndGame::Draw()
{
    m_background->Draw();
    m_endgame->Draw();
    m_endgamecurrentscore->Draw();
    m_endgamehighscore->Draw();
    for (auto it : m_listButton)
    {
        it->Draw();
    }
}
