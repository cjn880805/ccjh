#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"

//ÉñÁú shenlong
#include "../daemons/skill/high_skill/shenlong/huagu_mianzhang.h"
#include "../daemons/skill/high_skill/shenlong/shedao_qigong.h"
#include "../daemons/skill/high_skill/shenlong/shenlong_bashi.h"
#include "../daemons/skill/high_skill/shenlong/shenlong_xinfa.h"
#include "../daemons/skill/high_skill/shenlong/yixingbu.h"

CSkill * LoadSkill_shenlong(string skill_name)
{
	CSkill * skill = NULL;

	// ÉñÁú
	if(skill_name == "huagu_mianzhang")
		skill = new CShuagu_mianzhang();
	else if(skill_name == "shedao_qigong")
		skill = new CSshedao_qigong();
	else if(skill_name == "shenlong_bashi")
		skill = new CSshenlong_bashi();
	else if(skill_name == "shenlong_xinfa")
		skill = new CSshenlong_xinfa();
	else if(skill_name == "yixingbu")
		skill = new CSyixingbu();

	return skill;
}