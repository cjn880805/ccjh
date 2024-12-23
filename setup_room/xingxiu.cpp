#include "stdafx.h"
#include "../server/Room.h"

//星宿
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

	//星宿
	if(room_name == "星宿海山间平地")
		r = new CRXingXiu_xxroad6();
	else if(room_name == "星宿海")
		r = new CRXingXiu_xxh1();
	else if(room_name == "星宿海逍遥洞")
		r = new CRXingXiu_xiaoyao();
	else if(room_name == "星宿海天山山路4")
		r = new CRXingXiu_tianroad4();
	else if(room_name == "星宿海天山山路3")
		r = new CRXingXiu_tianroad3();
	else if(room_name == "星宿海天山山路2")
		r = new CRXingXiu_tianroad2();
	else if(room_name == "星宿派储藏室")
		r = new CRXingXiu_cangku();
	else if(room_name == "星宿海石道")
		r = new CRXingXiu_shidao();
	else if(room_name == "星宿海日月洞")
		r = new CRXingXiu_riyuedong();
	else if(room_name == "星宿海天山山路1")
		r = new CRXingXiu_tianroad1();
	else if(room_name == "星宿海小路")
		r = new CRXingXiu_xxroad4();		

	return r;
}