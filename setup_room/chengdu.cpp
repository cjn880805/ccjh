#include "stdafx.h"
#include "../std/RField.h"
#include "../std/resident.h"

//   �ɶ�
#include "../d/chengdu/chengducity.h"
#include "../d/chengdu/chengdu_bingqidian.h"
#include "../d/chengdu/chengdu_wuhoucigate.h"
#include "../d/chengdu/chengdu_wuguan.h"
#include "../d/chengdu/chengdu_wangjianglou.h"
#include "../d/chengdu/chengdu_tidufu.h"
#include "../d/chengdu/chengdu_kedian2.h"
#include "../d/chengdu/chengdu_kedian.h"
#include "../d/chengdu/chengdu_jiudian.h"
#include "../d/chengdu/chengdu_caotang.h"
#include "../d/chengdu/chengdu_yaodian.h"
#include "../d/chengdu/chengdu_nanheqiao.h"
#include "../d/chengdu/chengdu_fuheqiaon.h"
#include "../d/chengdu/chengdu_path.h"
#include "../d/chengdu/chengdu_fuheqiaone.h"

#include "../d/chengdu/chengdu_dong.h"
#include "../d/chengdu/chengdu_xi.h"
#include "../d/chengdu/chengdu_zhong.h"

CRoom * Load_ChengDu(string room_name)
{
	CRoom * r = NULL;

	//�ɶ�
	if(room_name == "�ɶ�")
		r = new CRchengducity();
	else if(room_name == "�ɶ��ᶽ��")
		r = new CRChengDu_tidufu();
	else if(room_name == "�ɶ�������ҩ��")
		r = new CRChengDu_yaodian();
	else if(room_name == "�ɶ����������")
		r = new CRChengDu_wuhoucigate();
	else if(room_name == "�ɶ���ţ���")
		r = new CRChengDu_wuguan();
	else if(room_name == "�ɶ�����¥")
		r = new CRChengDu_wangjianglou();
	else if(room_name == "�ɶ��������¥")
		r = new CRChengDu_kedian2();
	else if(room_name == "�ɶ�������")
		r = new CRChengDu_kedian();
	else if(room_name == "�ɶ��񶼾�¥")
		r = new CRChengDu_jiudian();
	else if(room_name == "�ɶ��Ÿ�����")
		r = new CRChengDu_caotang();
	else if(room_name == "�ɶ�������")
		r = new CRChengDu_bingqidian();
	else if(room_name == "�ɶ�Ϫ��С·")
		r = new CRChengDu_path();
	else if(room_name == "�ɶ��Ϻ���")
		r = new CRChengDu_nanheqiao();
	else if(room_name == "�ɶ�������")
		r = new CRChengDu_fuheqiaon();
	else if(room_name == "�ɶ���������")
		r = new CRChengDu_fuheqiaone();

	else if(room_name == "�ɶ���")
		r = new CRchengdu_xi();
	else if(room_name == "�ɶ���")
		r = new CRchengdu_dong();
	else if(room_name == "�ɶ���")
		r = new CRchengdu_zhong();

	return r;
}