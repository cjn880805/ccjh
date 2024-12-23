#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"
#include "../std/FightRoom.h"

//   ����
#include "../d/hangzhou/hangzhoucity.h"
#include "../d/hangzhou/hangzhou_baiti.h"
#include "../d/hangzhou/hangzhou_baoshishan.h"
#include "../d/hangzhou/hangzhou_baoshuta.h"
#include "../d/hangzhou/hangzhou_chashi.h"
#include "../d/hangzhou/hangzhou_cuiweiting.h"
#include "../d/hangzhou/hangzhou_dadao1.h"
#include "../d/hangzhou/hangzhou_dadao2.h"
#include "../d/hangzhou/hangzhou_dadao3.h"
#include "../d/hangzhou/hangzhou_dalu1.h"
#include "../d/hangzhou/hangzhou_duanqiao.h"
#include "../d/hangzhou/hangzhou_dxbaodian1.h"
#include "../d/hangzhou/hangzhou_dxbaodian2.h"
#include "../d/hangzhou/hangzhou_fajingsi.h"
#include "../d/hangzhou/hangzhou_fajinsi.h"
#include "../d/hangzhou/hangzhou_fangheting.h"
#include "../d/hangzhou/hangzhou_faxisi.h"
#include "../d/hangzhou/hangzhou_feilaifeng.h"
#include "../d/hangzhou/hangzhou_guozhuang.h"
#include "../d/hangzhou/hangzhou_gushan.h"
#include "../d/hangzhou/hangzhou_gushanpingtai.h"
#include "../d/hangzhou/hangzhou_hongchungqiao.h"
#include "../d/hangzhou/hangzhou_huagang.h"
#include "../d/hangzhou/hangzhou_huanglongdong.h"
#include "../d/hangzhou/hangzhou_huangniling.h"
#include "../d/hangzhou/hangzhou_hupaoquan.h"
#include "../d/hangzhou/hangzhou_jingcisi.h"
#include "../d/hangzhou/hangzhou_jiulou.h"
#include "../d/hangzhou/hangzhou_jiulou2.h"
#include "../d/hangzhou/hangzhou_jujingyuan.h"
#include "../d/hangzhou/hangzhou_lingyinsi.h"
#include "../d/hangzhou/hangzhou_kedian.h"
#include "../d/hangzhou/hangzhou_kedian2.h"
#include "../d/hangzhou/hangzhou_liuheta.h"
#include "../d/hangzhou/hangzhou_liulangqiao.h"
#include "../d/hangzhou/hangzhou_liuzhuang.h"
#include "../d/hangzhou/hangzhou_longhongdong.h"
#include "../d/hangzhou/hangzhou_longjing.h"
#include "../d/hangzhou/hangzhou_manjuelong.h"
#include "../d/hangzhou/hangzhou_maojiabu.h"
#include "../d/hangzhou/hangzhou_marry_room.h"
#include "../d/hangzhou/hangzhou_pinghuqiuyue.h"
#include "../d/hangzhou/hangzhou_qiantang.h"
#include "../d/hangzhou/hangzhou_qingbomen.h"
#include "../d/hangzhou/hangzhou_qinglindong.h"
#include "../d/hangzhou/hangzhou_quyuanbei.h"
#include "../d/hangzhou/hangzhou_road1.h"
#include "../d/hangzhou/hangzhou_road10.h"
#include "../d/hangzhou/hangzhou_road11.h"
#include "../d/hangzhou/hangzhou_road12.h"
#include "../d/hangzhou/hangzhou_road13.h"
#include "../d/hangzhou/hangzhou_road14.h"
#include "../d/hangzhou/hangzhou_road15.h"
#include "../d/hangzhou/hangzhou_road16.h"
#include "../d/hangzhou/hangzhou_road17.h"
#include "../d/hangzhou/hangzhou_road18.h"
#include "../d/hangzhou/hangzhou_road19.h"
#include "../d/hangzhou/hangzhou_road2.h"
#include "../d/hangzhou/hangzhou_road20.h"
#include "../d/hangzhou/hangzhou_road3.h"
#include "../d/hangzhou/hangzhou_road4.h"
#include "../d/hangzhou/hangzhou_road5.h"
#include "../d/hangzhou/hangzhou_road6.h"
#include "../d/hangzhou/hangzhou_road7.h"
#include "../d/hangzhou/hangzhou_road8.h"
#include "../d/hangzhou/hangzhou_road9.h"
#include "../d/hangzhou/hangzhou_shanlu1.h"
#include "../d/hangzhou/hangzhou_shanlu2.h"
#include "../d/hangzhou/hangzhou_shanlu3.h"
#include "../d/hangzhou/hangzhou_shanlu4.h"
#include "../d/hangzhou/hangzhou_shanlu5.h"
#include "../d/hangzhou/hangzhou_shanlu6.h"
#include "../d/hangzhou/hangzhou_shanlu7.h"
#include "../d/hangzhou/hangzhou_shanlu8.h"
#include "../d/hangzhou/hangzhou_shenxudong.h"
#include "../d/hangzhou/hangzhou_shiwudong.h"
#include "../d/hangzhou/hangzhou_shuiledong.h"
#include "../d/hangzhou/hangzhou_shuyuan.h"
#include "../d/hangzhou/hangzhou_suti1.h"
#include "../d/hangzhou/hangzhou_suti2.h"
#include "../d/hangzhou/hangzhou_suti3.h"
#include "../d/hangzhou/hangzhou_suti4.h"
#include "../d/hangzhou/hangzhou_suti5.h"
#include "../d/hangzhou/hangzhou_suti6.h"
#include "../d/hangzhou/hangzhou_suti7.h"
#include "../d/hangzhou/hangzhou_tianwangdian.h"
#include "../d/hangzhou/hangzhou_tiejiangpu.h"
#include "../d/hangzhou/hangzhou_tulu1.h"
#include "../d/hangzhou/hangzhou_xilingqiao.h"
#include "../d/hangzhou/hangzhou_xizhaoshan.h"
#include "../d/hangzhou/hangzhou_yanxiadong.h"
#include "../d/hangzhou/hangzhou_yaodian.h"
#include "../d/hangzhou/hangzhou_yuefen.h"
#include "../d/hangzhou/hangzhou_yuelang.h"
#include "../d/hangzhou/hangzhou_yuhuangsd.h"
#include "../d/hangzhou/hangzhou_yuhuangshan.h"
#include "../d/hangzhou/hangzhou_yuhuangsj.h"
#include "../d/hangzhou/hangzhou_yuquan.h"
#include "../d/hangzhou/hangzhou_wangqingge.h"

#include "../d/hangzhou/hangzhou_huangnididao.h"
#include "../d/hangzhou/hangzhou_duyezuo.h"
#include "../d/hangzhou/hangzhou_duyeyou.h"
#include "../d/hangzhou/hangzhou_lieyandao.h"
#include "../d/hangzhou/hangzhou_zhutiedao.h"

CRoom * Load_HangZhou(string room_name)
{
	CRoom * r = NULL;

	//����
	if(room_name == "����")
		r = new CRhangzhoucity();
	else if(room_name == "������ʯ���1")
		r = new CRhangzhou_road1();
	else if(room_name == "������Ȫ")
		r = new CRhangzhou_yuquan();
	else if(room_name == "�������ɽ��")
		r = new CRhangzhou_yuhuangsj();
	else if(room_name == "�������ɽ")
		r = new CRhangzhou_yuhuangshan();
	else if(room_name == "�������ɽ��")
		r = new CRhangzhou_yuhuangsd();
	else if(room_name == "��������")
		r = new CRhangzhou_yuelang();
	else if(room_name == "��������")
		r = new CRhangzhou_yuefen();
	else if(room_name == "���ݺ�������")
		r = new CRhangzhou_yaodian();
	else if(room_name == "������ϼ��")
		r = new CRhangzhou_yanxiadong();
	else if(room_name == "����Ϧ��ɽ")
		r = new CRhangzhou_xizhaoshan();	
	else if(room_name == "����������")
		r = new CRhangzhou_xilingqiao();
	else if(room_name == "������·")
		r = new CRhangzhou_tulu1();
	else if(room_name == "���ݰ׵�")
		r = new CRhangzhou_baiti();
	else if(room_name == "����������")
		r = new CRhangzhou_tiejiangpu();
	else if(room_name == "�����յ�7")
		r = new CRhangzhou_suti7();
	else if(room_name == "�����յ�6")
		r = new CRhangzhou_suti6();
	else if(room_name == "�����յ�5")
		r = new CRhangzhou_suti5();
	else if(room_name == "�����յ�4")
		r = new CRhangzhou_suti4();
	else if(room_name == "�����յ�3")
		r = new CRhangzhou_suti3();
	else if(room_name == "�����յ�2")
		r = new CRhangzhou_suti2();	
	else if(room_name == "�����յ�1")
		r = new CRhangzhou_suti1();
	else if(room_name == "���ݷ����Ժ")
		r = new CRhangzhou_shuyuan();
	else if(room_name == "����ˮ�ֶ�")
		r = new CRhangzhou_shuiledong();
	else if(room_name == "����ʯ�ݶ�")
		r = new CRhangzhou_shiwudong();
	else if(room_name == "��������")
		r = new CRhangzhou_shenxudong();
	else if(room_name == "����ɽ·8")
		r = new CRhangzhou_shanlu8();
	else if(room_name == "����ɽ·7")
		r = new CRhangzhou_shanlu7();
	else if(room_name == "����ɽ·6")
		r = new CRhangzhou_shanlu6();
	else if(room_name == "����ɽ·5")
		r = new CRhangzhou_shanlu5();
	else if(room_name == "����ɽ·4")
		r = new CRhangzhou_shanlu4();	
	else if(room_name == "����ɽ·3")
		r = new CRhangzhou_shanlu3();
	else if(room_name == "����ɽ·2")
		r = new CRhangzhou_shanlu2();
	else if(room_name == "����ɽ·1")
		r = new CRhangzhou_shanlu1();
	else if(room_name == "������ʯ���9")
		r = new CRhangzhou_road9();
	else if(room_name == "������ʯ���8")
		r = new CRhangzhou_road8();
	else if(room_name == "������ʯ���7")
		r = new CRhangzhou_road7();
	else if(room_name == "������ʯ���6")
		r = new CRhangzhou_road6();
	else if(room_name == "������ʯ���5")
		r = new CRhangzhou_road5();
	else if(room_name == "������ʯ���4")
		r = new CRhangzhou_road4();
	else if(room_name == "������ʯ���3")
		r = new CRhangzhou_road3();	
	else if(room_name == "������ʯ���20")
		r = new CRhangzhou_road20();
	else if(room_name == "������ʯ���2")
		r = new CRhangzhou_road2();
	else if(room_name == "������ʯ���19")
		r = new CRhangzhou_road19();
	else if(room_name == "������ʯ���18")
		r = new CRhangzhou_road18();
	else if(room_name == "������ʯ���17")
		r = new CRhangzhou_road17();
	else if(room_name == "������ʯ���16")
		r = new CRhangzhou_road16();
	else if(room_name == "������ʯ���15")
		r = new CRhangzhou_road15();
	else if(room_name == "������ʯ���14")
		r = new CRhangzhou_road14();
	else if(room_name == "������ʯ���13")
		r = new CRhangzhou_road13();
	else if(room_name == "������ʯ���12")
		r = new CRhangzhou_road12();	
	else if(room_name == "������ʯ���11")
		r = new CRhangzhou_road11();
	else if(room_name == "������ʯ���10")
		r = new CRhangzhou_road10();
	else if(room_name == "������Ժ���")
		r = new CRhangzhou_quyuanbei();
	else if(room_name == "�������ֶ�")
		r = new CRhangzhou_qinglindong();
	else if(room_name == "�����岨��")
		r = new CRhangzhou_qingbomen();
	else if(room_name == "����Ǯ������")
		r = new CRhangzhou_qiantang();
	else if(room_name == "����ƽ������")
		r = new CRhangzhou_pinghuqiuyue();
	else if(room_name == "���ݺ���ׯ")
		r = new CRhangzhou_marry_room();
	else if(room_name == "����é�Ҳ�")
		r = new CRhangzhou_maojiabu();
	else if(room_name == "��������¤")
		r = new CRhangzhou_manjuelong();	
	else if(room_name == "��������")
		r = new CRhangzhou_longjing();
	else if(room_name == "����������")
		r = new CRhangzhou_longhongdong();
	else if(room_name == "������ׯ")
		r = new CRhangzhou_liuzhuang();
	else if(room_name == "����������")
		r = new CRhangzhou_liulangqiao();
	else if(room_name == "����������")
		r = new CRhangzhou_liuheta();
	else if(room_name == "����������")
		r = new CRhangzhou_lingyinsi();
	else if(room_name == "��������")
		r = new CRhangzhou_longjing();
	else if(room_name == "����������")
		r = new CRhangzhou_lingyinsi();
	else if(room_name == "����������͵�")
		r = new CRhangzhou_kedian();
	else if(room_name == "����������͵��¥")
		r = new CRhangzhou_kedian2();
	else if(room_name == "���ݾ۾�԰")
		r = new CRhangzhou_jujingyuan();	
	else if(room_name == "����¥��¥")
		r = new CRhangzhou_jiulou();
	else if(room_name == "����¥��¥��¥")
		r = new CRhangzhou_jiulou2();
	else if(room_name == "���ݾ�����")
		r = new CRhangzhou_jingcisi();
	else if(room_name == "���ݻ���Ȫ")
		r = new CRhangzhou_hupaoquan();
	else if(room_name == "���ݻ�����")
		r = new CRhangzhou_huangniling();
	else if(room_name == "���ݻ�����")
		r = new CRhangzhou_huanglongdong();
	else if(room_name == "���ݻ��۹���")
		r = new CRhangzhou_huagang();
	else if(room_name == "���ݺ鴺��")
		r = new CRhangzhou_hongchungqiao();
	else if(room_name == "���ݹ�ɽƽ̨")
		r = new CRhangzhou_gushanpingtai();
	else if(room_name == "���ݹ�ɽ")
		r = new CRhangzhou_gushan();
	else if(room_name == "���ݹ�ׯ")
		r = new CRhangzhou_guozhuang();	
	else if(room_name == "���ݷ�����")
		r = new CRhangzhou_feilaifeng();
	else if(room_name == "���ݷ�ϲ��")
		r = new CRhangzhou_faxisi();
	else if(room_name == "���ݷź�ͤ")
		r = new CRhangzhou_fangheting();
	else if(room_name == "���ݷ�����")
		r = new CRhangzhou_fajinsi();
	else if(room_name == "���ݷ�����")
		r = new CRhangzhou_fajingsi();
	else if(room_name == "���ݴ��۱���2")
		r = new CRhangzhou_dxbaodian2();
	else if(room_name == "���ݴ��۱���1")
		r = new CRhangzhou_dxbaodian1();
	else if(room_name == "���ݶ���")
		r = new CRhangzhou_duanqiao();
	else if(room_name == "���ݴ�·1")
		r = new CRhangzhou_dalu1();
	else if(room_name == "�����غ����3")
		r = new CRhangzhou_dadao3();	
	else if(room_name == "�����غ����2")
		r = new CRhangzhou_dadao2();
	else if(room_name == "�����غ����1")
		r = new CRhangzhou_dadao1();
	else if(room_name == "���ݴ�΢ͤ")
		r = new CRhangzhou_cuiweiting();
	else if(room_name == "���ݱ�����")
		r = new CRhangzhou_baoshuta();
	else if(room_name == "���ݱ�ʯɽ")
		r = new CRhangzhou_baoshishan();
	else if(room_name == "����������")
		r = new CRhangzhou_tianwangdian();

	else if(room_name == "���������")
		r = new CRhangzhou_wangqingge();
	else if(room_name == "���ݻ���ص�")
		r = new CRhangzhou_huangnididao();
	else if(room_name == "���ݶ�Һ�ص���")
		r = new CRhangzhou_duyezuo();
	else if(room_name == "���ݶ�Һ�ص��Ұ�")
		r = new CRhangzhou_duyeyou();
	else if(room_name == "��������ص�")
		r = new CRhangzhou_lieyandao();
	else if(room_name == "���������ص�")
		r = new CRhangzhou_zhutiedao();

	return r;
}