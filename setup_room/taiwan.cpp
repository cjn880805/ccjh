#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"

//̨��
#include "../d/taiwan/taiwan_chiqian.h"
#include "../d/taiwan/taiwan_dagou.h"
#include "../d/taiwan/taiwan_dahai.h"
#include "../d/taiwan/taiwan_huangdi.h"
#include "../d/taiwan/taiwan_jilong.h"
#include "../d/taiwan/taiwan_riyuetan.h"
#include "../d/taiwan/taiwan_fengren.h"
#include "../d/taiwan/taiwan_jinku.h"
#include "../d/taiwan/taiwan_jvmin.h"
#include "../d/taiwan/taiwan_lifa.h"
#include "../d/taiwan/taiwan_sixing.h"
#include "../d/taiwan/taiwan_taohua.h"
#include "../d/taiwan/taiwan_xingzheng.h"
#include "../d/taiwan/taiwan_zongtong.h"

CRoom * Load_TaiWan(string room_name)
{
	CRoom * r = NULL;

	//̨��
	if(room_name == "̨������̶")
		r = new CRTaiWan_riyuetan();
	else if(room_name == "̨�弦����")
		r = new CRTaiWan_jilong();
	else if(room_name == "̨��ĵ�")
		r = new CRTaiWan_huangdi();
	else if(room_name == "̨���")
		r = new CRTaiWan_dahai();
	else if(room_name == "̨���Ƕ��")
		r = new CRTaiWan_chiqian();
	else if(room_name == "̨��򹷸�")
		r = new CRTaiWan_dagou();
	else if(room_name == "̨�����Ժ")
		r = new CRTaiWan_fengren();
	else if(room_name == "̨������Ժ���")
		r = new CRTaiWan_jinku();
	else if(room_name == "̨����ҩ������")
		r = new CRTaiWan_jvmin();
	else if(room_name == "̨������Ժ")
		r = new CRTaiWan_lifa();
	else if(room_name == "̨������Ժ˽�̷�")
		r = new CRTaiWan_sixing();
	else if(room_name == "̨���һ�Ժ")
		r = new CRTaiWan_taohua();
	else if(room_name == "̨������Ժ")
		r = new CRTaiWan_xingzheng();
	else if(room_name == "̨����ͨ��")
		r = new CRTaiWan_zongtong();	

	return r;
}