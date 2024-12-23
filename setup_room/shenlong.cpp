#include "stdafx.h"
#include "../server/Room.h"

//����
#include "../d/shenlong/shenlong_caoping.h"
#include "../d/shenlong/shenlong_damen.h"
#include "../d/shenlong/shenlong_dating.h"
#include "../d/shenlong/shenlong_haitan.h"
#include "../d/shenlong/shenlong_huanghai.h"
#include "../d/shenlong/shenlong_kongdi.h"
#include "../d/shenlong/shenlong_lin.h"
#include "../d/shenlong/shenlong_road.h"
#include "../d/shenlong/shenlong_xiaowu.h"

CRoom * Load_ShenLong(string room_name)
{
	CRoom * r = NULL;

	//����
	if(room_name == "������С��")
		r = new CRShenLong_xiaowu();
	else if(room_name == "�����̴��")
		r = new CRShenLong_road();
	else if(room_name == "�����̹�ľ��")
		r = new CRShenLong_lin();
	else if(room_name == "�����̿յ�")
		r = new CRShenLong_kongdi();
	else if(room_name == "�����ƺ�")
		r = new CRShenLong_huanghai();
	else if(room_name == "�����̺�̲")
		r = new CRShenLong_haitan();
	else if(room_name == "�����̲�ƺ")
		r = new CRShenLong_caoping();
	else if(room_name == "�����̴���")
		r = new CRShenLong_damen();
	else if(room_name == "�����̴���")
		r = new CRShenLong_dating();


	return r;
}