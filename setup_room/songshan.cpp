#include "stdafx.h"
#include "../server/Room.h"

//   嵩山
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

	//  嵩山
	if(room_name == "嵩山")
		r = new CRSongShancity();
	else if(room_name == "嵩山月台")
		r = new CRSongShan_yuetai();
	else if(room_name == "嵩山铁梁峡")
		r = new CRSongShan_tieliang();
	else if(room_name == "嵩山天中阁")
		r = new CRShongShan_tianzhongge();
	else if(room_name == "嵩山塔院")
		r = new CRSongShan_tayuan();
	else if(room_name == "嵩山太室阙")
		r = new CRSongShan_taishique();
	else if(room_name == "嵩山嵩岳塔")
		r = new CRSongShan_songyueta();
	else if(room_name == "嵩山嵩岳寺")
		r = new CRShongShan_songyuesi();
	else if(room_name == "嵩山嵩阳书院")
		r = new CRShongShan_shuyuan();
	else if(room_name == "嵩山山道6")
		r = new CRSongShan_shandao6();
	else if(room_name == "嵩山山道5")
		r = new CRSongShan_shandao5();
	else if(room_name == "嵩山山道4")
		r = new CRSongShan_shandao4();
	else if(room_name == "嵩山山道3")
		r = new CRSongShan_shandao3();
	else if(room_name == "嵩山山道2")
		r = new CRSongShan_shandao2();
	else if(room_name == "嵩山山道1")
		r = new CRSongShan_shandao1();
	else if(room_name == "嵩山启母石")
		r = new CRSongShan_qimushi();
	else if(room_name == "嵩山启母阙")
		r = new CRSongShan_qimuque();
	else if(room_name == "嵩山芦岩瀑布")
		r = new CRSongShan_luyanpubu();
	else if(room_name == "嵩山峻极禅院山门")
		r = new CRSongShan_junjigate();
	else if(room_name == "嵩山朝天门")
		r = new CRSongShan_chaotian();
	else if(room_name == "嵩山中岳大殿")
		r = new CRSongShan_dadian();
	else if(room_name == "嵩山崇圣门")
		r = new CRSongShan_chongsheng();
	else if(room_name == "嵩山法王寺")
		r = new CRSongShan_fawangsi();
	else if(room_name == "嵩山封禅台")
		r = new CRSongShan_fengchan();

	return r;
}