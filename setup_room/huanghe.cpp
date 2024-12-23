#include "stdafx.h"
#include "../server/Room.h"


//�ƺ�
#include "../d/changan_room.h" 
#include "../d/huanghe/huanghe.h"
#include "../d/huanghe/huanghe_bingcao.h"
#include "../d/huanghe/huanghe_dacaigou.h"
#include "../d/huanghe/huanghe_guangchang.h"
#include "../d/huanghe/huanghe_guchangcheng.h"
#include "../d/huanghe/huanghe_gulang.h"
#include "../d/huanghe/huanghe_hetao.h"
#include "../d/huanghe/huanghe_hongshanxia.h"
#include "../d/huanghe/huanghe_huanghe_1.h"
#include "../d/huanghe/huanghe_huanghe_2.h"
#include "../d/huanghe/huanghe_huanghe_3.h"
#include "../d/huanghe/huanghe_huanghe1.h"
#include "../d/huanghe/huanghe_huanghe2.h"
#include "../d/huanghe/huanghe_huanghe3.h"
#include "../d/huanghe/huanghe_huanghe4.h"
#include "../d/huanghe/huanghe_huanghe5.h"
#include "../d/huanghe/huanghe_huanghe6.h"
#include "../d/huanghe/huanghe_huanghe7.h"
#include "../d/huanghe/huanghe_huanghe8.h"
#include "../d/huanghe/huanghe_huanghegate.h"
#include "../d/huanghe/huanghe_huangtu.h"
#include "../d/huanghe/huanghe_jingyuan.h"
#include "../d/huanghe/huanghe_kedian.h"
#include "../d/huanghe/huanghe_majiu.h"
#include "../d/huanghe/huanghe_qingcheng.h"
#include "../d/huanghe/huanghe_shamo.h"
#include "../d/huanghe/huanghe_shamo1.h"
#include "../d/huanghe/huanghe_shidong.h"
#include "../d/huanghe/huanghe_shimen.h"
#include "../d/huanghe/huanghe_shixiazi.h"
#include "../d/huanghe/huanghe_shulin1.h"
#include "../d/huanghe/huanghe_shulin2.h"
#include "../d/huanghe/huanghe_shulin3.h"
#include "../d/huanghe/huanghe_shulin4.h"
#include "../d/huanghe/huanghe_shulin5.h"
#include "../d/huanghe/huanghe_shulin6.h"
#include "../d/huanghe/huanghe_tiandi1.h"
#include "../d/huanghe/huanghe_tiandi2.h"
#include "../d/huanghe/huanghe_tiandi3.h"
#include "../d/huanghe/huanghe_tiandi4.h"
#include "../d/huanghe/huanghe_tumenzi.h"
#include "../d/huanghe/huanghe_weifen.h"
#include "../d/huanghe/huanghe_wufosi.h"
#include "../d/huanghe/huanghe_wuqiao.h"
#include "../d/huanghe/huanghe_wuwei.h"
#include "../d/huanghe/huanghe_xiaojiaqiao.h"
#include "../d/huanghe/huanghe_xiayiting.h"
#include "../d/huanghe/huanghe_xueguan.h"
#include "../d/huanghe/huanghe_yaocaidian.h"
#include "../d/huanghe/huanghe_yinpanshui.h"
#include "../d/huanghe/huanghe_yongdeng.h"
#include "../d/huanghe/huanghe_shatulu.h"

CRoom * Load_HuangHe(string room_name)
{
	CRoom * r = NULL;

	//�ƺ�
    if(room_name == "�ƺ�")
		r = new CRHuangHe();
	else if(room_name == "�ƺ�����")
		r = new CRHuangHe_yongdeng();
	else if(room_name == "�ƺ�Ӫ��ˮ")
		r = new CRHuangHe_yinpanshui();
	else if(room_name == "�ƺ�Ƥ��ҩ�ĵ�")
		r = new CRHuangHe_yaocaidian();
	else if(room_name == "�ƺ�ѧ��")
		r = new CRHuangHe_xueguan();
	else if(room_name == "�ƺ�������")
		r = new CRHuangHe_xiayiting();
	else if(room_name == "�ƺ�������")
		r = new CRHuangHe_xiaojiaqiao();
	else if(room_name == "�ƺ�����")
		r = new CRHuangHe_wuwei();
	else if(room_name == "�ƺ�������")
		r = new CRHuangHe_wuqiao();
	else if(room_name == "�ƺ������")
		r = new CRHuangHe_wufosi();
	else if(room_name == "�ƺ�μ������")
		r = new CRHuangHe_weifen();
	else if(room_name == "�ƺ�������")
		r = new CRHuangHe_tumenzi();
	else if(room_name == "�ƺ����4")
		r = new CRHuangHe_tiandi4();
	else if(room_name == "�ƺ����3")
		r = new CRHuangHe_tiandi3();
	else if(room_name == "�ƺ����2")
		r = new CRHuangHe_tiandi2();
	else if(room_name == "�ƺ����1")
		r = new CRHuangHe_tiandi1();
	else if(room_name == "�ƺ�����6")
		r = new CRHuangHe_shulin6();
	else if(room_name == "�ƺ�����5")
		r = new CRHuangHe_shulin5();
	else if(room_name == "�ƺ�����4")
		r = new CRHuangHe_shulin4();
	else if(room_name == "�ƺ�����3")
		r = new CRHuangHe_shulin3();
	else if(room_name == "�ƺ�����2")
		r = new CRHuangHe_shulin2();
	else if(room_name == "�ƺ�����1")
		r = new CRHuangHe_shulin1();
	else if(room_name == "�ƺ�ʯϿ��")
		r = new CRHuangHe_shixiazi();
	else if(room_name == "�ƺ�ʯ��")
		r = new CRHuangHe_shimen();
	else if(room_name == "�ƺ�ʯ��")
		r = new CRHuangHe_shidong();
	else if(room_name == "�ƺ�ɳĮ1")
		r = new CRHuangHe_shamo();
	else if(room_name == "�ƺ�ɳĮ2")
		r = new CRHuangHe_shamo1();
	else if(room_name == "�ƺ����")
		r = new CRHuangHe_qingcheng();
	else if(room_name == "�ƺ����")
		r = new CRHuangHe_majiu();
	else if(room_name == "�ƺӿ͵�")
		r = new CRHuangHe_kedian();
	else if(room_name == "�ƺӾ�Զ")
		r = new CRHuangHe_jingyuan();
	else if(room_name == "�ƺӾ�Զ")
		r = new CRHuangHe_jingyuan();
	else if(room_name == "�ƺӻ�����ԭ")
		r = new CRHuangHe_huangtu();
	else if(room_name == "�ƺӰ�կ��")
		r = new CRHuangHe_huanghegate();
	else if(room_name == "�ƺ��뺣��")
		r = new CRHuangHe_huanghe8();
	else if(room_name == "�ƺӰ���7")
		r = new CRHuangHe_huanghe7();
	else if(room_name == "�ƺӰ���6")
		r = new CRHuangHe_huanghe6();
	else if(room_name == "�ƺӰ���5")
		r = new CRHuangHe_huanghe5();
	else if(room_name == "�ƺӰ���4")
		r = new CRHuangHe_huanghe4();
	else if(room_name == "�ƺӰ���3")
		r = new CRHuangHe_huanghe3();
	else if(room_name == "�ƺӰ���2")
		r = new CRHuangHe_huanghe2();
	else if(room_name == "�ƺӰ���1")
		r = new CRHuangHe_huanghe1();
	else if(room_name == "�ƺ�3")
		r = new CRHuangHe_huanghe_3();
	else if(room_name == "�ƺ�2")
		r = new CRHuangHe_huanghe_2();
	else if(room_name == "�ƺ�1")
		r = new CRHuangHe_huanghe_1();
	else if(room_name == "�ƺӺ�ɽϿ")
		r = new CRHuangHe_hongshanxia();
	else if(room_name == "�ƺӺ���")
		r = new CRHuangHe_hetao();
	else if(room_name == "�ƺӹ���")
		r = new CRHuangHe_gulang();
	else if(room_name == "�ƺӹų���")
		r = new CRHuangHe_guchangcheng();
	else if(room_name == "�ƺӹ㳡")
		r = new CRHuangHe_guangchang();
	else if(room_name == "�ƺӴ��")
		r = new CRHuangHe_dacaigou();
	else if(room_name == "�ƺӱ�����")
		r = new CRHuangHe_bingcao();
	else if(room_name == "�ƺ�ɳ��·")
		r = new CRHuangHe_shatulu();

	return r;
}