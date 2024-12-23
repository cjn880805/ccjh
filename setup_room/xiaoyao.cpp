#include "stdafx.h"
#include "../server/Room.h"
#include "../std/FightRoom.h"
#include "../std/xiaoyao.h"

//��ң��
#include "../d/xiaoyao/xiaoyaocity.h"
#include "../d/xiaoyao/xiaoyao_datiewu.h"
#include "../d/xiaoyao/xiaoyao_gongjiang.h"
#include "../d/xiaoyao/xiaoyao_jiujia.h"
#include "../d/xiaoyao/xiaoyao_muwu.h"
#include "../d/xiaoyao/xiaoyao_shiwu.h"
#include "../d/xiaoyao/xiaoyao_xiaomuwu.h"
#include "../d/xiaoyao/xiaoyao_xiaowu.h"
#include "../d/xiaoyao/xiaoyao_shulin.h"
#include "../d/xiaoyao/xiaoyao_xiaodao1.h"
#include "../d/xiaoyao/xiaoyao_xiaodao2.h"
#include "../d/xiaoyao/xiaoyao_xiaodao3.h"

//��ң��
#include "../d/xiaoyaogu/xiaoyaogucity.h"
#include "../d/xiaoyaogu/xiaoyao_baihu.h"
#include "../d/xiaoyaogu/xiaoyao_damen.h"
#include "../d/xiaoyaogu/xiaoyao_feiling.h"
#include "../d/xiaoyaogu/xiaoyao_huaiyueting.h"
#include "../d/xiaoyaogu/xiaoyao_jinsiting.h"
#include "../d/xiaoyaogu/xiaoyao_jinyuehu.h"
#include "../d/xiaoyaogu/xiaoyao_kongdi.h"
#include "../d/xiaoyaogu/xiaoyao_liangongchang.h"
#include "../d/xiaoyaogu/xiaoyao_liangongshi.h"
#include "../d/xiaoyaogu/xiaoyao_lianwuchang.h"
#include "../d/xiaoyaogu/xiaoyao_muwu.h"
#include "../d/xiaoyaogu/xiaoyao_pubu.h"
#include "../d/xiaoyaogu/xiaoyao_qinglong.h"
#include "../d/xiaoyaogu/xiaoyao_shanding.h"
#include "../d/xiaoyaogu/xiaoyao_shanjiao.h"
#include "../d/xiaoyaogu/xiaoyao_shanlu1.h"
#include "../d/xiaoyaogu/xiaoyao_shanlu2.h"
#include "../d/xiaoyaogu/xiaoyao_shanlu3.h"
#include "../d/xiaoyaogu/xiaoyao_shanlu4.h"
#include "../d/xiaoyaogu/xiaoyao_shanlu5.h"
#include "../d/xiaoyaogu/xiaoyao_shanyao.h"
#include "../d/xiaoyaogu/xiaoyao_shiwu.h"
#include "../d/xiaoyaogu/xiaoyao_xiaojin.h"
#include "../d/xiaoyaogu/xiaoyao_xiaolu1.h"
#include "../d/xiaoyaogu/xiaoyao_xiaolu2.h"
#include "../d/xiaoyaogu/xiaoyao_xiaolu3.h"
#include "../d/xiaoyaogu/xiaoyao_xiaolu4.h"
#include "../d/xiaoyaogu/xiaoyao_xiaowu.h"
#include "../d/xiaoyaogu/xiaoyao_xiaoxibian.h"
#include "../d/xiaoyaogu/xiaoyao_xiaoyuan.h"
#include "../d/xiaoyaogu/xiaoyao_xuanwu.h"
#include "../d/xiaoyaogu/xiaoyao_yuanwai.h"
#include "../d/xiaoyaogu/xiaoyao_zuque.h"

#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu11.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu12.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu13.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu14.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu15.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu16.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu17.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu21.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu22.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu23.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu24.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu25.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu26.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu31.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu32.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu33.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu34.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu35.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu41.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu42.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu43.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu44.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu51.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu52.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu53.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu61.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu62.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu71.h"

#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong11.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong12.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong13.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong14.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong15.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong16.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong17.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong21.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong22.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong23.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong24.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong25.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong26.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong31.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong32.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong33.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong34.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong35.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong41.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong42.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong43.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong44.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong51.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong52.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong53.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong61.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong62.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong71.h"

#include "../d/xiaoyaogu/baihu/xiaoyao_baihu11.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu12.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu13.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu14.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu15.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu16.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu17.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu21.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu22.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu23.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu24.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu25.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu26.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu31.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu32.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu33.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu34.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu35.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu41.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu42.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu43.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu44.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu51.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu52.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu53.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu61.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu62.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu71.h"

#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque11.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque12.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque13.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque14.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque15.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque16.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque17.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque21.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque22.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque23.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque24.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque25.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque26.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque31.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque32.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque33.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque34.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque35.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque41.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque42.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque43.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque44.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque51.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque52.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque53.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque61.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque62.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque71.h"

#include "../d/xiaoyaogu/feiling/xiaoyao_feiling1.h"
#include "../d/xiaoyaogu/feiling/xiaoyao_feiling2.h"
#include "../d/xiaoyaogu/feiling/xiaoyao_feiling3.h"
#include "../d/xiaoyaogu/feiling/xiaoyao_feiling4.h"
#include "../d/xiaoyaogu/feiling/xiaoyao_feiling5.h"
#include "../d/xiaoyaogu/feiling/xiaoyao_feiling6.h"
#include "../d/xiaoyaogu/feiling/xiaoyao_feiling7.h"
#include "../d/xiaoyaogu/feiling/xiaoyao_feiling8.h"
#include "../d/xiaoyaogu/feiling/xiaoyao_feiling9.h"

#include "../d/xiaoyaogu/linglang/xiaoyao_dongmen.h"
#include "../d/xiaoyaogu/linglang/xiaoyao_fudi.h"
#include "../d/xiaoyaogu/linglang/xiaoyao_shishi1.h"
#include "../d/xiaoyaogu/linglang/xiaoyao_shishi2.h"
#include "../d/xiaoyaogu/linglang/xiaoyao_shishi3.h"
#include "../d/xiaoyaogu/linglang/xiaoyao_shishi4.h"

#include "../d/xiaoyaogu/jingzhuang/xiaoyao_biguanshi.h"
#include "../d/xiaoyaogu/jingzhuang/xiaoyao_jingzhuang1.h"
#include "../d/xiaoyaogu/jingzhuang/xiaoyao_jingzhuang2.h"
#include "../d/xiaoyaogu/jingzhuang/xiaoyao_jingzhuang3.h"
#include "../d/xiaoyaogu/jingzhuang/xiaoyao_jingzhuang4.h"
#include "../d/xiaoyaogu/jingzhuang/xiaoyao_jingzhuang5.h"
#include "../d/xiaoyaogu/jingzhuang/xiaoyao_jingzhuang6.h"
#include "../d/xiaoyaogu/jingzhuang/xiaoyao_jingzhuang7.h"

CRoom * Load_XiaoYao(string room_name)
{
	CRoom * r = NULL;

	//��ң��
    if(room_name == "��ң��")
		r = new CRXiaoYaocity();
    else if(room_name == "��ң��С��")
		r = new CRXiaoYao_xiaowu();
    else if(room_name == "��ң��Сľ��")
		r = new CRXiaoYao_xiaomuwu();
    else if(room_name == "��ң�ִ�����")
		r = new CRXiaoYao_datiewu();
    else if(room_name == "��ң��ľ��")
		r = new CRXiaoYao_muwu();
    else if(room_name == "��ң�־Ƽ�")
		r = new CRXiaoYao_jiujia();
    else if(room_name == "��ң�ֹ�����")
		r = new CRXiaoYao_gongjiang();
    else if(room_name == "��ң��ʯ��")
		r = new CRXiaoYao_shiwu();
    else if(room_name == "��ң������")
		r = new CRXiaoYao_shulin();	
	
    else if(room_name == "��ң��С��1")
		r = new CRXiaoYao_xiaodao1();		
    else if(room_name == "��ң��С��2")
		r = new CRXiaoYao_xiaodao2();		
    else if(room_name == "��ң��С��3")
		r = new CRXiaoYao_xiaodao3();	
	
	//��ң��
    else if(room_name == "��ң��")
		r = new CRXiaoYao_city();
   else if(room_name == "��ң��СϪ��")
		r = new CRXiaoYao_xiaoxibian();
	else if(room_name == "��ң��С��")
		r = new CRXiaoYao_xiaojin();
	else if(room_name == "��ң��СԺ")
		r = new CRXiaoYao_xiaoyuan();
	else if(room_name == "��ң��С��")
		r = new CRXiaoYao_xiaowu1();
	else if(room_name == "��ң��ľ��")
		r = new CRXiaoYao_muwu1();
	else if(room_name == "��ң��������")
		r = new CRXiaoYao_liangongchang();
	else if(room_name == "��ң��������")
		r = new CRXiaoYao_liangongshi();
	else if(room_name == "��ң��ʯ��")
		r = new CRXiaoYao_shiwu1();
	else if(room_name == "��ң��Ժ��")
		r = new CRXiaoYao_yuanwai();
	else if(room_name == "��ң��С·1")
		r = new CRXiaoYao_xiaolu1();
	else if(room_name == "��ң��С·2")
		r = new CRXiaoYao_xiaolu2();
	else if(room_name == "��ң��С·3")
		r = new CRXiaoYao_xiaolu3();
	else if(room_name == "��ң��С·4")
		r = new CRXiaoYao_xiaolu4();
	else if(room_name == "��ң��������ɽ·1")
		r = new CRXiaoYao_shanlu1();
	else if(room_name == "��ң��������ɽ·2")
		r = new CRXiaoYao_shanlu2();
	else if(room_name == "��ң��������ɽ·3")
		r = new CRXiaoYao_shanlu3();
	else if(room_name == "��ң��������ɽ·4")
		r = new CRXiaoYao_shanlu4();
	else if(room_name == "��ң��������ɽ·5")
		r = new CRXiaoYao_shanlu5();
	else if(room_name == "��ң�ȿյ�")
		r = new CRXiaoYao_kongdi();
	else if(room_name == "��ң��׷�¹۴���")
		r = new CRXiaoYao_damen();
	else if(room_name == "��ң��׷�¹ۻ���ͥ")
		r = new CRXiaoYao_huaiyueting();
	else if(room_name == "��ң��׷�¹۾�˼ͥ")
		r = new CRXiaoYao_jinsiting();
	else if(room_name == "��ң��׷�¹����䳡")
		r = new CRXiaoYao_lianwuchang();
	else if(room_name == "��ң��������ɽ��")
		r = new CRXiaoYao_shanjiao();
	else if(room_name == "��ң��������ɽ��")
		r = new CRXiaoYao_shanyao();
	else if(room_name == "��ң��������嶥")
		r = new CRXiaoYao_shanding();
	else if(room_name == "��ң�Ⱦ��º�")
		r = new CRXiaoYao_jinyuehu();
	else if(room_name == "��ң���ٲ�")
		r = new CRXiaoYao_pubu();
	else if(room_name == "��ң�ȷ������������")
		r = new CRXiaoYao_feiling();
	else if(room_name == "��ң��������")
		r = new CRXiaoYao_qinglong();
	else if(room_name == "��ң��������")
		r = new CRXiaoYao_xuanwu();
	else if(room_name == "��ң����ȸ��")
		r = new CRXiaoYao_zuque();
	else if(room_name == "��ң�Ȱ׻���")
		r = new CRXiaoYao_baihu();

	else if(room_name == "��ң������������11")
		r = new CRXiaoYao_xuanwu11();
	else if(room_name == "��ң������������12")
		r = new CRXiaoYao_xuanwu12();
	else if(room_name == "��ң������������13")
		r = new CRXiaoYao_xuanwu13();
	else if(room_name == "��ң������������14")
		r = new CRXiaoYao_xuanwu14();
	else if(room_name == "��ң������������15")
		r = new CRXiaoYao_xuanwu15();
	else if(room_name == "��ң������������16")
		r = new CRXiaoYao_xuanwu16();
	else if(room_name == "��ң������������17")
		r = new CRXiaoYao_xuanwu17();
	else if(room_name == "��ң������������21")
		r = new CRXiaoYao_xuanwu21();
	else if(room_name == "��ң������������22")
		r = new CRXiaoYao_xuanwu22();
	else if(room_name == "��ң������������23")
		r = new CRXiaoYao_xuanwu23();
	else if(room_name == "��ң������������24")
		r = new CRXiaoYao_xuanwu24();
	else if(room_name == "��ң������������25")
		r = new CRXiaoYao_xuanwu25();
	else if(room_name == "��ң������������26")
		r = new CRXiaoYao_xuanwu26();
	else if(room_name == "��ң������������31")
		r = new CRXiaoYao_xuanwu31();
	else if(room_name == "��ң������������32")
		r = new CRXiaoYao_xuanwu32();
	else if(room_name == "��ң������������33")
		r = new CRXiaoYao_xuanwu33();
	else if(room_name == "��ң������������34")
		r = new CRXiaoYao_xuanwu34();
	else if(room_name == "��ң������������35")
		r = new CRXiaoYao_xuanwu35();
	else if(room_name == "��ң���������Ĳ�41")
		r = new CRXiaoYao_xuanwu41();
	else if(room_name == "��ң���������Ĳ�42")
		r = new CRXiaoYao_xuanwu42();
	else if(room_name == "��ң���������Ĳ�43")
		r = new CRXiaoYao_xuanwu43();
	else if(room_name == "��ң���������Ĳ�44")
		r = new CRXiaoYao_xuanwu44();
	else if(room_name == "��ң�����������51")
		r = new CRXiaoYao_xuanwu51();
	else if(room_name == "��ң�����������52")
		r = new CRXiaoYao_xuanwu52();
	else if(room_name == "��ң�����������53")
		r = new CRXiaoYao_xuanwu53();
	else if(room_name == "��ң������������61")
		r = new CRXiaoYao_xuanwu61();
	else if(room_name == "��ң������������62")
		r = new CRXiaoYao_xuanwu62();	
	else if(room_name == "��ң������������71")
		r = new CRXiaoYao_xuanwu71();

	else if(room_name == "��ң������������11")
		r = new CRXiaoYao_qinglong11();
	else if(room_name == "��ң������������12")
		r = new CRXiaoYao_qinglong12();
	else if(room_name == "��ң������������13")
		r = new CRXiaoYao_qinglong13();
	else if(room_name == "��ң������������14")
		r = new CRXiaoYao_qinglong14();
	else if(room_name == "��ң������������15")
		r = new CRXiaoYao_qinglong15();
	else if(room_name == "��ң������������16")
		r = new CRXiaoYao_qinglong16();
	else if(room_name == "��ң������������17")
		r = new CRXiaoYao_qinglong17();
	else if(room_name == "��ң������������21")
		r = new CRXiaoYao_qinglong21();
	else if(room_name == "��ң������������22")
		r = new CRXiaoYao_qinglong22();
	else if(room_name == "��ң������������23")
		r = new CRXiaoYao_qinglong23();
	else if(room_name == "��ң������������24")
		r = new CRXiaoYao_qinglong24();
	else if(room_name == "��ң������������25")
		r = new CRXiaoYao_qinglong25();
	else if(room_name == "��ң������������26")
		r = new CRXiaoYao_qinglong26();
	else if(room_name == "��ң������������31")
		r = new CRXiaoYao_qinglong31();
	else if(room_name == "��ң������������32")
		r = new CRXiaoYao_qinglong32();
	else if(room_name == "��ң������������33")
		r = new CRXiaoYao_qinglong33();
	else if(room_name == "��ң������������34")
		r = new CRXiaoYao_qinglong34();
	else if(room_name == "��ң������������35")
		r = new CRXiaoYao_qinglong35();
	else if(room_name == "��ң���������Ĳ�41")
		r = new CRXiaoYao_qinglong41();
	else if(room_name == "��ң���������Ĳ�42")
		r = new CRXiaoYao_qinglong42();
	else if(room_name == "��ң���������Ĳ�43")
		r = new CRXiaoYao_qinglong43();
	else if(room_name == "��ң���������Ĳ�44")
		r = new CRXiaoYao_qinglong44();
	else if(room_name == "��ң�����������51")
		r = new CRXiaoYao_qinglong51();
	else if(room_name == "��ң�����������52")
		r = new CRXiaoYao_qinglong52();
	else if(room_name == "��ң�����������53")
		r = new CRXiaoYao_qinglong53();
	else if(room_name == "��ң������������61")
		r = new CRXiaoYao_qinglong61();
	else if(room_name == "��ң������������62")
		r = new CRXiaoYao_qinglong62();	
	else if(room_name == "��ң������������71")
		r = new CRXiaoYao_qinglong71();

	else if(room_name == "��ң�Ȱ׻�������11")
		r = new CRXiaoYao_baihu11();
	else if(room_name == "��ң�Ȱ׻�������12")
		r = new CRXiaoYao_baihu12();
	else if(room_name == "��ң�Ȱ׻�������13")
		r = new CRXiaoYao_baihu13();
	else if(room_name == "��ң�Ȱ׻�������14")
		r = new CRXiaoYao_baihu14();
	else if(room_name == "��ң�Ȱ׻�������15")
		r = new CRXiaoYao_baihu15();
	else if(room_name == "��ң�Ȱ׻�������16")
		r = new CRXiaoYao_baihu16();
	else if(room_name == "��ң�Ȱ׻�������17")
		r = new CRXiaoYao_baihu17();
	else if(room_name == "��ң�Ȱ׻�������21")
		r = new CRXiaoYao_baihu21();
	else if(room_name == "��ң�Ȱ׻�������22")
		r = new CRXiaoYao_baihu22();
	else if(room_name == "��ң�Ȱ׻�������23")
		r = new CRXiaoYao_baihu23();
	else if(room_name == "��ң�Ȱ׻�������24")
		r = new CRXiaoYao_baihu24();
	else if(room_name == "��ң�Ȱ׻�������25")
		r = new CRXiaoYao_baihu25();
	else if(room_name == "��ң�Ȱ׻�������26")
		r = new CRXiaoYao_baihu26();
	else if(room_name == "��ң�Ȱ׻�������31")
		r = new CRXiaoYao_baihu31();
	else if(room_name == "��ң�Ȱ׻�������32")
		r = new CRXiaoYao_baihu32();
	else if(room_name == "��ң�Ȱ׻�������33")
		r = new CRXiaoYao_baihu33();
	else if(room_name == "��ң�Ȱ׻�������34")
		r = new CRXiaoYao_baihu34();
	else if(room_name == "��ң�Ȱ׻�������35")
		r = new CRXiaoYao_baihu35();
	else if(room_name == "��ң�Ȱ׻����Ĳ�41")
		r = new CRXiaoYao_baihu41();
	else if(room_name == "��ң�Ȱ׻����Ĳ�42")
		r = new CRXiaoYao_baihu42();
	else if(room_name == "��ң�Ȱ׻����Ĳ�43")
		r = new CRXiaoYao_baihu43();
	else if(room_name == "��ң�Ȱ׻����Ĳ�44")
		r = new CRXiaoYao_baihu44();
	else if(room_name == "��ң�Ȱ׻������51")
		r = new CRXiaoYao_baihu51();
	else if(room_name == "��ң�Ȱ׻������52")
		r = new CRXiaoYao_baihu52();
	else if(room_name == "��ң�Ȱ׻������53")
		r = new CRXiaoYao_baihu53();
	else if(room_name == "��ң�Ȱ׻�������61")
		r = new CRXiaoYao_baihu61();
	else if(room_name == "��ң�Ȱ׻�������62")
		r = new CRXiaoYao_baihu62();	
	else if(room_name == "��ң�Ȱ׻�������71")
		r = new CRXiaoYao_baihu71();

	else if(room_name == "��ң����ȸ������11")
		r = new CRXiaoYao_zhuque11();
	else if(room_name == "��ң����ȸ������12")
		r = new CRXiaoYao_zhuque12();
	else if(room_name == "��ң����ȸ������13")
		r = new CRXiaoYao_zhuque13();
	else if(room_name == "��ң����ȸ������14")
		r = new CRXiaoYao_zhuque14();
	else if(room_name == "��ң����ȸ������15")
		r = new CRXiaoYao_zhuque15();
	else if(room_name == "��ң����ȸ������16")
		r = new CRXiaoYao_zhuque16();
	else if(room_name == "��ң����ȸ������17")
		r = new CRXiaoYao_zhuque17();
	else if(room_name == "��ң����ȸ������21")
		r = new CRXiaoYao_zhuque21();
	else if(room_name == "��ң����ȸ������22")
		r = new CRXiaoYao_zhuque22();
	else if(room_name == "��ң����ȸ������23")
		r = new CRXiaoYao_zhuque23();
	else if(room_name == "��ң����ȸ������24")
		r = new CRXiaoYao_zhuque24();
	else if(room_name == "��ң����ȸ������25")
		r = new CRXiaoYao_zhuque25();
	else if(room_name == "��ң����ȸ������26")
		r = new CRXiaoYao_zhuque26();
	else if(room_name == "��ң����ȸ������31")
		r = new CRXiaoYao_zhuque31();
	else if(room_name == "��ң����ȸ������32")
		r = new CRXiaoYao_zhuque32();
	else if(room_name == "��ң����ȸ������33")
		r = new CRXiaoYao_zhuque33();
	else if(room_name == "��ң����ȸ������34")
		r = new CRXiaoYao_zhuque34();
	else if(room_name == "��ң����ȸ������35")
		r = new CRXiaoYao_zhuque35();
	else if(room_name == "��ң����ȸ���Ĳ�41")
		r = new CRXiaoYao_zhuque41();
	else if(room_name == "��ң����ȸ���Ĳ�42")
		r = new CRXiaoYao_zhuque42();
	else if(room_name == "��ң����ȸ���Ĳ�43")
		r = new CRXiaoYao_zhuque43();
	else if(room_name == "��ң����ȸ���Ĳ�44")
		r = new CRXiaoYao_zhuque44();
	else if(room_name == "��ң����ȸ�����51")
		r = new CRXiaoYao_zhuque51();
	else if(room_name == "��ң����ȸ�����52")
		r = new CRXiaoYao_zhuque52();
	else if(room_name == "��ң����ȸ�����53")
		r = new CRXiaoYao_zhuque53();
	else if(room_name == "��ң����ȸ������61")
		r = new CRXiaoYao_zhuque61();
	else if(room_name == "��ң����ȸ������62")
		r = new CRXiaoYao_zhuque62();	
	else if(room_name == "��ң����ȸ������71")
		r = new CRXiaoYao_zhuque71();

	else if(room_name == "��ң�ȷ���֮�����")
		r = new CRXiaoYao_feiling1();
	else if(room_name == "��ң�ȷ���֮ñ")
		r = new CRXiaoYao_feiling2();
	else if(room_name == "��ң�ȷ���֮�Ҽ���")
		r = new CRXiaoYao_feiling3();
	else if(room_name == "��ң�ȷ���֮�����")
		r = new CRXiaoYao_feiling4();
	else if(room_name == "��ң�ȷ���֮��")
		r = new CRXiaoYao_feiling5();
	else if(room_name == "��ң�ȷ���֮�ұ���")
		r = new CRXiaoYao_feiling6();
	else if(room_name == "��ң�ȷ���֮������")
		r = new CRXiaoYao_feiling7();
	else if(room_name == "��ң�ȷ���֮��")
		r = new CRXiaoYao_feiling8();
	else if(room_name == "��ң�ȷ���֮������")
		r = new CRXiaoYao_feiling9();

	else if(room_name == "��ң����ߧ���ض���")
		r = new CRXiaoYao_dongmen();
	else if(room_name == "��ң����ߧ����")
		r = new CRXiaoYao_fudi();
	else if(room_name == "��ң����ߧ����ʯ��1")
		r = new CRXiaoYao_shishi1();
	else if(room_name == "��ң����ߧ����ʯ��2")
		r = new CRXiaoYao_shishi2();
	else if(room_name == "��ң����ߧ����ʯ��3")
		r = new CRXiaoYao_shishi3();
	else if(room_name == "��ң����ߧ����ʯ��4")
		r = new CRXiaoYao_shishi4();

	else if(room_name == "��ң�ȱչ���")
		r = new CRXiaoYao_biguanshi();
	else if(room_name == "��ң�ȴ���Ǿ���1")
		r = new CRXiaoYao_jingzhuang1();
	else if(room_name == "��ң�ȴ���Ǿ���2")
		r = new CRXiaoYao_jingzhuang2();
	else if(room_name == "��ң�ȴ���Ǿ���3")
		r = new CRXiaoYao_jingzhuang3();
	else if(room_name == "��ң�ȴ���Ǿ���4")
		r = new CRXiaoYao_jingzhuang4();
	else if(room_name == "��ң�ȴ���Ǿ���5")
		r = new CRXiaoYao_jingzhuang5();
	else if(room_name == "��ң�ȴ���Ǿ���6")
		r = new CRXiaoYao_jingzhuang6();
	else if(room_name == "��ң�ȴ���Ǿ���7")
		r = new CRXiaoYao_jingzhuang7();

	return r;
}