#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"

//   ����
#include "../d/fuzhou/fuzhoucity.h"
#include "../d/fuzhou/fuzhou_biaoju.h"
#include "../d/fuzhou/fuzhou_jiulou.h"
#include "../d/fuzhou/fuzhou_laozhai.h"
#include "../d/fuzhou/fuzhou_rongcheng.h"
#include "../d/fuzhou/fuzhou_rongcheng2.h"
#include "../d/fuzhou/fuzhou_wuxiang.h"
#include "../d/fuzhou/fuzhou_xiangyang.h"
#include "../d/fuzhou/fuzhou_xiaochang.h"
#include "../d/fuzhou/fuzhou_xichansi.h"
#include "../d/fuzhou/fuzhou_yongquan.h"
#include "../d/fuzhou/fuzhou_zahuopu.h"
#include "../d/fuzhou/fuzhou_houyuan.h"
#include "../d/fuzhou/fuzhou_xiwuchang.h"
#include "../d/fuzhou/fuzhou_neizhai.h"
#include "../d/fuzhou/fuzhou_zhengting.h"
#include "../d/fuzhou/fuzhou_yamen.h"
#include "../d/fuzhou/fuzhou_nanmen.h"
#include "../d/fuzhou/fuzhou_fzroad.h"

#include "../d/fuzhou/fuzhou_xi.h"
#include "../d/fuzhou/fuzhou_dong.h"
#include "../d/fuzhou/fuzhou_nan.h"

CRoom * Load_FuZhou(string room_name)
{
	CRoom * r = NULL;

	//  ����
	if(room_name == "����")
		r = new CRfuzhoucity();
	else if(room_name == "�����ӻ���")
		r = new CRfuzhou_zahuopu();
	else if(room_name == "����ӿȪ��")
		r = new CRfuzhou_yongquan();
	else if(room_name == "�����ᶽ����")
		r = new CRfuzhou_yamen();
	else if(room_name == "����������")
		r = new CRfuzhou_xichansi();
	else if(room_name == "����У��")
		r = new CRfuzhou_xiaochang();
	else if(room_name == "����������")
		r = new CRfuzhou_xiangyang();
	else if(room_name == "����������")
		r = new CRfuzhou_wuxiang();
	else if(room_name == "�����ų���")
		r = new CRfuzhou_rongcheng();
	else if(room_name == "�����ų����¥")
		r = new CRfuzhou_rongcheng2();
	else if(room_name == "���ݸ����ھ�")
		r = new CRfuzhou_biaoju();
	else if(room_name == "����������լ")
		r = new CRfuzhou_laozhai();
	else if(room_name == "����ζ��ζ")
		r = new CRfuzhou_jiulou();
	else if(room_name == "���ݸ����ھ�����")
		r = new CRfuzhou_zhengting();
	else if(room_name == "���ݸ����ھֺ�Ժ")
		r = new CRfuzhou_houyuan();
	else if(room_name == "���ݸ����ھ���լ")
		r = new CRfuzhou_neizhai();
	else if(room_name == "���ݸ����ھ�ϰ�䳡")
		r = new CRfuzhou_xiwuchang();
	else if(room_name == "��������")
		r = new CRfuzhou_nanmen();
	else if(room_name == "�������д��")
		r = new CRfuzhou_fzroad();
		
	else if(room_name == "������")
		r = new CRfuzhou_xi();
	else if(room_name == "���ݶ�")
		r = new CRfuzhou_dong();
	else if(room_name == "������")
		r = new CRfuzhou_nan();

	//���ó�����
	if(r) r->set("city", 1);

	return r;
}