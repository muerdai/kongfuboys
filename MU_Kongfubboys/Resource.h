#pragma once

class CResource
{
public:
	CResource();
	~CResource();
	void InitResource();
	void ReleaseResource();
	void ShowFrame();
	IplImage* m_player[NINE];
	IplImage* m_bg;
	IplImage* m_clonebg;
	IplImage* m_enemy_1[SIX];
	//IplImage* m_boom[THREE];
	IplImage* m_start;
	IplImage* m_enemy_2[TWELVE];
	IplImage* m_enemy_3[NINE];
	IplImage* m_enemy_4[EIGHT];
	IplImage* m_level[FOUR];
	IplImage* m_end[FIVE];
};

