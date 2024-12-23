#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"

//   Ȫ��
#include "../d/quanzhou/quanzhoucity.h" 
#include "../d/quanzhou/quanzhou_bamboo.h" 
#include "../d/quanzhou/quanzhou_beimen.h" 
#include "../d/quanzhou/quanzhou_dahai.h" 
#include "../d/quanzhou/quanzhou_haigang.h" 
#include "../d/quanzhou/quanzhou_nanmen.h" 
#include "../d/quanzhou/quanzhou_penghu.h" 
#include "../d/quanzhou/quanzhou_puxian.h" 
#include "../d/quanzhou/quanzhou_qinglong.h" 
#include "../d/quanzhou/quanzhou_qinglong1.h" 
#include "../d/quanzhou/quanzhou_qinglong2.h" 
#include "../d/quanzhou/quanzhou_qinglong3.h" 
#include "../d/quanzhou/quanzhou_qzroad1.h" 
#include "../d/quanzhou/quanzhou_qzroad2.h" 
#include "../d/quanzhou/quanzhou_qzroad3.h" 
#include "../d/quanzhou/quanzhou_qzroad4.h" 
#include "../d/quanzhou/quanzhou_qzroad5.h" 
#include "../d/quanzhou/quanzhou_westbridge.h" 
#include "../d/quanzhou/quanzhou_zhongxin.h" 
#include "../d/quanzhou/quanzhou_zhongzhou.h" 


CRoom * Load_QuanZhou(string room_name)
{
	CRoom * r = NULL;

	//     Ȫ��
	if(room_name == "Ȫ��")
		r = new CRQuanzhoucity();
	else if(room_name == "Ȫ��������")
		r = new CRQuanZhou_zhongzhou();
	else if(room_name == "Ȫ�ݳ�����")
		r = new CRQuanZhou_zhongxin();
	else if(room_name == "Ȫ�����ŵ���")
		r = new CRQuanzhou_westbridge();
	else if(room_name == "Ȫ��ɽ·5")
		r = new CRQuanZhou_qzroad5();
	else if(room_name == "Ȫ��ɽ·4")
		r = new CRQuanZhou_qzroad4();
	else if(room_name == "Ȫ��ɽ·3")
		r = new CRQuanZhou_qzroad3();
	else if(room_name == "Ȫ��ɽ·2")
		r = new CRQuanZhou_qzroad2();
	else if(room_name == "Ȫ��ɽ·1")
		r = new CRQuanZhou_qzroad1();
	else if(room_name == "Ȫ���������ͥ3")
		r = new CRQuanZhou_qinglong3();
	else if(room_name == "Ȫ���������ͥ2")
		r = new CRQuanZhou_qinglong2();
	else if(room_name == "Ȫ���������ͥ")
		r = new CRQuanZhou_qinglong1();
	else if(room_name == "Ȫ��������ǰͥ")
		r = new CRQuanZhou_qinglong();
	else if(room_name == "Ȫ������С��")
		r = new CRQuanZhou_bamboo();
	else if(room_name == "Ȫ������ƽԭ")
		r = new CRQuanZhou_puxian();
	else if(room_name == "Ȫ�������")
		r = new CRQuanZhou_penghu();
	else if(room_name == "Ȫ������")
		r = new CRQuanZhou_nanmen();
	else if(room_name == "Ȫ�ݺ���")
		r = new CRQuanZhou_haigang();
	else if(room_name == "Ȫ�ݴ�")
		r = new CRQuanZhou_dahai();
	else if(room_name == "Ȫ�ݱ���")
		r = new CRQuanZhou_beimen();

	return r;
}