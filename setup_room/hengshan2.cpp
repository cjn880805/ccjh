#include "stdafx.h"
#include "../server/Room.h"

//��ɽ
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

	//��ɽ
    if(room_name == "��ɽ")
		r = new CRHengShancity2();
    else if(room_name == "��ɽ��ʽջ��")
		r = new CRHengShan2_zhandao();
    else if(room_name == "��ɽ�Ƹ����")
		r = new CRHengShan2_yunge();
    else if(room_name == "��ɽ������")
		r = new CRHengShan2_xuankong();
    else if(room_name == "��ɽͨԪ��")
		r = new CRHengShan2_tongyuangu();
    else if(room_name == "��ɽ���Է�㳡")
		r = new CRHengShan2_huixiantai();
    else if(room_name == "��ɽ���Է�ɽ��2")
		r = new CRHengShan2_shandao2();
    else if(room_name == "��ɽ���Է�ɽ��1")
		r = new CRHengShan2_shandao1();
    else if(room_name == "��ɽ�����")
		r = new CRHengShan2_hufengkou();
    else if(room_name == "��ɽ������")
		r = new CRHengShan2_guolaoling();
    else if(room_name == "��ɽ������")
		r = new CRHengShan2_daziling();
    else if(room_name == "��ɽ������")
		r = new CRHengShan2_beiyuemiao();
    else if(room_name == "��ɽ������")
		r = new CRHengShan2_beiyuedian();
    else if(room_name == "��ɽ������")
		r = new CRHengShan2_baiyunan();
    else if(room_name == "��ɽ����ɽ��1")
		r = new CRHengShan2_cuiping1();
    else if(room_name == "��ɽ���̵�")
		r = new CRHengShan2_sanjiaodian();
    else if(room_name == "��ɽ����Ͽ")
		r = new CRHengShan2_jinlongxia();
    else if(room_name == "��ɽ������2")
		r = new CRHengShan2_cuipinggu2();
    else if(room_name == "��ɽ������1")
		r = new CRHengShan2_cuipinggu1();
    else if(room_name == "��ɽ����ɽ��2")
		r = new CRHengShan2_cuiping2();

	return r;
}