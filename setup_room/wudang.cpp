#include "stdafx.h"
#include "../server/Room.h"
#include "../server/Char.h"

//�䵱
#include "../d/wudang/wudang_chaotiangong.h"
#include "../d/wudang/wudang_ertiangate.h"
#include "../d/wudang/wudang_fuzhenguan.h"
#include "../d/wudang/wudang_gaotai.h"
#include "../d/wudang/wudang_guangchang.h"
#include "../d/wudang/wudang_gytoad1.h"
#include "../d/wudang/wudang_gytoad2.h"
#include "../d/wudang/wudang_haohanpo.h"
#include "../d/wudang/wudang_huixianqiao.h"
#include "../d/wudang/wudang_hutouyan.h"
#include "../d/wudang/wudang_jiejianyan.h"
#include "../d/wudang/wudang_jindian.h"
#include "../d/wudang/wudang_jinding.h"
#include "../d/wudang/wudang_landmeiyuan.h"
#include "../d/wudang/wudang_mozhenjing.h"
#include "../d/wudang/wudang_nanyanfeng.h"
#include "../d/wudang/wudang_nanyangong.h"
#include "../d/wudang/wudang_sanbuguan.h"
#include "../d/wudang/wudang_sanlaofeng.h"
#include "../d/wudang/wudang_sanqingdian.h"
#include "../d/wudang/wudang_santiangate.h"
#include "../d/wudang/wudang_shanlu1.h"
#include "../d/wudang/wudang_shanlu4.h"
#include "../d/wudang/wudang_sheshenya.h"
#include "../d/wudang/wudang_shibapan.h"
#include "../d/wudang/wudang_shierliantai.h"
#include "../d/wudang/wudang_shiliang.h"
#include "../d/wudang/wudang_shizhu.h"
#include "../d/wudang/wudang_shop.h"
#include "../d/wudang/wudang_songlin.h"
#include "../d/wudang/wudang_taizipo.h"
#include "../d/wudang/wudang_taiziyan.h"
#include "../d/wudang/wudang_taoyuan.h"
#include "../d/wudang/wudang_toutiangate.h"
#include "../d/wudang/wudang_tygate1.h"
#include "../d/wudang/wudang_tygate2.h"
#include "../d/wudang/wudang_tynroad.h"
#include "../d/wudang/wudang_tyroad1.h"
#include "../d/wudang/wudang_tyroad10.h"
#include "../d/wudang/wudang_tyroad8.h"
#include "../d/wudang/wudang_tyroad9.h"
#include "../d/wudang/wudang_wdbl.h"
#include "../d/wudang/wudang_wdroad1.h"
#include "../d/wudang/wudang_wdroad2.h"
#include "../d/wudang/wudang_wdroad3.h"
#include "../d/wudang/wudang_wulaofeng.h"
#include "../d/wudang/wudang_wuyaling.h"
#include "../d/wudang/wudang_xuanyuegate.h"
#include "../d/wudang/wudang_yuzhengong.h"
#include "../d/wudang/wudang_zijincheng.h"
#include "../d/wudang/wudang_zixiaogonggate.h"
#include "../d/wudang/wudangcity.h"

CRoom * Load_WuDang(string room_name)
{
	CRoom * r = NULL;

	//�䵱
    if(room_name == "�䵱�Ͻ��")
		r = new CRWuDang_zijincheng();
    else if(room_name == "�䵱��ѻ��")
		r = new CRWuDang_wuyaling();
    else if(room_name == "�䵱���Ϸ�")
		r = new CRWuDang_wulaofeng();
    else if(room_name == "�䵱ͷ����")
		r = new CRWuDang_toutiangate();
    else if(room_name == "�䵱̫����")
		r = new CRWuDang_taiziyan();
    else if(room_name == "�䵱ʯ��")
		r = new CRWuDang_shizhu();
    else if(room_name == "�䵱ʮ����̨")
		r = new CRWuDang_shierliantai();
    else if(room_name == "�䵱������")
		r = new CRWuDang_sheshenya();
    else if(room_name == "�䵱������")
		r = new CRWuDang_santiangate();
    else if(room_name == "�䵱���Ϸ�")
		r = new CRWuDang_sanlaofeng();
    else if(room_name == "�䵱���ҹ�")
		r = new CRWuDang_nanyangong();
    else if(room_name == "�䵱���ҷ�")
		r = new CRWuDang_nanyanfeng();
    else if(room_name == "�䵱��÷԰")
		r = new CRWuDang_landmeiyuan();
    else if(room_name == "�䵱��")
		r = new CRWuDang_jinding();
    else if(room_name == "�䵱���")
		r = new CRWuDang_jindian();
    else if(room_name == "�䵱��ͷ��")
		r = new CRWuDang_hutouyan();
    else if(room_name == "�䵱������")
		r = new CRWuDang_huixianqiao();
    else if(room_name == "�䵱�㳡")
		r = new CRWuDang_guangchang();
    else if(room_name == "�䵱���ҹ���̨")
		r = new CRWuDang_gaotai();
    else if(room_name == "�䵱������")
		r = new CRWuDang_ertiangate();
    else if(room_name == "�䵱���칬")
		r = new CRWuDang_chaotiangong();
    else if(room_name == "�䵱����������")
		r = new CRWuDang_zixiaogonggate();
    else if(room_name == "�䵱���湬")
		r = new CRWuDang_yuzhengong();
    else if(room_name == "�䵱������")
		r = new CRWuDang_xuanyuegate();
    else if(room_name == "�䵱����·3")
		r = new CRWuDang_wdroad3();
    else if(room_name == "�䵱����·2")
		r = new CRWuDang_wdroad2();
    else if(room_name == "�䵱��ʯ���1")
		r = new CRWuDang_wdroad1();
    else if(room_name == "�䵱����")
		r = new CRWuDang_wdbl();
    else if(room_name == "�䵱��԰С·9")
		r = new CRWuDang_tyroad9();
    else if(room_name == "�䵱��԰С·8")
		r = new CRWuDang_tyroad8();
    else if(room_name == "�䵱��԰С·10")
		r = new CRWuDang_tyroad10();
    else if(room_name == "�䵱ʯ��")
		r = new CRWuDang_tyroad1();
    else if(room_name == "�䵱��԰С·")
		r = new CRWuDang_tynroad();
    else if(room_name == "�䵱��԰���2")
		r = new CRWuDang_tygate2();
    else if(room_name == "�䵱��԰���1")
		r = new CRWuDang_tygate1();
    else if(room_name == "�䵱̫����")
		r = new CRWuDang_taizipo();
    else if(room_name == "�䵱��԰")
		r = new CRWuDang_taoyuan();
    else if(room_name == "�䵱����")
		r = new CRWuDang_songlin();
    else if(room_name == "�䵱С�Ե�")
		r = new CRWuDang_shop();
    else if(room_name == "�䵱ʯ��")
		r = new CRWuDang_shiliang();
    else if(room_name == "�䵱�����")
		r = new CRWuDang_fuzhenguan();
    else if(room_name == "�䵱ɽ·4")
		r = new CRWuDang_shanlu4();
    else if(room_name == "�䵱ɽ·1")
		r = new CRWuDang_shanlu1();
    else if(room_name == "�䵱�����")
		r = new CRWuDang_sanqingdian();
    else if(room_name == "�䵱������")
		r = new CRWuDang_sanbuguan();
    else if(room_name == "�䵱ĥ�뾮")
		r = new CRWuDang_mozhenjing();
    else if(room_name == "�䵱�⽣��")
		r = new CRWuDang_jiejianyan();
    else if(room_name == "�䵱�ú���")
		r = new CRWuDang_haohanpo();
    else if(room_name == "�䵱��԰С·2")
		r = new CRWuDang_gytoad2();
    else if(room_name == "�䵱��԰С·1")
		r = new CRWuDang_gytoad1();
    else if(room_name == "�䵱ʮ����")
		r = new CRWuDang_shibapan();
    else if(room_name == "�䵱")
		r = new CRWuDangcity();

	return r;
}