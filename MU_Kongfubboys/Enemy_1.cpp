#include "stdafx.h"
#include "Enemy_1.h"


CEnemy_1::CEnemy_1()
: m_keyword(ZERO)
, m_isturn(false)


{
	m_frameid = ZERO;
	m_isleftwalk = false;
	m_isrightwalk = false;
	m_isjump = false;
	m_playerpos.y = GOUNDY;
	m_playerpos.x = ENEMYGOUNDX;
	m_waittime = ZERO;
	srand((unsigned)time(NULL));
	m_randnum = rand() % TWO + ZERO;
}


CEnemy_1::~CEnemy_1()
{
}

/*
* param[in]:
* param[out]:
* 自己的行走
*/
void CEnemy_1::Move()
{
	if (!m_keyword && m_Hp)
	{
		if (CTools::IsAttack(m_enemypos, m_playerpos) == LEFTEMENYWAlk)
		{
			m_waittime = ZERO;
			m_keyword = ONE;
			m_isleftwalk = true;
			m_isboxing = false;
			m_iskickaleg = false;
		}
		else if (CTools::IsAttack(m_enemypos, m_playerpos) == RIGHTEMENYWAlk)
		{
			m_waittime = ZERO;
			m_keyword = ONE;
			m_isrightwalk = true;
			m_isturn = true;
			m_isboxing = false;
			m_iskickaleg = false;
		}
		else if (CTools::IsAttack(m_enemypos, m_playerpos) == FOUR)
		{
			m_waittime = ZERO;
			m_keyword = ONE;
			m_isjump = true;
			if (m_playerpos.x  < PLAYERLEFTBOUNDARY + HUNDRED)
			{
				m_isturn = true;
			}
			
		}
		else if (CTools::IsAttack(m_enemypos, m_playerpos) == -FOUR)
		{
			m_waittime = ZERO;
			m_keyword = ONE;
			m_isturn = true;
			m_isjump = true;
			if (m_playerpos.x  >= PLAYERRIGHTBOUNDARY)
			{
				m_isturn = false;
			}
			
		}
	}
	if (m_isleftwalk)
	{
		m_keyword = ONE;
		m_isturn = false;
		m_waittime++;
		if (m_waittime == FIVE)
		{
			m_waittime = ZERO;
			m_playerpos.x -= EIGHT;
			if (m_isleftwalk)
				m_frameid++;
			if (m_frameid == TWO)
			{
				m_frameid = ZERO;
				m_isleftwalk = false;
				m_keyword = ZERO;
			}

		}

	}
	else if (m_isrightwalk)
	{
		m_isboxing = false;
		m_iskickaleg = false;
		m_keyword = ONE;
		m_waittime++;
		if (m_waittime == FIVE)
		{
			m_waittime = ZERO;
			m_playerpos.x += EIGHT;
			if (m_isrightwalk)
				m_frameid++;
			if (m_frameid == TWO)
			{
				m_frameid = ZERO;
				m_isrightwalk = false;
				m_keyword = ZERO;
			}
		}
	}
	else if (m_isjump)
	{		
		m_waittime++;
		m_frameid = THREE;
		if (m_isturn)
			m_playerpos.x += TEN;
		else
			m_playerpos.x -= TEN;
		   
		if (m_waittime > WAITTIME/TWO && m_waittime < WAITTIME)
			m_playerpos.y += TWELVE*TWO;
		if (m_waittime<WAITTIME / TWO)
			m_playerpos.y -= TWELVE*TWO;
		if (m_waittime == WAITTIME)
		{
			m_isjump = false;
			m_keyword = ZERO;
			m_waittime = ZERO;
			m_frameid = ZERO;
		}
	}
}

/*
* param[in]:
* param[out]:
* 攻击玩家
*/
void CEnemy_1::Attack()
{
	
	if (!m_keyword && !m_isboxing && !m_iskickaleg&& m_Hp)
	{
		if (CTools::IsAttack(m_enemypos, m_playerpos) == LEFTATTACK)
		{
			srand((unsigned)time(NULL));
			m_randnum = rand() % TWO + ZERO;
			m_keyword = ONE;
			m_waittime = ZERO;
			m_isturn = false;
			if (m_randnum == ZERO)
			{
				m_isboxing = true;
			}
			else if (m_randnum == ONE)
			{
				m_iskickaleg = true;

			}
		}
		if (CTools::IsAttack(m_enemypos, m_playerpos) == RIGHTATTACK)
		{
			srand((unsigned)time(NULL));
			m_randnum = rand() % TWO + ZERO;
			m_keyword = ONE;
			m_isturn = true;;
			m_waittime = ZERO;
			if (m_randnum == ZERO)
			{
				m_isboxing = true;
			}
			else if (m_randnum == ONE)
			{
				m_iskickaleg = true;

			}
		}
	}
	if (!m_isleftwalk &&!m_isrightwalk)
	{
		if (m_isboxing)
		{
			m_frameid = FOUR;
			m_waittime++;
			m_keyword = ONE;
			if (m_waittime == WAITTIME)
			{
				m_waittime = ZERO;
				m_frameid = ZERO;
				m_keyword = ZERO;
				while (m_waittime < TEN)        //攻击之后后退
				{
					m_waittime++;
					if (!m_isturn)
						m_playerpos.x += SIX;
					else m_playerpos.x -= SIX;
				}
				if (m_waittime == TEN)
				{
					m_isboxing = false;
					m_waittime = ZERO;
				}

			}
		}
		else if (m_iskickaleg)
		{
			m_keyword = ONE;
			m_frameid = TWO;
			m_waittime++;
			if (m_waittime == WAITTIME)
			{
				m_keyword = ZERO;
				m_frameid = ZERO;
				m_waittime = ZERO;
				while (m_waittime < TEN)
				{
					m_waittime++;
					if (!m_isturn)
						m_playerpos.x += SIX;
					else m_playerpos.x -= SIX;
				}
				if (m_waittime == TEN)
				{
					m_iskickaleg = false;
					m_waittime = ZERO;
				}
			}
		}
	}
}



/*
* param[in]:背景图bg
* param[out]:
*绘制图片
*/
void CEnemy_1::DrawBack(IplImage* bg)
{	
		
	if (m_playerpos.x <= PLAYERLEFTBOUNDARY)
		m_playerpos.x = PLAYERLEFTBOUNDARY;
	if (m_playerpos.x >= PLAYERRIGHTBOUNDARY)
		m_playerpos.x = PLAYERRIGHTBOUNDARY;
	if (!m_deadtime && m_frameid<SIX)
		CTools::PaintImg(m_img[m_frameid], bg, m_playerpos, m_isturn);
	else 
		CTools::PaintImg(m_img[FIVE], bg, m_playerpos, m_isturn);
	
	char string[HUNDRED];
	_itoa(m_Hp, string, TEN);                //将分数转换成char
	CTools::Text(bg, string, ENEMYSCOREX, SCOREY);    //将分数显示在图片上
	
}




