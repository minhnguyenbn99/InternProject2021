#pragma once

#include "GameStateBase.h"
//#include "Sprite2D.h"

class Sprite2D;
class Sprite3D;
class Text;
class GameButton;
class ObjectObstacle;
class AnimationSprite;
class ParallelBG;
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
	void	changecar(int numberchange);
	void	removeobs(int numberobs);
	void	removecoin(int numberobs);
	bool	isCollision(std::shared_ptr<Sprite2D> o1, std::shared_ptr<Sprite2D> o2);
	bool	isCollision(std::shared_ptr<AnimationSprite> o1, std::shared_ptr<Sprite2D> o2);
	void	setdifficult(int scoregame);
	void    spawnObstacle(float deltaTime);
	void	spawnCoins(float deltaTime);


private:
	std::shared_ptr<ObjectObstacle>				m_barrel;
	std::shared_ptr<ObjectObstacle>				m_block;
	std::shared_ptr<ParallelBG>	m_background;
	std::shared_ptr<Sprite2D>	m_objectplayer;
	std::shared_ptr<Text>		m_score;
	std::shared_ptr<Text>		m_endgamecredit;
	std::shared_ptr<Sprite2D> m_endgame;
	std::shared_ptr<AnimationSprite> m_coins;
	std::shared_ptr<AnimationSprite> m_boom;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::list<std::shared_ptr<GameButton>>	m_listButton1;
	std::list<std::shared_ptr<ObjectObstacle>> m_listObs;
	std::vector<std::shared_ptr<AnimationSprite>> m_listObsObj;
	std::vector<std::shared_ptr<AnimationSprite>> m_listAwdObj;
	std::vector<std::shared_ptr<ObjectObstacle>> m_listBlkObj;
	std::shared_ptr<Text>		m_endgamecurrentscore;
	std::shared_ptr<Text>		m_gameover;
	bool endgame;
	float	m_spawnEnemyTime;
	float	m_spawnAwardTime;
	int scoregame;
	float difficultgame;
	bool nocollision;
	int highscore;
	float	m_time;
	
};

