#pragma once

#include "Person.h"
#include "stdafx.h"
#include"Tools.h"
#include"Player.h"
class CEnemy_1 :public CPerson
{
public:
	CEnemy_1();
	~CEnemy_1();
	void Move();
	void Attack();
	void DrawBack(IplImage* bg);
	
private:
	int m_randnum;   //����ѡ�����Ȼ��ȭ
	int m_keyword;   //��·��ʱ�����ȡ�����ȭ,�õ����ܶ�ι�����keyword=0ʱ�����ж��Ƿ���·�򹥻�
	
	int m_waittime;             //������ʱ�������û�����һ������
	
	bool m_isjump;               //�Ƿ�jump
	
	bool m_isleftwalk;            //�Ƿ�������
	bool m_isrightwalk;
	bool m_isturn;


	
};

