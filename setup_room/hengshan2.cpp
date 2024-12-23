#include "stdafx.h"
#include "../server/Room.h"

//恒山
#include "../d/hengshan2/hengshancity2.h"
#include "../d/hengshan2/hengshan2_baiyunan.h"
#include "../d/hengshan2/hengshan2_beiyuedian.h"
#include "../d/hengshan2/hengshan2_beiyuemiao.h"
#include "../d/hengshan2/hengshan2_cuiping1.h"
#include "../d/hengshan2/hengshan2_cuiping2.h"
#include "../d/hengshan2/hengshan2_cuipinggu1.h"
#include "../d/hengshan2/hengshan2_cuipinggu2.h"
#include "../d/hengshan2/hengshan2_daziling.h"
#include "../d/hengshan2/hengshan2_guolaoling.h"
#include "../d/hengshan2/hengshan2_hufengkou.h"
#include "../d/hengshan2/hengshan2_jinlongxia.h"
#include "../d/hengshan2/hengshan2_sanjiaodian.h"
#include "../d/hengshan2/hengshan2_shandao1.h"
#include "../d/hengshan2/hengshan2_shandao2.h"
#include "../d/hengshan2/hengshan2_square.h"
#include "../d/hengshan2/hengshan2_tongyuangu.h"
#include "../d/hengshan2/hengshan2_xuankong.h"
#include "../d/hengshan2/hengshan2_yunge.h"
#include "../d/hengshan2/hengshan2_zhandao.h"

CRoom * Load_HengShan2(string room_name)
{
	CRoom * r = NULL;

	//恒山
    if(room_name == "恒山")
		r = new CRHengShancity2();
    else if(room_name == "恒山梯式栈道")
		r = new CRHengShan2_zhandao();
    else if(room_name == "恒山云阁虹桥")
		r = new CRHengShan2_yunge();
    else if(room_name == "恒山悬空寺")
		r = new CRHengShan2_xuankong();
    else if(room_name == "恒山通元谷")
		r = new CRHengShan2_tongyuangu();
    else if(room_name == "恒山见性峰广场")
		r = new CRHengShan2_huixiantai();
    else if(room_name == "恒山见性峰山道2")
		r = new CRHengShan2_shandao2();
    else if(room_name == "恒山见性峰山道1")
		r = new CRHengShan2_shandao1();
    else if(room_name == "恒山虎风口")
		r = new CRHengShan2_hufengkou();
    else if(room_name == "恒山果老岭")
		r = new CRHengShan2_guolaoling();
    else if(room_name == "恒山大字岭")
		r = new CRHengShan2_daziling();
    else if(room_name == "恒山北岳庙")
		r = new CRHengShan2_beiyuemiao();
    else if(room_name == "恒山北岳殿")
		r = new CRHengShan2_beiyuedian();
    else if(room_name == "恒山白云庵")
		r = new CRHengShan2_baiyunan();
    else if(room_name == "恒山翠屏山道1")
		r = new CRHengShan2_cuiping1();
    else if(room_name == "恒山三教殿")
		r = new CRHengShan2_sanjiaodian();
    else if(room_name == "恒山金龙峡")
		r = new CRHengShan2_jinlongxia();
    else if(room_name == "恒山翠屏谷2")
		r = new CRHengShan2_cuipinggu2();
    else if(room_name == "恒山翠屏谷1")
		r = new CRHengShan2_cuipinggu1();
    else if(room_name == "恒山翠屏山道2")
		r = new CRHengShan2_cuiping2();

	return r;
}