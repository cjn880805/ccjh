#include "stdafx.h"
#include "../server/Room.h"

//¶ëáÒ
#include "../d/emei/emei_bailongdong.h"
#include "../d/emei/emei_bgs.h"
#include "../d/emei/emei_bgsgate.h"
#include "../d/emei/emei_chunyangdian.h"
#include "../d/emei/emei_fhs.h"
#include "../d/emei/emei_fushouan.h"
#include "../d/emei/emei_guanyintang.h"
#include "../d/emei/emei_guiyunge.h"
#include "../d/emei/emei_heilong1.h"
#include "../d/emei/emei_huayanding.h"
#include "../d/emei/emei_jietuopo.h"
#include "../d/emei/emei_jldongkou.h"
#include "../d/emei/emei_jsjdg.h"
#include "../d/emei/emei_jsjdg2.h"
#include "../d/emei/emei_jsjdg3.h"
#include "../d/emei/emei_jsjdg4.h"
#include "../d/emei/emei_lianhuashi.h"
#include "../d/emei/emei_lingwenge.h"
#include "../d/emei/emei_milin1.h"
#include "../d/emei/emei_milin2.h"
#include "../d/emei/emei_qianfoan.h"
#include "../d/emei/emei_qingyinge.h"
#include "../d/emei/emei_qsjie2.h"
#include "../d/emei/emei_shenshuian.h"
#include "../d/emei/emei_shierpan1.h"
#include "../d/emei/emei_shierpan2.h"
#include "../d/emei/emei_shierpan3.h"
#include "../d/emei/emei_shierpan4.h"
#include "../d/emei/emei_wannianan.h"
#include "../d/emei/emei_xiaolu.h"
#include "../d/emei/emei_yunufeng.h"
#include "../d/emei/emei_zhongfengsi.h"
#include "../d/emei/emei.h"
#include "../d/emei/emei_bashisipan1.h"
#include "../d/emei/emei_bashisipan2.h"
#include "../d/emei/emei_bashisipan3.h"
#include "../d/emei/emei_duguangtai.h"
#include "../d/emei/emei_hcachanfang1.h"
#include "../d/emei/emei_hcadadian.h"
#include "../d/emei/emei_hcaeast.h"
#include "../d/emei/emei_hcaeast1.h"
#include "../d/emei/emei_hcaeast2.h"
#include "../d/emei/emei_hcaguangchang.h"
#include "../d/emei/emei_hcahoudian.h"
#include "../d/emei/emei_hcawest.h"
#include "../d/emei/emei_hcawest1.h"
#include "../d/emei/emei_hcawest2.h"
#include "../d/emei/emei_hcaxiuxishi.h"
#include "../d/emei/emei_hcazhaitang.h"
#include "../d/emei/emei_hcazhengdian.h"
#include "../d/emei/emei_huacangan.h"
#include "../d/emei/emei_jieyindian.h"
#include "../d/emei/emei_jinding.h"
#include "../d/emei/emei_leidongping.h"
#include "../d/emei/emei_lengsl1.h"
#include "../d/emei/emei_lengsl2.h"
#include "../d/emei/emei_lengsl3.h"
#include "../d/emei/emei_lengsl4.h"
#include "../d/emei/emei_lingyunti.h"
#include "../d/emei/emei_wanxingan.h"
#include "../d/emei/emei_woyunan.h"
#include "../d/emei/emei_xixiangchi.h"
#include "../d/emei/emei_ztpo1.h"
#include "../d/emei/emei_ztpo2.h"

CRoom * Load_EMei(string room_name)
{
	CRoom * r = NULL;

	//¶ëáÒ
	if(room_name == "¶ëáÒÖĞ·åËÂ")
		r = new CREMei_zhongfengsi();
	else if(room_name == "¶ëáÒÓñÅ®·å")
		r = new CREMei_yunufeng();
	else if(room_name == "¶ëáÒĞ¡Â·")
		r = new CREMei_xiaolu();
	else if(room_name == "¶ëáÒÍòÄêâÖ")
		r = new CREMei_wannianan();
	else if(room_name == "¶ëáÒÊ®¶şÅÌ4")
		r = new CREMei_shierpan4();
	else if(room_name == "¶ëáÒÊ®¶şÅÌ3")
		r = new CREMei_shierpan3();
	else if(room_name == "¶ëáÒÊ®¶şÅÌ2")
		r = new CREMei_shierpan2();
	else if(room_name == "¶ëáÒÊ®¶şÅÌ1")
		r = new CREMei_shierpan1();
	else if(room_name == "¶ëáÒÉñË®âÖ")
		r = new CREMei_shenshuian();
	else if(room_name == "¶ëáÒÇàÊ¯½×")
		r = new CREMei_qsjie2();
	else if(room_name == "¶ëáÒÇåÒô¸ó")
		r = new CREMei_qingyinge();
	else if(room_name == "¶ëáÒÇ§·ğâÖ")
		r = new CREMei_qianfoan();
	else if(room_name == "¶ëáÒÃÜÁÖ2")
		r = new CREMei_milin2();
	else if(room_name == "¶ëáÒÃÜÁÖ1")
		r = new CREMei_milin1();
	else if(room_name == "¶ëáÒÁéÎÄ¸ó")
		r = new CREMei_lingwenge();
	else if(room_name == "¶ëáÒÁ«»¨Ê¯")
		r = new CREMei_lianhuashi();
	else if(room_name == "¶ëáÒ¾ÅÊ®¾ÅµÀ¹Õ4")
		r = new CREMei_jsjdg4();
	else if(room_name == "¶ëáÒ¾ÅÊ®¾ÅµÀ¹Õ3")
		r = new CREMei_jsjdg3();
	else if(room_name == "¶ëáÒ¾ÅÊ®¾ÅµÀ¹Õ2")
		r = new CREMei_jsjdg2();
	else if(room_name == "¶ëáÒ¾ÅÊ®¾ÅµÀ¹Õ1")
		r = new CREMei_jsjdg();
	else if(room_name == "¶ëáÒ¾ÅÀÏ¶´¿Ú")
		r = new CREMei_jldongkou();
	else if(room_name == "¶ëáÒ½âÍÑÆÂ")
		r = new CREMei_jietuopo();
	else if(room_name == "¶ëáÒ»ªÑÏ¶¥")
		r = new CREMei_huayanding();
	else if(room_name == "¶ëáÒ¹éÔÆ¸ó")
		r = new CREMei_guiyunge();
	else if(room_name == "¶ëáÒ¹ÛÒôÌÃ")
		r = new CREMei_guanyintang();
	else if(room_name == "¶ëáÒ¸£ÊÙâÖ")
		r = new CREMei_fushouan();
	else if(room_name == "¶ëáÒ·ü»¢ËÂ")
		r = new CREMei_fhs();
	else if(room_name == "¶ëáÒ´¿Ñôµî")
		r = new CREMei_chunyangdian();
	else if(room_name == "¶ëáÒ±¨¹úËÂÉ½ÃÅ")
		r = new CREMei_bgsgate();
	else if(room_name == "¶ëáÒ±¨¹úËÂ")
		r = new CREMei_bgs();
	else if(room_name == "¶ëáÒ°×Áú¶´")
		r = new CREMei_bailongdong();
	else if(room_name == "¶ëáÒºÚÁú½­Õ»µÀ")
		r = new CREMei_heilong1();
	else if(room_name == "¶ëáÒ")
		r = new CREMei();
	else if(room_name == "¶ëáÒ×êÌìÆÂ2")
		r = new CREMei_ztpo2();
	else if(room_name == "¶ëáÒ×êÌìÆÂ1")
		r = new CREMei_ztpo1();
	else if(room_name == "¶ëáÒÏ´Ïó³Ø")
		r = new CREMei_xixiangchi();
	else if(room_name == "¶ëáÒÎÔÔÆâÖ")
		r = new CREMei_woyunan();
	else if(room_name == "¶ëáÒÍòĞĞâÖ")
		r = new CREMei_wanxingan();
	else if(room_name == "¶ëáÒÁèÔÆÌİ")
		r = new CREMei_lingyunti();
	else if(room_name == "¶ëáÒÀäÉ¼ÁÖ4")
		r = new CREMei_lengsl4();
	else if(room_name == "¶ëáÒÀäÉ¼ÁÖ3")
		r = new CREMei_lengsl3();
	else if(room_name == "¶ëáÒÀäÉ¼ÁÖ2")
		r = new CREMei_lengsl2();
	else if(room_name == "¶ëáÒÀäÉ¼ÁÖ1")
		r = new CREMei_lengsl1();
	else if(room_name == "¶ëáÒÀ×¶´Æº")
		r = new CREMei_leidongping();
	else if(room_name == "¶ëáÒ½ğ¶¥")
		r = new CREMei_jinding();
	else if(room_name == "¶ëáÒ½ÓÒıµî")
		r = new CREMei_jieyindian();
	else if(room_name == "¶ëáÒ»ª²ØâÖ")
		r = new CREMei_huacangan();
	else if(room_name == "¶ëáÒ»ª²ØâÖÕıµî")
		r = new CREMei_hcazhengdian();
	else if(room_name == "¶ëáÒ»ª²ØâÖÕ«ÌÃ")
		r = new CREMei_hcazhaitang();
	else if(room_name == "¶ëáÒ»ª²ØâÖĞİÏ¢ÊÒ")
		r = new CREMei_hcaxiuxishi();
	else if(room_name == "¶ëáÒ»ª²ØâÖÎ÷ÀÈ2")
		r = new CREMei_hcawest2();
	else if(room_name == "¶ëáÒ»ª²ØâÖÎ÷ÀÈ1")
		r = new CREMei_hcawest1();
	else if(room_name == "¶ëáÒ»ª²ØâÖÎ÷²àµî")
		r = new CREMei_hcawest();
	else if(room_name == "¶ëáÒ»ª²ØâÖºóµî")
		r = new CREMei_hcahoudian();
	else if(room_name == "¶ëáÒ»ª²ØâÖ¹ã³¡")
		r = new CREMei_hcaguangchang();
	else if(room_name == "¶ëáÒ»ª²ØâÖ¶«ÀÈ2")
		r = new CREMei_hcaeast2();
	else if(room_name == "¶ëáÒ»ª²ØâÖ¶«ÀÈ1")
		r = new CREMei_hcaeast1();
	else if(room_name == "¶ëáÒ»ª²ØâÖ¶«²àµî")
		r = new CREMei_hcaeast();
	else if(room_name == "¶ëáÒ»ª²ØâÖ´óĞÛ±¦µî")
		r = new CREMei_hcadadian();
	else if(room_name == "¶ëáÒ»ª²ØâÖìø·¿")
		r = new CREMei_hcachanfang();
	else if(room_name == "¶ëáÒ°ËÊ®ËÄÅÌ1")
		r = new CREMei_bashisipan1();
	else if(room_name == "¶ëáÒ°ËÊ®ËÄÅÌ3")
		r = new CREMei_bashisipan3();
	else if(room_name == "¶ëáÒ°ËÊ®ËÄÅÌ2")
		r = new CREMei_bashisipan2();
	else if(room_name == "¶ëáÒ¶Ã¹âÌ¨")
		r = new CREMei_duguangtai();

	return r;
}