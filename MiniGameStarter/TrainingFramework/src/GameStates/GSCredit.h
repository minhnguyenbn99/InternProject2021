#pragma once
#include "GameStateBase.h"
#include "GameButton.h"

class GSCredit :
	public GameStateBase
{
public:
	GSCredit();
	~GSCredit();

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
	std::shared_ptr<Sprite2D>				m_panelCredits;
	std::shared_ptr<Text>					m_textGameName;
	std::shared_ptr<Text>					m_textGameName1;
	std::shared_ptr<Text>					m_textGameName2;
	std::shared_ptr<Text>					m_textGameName3;
	std::shared_ptr<Text>					m_textGameName4;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
};