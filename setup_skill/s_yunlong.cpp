#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"

//ÔÆÁú yunlong
#include "../daemons/skill/high_skill/yunlong/yunlong_bian.h"
#include "../daemons/skill/high_skill/yunlong/yunlong_jian.h"
#include "../daemons/skill/high_skill/yunlong/yunlong_shenfa.h"
#include "../daemons/skill/high_skill/yunlong/yunlong_shengong.h"
#include "../daemons/skill/high_skill/yunlong/yunlong_shou.h"
#include "../daemons/skill/high_skill/yunlong/yunlong_xinfa.h"
#include "../daemons/skill/high_skill/yunlong/yunlong_zhua.h"

CSkill * LoadSkill_yunlong(string skill_name)
{
	CSkill * skill = NULL;

	// ÔÆÁú
	if(skill_name == "yunlong_bian")
		skill = new CSyunlong_bian();
	else if(skill_name == "yunlong_jian")
		skill = new CSyunlong_jian();
	else if(skill_name == "yunlong_shenfa")
		skill = new CSyunlong_shenfa();
	else if(skill_name == "yunlong_shengong")
		skill = new CSyunlong_shengong();
	else if(skill_name == "yunlong_shou")
		skill = new CSyunlong_shou();
	else if(skill_name == "yunlong_xinfa")
		skill = new CSyunlong_xinfa();
	else if(skill_name == "yunlong_zhua")
		skill = new CSyunlong_zhua();

	return skill;
}