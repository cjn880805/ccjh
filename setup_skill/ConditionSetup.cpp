//----------Conditions--------------------
#include "stdafx.h"
#include "../server/Room.h"
#include "../server/Condition.h"
#include "../std/npcmirror.h"

#include "../daemons/condition/CPoison.h"
#include "../daemons/condition/autosave.h"
#include "../daemons/condition/bandaged.h"
#include "../daemons/condition/bingpo_poison.h"
#include "../daemons/condition/bonze_drug.h"
#include "../daemons/condition/bonze_jail.h"
#include "../daemons/condition/drunk.h"
#include "../daemons/condition/f_condi.h"
#include "../daemons/condition/feng_poison.h"
#include "../daemons/condition/flower_poison.h"
#include "../daemons/condition/gvmt_jail.h"
#include "../daemons/condition/ice_poison.h"
#include "../daemons/condition/iceshock.h"
#include "../daemons/condition/ill_dongshang.h"
#include "../daemons/condition/ill_fashao.h"
#include "../daemons/condition/ill_kesou.h"
#include "../daemons/condition/ill_shanghan.h"
#include "../daemons/condition/ill_zhongshu.h"
#include "../daemons/condition/jing_curing.h"
#include "../daemons/condition/jy_poison.h"
#include "../daemons/condition/killer.h"
#include "../daemons/condition/linji_daxiao.h"
#include "../daemons/condition/linji_fengyun.h"
#include "../daemons/condition/linji_longhe.h"
#include "../daemons/condition/linji_tiandi.h"
#include "../daemons/condition/linji_zhixin.h"
#include "../daemons/condition/poison_sandu.h"
#include "../daemons/condition/prostitute.h"
#include "../daemons/condition/putizi_drug.h"
#include "../daemons/condition/rose_poison.h"
#include "../daemons/condition/sanxiao_poison.h"
#include "../daemons/condition/scorpion_poison.h"
#include "../daemons/condition/slumber_drug.h"
#include "../daemons/condition/snake_poison.h"
#include "../daemons/condition/ss_poison.h"
#include "../daemons/condition/vote_clear.h"
#include "../daemons/condition/vote_suspension.h"
#include "../daemons/condition/wudu_poison.h"
#include "../daemons/condition/wuduz_poison.h"
#include "../daemons/condition/xx_poison.h"
#include "../daemons/condition/yufeng_poison.h"
#include "../daemons/condition/zhua_poison.h"
#include "../daemons/condition/zm_poison.h"
#include "../daemons/condition/rainbow_poison.h"
#include "../daemons/condition/nantianzhu.h"
#include "../daemons/condition/wuwen_poison.h"
#include "../daemons/condition/dog_poison.h"
#include "../daemons/condition/wugong_poison.h"
#include "../daemons/condition/chanchu_poison.h"

#include "../daemons/condition/xunbu_catching.h"
#include "../daemons/condition/congtu.h"

#include "../daemons/condition/drunk1.h"
#include "../daemons/condition/fugu_poison.h"
#include "../daemons/condition/dsy_poison.h"


CCondition * Create_Condition(string base_name)
{
	CCondition * cnd = NULL;
	if(base_name == "poison")
		cnd = new CCPoison();
	else if(base_name == "autosave")
		cnd = new CCautosave();
	else if(base_name == "bandaged")
		cnd = new CCbandaged();
	else if(base_name == "bingpo_poison")
		cnd = new CCbingpo_poison();
	else if(base_name == "bonze_drug")
		cnd = new CCbonze_drug();
	else if(base_name == "bonze_jail")
		cnd = new CCbonze_jail();
	else if(base_name == "drunk")
		cnd = new CCdrunk();
	else if(base_name == "f_condi")
		cnd = new CCf_condi();
	else if(base_name == "feng_poison")
		cnd = new CCfeng_poison();
	else if(base_name == "flower_poison")
		cnd = new CCflower_poison();
	else if(base_name == "gvmt_jail")
		cnd = new CCgvmt_jail();
	else if(base_name == "ice_poison")
		cnd = new CCice_poison();
	else if(base_name == "iceshock")
		cnd = new CCiceshock();
	else if(base_name == "ill_dongshang")
		cnd = new CCill_dongshang();
	else if(base_name == "ill_fashao")
		cnd = new CCill_fashao();
	else if(base_name == "ill_kesou")
		cnd = new CCill_kesou();
	else if(base_name == "ill_shanghan")
		cnd = new CCill_shanghan();
	else if(base_name == "ill_zhongshu")
		cnd = new CCill_zhongshu();
	else if(base_name == "jing_curing")
		cnd = new CCjing_curing();
	else if(base_name == "jy_poison")
		cnd = new CCjy_poison();
	else if(base_name == "killer")
		cnd = new CCkiller();
	else if(base_name == "linji_daxiao")
		cnd = new CClinji_daxiao();
	else if(base_name == "linji_fengyun")
		cnd = new CClinji_fengyun();
	else if(base_name == "linji_longhe")
		cnd = new CClinji_longhe();
	else if(base_name == "linji_tiandi")
		cnd = new CClinji_tiandi();
	else if(base_name == "linji_zhixin")
		cnd = new CClinji_zhixin();
	else if(base_name == "poison_sandu")
		cnd = new CCpoison_sandu();
	else if(base_name == "prostitute")
		cnd = new CCprostitute();
	else if(base_name == "putizi_drug")
		cnd = new CCputizi_drug();
	else if(base_name == "rose_poison")
		cnd = new CCrose_poison();
	else if(base_name == "sanxiao_poison")
		cnd = new CCsanxiao_poison();
	else if(base_name == "scorpion_poison")
		cnd = new CCscorpion_poison();
	else if(base_name == "slumber_drug")
		cnd = new CCslumber_drug();
	else if(base_name == "snake_poison")
		cnd = new CCsnake_poison();
	else if(base_name == "ss_poison")
		cnd = new CCss_poison();
	else if(base_name == "vote_clear")
		cnd = new CCvote_clear();
	else if(base_name == "vote_suspension")
		cnd = new CCvote_suspension();
	else if(base_name == "wudu_poison")
		cnd = new CCwudu_poison();
	else if(base_name == "wuduz_poison")
		cnd = new CCwuduz_poison();
	else if(base_name == "xx_poison")
		cnd = new CCxx_poison();
	else if(base_name == "yufeng_poison")
		cnd = new CCyufeng_poison();
	else if(base_name == "zhua_poison")
		cnd = new CCzhua_poison();
	else if(base_name == "zm_poison")
		cnd = new CCzm_poison();
	else if(base_name == "rainbow_poison")
		cnd = new CCrainbow_poison();

	else if(base_name == "wc_poison")
		cnd = new CCnantianzhu();
	else if(base_name == "wuwen_poison")
		cnd = new CCwuwen_poison();
	else if(base_name == "wugong_poison")
		cnd = new CCwugong_poison();
	else if(base_name == "chanchu_poison")
		cnd = new CCchanchu_poison();

	else if(base_name == "xunbu_catching")
		cnd = new CCxunbu_catching();
	else if(base_name == "congtu")
		cnd = new CCcongtu();

	else if(base_name == "drunk1")
		cnd = new CCdrunk1();
	else if(base_name == "fugu_poison")
		cnd = new CCfugu_poison();
	else if(base_name == "dsy_poison")
		cnd = new CCdsy_poison();


// code by Fisho form here 
	if(!cnd)
	{
		output_error("Fail Condition:%s", base_name.c_str());
		cnd = new CCondition();

		string msg = "fc-";
		msg+= base_name;
		cnd->set_name(msg.c_str());
	}
// to here
	return cnd;
}

