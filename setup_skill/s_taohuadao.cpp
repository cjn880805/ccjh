#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"
#include "../std/FightRoom.h"
#include "../server/Room.h"

//Ã“ª®µ∫ taohuadao
#include "../daemons/skill/high_skill/taohuadao/anying_fuxiang.h"
#include "../daemons/skill/high_skill/taohuadao/bibo_shengong.h"
#include "../daemons/skill/high_skill/taohuadao/count.h"
#include "../daemons/skill/high_skill/taohuadao/lanhua_shou.h"
#include "../daemons/skill/high_skill/taohuadao/luoying_shenjian.h"
#include "../daemons/skill/high_skill/taohuadao/luoying_shenzhang.h"
//#include "../daemons/skill/high_skill/taohuadao/luoying_xinfa.h"
#include "../daemons/skill/high_skill/taohuadao/qimen_wuxing.h"
#include "../daemons/skill/high_skill/taohuadao/tanzhi_shentong.h"
#include "../daemons/skill/high_skill/taohuadao/xuanfeng_leg.h"
#include "../daemons/skill/high_skill/taohuadao/yuxiao_jianfa.h"

CSkill * LoadSkill_taohuadao(string skill_name)
{
	CSkill * skill = NULL;

	// Ã“ª®µ∫
	if(skill_name == "anying_fuxiang")			//∞µ”∞∏°œ„ lanwood 2000-12-29
		skill = new CSanying_fuxiang();
	else if(skill_name == "bibo_shengong")
		skill = new CSbibo_shengong();
	else if(skill_name == "count")
		skill = new CScount();
	else if(skill_name == "lanhua_shou")
		skill = new CSlanhua_shou();
	else if(skill_name == "luoying_shenjian")
		skill = new CSluoying_shenjian();
	else if(skill_name == "luoying_shenzhang")
		skill = new CSluoying_shenzhang();
//	else if(skill_name == "luoying_xinfa")
//		skill = new CSluoying_xinfa();
	else if(skill_name == "qimen_wuxing")
		skill = new CSqimen_wuxing();
	else if(skill_name == "tanzhi_shentong")
		skill = new CStanzhi_shentong();
	else if(skill_name == "xuanfeng_leg")
		skill = new CSxuanfeng_leg();
	else if(skill_name == "yuxiao_jianfa")
		skill = new CSyuxiao_jianfa();

	return skill;
}