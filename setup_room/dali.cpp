#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"
#include "../std/FightRoom.h"

//�����
#include "../d/dali/dali_bingqiku.h"
#include "../d/dali/dalicity.h"
#include "../d/dali/dali_bingying.h" 
#include "../d/dali/dali_chengyipu.h"
#include "../d/dali/dali_chufang.h"
#include "../d/dali/dali_gongmen.h"
#include "../d/dali/dali_majiu.h"
#include "../d/dali/dali_neiting.h"
#include "../d/dali/dali_piandian.h"
#include "../d/dali/dali_qiandian.h"
#include "../d/dali/dali_shufang.h"
#include "../d/dali/dali_sikong.h"
#include "../d/dali/dali_sima.h"
#include "../d/dali/dali_situ.h"
#include "../d/dali/dali_stoneshop.h"
#include "../d/dali/dali_taiheju.h" 
#include "../d/dali/dali_taiheju2.h" 
#include "../d/dali/dali_tusifu.h" 
#include "../d/dali/dali_tusiyishi.h"
#include "../d/dali/dali_wangfugate.h"
#include "../d/dali/dali_wfdating.h"
#include "../d/dali/dali_xiuxishi.h"
#include "../d/dali/dali_yaopu.h"
#include "../d/dali/dali_yushanfang.h"
#include "../d/dali/dali_zhangfang.h"
#include "../d/dali/dali_zhengdian.h"
#include "../d/dali/dali_zonglichu.h"
#include "../d/dali/dali_road5.h"
#include "../d/dali/dalidong.h"
#include "../d/dali/dalixi.h"
//����Ƕ�
#include "../d/dalieast/dalieast_yangcanfang.h"
#include "../d/dalieast/dalieast_bijishan.h"
#include "../d/dalieast/dalieast_banshan.h"
#include "../d/dalieast/dalieast_buxiongbu.h"
#include "../d/dalieast/dalieast_chahuashan1.h"
#include "../d/dalieast/dalieast_chahuashan2.h"
#include "../d/dalieast/dalieast_chahuashan3.h"
#include "../d/dalieast/dalieast_chahuashan4.h"
#include "../d/dalieast/dalieast_chahuashan5.h"
#include "../d/dalieast/dalieast_chahuashan6.h"
#include "../d/dalieast/dalieast_dadieshui.h"
#include "../d/dalieast/dalieast_dalangan1.h"
#include "../d/dalieast/dalieast_dianchi.h"
#include "../d/dalieast/dalieast_heilongling.h"
#include "../d/dalieast/dalieast_hudiequan.h"
#include "../d/dalieast/dalieast_jingzhuang1.h"
#include "../d/dalieast/dalieast_jingzhuang2.h"
#include "../d/dalieast/dalieast_jingzhuang3.h"
#include "../d/dalieast/dalieast_jingzhuang4.h"
#include "../d/dalieast/dalieast_jingzhuang5.h"
#include "../d/dalieast/dalieast_jingzhuang6.h"
#include "../d/dalieast/dalieast_jingzhuang7.h"
#include "../d/dalieast/dalieast_jinzhihe.h"
#include "../d/dalieast/dalieast_langan1.h"
#include "../d/dalieast/dalieast_langan3.h"
#include "../d/dalieast/dalieast_langan4.h"
#include "../d/dalieast/dalieast_luojiadian.h"
#include "../d/dalieast/dalieast_milin.h"
#include "../d/dalieast/dalieast_nongtian2.h"
#include "../d/dalieast/dalieast_nongtian3.h"
#include "../d/dalieast/dalieast_nongtian4.h"
#include "../d/dalieast/dalieast_nongtian5.h"
#include "../d/dalieast/dalieast_northgate.h"
#include "../d/dalieast/dalieast_qingxi.h"
#include "../d/dalieast/dalieast_sanglin.h"
#include "../d/dalieast/dalieast_shanjian.h"
#include "../d/dalieast/dalieast_shanlu7.h"
#include "../d/dalieast/dalieast_shanlu8.h"
#include "../d/dalieast/dalieast_shulinwai.h"
#include "../d/dalieast/dalieast_southgate.h"
#include "../d/dalieast/dalieast_xiaodao1.h"
#include "../d/dalieast/dalieast_xiaodao2.h"
#include "../d/dalieast/dalieast_xiaojing.h"
#include "../d/dalieast/dalieast_xingyunhu.h"
#include "../d/dalieast/dalieast_yanan1.h"
#include "../d/dalieast/dalieast_yanan2.h"
#include "../d/dalieast/dalieast_yanchi1.h"
#include "../d/dalieast/dalieast_yanchi2.h"
#include "../d/dalieast/dalieast_yanchi3.h"
#include "../d/dalieast/dalieast_yangzong.h"
#include "../d/dalieast/dalieast_yuxiashan.h"
#include "../d/dalieast/dalieast_yuxuguan.h"
#include "../d/dalieast/dalieast_yuxuguanqian.h"
//�������
#include "../d/dalisouth/dalisouth_dazhulou.h"
#include "../d/dalisouth/dalisouth_feilihu.h"
#include "../d/dalisouth/dalisouth_feilihueast.h"
#include "../d/dalisouth/dalisouth_feilihusouth.h"
#include "../d/dalisouth/dalisouth_gudao.h"
#include "../d/dalisouth/dalisouth_hexi.h"
#include "../d/dalisouth/dalisouth_jisi.h"
#include "../d/dalisouth/dalisouth_kedian.h"
#include "../d/dalisouth/dalisouth_longkou.h"
#include "../d/dalisouth/dalisouth_luwang.h"
#include "../d/dalisouth/dalisouth_luyuxi.h"
#include "../d/dalisouth/dalisouth_nongtian.h"
#include "../d/dalisouth/dalisouth_qingzhulin.h"
#include "../d/dalisouth/dalisouth_road4.h"
#include "../d/dalisouth/dalisouth_shanlu2.h"
#include "../d/dalisouth/dalisouth_shanlu4.h"
#include "../d/dalisouth/dalisouth_shanlu5.h"
#include "../d/dalisouth/dalisouth_shanlu6.h"
#include "../d/dalisouth/dalisouth_shuangheqiao.h"
#include "../d/dalisouth/dalisouth_shuitian.h"
#include "../d/dalisouth/dalisouth_tianweijing.h"
#include "../d/dalisouth/dalisouth_wuding.h"
#include "../d/dalisouth/dalisouth_wuhalou.h"
#include "../d/dalisouth/dalisouth_wuhalou2.h"
#include "../d/dalisouth/dalisouth_xizhou.h"
#include "../d/dalisouth/dalisouth_yishitang.h"
#include "../d/dalisouth/dalisouth_yujia.h"
#include "../d/dalisouth/dalisouth_yulin.h"
#include "../d/dalisouth/dalisouth_zhulin.h"
#include "../d/dalisouth/dalisouth_zhulin2.h"
#include "../d/dalisouth/dalisouth_zhulou.h"
#include "../d/dalisouth/dalisouth_zhulou1.h"
#include "../d/dalisouth/dalisouth_zhulou3.h"
//�������
#include "../d/daliwest/daliwest_atoubu.h"
#include "../d/daliwest/daliwest_badidian.h"
#include "../d/daliwest/daliwest_biluoshan.h"
#include "../d/daliwest/daliwest_biluoxueshan.h"
#include "../d/daliwest/daliwest_gaolishan1.h"
#include "../d/daliwest/daliwest_gaolishan2.h"
#include "../d/daliwest/daliwest_gelucheng.h"
#include "../d/daliwest/daliwest_hebian.h"
#include "../d/daliwest/daliwest_heshang.h"
#include "../d/daliwest/daliwest_jisidawu.h"
#include "../d/daliwest/daliwest_jisidawu1.h"
#include "../d/daliwest/daliwest_lushui.h"
#include "../d/daliwest/daliwest_lushuieast.h"
#include "../d/daliwest/daliwest_minadian.h"
#include "../d/daliwest/daliwest_nianhuasi.h"
#include "../d/daliwest/daliwest_shanlin.h"
#include "../d/daliwest/daliwest_shanlu3.h"
#include "../d/daliwest/daliwest_titian1.h"
#include "../d/daliwest/daliwest_wuyiminju3.h"
#include "../d/daliwest/daliwest_wuyiminju4.h"
#include "../d/daliwest/daliwest_yixibu.h"
#include "../d/daliwest/daliwest_zhenxiong.h"
//����Ǳ�
#include "../d/dalinorth/dalinorth_cangshanzhong.h"
#include "../d/dalinorth/dalinorth_cangshanlu1.h"
#include "../d/dalinorth/dalinorth_cangshan.h"
#include "../d/dalinorth/dalinorth_caopo.h"
#include "../d/dalinorth/dalinorth_changhu.h"
#include "../d/dalinorth/dalinorth_daduhe.h"
#include "../d/dalinorth/dalinorth_dalinorth.h"
#include "../d/dalinorth/dalinorth_dehuabei.h"
#include "../d/dalinorth/dalinorth_ershuiqiao.h"
#include "../d/dalinorth/dalinorth_hole.h"
#include "../d/dalinorth/dalinorth_hongsheng.h"
#include "../d/dalinorth/dalinorth_jianchuan.h"
#include "../d/dalinorth/dalinorth_jianchuankou.h"
#include "../d/dalinorth/dalinorth_road1.h"
#include "../d/dalinorth/dalinorth_road2.h"
#include "../d/dalinorth/dalinorth_road3.h"
#include "../d/dalinorth/dalinorth_shanlu1.h"
#include "../d/dalinorth/dalinorth_shilin.h"
#include "../d/dalinorth/dalinorth_shilin1.h"
#include "../d/dalinorth/dalinorth_shilin2.h"
#include "../d/dalinorth/dalinorth_taihecheng.h"
#include "../d/dalinorth/dalinorth_tianlongsi.h"
#include "../d/dalinorth/dalinorth_wumeng.h"
#include "../d/dalinorth/dalinorth_wunong.h"
#include "../d/dalinorth/dalinorth_wuyiminju1.h"
#include "../d/dalinorth/dalinorth_wuyiminju2.h"
#include "../d/dalinorth/dalinorth_xiaguan.h"
#include "../d/dalinorth/dalinorth_zhiyundong.h"
#include "../d/dalinorth/dalinorthcity.h"

#include "../d/dali/dali_chongshengtading.h"	//����ǳ�ʥ����--�����η�

CRoom * Load_DaLi(string room_name)
{	
	CRoom * r = NULL;

	//�����
	if(room_name == "�����ҩ��")
		r = new CRDali_yaopu();
	else if(room_name == "�����")
		r = new CRDaLicity();
	else if(room_name == "�������������")
		r = new CRDali_wangfugate();
	else if(room_name == "�������˾��")
		r = new CRDali_tusifu();
	else if(room_name == "�����̫�;Ӷ�¥")
		r = new CRDali_taiheju2();
	else if(room_name == "�����̫�;�")
		r = new CRDali_taiheju();
	else if(room_name == "�����ʯ��")
		r = new CRDali_stoneshop();
	else if(room_name == "��������")
		r = new CRDali_majiu();
	else if(room_name == "����ǻʹ�����")
		r = new CRDali_gongmen();
	else if(room_name == "����Ǳ�Ӫ")
		r = new CRDali_bingying();
	else if(room_name == "�����Ѧ�ǳ�����")
		r = new CRDali_chengyipu();
	else if(room_name == "�������������")
		r = new CRDali_zonglichu();
	else if(room_name == "���������������")
		r = new CRDali_bingqiku();
	else if(room_name == "�������������")
		r = new CRDali_neiting();
	else if(room_name == "�������������")
		r = new CRDali_wfdating();
	else if(room_name == "������������˾���")
		r = new CRDali_xiuxishi();
	else if(room_name == "���������˾ͽ��")
		r = new CRDali_situ();
	else if(room_name == "���������˾����")
		r = new CRDali_sima();
	else if(room_name == "���������˾����")
		r = new CRDali_sikong();
	else if(room_name == "����������鷿")
		r = new CRDali_shufang();
	else if(room_name == "�������������")
		r = new CRDali_chufang();
	else if(room_name == "����������ʷ�")
		r = new CRDali_zhangfang();
	else if(room_name == "����ǻʹ�����")
		r = new CRDali_zhengdian();
	else if(room_name == "����ǻʹ�ƫ��")
		r = new CRDali_piandian();
	else if(room_name == "�������˾��������")
		r = new CRDali_tusiyishi();
	else if(room_name == "����ǻʹ�ǰ��")
		r = new CRDali_qiandian();
	else if(room_name == "����ǻʹ����ŷ�")
		r = new CRDali_yushanfang();
	else if(room_name == "����ǻ���·")
		r = new CRDali_road5();
	
	//����Ƕ�
	if(room_name == "��������Ϸ�")
		r = new CRDaliEast_yangcanfang();
	else if(room_name == "����������")
		r = new CRDaliEast_yuxuguan();
	else if(room_name == "����������ǰ")
		r = new CRDaliEast_yuxuguanqian();
	else if(room_name == "�������ϼɽ")
		r = new CRDaliEast_yuxiashan();
	else if(room_name == "�����������")
		r = new CRDaliEast_yangzong();
	else if(room_name == "������سص̰�3")
		r = new CRDaliEast_yanchi3();
	else if(room_name == "������سص̰�2")
		r = new CRDaliEast_yanchi2();
	else if(room_name == "������سص̰�1")
		r = new CRDaliEast_yanchi1();
	else if(room_name == "������س�С·2")
		r = new CRDaliEast_yanan2();
	else if(room_name == "����ǵ���ذ�1")
		r = new CRDaliEast_yanan1();
	else if(room_name == "��������ƺ���")
		r = new CRDaliEast_xingyunhu();
	else if(room_name == "�����ɽ��С��")
		r = new CRDaliEast_xiaojing();
	else if(room_name == "������ּ�С��2")
		r = new CRDaliEast_xiaodao2();
	else if(room_name == "������ּ�С��1")
		r = new CRDaliEast_xiaodao1();
	else if(room_name == "���������")
		r = new CRDaliEast_southgate();
	else if(room_name == "�����������")
		r = new CRDaliEast_shulinwai();
	else if(room_name == "�����ɽ·8")
		r = new CRDaliEast_shanlu8();
	else if(room_name == "�����ɽ·7")
		r = new CRDaliEast_shanlu7();
	else if(room_name == "���������ɽ��")
		r = new CRDaliEast_shanjian();
	else if(room_name == "�����ɣ��")
		r = new CRDaliEast_sanglin();
	else if(room_name == "�������Ϫ��̶")
		r = new CRDaliEast_qingxi();
	else if(room_name == "�����ũ��5")
		r = new CRDaliEast_nongtian5();
	else if(room_name == "�����ũ��4")
		r = new CRDaliEast_nongtian4();
	else if(room_name == "�����ũ��3")
		r = new CRDaliEast_nongtian3();
	else if(room_name == "�����ũ��2")
		r = new CRDaliEast_nongtian2();
	else if(room_name == "���������")
		r = new CRDaliEast_milin();
	else if(room_name == "�������٤��")
		r = new CRDaliEast_luojiadian();
	else if(room_name == "����Ǹ���4")
		r = new CRDaliEast_langan4();
	else if(room_name == "����Ǹ���3")
		r = new CRDaliEast_langan3();
	else if(room_name == "����Ǹ���")
		r = new CRDaliEast_langan1();
	else if(room_name == "����ǽ�֭����")
		r = new CRDaliEast_jinzhihe();
	else if(room_name == "����Ǿ���7")
		r = new CRDaliEast_jingzhuang7();
	else if(room_name == "����Ǿ���6")
		r = new CRDaliEast_jingzhuang6();
	else if(room_name == "����Ǿ���5")
		r = new CRDaliEast_jingzhuang5();
	else if(room_name == "����Ǿ���4")
		r = new CRDaliEast_jingzhuang4();
	else if(room_name == "����Ǿ���3")
		r = new CRDaliEast_jingzhuang3();
	else if(room_name == "����Ǿ���2")
		r = new CRDaliEast_jingzhuang2();
	else if(room_name == "����Ǿ���1")
		r = new CRDaliEast_jingzhuang1();
	else if(room_name == "����Ǻ���Ȫ")
		r = new CRDaliEast_hudiequan();
	else if(room_name == "����Ǻ�����")
		r = new CRDaliEast_heilongling();
	else if(room_name == "����ǵ��")
		r = new CRDaliEast_dianchi();
	else if(room_name == "����Ǵ����")
		r = new CRDaliEast_dalangan1();
	else if(room_name == "����Ǵ��ˮ�ٲ�")
		r = new CRDaliEast_dadieshui();
	else if(room_name == "����ǰ�ɽ����")
		r = new CRDaliEast_banshan();
	else if(room_name == "����ǲ軨ɽ5")
		r = new CRDaliEast_chahuashan5();
	else if(room_name == "����ǲ軨ɽ4")
		r = new CRDaliEast_chahuashan4();
	else if(room_name == "����ǲ軨ɽ3")
		r = new CRDaliEast_chahuashan3();
	else if(room_name == "����ǲ軨ɽ2")
		r = new CRDaliEast_chahuashan2();
	else if(room_name == "����ǲ軨ɽ1")
		r = new CRDaliEast_chahuashan1();
	else if(room_name == "����ǲ��۲�")
		r = new CRDaliEast_buxiongbu();
	else if(room_name == "����Ǳ̼�ɽ��")
		r = new CRDaliEast_bijishan();
	else if(room_name == "����ǲ軨ɽ��")
		r = new CRDaliEast_chahuashan6();
	
	//�������
	else if(room_name == "����Ǵ���¥")
		r = new CRDaLisouth_zhulou3();
	else if(room_name == "�������¥��")
		r = new CRDaLisouth_zhulou1();
	else if(room_name == "�������¥")
		r = new CRDaLisouth_zhulou();
	else if(room_name == "����������")
		r = new CRDaLisouth_zhulin2();
	else if(room_name == "���������С·")
		r = new CRDaLisouth_zhulin();
	else if(room_name == "�������������")
		r = new CRDaLisouth_yulin();
	else if(room_name == "��������")
		r = new CRDaLisouth_yujia();
	else if(room_name == "�����ϲ�ݳ�")
		r = new CRDaLisouth_xizhou();
	else if(room_name == "��������廪¥")
		r = new CRDaLisouth_wuhalou();
	else if(room_name == "������䶨��")
		r = new CRDaLisouth_wuding();
	else if(room_name == "�����������")
		r = new CRDaLisouth_tianweijing();
	else if(room_name == "�����ˮ��")
		r = new CRDaLisouth_shuitian();
	else if(room_name == "�����˫����")
		r = new CRDaLisouth_shuangheqiao();
	else if(room_name == "�����ɽ·6")
		r = new CRDaLisouth_shanlu6();
	else if(room_name == "�����ɽ·5")
		r = new CRDaLisouth_shanlu5();
	else if(room_name == "�����ɽ·4")
		r = new CRDaLisouth_shanlu4();
	else if(room_name == "�����ɽ·2")
		r = new CRDaLisouth_shanlu2();
	else if(room_name == "����Ǵ�·4")
		r = new CRDaLisouth_road4();
	else if(room_name == "�����������")
		r = new CRDaLisouth_qingzhulin();
	else if(room_name == "�����ũ��")
		r = new CRDaLisouth_nongtian();
	else if(room_name == "���������Ϫ�ذ�")
		r = new CRDaLisouth_luyuxi();
	else if(room_name == "�����³����")
		r = new CRDaLisouth_luwang();
	else if(room_name == "��������ڳ�")
		r = new CRDaLisouth_longkou();
	else if(room_name == "����ǿ͵�")
		r = new CRDaLisouth_kedian();
	else if(room_name == "����ǹŵ�")
		r = new CRDaLisouth_gudao();
	else if(room_name == "������������ϰ�")
		r = new CRDaLisouth_feilihusouth();
	else if(room_name == "�������������")
		r = new CRDaLisouth_feilihueast();
	else if(room_name == "�������������")
		r = new CRDaLisouth_feilihu();
	else if(room_name == "������ϴ���¥")
		r = new CRDaLisouth_dazhulou();
	else if(room_name == "����Ǻ�����")
		r = new CRDaLisouth_hexi();
	else if(room_name == "��������廪¥��¥")
		r = new CRDaLisouth_wuhalou2();		
	
	//�������
	if(room_name == "���������")
		r = new CRDaLiWest_zhenxiong();
	else if(room_name == "�������Ϫ��")
		r = new CRDaLiWest_yixibu();
	else if(room_name == "������������4")
		r = new CRDaLiWest_wuyiminju4();
	else if(room_name == "������������")
		r = new CRDaLiWest_wuyiminju3();
	else if(room_name == "���������")
		r = new CRDaLiWest_titian1();
	else if(room_name == "�����ɽ·3")
		r = new CRDaLiWest_shanlu3();
	else if(room_name == "�����ɽ��")
		r = new CRDaLiWest_shanlin();
	else if(room_name == "������黨��")
		r = new CRDaLiWest_nianhuasi();
	else if(room_name == "��������ɵ�")
		r = new CRDaLiWest_minadian();
	else if(room_name == "����Ƕ���ˮ�ӹ�")
		r = new CRDaLiWest_lushuieast();
	else if(room_name == "�������ˮ�ذ�")
		r = new CRDaLiWest_lushui();
	else if(room_name == "����Ǽ������")
		r = new CRDaLiWest_jisidawu1();
	else if(room_name == "����Ǻ���")
		r = new CRDaLiWest_heshang();
	else if(room_name == "����Ǻӱ�")
		r = new CRDaLiWest_hebian();
	else if(room_name == "����Ǹ�³��")
		r = new CRDaLiWest_gelucheng();
	else if(room_name == "����ǰ�ͷ��")
		r = new CRDaLiWest_atoubu();
	else if(room_name == "����Ǹ���ɽ����")
		r = new CRDaLiWest_gaolishan1();
	else if(room_name == "����Ǳ���ѩɽ")
		r = new CRDaLiWest_biluoxueshan();
	else if(room_name == "����Ǹ���ɽ����")
		r = new CRDaLiWest_gaolishan2();
	else if(room_name == "����Ǳ���ɽ��")
		r = new CRDaLiWest_biluoshan();
	else if(room_name == "����ǰ͵ĵ�")
		r = new CRDaLiWest_badidian();
	
	//����Ǳ�
	if(room_name == "����Ǳ���")
		r = new CRDaLiNorthcity();
	else if(room_name == "�����֥�ƶ�")
		r = new CRDaLiNorth_zhiyundong();
	else if(room_name == "������¹س�")
		r = new CRDaLiNorth_xiaguan();
	else if(room_name == "������������2")
		r = new CRDaLiNorth_wuyiminju2();
	else if(room_name == "������������1")
		r = new CRDaLiNorth_wuyiminju1();
	else if(room_name == "�������Ū��")
		r = new CRDaLiNorth_wunong();
	else if(room_name == "��������ɴ���")
		r = new CRDaLiNorth_wumeng();
	else if(room_name == "����Ǳ�������")
		r = new CRDaLiNorth_tianlongsi();
	else if(room_name == "�����̫�ͳ�")
		r = new CRDaLiNorth_taihecheng();
	else if(room_name == "����Ǻ�Ħ��ʯ��")
		r = new CRDaLiNorth_shilin2();
	else if(room_name == "�����������ʯ��")
		r = new CRDaLiNorth_shilin1();
	else if(room_name == "�����·��ʯ��")
		r = new CRDaLiNorth_shilin();
	else if(room_name == "����Ǵ���ɽ·")
		r = new CRDaLiNorth_shanlu1();
	else if(room_name == "����ǹٵ�3")
		r = new CRDaLiNorth_road3();
	else if(room_name == "����ǹٵ�2")
		r = new CRDaLiNorth_road2();
	else if(room_name == "����ǹٵ�1")
		r = new CRDaLiNorth_road1();
	else if(room_name == "����ǽ���ɽ��")
		r = new CRDaLiNorth_jianchuankou();
	else if(room_name == "����ǽ�����")
		r = new CRDaLiNorth_jianchuan();
	else if(room_name == "����Ǻ�ʥ����")
		r = new CRDaLiNorth_hongsheng();
	else if(room_name == "����Ƕ�ˮ��")
		r = new CRDaLiNorth_ershuiqiao();
	else if(room_name == "����ǲ�ɽ")
		r = new CRDaLiNorth_cangshan();
	else if(room_name == "�������گ�»���")
		r = new CRDaLiNorth_dehuabei();
	else if(room_name == "����ǲ�ɽɽ·")
		r = new CRDaLiNorth_cangshanlu1();
	else if(room_name == "����Ǵ�ɺӱ�")
		r = new CRDaLiNorth_daduhe();
	else if(room_name == "����ǳ���")
		r = new CRDaLiNorth_changhu();
	else if(room_name == "����Ǵ������")
		r = new CRDaLiNorth_caopo();
	else if(room_name == "����ǲ�ɽ�в�")
		r = new CRDaLiNorth_cangshanzhong();
	else if(room_name == "����Ǳ�")
		r = new CRDaLiNorth_dalinorth();
	else if(room_name == "����Ƕ�")
		r = new CRDaLidong();
	else if(room_name == "�������")
		r = new CRDaLixi();
	else if(room_name == "����ǳ�ʥ����")
		r = new CRDali_chongshengtading();
	return r;
}



