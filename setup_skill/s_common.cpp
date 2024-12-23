#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"
#include "../server/Item.h"
#include "../std/FightRoom.h"
#include "../server/Npc.h"


// 基本技能 base_skill
#include "../daemons/skill/base_skill/axe.h"
#include "../daemons/skill/base_skill/begging.h"
#include "../daemons/skill/base_skill/sword.h"
#include "../daemons/skill/base_skill/blade.h"
#include "../daemons/skill/base_skill/dodge.h"
#include "../daemons/skill/base_skill/hammer.h"
#include "../daemons/skill/base_skill/parry.h"
//#include "../daemons/skill/base_skill/qiang.h"
#include "../daemons/skill/base_skill/staff.h"
//#include "../daemons/skill/base_skill/stick.h"
#include "../daemons/skill/base_skill/throwing.h"
#include "../daemons/skill/base_skill/stealing.h"
#include "../daemons/skill/base_skill/unarmed.h"
#include "../daemons/skill/base_skill/whip.h"
#include "../daemons/skill/base_skill/claw.h"
#include "../daemons/skill/base_skill/club.h"
#include "../daemons/skill/base_skill/cuff.h"
#include "../daemons/skill/base_skill/dagger.h"
#include "../daemons/skill/base_skill/finger.h"
#include "../daemons/skill/base_skill/hand.h"
#include "../daemons/skill/base_skill/strike.h"
#include "../daemons/skill/base_skill/array.h"
#include "../daemons/skill/base_skill/literate.h"
#include "../daemons/skill/base_skill/taoism.h"
#include "../daemons/skill/base_skill/buddhism.h"
#include "../daemons/skill/base_skill/leg.h"
#include "../daemons/skill/base_skill/lingfa.h"
#include "../daemons/skill/base_skill/music.h"
#include "../daemons/skill/base_skill/xunshou_shu.h"
	

CSkill * LoadSkill_common(string skill_name)
{
	CSkill * skill = NULL;

	// 基本技能 base_skill
	if(skill_name == "sword")
		skill = new CSSword();
	else if(skill_name == "force")
		skill = new CForce();
	else if(skill_name == "begging")		//乞讨之术 lanwood 2000-12-30
		skill = new CSbegging();
	else if(skill_name == "blade")
		skill = new CSBlade();
	else if(skill_name == "dodge")
		skill = new CSDodge();
	else if(skill_name == "hammer")
		skill = new CSHammer();
	else if(skill_name == "parry")
		skill = new CSParry();
	else if(skill_name == "staff")
		skill = new CSStaff();
//	else if(skill_name == "stick")
//		skill = new CSStick();
	else if(skill_name == "throwing")
		skill = new CSThrowing();
	else if(skill_name == "unarmed")
		skill = new CSUnarmed();
	else if(skill_name == "whip")
		skill = new CSWhip();
	else if(skill_name == "claw")
		skill = new CSclaw();
	else if(skill_name == "club")
		skill = new CSclub();
	else if(skill_name == "cuff")
		skill = new CScuff();
	else if(skill_name == "dagger")
		skill = new CSdagger();
	else if(skill_name == "finger")
		skill = new CSfinger();
	else if(skill_name == "hand")
		skill = new CShand();
	else if(skill_name == "strike")
		skill = new CSstrike();
	else if(skill_name == "stealing")
		skill = new CSstealing();
	else if(skill_name == "array")
		skill = new CSarray();
	else if(skill_name == "axe" )
		skill = new CSaxe();
	else if(skill_name == "literate")
		skill = new CSliterate();
	else if(skill_name == "taoism")
		skill = new CStaoism();
	else if(skill_name == "buddhism")
		skill = new CSbuddhism();
	else if(skill_name == "leg")
		skill = new CSleg();
	else if(skill_name == "lingfa")
		skill = new CSlingfa();
	else if(skill_name == "music")
		skill = new CSmusic();
	//新增技能：灵蛇心法 2001-05-04
	else if(skill_name == "xunshou_shu")
		skill = new CSxunshou_shu();

	return skill;
}