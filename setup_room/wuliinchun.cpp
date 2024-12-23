#include "stdafx.h"
#include "../std/FightRoom.h"
#include "../std/wl.h"

//���ֱ�����
#include "../d/wuliinchun/wulin_beiqiouge.h"
#include "../d/wuliinchun/wulin_changlang1.h"
#include "../d/wuliinchun/wulin_changlang2.h"
#include "../d/wuliinchun/wulin_chonglou.h"
#include "../d/wuliinchun/wulin_cudaifeng.h"
#include "../d/wuliinchun/wulin_cueimeitai.h"
#include "../d/wuliinchun/wulin_diyuange.h"
#include "../d/wuliinchun/wulin_fengbinfeng.h"
#include "../d/wuliinchun/wulin_fengyuelou.h"
#include "../d/wuliinchun/wulin_hebidating.h"
#include "../d/wuliinchun/wulin_honglangge.h"
#include "../d/wuliinchun/wulin_houmen.h"
#include "../d/wuliinchun/wulin_houyuan.h"
#include "../d/wuliinchun/wulin_houyuandamen.h"
#include "../d/wuliinchun/wulin_jichugu.h"
#include "../d/wuliinchun/wulin_jingniting.h"
#include "../d/wuliinchun/wulin_jioupengting.h"
#include "../d/wuliinchun/wulin_lianergu.h"
#include "../d/wuliinchun/wulin_liangou.h"
#include "../d/wuliinchun/wulin_luorilin.h"
#include "../d/wuliinchun/wulin_muyunge.h"
#include "../d/wuliinchun/wulin_nianjinfeng.h"
#include "../d/wuliinchun/wulin_nianwoge.h"
#include "../d/wuliinchun/wulin_ningmouge.h"
#include "../d/wuliinchun/wulin_pucueigu.h"
#include "../d/wuliinchun/wulin_ranliouchi.h"
#include "../d/wuliinchun/wulin_rongjingcheng.h"
#include "../d/wuliinchun/wulin_rumengfeng.h"
#include "../d/wuliinchun/wulin_shilvge.h"
#include "../d/wuliinchun/wulin_shutouxi.h"
#include "../d/wuliinchun/wulin_xianglengshanzhuang.h"
#include "../d/wuliinchun/wulin_xiaoyufeng.h"
#include "../d/wuliinchun/wulin_xinchougge.h"
#include "../d/wuliinchun/wulin_xuebinfeng.h"
#include "../d/wuliinchun/wulin_xueliougu.h"
#include "../d/wuliinchun/wulin_yannongge.h"
#include "../d/wuliinchun/wulin_zhengting.h"
#include "../d/wuliinchun/wulin_zhongzhouxiaodao.h"

CRoom * Load_WuLin(string room_name)
{
	CRoom * r = NULL;
	
	if(room_name == "���괺������")	r = new CRWuLin_luorilin();	
	else if(room_name == "���괺�����")r = new CRWuLin_beiqiouge();
	else if(room_name == "���괺����1")r = new CRWuLin_changlang1();
	else if(room_name == "���괺����2")r = new CRWuLin_changlang2();
	else if(room_name == "���괺��¥")r = new CRWuLin_chonglou();
	else if(room_name == "���괺�ش���")r = new CRWuLin_cudaifeng();
	else if(room_name == "���괺��÷̨")r = new CRWuLin_cueimeitai();
	else if(room_name == "���괺��Թ��")r = new CRWuLin_diyuange();
	else if(room_name == "���괺���޷�")r = new CRWuLin_fengbinfeng();
	else if(room_name == "���괺����¥")r = new CRWuLin_fengyuelou();
	else if(room_name == "���괺�ϱ�ɽׯ����")r = new CRWuLin_hebidating();
	else if(room_name == "���괺���˸�")r = new CRWuLin_honglangge();
	else if(room_name == "���괺�ϱ�ɽׯ����")r = new CRWuLin_houmen();
	else if(room_name == "���괺����ɽׯ��Ժ")r = new CRWuLin_houyuan();
	else if(room_name == "���괺����ɽׯ��Ժ����")r = new CRWuLin_houyuandamen();
	else if(room_name == "���괺�ó���")r = new CRWuLin_jichugu();
	else if(room_name == "���괺�����")r = new CRWuLin_jingniting();
	else if(room_name == "���괺������")r = new CRWuLin_jioupengting();
	else if(room_name == "���괺������")r = new CRWuLin_lianergu();
	else if(room_name == "���괺����")r = new CRWuLin_liangou();
	else if(room_name == "���괺ĺ�Ƹ�")r = new CRWuLin_muyunge();
	else if(room_name == "���괺����")r = new CRWuLin_nianjinfeng();
	else if(room_name == "���괺���Ҹ�")r = new CRWuLin_nianwoge();
	else if(room_name == "���괺������")r = new CRWuLin_ningmouge();
	else if(room_name == "���괺�̴��")r = new CRWuLin_pucueigu();
	else if(room_name == "���괺Ⱦ����")r = new CRWuLin_ranliouchi();
	else if(room_name == "���괺�۽��")r = new CRWuLin_rongjingcheng();
	else if(room_name == "���괺���η�")r = new CRWuLin_rumengfeng();
	else if(room_name == "���괺ʫ�¸�")r = new CRWuLin_shilvge();
	else if(room_name == "���괺��ͷϪ")r = new CRWuLin_shutouxi();
	else if(room_name == "���괺����ɽׯ����")r = new CRWuLin_xianglengshanzhuang();
	else if(room_name == "���괺Ц���")r = new CRWuLin_xiaoyufeng();
	else if(room_name == "���괺�³��")r = new CRWuLin_xinchougge();
	else if(room_name == "���괺ѩ�޷�")r = new CRWuLin_xuebinfeng();
	else if(room_name == "���괺ѩ����")r = new CRWuLin_xueliougu();
	else if(room_name == "���괺��Ũ��")r = new CRWuLin_yannongge();
	else if(room_name == "���괺����")r = new CRWuLin_zhengting();
	else if(room_name == "���괺����С��")r = new CRWuLin_zhongzhouxiaodao();
	
	return r;
}







