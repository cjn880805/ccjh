#include "stdafx.h"
#include "../server/Room.h"
#include "../std/FightRoom.h"
#include "../std/Money.h"
#include "../std/Vendor.h"
#include "../std/BankOwner.h"
#include "../std/Corpse.h"
#include "../server/User.h"
#include "../server/Channel.h"
#include "../combat/Combatd.h"
#include "../std/resident.h"

#ifdef _SQL_
#include "../sql/sql.h"
#endif

#include "../npc/pub3/pub3_baby.h"
#include "../npc/pub3/pub3_chenlaoben.h"
#include "../npc/pub3/pub3_gongpingzi.h"
#include "../npc/pub3/pub3_gongpingziw.h"
#include "../npc/pub3/pub3_gulong.h"
#include "../npc/pub3/pub3_hongniang.h"
#include "../npc/pub3/pub3_huangyishizhe.h"
#include "../npc/pub3/pub3_liuruenfei.h"
#include "../npc/pub3/pub3_meipo.h"
#include "../npc/pub3/pub3_qianyankai.h"
#include "../npc/pub3/pub3_shangguanrexue.h"
#include "../npc/pub3/pub3_taoganxian.h"
#include "../npc/pub3/pub3_taogenxian.h"
#include "../npc/pub3/pub3_taohuatong.h"
#include "../npc/pub3/pub3_taohuaxian.h"
#include "../npc/pub3/pub3_taoshixian.h"
#include "../npc/pub3/pub3_taoyexian.h"
#include "../npc/pub3/pub3_taozhixian.h"
#include "../npc/pub3/pub3_xiejian.h"
#include "../npc/pub3/pub3_ximenwuqing.h"
#include "../npc/pub3/pub3_xunbu.h"

//“∞Õ‚ÀÊª˙π÷ŒÔ
#include "../npc/monster/monster.h"
#include "../npc/monster/monster_1.h"
#include "../npc/monster/monster_2.h"

#include "../npc/monster/rebooter.h"

#include "../npc/monster/zhangmen/zhangmen.h"
#include "../npc/monster/zhangmen/zm_btshan.h"
#include "../npc/monster/zhangmen/zm_dali.h"
#include "../npc/monster/zhangmen/zm_emei.h"
#include "../npc/monster/zhangmen/zm_gaibang.h"
#include "../npc/monster/zhangmen/zm_gumu.h"
#include "../npc/monster/zhangmen/zm_huashan.h"
#include "../npc/monster/zhangmen/zm_lingjiu.h"
#include "../npc/monster/zhangmen/zm_mingjiao.h"
#include "../npc/monster/zhangmen/zm_quanzhen.h"
#include "../npc/monster/zhangmen/zm_shaolin.h"
#include "../npc/monster/zhangmen/zm_shenlong.h"
#include "../npc/monster/zhangmen/zm_taohua.h"
#include "../npc/monster/zhangmen/zm_wudang.h"
#include "../npc/monster/zhangmen/zm_riyue.h"
#include "../npc/monster/zhangmen/zm_xiaoyao.h"
#include "../npc/monster/zhangmen/zm_xingxiu.h"
#include "../npc/monster/zhangmen/zm_xueshan.h"

#include "../npc/monster/taiwan_scavenger.h"
#include "../npc/monster/quanzhou/nanchen.h"
#include "../npc/monster/quanzhou/shuimm.h"
#include "../npc/monster/quanzhou/xmdog.h"
#include "../npc/monster/quanzhou/seller.h"
#include "../npc/monster/quanzhou/lse.h"

#include "../npc/monster/pub_scavenger.h"

#include "../npc/monster/huashan/monster_huashan.h"
#include "../npc/monster/huashan/mei.h"
#include "../npc/monster/huashan/qi.h"
#include "../npc/monster/huashan/wang.h"
#include "../npc/monster/huashan/yan.h"
#include "../npc/monster/searcher2.h"
#include "../npc/monster/yongrong.h"
#include "../npc/monster/baby.h"
#include "../npc/monster/yongren.h"
#include "../npc/monster/shizhe.h"

#include "../npc/monster/xitian/pub_tangseng.h"
#include "../npc/monster/xitian/pub_robber.h"
#include "../npc/monster/xitian/pub_wooden.h"

#include "../npc/monster/monster/monster_10k.h"
#include "../npc/monster/monster/monster_13k.h"
#include "../npc/monster/monster/monster_1632k.h"
#include "../npc/monster/monster/monster_16k.h"
#include "../npc/monster/monster/monster_20k.h"
#include "../npc/monster/monster/monster_24k.h"
#include "../npc/monster/monster/monster_28k.h"
#include "../npc/monster/monster/monster_3248k.h"
#include "../npc/monster/monster/monster_32k.h"
#include "../npc/monster/monster/monster_36k.h"
#include "../npc/monster/monster/monster_40k.h"
#include "../npc/monster/monster/monster_416k.h"
#include "../npc/monster/monster/monster_44k.h"
#include "../npc/monster/monster/monster_4k.h"
#include "../npc/monster/monster/monster_6k.h"
#include "../npc/monster/monster/monster_8k.h"

#include "../npc/wiz/animal_diablo2.h"
#include "../npc/wiz/yinling.h"
#include "../npc/wiz/pub_shamurai.h"
#include "../npc/wiz/wiz_guard.h"
#include "../npc/wiz/redpacket.h"
#include "../npc/wiz/wiz_youqin.h"
#include "../npc/wiz/wiz_limian.h"
#include "../npc/wiz/wiz_hanshueiyu.h"

#include "../npc/monster/red/monster.h"
#include "../npc/monster/red/xunbu.h"
#include "../npc/monster/red/newbie001.h"
#include "../npc/monster/red/gongpingzi.h"
#include "../npc/monster/red/shangshanshi.h"

#include "../npc/monster/red/fighter.h"
#include "../npc/monster/red/fighter1.h"
#include "../npc/monster/red/fighter2.h"
#include "../npc/monster/red/fighter3.h"
#include "../npc/monster/red/fighter4.h"
#include "../npc/monster/red/fighter5.h"

#include "../npc/monster/red/paihangbang.h"

//2002°¢2°¢6 «ÿ≤®–¬‘ˆ
#include "../npc/wiz/charge.h"
#include "../npc/wiz/wiz_newgift.h"

/*#include "../npc/wiz/wiz_teacher1.h"
#include "../npc/wiz/wiz_teacher2.h"
#include "../npc/wiz/wiz_teacher3.h"
*/
#include "../npc/wiz/wiz_teacher4.h"

#include "../npc/wiz/wiz_biaoche.h"
#include "../npc/wiz/wiz_mingjiaokill.h"
#include "../npc/monster/mf/mfnpc.h"
#include "../npc/monster/mf/mfnpc_1.h"
#include "../npc/monster/mf/mfnpc_2.h"
#include "../npc/monster/mf/mfnpc_3.h"
#include "../npc/monster/mf/mfnpc_4.h"
#include "../npc/monster/mf/mfnpc_5.h"
#include "../npc/monster/mf/mfnpc_6.h"
#include "../npc/monster/mf/mfnpc_7.h"
#include "../npc/monster/mf/mfnpc_8.h"
#include "../npc/monster/mf/mfnpc_9.h"
#include "../npc/monster/mf/mfnpc_10.h"
#include "../npc/monster/mf/mfnpc_11.h"
#include "../npc/monster/mf/mfnpc_12.h"
#include "../npc/monster/mf/mfnpc_13.h"
#include "../npc/monster/mf/mfnpc_14.h"
#include "../npc/monster/mf/mfnpc_15.h"
#include "../npc/monster/mf/pub_mengzeshizhe.h"
#include "../npc/wiz/wiz_yutou.h"
#include "../npc/monster/red/fighter_t.h"
#include "../npc/monster/randomnpc.h"
#include "../npc/wiz/wiz_skill.h"
#include "../npc/wiz/wiz_skill_1.h"
#include "../npc/monster/red/monster_anbiao.h"
#include "../npc/pub/pub_wokou1.h"
//#include "../npc/wiz/wiz_smash.h"
//#include "../npc/monster/red/fighter_lante.h"
#include "../npc/monster/red/fighter_zhuge.h"
//#include "../npc/wiz/corps_kill.h"
#include "../npc/wiz/wiz_buchangshi.h"

//∞Ô≈…NPC
//π¨
#include "../npc/d/corps/gong/xinyunhun.h"  //–«‘¬÷ÆªÍ
#include "../npc/d/corps/gong/qingxia.h"  //«Âœº
#include "../npc/d/corps/gong/xiaoyaosanren.h"  //Â–“£…¢»À

CNpc * LoadNPC_pub3(string npc_name)
{
	CNpc * t = 0;

	if(npc_name == "pub3_xunbu")
		t = new CNpub3_xunbu();
	else if(npc_name == "pub3_ximenwuqing")
		t = new CNpub3_ximenwuqing();
	else if(npc_name == "pub3_xiejian")
		t = new CNpub3_xiejian();
	else if(npc_name == "pub3_taozhixian")
		t = new CNpub3_taozhixian();
	else if(npc_name == "pub3_taoyexian")
		t = new CNpub3_taoyexian();
	else if(npc_name == "pub3_taoshixian")
		t = new CNpub3_taoshixian();
	else if(npc_name == "pub3_taohuaxian")
		t = new CNpub3_taohuaxian();
	else if(npc_name == "pub3_taohuatong")
		t = new CNpub3_taohuatong();
	else if(npc_name == "pub3_taogenxian")
		t = new CNpub3_taogenxian();
	else if(npc_name == "pub3_taoganxian")
		t = new CNpub3_taoganxian();
	else if(npc_name == "pub3_shangguanrexue")
		t = new CNpub3_shangguanrexue();
	else if(npc_name == "pub3_qianyankai")
		t = new CNpub3_qianyankai();
	else if(npc_name == "pub3_meipo")
		t = new CNpub3_meipo();
	else if(npc_name == "pub3_baby")
		t = new CNpub3_baby();
	else if(npc_name == "pub3_huangyishizhe")
		t = new CNpub3_huangyishizhe();
	else if(npc_name == "pub3_hongniang")
		t = new CNpub3_hongniang();
	else if(npc_name == "pub3_gulong")
		t = new CNpub3_gulong();
	else if(npc_name == "pub3_gongpingziw")
		t = new CNpub3_gongpingziw();
	else if(npc_name == "pub3_gongpingzi")
		t = new CNpub3_gongpingzi();
	else if(npc_name == "pub3_chenlaoben")
		t = new CNpub3_chenlaoben();
	else if(npc_name == "pub3_liuruenfei")
		t = new CNpub3_liuruenfei();

	else if(npc_name == "monster_1")
		t = new CNMonster_1();
	else if(npc_name == "monster_2")
		t = new CNMonster_2();

	else if(npc_name == "monster_rebooter")
		t = new CNmonster_rebooter();
	
	else if(npc_name == "zm_btshan")
		t = new CNzm_btshan();
	else if(npc_name == "zm_dali")
		t = new CNzm_dali();
	else if(npc_name == "zm_emei")
		t = new CNzm_emei();
	else if(npc_name == "zm_gaibang")
		t = new CNzm_gaibang();
	else if(npc_name == "zm_gumu")
		t = new CNzm_gumu();
	else if(npc_name == "zm_huashan")
		t = new CNzm_huashan();
	else if(npc_name == "zm_lingjiu")
		t = new CNzm_lingjiu();
	else if(npc_name == "zm_mingjiao")
		t = new CNzm_mingjiao();
	else if(npc_name == "zm_quanzhen")
		t = new CNzm_quanzhen();
	else if(npc_name == "zm_shaolin")
		t = new CNzm_shaolin();
	else if(npc_name == "zm_shenlong")
		t = new CNzm_shenlong();
	else if(npc_name == "zm_taohua")
		t = new CNzm_taohua();
	else if(npc_name == "zm_wudang")
		t = new CNzm_wudang();
	else if(npc_name == "zm_riyue")
		t = new CNzm_riyue();
	else if(npc_name == "zm_xiaoyao")
		t = new CNzm_xiaoyao();
	else if(npc_name == "zm_xingxiu")
		t = new CNzm_xingxiu();
	else if(npc_name == "zm_xueshan")
		t = new CNzm_xueshan();

	else if(npc_name == "taiwan_scavenger")
		t = new CNtaiwan_scavenger();
	else if(npc_name == "quanzhou_nanchen")
		t = new CNquanzhou_nanchen();
	else if(npc_name == "quanzhou_shuimm")
		t = new CNquanzhou_shuimm();
	else if(npc_name == "quanzhou_xmdog")
		t = new CNquanzhou_xmdog();
	else if(npc_name == "pub_robotseller")
		t = new CNpub_robotseller();
	else if(npc_name == "pub_scavenger")
		t = new CNpub_scavenger();
	else if(npc_name == "quanzhou_lse")
		t = new CNquanzhou_lse();

	else if(npc_name == "huashan_mei")
		t = new CNhuashan_mei();
	else if(npc_name == "huashan_qi")
		t = new CNhuashan_qi();
	else if(npc_name == "huashan_wang")
		t = new CNhuashan_wang();
	else if(npc_name == "huashan_yan")
		t = new CNhuashan_yan();
	else if(npc_name == "monster_searcher")
		t = new CNmonster_searcher2();
	else if(npc_name == "monster_yongrong")
		t = new CNmonster_yongrong();
	else if(npc_name == "monster_baby")
		t = new CNmonster_baby();
	else if(npc_name == "monster_yongren")
		t = new CNmonster_yongren();
	else if(npc_name == "monster_shizhe")
		t = new CNmonster_shizhe();

	else if(npc_name == "pub_tangseng")
		t = new CNpub_tangseng();
	else if(npc_name == "pub_robber")
		t = new CNpub_robber();
	else if(npc_name == "pub_wooden")
		t = new CNpub_wooden();

	//monster
	else if(npc_name == "monster_10k")
		t = new CNmonster_10k();
	else if(npc_name == "monster_13k")
		t = new CNmonster_13k();
	else if(npc_name == "monster_1632k")
		t = new CNmonster_1632k();
	else if(npc_name == "monster_16k")
		t = new CNmonster_16k();
	else if(npc_name == "monster_20k")
		t = new CNmonster_20k();
	else if(npc_name == "monster_24k")
		t = new CNmonster_24k();
	else if(npc_name == "monster_28k")
		t = new CNmonster_28k();
	else if(npc_name == "monster_3248k")
		t = new CNmonster_3248k();
	else if(npc_name == "monster_32k")
		t = new CNmonster_32k();
	else if(npc_name == "monster_36k")
		t = new CNmonster_36k();
	else if(npc_name == "monster_40k")
		t = new CNmonster_40k();
	else if(npc_name == "monster_416k")
		t = new CNmonster_416k();
	else if(npc_name == "monster_44k")
		t = new CNmonster_44k();
	else if(npc_name == "monster_4k")
		t = new CNmonster_4k();
	else if(npc_name == "monster_6k")
		t = new CNmonster_6k();
	else if(npc_name == "monster_8k")
		t = new CNmonster_8k();

	else if(npc_name == "pub_yinling")
		t = new CNpub_yinling();
	else if(npc_name == "animal_diablo2")
		t = new CNanimal_diablo2();	

	else if(npc_name == "monster_jieyu")
		t = new CNmonster_jieyu();
	else if(npc_name == "monster_xunbu")
		t = new CNmonster_xunbu();

	else if(npc_name == "pub_shamurai")
		t = new CNpub_shamurai();
	else if(npc_name == "wiz_newbie001")
		t = new CNwiz_newbie001();
	else if(npc_name == "wiz_guard")
		t = new CNwiz_guard();
	else if(npc_name == "wiz_gongpingzi")
		t = new CNwiz_gongpingzi();
	else if(npc_name == "wiz_shangshanshi")
		t = new CNwiz_shangshanshi();
	else if(npc_name == "wiz_fighter1")
		t = new CNwiz_fighter1();
	else if(npc_name == "wiz_fighter2")
		t = new CNwiz_fighter2();
	else if(npc_name == "wiz_fighter3")
		t = new CNwiz_fighter3();
	else if(npc_name == "wiz_fighter4")
		t = new CNwiz_fighter4();
	else if(npc_name == "wiz_fighter5")
		t = new CNwiz_fighter5();
	else if(npc_name == "wiz_paihangbang")
		t = new CNwiz_paihangbang();
	else if(npc_name == "wiz_redpacket")
		t = new CNwiz_redpacket();
	else if(npc_name == "wiz_youqin")
		t = new CNwiz_youqin();
	else if(npc_name == "wiz_limian")
		t = new CNwiz_limian();
	else if(npc_name == "wiz_hanshueiyu")
		t = new CNwiz_hanshueiyu();
	else if(npc_name == "wiz_newgift")
		t = new CNwiz_newgift();
/*	else if(npc_name == "wiz_teacher1")
		t = new CNwiz_teacher1();
	else if(npc_name == "wiz_teacher2")
		t = new CNwiz_teacher2();
	else if(npc_name == "wiz_teacher3")
		t = new CNwiz_teacher3();
*/	else if(npc_name == "wiz_teacher4")
		t = new CNwiz_teacher4();
	else if(npc_name == "wiz_biaoche")
		t = new CNwiz_biaoche();
	else if(npc_name == "wiz_mingjiaokill")
		t = new CNwiz_mingjiaokill();
	else if(npc_name == "mfnpc_1")
		t = new CNmfnpc_1();
	else if(npc_name == "mfnpc_2")
		t = new CNmfnpc_2();
	else if(npc_name == "mfnpc_3")
		t = new CNmfnpc_3();
	else if(npc_name == "mfnpc_4")
		t = new CNmfnpc_4();
	else if(npc_name == "mfnpc_5")
		t = new CNmfnpc_5();
	else if(npc_name == "mfnpc_6")
		t = new CNmfnpc_6();
	else if(npc_name == "mfnpc_7")
		t = new CNmfnpc_7();
	else if(npc_name == "mfnpc_8")
		t = new CNmfnpc_8();
	else if(npc_name == "mfnpc_9")
		t = new CNmfnpc_9();
	else if(npc_name == "mfnpc_10")
		t = new CNmfnpc_10();
	else if(npc_name == "mfnpc_11")
		t = new CNmfnpc_11();
	else if(npc_name == "mfnpc_12")
		t = new CNmfnpc_12();
	else if(npc_name == "mfnpc_13")
		t = new CNmfnpc_13();
	else if(npc_name == "mfnpc_14")
		t = new CNmfnpc_14();
	else if(npc_name == "mfnpc_15")
		t = new CNmfnpc_15();
	else if(npc_name == "pub_mengzeshizhe")
		t = new CNpub_mengzeshizhe();
	else if(npc_name == "wiz_yutou")
		t = new CNwiz_yutou();
	else if(npc_name == "fighter_t")
		t = new CNfighter_t();
	else if(npc_name == "wiz_charge")
		t = new CNwiz_charge();
	else if(npc_name == "randomnpc")
		t = new CNrandomnpc();
	else if(npc_name == "wiz_skill")
		t = new CNwiz_skill();
	else if(npc_name == "monster_anbiao")
		t = new CNmonster_anbiao();
	else if(npc_name == "pub_wokou1")
		t = new CNpub_wokou1();
//	else if(npc_name == "wiz_smash")
//		t = new CNwiz_smash();
	else if(npc_name == "wiz_skill_1")
		t = new CNwiz_skill_1();
//	else if(npc_name == "fighter_lante")
//		t = new CNfighter_lante();
	else if(npc_name == "fighter_zhuge")
		t = new CNfighter_zhuge();
//	else if(npc_name == "corps_kill")
//		t = new CNcorps_kill();
	else if(npc_name == "wiz_buchangshi")
		t = new CNwiz_buchangshi();

//∞Ô≈…NPC
//π¨
	else if(npc_name == "corps_xinyunhun")  //–«‘¬÷ÆªÍ
		t = new CNcorps_xinyunhun();
	else if(npc_name == "corps_qingxia")  //«Âœº
		t = new CNcorps_qingxia();
	else if(npc_name == "corps_xiaoyaosanren")  //Â–“£…¢»À
		t = new CNcorps_xiaoyaosanren();

	return t;
}

