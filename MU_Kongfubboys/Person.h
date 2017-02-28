#pragma once
#include"Tools.h"
#ifndef PERSON_H
#define PERSON_H     //�ú궨��ķ�������ض���
class CPerson
{
public:
	CPerson();
	 ~CPerson();
	virtual void Move();                 //���������
	virtual void Attack();                //����
	virtual void DrawBack(IplImage* bg);
	 IplImage* GetMyImg();
	bool IsDead();
	void SetImage(IplImage* img[],int count);	
	void GetEnemyPoint(CvPoint pos);
	void GetEnemyImg(IplImage* img, int key);	
    CvPoint GetPoint();
	CvPoint m_playerpos;
	CvPoint m_enemypos;          //�õ���ǰ���˵�����
	int m_time;        //���˹�����ʱ����и�������ʱ��������Ǳ�֤���˹���һ��ֻ���һ��Ѫ��
	int m_Hp;
	int m_deadtime;
	int m_frameid;
	bool m_isboom;
	CvPoint m_boompoint;
	bool m_isboxing;             //�Ƿ��ȭ
	bool m_iskickaleg;           //�Ƿ�����
	bool m_downshoot;
	bool m_isshoot;
	int m_weapon;             //0�ǻ� 1�Ƿɵ�
	bool m_isdownkick;             //�Ƿ�����
	bool m_isfly;
	bool m_upfoot;
	IplImage** m_img;
	
};

#endif