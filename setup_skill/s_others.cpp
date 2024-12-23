#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"
#include "../server/Room.h"
#include "../server/Item.h"

//乱七八糟

// 高级技能 high_skill
#include "../daemons/skill/high_skill/special/others/wuhuduanmendao.h"
#include "../daemons/skill/high_skill/special/others/zhongpingqiang.h"
#include "../daemons/skill/high_skill/special/others/changquan.h"
#include "../daemons/skill/high_skill/special/others/duanyun_fu.h"
#include "../daemons/skill/high_skill/special/others/shenxing_baibian.h"

//四岳剑派
#include "../daemons/skill/high_skill/special/others/hengshan_jian.h"
#include "../daemons/skill/high_skill/special/others/hengshan_sword.h"
#include "../daemons/skill/high_skill/special/others/songshan_sword.h"
#include "../daemons/skill/high_skill/special/others/taishan_sword.h"

#include "../daemons/skill/high_skill/special/others/lingxu_bu.h"
#include "../daemons/skill/high_skill/special/others/jinwu_daofa.h"
#include "../daemons/skill/high_skill/special/others/kuangfeng_blade.h"
#include "../daemons/skill/high_skill/special/others/juemen_gun.h"
#include "../daemons/skill/high_skill/special/others/hanxing_bada.h"
#include "../daemons/skill/high_skill/special/others/hujia_daofa.h"

#include "../daemons/skill/high_skill/special/others/guimei_shenfa.h"
#include "../daemons/skill/high_skill/special/others/wudu_bian.h"
#include "../daemons/skill/high_skill/special/others/wudu_shengong.h"
#include "../daemons/skill/high_skill/special/others/wudu_xinfa.h"
#include "../daemons/skill/high_skill/special/others/wudu_zhang.h"

//NPC专用技能
#include "../daemons/skill/high_skill/special/npc/celestrike.h" //虎掌
#include "../daemons/skill/high_skill/special/npc/tiexue_steps.h" //铁血十二势
#include "../daemons/skill/high_skill/special/npc/huanhua_bu.h" //浣花步法
#include "../daemons/skill/high_skill/special/npc/fengyu_bu.h" //风雨飘香步
#include "../daemons/skill/high_skill/special/npc/feixian_bu.h" //飞仙步法
#include "../daemons/skill/high_skill/special/npc/duanhun_qiang.h" //断魂枪法
#include "../daemons/skill/high_skill/special/npc/shengji_blade.h" //神机刀法

CSkill * LoadSkill_others(string skill_name)
{
	CSkill * skill = NULL;

	// 高级技能 high_skill
	
	if(skill_name == "wuhuduanmendao")
		skill = new CSWuHuDuanMenDao();
	else if(skill_name == "zhongpingqiang")
		skill = new CSZhongPingQiang();
	else if(skill_name == "changquan")
		skill = new CSChangQuan();
	else if(skill_name == "duanyun_fu")
		skill = new CSduanyun_fu();
	else if(skill_name == "shenxing_baibian")
		skill = new CSshenxing_baibian();

	else if(skill_name == "hengshan_jian")
		skill = new CShengshan_jian();
	else if(skill_name == "hengshan_sword")
		skill = new CShengshan_sword();
	else if(skill_name == "hanxing_bada")
		skill = new CShanxing_bada();
	else if(skill_name == "hujia_daofa")
		skill = new CShujia_daofa();
	else if(skill_name == "jinwu_daofa")
		skill = new CSjinwu_daofa();
	else if(skill_name == "kuangfeng_blade")
		skill = new CSkuangfeng_blade();
	else if(skill_name == "juemen_gun")
		skill = new CSjuemen_gun();
	else if(skill_name == "songshan_sword")
		skill = new CSsongshan_sword();
	else if(skill_name == "taishan_sword")
		skill = new CStaishan_sword();
	else if(skill_name == "lingxu_bu")
		skill = new CSlingxu_bu();

	else if(skill_name == "guimei_shenfa")
		skill = new CSguimei_shenfa();
	else if(skill_name == "wudu_bian")
		skill = new CSwudu_bian();
	else if(skill_name == "wudu_shengong")
		skill = new CSwudu_shengong();
	else if(skill_name == "wudu_xinfa")
		skill = new CSwudu_xinfa();
	else if(skill_name == "wudu_zhang")
		skill = new CSwudu_zhang();

	else if(skill_name == "celestrike")
		skill = new CScelestrike();
	else if(skill_name == "tiexue_steps")
		skill = new CStiexue_steps();
	else if(skill_name == "huanhua_bu")
		skill = new CShuanhua_bu();
	else if(skill_name == "fengyu_bu")
		skill = new CSfengyu_bu();
	else if(skill_name == "feixian_bu")
		skill = new CSfeixian_bu();
	else if(skill_name == "duanhun_qiang")
		skill = new CSduanhun_qiang();
	else if(skill_name == "shengji_blade")
		skill = new CSshengji_blade();
	
	return skill;
}