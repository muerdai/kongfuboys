#pragma once
#include "Person.h"
#include "stdafx.h"
#include"Tools.h"
class CPlayer :public CPerson
{
public:
	CPlayer();
	~CPlayer();
	void Move();           //获取鼠标按键移动、下蹲、跳跃
	void Attack();           //获取鼠标按键攻击 z是踢腿 x是出拳
	void DrawBack(IplImage* bg);
	void GetKeyboard();
	
private:
	bool m_isturn;
	bool m_isleftwalk;            //是否向左走
	bool m_isrightwalk;
	bool m_isup;                 //是否跳跃
	bool m_isdown;               //是否蹲下
	int m_waittime;
};

