#pragma once
#include "stdafx.h"
class CTools
{
public:
	CTools();
	~CTools();
	static void PaintImg(IplImage* img, IplImage* bg, CvPoint pos, bool isturn);
	static int IsAttack(CvPoint pos1, CvPoint pos2);
	static bool Judge(int posx, int posy, IplImage* playerimg, IplImage* enemyimg);
	static void Text(IplImage* img, const char* text, int x, int y);
	//static bool IsBoomJudge(CvPoint pos1, CvPoint pos2);
};

