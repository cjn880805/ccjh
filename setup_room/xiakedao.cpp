#include "stdafx.h"
#include "../server/Room.h"

//   ���͵�
#include "../d/xiakedao/xiakedao_dating.h"
#include "../d/xiakedao/xiakedao_dongmen.h"
#include "../d/xiakedao/xiakedao_haitan.h"
#include "../d/xiakedao/xiakedao_motianya.h"
#include "../d/xiakedao/xiakedao_mtroad.h"
#include "../d/xiakedao/xiakedao_mtroad1.h"
#include "../d/xiakedao/xiakedao_mtxiaowu.h"
#include "../d/xiakedao/xiakedao_mtyadi.h"
#include "../d/xiakedao/xiakedao_pubu.h"
#include "../d/xiakedao/xiakedao_road1.h"
#include "../d/xiakedao/xiakedao_road6.h"
#include "../d/xiakedao/xiakedao_road7.h"
#include "../d/xiakedao/xiakedao_road8.h"
#include "../d/xiakedao/xiakedao_shanmen.h"
#include "../d/xiakedao/xiakedao_shidong1.h"
#include "../d/xiakedao/xiakedao_shidong2.h"
#include "../d/xiakedao/xiakedao_shidong6.h"
#include "../d/xiakedao/xiakedao_shidong7.h"
#include "../d/xiakedao/xiakedao_shidong8.h"
#include "../d/xiakedao/xiakedao_shishi.h"
#include "../d/xiakedao/xiakedao_shufang.h"
#include "../d/xiakedao/xiakedao_wangyun.h"
#include "../d/xiakedao/xiakedao_wuqiku.h"
#include "../d/xiakedao/xiakedao_xiaodian.h"
#include "../d/xiakedao/xiakedao_xiuxis.h"
#include "../d/xiakedao/xiakedao_yingbin.h"
#include "../d/xiakedao/xiakedao_yongdao.h"

CRoom * Load_XiaKeDao(string room_name)
{
	CRoom * r = NULL;

	//���͵�
	if(room_name == "���͵���̲")
		r = new CRXiaKeDao_haitan();
	else if(room_name == "���͵���")
		r = new CRXiaKeDao_yongdao();
	else if(room_name == "���͵�ӭ����")
		r = new CRXiaKeDao_yingbin();
	else if(room_name == "���͵���Ϣ��")
		r = new CRXiaKeDao_xiuxis();
	else if(room_name == "���͵�С�Ե�")
		r = new CRXiaKeDao_xiaodian();
	else if(room_name == "���͵�������")
		r = new CRXiaKeDao_wuqiku();
	else if(room_name == "���͵�����̨")
		r = new CRXiaKeDao_wangyun();
	else if(room_name == "���͵��鷿")
		r = new CRXiaKeDao_shufang();
	else if(room_name == "���͵�ʯ��")
		r = new CRXiaKeDao_shishi();
	else if(room_name == "���͵�ʯ��8")
		r = new CRXiaKeDao_shidong8();
	else if(room_name == "���͵�ʯ��7")
		r = new CRXiaKeDao_shidong7();
	else if(room_name == "���͵�ʯ��6")
		r = new CRXiaKeDao_shidong6();
	else if(room_name == "���͵�ʯ��2")
		r = new CRXiaKeDao_shidong2();
	else if(room_name == "���͵�ʯ��1")
		r = new CRXiaKeDao_shidong1();
	else if(room_name == "���͵�ɽ��")
		r = new CRXiaKeDao_shanmen();
	else if(room_name == "���͵�һ����")
		r = new CRXiaKeDao_road8();
	else if(room_name == "���͵��б�ʯ")
		r = new CRXiaKeDao_road7();
	else if(room_name == "���͵�ɽ·6")
		r = new CRXiaKeDao_road6();
	else if(room_name == "���͵�ɽ·1")
		r = new CRXiaKeDao_road1();
	else if(room_name == "���͵��ٲ�")
		r = new CRXiaKeDao_pubu();
	else if(room_name == "���͵�����")
		r = new CRXiaKeDao_dating();
	else if(room_name == "���͵�ľ��")
		r = new CRXiaKeDao_mtxiaowu();
	else if(room_name == "���͵�����")
		r = new CRXiaKeDao_mtroad1();
	else if(room_name == "���͵�ɽ·")
		r = new CRXiaKeDao_mtroad();
	else if(room_name == "���͵�Ħ����")
		r = new CRXiaKeDao_motianya();
	else if(room_name == "���͵�����")
		r = new CRXiaKeDao_dongmen();
	else if(room_name == "���͵��µ�")
		r = new CRXiaKeDao_mtyadi();

	return r;
}