#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"

//����
#include "../d/xiyu_room.h"
#include "../d/xiyu/xiyu.h"
#include "../d/xiyu/xiyu_caoyuan.h"
#include "../d/xiyu/xiyu_damo.h"
#include "../d/xiyu/xiyu_jiayuguan.h"
#include "../d/xiyu/xiyu_shamo.h"
#include "../d/xiyu/xiyu_sichouzilu1.h"
#include "../d/xiyu/xiyu_sichouzilu2.h"
#include "../d/xiyu/xiyu_sichouzilu3.h"
#include "../d/xiyu/xiyu_sichouzilu4.h"
#include "../d/xiyu/xiyu_tianshanjiaoxia.h"
#include "../d/xiyu/xiyu_tianshanlu1.h"
#include "../d/xiyu/xiyu_tianshanlu2.h"

CRoom * Load_XiYu(string room_name)
{
	CRoom * r = NULL;

	//����
	if(room_name == "������ɽɽ·2")
		r = new CRXiYu_tianshanlu2();
	else if(room_name == "������ɽɽ·1")
		r = new CRXiYu_tianshanlu();
	else if(room_name == "������ɽ����")
		r = new CRXiYu_tianshanjiaoxia();
	else if(room_name == "����˿��֮·4")
		r = new CRXiYu_sichouzilu4();
	else if(room_name == "����˿��֮·3")
		r = new CRXiYu_sichouzilu3();
	else if(room_name == "����˿��֮·2")
		r = new CRXiYu_sichouzilu2();
	else if(room_name == "����˿��֮·1")
		r = new CRXiYu_sichouzilu1();
	else if(room_name == "���������")
		r = new CRXiYu_jiayuguan();
	else if(room_name == "�����Į")
		r = new CRXiYu_damo();
	else if(room_name == "�����ԭ")
		r = new CRXiYu_caoyuan();
	else if(room_name == "�����Ͻ�ɳĮ")
		r = new CRXiYu_shamo();
	else if(room_name == "����")
		r = new CRXiYu();

	return r;
}