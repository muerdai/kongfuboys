#pragma once
#include "Person.h"
#include "stdafx.h"
#include"Tools.h"
class CEnemy_3 :public CPerson
{
public:
	CEnemy_3();
	~CEnemy_3();
	void Move();
	void Attack();
	
	void DrawBack(IplImage* bg);
	
private:
	
	int m_num;   //飞镖能返回
	int m_randnum;   //随意选择踢腿或打拳
	int m_keyword;   //走路的时候不踢腿、不打拳,让敌人能多次攻击，keyword=0时才能判断是否走路或攻击
	bool m_isjump;
	int m_waittime;             //动作延时，好让用户看到一个过程	
	bool m_isknife;               //是否飞刀
	bool m_isleftwalk;            //是否向左走
	bool m_isrightwalk;
	bool m_isturn;


};

