#include "stdafx.h"
#include "../server/Room.h"
#include "../server/Char.h"
#include "../std/Money.h"

//昆仑明教
#include "../d/mingjiao/mingjiao_dadian.h"
#include "../d/mingjiao/mingjiao_daoshe.h"
#include "../d/mingjiao/mingjiao_fangtang.h"
#include "../d/mingjiao/mingjiao_hsqdating.h"
#include "../d/mingjiao/mingjiao_hsqmen.h"
#include "../d/mingjiao/mingjiao_htqdating.h"
#include "../d/mingjiao/mingjiao_htqmen.h"
#include "../d/mingjiao/mingjiao_jmqdating.h"
#include "../d/mingjiao/mingjiao_jmqmen.h"
#include "../d/mingjiao/mingjiao_lhqdating.h"
#include "../d/mingjiao/mingjiao_lhqmen.h"
#include "../d/mingjiao/mingjiao_lhqpaifang.h"
#include "../d/mingjiao/mingjiao_mjdimen.h"
#include "../d/mingjiao/mingjiao_mjfengmen1.h"
#include "../d/mingjiao/mingjiao_mjleimen.h"
#include "../d/mingjiao/mingjiao_mjtianmen.h"
#include "../d/mingjiao/mingjiao_nanshe.h"
#include "../d/mingjiao/mingjiao_nushe.h"
#include "../d/mingjiao/mingjiao_qsdadao1.h"
#include "../d/mingjiao/mingjiao_qsdadao2.h"
#include "../d/mingjiao/mingjiao_qsdadao3.h"
#include "../d/mingjiao/mingjiao_qsdadao4.h"
#include "../d/mingjiao/mingjiao_qsdadao5.h"
#include "../d/mingjiao/mingjiao_qsdadao6.h"
#include "../d/mingjiao/mingjiao_qsdadao7.h"
#include "../d/mingjiao/mingjiao_qsdadao8.h"
#include "../d/mingjiao/mingjiao_qsdadao9.h"
#include "../d/mingjiao/mingjiao_rjqdating.h"
#include "../d/mingjiao/mingjiao_rjqmen.h"
#include "../d/mingjiao/mingjiao_rjyuan.h"
#include "../d/mingjiao/mingjiao_shanmen.h"
#include "../d/mingjiao/mingjiao_simenguangchang.h"
#include "../d/mingjiao/mingjiao_square.h"
#include "../d/mingjiao/mingjiao_sushe.h"
#include "../d/mingjiao/mingjiao_tianweitang.h"
#include "../d/mingjiao/mingjiao_xingtang.h"
#include "../d/mingjiao/mingjiao_xuantianya.h"
#include "../d/mingjiao/mingjiao_zhandao.h"
#include "../d/mingjiao/mingjiao.h"
//秘道
#include "../d/mjmidao/mingjiao_md1.h"
#include "../d/mjmidao/mingjiao_md2.h"
#include "../d/mjmidao/mingjiao_md3.h"
#include "../d/mjmidao/mingjiao_md4.h"
#include "../d/mjmidao/mingjiao_md5.h"
#include "../d/mjmidao/mingjiao_md6.h"
#include "../d/mjmidao/mingjiao_md7.h"
#include "../d/mjmidao/mingjiao_md8.h"
#include "../d/mjmidao/mingjiao_mishi.h"
//#include "../d/mjmidao/mingjiao_midao.h"

CRoom * Load_MingJiao(string room_name)
{
	CRoom * r = NULL;

	//昆仑明教
	if(room_name == "明教栈道")
		r = new CRMingJiao_zhandao();
	else if(room_name == "明教悬天崖")
		r = new CRMingJiao_xuantianya();
	else if(room_name == "明教刑堂")
		r = new CRMingJiao_xingtang();
	else if(room_name == "明教天微堂")
		r = new CRMingJiao_tianweitang();
	else if(room_name == "明教雷门宿舍")
		r = new CRMingJiao_sushe();
	else if(room_name == "明教广场")
		r = new CRMingJiao_square();
	else if(room_name == "明教四门广场")
		r = new CRMingJiao_simenguangchang();
	else if(room_name == "明教山门")
		r = new CRMingJiao_shanmen();
	else if(room_name == "明教大院")
		r = new CRMingJiao_rjyuan();
	else if(room_name == "明教锐金旗大厅")
		r = new CRMingJiao_rjqdating();
	else if(room_name == "明教青石大道9")
		r = new CRMingJiao_qsdadao9();
	else if(room_name == "明教青石大道8")
		r = new CRMingJiao_qsdadao8();
	else if(room_name == "明教青石大道7")
		r = new CRMingJiao_qsdadao7();
	else if(room_name == "明教青石大道6")
		r = new CRMingJiao_qsdadao6();
	else if(room_name == "明教青石大道5")
		r = new CRMingJiao_qsdadao5();
	else if(room_name == "明教青石大道4")
		r = new CRMingJiao_qsdadao4();
	else if(room_name == "明教青石大道3")
		r = new CRMingJiao_qsdadao3();
	else if(room_name == "明教青石大道2")
		r = new CRMingJiao_qsdadao2();
	else if(room_name == "明教青石大道1")
		r = new CRMingJiao_qsdadao1();
	else if(room_name == "明教地门女舍")
		r = new CRMingJiao_nushe();
	else if(room_name == "明教天门男舍")
		r = new CRMingJiao_nanshe();
	else if(room_name == "明教烈火旗牌坊")
		r = new CRMingJiao_lhqpaifang();
	else if(room_name == "明教烈火旗大厅")
		r = new CRMingJiao_lhqdating();
	else if(room_name == "明教巨木旗大厅")
		r = new CRMingJiao_jmqdating();
	else if(room_name == "明教昆仑山下")
		r = new CRMingJiaocity();
	else if(room_name == "明教洪水旗大厅")
		r = new CRMingJiao_hsqdating();
	else if(room_name == "明教饭堂")
		r = new CRMingJiao_fangtang();
	else if(room_name == "明教道家竹舍")
		r = new CRMingJiao_daoshe();
	else if(room_name == "明教大殿")
		r = new CRMingJiao_dadian();
	else if(room_name == "明教厚土旗大厅")
		r = new CRMingJiao_htqdating();

	else if(room_name == "明教秘道1")
		r = new CRMingJiao_md1();
	else if(room_name == "明教秘道2")
		r = new CRMingJiao_md2();
	else if(room_name == "明教秘道3")
		r = new CRMingJiao_md3();
	else if(room_name == "明教秘道4")
		r = new CRMingJiao_md4();
	else if(room_name == "明教秘道5")
		r = new CRMingJiao_md5();
	else if(room_name == "明教秘道6")
		r = new CRMingJiao_md6();
	else if(room_name == "明教秘道7")
		r = new CRMingJiao_md7();
	else if(room_name == "明教秘道8")
		r = new CRMingJiao_md8();
	else if(room_name == "明教密室")
		r = new CRMingJiao_mishi();

	return r;
}