#include "stdafx.h"
#include "../server/Room.h"
#include "../server/Char.h"
#include "../server/Npc.h"
#include "../server/User.h"
#include "../server/Skill.h"
#include "../std/resident.h"
#include "../std/FightRoom.h"
#include "../std/RField.h"

//����
#include "../d/guanwai/guanwai_heifengkou.h"
#include "../d/guanwai/guanwai_huagai.h"
#include "../d/guanwai/guanwai_huandi1.h"
#include "../d/guanwai/guanwai_huandi2.h"
#include "../d/guanwai/guanwai_laolongtou.h"
#include "../d/guanwai/guanwai_longmen.h"
#include "../d/guanwai/guanwai_luming.h"
#include "../d/guanwai/guanwai_majiu.h"
#include "../d/guanwai/guanwai_mantianxing.h"
#include "../d/guanwai/guanwai_milin2.h"
#include "../d/guanwai/guanwai_milin3.h"
#include "../d/guanwai/guanwai_ningyuan.h"
#include "../d/guanwai/guanwai_pubu.h"
#include "../d/guanwai/guanwai_road.h"
#include "../d/guanwai/guanwai_rouguan.h"
#include "../d/guanwai/guanwai_shanhaiguan.h"
#include "../d/guanwai/guanwai_shanshenmiao.h"
#include "../d/guanwai/guanwai_tianchi1.h"
#include "../d/guanwai/guanwai_tianchi2.h"
#include "../d/guanwai/guanwai_tianhuo.h"
#include "../d/guanwai/guanwai_tiyun.h"
#include "../d/guanwai/guanwai_tuwu.h"
#include "../d/guanwai/guanwai_tuyaoguan.h"
#include "../d/guanwai/guanwai_xiaotianchi.h"
#include "../d/guanwai/guanwai_xuedi1.h"
#include "../d/guanwai/guanwai_xuedi2.h"
#include "../d/guanwai/guanwai_xuedi3.h"
#include "../d/guanwai/guanwai_yuzhu.h"
#include "../d/guanwai/guanwai_baihe.h"
#include "../d/guanwai/guanwai_baiyun.h"
#include "../d/guanwai/guanwai_bingmian.h"
#include "../d/guanwai/guanwai_caoguduo.h"
#include "../d/guanwai/guanwai_chuanchang.h"
#include "../d/guanwai/guanwai_damen.h"
#include "../d/guanwai/guanwai_damenkan.h"
#include "../d/guanwai/guanwai_dongcheng.h"
#include "../d/guanwai/guanwai_ermenkan.h"
#include "../d/guanwai/guanwaicity.h"


//��������-��Ӫ
#include "../d/guanwai/junying/guanwai_junying.h"
#include "../d/guanwai/junying/guanwai_junying11.h"
#include "../d/guanwai/junying/guanwai_junying12.h"
#include "../d/guanwai/junying/guanwai_junying13.h"
#include "../d/guanwai/junying/guanwai_junying14.h"
#include "../d/guanwai/junying/guanwai_junying21.h"
#include "../d/guanwai/junying/guanwai_junying22.h"
#include "../d/guanwai/junying/guanwai_junying23.h"
#include "../d/guanwai/junying/guanwai_junying24.h"
#include "../d/guanwai/junying/guanwai_junying31.h"
#include "../d/guanwai/junying/guanwai_junying32.h"
#include "../d/guanwai/junying/guanwai_junying33.h"
#include "../d/guanwai/junying/guanwai_junying34.h"
#include "../d/guanwai/junying/guanwai_junying41.h"
#include "../d/guanwai/junying/guanwai_junying42.h"
#include "../d/guanwai/junying/guanwai_junying43.h"
#include "../d/guanwai/junying/guanwai_junying44.h"
#include "../d/guanwai/junying/guanwai_junying51.h"
#include "../d/guanwai/junying/guanwai_junying52.h"
#include "../d/guanwai/junying/guanwai_junying53.h"
#include "../d/guanwai/junying/guanwai_junying54.h"
#include "../d/guanwai/junying/guanwai_junying61.h"
#include "../d/guanwai/junying/guanwai_junying62.h"
#include "../d/guanwai/junying/guanwai_junying63.h"
#include "../d/guanwai/junying/guanwai_junying64.h"
#include "../d/guanwai/junying/guanwai_junying71.h"
#include "../d/guanwai/junying/guanwai_junying72.h"
#include "../d/guanwai/junying/guanwai_junying73.h"
#include "../d/guanwai/junying/guanwai_junying74.h"
#include "../d/guanwai/junying/guanwai_junying75.h"
#include "../d/guanwai/junying/guanwai_junying76.h"
#include "../d/guanwai/junying/guanwai_junying77.h"

CRoom * Load_GuanWai(string room_name)
{
	CRoom * r = NULL;

	//����
    if(room_name == "����������")
		r = new CRGuanWai_yuzhu();
    else if(room_name == "����ѩ��3")
		r = new CRGuanWai_xuedi3();
    else if(room_name == "����ѩ��2")
		r = new CRGuanWai_xuedi2();
    else if(room_name == "����ѩ��1")
		r = new CRGuanWai_xuedi1();
    else if(room_name == "����С���")
		r = new CRGuanWai_xiaotianchi();
    else if(room_name == "������Զ��Ҥ��")
		r = new CRGuanWai_tuyaoguan();
    else if(room_name == "������ԶС����")
		r = new CRGuanWai_tuwu();
    else if(room_name == "�������Ʒ�")
		r = new CRGuanWai_tiyun();
    else if(room_name == "��������")
		r = new CRGuanWai_tianhuo();
    else if(room_name == "�����ͷɽ���2")
		r = new CRGuanWai_tianchi2();
    else if(room_name == "�����ͷɽ���1")
		r = new CRGuanWai_tianchi1();
    else if(room_name == "����ɽ����")
		r = new CRGuanWai_shanshenmiao();
    else if(room_name == "����ɽ����")
		r = new CRGuanWai_shanhaiguan();
    else if(room_name == "������Զ�����")
		r = new CRGuanWai_rouguan();
    else if(room_name == "����ٵ�")
		r = new CRGuanWai_road();
    else if(room_name == "���ⳤ���ٲ�")
		r = new CRGuanWai_pubu();
    else if(room_name == "������Զ")
		r = new CRGuanWai_ningyuan();
    else if(room_name == "��������2")
		r = new CRGuanWai_milin2();
    else if(room_name == "��������1")
		r = new CRGuanWai_milin1();
    else if(room_name == "����������")
		r = new CRGuanWai_mantianxing();
    else if(room_name == "������Զ���")
		r = new CRGuanWai_majiu();
    else if(room_name == "����¹����")
		r = new CRGuanWai_luming();
    else if(room_name == "�������ŷ�")
		r = new CRGuanWai_longmen();
    else if(room_name == "��������ͷ")
		r = new CRGuanWai_laolongtou();
    else if(room_name == "�����·2")
		r = new CRGuanWai_huandi2();
    else if(room_name == "�����·1")
		r = new CRGuanWai_huandi1();
    else if(room_name == "���⻪�Ƿ�")
		r = new CRGuanWai_huagai();
    else if(room_name == "����ڷ��")
		r = new CRGuanWai_heifengkou();
    else if(room_name == "������ſ���")
		r = new CRGuanWai_ermenkan();
    else if(room_name == "������Զ����")
		r = new CRGuanWai_dongcheng();
    else if(room_name == "����׺�")
		r = new CRGuanWai_baihe();
    else if(room_name == "�������")
		r = new CRGuanWai_damen();
    else if(room_name == "���⴬��")
		r = new CRGuanWai_chuanchang();
    else if(room_name == "����Ȳݶ�")
		r = new CRGuanWai_caoguduo();
    else if(room_name == "�������")
		r = new CRGuanWai_bingmian();
    else if(room_name == "������Ʒ�")
		r = new CRGuanWai_baiyun();
    else if(room_name == "������ſ���")
		r = new CRGuanWai_damenkan();
    else if(room_name == "����")
		r = new CRGuanWaicity();

	else if(room_name == "�����Ӫ")
		r = new CRGuanWai_junying();

	else if(room_name == "�������ȷ�Ӫ��1")
		r = new CRGuanWai_junying11();
	else if(room_name == "�������ȷ�Ӫ��2")
		r = new CRGuanWai_junying12();
	else if(room_name == "�������ȷ�Ӫ��3")
		r = new CRGuanWai_junying13();
	else if(room_name == "�������ȷ�Ӫ��4")
		r = new CRGuanWai_junying14();
	
	else if(room_name == "�����о��ȷ�Ӫ��1")
		r = new CRGuanWai_junying21();
	else if(room_name == "�����о��ȷ�Ӫ��2")
		r = new CRGuanWai_junying22();
	else if(room_name == "�����о��ȷ�Ӫ��3")
		r = new CRGuanWai_junying23();
	else if(room_name == "�����о��ȷ�Ӫ��4")
		r = new CRGuanWai_junying24();

	else if(room_name == "�������ȷ�Ӫ��1")
		r = new CRGuanWai_junying31();
	else if(room_name == "�������ȷ�Ӫ��2")
		r = new CRGuanWai_junying32();
	else if(room_name == "�������ȷ�Ӫ��3")
		r = new CRGuanWai_junying33();
	else if(room_name == "�������ȷ�Ӫ��4")
		r = new CRGuanWai_junying34();

	else if(room_name == "��������Ӫ��1")
		r = new CRGuanWai_junying41();
	else if(room_name == "��������Ӫ��2")
		r = new CRGuanWai_junying42();
	else if(room_name == "��������Ӫ��3")
		r = new CRGuanWai_junying43();
	else if(room_name == "��������Ӫ��4")
		r = new CRGuanWai_junying44();
	
	else if(room_name == "��������Ӫ��1")
		r = new CRGuanWai_junying51();
	else if(room_name == "��������Ӫ��2")
		r = new CRGuanWai_junying52();
	else if(room_name == "��������Ӫ��3")
		r = new CRGuanWai_junying53();
	else if(room_name == "��������Ӫ��4")
		r = new CRGuanWai_junying54();

	else if(room_name == "������Ӫ��1")
		r = new CRGuanWai_junying61();
	else if(room_name == "������Ӫ��2")
		r = new CRGuanWai_junying62();
	else if(room_name == "������Ӫ��3")
		r = new CRGuanWai_junying63();
	else if(room_name == "������Ӫ��4")
		r = new CRGuanWai_junying64();

	else if(room_name == "�����о�Ӫ��1")
		r = new CRGuanWai_junying71();
	else if(room_name == "�����о�Ӫ��2")
		r = new CRGuanWai_junying72();
	else if(room_name == "�����о�Ӫ��3")
		r = new CRGuanWai_junying73();
	else if(room_name == "�����о�Ӫ��4")
		r = new CRGuanWai_junying74();
	else if(room_name == "�����о�Ӫ��5")
		r = new CRGuanWai_junying75();
	else if(room_name == "�����о�Ӫ��6")
		r = new CRGuanWai_junying76();
	else if(room_name == "�����о�˧��")
		r = new CRGuanWai_junying77();

	return r;
}



