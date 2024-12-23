#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"
#include "../server/Room.h"
#include "../std/FightRoom.h"
#include "../server/User.h"

//Î×Ê¦³öÆ·
#include "../daemons/skill/high_skill/special/wiz/xuanwu_douqi.h"
#include "../daemons/skill/high_skill/special/wiz/xiaoaojianghu.h"
#include "../daemons/skill/high_skill/special/wiz/wuwen_zhua.h"
#include "../daemons/skill/high_skill/special/wiz/viviensword.h"
#include "../daemons/skill/high_skill/special/wiz/vivien_sword.h"
#include "../daemons/skill/high_skill/special/wiz/tangshoudao.h"
#include "../daemons/skill/high_skill/special/wiz/shenzhao_gong.h"
//#include "../daemons/skill/high_skill/special/wiz/mtg.h"
#include "../daemons/skill/high_skill/special/wiz/misssword.h"
#include "../daemons/skill/high_skill/special/wiz/missblade.h"
#include "../daemons/skill/high_skill/special/wiz/magic.h"
#include "../daemons/skill/high_skill/special/wiz/lovesword.h"
#include "../daemons/skill/high_skill/special/wiz/lovestrike.h"
#include "../daemons/skill/high_skill/special/wiz/lovesteps.h"
#include "../daemons/skill/high_skill/special/wiz/loveblade.h"
#include "../daemons/skill/high_skill/special/wiz/ice_sword.h"
#include "../daemons/skill/high_skill/special/wiz/frost_blade.h"
#include "../daemons/skill/high_skill/special/wiz/doomsword.h"
#include "../daemons/skill/high_skill/special/wiz/dongyangdaofa.h"
#include "../daemons/skill/high_skill/special/wiz/doggiesword.h"
#include "../daemons/skill/high_skill/special/wiz/doggiestrike.h"
#include "../daemons/skill/high_skill/special/wiz/doggiesteps.h"
#include "../daemons/skill/high_skill/special/wiz/doggieblade.h"

#include "../daemons/skill/high_skill/special/wiz/zhanjiang_jue.h"
#include "../daemons/skill/high_skill/special/wiz/fengyu_wuqingzhi.h"
//#include "../daemons/skill/high_skill/special/wiz/jieyubian.h"

#include "../daemons/skill/high_skill/special/wiz/chanhe_zhi.h"
#include "../daemons/skill/high_skill/special/wiz/murong_sword.h"
#include "../daemons/skill/high_skill/special/wiz/kill_hammer.h"
#include "../daemons/skill/high_skill/special/wiz/kao.h"

CSkill * LoadSkill_wiz(string skill_name)
{
	CSkill * skill = NULL;


	if(skill_name == "magic")
		skill = new CSmagic();
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
	else if(skill_name == "vivien_sword")
		skill = new CSvivien_sword();

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
	else if(skill_name == "zhanjiang_jue")
		skill = new CSzhanjiang_jue();

	else if(skill_name == "fengyu_wuqingzhi")
		skill = new CSfengyu_wuqingzhi();
//	else if(skill_name == "jieyu_bian")
//		skill = new CSjieyu_bian();


	else if(skill_name == "chanhe_zhi")
		skill = new CSchanhe_zhi();
	else if(skill_name == "murong_sword")
		skill = new CSmurong_sword();
	else if(skill_name == "kill_hammer")
		skill = new CSkill_hammer();
	else if(skill_name == "kao")
		skill = new CSkao();

	return skill;
}



