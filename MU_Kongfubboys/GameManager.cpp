#include "stdafx.h"
#include "GameManager.h"
template<typename T,typename B,typename M,typename C>
void CreatPerson(B b,M &m,C c)
{
	T *t = new T;
	t->SetImage(b,c);
	m.push_back(t);
}
CGameManager::CGameManager()
{
	
}


CGameManager::~CGameManager()
{
	m_resource.ReleaseResource();
	if (m_person.size())
	{
		m_person.clear();
		vector<CPerson*>(m_person).swap(m_person);
	}
}

/*
* param[in]:
* param[out]:
* 游戏的初始化
*/
void CGameManager::InitGame()
{
	m_resource.InitResource();
	m_isenemy_1 = true;
	m_isenemy_2 = false;
	m_isstart = false;
	m_isenemy_3 = false;
	m_isenemy_4 = false;
	m_isplayer = false;
	m_ispause = false;
	m_keyword = ZERO;
	m_time = ZERO;
	m_pausenum = ZERO;
	Rank();
}

/*
* param[in]:
* param[out]:
*显示图片
*/
void CGameManager::Show()
{
	if (m_isplayer)
	 m_resource.ShowFrame();
}

/*
* param[in]:
* param[out]:
*整个程序的运行
*/
void CGameManager::Run()
{
	
	PlaySound(TEXT(".\\resources\\BG.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);   //游戏进行音乐
		
	    	
			while (true)
			{

				int key = cvWaitKey(TEN);
				Start();
			if (m_isstart)
			{
					SetAllImage();
					Show();
					Pause(key);
					if (key == 27)
					{
						break;
					}
					if (m_isenemy_1)
						Level_1();
					if (m_isenemy_2)
						Level_2();
					if (m_isenemy_3)
						Level_3();
					if (m_isenemy_4)
						Level_4();
			}
		}
}

/*
* param[in]:
* param[out]:
* 实例化对象，并将它们存入vector中
*/
void CGameManager::SetAllImage()
{
	int i;
	if (m_keyword==ZERO && m_isstart)
	{
		if (m_isenemy_1)
		{
			m_keyword = ONE;
			m_isplayer = true;
			CreatPerson<CPlayer, IplImage**, vector<CPerson*>,int>(m_resource.m_player, m_person,NINE);
			CreatPerson<CEnemy_1, IplImage**, vector<CPerson*>,int>(m_resource.m_enemy_1, m_person,SIX);
			/*CPlayer* m_player = new CPlayer;
			m_player->SetImage(m_resource.m_player);
			
			m_person.push_back(m_player);
			CEnemy_1* m_enemy_1 = new CEnemy_1;
			m_enemy_1->SetImage(m_resource.m_enemy_1);
			m_person.push_back(m_enemy_1);*/
	
		}
		else if (m_isenemy_2)
		{
			m_keyword = ONE;
			m_isplayer = true;
			CreatPerson<CPlayer, IplImage**, vector<CPerson*>, int>(m_resource.m_player, m_person,NINE);
			CreatPerson<CEnemy_2, IplImage**, vector<CPerson*>, int>(m_resource.m_enemy_2, m_person,TWELVE);
			/*CPlayer* m_player = new CPlayer;
			m_player->SetImage(m_resource.m_player);
			m_person.push_back(m_player);
			CEnemy_2* m_enemy_2 = new CEnemy_2;
			m_enemy_2->SetImage(m_resource.m_enemy_2);
			m_person.push_back(m_enemy_2);*/
		}

		else if (m_isenemy_3)
		{
			m_keyword = ONE;
			CreatPerson<CPlayer, IplImage**, vector<CPerson*>, int>(m_resource.m_player, m_person,NINE);
			CreatPerson<CEnemy_3, IplImage**, vector<CPerson*>, int>(m_resource.m_enemy_3, m_person,NINE);
			m_isplayer = true;
			/*CPlayer* m_player = new CPlayer;
			m_player->SetImage(m_resource.m_player);
			m_person.push_back(m_player);
			CEnemy_3* m_enemy_3 = new CEnemy_3;
			m_enemy_3->SetImage(m_resource.m_enemy_3);
			m_person.push_back(m_enemy_3);*/
		}

		else if (m_isenemy_4)
		{
			m_keyword = ONE;
			m_isplayer = true;
			CreatPerson<CPlayer, IplImage**, vector<CPerson*>, int>(m_resource.m_player, m_person,NINE);
			CreatPerson<CEnemy_4, IplImage**, vector<CPerson*>, int>(m_resource.m_enemy_4, m_person,EIGHT);
			/*CPlayer* m_player = new CPlayer;
			m_player->SetImage(m_resource.m_player);
			m_person.push_back(m_player);
			CEnemy_4* m_enemy_4 = new CEnemy_4;
			m_enemy_4->SetImage(m_resource.m_enemy_4);
			m_person.push_back(m_enemy_4);*/
		}		
	}
}

/*
* param[in]:
* param[out]:
* 第一关
*/
void CGameManager::Level_1()
{
	int i;
	m_time++;
	if (m_time < TWELVE*THREE)
	{
		cvShowImage("KongfuBoys", m_resource.m_level[ZERO]);
	}
	else
	{
		if (m_isenemy_1&&m_keyword)
		{
			try{
				if (!m_ispause)
				{
					/*m_person[ZERO]->GetKeyboard();
					m_person[ZERO]->Attack();
					m_person[ZERO]->Move();
					m_person[ZERO]->DrawBack(m_resource.m_bg);
					m_person[ONE]->GetEnemyPoint(m_person[ZERO]->GetPoint());
					m_person[ZERO]->GetEnemyPoint(m_person[ONE]->GetPoint());
					m_person[ONE]->Move();
					m_person[ONE]->Attack();
					m_person[ONE]->DrawBack(m_resource.m_bg);
					m_person[ONE]->GetEnemyImg(m_person[ZERO]->GetMyImg());
					m_person[ZERO]->GetEnemyImg(m_person[ONE]->GetMyImg());*/
					Fight(m_person[ZERO], m_person[ONE]);
					if (m_person[ZERO]->IsDead() || m_person[ONE]->IsDead())
					{
						m_isenemy_1 = false;
						if (m_person[ZERO]->IsDead())
						{
							m_isplayer = false;
							cvShowImage("KongfuBoys", m_resource.m_end[ZERO]);
							fstream f(".\\resources\\rank.txt", ios::app);
							f << ONE << endl;
							f.close();
						}
						if (m_person[ONE]->IsDead())
						{
							m_isenemy_2 = true;
							m_person.clear();
							vector<CPerson*>(m_person).swap(m_person);
							
							if (m_person.size() == ZERO)
							{
								m_keyword = ZERO;
								m_time = ZERO;
								
								//	break;
							}
						}
						
					}
				}
				else
				{
					m_person[ZERO]->DrawBack(m_resource.m_bg);
					m_person[ONE]->DrawBack(m_resource.m_bg);
				}
			}
			catch (...)
			{
				cout << "异常" << endl;
			}
		}
	}
}

///*
//* param[in]:
//* param[out]:
//* 游戏资源的释放和销毁
//*/
//void CGameManager::ReleaseGame()
//{
//	
//}

/*
* param[in]:
* param[out]:
* 第二关
*/
void CGameManager::Level_2()
{
	int i;
	m_time++;
	if (m_time < TWELVE*THREE)
	{
		cvShowImage("KongfuBoys", m_resource.m_level[ONE]);
	}
	else
	{
		if (m_isenemy_2&&m_keyword)
		{
			try{
				if (!m_ispause)
				{
					/*m_person[ZERO]->GetKeyboard();
					m_person[ZERO]->Attack();
					m_person[ZERO]->Move();
					m_person[ZERO]->DrawBack(m_resource.m_bg);
					m_person[ONE]->GetEnemyPoint(m_person[ZERO]->GetPoint());
					m_person[ZERO]->GetEnemyPoint(m_person[ONE]->GetPoint());
					m_person[ONE]->Move();
					m_person[ONE]->Attack();
					m_person[ONE]->DrawBack(m_resource.m_bg);
					m_person[ONE]->GetEnemyImg(m_person[ZERO]->GetMyImg());
					m_person[ZERO]->GetEnemyImg(m_person[ONE]->GetMyImg());*/
					Fight(m_person[ZERO], m_person[ONE]);
					if (m_person[ZERO]->IsDead() || m_person[ONE]->IsDead())
					{
						m_isenemy_2 = false;
						if (m_person[ZERO]->IsDead())
						{
							m_isplayer = false;
							cvShowImage("KongfuBoys", m_resource.m_end[ONE]);
							fstream f(".\\resources\\rank.txt", ios::app);
							f << TWO << endl;
							f.close();
						}
						if (m_person[ONE]->IsDead())
						{
							m_isenemy_3 = true;
							m_person.clear();
							vector<CPerson*>(m_person).swap(m_person);
							if (m_person.size() == ZERO)
							{
								m_keyword = ZERO;
								m_time = ZERO;
								//	break;
							}
						}

					}
				}
				else
				{
					m_person[ZERO]->DrawBack(m_resource.m_bg);
					m_person[ONE]->DrawBack(m_resource.m_bg);
				}
			}
			catch (...)
			{
				cout << "异常" << endl;
			}
		}
	}
}

/*
* param[in]:
* param[out]:
* 第三关
*/
void CGameManager::Level_3()
{
	int i;
	m_time++;
	if (m_time < TWELVE*THREE)
	{
		cvShowImage("KongfuBoys", m_resource.m_level[TWO]);
	}
	else
	{
		if (m_isenemy_3&&m_keyword)
		{
			try{
				if (!m_ispause)
				{
					
					Fight(m_person[ZERO], m_person[ONE]);
					if (m_person[ZERO]->IsDead() || m_person[ONE]->IsDead())
					{
						m_isenemy_3 = false;
						if (m_person[ZERO]->IsDead())
						{
							m_isplayer = false;
							cvShowImage("KongfuBoys", m_resource.m_end[TWO]);
							fstream f(".\\resources\\rank.txt", ios::app);
							f << THREE << endl;
							f.close();
						}
						if (m_person[ONE]->IsDead())
						{
							m_isenemy_4 = true;
							m_person.clear();
							
							vector<CPerson*>(m_person).swap(m_person);
							
							if (m_person.size() == ZERO)
							{
								m_keyword = ZERO;
								m_time = ZERO;
								//	break;
							}
						}

					}
				}
				else
				{
					m_person[ZERO]->DrawBack(m_resource.m_bg);
					m_person[ONE]->DrawBack(m_resource.m_bg);
				}
			}
			catch (...)
			{
				cout << "异常" << endl;
			}
		}
	}
}

/*
* param[in]:
* param[out]:
* 第四关
*/
void CGameManager::Level_4()
{
	int i;
	m_time++;
	if (m_time < TWELVE*THREE)
	{
		cvShowImage("KongfuBoys", m_resource.m_level[THREE]);
	}
	else
	{
		if (m_isenemy_4&&m_keyword)
		{
			try{
				if (!m_ispause)
				{
					
					Fight(m_person[ZERO], m_person[ONE]);
					if (m_person[ZERO]->IsDead() || m_person[ONE]->IsDead())
					{
						m_isenemy_4 = false;
						if (m_person[ZERO]->IsDead())
						{
							m_isplayer = false;
							cvShowImage("KongfuBoys", m_resource.m_end[FOUR]);
							fstream f(".\\resources\\rank.txt", ios::app);
							f << FOUR << endl;
							f.close();
						}
						if (m_person[ONE]->IsDead())
						{
							m_person.clear();
							m_isplayer = false;
							vector<CPerson*>(m_person).swap(m_person);
							if (m_person.size() == ZERO)
							{
								m_keyword = ZERO;
								m_time = ZERO;
								//	break;
							}
							
								cvShowImage("KongfuBoys", m_resource.m_end[THREE]);
							
						}
						
					}
				}
				else
				{
					m_person[ZERO]->DrawBack(m_resource.m_bg);
					m_person[ONE]->DrawBack(m_resource.m_bg);
				}
			}
			catch (...)
			{
				cout << "异常" << endl;
			}
		}
	}
}

/*
* param[in]:
* param[out]:
*开始界面
*/
void CGameManager::Start()
{
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
			m_isstart = true;
		
	}		
			if (!m_isstart)
			{
				cvShowImage("KongfuBoys", m_resource.m_start);
			}
}

/*
* param[in]:key 获取的键盘值
* param[out]:
* 暂停功能 第一次按空格键暂停，第二次又不暂停
*/
void CGameManager::Pause(int key)
{
	if (key==' ')
	{		
		m_pausenum+=ONE;	
		if (m_pausenum == ONE)
		{
			m_ispause = true;
		}
		else if (m_pausenum == TWO)
		{
			m_pausenum = ZERO;
			m_ispause = false;
		}
	}
	
}

/*
* param[in]:
* param[out]:
* 以往达到的最后关卡
*/
void CGameManager::Rank()
{
	int num=0,i=1;
	fstream f(".\\resources\\rank.txt", ios::in);
	cout << "以往达到的最后关卡：" << endl;
	while (!f.eof())
	{
		
		f >> num;
		cout <<"第"<<i<<"次达到的最后关卡"<< num << endl;
		i++;
	}
	f.close();
}


void CGameManager::Fight(CPerson* person1, CPerson* person2)
{
	//person1->GetKeyboard();
	person1->Attack();
	person1->Move();
	person1->DrawBack(m_resource.m_bg);
	person2->GetEnemyPoint(person1->GetPoint());
	person1->GetEnemyPoint(person2->GetPoint());
	person2->Move();
	person2->Attack();
	person2->DrawBack(m_resource.m_bg);
	person1->GetEnemyImg(person2->GetMyImg(),ONE);
	person2->GetEnemyImg(person1->GetMyImg(),ZERO);
	
}
