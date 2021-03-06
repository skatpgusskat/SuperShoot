#pragma once
#include "Bullet.h"
#include "Castle.h"
#include "Camera.h"
#include "Monster.h"
#include <list>
#include "Stage.h"
#include "event_listener.h"
enum GAME_STATE{
	READY,
	SHOOT
};
class Game : public EventListener
{
public:
	Game(void);
	~Game(void);

	void Update(float dTime);

	void StartShoot(float x, float y);
	void ScreenClicked(float x, float y);
	void BulletCollideWithGround();
	void BulletCollideWithMonster();
	Monster* NewMonster();

	
	void Notify(event::EventHeader& event);

	std::list<Monster*>* GetMonsterList()	{ return &monster_list_; }
	Camera* GetCamera()						{ return &camera_; }
	Bullet* GetBullet()						{ return &bullet_; }
	Castle* GetCastle()						{ return castle_; }

	int GetStageNumber()					{ return stage_.GetNowStage();	}
	int GetCastleHP()						{ return castle_->GetHP();		}
	int GetAppearedMonsterCount()			{ return stage_.GetAppearedMonsterCount(); }
	int GetNowStageMonsterCount()			{ return stage_.GetNowStageMonsterCount(); }

private:
	//STATE : READY
	void BeforeReady();
	void AfterReady();
	//STATE : SHOOT
	void BeforeShoot();
	void AfterShoot();


	Camera camera_;
	Bullet bullet_;
	Castle * castle_;
	Stage stage_;
	
	std::list<Monster*> monster_list_;
};

extern GAME_STATE g_game_state_;

extern Game * g_game;