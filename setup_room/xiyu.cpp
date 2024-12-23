#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"

//西域
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

	//西域
	if(room_name == "西域天山山路2")
		r = new CRXiYu_tianshanlu2();
	else if(room_name == "西域天山山路1")
		r = new CRXiYu_tianshanlu();
	else if(room_name == "西域天山脚下")
		r = new CRXiYu_tianshanjiaoxia();
	else if(room_name == "西域丝绸之路4")
		r = new CRXiYu_sichouzilu4();
	else if(room_name == "西域丝绸之路3")
		r = new CRXiYu_sichouzilu3();
	else if(room_name == "西域丝绸之路2")
		r = new CRXiYu_sichouzilu2();
	else if(room_name == "西域丝绸之路1")
		r = new CRXiYu_sichouzilu1();
	else if(room_name == "西域嘉峪关")
		r = new CRXiYu_jiayuguan();
	else if(room_name == "西域大漠")
		r = new CRXiYu_damo();
	else if(room_name == "西域草原")
		r = new CRXiYu_caoyuan();
	else if(room_name == "西域南疆沙漠")
		r = new CRXiYu_shamo();
	else if(room_name == "西域")
		r = new CRXiYu();

	return r;
}