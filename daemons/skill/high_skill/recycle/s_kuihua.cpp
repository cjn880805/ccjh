#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"

//¿û»¨
#include "../daemons/skill/high_skill/wiz/kuihua/kuihua_xinfa.h" 
#include "../daemons/skill/high_skill/wiz/kuihua/pixie_jian.h" 
#include "../daemons/skill/high_skill/wiz/kuihua/pixie_sword.h" 

CSkill * LoadSkill_kuihua(string skill_name)
{
	CSkill * skill = NULL;
	
	if(skill_name == "kuihua_xinfa")
		skill = new CSkuihua_xinfa();
	else if(skill_name == "pixie_jian")
		skill = new CSpixie_jian();
	else if(skill_name == "pixie_sword")
		skill = new CSpixie_sword();

	return skill;
}