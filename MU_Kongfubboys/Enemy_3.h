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
	
	int m_num;   //�����ܷ���
	int m_randnum;   //����ѡ�����Ȼ��ȭ
	int m_keyword;   //��·��ʱ�����ȡ�����ȭ,�õ����ܶ�ι�����keyword=0ʱ�����ж��Ƿ���·�򹥻�
	bool m_isjump;
	int m_waittime;             //������ʱ�������û�����һ������	
	bool m_isknife;               //�Ƿ�ɵ�
	bool m_isleftwalk;            //�Ƿ�������
	bool m_isrightwalk;
	bool m_isturn;


};

