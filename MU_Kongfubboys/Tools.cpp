#include "stdafx.h"
#include "Tools.h"
#define boomJud 16


CTools::CTools()
{
}


CTools::~CTools()
{
}


void CTools::PaintImg(IplImage* img, IplImage* bg, CvPoint pos, bool isturn)
{
	int i, j;
	int judge = 17;      //without black
	if (img!=NULL)
	{
		for (i = ZERO; i < img->height; i++)
		{
			if (isturn)
			{
				for (j = ZERO; j < img->width; j++)
				{
					int b = CV_IMAGE_ELEM(img, uchar, i, (img->width - j - ONE) * THREE + ZERO);
					int g = CV_IMAGE_ELEM(img, uchar, i, (img->width - j - ONE) * THREE + ONE);
					int r = CV_IMAGE_ELEM(img, uchar, i, (img->width - j - ONE) * THREE + TWO);
					if (b >= judge || g >= judge || r >= judge)  // without black 
					{
						if (j + pos.x>bg->width || j + pos.x <= ZERO)
							continue;
						CV_IMAGE_ELEM(bg, uchar, i + pos.y, (j + pos.x) * THREE + ZERO) = b;
						CV_IMAGE_ELEM(bg, uchar, i + pos.y, (j + pos.x) * THREE + ONE) = g;
						CV_IMAGE_ELEM(bg, uchar, i + pos.y, (j + pos.x) * THREE + TWO) = r;
					}
				}
			}
			else
			{
				for (j = ZERO; j < img->width; j++)
				{
					int b = CV_IMAGE_ELEM(img, uchar, i, j * THREE + ZERO);
					int g = CV_IMAGE_ELEM(img, uchar, i, j * THREE + ONE);
					int r = CV_IMAGE_ELEM(img, uchar, i, j * THREE + TWO);
					if (b >= judge || g >= judge || r >= judge)  // without black 
					{
						if (j + pos.x>bg->width || j + pos.x <= ZERO)
							continue;
						CV_IMAGE_ELEM(bg, uchar, i + pos.y, (j + pos.x) * THREE + ZERO) = b;
						CV_IMAGE_ELEM(bg, uchar, i + pos.y, (j + pos.x) * THREE + ONE) = g;
						CV_IMAGE_ELEM(bg, uchar, i + pos.y, (j + pos.x) * THREE + TWO) = r;
					}
				}
			}
		}
	}
}
/*
*param[in]:pos1 玩家坐标 pos2 敌人坐标
*param[out]:ONE 表示左攻击 -ONE 表示右攻击 TWO 向左走 THREE向右走
*判断攻击或走路
*/

int CTools::IsAttack(CvPoint pos1, CvPoint pos2)
{
	if ((pos2.x - pos1.x) >= CollisionDistanceX)
	{
		if (abs(pos2.x - pos1.x) < AttackDistanceX)
		{
			return ONE;   //ONE 表示left攻击
		}
		else if ((pos2.x - pos1.x) >= AttackDistanceX)
		{
			return TWO;   //TWO 向左走
		}
		/*else if ((pos1.x - pos2.x) >= AttackDistanceX)
		{
			return THREE;   //THREE向右走
		}*/
	}
	if ((pos1.x - pos2.x) >= CollisionDistanceX)
	{
		if (abs(pos1.x - pos2.x) < AttackDistanceX )
		{
			return -ONE;   //-ONE 表示right攻击
		}
		/*else if ((pos2.x - pos1.x) >= AttackDistanceX)
		{
			return TWO;   //TWO 向左走
		}*/
		else if ((pos1.x - pos2.x) >= AttackDistanceX)
		{
			return THREE;   //THREE向右走
		}
	}
	if ((pos2.x - pos1.x) <= SIX*TEN)
		return FOUR;
	if ((pos1.x - pos2.x) <= SIX*TEN )
		return -FOUR;
	return ZERO;

}

/*
*param[in]:posx 横坐标绝对值 posy 纵坐标绝对值 playerimg 玩家图片 enemyimg 敌人图片
*param[out]:true 打到了敌人
*判断是否打到敌人
*/
bool CTools::Judge(int posx, int posy, IplImage* playerimg, IplImage* enemyimg)
{
	if (enemyimg && playerimg)
	{
		for (int i = ZERO; i < enemyimg->height; i++)
		{
			for (int j = ZERO; j < TEN*THREE; j++)
			{
				int r = CV_IMAGE_ELEM(enemyimg, uchar, i, j * THREE + ZERO);
				int g = CV_IMAGE_ELEM(enemyimg, uchar, i, j * THREE + ONE);
				int b = CV_IMAGE_ELEM(enemyimg, uchar, i, j * THREE + TWO);
				if ((r >= boomJud&&g >= boomJud&&b >= boomJud) && (posx + j) < playerimg->width && ((posy + i) < playerimg->height))
				{
					r = CV_IMAGE_ELEM(playerimg, uchar, posy + i, (posx + j) * THREE + ZERO);
					b = CV_IMAGE_ELEM(playerimg, uchar, posy + i, (posx + j) * THREE + ONE);
					g = CV_IMAGE_ELEM(playerimg, uchar, posy + i, (posx + j) * THREE + TWO);

					if (r >= boomJud&&g >= boomJud&&b >= boomJud)
					{
						return true;
					}
				}

			}
		}
	}
	return false;
}


void CTools::Text(IplImage* img, const char* text, int x, int y)
{
	CvFont font;
	double hscale = 0.5;               //字体长度
	double vscale = 0.5;               //字体宽度
	int linewidth = TWO;
	cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX | CV_FONT_ITALIC, hscale, vscale, ZERO, linewidth);
	CvScalar textColor = cvScalar(90, 90, 90);       //字体颜色
	CvPoint textPos = cvPoint(x, y);               //字体位置
	cvPutText(img, text, textPos, &font, textColor);
}


/*bool CTools::IsBoomJudge(CvPoint pos1, CvPoint pos2)
{
	if ((abs(pos2.x - pos1.x) <= BOOMRDISTANCEX && abs(pos2.x - pos1.x) >= BOOMLDISTANCEX))
		return true;
	return false;
}*/
