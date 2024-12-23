#include "stdafx.h"
#include "../server/Room.h"

//��ɽ
#include "../d/hengshan/hengshancity.h"
#include "../d/hengshan/hengshan_banshan.h"
#include "../d/hengshan/hengshan_beimen.h"
#include "../d/hengshan/hengshan_cangjingdian.h"
#include "../d/hengshan/hengshan_chidifeng.h"
#include "../d/hengshan/hengshan_dadian.h"
#include "../d/hengshan/hengshan_denggaotai.h"
#include "../d/hengshan/hengshan_fangguangsi.h"
#include "../d/hengshan/hengshan_fuyansi.h"
#include "../d/hengshan/hengshan_heishatan.h"
#include "../d/hengshan/hengshan_houdian.h"
#include "../d/hengshan/hengshan_jiayingmen.h"
#include "../d/hengshan/hengshan_jigaoming.h"
#include "../d/hengshan/hengshan_kuixingge.h"
#include "../d/hengshan/hengshan_lingxingmen.h"
#include "../d/hengshan/hengshan_liuyunping.h"
#include "../d/hengshan/hengshan_mojingtai.h"
#include "../d/hengshan/hengshan_nantaisi.h"
#include "../d/hengshan/hengshan_nantian.h"
#include "../d/hengshan/hengshan_sansheng.h"
#include "../d/hengshan/hengshan_shanjian.h"
#include "../d/hengshan/hengshan_shanlu1.h"
#include "../d/hengshan/hengshan_shanlu10.h"
#include "../d/hengshan/hengshan_shanlu11.h"
#include "../d/hengshan/hengshan_shanlu12.h"
#include "../d/hengshan/hengshan_shanlu13.h"
#include "../d/hengshan/hengshan_shanlu14.h"
#include "../d/hengshan/hengshan_shanlu2.h"
#include "../d/hengshan/hengshan_shanlu3.h"
#include "../d/hengshan/hengshan_shanlu4.h"
#include "../d/hengshan/hengshan_shanlu5.h"
#include "../d/hengshan/hengshan_shanlu6.h"
#include "../d/hengshan/hengshan_shanlu7.h"
#include "../d/hengshan/hengshan_shanlu8.h"
#include "../d/hengshan/hengshan_shanlu9.h"
#include "../d/hengshan/hengshan_shiziyan.h"
#include "../d/hengshan/hengshan_shuiliandong.h"
#include "../d/hengshan/hengshan_shuzhuangtai.h"
#include "../d/hengshan/hengshan_tianzhu.h"
#include "../d/hengshan/hengshan_wangritai.h"
#include "../d/hengshan/hengshan_wangyuetai.h"
#include "../d/hengshan/hengshan_yubeiting.h"
#include "../d/hengshan/hengshan_yushulou.h"
#include "../d/hengshan/hengshan_zhengchuan.h"
#include "../d/hengshan/hengshan_zhongting.h"
#include "../d/hengshan/hengshan_zhurongdian.h"
#include "../d/hengshan/hengshan_zhurongfeng.h"
#include "../d/hengshan/hengshan_hsroad3.h"

CRoom * Load_HengShan(string room_name)
{
	CRoom * r = NULL;

	//��ɽ
    if(room_name == "��ɽ")
		r = new CRHengShancity();
    else if(room_name == "��ɽף�ڷ�")
		r = new CRHengShan_zhurongfeng();
    else if(room_name == "��ɽף�ڵ�")
		r = new CRHengShan_zhurongdian();
    else if(room_name == "��ɽ��ͤ")
		r = new CRHengShan_zhongting();
    else if(room_name == "��ɽ������")
		r = new CRHengShan_zhengchuan();
    else if(room_name == "��ɽ����¥")
		r = new CRHengShan_yushulou();
    else if(room_name == "��ɽ����ͤ")
		r = new CRHengShan_yubeiting();
    else if(room_name == "��ɽ����̨")
		r = new CRHengShan_wangyuetai();
    else if(room_name == "��ɽ����̨")
		r = new CRHengShan_wangritai();
    else if(room_name == "��ɽ������")
		r = new CRHengShan_tianzhu();
    else if(room_name == "��ɽ��ױ̨")
		r = new CRHengShan_shuzhuangtai();
    else if(room_name == "��ɽˮ����")
		r = new CRHengShan_shuiliandong();
    else if(room_name == "��ɽʨ����")
		r = new CRHengShan_shiziyan();
    else if(room_name == "��ɽɽ·9")
		r = new CRHengShan_shanlu9();
    else if(room_name == "��ɽɽ·8")
		r = new CRHengShan_shanlu8();
    else if(room_name == "��ɽɽ·7")
		r = new CRHengShan_shanlu7();
    else if(room_name == "��ɽɽ·6")
		r = new CRHengShan_shanlu6();
    else if(room_name == "��ɽɽ·5")
		r = new CRHengShan_shanlu5();
    else if(room_name == "��ɽ��ɽͤ")
		r = new CRHengShan_banshan();
    else if(room_name == "��ɽɽ·3")
		r = new CRHengShan_shanlu3();
    else if(room_name == "��ɽɽ·2")
		r = new CRHengShan_shanlu2();
    else if(room_name == "��ɽɽ·14")
		r = new CRHengShan_shanlu14();
    else if(room_name == "��ɽɽ·13")
		r = new CRHengShan_shanlu13();
    else if(room_name == "��ɽɽ·12")
		r = new CRHengShan_shanlu12();
    else if(room_name == "��ɽɽ·11")
		r = new CRHengShan_shanlu11();
    else if(room_name == "��ɽɽ·10")
		r = new CRHengShan_shanlu10();
    else if(room_name == "��ɽɽ·1")
		r = new CRHengShan_shanlu1();
    else if(room_name == "��ɽɽ��")
		r = new CRHengShan_shanjian();
    else if(room_name == "��ɽ������")
		r = new CRHengShan_sansheng();
    else if(room_name == "��ɽ������")
		r = new CRHengShan_nantian();
    else if(room_name == "��ɽ��̨��")
		r = new CRHengShan_nantaisi();
    else if(room_name == "��ɽĥ��̨")
		r = new CRHengShan_mojingtai();
    else if(room_name == "��ɽ����ƺ")
		r = new CRHengShan_liuyunping();
    else if(room_name == "��ɽ������")
		r = new CRHengShan_lingxingmen();
    else if(room_name == "��ɽ���Ǹ�")
		r = new CRHengShan_kuixingge();
    else if(room_name == "��ɽ������̨")
		r = new CRHengShan_jigaoming();
    else if(room_name == "��ɽ��Ӧ��")
		r = new CRHengShan_jiayingmen();
    else if(room_name == "��ɽ���")
		r = new CRHengShan_houdian();
    else if(room_name == "��ɽ��ɳ̶")
		r = new CRHengShan_heishatan();
    else if(room_name == "��ɽ������")
		r = new CRHengShan_fuyansi();
    else if(room_name == "��ɽ������")
		r = new CRHengShan_fangguangsi();
    else if(room_name == "��ɽ�Ǹ�̨")
		r = new CRHengShan_denggaotai();
    else if(room_name == "��ɽ���")
		r = new CRHengShan_dadian();
    else if(room_name == "��ɽ��۷�")
		r = new CRHengShan_chidifeng();
    else if(room_name == "��ɽ�ؾ���")
		r = new CRHengShan_cangjingdian();
    else if(room_name == "��ɽ������")
		r = new CRHengShan_beimen();
    else if(room_name == "��ɽɽ·4")
		r = new CRHengShan_shanlu4();
    else if(room_name == "��ɽ����·")
		r = new CRHengShan_hsroad3();

	return r;
}