#include "stdafx.h"
#include "../server/Room.h"

//����
#include "../d/xingxiu/xingxiu_cangku.h"
#include "../d/xingxiu/xingxiu_riyuedong.h"
#include "../d/xingxiu/xingxiu_shidao.h"
#include "../d/xingxiu/xingxiu_tianroad1.h"
#include "../d/xingxiu/xingxiu_tianroad2.h"
#include "../d/xingxiu/xingxiu_tianroad3.h"
#include "../d/xingxiu/xingxiu_tianroad4.h"
#include "../d/xingxiu/xingxiu_xiaoyao.h"
#include "../d/xingxiu/xingxiu_xxh1.h"
#include "../d/xingxiu/xingxiu_xxroad6.h"
#include "../d/xingxiu/xingxiu_xxroad4.h"

CRoom * Load_XingXiu(string room_name)
{
	CRoom * r = NULL;

	//����
	if(room_name == "���޺�ɽ��ƽ��")
		r = new CRXingXiu_xxroad6();
	else if(room_name == "���޺�")
		r = new CRXingXiu_xxh1();
	else if(room_name == "���޺���ң��")
		r = new CRXingXiu_xiaoyao();
	else if(room_name == "���޺���ɽɽ·4")
		r = new CRXingXiu_tianroad4();
	else if(room_name == "���޺���ɽɽ·3")
		r = new CRXingXiu_tianroad3();
	else if(room_name == "���޺���ɽɽ·2")
		r = new CRXingXiu_tianroad2();
	else if(room_name == "�����ɴ�����")
		r = new CRXingXiu_cangku();
	else if(room_name == "���޺�ʯ��")
		r = new CRXingXiu_shidao();
	else if(room_name == "���޺����¶�")
		r = new CRXingXiu_riyuedong();
	else if(room_name == "���޺���ɽɽ·1")
		r = new CRXingXiu_tianroad1();
	else if(room_name == "���޺�С·")
		r = new CRXingXiu_xxroad4();		

	return r;
}