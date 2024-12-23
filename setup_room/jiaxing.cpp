#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"

//   ���˳�
#include "../d/jiaxing/jiaxing_nanhu.h"
#include "../d/jiaxing/jiaxing_nanmen.h"
#include "../d/jiaxing/jiaxing_tieqiang.h"
#include "../d/jiaxing/jiaxing_yanyu.h"
#include "../d/jiaxing/jiaxingcity.h" 

CRoom * Load_JiaXing(string room_name)
{
	CRoom * r = NULL;

	//   ���˳�
	if(room_name == "���˳�")
		r = new CRjiaxingcity();
	else if(room_name == "������ǹ��")
		r = new CRJiaXing_tieqiang();
	else if(room_name == "��������¥")
		r = new CRJiaXing_yanyu();
	else if(room_name == "�����Ϻ�")
		r = new CRJiaXing_nanhu();
	else if(room_name == "��������")
		r = new CRJiaXing_nanmen();

	return r;
}