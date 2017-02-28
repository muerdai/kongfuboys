#pragma once
#include "Person.h"
#include "stdafx.h"
#include"Tools.h"
class CEnemy_2 :public CPerson
{
public:
	CEnemy_2();
	~CEnemy_2();
	void Move();
	void Attack();
	void DrawBack(IplImage* bg);

private:
	
	int m_randnum;   //����ѡ�����Ȼ��ȭ
	int m_keyword;   //��·��ʱ�����ȡ�����ȭ,�õ����ܶ�ι�����keyword=0ʱ�����ж��Ƿ���·�򹥻�
	
	int m_waittime;             //������ʱ�������û�����һ������
	int m_boomtime;
	bool m_isjump;
	
	
	bool m_isdown;               //�Ƿ����
	


	bool m_isleftwalk;            //�Ƿ�������
	bool m_isrightwalk;
	bool m_isturn;

};

