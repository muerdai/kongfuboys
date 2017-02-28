#pragma once
#include"Tools.h"
#ifndef PERSON_H
#define PERSON_H     //用宏定义的方法解决重定义
class CPerson
{
public:
	CPerson();
	 ~CPerson();
	virtual void Move();                 //人物的行走
	virtual void Attack();                //攻击
	virtual void DrawBack(IplImage* bg);
	 IplImage* GetMyImg();
	bool IsDead();
	void SetImage(IplImage* img[],int count);	
	void GetEnemyPoint(CvPoint pos);
	void GetEnemyImg(IplImage* img, int key);	
    CvPoint GetPoint();
	CvPoint m_playerpos;
	CvPoint m_enemypos;          //得到当前敌人的坐标
	int m_time;        //敌人攻击的时候会有个动作延时，这个就是保证敌人攻击一次只会扣一次血量
	int m_Hp;
	int m_deadtime;
	int m_frameid;
	bool m_isboom;
	CvPoint m_boompoint;
	bool m_isboxing;             //是否出拳
	bool m_iskickaleg;           //是否踢腿
	bool m_downshoot;
	bool m_isshoot;
	int m_weapon;             //0是环 1是飞刀
	bool m_isdownkick;             //是否下踢
	bool m_isfly;
	bool m_upfoot;
	IplImage** m_img;
	
};

#endif