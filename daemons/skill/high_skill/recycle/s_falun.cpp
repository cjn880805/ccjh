#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"
#include "../server/Room.h"
#include "../std/FightRoom.h"
#include "../server/User.h"

//·¨ÂÖ falun
#include "../daemons/skill/high_skill/wiz/falun/falun_daofa.h"
#include "../daemons/skill/high_skill/wiz/falun/falun_gong.h"
#include "../daemons/skill/high_skill/wiz/falun/falun_step.h"
#include "../daemons/skill/high_skill/wiz/falun/falun_zhanfa.h"

#include "../daemons/skill/high_skill/wiz/mm/doomsword.h"
#include "../daemons/skill/high_skill/wiz/mm/shenzhao_gong.h"

#include "../daemons/skill/high_skill/wiz/mm/doggiesword.h"
#include "../daemons/skill/high_skill/wiz/mm/doggiesteps.h"
#include "../daemons/skill/high_skill/wiz/mm/doggieblade.h"
#include "../daemons/skill/high_skill/wiz/mm/doggiestrike.h"
#include "../daemons/skill/high_skill/wiz/mm/ice_sword.h"
#include "../daemons/skill/high_skill/wiz/mm/frost_blade.h"
//#include "../daemons/skill/high_skill/wiz/mm/mtg.h"
#include "../daemons/skill/high_skill/wiz/mm/viviensword.h"
#include "../daemons/skill/high_skill/wiz/mm/xuanwu_douqi.h"

#include "../daemons/skill/high_skill/wiz/dog/loveblade.h"
#include "../daemons/skill/high_skill/wiz/dog/lovesteps.h"
#include "../daemons/skill/high_skill/wiz/dog/lovestrike.h"
#include "../daemons/skill/high_skill/wiz/dog/lovesword.h"

#include "../daemons/skill/high_skill/wiz/dog/dongyangdaofa.h"
#include "../daemons/skill/high_skill/wiz/dog/tangshoudao.h"

#include "../daemons/skill/high_skill/wiz/dog/wuwen_zhua.h"

#include "../daemons/skill/high_skill/wiz/dog/missblade.h"
#include "../daemons/skill/high_skill/wiz/mm/misssword.h"

#include "../daemons/skill/high_skill/wiz/red/xiaoaojianghu.h"

CSkill * LoadSkill_falun(string skill_name)
{
	CSkill * skill = NULL;

	// falun
	if(skill_name == "falun_daofa")
		skill = new CSfalun_daofa();
	else if(skill_name == "falun_gong")
		skill = new CSfalun_gong();
	else if(skill_name == "falun_step")
		skill = new CSfalun_step();
	else if(skill_name == "falun_zhanfa")
		skill = new CSfalun_zhanfa();
	else if(skill_name == "doomsword")
		skill = new CSdoomsword();
	else if(skill_name == "shenzhao_gong")
		skill = new CSshenzhao_gong();

	else if(skill_name == "doggiesword")
		skill = new CSdoggiesword();
	else if(skill_name == "doggiestrike")
		skill = new CSdoggiestrike();
	else if(skill_name == "doggieblade")
		skill = new CSdoggieblade();
	else if(skill_name == "doggiesteps")
		skill = new CSdoggiesteps();
	else if(skill_name == "ice_sword")
		skill = new CSice_sword();
	else if(skill_name == "frost_blade")
		skill = new CSfrost_blade();
//	else if(skill_name == "mtg")
//		skill = new CSmtg();
	else if(skill_name == "viviensword")
		skill = new CSviviensword();

	else if(skill_name == "loveblade")
		skill = new CSloveblade();
	else if(skill_name == "lovesteps")
		skill = new CSlovesteps();
	else if(skill_name == "lovestrike")
		skill = new CSlovestrike();
	else if(skill_name == "lovesword")
		skill = new CSlovesword();
	else if(skill_name == "wuwen_zhua")
		skill = new CSwuwen_zhua();
	else if(skill_name == "missblade")
		skill = new CSmissblade();
	else if(skill_name == "misssword")
		skill = new CSmisssword();
	else if(skill_name == "xuanwu_douqi")
		skill = new CSxuanwu_douqi();

	else if(skill_name == "dongyangdaofa")
		skill = new CSdongyangdaofa();
	else if(skill_name == "tangshoudao")
		skill = new CStangshoudao();

	else if(skill_name == "xiaoaojianghu")
		skill = new CSxiaoaojianghu();
	
	return skill;
}