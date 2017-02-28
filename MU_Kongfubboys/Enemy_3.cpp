#include "stdafx.h"
#include "Enemy_3.h"

CEnemy_3::CEnemy_3()
: m_keyword(ZERO)
, m_isturn(false)

{
	m_frameid = ZERO;
	m_isleftwalk = false;
	m_isrightwalk = false;
	m_isknife = false;
	m_playerpos.y = GOUNDY;
	m_playerpos.x = ENEMYGOUNDX;
	m_isshoot = false;
	m_isboom = false;
	m_waittime = ZERO;
	srand((unsigned)time(NULL));
	m_randnum = rand() % TWO;
}


CEnemy_3::~CEnemy_3()
{
}


void CEnemy_3::Move()
{
	if (!m_keyword )
	{
		if (CTools::IsAttack(m_enemypos, m_playerpos) == LEFTEMENYWAlk)
		{
			m_waittime = ZERO;
			m_keyword = ONE;
			m_isleftwalk = true;
			m_isdownkick = false;
			m_iskickaleg = false;
		}
		else if (CTools::IsAttack(m_enemypos, m_playerpos) == RIGHTEMENYWAlk)
		{
			m_waittime = ZERO;
			m_keyword = ONE;
			m_isrightwalk = true;
			m_isturn = true;
			m_isdownkick = false;
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
			if (m_playerpos.x + HUNDRED >= PLAYERRIGHTBOUNDARY)
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
		if (m_waittime == FOUR)
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
		m_isdownkick = false;
		m_iskickaleg = false;
		m_keyword = ONE;
		m_waittime++;
		if (m_waittime == FOUR)
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
		m_frameid = FIVE;
		if (m_isturn)
			m_playerpos.x += TEN;
		else
			m_playerpos.x -= TEN;

		if (m_waittime > WAITTIME / TWO && m_waittime < WAITTIME)
			m_playerpos.y += TWELVE*THREE;
		if (m_waittime<WAITTIME / TWO)
			m_playerpos.y -= TWELVE*THREE;
		if (m_waittime == WAITTIME)
		{
			m_isjump = false;
			m_keyword = ZERO;
			m_waittime = ZERO;
			m_frameid = ZERO;
		}
	}
	if (m_isboom)
	{	
		if (m_weapon == ZERO)
		{
			if (m_num)
			{
				if (m_playerpos.x < m_boompoint.x)
				{
					m_boompoint.x -= FIVE;
				}
				if (m_boompoint.x < m_playerpos.x)
				{
					m_boompoint.x += FIVE;
				}
				if (abs(m_playerpos.x - m_boompoint.x) <= TEN)
				{
					m_isboom = false;
					m_num = ZERO;
				}
			}
			else
			{
				if (!m_isturn)
					m_boompoint.x -= FIVE;
				else
					m_boompoint.x += FIVE;

			}
			if (m_boompoint.x <= TEN*TWO || m_boompoint.x >= PLAYERRIGHTBOUNDARY + TEN*TWO)
			{
				m_num = ONE;
			}
		}
		else if (m_weapon == ONE)
		{
			if (m_boompoint.x <= TEN*TWO || m_boompoint.x >= PLAYERRIGHTBOUNDARY + TEN*TWO)
			{
				m_isboom = false;
			}
			if (!m_isturn)
				m_boompoint.x -= FIVE;
			else
				m_boompoint.x += FIVE;
		}
	}
	
}

/*
* param[in]:
* param[out]:
* 攻击玩家
*/
void CEnemy_3::Attack()
{
	if (!m_keyword && !m_isdownkick && !m_iskickaleg && !m_isshoot )
	{	   
		if (CTools::IsAttack(m_enemypos, m_playerpos) == LEFTATTACK)
		  {
			srand((unsigned)time(NULL));
			m_randnum = rand() % FOUR;
			m_keyword = ONE;
			m_waittime = ZERO;
			m_isturn = false;
			if (m_randnum == ZERO || m_randnum==THREE)
			{
				m_isshoot = true;
				m_frameid = FOUR;
				
			}
			else if (m_randnum == ONE)
			{
				m_iskickaleg = true;
			}
			else if (m_randnum == TWO)
			{
				m_isdownkick = true;
			}
			
		}
		
		if (CTools::IsAttack(m_enemypos, m_playerpos) == RIGHTATTACK)
		{
			srand((unsigned)time(NULL));
			m_randnum = rand() % FOUR;
			m_keyword = ONE;
			m_isturn = true;;
			m_waittime = ZERO;
			if (m_randnum == ZERO  || m_randnum==THREE)
			{
				m_isshoot = true;
				m_frameid = FOUR;
			
			}
			else if (m_randnum == ONE)
			{
				m_iskickaleg = true;
			}
			else if (m_randnum == TWO)
			{
				m_isdownkick = true;
			}
		}
		
	}
	if (!m_isleftwalk &&!m_isrightwalk)
	{
		if (m_isdownkick)
		{
			m_frameid = THREE;
			m_waittime++;
			m_keyword = ONE;
			if (m_waittime == WAITTIME)
			{
				m_waittime = ZERO;
				m_frameid = ZERO;
				m_keyword = ZERO;
				while (m_waittime < WAITTIME)        //攻击之后后退
				{
					m_waittime++;
					if (!m_isturn)
						m_playerpos.x += FIVE;
					else m_playerpos.x -= FIVE;
				}
				if (m_waittime == WAITTIME)
				{
					m_isdownkick = false;
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
				while (m_waittime < WAITTIME)
				{
					m_waittime++;
					if (!m_isturn)
						m_playerpos.x += FIVE;
					else m_playerpos.x -= FIVE;
				}
				if (m_waittime == WAITTIME)
				{
					m_iskickaleg = false;
					m_waittime = ZERO;
				}
			}
		}
		else if (m_isshoot)
		{
			m_keyword = ONE;
			m_waittime++;			
			if (m_waittime == WAITTIME)
			{
				m_waittime = ZERO;
				if (m_isshoot)
					m_frameid++;
				if (m_frameid == SIX)
				{
					m_waittime = ZERO;
					m_keyword = ZERO;
					while (m_waittime < TWELVE*TWO)
					{
						m_waittime++;
						if (!m_isturn)
							m_playerpos.x += FIVE;
						else m_playerpos.x -= FIVE;
					}
					if (m_waittime == TWELVE*TWO)
					{
						m_isshoot = false;
						m_waittime = ZERO;
						m_frameid = ZERO;
						m_isboom = true;
						m_weapon = rand() % TWO;
						m_boompoint.x = m_playerpos.x;
						m_boompoint.y = m_playerpos.y + 20;
					}
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
void CEnemy_3::DrawBack(IplImage* bg)
{

	if (m_playerpos.x <= PLAYERLEFTBOUNDARY)
		m_playerpos.x = PLAYERLEFTBOUNDARY;
	if (m_playerpos.x >= PLAYERRIGHTBOUNDARY)
		m_playerpos.x = PLAYERRIGHTBOUNDARY;
	if (!m_deadtime)
	{
		CTools::PaintImg(m_img[m_frameid], bg, m_playerpos, m_isturn);
		if (m_isboom)
		{
			if (m_weapon == ZERO)
				CTools::PaintImg(m_img[SIX], bg, m_boompoint, m_isturn);
			else if (m_weapon == ONE)
				CTools::PaintImg(m_img[SEVEN], bg, m_boompoint, m_isturn);
		}
	}
	else CTools::PaintImg(m_img[EIGHT], bg, m_playerpos, m_isturn);
	char string[HUNDRED];
	_itoa(m_Hp, string, TEN);                //将分数转换成char
	CTools::Text(bg, string, ENEMYSCOREX, SCOREY);    //将分数显示在图片上 
}











