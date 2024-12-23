#include "stdafx.h"
#include "../server/Room.h"
#include "../std/FightRoom.h"
#include "../std/xiaoyao.h"

//åĞÒ£ÁÖ
#include "../d/xiaoyao/xiaoyaocity.h"
#include "../d/xiaoyao/xiaoyao_datiewu.h"
#include "../d/xiaoyao/xiaoyao_gongjiang.h"
#include "../d/xiaoyao/xiaoyao_jiujia.h"
#include "../d/xiaoyao/xiaoyao_muwu.h"
#include "../d/xiaoyao/xiaoyao_shiwu.h"
#include "../d/xiaoyao/xiaoyao_xiaomuwu.h"
#include "../d/xiaoyao/xiaoyao_xiaowu.h"
#include "../d/xiaoyao/xiaoyao_shulin.h"
#include "../d/xiaoyao/xiaoyao_xiaodao1.h"
#include "../d/xiaoyao/xiaoyao_xiaodao2.h"
#include "../d/xiaoyao/xiaoyao_xiaodao3.h"

//åĞÒ£¹È
#include "../d/xiaoyaogu/xiaoyaogucity.h"
#include "../d/xiaoyaogu/xiaoyao_baihu.h"
#include "../d/xiaoyaogu/xiaoyao_damen.h"
#include "../d/xiaoyaogu/xiaoyao_feiling.h"
#include "../d/xiaoyaogu/xiaoyao_huaiyueting.h"
#include "../d/xiaoyaogu/xiaoyao_jinsiting.h"
#include "../d/xiaoyaogu/xiaoyao_jinyuehu.h"
#include "../d/xiaoyaogu/xiaoyao_kongdi.h"
#include "../d/xiaoyaogu/xiaoyao_liangongchang.h"
#include "../d/xiaoyaogu/xiaoyao_liangongshi.h"
#include "../d/xiaoyaogu/xiaoyao_lianwuchang.h"
#include "../d/xiaoyaogu/xiaoyao_muwu.h"
#include "../d/xiaoyaogu/xiaoyao_pubu.h"
#include "../d/xiaoyaogu/xiaoyao_qinglong.h"
#include "../d/xiaoyaogu/xiaoyao_shanding.h"
#include "../d/xiaoyaogu/xiaoyao_shanjiao.h"
#include "../d/xiaoyaogu/xiaoyao_shanlu1.h"
#include "../d/xiaoyaogu/xiaoyao_shanlu2.h"
#include "../d/xiaoyaogu/xiaoyao_shanlu3.h"
#include "../d/xiaoyaogu/xiaoyao_shanlu4.h"
#include "../d/xiaoyaogu/xiaoyao_shanlu5.h"
#include "../d/xiaoyaogu/xiaoyao_shanyao.h"
#include "../d/xiaoyaogu/xiaoyao_shiwu.h"
#include "../d/xiaoyaogu/xiaoyao_xiaojin.h"
#include "../d/xiaoyaogu/xiaoyao_xiaolu1.h"
#include "../d/xiaoyaogu/xiaoyao_xiaolu2.h"
#include "../d/xiaoyaogu/xiaoyao_xiaolu3.h"
#include "../d/xiaoyaogu/xiaoyao_xiaolu4.h"
#include "../d/xiaoyaogu/xiaoyao_xiaowu.h"
#include "../d/xiaoyaogu/xiaoyao_xiaoxibian.h"
#include "../d/xiaoyaogu/xiaoyao_xiaoyuan.h"
#include "../d/xiaoyaogu/xiaoyao_xuanwu.h"
#include "../d/xiaoyaogu/xiaoyao_yuanwai.h"
#include "../d/xiaoyaogu/xiaoyao_zuque.h"

#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu11.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu12.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu13.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu14.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu15.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu16.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu17.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu21.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu22.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu23.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu24.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu25.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu26.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu31.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu32.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu33.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu34.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu35.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu41.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu42.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu43.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu44.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu51.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu52.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu53.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu61.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu62.h"
#include "../d/xiaoyaogu/xuanwu/xiaoyao_xuanwu71.h"

#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong11.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong12.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong13.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong14.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong15.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong16.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong17.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong21.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong22.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong23.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong24.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong25.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong26.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong31.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong32.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong33.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong34.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong35.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong41.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong42.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong43.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong44.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong51.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong52.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong53.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong61.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong62.h"
#include "../d/xiaoyaogu/qinglong/xiaoyao_qinglong71.h"

#include "../d/xiaoyaogu/baihu/xiaoyao_baihu11.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu12.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu13.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu14.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu15.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu16.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu17.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu21.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu22.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu23.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu24.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu25.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu26.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu31.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu32.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu33.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu34.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu35.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu41.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu42.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu43.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu44.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu51.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu52.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu53.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu61.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu62.h"
#include "../d/xiaoyaogu/baihu/xiaoyao_baihu71.h"

#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque11.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque12.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque13.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque14.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque15.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque16.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque17.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque21.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque22.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque23.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque24.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque25.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque26.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque31.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque32.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque33.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque34.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque35.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque41.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque42.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque43.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque44.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque51.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque52.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque53.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque61.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque62.h"
#include "../d/xiaoyaogu/zhuque/xiaoyao_zhuque71.h"

#include "../d/xiaoyaogu/feiling/xiaoyao_feiling1.h"
#include "../d/xiaoyaogu/feiling/xiaoyao_feiling2.h"
#include "../d/xiaoyaogu/feiling/xiaoyao_feiling3.h"
#include "../d/xiaoyaogu/feiling/xiaoyao_feiling4.h"
#include "../d/xiaoyaogu/feiling/xiaoyao_feiling5.h"
#include "../d/xiaoyaogu/feiling/xiaoyao_feiling6.h"
#include "../d/xiaoyaogu/feiling/xiaoyao_feiling7.h"
#include "../d/xiaoyaogu/feiling/xiaoyao_feiling8.h"
#include "../d/xiaoyaogu/feiling/xiaoyao_feiling9.h"

#include "../d/xiaoyaogu/linglang/xiaoyao_dongmen.h"
#include "../d/xiaoyaogu/linglang/xiaoyao_fudi.h"
#include "../d/xiaoyaogu/linglang/xiaoyao_shishi1.h"
#include "../d/xiaoyaogu/linglang/xiaoyao_shishi2.h"
#include "../d/xiaoyaogu/linglang/xiaoyao_shishi3.h"
#include "../d/xiaoyaogu/linglang/xiaoyao_shishi4.h"

#include "../d/xiaoyaogu/jingzhuang/xiaoyao_biguanshi.h"
#include "../d/xiaoyaogu/jingzhuang/xiaoyao_jingzhuang1.h"
#include "../d/xiaoyaogu/jingzhuang/xiaoyao_jingzhuang2.h"
#include "../d/xiaoyaogu/jingzhuang/xiaoyao_jingzhuang3.h"
#include "../d/xiaoyaogu/jingzhuang/xiaoyao_jingzhuang4.h"
#include "../d/xiaoyaogu/jingzhuang/xiaoyao_jingzhuang5.h"
#include "../d/xiaoyaogu/jingzhuang/xiaoyao_jingzhuang6.h"
#include "../d/xiaoyaogu/jingzhuang/xiaoyao_jingzhuang7.h"

CRoom * Load_XiaoYao(string room_name)
{
	CRoom * r = NULL;

	//åĞÒ£ÁÖ
    if(room_name == "åĞÒ£ÁÖ")
		r = new CRXiaoYaocity();
    else if(room_name == "åĞÒ£ÁÖĞ¡Îİ")
		r = new CRXiaoYao_xiaowu();
    else if(room_name == "åĞÒ£ÁÖĞ¡Ä¾Îİ")
		r = new CRXiaoYao_xiaomuwu();
    else if(room_name == "åĞÒ£ÁÖ´òÌúÎİ")
		r = new CRXiaoYao_datiewu();
    else if(room_name == "åĞÒ£ÁÖÄ¾Îİ")
		r = new CRXiaoYao_muwu();
    else if(room_name == "åĞÒ£ÁÖ¾Æ¼Ò")
		r = new CRXiaoYao_jiujia();
    else if(room_name == "åĞÒ£ÁÖ¹¤½³Îİ")
		r = new CRXiaoYao_gongjiang();
    else if(room_name == "åĞÒ£ÁÖÊ¯Îİ")
		r = new CRXiaoYao_shiwu();
    else if(room_name == "åĞÒ£ÁÖÊ÷ÁÖ")
		r = new CRXiaoYao_shulin();	
	
    else if(room_name == "åĞÒ£ÁÖĞ¡µÀ1")
		r = new CRXiaoYao_xiaodao1();		
    else if(room_name == "åĞÒ£ÁÖĞ¡µÀ2")
		r = new CRXiaoYao_xiaodao2();		
    else if(room_name == "åĞÒ£ÁÖĞ¡µÀ3")
		r = new CRXiaoYao_xiaodao3();	
	
	//åĞÒ£¹È
    else if(room_name == "åĞÒ£¹È")
		r = new CRXiaoYao_city();
   else if(room_name == "åĞÒ£¹ÈĞ¡Ïª±ß")
		r = new CRXiaoYao_xiaoxibian();
	else if(room_name == "åĞÒ£¹ÈĞ¡¾¶")
		r = new CRXiaoYao_xiaojin();
	else if(room_name == "åĞÒ£¹ÈĞ¡Ôº")
		r = new CRXiaoYao_xiaoyuan();
	else if(room_name == "åĞÒ£¹ÈĞ¡Îİ")
		r = new CRXiaoYao_xiaowu1();
	else if(room_name == "åĞÒ£¹ÈÄ¾Îİ")
		r = new CRXiaoYao_muwu1();
	else if(room_name == "åĞÒ£¹ÈÁ·¹¦³¡")
		r = new CRXiaoYao_liangongchang();
	else if(room_name == "åĞÒ£¹ÈÁ·¹¦ÊÒ")
		r = new CRXiaoYao_liangongshi();
	else if(room_name == "åĞÒ£¹ÈÊ¯Îİ")
		r = new CRXiaoYao_shiwu1();
	else if(room_name == "åĞÒ£¹ÈÔºÍâ")
		r = new CRXiaoYao_yuanwai();
	else if(room_name == "åĞÒ£¹ÈĞ¡Â·1")
		r = new CRXiaoYao_xiaolu1();
	else if(room_name == "åĞÒ£¹ÈĞ¡Â·2")
		r = new CRXiaoYao_xiaolu2();
	else if(room_name == "åĞÒ£¹ÈĞ¡Â·3")
		r = new CRXiaoYao_xiaolu3();
	else if(room_name == "åĞÒ£¹ÈĞ¡Â·4")
		r = new CRXiaoYao_xiaolu4();
	else if(room_name == "åĞÒ£¹È×ÏÁ«·åÉ½Â·1")
		r = new CRXiaoYao_shanlu1();
	else if(room_name == "åĞÒ£¹È×ÏÁ«·åÉ½Â·2")
		r = new CRXiaoYao_shanlu2();
	else if(room_name == "åĞÒ£¹È×ÏÁ«·åÉ½Â·3")
		r = new CRXiaoYao_shanlu3();
	else if(room_name == "åĞÒ£¹È×ÏÁ«·åÉ½Â·4")
		r = new CRXiaoYao_shanlu4();
	else if(room_name == "åĞÒ£¹È×ÏÁ«·åÉ½Â·5")
		r = new CRXiaoYao_shanlu5();
	else if(room_name == "åĞÒ£¹È¿ÕµØ")
		r = new CRXiaoYao_kongdi();
	else if(room_name == "åĞÒ£¹È×·ÔÂ¹Û´óÃÅ")
		r = new CRXiaoYao_damen();
	else if(room_name == "åĞÒ£¹È×·ÔÂ¹Û»³ÔÂÍ¥")
		r = new CRXiaoYao_huaiyueting();
	else if(room_name == "åĞÒ£¹È×·ÔÂ¹Û¾²Ë¼Í¥")
		r = new CRXiaoYao_jinsiting();
	else if(room_name == "åĞÒ£¹È×·ÔÂ¹ÛÁ·Îä³¡")
		r = new CRXiaoYao_lianwuchang();
	else if(room_name == "åĞÒ£¹È×ÏÁ«·åÉ½½Å")
		r = new CRXiaoYao_shanjiao();
	else if(room_name == "åĞÒ£¹È×ÏÁ«·åÉ½Ñü")
		r = new CRXiaoYao_shanyao();
	else if(room_name == "åĞÒ£¹È×ÏÁ«·å·å¶¥")
		r = new CRXiaoYao_shanding();
	else if(room_name == "åĞÒ£¹È¾µÔÂºş")
		r = new CRXiaoYao_jinyuehu();
	else if(room_name == "åĞÒ£¹ÈÆÙ²¼")
		r = new CRXiaoYao_pubu();
	else if(room_name == "åĞÒ£¹È·ÉÁè¾ÅÏü¸óÕıÃÅ")
		r = new CRXiaoYao_feiling();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËş")
		r = new CRXiaoYao_qinglong();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËş")
		r = new CRXiaoYao_xuanwu();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸Ëş")
		r = new CRXiaoYao_zuque();
	else if(room_name == "åĞÒ£¹È°×»¢Ëş")
		r = new CRXiaoYao_baihu();

	else if(room_name == "åĞÒ£¹ÈĞşÎäËşËşµ×11")
		r = new CRXiaoYao_xuanwu11();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËşËşµ×12")
		r = new CRXiaoYao_xuanwu12();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËşËşµ×13")
		r = new CRXiaoYao_xuanwu13();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËşËşµ×14")
		r = new CRXiaoYao_xuanwu14();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËşËşµ×15")
		r = new CRXiaoYao_xuanwu15();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËşËşµ×16")
		r = new CRXiaoYao_xuanwu16();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËşËşµ×17")
		r = new CRXiaoYao_xuanwu17();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËş¶ş²ã21")
		r = new CRXiaoYao_xuanwu21();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËş¶ş²ã22")
		r = new CRXiaoYao_xuanwu22();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËş¶ş²ã23")
		r = new CRXiaoYao_xuanwu23();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËş¶ş²ã24")
		r = new CRXiaoYao_xuanwu24();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËş¶ş²ã25")
		r = new CRXiaoYao_xuanwu25();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËş¶ş²ã26")
		r = new CRXiaoYao_xuanwu26();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËşÈı²ã31")
		r = new CRXiaoYao_xuanwu31();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËşÈı²ã32")
		r = new CRXiaoYao_xuanwu32();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËşÈı²ã33")
		r = new CRXiaoYao_xuanwu33();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËşÈı²ã34")
		r = new CRXiaoYao_xuanwu34();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËşÈı²ã35")
		r = new CRXiaoYao_xuanwu35();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËşËÄ²ã41")
		r = new CRXiaoYao_xuanwu41();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËşËÄ²ã42")
		r = new CRXiaoYao_xuanwu42();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËşËÄ²ã43")
		r = new CRXiaoYao_xuanwu43();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËşËÄ²ã44")
		r = new CRXiaoYao_xuanwu44();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËşÎå²ã51")
		r = new CRXiaoYao_xuanwu51();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËşÎå²ã52")
		r = new CRXiaoYao_xuanwu52();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËşÎå²ã53")
		r = new CRXiaoYao_xuanwu53();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËşÁù²ã61")
		r = new CRXiaoYao_xuanwu61();
	else if(room_name == "åĞÒ£¹ÈĞşÎäËşÁù²ã62")
		r = new CRXiaoYao_xuanwu62();	
	else if(room_name == "åĞÒ£¹ÈĞşÎäËşËş¶¥71")
		r = new CRXiaoYao_xuanwu71();

	else if(room_name == "åĞÒ£¹ÈÇàÁúËşËşµ×11")
		r = new CRXiaoYao_qinglong11();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËşËşµ×12")
		r = new CRXiaoYao_qinglong12();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËşËşµ×13")
		r = new CRXiaoYao_qinglong13();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËşËşµ×14")
		r = new CRXiaoYao_qinglong14();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËşËşµ×15")
		r = new CRXiaoYao_qinglong15();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËşËşµ×16")
		r = new CRXiaoYao_qinglong16();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËşËşµ×17")
		r = new CRXiaoYao_qinglong17();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËş¶ş²ã21")
		r = new CRXiaoYao_qinglong21();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËş¶ş²ã22")
		r = new CRXiaoYao_qinglong22();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËş¶ş²ã23")
		r = new CRXiaoYao_qinglong23();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËş¶ş²ã24")
		r = new CRXiaoYao_qinglong24();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËş¶ş²ã25")
		r = new CRXiaoYao_qinglong25();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËş¶ş²ã26")
		r = new CRXiaoYao_qinglong26();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËşÈı²ã31")
		r = new CRXiaoYao_qinglong31();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËşÈı²ã32")
		r = new CRXiaoYao_qinglong32();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËşÈı²ã33")
		r = new CRXiaoYao_qinglong33();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËşÈı²ã34")
		r = new CRXiaoYao_qinglong34();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËşÈı²ã35")
		r = new CRXiaoYao_qinglong35();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËşËÄ²ã41")
		r = new CRXiaoYao_qinglong41();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËşËÄ²ã42")
		r = new CRXiaoYao_qinglong42();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËşËÄ²ã43")
		r = new CRXiaoYao_qinglong43();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËşËÄ²ã44")
		r = new CRXiaoYao_qinglong44();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËşÎå²ã51")
		r = new CRXiaoYao_qinglong51();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËşÎå²ã52")
		r = new CRXiaoYao_qinglong52();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËşÎå²ã53")
		r = new CRXiaoYao_qinglong53();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËşÁù²ã61")
		r = new CRXiaoYao_qinglong61();
	else if(room_name == "åĞÒ£¹ÈÇàÁúËşÁù²ã62")
		r = new CRXiaoYao_qinglong62();	
	else if(room_name == "åĞÒ£¹ÈÇàÁúËşËş¶¥71")
		r = new CRXiaoYao_qinglong71();

	else if(room_name == "åĞÒ£¹È°×»¢ËşËşµ×11")
		r = new CRXiaoYao_baihu11();
	else if(room_name == "åĞÒ£¹È°×»¢ËşËşµ×12")
		r = new CRXiaoYao_baihu12();
	else if(room_name == "åĞÒ£¹È°×»¢ËşËşµ×13")
		r = new CRXiaoYao_baihu13();
	else if(room_name == "åĞÒ£¹È°×»¢ËşËşµ×14")
		r = new CRXiaoYao_baihu14();
	else if(room_name == "åĞÒ£¹È°×»¢ËşËşµ×15")
		r = new CRXiaoYao_baihu15();
	else if(room_name == "åĞÒ£¹È°×»¢ËşËşµ×16")
		r = new CRXiaoYao_baihu16();
	else if(room_name == "åĞÒ£¹È°×»¢ËşËşµ×17")
		r = new CRXiaoYao_baihu17();
	else if(room_name == "åĞÒ£¹È°×»¢Ëş¶ş²ã21")
		r = new CRXiaoYao_baihu21();
	else if(room_name == "åĞÒ£¹È°×»¢Ëş¶ş²ã22")
		r = new CRXiaoYao_baihu22();
	else if(room_name == "åĞÒ£¹È°×»¢Ëş¶ş²ã23")
		r = new CRXiaoYao_baihu23();
	else if(room_name == "åĞÒ£¹È°×»¢Ëş¶ş²ã24")
		r = new CRXiaoYao_baihu24();
	else if(room_name == "åĞÒ£¹È°×»¢Ëş¶ş²ã25")
		r = new CRXiaoYao_baihu25();
	else if(room_name == "åĞÒ£¹È°×»¢Ëş¶ş²ã26")
		r = new CRXiaoYao_baihu26();
	else if(room_name == "åĞÒ£¹È°×»¢ËşÈı²ã31")
		r = new CRXiaoYao_baihu31();
	else if(room_name == "åĞÒ£¹È°×»¢ËşÈı²ã32")
		r = new CRXiaoYao_baihu32();
	else if(room_name == "åĞÒ£¹È°×»¢ËşÈı²ã33")
		r = new CRXiaoYao_baihu33();
	else if(room_name == "åĞÒ£¹È°×»¢ËşÈı²ã34")
		r = new CRXiaoYao_baihu34();
	else if(room_name == "åĞÒ£¹È°×»¢ËşÈı²ã35")
		r = new CRXiaoYao_baihu35();
	else if(room_name == "åĞÒ£¹È°×»¢ËşËÄ²ã41")
		r = new CRXiaoYao_baihu41();
	else if(room_name == "åĞÒ£¹È°×»¢ËşËÄ²ã42")
		r = new CRXiaoYao_baihu42();
	else if(room_name == "åĞÒ£¹È°×»¢ËşËÄ²ã43")
		r = new CRXiaoYao_baihu43();
	else if(room_name == "åĞÒ£¹È°×»¢ËşËÄ²ã44")
		r = new CRXiaoYao_baihu44();
	else if(room_name == "åĞÒ£¹È°×»¢ËşÎå²ã51")
		r = new CRXiaoYao_baihu51();
	else if(room_name == "åĞÒ£¹È°×»¢ËşÎå²ã52")
		r = new CRXiaoYao_baihu52();
	else if(room_name == "åĞÒ£¹È°×»¢ËşÎå²ã53")
		r = new CRXiaoYao_baihu53();
	else if(room_name == "åĞÒ£¹È°×»¢ËşÁù²ã61")
		r = new CRXiaoYao_baihu61();
	else if(room_name == "åĞÒ£¹È°×»¢ËşÁù²ã62")
		r = new CRXiaoYao_baihu62();	
	else if(room_name == "åĞÒ£¹È°×»¢ËşËş¶¥71")
		r = new CRXiaoYao_baihu71();

	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşËşµ×11")
		r = new CRXiaoYao_zhuque11();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşËşµ×12")
		r = new CRXiaoYao_zhuque12();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşËşµ×13")
		r = new CRXiaoYao_zhuque13();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşËşµ×14")
		r = new CRXiaoYao_zhuque14();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşËşµ×15")
		r = new CRXiaoYao_zhuque15();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşËşµ×16")
		r = new CRXiaoYao_zhuque16();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşËşµ×17")
		r = new CRXiaoYao_zhuque17();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸Ëş¶ş²ã21")
		r = new CRXiaoYao_zhuque21();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸Ëş¶ş²ã22")
		r = new CRXiaoYao_zhuque22();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸Ëş¶ş²ã23")
		r = new CRXiaoYao_zhuque23();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸Ëş¶ş²ã24")
		r = new CRXiaoYao_zhuque24();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸Ëş¶ş²ã25")
		r = new CRXiaoYao_zhuque25();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸Ëş¶ş²ã26")
		r = new CRXiaoYao_zhuque26();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşÈı²ã31")
		r = new CRXiaoYao_zhuque31();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşÈı²ã32")
		r = new CRXiaoYao_zhuque32();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşÈı²ã33")
		r = new CRXiaoYao_zhuque33();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşÈı²ã34")
		r = new CRXiaoYao_zhuque34();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşÈı²ã35")
		r = new CRXiaoYao_zhuque35();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşËÄ²ã41")
		r = new CRXiaoYao_zhuque41();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşËÄ²ã42")
		r = new CRXiaoYao_zhuque42();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşËÄ²ã43")
		r = new CRXiaoYao_zhuque43();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşËÄ²ã44")
		r = new CRXiaoYao_zhuque44();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşÎå²ã51")
		r = new CRXiaoYao_zhuque51();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşÎå²ã52")
		r = new CRXiaoYao_zhuque52();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşÎå²ã53")
		r = new CRXiaoYao_zhuque53();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşÁù²ã61")
		r = new CRXiaoYao_zhuque61();
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşÁù²ã62")
		r = new CRXiaoYao_zhuque62();	
	else if(room_name == "åĞÒ£¹ÈÖìÈ¸ËşËş¶¥71")
		r = new CRXiaoYao_zhuque71();

	else if(room_name == "åĞÒ£¹È·ÉÁèÖ®×ó¼çÊÒ")
		r = new CRXiaoYao_feiling1();
	else if(room_name == "åĞÒ£¹È·ÉÁèÖ®Ã±")
		r = new CRXiaoYao_feiling2();
	else if(room_name == "åĞÒ£¹È·ÉÁèÖ®ÓÒ¼çÊÒ")
		r = new CRXiaoYao_feiling3();
	else if(room_name == "åĞÒ£¹È·ÉÁèÖ®×ó±ÛÊÒ")
		r = new CRXiaoYao_feiling4();
	else if(room_name == "åĞÒ£¹È·ÉÁèÖ®ĞÄ")
		r = new CRXiaoYao_feiling5();
	else if(room_name == "åĞÒ£¹È·ÉÁèÖ®ÓÒ±ÛÊÒ")
		r = new CRXiaoYao_feiling6();
	else if(room_name == "åĞÒ£¹È·ÉÁèÖ®×ó×ãÊÒ")
		r = new CRXiaoYao_feiling7();
	else if(room_name == "åĞÒ£¹È·ÉÁèÖ®ÂÄ")
		r = new CRXiaoYao_feiling8();
	else if(room_name == "åĞÒ£¹È·ÉÁèÖ®ÓÒ×ãÊÒ")
		r = new CRXiaoYao_feiling9();

	else if(room_name == "åĞÒ£¹ÈÀÅß§¸£µØ¶´ÃÅ")
		r = new CRXiaoYao_dongmen();
	else if(room_name == "åĞÒ£¹ÈÀÅß§¸£µØ")
		r = new CRXiaoYao_fudi();
	else if(room_name == "åĞÒ£¹ÈÀÅß§¸£µØÊ¯ÊÒ1")
		r = new CRXiaoYao_shishi1();
	else if(room_name == "åĞÒ£¹ÈÀÅß§¸£µØÊ¯ÊÒ2")
		r = new CRXiaoYao_shishi2();
	else if(room_name == "åĞÒ£¹ÈÀÅß§¸£µØÊ¯ÊÒ3")
		r = new CRXiaoYao_shishi3();
	else if(room_name == "åĞÒ£¹ÈÀÅß§¸£µØÊ¯ÊÒ4")
		r = new CRXiaoYao_shishi4();

	else if(room_name == "åĞÒ£¹È±Õ¹ØÊÒ")
		r = new CRXiaoYao_biguanshi();
	else if(room_name == "åĞÒ£¹È´óÀí³Ç¾­´±1")
		r = new CRXiaoYao_jingzhuang1();
	else if(room_name == "åĞÒ£¹È´óÀí³Ç¾­´±2")
		r = new CRXiaoYao_jingzhuang2();
	else if(room_name == "åĞÒ£¹È´óÀí³Ç¾­´±3")
		r = new CRXiaoYao_jingzhuang3();
	else if(room_name == "åĞÒ£¹È´óÀí³Ç¾­´±4")
		r = new CRXiaoYao_jingzhuang4();
	else if(room_name == "åĞÒ£¹È´óÀí³Ç¾­´±5")
		r = new CRXiaoYao_jingzhuang5();
	else if(room_name == "åĞÒ£¹È´óÀí³Ç¾­´±6")
		r = new CRXiaoYao_jingzhuang6();
	else if(room_name == "åĞÒ£¹È´óÀí³Ç¾­´±7")
		r = new CRXiaoYao_jingzhuang7();

	return r;
}