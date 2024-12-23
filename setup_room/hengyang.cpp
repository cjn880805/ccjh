#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"

//   ������
#include "../d/hengyang/hengyangcity.h" 
#include "../d/hengyang/hengyang_chaguan.h" 
#include "../d/hengyang/hengyang_huiyan.h" 
#include "../d/hengyang/hengyang_liufudayuan.h"
#include "../d/hengyang/hengyang_shop.h" 

CRoom * Load_HengYang(string room_name)
{
	CRoom * r = NULL;

	//   ������
	if(room_name == "������")
		r = new CRhengyangcity();
	else if(room_name == "�������")
		r = new CRHengYang_chaguan();
	else if(room_name == "����С��")
		r = new CRHengYang_shop();
	else if(room_name == "����������Ժ")
		r = new CRHengYang_liufudayuan();
	else if(room_name == "��������¥")
		r = new CRHengYang_huiyan();

	return r;
}