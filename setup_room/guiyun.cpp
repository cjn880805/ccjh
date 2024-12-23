#include "stdafx.h"
#include "../server/Room.h"

//����ׯ
#include "../d/gueiyun/gueiyuncity.h"
#include "../d/gueiyun/gueiyun_chufang.h"
#include "../d/gueiyun/gueiyun_liangong.h"
#include "../d/gueiyun/gueiyun_nanxiangfang.h"
#include "../d/gueiyun/gueiyun_nvxiangfang.h"
#include "../d/gueiyun/gueiyun_shufang.h"

CRoom * Load_GuiYun(string room_name)
{
	CRoom * r = NULL;

	//����ׯ
    if(room_name == "����ׯ")
		r = new CRGueiYuncity();
    else if(room_name == "����ׯ������")
		r = new CRGueiYun_liangong();
    else if(room_name == "����ׯ�鷿")
		r = new CRGueiYun_shufang();
    else if(room_name == "����ׯŮ�᷿")
		r = new CRGueiYun_nvxiangfang();
    else if(room_name == "����ׯ����")
		r = new CRGueiYun_chufang();
    else if(room_name == "����ׯ���᷿")
		r = new CRGueiYun_nanxiangfang();

	return r;
}