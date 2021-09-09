#pragma once

#include "GameStateBase.h"
//#include "Sprite2D.h"

class Sprite2D;
class Sprite3D;
class Text;
class GameButton;
class ObjectObstacle;

class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

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
	void	changecar();
	void	removeobs(int numberobs);
	bool	isCollision(std::shared_ptr<Sprite2D> o1, std::shared_ptr<Sprite2D> o2);
	void	setdifficult(int scoregame);


private:
	std::shared_ptr<Sprite2D>				m_barrel;
	std::shared_ptr<Sprite2D>				m_block;
	std::shared_ptr<Sprite2D>	m_background;
	std::shared_ptr<Sprite2D>	m_objectplayer;
	std::shared_ptr<Text>		m_score;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::list<std::shared_ptr<ObjectObstacle>> m_listObs;
	std::vector<std::shared_ptr<ObjectObstacle>> m_listObsObj;
	float	m_spawnEnemyTime;
	int scoregame;
	float difficultgame;
	bool nocollision;
};

