#include "stdafx.h"
#include "../std/FightRoom.h"
#include "../std/mf.h"


//≤ÿ±¶-√Œ‘Û…Ω
#include "../d/cangbaolin/CangBaoLin_choubiyi.h"
#include "../d/cangbaolin/CangBaoLin_dongmenchi.h"
#include "../d/cangbaolin/CangBaoLin_dulangu.h"
#include "../d/cangbaolin/CangBaoLin_elvxiaodao.h"
#include "../d/cangbaolin/CangBaoLin_fengyuedong.h"
#include "../d/cangbaolin/CangBaoLin_hengmen.h"
#include "../d/cangbaolin/CangBaoLin_huanshagu.h"
#include "../d/cangbaolin/CangBaoLin_jianxialin.h"
#include "../d/cangbaolin/CangBaoLin_jinsedong.h"
#include "../d/cangbaolin/CangBaoLin_liouyinxiaodao.h"
#include "../d/cangbaolin/CangBaoLin_longchi.h"
#include "../d/cangbaolin/CangBaoLin_mzeshanjiao.h"
#include "../d/cangbaolin/CangBaoLin_mzszhufeng.h"
#include "../d/cangbaolin/CangBaoLin_shuosudong.h"
#include "../d/cangbaolin/CangBaoLin_wanchougu.h"
#include "../d/cangbaolin/CangBaoLin_wanqinggu.h"
#include "../d/cangbaolin/CangBaoLin_wanqiou.h"
#include "../d/cangbaolin/CangBaoLin_weiyufeng.h"
#include "../d/cangbaolin/CangBaoLin_xiangfeilin.h"
#include "../d/cangbaolin/CangBaoLin_xiangsiting.h"
#include "../d/cangbaolin/CangBaoLin_xiyanglou.h"
#include "../d/cangbaolin/CangBaoLin_yaoci.h"
#include "../d/cangbaolin/CangBaoLin_yimeigu.h"
#include "../d/cangbaolin/CangBaoLin_yirenge.h"
#include "../d/cangbaolin/CangBaoLin_zenglioutai.h"


CRoom * Load_CangBao(string room_name)
{
	CRoom * r = NULL;

	// ≤ÿ±¶¡Î
	if(room_name == "√Œ‘Û…Ω…ΩΩ≈")
		r = new CRCangBao_mzshanjiao();
	else if(room_name == "√Œ‘Û…Ω‘˘¡¯Ã®")
		r = new CRCangBao_zenglioutai();
	else if(room_name == "√Œ‘Û…Ω“¡»ÀÀÆ∏Û")
		r = new CRCangBao_yirenge();
	else if(room_name == "√Œ‘Û…Ω“‰√∑π»")
		r = new CRCangBao_yimeigu();
	else if(room_name == "√Œ‘Û…Ω—˛≥ÿ")
		r = new CRCangBao_yaoci();
	else if(room_name == "√Œ‘Û…Ωœ¶—Ù¬•")
		r = new CRCangBao_xiyanglou();
	else if(room_name == "√Œ‘Û…Ωœ‡ÀºÕ§")
		r = new CRCangBao_xiangsiting();
	else if(room_name == "√Œ‘Û…ΩœÊÂ˙¡÷")
		r = new CRCangBao_xiangfeilin();
	else if(room_name == "√Œ‘Û…ΩŒ¢”Í∑Â")
		r = new CRCangBao_weiyufeng();
	else if(room_name == "√Œ‘Û…ΩÕ«")
		r = new CRCangBao_wanqiou();
	else if(room_name == "√Œ‘Û…ΩÕÌ«Áπ»")
		r = new CRCangBao_wanqinggu();
	else if(room_name == "√Œ‘Û…ΩÕÚ≥Óπ»")
		r = new CRCangBao_wanchougu();
	else if(room_name == "√Œ‘Û…ΩÀ∂ Û∂¥")
		r = new CRCangBao_shuosudong();
	else if(room_name == "√Œ‘Û…Ω÷˜∑Â")
		r = new CRCangBao_mzszhufeng();
	else if(room_name == "√Œ‘Û…Ω¡˙≥ÿ")
		r = new CRCangBao_longchi();
	else if(room_name == "√Œ‘Û…Ω¡˜›∫–°µ¿")
		r = new CRCangBao_liouyinxiaodao();
	else if(room_name == "√Œ‘Û…ΩΩı…™∂¥")
		r = new CRCangBao_jinsedong();
	else if(room_name == "√Œ‘Û…Ω›Û›Á¡Î")
		r = new CRCangBao_jianxialin();
	else if(room_name == "√Œ‘Û…Ω‰Ω…¥π»")
		r = new CRCangBao_huanshagu();
	else if(room_name == "√Œ‘Û…Ω∫‚√≈")
		r = new CRCangBao_hengmen();
	else if(room_name == "√Œ‘Û…Ω∑Á‘¬∂¥")
		r = new CRCangBao_fengyuedong();
	else if(room_name == "√Œ‘Û…Ω›‡¬Ã–°µ¿")
		r = new CRCangBao_elvxiaodao();
	else if(room_name == "√Œ‘Û…Ω∂≈¿ºπ»")
		r = new CRCangBao_dulangu();		
	else if(room_name == "√Œ‘Û…Ω∂´√≈÷Æ≥ÿ")
		r = new CRCangBao_dongmenchi();
	else if(room_name == "√Œ‘Û…Ω≥Ô± Ê‰")
		r = new CRCangBao_choubiyi();	
	return r;
}





