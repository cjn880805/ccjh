#include "stdafx.h"
#include "../server/Room.h"

//   ��ɽ
#include "../d/songshan/songshancity.h"
#include "../d/songshan/songshan_chaotian.h"
#include "../d/songshan/songshan_chongsheng.h"
#include "../d/songshan/songshan_dadian.h"
#include "../d/songshan/songshan_fawangsi.h"
#include "../d/songshan/songshan_junjigate.h"
#include "../d/songshan/songshan_luyanpubu.h"
#include "../d/songshan/songshan_qimuque.h"
#include "../d/songshan/songshan_qimushi.h"
#include "../d/songshan/songshan_shandao1.h"
#include "../d/songshan/songshan_shandao2.h"
#include "../d/songshan/songshan_shandao3.h"
#include "../d/songshan/songshan_shandao4.h"
#include "../d/songshan/songshan_shandao5.h"
#include "../d/songshan/songshan_shandao6.h"
#include "../d/songshan/songshan_shuyuan.h"
#include "../d/songshan/songshan_songyuesi.h"
#include "../d/songshan/songshan_songyueta.h"
#include "../d/songshan/songshan_taishique.h"
#include "../d/songshan/songshan_tayuan.h"
#include "../d/songshan/songshan_tianzhongge.h"
#include "../d/songshan/songshan_tieliang.h"
#include "../d/songshan/songshan_yuetai.h"
#include "../d/songshan/songshan_fengchan.h"

CRoom * Load_SongShan(string room_name)
{
	CRoom * r = NULL;

	//  ��ɽ
	if(room_name == "��ɽ")
		r = new CRSongShancity();
	else if(room_name == "��ɽ��̨")
		r = new CRSongShan_yuetai();
	else if(room_name == "��ɽ����Ͽ")
		r = new CRSongShan_tieliang();
	else if(room_name == "��ɽ���и�")
		r = new CRShongShan_tianzhongge();
	else if(room_name == "��ɽ��Ժ")
		r = new CRSongShan_tayuan();
	else if(room_name == "��ɽ̫����")
		r = new CRSongShan_taishique();
	else if(room_name == "��ɽ������")
		r = new CRSongShan_songyueta();
	else if(room_name == "��ɽ������")
		r = new CRShongShan_songyuesi();
	else if(room_name == "��ɽ������Ժ")
		r = new CRShongShan_shuyuan();
	else if(room_name == "��ɽɽ��6")
		r = new CRSongShan_shandao6();
	else if(room_name == "��ɽɽ��5")
		r = new CRSongShan_shandao5();
	else if(room_name == "��ɽɽ��4")
		r = new CRSongShan_shandao4();
	else if(room_name == "��ɽɽ��3")
		r = new CRSongShan_shandao3();
	else if(room_name == "��ɽɽ��2")
		r = new CRSongShan_shandao2();
	else if(room_name == "��ɽɽ��1")
		r = new CRSongShan_shandao1();
	else if(room_name == "��ɽ��ĸʯ")
		r = new CRSongShan_qimushi();
	else if(room_name == "��ɽ��ĸ��")
		r = new CRSongShan_qimuque();
	else if(room_name == "��ɽ«���ٲ�")
		r = new CRSongShan_luyanpubu();
	else if(room_name == "��ɽ������Ժɽ��")
		r = new CRSongShan_junjigate();
	else if(room_name == "��ɽ������")
		r = new CRSongShan_chaotian();
	else if(room_name == "��ɽ�������")
		r = new CRSongShan_dadian();
	else if(room_name == "��ɽ��ʥ��")
		r = new CRSongShan_chongsheng();
	else if(room_name == "��ɽ������")
		r = new CRSongShan_fawangsi();
	else if(room_name == "��ɽ����̨")
		r = new CRSongShan_fengchan();

	return r;
}