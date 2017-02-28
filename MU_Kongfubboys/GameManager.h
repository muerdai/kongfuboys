#pragma once
#include "Resource.h"
#include "Player.h"
#include "Enemy_1.h"
#include "Enemy_2.h"
#include "Enemy_3.h"
#include "Enemy_4.h"
#include "Person.h"
class CGameManager
{
public:
	CGameManager();
	~CGameManager();
	void InitGame();
	void Show();
	void Run();
	void SetAllImage();
	void Level_1();
	//void ReleaseGame();
	void Level_2();
	void Level_3();
	void Level_4();
	void Rank();
	void Pause(int key);
private:
	CResource m_resource;
	vector<CPerson*> m_person;	
	bool m_isenemy_1;
	bool m_isenemy_2;
	bool m_isenemy_3;
	bool m_isenemy_4;
	bool m_ispause;
	bool m_isstart;
	int m_keyword;               //0ʱʵ��������1ʱ����ʵ��������
	int m_time;                 //��ʱ
	void Start();
	bool m_isplayer;            //����Ƿ����
	int m_pausenum;             //1��ͣ 2��ʼ
	
public:
	void Fight(CPerson* person1, CPerson* person2);
};

