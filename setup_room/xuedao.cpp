#include "stdafx.h"
#include "../server/Room.h"
#include "../server/Char.h"

//Ѫ����
#include "../d/xuedao/xuedao_beilu.h"
#include "../d/xuedao/xuedao_nroad1.h"
#include "../d/xuedao/xuedao_nroad2.h"
#include "../d/xuedao/xuedao_nroad3.h"
#include "../d/xuedao/xuedao_nroad4.h"
#include "../d/xuedao/xuedao_nroad5.h"
#include "../d/xuedao/xuedao_nroad6.h"
#include "../d/xuedao/xuedao_nroad7.h"
#include "../d/xuedao/xuedao_shandong1.h"
#include "../d/xuedao/xuedao_shandong2.h"
#include "../d/xuedao/xuedao_sroad1.h"
#include "../d/xuedao/xuedao_sroad2.h"
#include "../d/xuedao/xuedao_sroad3.h"
#include "../d/xuedao/xuedao_sroad4.h"
#include "../d/xuedao/xuedao_sroad5.h"
#include "../d/xuedao/xuedao_sroad6.h"
#include "../d/xuedao/xuedao_sroad7.h"
#include "../d/xuedao/xuedao_sroad8.h"
#include "../d/xuedao/xuedao_sroad9.h"
#include "../d/xuedao/xuedao_wangyougu.h"
#include "../d/xuedao/xuedaomen.h"

#include "../d/xuedao/xuedao_guenchao.h"
#include "../d/xuedao/xuedao_kedian.h"
#include "../d/xuedao/xuedao_shanjiao.h"
#include "../d/xuedao/xuedao_shenghu.h"
#include "../d/xuedao/xuedao_tulu1.h"
#include "../d/xuedao/xuedao_tulu2.h"
#include "../d/xuedao/xuedao_tulu3.h"
#include "../d/xuedao/xuedao_xiaolu1.h"
#include "../d/xuedao/xuedao_xiaolu2.h"
#include "../d/xuedao/xuedao_xiaolu3.h"
#include "../d/xuedao/xuedao_xiaolu4.h"

CRoom * Load_XueDao(string room_name)
{
	CRoom * r = NULL;

	//Ѫ����
	if(room_name == "Ѫ�������ǹ�")
		r = new CRXueDao_wangyougu();
	else if(room_name == "Ѫ���Ŵ�ѩɽɽ��9")
		r = new CRXueDao_sroad9();
	else if(room_name == "Ѫ���Ŵ�ѩɽɽ��8")
		r = new CRXueDao_sroad8();
	else if(room_name == "Ѫ���Ŵ�ѩɽ��7")
		r = new CRXueDao_sroad7();
	else if(room_name == "Ѫ���Ŵ�ѩɽ��6")
		r = new CRXueDao_sroad6();
	else if(room_name == "Ѫ���Ŵ�ѩɽ")
		r = new CRXueDao_sroad5();
	else if(room_name == "Ѫ���Ŵ�ѩɽ��4")
		r = new CRXueDao_sroad4();
	else if(room_name == "Ѫ����ѩɽ·3")
		r = new CRXueDao_sroad3();
	else if(room_name == "Ѫ����ѩɽ·2")
		r = new CRXueDao_sroad2();
	else if(room_name == "Ѫ����ѩɽ·1")
		r = new CRXueDao_sroad1();
	else if(room_name == "Ѫ����ɽ��2")
		r = new CRXueDao_shandong2();
	else if(room_name == "Ѫ����ɽ��1")
		r = new CRXueDao_shandong1();
	else if(room_name == "Ѫ����ɽ·7")
		r = new CRXueDao_nroad7();
	else if(room_name == "Ѫ����ɽ·6")
		r = new CRXueDao_nroad6();
	else if(room_name == "Ѫ����ɽ·5")
		r = new CRXueDao_nroad5();
	else if(room_name == "Ѫ����ɽ·4")
		r = new CRXueDao_nroad4();
	else if(room_name == "Ѫ����ѩɽ��´")
		r = new CRXueDao_beilu();
	else if(room_name == "Ѫ����ɽ·2")
		r = new CRXueDao_nroad2();
	else if(room_name == "Ѫ����ɽ·1")
		r = new CRXueDao_nroad1();
	else if(room_name == "Ѫ����ɽ·3")
		r = new CRXueDao_nroad3();
	else if(room_name == "Ѫ����")
		r = new CRXueDao();
	else if(room_name == "Ѫ����С·4")
		r = new CRXueDao_xiaolu4();
	else if(room_name == "Ѫ����С·3")
		r = new CRXueDao_xiaolu3();
	else if(room_name == "Ѫ����С·2")
		r = new CRXueDao_xiaolu2();
	else if(room_name == "Ѫ���Ź���")
		r = new CRXueDao_guenchao();
	else if(room_name == "Ѫ������·3")
		r = new CRXueDao_tulu3();
	else if(room_name == "Ѫ������·2")
		r = new CRXueDao_tulu2();
	else if(room_name == "Ѫ������·1")
		r = new CRXueDao_tulu1();
	else if(room_name == "Ѫ����ʥ��")
		r = new CRXueDao_shenghu();
	else if(room_name == "Ѫ����ɽ��")
		r = new CRXueDao_shanjiao();
	else if(room_name == "Ѫ���ſ͵�")
		r = new CRXueDao_kedian();
	else if(room_name == "Ѫ����С·1")
		r = new CRXueDao_xiaolu1();

	return r;
}