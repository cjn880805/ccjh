#include "stdafx.h"
#include "../server/Room.h"
#include "../server/Char.h"
#include "../server/Npc.h"
#include "../server/User.h"
#include "../server/Skill.h"
#include "../std/FightRoom.h"
#include "../std/resident.h"

//����
#include "../d/lingzhou/lingzhou_lingzhong.h"
#include "../d/lingzhou/lingzhou_lingzhongmishi.h"
#include "../d/lingzhou/lingzhou_lingxia.h"
#include "../d/lingzhou/lingzhou_wuminggu.h"


#include "../d/lingzhou/lingzhou_biaoqiyin.h"
#include "../d/lingzhou/lingzhou_baxian.h"
#include "../d/lingzhou/lingzhou_chema.h"
#include "../d/lingzhou/lingzhou_chiling.h"
#include "../d/lingzhou/lingzhou_dalu1.h"
#include "../d/lingzhou/lingzhou_daodian.h"
#include "../d/lingzhou/lingzhou_dawu.h"
#include "../d/lingzhou/lingzhou_deling.h"
#include "../d/lingzhou/lingzhou_gonggate.h"
#include "../d/lingzhou/lingzhou_gongling.h"
#include "../d/lingzhou/lingzhou_huangyangtan.h"
#include "../d/lingzhou/lingzhou_jiangjungate.h"
#include "../d/lingzhou/lingzhou_jiuguan.h"
#include "../d/lingzhou/lingzhou_kongdi.h"
#include "../d/lingzhou/lingzhou_luorilin1.h"
#include "../d/lingzhou/lingzhou_luorilin2.h"
#include "../d/lingzhou/lingzhou_majiu.h"
#include "../d/lingzhou/lingzhou_mingshazhou.h"
#include "../d/lingzhou/lingzhou_nanmen.h"
#include "../d/lingzhou/lingzhou_qingtongxia.h"
#include "../d/lingzhou/lingzhou_qingxinquan.h"
#include "../d/lingzhou/lingzhou_tulu.h"
#include "../d/lingzhou/lingzhou_wangling.h"
#include "../d/lingzhou/lingzhou_xiaoba.h"
#include "../d/lingzhou/lingzhou_xiaolu1.h"
#include "../d/lingzhou/lingzhou_xiaolu2.h"
#include "../d/lingzhou/lingzhou_xiaolu3.h"
#include "../d/lingzhou/lingzhou_xuanhebao.h"
#include "../d/lingzhou/lingzhou_yamen.h"
#include "../d/lingzhou/lingzhou_yipindating.h"
#include "../d/lingzhou/lingzhou_yipinjieyin.h"
#include "../d/lingzhou/lingzhou_yipinzhang.h"
#include "../d/lingzhou/lingzhou_xi.h"
#include "../d/lingzhou/lingzhou_dong.h"
#include "../d/lingzhou/lingzhoucity.h"
#include "../d/lingzhou/lingzhou_guangchang.h"

#include "../d/lingzhou/lingzhou_houting.h"
#include "../d/lingzhou/lingzhou_huanyuan.h"
#include "../d/lingzhou/lingzhou_huanyuanlu.h"
#include "../d/lingzhou/lingzhou_dadian.h"
#include "../d/lingzhou/lingzhou_youlanjian.h"
#include "../d/lingzhou/lingzhou_youlanjiandong.h"
#include "../d/lingzhou/lingzhou_neishufang.h"
#include "../d/lingzhou/lingzhou_dadao1.h"
#include "../d/lingzhou/lingzhou_dadao2.h"
#include "../d/lingzhou/lingzhou_dadao3.h"
#include "../d/lingzhou/lingzhou_qingfengge.h"
#include "../d/lingzhou/lingzhou_qingfengge1.h"

CRoom * Load_LingZhou(string room_name)
{
	CRoom * r = NULL;

	//����
    if(room_name == "����")
		r = new CRLingZhoucity();
    else if(room_name == "������������")
		r = new CRlingzhou_lingzhongmishi();
    else if(room_name == "��������")
		r = new CRlingzhou_lingzhong();
    else if(room_name == "��������")
		r = new CRlingzhou_lingxia();
    else if(room_name == "����������")
		r = new CRlingzhou_wuminggu();

    
	else if(room_name == "����һƷ���ʷ�")
		r = new CRLingZhou_yipinzhang();
    else if(room_name == "���ݽ�����")
		r = new CRLingZhou_yipinjieyin();
    else if(room_name == "����һƷ�ô���")
		r = new CRLingZhou_yipindating();
    else if(room_name == "��������")
		r = new CRLingZhou_yamen();
    else if(room_name == "�������")
		r = new CRLingZhou_majiu();
    else if(room_name == "���ݾƹ�")
		r = new CRLingZhou_jiuguan();
    else if(room_name == "���ݴ󽫾���")
		r = new CRLingZhou_jiangjungate();
    else if(room_name == "���ݻʹ�����")
		r = new CRLingZhou_gonggate();
    else if(room_name == "�������д���")
		r = new CRLingZhou_dawu();
    else if(room_name == "���ݵ���")
		r = new CRLingZhou_daodian();
    else if(room_name == "���ݰ��ɵ���")
		r = new CRLingZhou_baxian();
    else if(room_name == "��������Ӫ")
		r = new CRLingZhou_biaoqiyin();
    else if(room_name == "���ݳ����")
		r = new CRLingZhou_chema();
	else if(room_name == "������������")
		r = new CRLingZhou_wangling();
	else if(room_name == "�������пյ�")
		r = new CRLingZhou_kongdi();
	else if(room_name == "����������1")
		r = new CRLingZhou_luorilin1();
	else if(room_name == "�������ͱ�")
		r = new CRLingZhou_xuanhebao();
	else if(room_name == "���ݹ���")
		r = new CRLingZhou_gongling();
	else if(room_name == "���ݻ���̲")
		r = new CRLingZhou_huangyangtan();
	else if(room_name == "���ݳ���")
		r = new CRLingZhou_chiling();
	else if(room_name == "���ݵ���")
		r = new CRLingZhou_deling();
	else if(room_name == "����������·")
		r = new CRLingZhou_tulu();
	else if(room_name == "��������С·3")
		r = new CRLingZhou_xiaolu3();
	else if(room_name == "��������С·2")
		r = new CRLingZhou_xiaolu2();
	else if(room_name == "��������С·1")
		r = new CRLingZhou_xiaolu1();
	else if(room_name == "����С��")
		r = new CRLingZhou_xiaoba();
	else if(room_name == "��������Ȫ")
		r = new CRLingZhou_qingxinquan();
	else if(room_name == "������ͭϿ")
		r = new CRLingZhou_qingtongxia();
	else if(room_name == "��������")
		r = new CRLingZhou_nanmen();
	else if(room_name == "������ɳ��")
		r = new CRLingZhou_mingshazhou();
	else if(room_name == "����������2")
		r = new CRLingZhou_luorilin2();
	else if(room_name == "�������д�·1")
		r = new CRLingZhou_dalu1();
	else if(room_name == "������")
		r = new CRLingZhou_xi();
	else if(room_name == "���ݶ�")
		r = new CRLingZhou_dong();
	else if(room_name == "���ݻʹ��㳡")
		r = new CRLingZhou_guangchang();

	else if(room_name == "���ݻʹ�����")
		r = new CRLingZhou_dadian();
	else if(room_name == "���ݻʹ�����")
		r = new CRLingZhou_houting();
	else if(room_name == "���ݻʹ���԰С·")
		r = new CRLingZhou_huanyuanlu();
	else if(room_name == "���ݻʹ���԰")
		r = new CRLingZhou_huanyuan();
	else if(room_name == "���ݻʹ�������")
		r = new CRLingZhou_youlanjian();
	else if(room_name == "���ݻʹ���������")
		r = new CRLingZhou_youlanjiandong();
	else if(room_name == "���ݻʹ����鷿")
		r = new CRLingZhou_neishufang();
	else if(room_name == "���ݻʹ����")
		r = new CRLingZhou_dadao1();
	else if(room_name == "���ݻʹ����2")
		r = new CRLingZhou_dadao2();
	else if(room_name == "���ݻʹ����3")
		r = new CRLingZhou_dadao3();
	else if(room_name == "���ݻʹ�����")
		r = new CRLingZhou_qingfengge();
	else if(room_name == "���ݻʹ���������")
		r = new CRLingZhou_qingfengge1();


	return r;
}
