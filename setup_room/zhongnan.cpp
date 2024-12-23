#include "stdafx.h"
#include "../server/Room.h"

//����ɽ
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

	//����ɽ
    if(room_name == "����ɽ��")
		r = new CRZhongNancity();
    else if(room_name == "����ɽ���湬")
		r = new CRZhongNan_yuzhengong();
    else if(room_name == "����ɽС�ӱ�")
		r = new CRZhongNan_xiaohebian();
    else if(room_name == "����ɽ̫�ҳ�")
		r = new CRZhongNan_taiyi();
    else if(room_name == "����ɽ����9")
		r = new CRZhongNan_shulin9();
    else if(room_name == "����ɽ����8")
		r = new CRZhongNan_shulin8();
    else if(room_name == "����ɽ����7")
		r = new CRZhongNan_shulin7();
    else if(room_name == "����ɽ����10")
		r = new CRZhongNan_shulin10();
    else if(room_name == "����ɽʯ��8")
		r = new CRZhongNan_shijie8();
    else if(room_name == "����ɽʯ��7")
		r = new CRZhongNan_shijie7();
    else if(room_name == "����ɽʯ��6")
		r = new CRZhongNan_shijie6();
    else if(room_name == "����ɽʯ��5")
		r = new CRZhongNan_shijie5();
    else if(room_name == "����ɽʯ��4")
		r = new CRZhongNan_shijie4();
    else if(room_name == "����ɽʯ��3")
		r = new CRZhongNan_shijie3();
    else if(room_name == "����ɽʯ��2")
		r = new CRZhongNan_shijie2();
    else if(room_name == "����ɽʯ��1")
		r = new CRZhongNan_shijie1();
    else if(room_name == "����ɽ�Խ���")
		r = new CRZhongNan_shijianyan();
    else if(room_name == "����ɽ���ԭ")
		r = new CRZhongNan_shenheyuan();
    else if(room_name == "����ɽɽ��9")
		r = new CRZhongNan_shanlu9();
    else if(room_name == "����ɽɽ��8")
		r = new CRZhongNan_shanlu8();
    else if(room_name == "����ɽɽ·7")
		r = new CRZhongNan_shanlu7();
    else if(room_name == "����ɽɽ·6")
		r = new CRZhongNan_shanlu6();
    else if(room_name == "����ɽɽ·5")
		r = new CRZhongNan_shanlu5();
    else if(room_name == "����ɽɽ·4")
		r = new CRZhongNan_shanlu4();
    else if(room_name == "����ɽɽ·3")
		r = new CRZhongNan_shanlu3();
    else if(room_name == "����ɽɽ·2")
		r = new CRZhongNan_shanlu2();
    else if(room_name == "����ɽɽ��С��16")
		r = new CRZhongNan_shanlu16();
    else if(room_name == "����ɽɽ��С��15")
		r = new CRZhongNan_shanlu15();
    else if(room_name == "����ɽɽ��С��14")
		r = new CRZhongNan_shanlu14();
    else if(room_name == "����ɽ��·13")
		r = new CRZhongNan_shanlu13();
    else if(room_name == "����ɽɽ·12")
		r = new CRZhongNan_shanlu12();
    else if(room_name == "����ɽ��·11")
		r = new CRZhongNan_shanlu11();
    else if(room_name == "����ɽɽ·10")
		r = new CRZhongNan_shanlu10();
    else if(room_name == "����ɽɽ·1")
		r = new CRZhongNan_shanlu1();
    else if(room_name == "����ɽ��")
		r = new CRZhongNan_shanjiao();
    else if(room_name == "����ɽɽ��3")
		r = new CRZhongNan_shandao3();
    else if(room_name == "����ɽɽ��2")
		r = new CRZhongNan_shandao2();
    else if(room_name == "����ɽɽ��1")
		r = new CRZhongNan_shandao1();
    else if(room_name == "����ɽ��ٵ�")
		r = new CRZhongNan_road3();
    else if(room_name == "����ɽ������")
		r = new CRZhongNan_riyueyan();
    else if(room_name == "����ɽ�չ���")
		r = new CRZhongNan_puguangsi();
    else if(room_name == "����ɽ������")
		r = new CRZhongNan_juyan();
    else if(room_name == "����ɽ������")
		r = new CRZhongNan_jinliange();
    else if(room_name == "����ɽ�̱�")
		r = new CRZhongNan_jiaobei();
    else if(room_name == "����ɽ�ڷﶴ")
		r = new CRZhongNan_heifengdong();
    else if(room_name == "����ɽ����̨")
		r = new CRZhongNan_guanritai();
    else if(room_name == "����ɽ��ү��")
		r = new CRZhongNan_foyezhang();
    else if(room_name == "����ɽ����̶")
		r = new CRZhongNan_baimatang();
    else if(room_name == "����ɽ��У��")
		r = new CRZhongNan_daxiaochang();
    else if(room_name == "����ɽ������")
		r = new CRZhongNan_cuipinggu();
    else if(room_name == "����ɽ�����嶥")
		r = new CRZhongNan_cuipingfeng();
    else if(room_name == "����ɽ������")
		r = new CRZhongNan_caotangsi();
    else if(room_name == "����ɽ������")
		r = new CRZhongNan_baoziyan();
    else if(room_name == "����ɽ��ɽͤ")
		r = new CRZhongNan_banshanting();
    else if(room_name == "����ɽ������")
		r = new CRZhongNan_baishulin();
    else if(room_name == "����ɽ������")
		r = new CRZhongNan_fangzhenqiao();
    else if(room_name == "����ɽ�����ȵ�")
		r = new CRZhongNan_cuipinggudi();

	return r;
}



