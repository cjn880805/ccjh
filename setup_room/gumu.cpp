#include "stdafx.h"
#include "../server/Room.h"

//��Ĺ
#include "../d/gumu/gumu_fengwu.h"
#include "../d/gumu/gumu_houting.h"
#include "../d/gumu/gumu_liangong.h"
#include "../d/gumu/gumu_xiaowu1.h"
#include "../d/gumu/gumu_xiaowu2.h"
#include "../d/gumu/gumu_xiuxishi.h"
#include "../d/gumu/gumu_mumen.h"
#include "../d/gumu/gumu_caodi2.h"
#include "../d/gumu/gumu_hanshuitan.h"
#include "../d/gumu/gumu_huangshalin.h"
#include "../d/gumu/gumu_kongdi.h"
#include "../d/gumu/gumu_caodi.h"
#include "../d/gumu/gumu_qianting.h"
#include "../d/gumu/gumu_shanlu.h"
#include "../d/gumu/gumu_shulin1.h"
#include "../d/gumu/gumu_xiaoting.h"
#include "../d/gumu/gumu_shulin2.h"
#include "../d/gumu/gumu_zhengting.h"
#include "../d/gumu/gumu_zhufeng.h"

CRoom * Load_GuMu(string room_name)
{
	CRoom * r = NULL;

	//��Ĺ
	if(room_name == "��Ĺ��Ϣ��")
		r = new CRGuMu_xiuxishi();
	else if(room_name == "��Ĺ������С��")
		r = new CRGuMu_xiaowu2();
	else if(room_name == "��ĹС��")
		r = new CRGuMU_xiaowu1();
	else if(room_name == "��ĹĹ��")
		r = new CRGuMu_mumen();
	else if(room_name == "��Ĺ������")
		r = new CRGuMu_liangong();
	else if(room_name == "��Ĺ����")
		r = new CRGuMu_fengwu();
	else if(room_name == "��Ĺ����")
		r = new CRGuMu_houting();
	else if(room_name == "��Ĺ����ɽ����")
		r = new CRGuMu_zhufeng();
	else if(room_name == "��Ĺ����")
		r = new CRGuMu_zhengting();
	else if(room_name == "��ĹС��")
		r = new CRGuMu_xiaoting();
	else if(room_name == "��Ĺ����2")
		r = new CRGuMu_shulin2();
	else if(room_name == "��Ĺ�ݵ�")
		r = new CRGuMu_caodi();
	else if(room_name == "��Ĺɽ·")
		r = new CRGuMu_shanlu();
	else if(room_name == "��Ĺǰ��")
		r = new CRGuMu_qianting();
	else if(room_name == "��Ĺ�յ�")
		r = new CRGuMu_kongdi();
	else if(room_name == "��Ĺ��ɳ��")
		r = new CRGuMu_huangshalin();
	else if(room_name == "��Ĺ��ˮ̶")
		r = new CRGuMu_hanshuitan();
	else if(room_name == "��Ĺ�ݵ�2")
		r = new CRGuMu_caodi2();
	else if(room_name == "��Ĺ����1")
		r = new CRGuMu_shulin1();

	return r;
}
