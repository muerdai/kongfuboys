#pragma once
#include "Person.h"
#include "stdafx.h"
#include"Tools.h"
class CPlayer :public CPerson
{
public:
	CPlayer();
	~CPlayer();
	void Move();           //��ȡ��갴���ƶ����¶ס���Ծ
	void Attack();           //��ȡ��갴������ z������ x�ǳ�ȭ
	void DrawBack(IplImage* bg);
	void GetKeyboard();
	
private:
	bool m_isturn;
	bool m_isleftwalk;            //�Ƿ�������
	bool m_isrightwalk;
	bool m_isup;                 //�Ƿ���Ծ
	bool m_isdown;               //�Ƿ����
	int m_waittime;
};

