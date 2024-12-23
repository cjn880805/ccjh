#include "stdafx.h"
#include "../std/FightRoom.h"
#include "../std/wl.h"

//–¬ ÷±£ª§«¯
#include "../d/wuliinchun/wulin_beiqiouge.h"
#include "../d/wuliinchun/wulin_changlang1.h"
#include "../d/wuliinchun/wulin_changlang2.h"
#include "../d/wuliinchun/wulin_chonglou.h"
#include "../d/wuliinchun/wulin_cudaifeng.h"
#include "../d/wuliinchun/wulin_cueimeitai.h"
#include "../d/wuliinchun/wulin_diyuange.h"
#include "../d/wuliinchun/wulin_fengbinfeng.h"
#include "../d/wuliinchun/wulin_fengyuelou.h"
#include "../d/wuliinchun/wulin_hebidating.h"
#include "../d/wuliinchun/wulin_honglangge.h"
#include "../d/wuliinchun/wulin_houmen.h"
#include "../d/wuliinchun/wulin_houyuan.h"
#include "../d/wuliinchun/wulin_houyuandamen.h"
#include "../d/wuliinchun/wulin_jichugu.h"
#include "../d/wuliinchun/wulin_jingniting.h"
#include "../d/wuliinchun/wulin_jioupengting.h"
#include "../d/wuliinchun/wulin_lianergu.h"
#include "../d/wuliinchun/wulin_liangou.h"
#include "../d/wuliinchun/wulin_luorilin.h"
#include "../d/wuliinchun/wulin_muyunge.h"
#include "../d/wuliinchun/wulin_nianjinfeng.h"
#include "../d/wuliinchun/wulin_nianwoge.h"
#include "../d/wuliinchun/wulin_ningmouge.h"
#include "../d/wuliinchun/wulin_pucueigu.h"
#include "../d/wuliinchun/wulin_ranliouchi.h"
#include "../d/wuliinchun/wulin_rongjingcheng.h"
#include "../d/wuliinchun/wulin_rumengfeng.h"
#include "../d/wuliinchun/wulin_shilvge.h"
#include "../d/wuliinchun/wulin_shutouxi.h"
#include "../d/wuliinchun/wulin_xianglengshanzhuang.h"
#include "../d/wuliinchun/wulin_xiaoyufeng.h"
#include "../d/wuliinchun/wulin_xinchougge.h"
#include "../d/wuliinchun/wulin_xuebinfeng.h"
#include "../d/wuliinchun/wulin_xueliougu.h"
#include "../d/wuliinchun/wulin_yannongge.h"
#include "../d/wuliinchun/wulin_zhengting.h"
#include "../d/wuliinchun/wulin_zhongzhouxiaodao.h"

CRoom * Load_WuLin(string room_name)
{
	CRoom * r = NULL;
	
	if(room_name == "Œ‰¡Í¥∫¬‰»’¡÷")	r = new CRWuLin_luorilin();	
	else if(room_name == "Œ‰¡Í¥∫±Ø«Ô∏Û")r = new CRWuLin_beiqiouge();
	else if(room_name == "Œ‰¡Í¥∫≥§¿»1")r = new CRWuLin_changlang1();
	else if(room_name == "Œ‰¡Í¥∫≥§¿»2")r = new CRWuLin_changlang2();
	else if(room_name == "Œ‰¡Í¥∫÷ÿ¬•")r = new CRWuLin_chonglou();
	else if(room_name == "Œ‰¡Í¥∫¥ÿ¥¯∑Â")r = new CRWuLin_cudaifeng();
	else if(room_name == "Œ‰¡Í¥∫¥µ√∑Ã®")r = new CRWuLin_cueimeitai();
	else if(room_name == "Œ‰¡Í¥∫µ—‘π∏Û")r = new CRWuLin_diyuange();
	else if(room_name == "Œ‰¡Í¥∫∑Á˜ﬁ∑Â")r = new CRWuLin_fengbinfeng();
	else if(room_name == "Œ‰¡Í¥∫∑Á”Í¬•")r = new CRWuLin_fengyuelou();
	else if(room_name == "Œ‰¡Í¥∫∫œ±⁄…Ω◊Ø¥Û√≈")r = new CRWuLin_hebidating();
	else if(room_name == "Œ‰¡Í¥∫∫Ï¿À∏Û")r = new CRWuLin_honglangge();
	else if(room_name == "Œ‰¡Í¥∫∫œ±⁄…Ω◊Ø∫Û√≈")r = new CRWuLin_houmen();
	else if(room_name == "Œ‰¡Í¥∫œ„¿‰…Ω◊Ø∫Û‘∫")r = new CRWuLin_houyuan();
	else if(room_name == "Œ‰¡Í¥∫œ„¿‰…Ω◊Ø∫Û‘∫¥Û√≈")r = new CRWuLin_houyuandamen();
	else if(room_name == "Œ‰¡Í¥∫º√≥˛π»")r = new CRWuLin_jichugu();
	else if(room_name == "Œ‰¡Í¥∫Ω‚•Ã¸")r = new CRWuLin_jingniting();
	else if(room_name == "Œ‰¡Í¥∫æ∆≈ÛÃ¸")r = new CRWuLin_jioupengting();
	else if(room_name == "Œ‰¡Í¥∫¡±∂˘π»")r = new CRWuLin_lianergu();
	else if(room_name == "Œ‰¡Í¥∫¡±π≥")r = new CRWuLin_liangou();
	else if(room_name == "Œ‰¡Í¥∫ƒ∫‘∆∏Û")r = new CRWuLin_muyunge();
	else if(room_name == "Œ‰¡Í¥∫ƒÌΩ∑Â")r = new CRWuLin_nianjinfeng();
	else if(room_name == "Œ‰¡Í¥∫ƒÓŒ“∏Û")r = new CRWuLin_nianwoge();
	else if(room_name == "Œ‰¡Í¥∫ƒ˝Ì¯∏Û")r = new CRWuLin_ningmouge();
	else if(room_name == "Œ‰¡Í¥∫∆Ã¥‰π»")r = new CRWuLin_pucueigu();
	else if(room_name == "Œ‰¡Í¥∫»æ¡¯≥ÿ")r = new CRWuLin_ranliouchi();
	else if(room_name == "Œ‰¡Í¥∫»€Ω≥«")r = new CRWuLin_rongjingcheng();
	else if(room_name == "Œ‰¡Í¥∫»Á√Œ∑Â")r = new CRWuLin_rumengfeng();
	else if(room_name == "Œ‰¡Í¥∫ ´¬¬∏Û")r = new CRWuLin_shilvge();
	else if(room_name == "Œ‰¡Í¥∫ ·Õ∑œ™")r = new CRWuLin_shutouxi();
	else if(room_name == "Œ‰¡Í¥∫œ„¿‰…Ω◊Ø¥Û√≈")r = new CRWuLin_xianglengshanzhuang();
	else if(room_name == "Œ‰¡Í¥∫–¶”Ô∑Â")r = new CRWuLin_xiaoyufeng();
	else if(room_name == "Œ‰¡Í¥∫–¬≥Ó∏Û")r = new CRWuLin_xinchougge();
	else if(room_name == "Œ‰¡Í¥∫—©˜ﬁ∑Â")r = new CRWuLin_xuebinfeng();
	else if(room_name == "Œ‰¡Í¥∫—©¡¯π»")r = new CRWuLin_xueliougu();
	else if(room_name == "Œ‰¡Í¥∫—Ã≈®∏Û")r = new CRWuLin_yannongge();
	else if(room_name == "Œ‰¡Í¥∫’˝Ã¸")r = new CRWuLin_zhengting();
	else if(room_name == "Œ‰¡Í¥∫÷–÷ﬁ–°µ¿")r = new CRWuLin_zhongzhouxiaodao();
	
	return r;
}







