#include "stdafx.h"
#include "../server/Room.h"

//终南山
#include "../d/zhongnan/zhongnan_baimatang.h"
#include "../d/zhongnan/zhongnan_baishulin.h"
#include "../d/zhongnan/zhongnan_banshanting.h"
#include "../d/zhongnan/zhongnan_baoziyan.h"
#include "../d/zhongnan/zhongnan_caotangsi.h"
#include "../d/zhongnan/zhongnan_cuipingfeng.h"
#include "../d/zhongnan/zhongnan_cuipinggu.h"
#include "../d/zhongnan/zhongnan_daxiaochang.h"
#include "../d/zhongnan/zhongnan_fangzhenqiao.h"
#include "../d/zhongnan/zhongnan_foyezhang.h"
#include "../d/zhongnan/zhongnan_guanritai.h"
#include "../d/zhongnan/zhongnan_heifengdong.h"
#include "../d/zhongnan/zhongnan_jiaobei.h"
#include "../d/zhongnan/zhongnan_jinliange.h"
#include "../d/zhongnan/zhongnan_juyan.h"
#include "../d/zhongnan/zhongnan_puguangsi.h"
#include "../d/zhongnan/zhongnan_riyueyan.h"
#include "../d/zhongnan/zhongnan_road3.h"
#include "../d/zhongnan/zhongnan_shandao1.h"
#include "../d/zhongnan/zhongnan_shandao2.h"
#include "../d/zhongnan/zhongnan_shandao3.h"
#include "../d/zhongnan/zhongnan_shanjiao.h"
#include "../d/zhongnan/zhongnan_shanlu1.h"
#include "../d/zhongnan/zhongnan_shanlu10.h"
#include "../d/zhongnan/zhongnan_shanlu11.h"
#include "../d/zhongnan/zhongnan_shanlu12.h"
#include "../d/zhongnan/zhongnan_shanlu13.h"
#include "../d/zhongnan/zhongnan_shanlu14.h"
#include "../d/zhongnan/zhongnan_shanlu15.h"
#include "../d/zhongnan/zhongnan_shanlu16.h"
#include "../d/zhongnan/zhongnan_shanlu2.h"
#include "../d/zhongnan/zhongnan_shanlu3.h"
#include "../d/zhongnan/zhongnan_shanlu4.h"
#include "../d/zhongnan/zhongnan_shanlu5.h"
#include "../d/zhongnan/zhongnan_shanlu6.h"
#include "../d/zhongnan/zhongnan_shanlu7.h"
#include "../d/zhongnan/zhongnan_shanlu8.h"
#include "../d/zhongnan/zhongnan_shanlu9.h"
#include "../d/zhongnan/zhongnan_shenheyuan.h"
#include "../d/zhongnan/zhongnan_shijianyan.h"
#include "../d/zhongnan/zhongnan_shijie1.h"
#include "../d/zhongnan/zhongnan_shijie2.h"
#include "../d/zhongnan/zhongnan_shijie3.h"
#include "../d/zhongnan/zhongnan_shijie4.h"
#include "../d/zhongnan/zhongnan_shijie5.h"
#include "../d/zhongnan/zhongnan_shijie6.h"
#include "../d/zhongnan/zhongnan_shijie7.h"
#include "../d/zhongnan/zhongnan_shijie8.h"
#include "../d/zhongnan/zhongnan_shulin10.h"
#include "../d/zhongnan/zhongnan_shulin7.h"
#include "../d/zhongnan/zhongnan_shulin8.h"
#include "../d/zhongnan/zhongnan_shulin9.h"
#include "../d/zhongnan/zhongnan_taiyi.h"
#include "../d/zhongnan/zhongnan_xiaohebian.h"
#include "../d/zhongnan/zhongnan_yuzhengong.h"
#include "../d/zhongnan/zhongnancity.h"
#include "../d/zhongnan/zhongnan_cuipinggudi.h"

CRoom * Load_ZhongNan(string room_name)
{
	CRoom * r = NULL;

	//终南山
    if(room_name == "终南山口")
		r = new CRZhongNancity();
    else if(room_name == "终南山遇真宫")
		r = new CRZhongNan_yuzhengong();
    else if(room_name == "终南山小河边")
		r = new CRZhongNan_xiaohebian();
    else if(room_name == "终南山太乙池")
		r = new CRZhongNan_taiyi();
    else if(room_name == "终南山树林9")
		r = new CRZhongNan_shulin9();
    else if(room_name == "终南山树林8")
		r = new CRZhongNan_shulin8();
    else if(room_name == "终南山树林7")
		r = new CRZhongNan_shulin7();
    else if(room_name == "终南山树林10")
		r = new CRZhongNan_shulin10();
    else if(room_name == "终南山石阶8")
		r = new CRZhongNan_shijie8();
    else if(room_name == "终南山石阶7")
		r = new CRZhongNan_shijie7();
    else if(room_name == "终南山石阶6")
		r = new CRZhongNan_shijie6();
    else if(room_name == "终南山石阶5")
		r = new CRZhongNan_shijie5();
    else if(room_name == "终南山石阶4")
		r = new CRZhongNan_shijie4();
    else if(room_name == "终南山石阶3")
		r = new CRZhongNan_shijie3();
    else if(room_name == "终南山石阶2")
		r = new CRZhongNan_shijie2();
    else if(room_name == "终南山石阶1")
		r = new CRZhongNan_shijie1();
    else if(room_name == "终南山试剑岩")
		r = new CRZhongNan_shijianyan();
    else if(room_name == "终南山神禾原")
		r = new CRZhongNan_shenheyuan();
    else if(room_name == "终南山山道9")
		r = new CRZhongNan_shanlu9();
    else if(room_name == "终南山山道8")
		r = new CRZhongNan_shanlu8();
    else if(room_name == "终南山山路7")
		r = new CRZhongNan_shanlu7();
    else if(room_name == "终南山山路6")
		r = new CRZhongNan_shanlu6();
    else if(room_name == "终南山山路5")
		r = new CRZhongNan_shanlu5();
    else if(room_name == "终南山山路4")
		r = new CRZhongNan_shanlu4();
    else if(room_name == "终南山山路3")
		r = new CRZhongNan_shanlu3();
    else if(room_name == "终南山山路2")
		r = new CRZhongNan_shanlu2();
    else if(room_name == "终南山山间小径16")
		r = new CRZhongNan_shanlu16();
    else if(room_name == "终南山山间小径15")
		r = new CRZhongNan_shanlu15();
    else if(room_name == "终南山山间小径14")
		r = new CRZhongNan_shanlu14();
    else if(room_name == "终南山道路13")
		r = new CRZhongNan_shanlu13();
    else if(room_name == "终南山山路12")
		r = new CRZhongNan_shanlu12();
    else if(room_name == "终南山道路11")
		r = new CRZhongNan_shanlu11();
    else if(room_name == "终南山山路10")
		r = new CRZhongNan_shanlu10();
    else if(room_name == "终南山山路1")
		r = new CRZhongNan_shanlu1();
    else if(room_name == "终南山脚")
		r = new CRZhongNan_shanjiao();
    else if(room_name == "终南山山道3")
		r = new CRZhongNan_shandao3();
    else if(room_name == "终南山山道2")
		r = new CRZhongNan_shandao2();
    else if(room_name == "终南山山道1")
		r = new CRZhongNan_shandao1();
    else if(room_name == "终南山大官道")
		r = new CRZhongNan_road3();
    else if(room_name == "终南山日月岩")
		r = new CRZhongNan_riyueyan();
    else if(room_name == "终南山普光寺")
		r = new CRZhongNan_puguangsi();
    else if(room_name == "终南山老妪岩")
		r = new CRZhongNan_juyan();
    else if(room_name == "终南山金莲阁")
		r = new CRZhongNan_jinliange();
    else if(room_name == "终南山教碑")
		r = new CRZhongNan_jiaobei();
    else if(room_name == "终南山黑凤洞")
		r = new CRZhongNan_heifengdong();
    else if(room_name == "终南山观日台")
		r = new CRZhongNan_guanritai();
    else if(room_name == "终南山佛爷掌")
		r = new CRZhongNan_foyezhang();
    else if(room_name == "终南山白马潭")
		r = new CRZhongNan_baimatang();
    else if(room_name == "终南山大校场")
		r = new CRZhongNan_daxiaochang();
    else if(room_name == "终南山翠屏谷")
		r = new CRZhongNan_cuipinggu();
    else if(room_name == "终南山翠屏峰顶")
		r = new CRZhongNan_cuipingfeng();
    else if(room_name == "终南山草堂寺")
		r = new CRZhongNan_caotangsi();
    else if(room_name == "终南山抱子岩")
		r = new CRZhongNan_baoziyan();
    else if(room_name == "终南山半山亭")
		r = new CRZhongNan_banshanting();
    else if(room_name == "终南山柏树林")
		r = new CRZhongNan_baishulin();
    else if(room_name == "终南山访真桥")
		r = new CRZhongNan_fangzhenqiao();
    else if(room_name == "终南山翠屏谷底")
		r = new CRZhongNan_cuipinggudi();

	return r;
}



