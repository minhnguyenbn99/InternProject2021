#pragma once
#include "GameStateBase.h"
#include "GameButton.h"
//#include "GameObject.h"

class GSMenu :
	public GameStateBase
{
public:
	GSMenu();
	~GSMenu();

	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	void	HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw() override;

private:
	std::shared_ptr<Sprite2D>				m_background;
	std::shared_ptr<Sprite2D>				m_startLine;
	std::shared_ptr<Sprite2D>				m_carplay1;
	std::shared_ptr<Sprite2D>				m_carplay2;
	std::shared_ptr<Sprite2D>				m_barrel;
	std::shared_ptr<Sprite2D>				m_block;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::shared_ptr<Text>					m_textGameName;

};

