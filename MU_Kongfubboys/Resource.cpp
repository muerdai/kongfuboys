#include "stdafx.h"
#include "Resource.h"
template<typename T ,int size>
void ReleaseImg(T t)   //º¯ÊýÄ£°å
{
	int i;
	for (i = ZERO; i < size; i++)
	{
		cvReleaseImage(&t[i]);
	}
}
CResource::CResource()
{
}


CResource::~CResource()
{
}


void CResource::InitResource()
{
	cvNamedWindow("KongfuBoys");
	m_bg = cvLoadImage(".\\resources\\BackGround\\BG.jpg");
	m_start = cvLoadImage(".\\resources\\BackGround\\begin.jpg");
	m_clonebg = cvCloneImage(m_bg);
	char filename[50];
	int i;
	for (i = ZERO; i < NINE; i++)
	{
		sprintf_s(filename, ".\\resources\\Player\\Player_%d.jpg",i);
		m_player[i] = cvLoadImage(filename, ONE);
	}
	for (i = ZERO; i < SIX; i++)
	{
		sprintf_s(filename, ".\\resources\\Enemy_1\\enemy_%d.jpg", i);
		m_enemy_1[i] = cvLoadImage(filename, ONE);
	}
	for (i = ZERO; i < EIGHT; i++)
	{
		sprintf_s(filename, ".\\resources\\Enemy_4\\%d.jpg", i);
		m_enemy_4[i] = cvLoadImage(filename, ONE);
	}

	for (i = ZERO; i < TWELVE; i++)
	{
		sprintf_s(filename, ".\\resources\\Enemy_2\\%d.jpg", i);
		m_enemy_2[i] = cvLoadImage(filename, ONE);
	}

	for (i = ZERO; i < NINE; i++)
	{
		sprintf_s(filename, ".\\resources\\Enemy_3\\%d.jpg", i);
		m_enemy_3[i] = cvLoadImage(filename, ONE);
	}

	for (i = ZERO; i < FOUR; i++)
	{
		sprintf_s(filename, ".\\resources\\Gametips\\Level_%d.jpg", i);
		m_level[i] = cvLoadImage(filename, ONE);
	}

	for (i = ZERO; i < FIVE; i++)
	{
		sprintf_s(filename, ".\\resources\\Gametips\\%d.jpg", i);
		m_end[i] = cvLoadImage(filename, ONE);
	}
}


void CResource::ReleaseResource()
{
	
	ReleaseImg<IplImage**, NINE> (m_player);
	ReleaseImg<IplImage**, SIX>(m_enemy_1);	
	ReleaseImg<IplImage**, EIGHT>(m_enemy_4);	
	ReleaseImg<IplImage**, TWELVE>(m_enemy_2);
	ReleaseImg<IplImage**, NINE>(m_enemy_3);	
	ReleaseImg<IplImage**, FOUR>(m_level);
	ReleaseImg<IplImage**, FIVE>(m_end);
	cvReleaseImage(&m_bg);
	cvReleaseImage(&m_clonebg);
	cvReleaseImage(&m_start);
	cvDestroyAllWindows();

	/*for ( i = ZERO; i < EIGHT; i++)
	cvReleaseImage(&m_enemy_4[i]);*/
	/*for (i = ZERO; i < FOUR; i++)
	{
		cvReleaseImage(&m_level[i]);
		cvReleaseImage(&m_end[i]);
	}	
		cvReleaseImage(&m_end[FOUR]);
	*/
	/*for (i = ZERO; i < SIX; i++)
	   cvReleaseImage(&m_enemy_1[i]);
	int i;
	/*for (i = ZERO; i < NINE; i++)
		cvReleaseImage(&m_player[i]);*/
	
}


void CResource::ShowFrame()
{
	cvShowImage("KongfuBoys", m_bg);
	cvCopy(m_clonebg, m_bg);
}
