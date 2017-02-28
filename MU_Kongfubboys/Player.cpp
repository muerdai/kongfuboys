#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
: m_waittime(ZERO)
, m_isturn(false)
{
	m_isleftwalk = false;
	m_isup = false;
	m_isrightwalk = false;
	m_isdown = false;
	m_playerpos.x = PLAYERGOUNDX;
	m_playerpos.y = GOUNDY;
	m_frameid = ZERO;
	//m_Hp = HUNDRED;
	m_time = ZERO;
	//m_deadtime = ZERO;
}


CPlayer::~CPlayer()
{
}

/*
* param[in]:
* param[out]:
* ��һ������� ������ ������ ���������ߡ� ��������
*/
void CPlayer::Move()
{
	if (!m_isboxing && !m_iskickaleg && m_Hp)
	{
		GetKeyboard();
		if (m_isrightwalk)        //if turnright,just walk right
		{
			m_waittime++;
			if (m_waittime == FIVE)
			{
				m_waittime = ZERO;
				m_frameid++;
				m_playerpos.x += SIX;
				m_isturn = false;
				if (m_frameid == TWO)
				{

					m_frameid = ZERO;
					m_isrightwalk = false;
				}
			}

		}
		else if (m_isleftwalk)
		{
			m_waittime++;
			if (m_waittime == FIVE)
			{
				m_waittime = ZERO;
				m_frameid++;
				m_playerpos.x -= SIX;
				m_isturn = true;
				if (m_frameid == TWO)
				{

					m_frameid = ZERO;
					m_isleftwalk = false;
				}
			}
		}
		if (m_isdown && !m_isup)
		{
			m_waittime++;
			if (m_waittime == WAITTIME)
			{
				m_frameid = ZERO;
				m_isdown = false;
				m_waittime = ZERO;
			}
		}
	}
		if (m_isup)
		{			
			if (m_playerpos.y >= GOUNDY)
			{
				m_frameid = ZERO;
				m_isup = false;
				m_playerpos.y = GOUNDY;
			}
			if (m_isup)
			{
				m_frameid = SEVEN;
				m_playerpos.y += TWO;
				if (m_isleftwalk)
				{
					m_playerpos.x -= TWO;
					if (m_playerpos.y < GOUNDY)     //����û����ǰ���������˶�
					{
						m_isleftwalk = true;
					}
					else m_isleftwalk = false;
				}
				if (m_isrightwalk)
				{
					m_playerpos.x += TWO;
					if (m_playerpos.y < GOUNDY)
					{
						m_isrightwalk = true;
					}
					else
						m_isrightwalk = false;
				}
				if (m_iskickaleg)
				{
					m_frameid = EIGHT;
					if (m_playerpos.y >=GOUNDY)
						m_iskickaleg = false;
				}
			}
		
		}
}

/*
* param[in]:
* param[out]:
* ��������  z������ x�ǳ�ȭ
*/
void CPlayer::Attack()
{
	if (!m_isup )
	{
		GetKeyboard();
		if (m_isboxing)
		{
			m_waittime++;
			if (m_waittime == WAITTIME)
			{
				m_frameid = ZERO;
				m_waittime = ZERO;
				m_isboxing = false;
			}
			if (m_isleftwalk)
				m_playerpos.x -= TWO;
			if (m_isrightwalk)
				m_playerpos.x += TWO;

		}
		else if (m_iskickaleg)
		{
			m_frameid = TWO;
			m_waittime++;
			if (m_waittime == WAITTIME)
			{
				m_frameid = ZERO;
				m_waittime = ZERO;
				m_iskickaleg = false;
			}
			if (m_isleftwalk)
				m_playerpos.x -= ONE;
			if (m_isrightwalk)
				m_playerpos.x += ONE;

		}
	}
}

\
/*
* param[in]:IplImage* bg
* param[out]:
*��������ͼ�εĶ���
*/

void CPlayer::DrawBack(IplImage* bg)
{
	if (m_playerpos.x <= PLAYERLEFTBOUNDARY)
		m_playerpos.x = PLAYERLEFTBOUNDARY;
	if (m_playerpos.x >= PLAYERRIGHTBOUNDARY)
		m_playerpos.x = PLAYERRIGHTBOUNDARY;
	if (m_playerpos.y <= PLAYERHEIGHTBOUNDARY)
		m_playerpos.y = PLAYERHEIGHTBOUNDARY;
	if (!m_deadtime)
	  CTools::PaintImg(m_img[m_frameid], bg, m_playerpos, m_isturn);
	else
	{
		m_playerpos.y = GOUNDY;
		CTools::PaintImg(m_img[SIX], bg, m_playerpos, m_isturn); 
	}
	char string[HUNDRED];
	_itoa(m_Hp, string, TEN);                //������ת����char
	CTools::Text(bg, string, PLAYERSCOREX, SCOREY);    //��������ʾ��ͼƬ�� 
}





/*
* param[in]:
* param[out]:
* ������ȡ���̰��� �� ���� ������ ���������ߡ� �������� z������ x�ǳ�ȭ
*/
void CPlayer::GetKeyboard()
{
	if (m_Hp)
	{
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			m_isdown = true;
			m_frameid = SEVEN;
			m_waittime = ZERO;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			m_playerpos.y -= TEN;
			m_isup = true;
			m_waittime = ZERO;
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{

			m_isleftwalk = true;

		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{

			m_isrightwalk = true;
		}
		if (GetAsyncKeyState('Z') & 0x8000)
		{
			m_iskickaleg = true;

			m_waittime = ZERO;
		}

		if (GetAsyncKeyState('X') & 0x8000)
		{
			m_isboxing = true;
			m_frameid = FIVE;
			m_waittime = ZERO;
		}
	}
}




