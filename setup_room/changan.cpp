#include "stdafx.h"
#include "../std/RField.h"
#include "../std/resident.h"

//    ������ 
#include "../d/changan_room.h" 
#include "../d/chang_an/chang_ancity.h" 
#include "../d/chang_an/chang_an_club.h"
#include "../d/chang_an/chang_an_club3.h" 
#include "../d/chang_an/chang_an_clubpoem.h" 
#include "../d/chang_an/chang_an_clubup.h" 
#include "../d/chang_an/chang_an_duchang1.h" 
#include "../d/chang_an/chang_an_duchang2.h" 
#include "../d/chang_an/chang_an_duchang3.h" 
#include "../d/chang_an/chang_an_duchang4.h" 
#include "../d/chang_an/chang_an_piggy.h" 
#include "../d/chang_an/chang_an_pukeroom.h" 
#include "../d/chang_an/chang_an_qianzhuang.h" 
#include "../d/chang_an/chang_an_qishi.h" 
#include "../d/chang_an/chang_an_shaiziroom.h" 
#include "../d/chang_an/chang_an_road1.h" 
#include "../d/chang_an/chang_an_road2.h" 
#include "../d/chang_an/chang_an_road4.h" 
#include "../d/chang_an/chang_an_hanguguan.h" 

CRoom * Load_ChangAn(string room_name)
{
	CRoom * r = NULL;

	//    ������
	if(room_name == "����")
		r = new CRchang_ancity();
	else if(room_name == "�������ӷ�")
		r = new CRChangAn_shaiziroom();
	else if(room_name == "��������������")
		r = new CRChangAn_qishi();
	else if(room_name == "�������Ǯׯ")
		r = new CRChangAn_qianzhuang();
	else if(room_name == "��������")
		r = new CRChangAn_pukeroom();
	else if(room_name == "������¥����")
		r = new CRChangAn_piggy();
	else if(room_name == "�����ַ�")
		r = new CRChangAn_club();
	else if(room_name == "�������귿")
		r = new CRChangAn_duchang4();
	else if(room_name == "����������")
		r = new CRChangAn_duchang3();
	else if(room_name == "����������")
		r = new CRChangAn_duchang2();
	else if(room_name == "����Ѻǩ��")
		r = new CRChangAn_duchang1();
	else if(room_name == "�����ַ���¥����")
		r = new CRChangAn_clubup();
	else if(room_name == "�����ָ�ʫ��")
		r = new CRChangAn_clubpoem();
	else if(room_name == "����������")
		r = new CRChangAn_club3();
	else if(room_name == "������ٵ�4")
		r = new CRChangAn_road4();
	else if(room_name == "������ٵ�2")
		r = new CRChangAn_road2();
	else if(room_name == "���������")
		r = new CRChangAn_road1();
	else if(room_name == "�������ȹ�")
		r = new CRChangAn_hanguguan();

	return r;
}