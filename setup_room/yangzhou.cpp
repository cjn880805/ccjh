#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"
#include "../std/FightRoom.h"

//   ���ݳ�
#include "../d/yangzhou/yangzhoucity.h"
#include "../d/yangzhou/yangzhou_bingying.h"
#include "../d/yangzhou/yangzhou_caizhu.h"
#include "../d/yangzhou/yangzhou_chaguan.h"
#include "../d/yangzhou/yangzhou_dangpu.h"
#include "../d/yangzhou/yangzhou_datiepu.h"
#include "../d/yangzhou/yangzhou_duchang.h"
#include "../d/yangzhou/yangzhou_kedian.h"
#include "../d/yangzhou/yangzhou_lichunyuan.h"
#include "../d/yangzhou/yangzhou_lichunyuan2.h"
#include "../d/yangzhou/yangzhou_majiu.h"
#include "../d/yangzhou/yangzhou_qianzhuang.h"
#include "../d/yangzhou/yangzhou_shuyuan.h"
#include "../d/yangzhou/yangzhou_wuguan.h"
#include "../d/yangzhou/yangzhou_wumiao.h"
#include "../d/yangzhou/yangzhou_yamen.h"
#include "../d/yangzhou/yangzhou_yaopu.h"
#include "../d/yangzhou/yangzhou_zahuopu.h"
#include "../d/yangzhou/yangzhou_zuixianlou.h"
#include "../d/yangzhou/yangzhou_taohua5.h"
#include "../d/yangzhou/yangzhou_taohua4.h"
#include "../d/yangzhou/yangzhou_taohua3.h"
#include "../d/yangzhou/yangzhou_taohua2.h"
#include "../d/yangzhou/yangzhou_taohua1.h"

#include "../d/yangzhou/yangzhou_dongbei.h"
#include "../d/yangzhou/yangzhou_dongnan.h"
#include "../d/yangzhou/yangzhou_xibei.h"
#include "../d/yangzhou/yangzhou_xinan.h"

//���ݽ���
#include "../d/yzjiaowai/yzjw_beimen.h"
#include "../d/yzjiaowai/yzjw_beiyidao.h"
#include "../d/yzjiaowai/yzjw_dadao.h"
#include "../d/yzjiaowai/yzjw_dongmen.h"
#include "../d/yzjiaowai/yzjw_dongyidao.h"
#include "../d/yzjiaowai/yzjw_jiaowai1.h"
#include "../d/yzjiaowai/yzjw_jiaowai10.h"
#include "../d/yzjiaowai/yzjw_jiaowai11.h"
#include "../d/yzjiaowai/yzjw_jiaowai12.h"
#include "../d/yzjiaowai/yzjw_jiaowai2.h"
#include "../d/yzjiaowai/yzjw_jiaowai3.h"
#include "../d/yzjiaowai/yzjw_jiaowai4.h"
#include "../d/yzjiaowai/yzjw_jiaowai5.h"
#include "../d/yzjiaowai/yzjw_jiaowai6.h"
#include "../d/yzjiaowai/yzjw_jiaowai7.h"
#include "../d/yzjiaowai/yzjw_jiaowai8.h"
#include "../d/yzjiaowai/yzjw_jiaowai9.h"
#include "../d/yzjiaowai/yzjw_milin1.h"
#include "../d/yzjiaowai/yzjw_milin2.h"
#include "../d/yzjiaowai/yzjw_milin3.h"
#include "../d/yzjiaowai/yzjw_milin4.h"
#include "../d/yzjiaowai/yzjw_milin5.h"
#include "../d/yzjiaowai/yzjw_milin6.h"
#include "../d/yzjiaowai/yzjw_milin7.h"
#include "../d/yzjiaowai/yzjw_nanmen.h"
#include "../d/yzjiaowai/yzjw_nanxun.h"
#include "../d/yzjiaowai/yzjw_pomiao.h"
#include "../d/yzjiaowai/yzjw_shanlu1.h"
#include "../d/yzjiaowai/yzjw_shanlu2.h"
#include "../d/yzjiaowai/yzjw_shulin.h"
#include "../d/yzjiaowai/yzjw_tiandi.h"
#include "../d/yzjiaowai/yzjw_wudao.h"
#include "../d/yzjiaowai/yzjw_ximen.h"
#include "../d/yzjiaowai/yzjw_ximenroad.h"
#include "../d/yzjiaowai/yzjw_yixing.h"

CRoom * Load_YangZhou(string room_name)
{
	CRoom * r = NULL;

	//   ���ݳ�
	if(room_name == "���ݳ�")
		r = new CRyangzhoucity();
	else if(room_name == "���ݱ�Ӫ")
		r = new CRYangZhou_bingying();
	else if(room_name == "���ݲ�������")
		r = new CRYangZhou_caizhu();
	else if(room_name == "���ݴ������")
		r = new CRYangZhou_chaguan();
	else if(room_name == "���ݵ���")
		r = new CRYangZhou_dangpu();
	else if(room_name == "���ݴ�����")
		r = new CRYangZhou_datiepu();
	else if(room_name == "���ݶĳ�")
		r = new CRYangZhou_duchang();
	else if(room_name == "���ݿ͵�")
		r = new CRYangZhou_kedian();
	else if(room_name == "��������Ժ")
		r = new CRYangZhou_lichunyuan();
	else if(room_name == "��������Ժ��¥")
		r = new CRYangZhou_lichunyuan2();
	else if(room_name == "�������")
		r = new CRYangZhou_majiu();
	else if(room_name == "����Ǯׯ")
		r = new CRYangZhou_qianzhuang();
	else if(room_name == "������Ժ")
		r = new CRYangZhou_shuyuan();
	else if(room_name == "�������")
		r = new CRYangZhou_wuguan();
	else if(room_name == "��������")
		r = new CRYangZhou_wumiao();
	else if(room_name == "�������Ŵ���")
		r = new CRYangZhou_yamen();
	else if(room_name == "����ҩ��")
		r = new CRYangZhou_yaopu();
	else if(room_name == "�����ӻ���")
		r = new CRYangZhou_zahuopu();
	else if(room_name == "��������¥")
		r = new CRYangZhou_zuixianlou();
	else if(room_name == "�����һ�ƺ")
		r = new CRYangZhou_taohua5();
	else if(room_name == "�����һ���")
		r = new CRYangZhou_taohua4();
	else if(room_name == "�����һ���")
		r = new CRYangZhou_taohua3();
	else if(room_name == "�����һ�Ϫ")
		r = new CRYangZhou_taohua2();
	else if(room_name == "�����һ���")
		r = new CRYangZhou_taohua1();
		
	else if(room_name == "���ݶ���")
		r = new CRyangzhou_dongbei();
	else if(room_name == "���ݶ���")
		r = new CRyangzhou_dongnan();
	else if(room_name == "��������")
		r = new CRyangzhou_xibei();
	else if(room_name == "��������")
		r = new CRyangzhou_xinan();

	//���ݽ���
	if(room_name == "��������")
		r = new CRYZJW_yixing();
	else if(room_name == "�������Ŵ��")
		r = new CRYZJW_ximenroad();
	else if(room_name == "��������")
		r = new CRYZJW_ximen();
	else if(room_name == "���������")
		r = new CRYZJW_wudao();
	else if(room_name == "�������")
		r = new CRYZJW_tiandi();
	else if(room_name == "��������")
		r = new CRYZJW_shulin();
	else if(room_name == "����ɽ·2")
		r = new CRYZJW_shanlu2();
	else if(room_name == "����ɽ·1")
		r = new CRYZJW_shanlu1();
	else if(room_name == "����������")
		r = new CRYZJW_pomiao();
	else if(room_name == "�������")
		r = new CRYZJW_nanxun();
	else if(room_name == "��������")
		r = new CRYZJW_nanmen();
	else if(room_name == "����������7")
		r = new CRYZJW_milin7();
	else if(room_name == "����������6")
		r = new CRYZJW_milin6();
	else if(room_name == "����������5")
		r = new CRYZJW_milin5();
	else if(room_name == "���ݱ���")
		r = new CRYZJW_beimen();
	else if(room_name == "����������3")
		r = new CRYZJW_milin3();
	else if(room_name == "����������2")
		r = new CRYZJW_milin2();
	else if(room_name == "����������1")
		r = new CRYZJW_milin1();
	else if(room_name == "��������9")
		r = new CRYZJW_jiaowai9();
	else if(room_name == "���ݲݵ�8")
		r = new CRYZJW_jiaowai8();
	else if(room_name == "���ݲݵ�7")
		r = new CRYZJW_jiaowai7();
	else if(room_name == "��������6")
		r = new CRYZJW_jiaowai6();
	else if(room_name == "��������5")
		r = new CRYZJW_jiaowai5();
	else if(room_name == "��������4")
		r = new CRYZJW_jiaowai4();
	else if(room_name == "��������3")
		r = new CRYZJW_jiaowai3();
	else if(room_name == "��������2")
		r = new CRYZJW_jiaowai2();
	else if(room_name == "��������12")
		r = new CRYZJW_jiaowai12();
	else if(room_name == "��������11")
		r = new CRYZJW_jiaowai11();
	else if(room_name == "��������10")
		r = new CRYZJW_jiaowai10();
	else if(room_name == "���ݲݵ�1")
		r = new CRYZJW_jiaowai1();
	else if(room_name == "���ݶ����")
		r = new CRYZJW_dongyidao();
	else if(room_name == "���ݶ���")
		r = new CRYZJW_dongmen();
	else if(room_name == "������ʯ���")
		r = new CRYZJW_dadao();
	else if(room_name == "���ݱ����")
		r = new CRYZJW_beiyidao();
	else if(room_name == "����������4")
		r = new CRYZJW_milin4();

	return r;
}