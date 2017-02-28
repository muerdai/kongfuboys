#include "stdafx.h"
#include "Person.h"


CPerson::CPerson()
: m_iskickaleg(false)
, m_isboxing(false)
, m_isshoot(false)
, m_isdownkick(false)
, m_isfly(false)
, m_upfoot(false)
{
	m_Hp = HUNDRED;
	m_deadtime = ZERO;
	m_frameid = ZERO;
	m_isboom = false;
	m_weapon = TWO;
	m_isdownkick = false;
}


CPerson::~CPerson()
{
}


void CPerson::Move()
{
}


void CPerson::Attack()
{
}

/*
* param[in]:IplImage* img[], int count
* param[out]:
*传入需要的图片
*/
void CPerson::SetImage(IplImage* img[], int count)
{
	int i=0;
	m_img = new IplImage*[count];
	//m_playerimg = new IplImage*[count];
	for (; i < count; i++)
	{
		//m_playerimg[i] = img[i];
		m_img[i] = img[i];
	}
}

/*
* param[in]:背景图bg
* param[out]:
*绘制图片
*/
void CPerson::DrawBack(IplImage* bg)
{
}


/*
* param[in]:CvPoint pos
* param[out]:
*得到敌人坐标
*/
void CPerson::GetEnemyPoint(CvPoint pos)
{	
		m_enemypos = pos;
}



/*
* param[in]:IplImage* img,int key
* param[out]:
*得到敌人当前图片
*/
void CPerson::GetEnemyImg(IplImage* img,int key)
{
	if (img != NULL)
	{
		if (((CTools::IsAttack(m_playerpos, m_enemypos) == RIGHTATTACK || CTools::IsAttack(m_playerpos, m_enemypos) == LEFTATTACK)))
		{
			m_time++;
			if (m_time == ONE)
			{
				if (key == ZERO)
				{
					if (CTools::Judge(abs(m_playerpos.x - m_enemypos.x), abs(m_playerpos.y - m_enemypos.y), img, m_img[m_frameid]))
					{
						if (m_Hp)
						{
							
							m_Hp -= TEN;
						}
					}
				}
				else
				{
				
					if (CTools::Judge(abs(m_playerpos.x - m_enemypos.x), abs(m_playerpos.y - m_enemypos.y), m_img[m_frameid], img))
					{
						if (m_Hp)
							m_Hp -= TEN;
					}
				}
			}
			if (m_time == WAITTIME)
				m_time = ZERO;
		}
	}
}


/*
* param[in]:
* param[out]:
*得到自己当前图片
*/
IplImage* CPerson::GetMyImg()
{
	if (m_isboom)
	{
		if (m_weapon == ZERO)
			return m_img[SIX];
		else if (m_weapon == ONE)
			return m_img[SEVEN];
		else return m_img[ELEVEN];
	}
	else if (m_downshoot || m_isboxing || m_iskickaleg || m_isshoot || m_isfly || m_upfoot)
		return m_img[m_frameid];
	else return NULL;
	
	
}

/*
* param[in]:
* param[out]:
*得到自己当前坐标
*/
CvPoint CPerson::GetPoint()
{
	if (m_isboom)
		return m_boompoint;
	else return m_playerpos;
}

/*
* param[in]:
* param[out]:
*判断是否死亡
*/
bool CPerson::IsDead()
{
	if (m_Hp>ZERO)
		return false;
	else
	{
		m_deadtime++;
		if (m_deadtime >= TEN*SIX)
		{
			return true;
			m_deadtime = ZERO;
		}
		else
			return false;
	}
}


