#include "stdafx.h"
#include "../server/Room.h"
#include "../server/Char.h"
#include "../std/resident.h"

//��ɽ
#include "../d/huashan/huashan_bingqifang.h"
#include "../d/huashan/huashan_baichi.h"
#include "../d/huashan/huashan_buwei1.h"
#include "../d/huashan/huashan_buwei3.h"
#include "../d/huashan/huashan_canglong.h"
#include "../d/huashan/huashan_changlang.h"
#include "../d/huashan/huashan_chaopath2.h"
#include "../d/huashan/huashan_chaoyang.h"
#include "../d/huashan/huashan_chaoyangpath1.h"
#include "../d/huashan/huashan_chengxiang.h"
#include "../d/huashan/huashan_chufang.h"
#include "../d/huashan/huashan_garden.h"
#include "../d/huashan/huashan_houyuan.h"
#include "../d/huashan/huashan_huixinshi.h"
#include "../d/huashan/huashan_husun.h"
#include "../d/huashan/huashan_jiashan.h"
#include "../d/huashan/huashan_jinsuo.h"
#include "../d/huashan/huashan_jushi.h"
#include "../d/huashan/huashan_laojun.h"
#include "../d/huashan/huashan_lianhua.h"
#include "../d/huashan/huashan_lianpath1.h"
#include "../d/huashan/huashan_luoyan.h"
#include "../d/huashan/huashan_path1.h"
#include "../d/huashan/huashan_pingxinshi.h"
#include "../d/huashan/huashan_qianchi.h"
#include "../d/huashan/huashan_qingke.h"
#include "../d/huashan/huashan_qinshi.h"
#include "../d/huashan/huashan_qunxianguan.h"
#include "../d/huashan/huashan_sgyhole.h"
#include "../d/huashan/huashan_shaluo.h"
#include "../d/huashan/huashan_shangtianti.h"
#include "../d/huashan/huashan_shanhongpb.h"
#include "../d/huashan/huashan_sheshenya.h"
#include "../d/huashan/huashan_shop.h"
#include "../d/huashan/huashan_shufang.h"
#include "../d/huashan/huashan_siguoya.h"
#include "../d/huashan/huashan_songlin.h"
#include "../d/huashan/huashan_square.h"
#include "../d/huashan/huashan_xiaolu1.h"
#include "../d/huashan/huashan_xiuxishi.h"
#include "../d/huashan/huashan_yunmen.h"
#include "../d/huashan/huashan_yuntai.h"
#include "../d/huashan/huashan_yunu.h"
#include "../d/huashan/huashan_yunuci.h"
#include "../d/huashan/huashan_yunupath1.h"
#include "../d/huashan/huashan_yuquan.h"
#include "../d/huashan/huashan_zhandao.h"
#include "../d/huashan/huashan_zhenyue.h"
#include "../d/huashan/huashan_ziqitai.h"
#include "../d/huashan/huashan_zongsuo.h"
#include "../d/huashan/huashancity.h"

//��ɽ��
#include "../d/huashancuen/huashancuen.h"
#include "../d/huashancuen/huashancuen_bighouse1.h"
#include "../d/huashancuen/huashancuen_bighouse2.h"
#include "../d/huashancuen/huashancuen_ehouse1.h"
#include "../d/huashancuen/huashancuen_nwhouse.h"
#include "../d/huashancuen/huashancuen_shack.h"
#include "../d/huashancuen/huashancuen_shop.h"
#include "../d/huashancuen/huashancuen_smithy.h"
#include "../d/huashancuen/huashancuen_temple1.h"
#include "../d/huashancuen/huashancuen_hsroad1.h"

//��������������������
#include "../d/huashan/huashan_pbhoushandong.h"

CRoom * Load_HuaShan(string room_name)
{
	CRoom * r = NULL;

	//��ɽ
    if(room_name == "��ɽ")
		r = new CRHuaShancity();
    else if(room_name == "��ɽ����̨")
		r = new CRHuaShan_ziqitai();
    else if(room_name == "��ɽ������")
		r = new CRHuaShan_zhenyue();
    else if(room_name == "��ɽ����ջ��")
		r = new CRHuaShan_zhandao();
    else if(room_name == "��ɽ��ȪԺ")
		r = new CRHuaShan_yuquan();
    else if(room_name == "��ɽ��Ů��ɽ·")
		r = new CRHuaShan_yunupath1();
    else if(room_name == "��ɽ��Ů��")
		r = new CRHuaShan_yunuci();
    else if(room_name == "��ɽ��Ů��")
		r = new CRHuaShan_yunu();
    else if(room_name == "��ɽ��̨��")
		r = new CRHuaShan_yuntai();
    else if(room_name == "��ɽ����")
		r = new CRHuaShan_yunmen();
    else if(room_name == "��ɽС��")
		r = new CRHuaShan_xiuxishi();
    else if(room_name == "��ɽСɽ·")
		r = new CRHuaShan_xiaolu1();
    else if(room_name == "��ɽ���䳡")
		r = new CRHuaShan_square();
    else if(room_name == "��ɽ������")
		r = new CRHuaShan_songlin();
    else if(room_name == "��ɽ˼����")
		r = new CRHuaShan_siguoya();
    else if(room_name == "��ɽ�鷿")
		r = new CRHuaShan_shufang();
    else if(room_name == "��ɽɽ��С��")
		r = new CRHuaShan_shop();
    else if(room_name == "��ɽ������")
		r = new CRHuaShan_sheshenya();
    else if(room_name == "��ɽɽ���ٲ�")
		r = new CRHuaShan_shanhongpb();
    else if(room_name == "��ɽ������")
		r = new CRHuaShan_shangtianti();
    else if(room_name == "��ɽɯ��ƺ")
		r = new CRHuaShan_shaluo();
    else if(room_name == "��ɽɽ��")
		r = new CRHuaShan_sgyhole();
    else if(room_name == "��ɽȺ�ɹ�")
		r = new CRHuaShan_qunxianguan();
    else if(room_name == "��ɽ����")
		r = new CRHuaShan_qinshi();
    else if(room_name == "��ɽ���ƺ")
		r = new CRHuaShan_qingke();
    else if(room_name == "��ɽǧ�ߴ�")
		r = new CRHuaShan_qianchi();
    else if(room_name == "��ɽƽ��ʯ")
		r = new CRHuaShan_pingxinshi();
    else if(room_name == "��ɽ����")
		r = new CRHuaShan_path1();
    else if(room_name == "��ɽ�����")
		r = new CRHuaShan_luoyan();
    else if(room_name == "��ɽ������С·")
		r = new CRHuaShan_lianpath1();
    else if(room_name == "��ɽ������")
		r = new CRHuaShan_lianhua();		
    else if(room_name == "��ɽ�Ͼ���")
		r = new CRHuaShan_laojun();
    else if(room_name == "��ɽ����")
		r = new CRHuaShan_jushi();
    else if(room_name == "��ɽ������")
		r = new CRHuaShan_jinsuo();
    else if(room_name == "��ɽ��ɽС��")
		r = new CRHuaShan_jiashan();
    else if(room_name == "��ɽ�����")
		r = new CRHuaShan_husun();
    else if(room_name == "��ɽ����ʯ")
		r = new CRHuaShan_huixinshi();
    else if(room_name == "��ɽ��Ժ")
		r = new CRHuaShan_houyuan();
    else if(room_name == "��ɽ��԰")
		r = new CRHuaShan_garden();
    else if(room_name == "��ɽ����")
		r = new CRHuaShan_chufang();
    else if(room_name == "��ɽ������ɽ��")
		r = new CRHuaShan_chengxiang();
    else if(room_name == "��ɽ������С·1")
		r = new CRHuaShan_chaoyangpath1();
    else if(room_name == "��ɽ������")
		r = new CRHuaShan_chaoyang();
    else if(room_name == "��ɽ������С·2")
		r = new CRHuaShan_chaopath2();
    else if(room_name == "��ɽ�ٳ�Ͽ")
		r = new CRHuaShan_baichi();
    else if(room_name == "��ɽ������")
		r = new CRHuaShan_canglong();
    else if(room_name == "��ɽƫ��")
		r = new CRHuaShan_buwei3();
    else if(room_name == "��ɽ������Ϊ��")
		r = new CRHuaShan_buwei1();
    else if(room_name == "��ɽ������")
		r = new CRHuaShan_bingqifang();
    else if(room_name == "��ɽ����")
		r = new CRHuaShan_changlang();

	//��ɽ��
    if(room_name == "��ɽ��")
		r = new CRHuaShancuen();
    else if(room_name == "��ɽ����̳��")
		r = new CRHuaShanCuen_temple1();
    else if(room_name == "��ɽ��������")
		r = new CRHuaShanCuen_smithy();
    else if(room_name == "��ɽ���ӻ���")
		r = new CRHuaShanCuen_shop();
    else if(room_name == "��ɽ�������ǰ��")
		r = new CRHuaShanCuen_bighouse1();
    else if(room_name == "��ɽ����")
		r = new CRHuaShanCuen_nwhouse();
    else if(room_name == "��ɽ����լ")
		r = new CRHuaShanCuen_ehouse1();
    else if(room_name == "��ɽ�����������")
		r = new CRHuaShanCuen_bighouse2();
    else if(room_name == "��ɽ�����")
		r = new CRHuaShanCuen_shack();
    else if(room_name == "��ɽ����ʯ���")
		r = new CRHuaShanCuen_hsroad1();		
	
	//��������������������
	else if(room_name == "��ɽ�ٲ���ɽ��")
		r = new CRHuaShan_pbhoushandong();

	return r;
}