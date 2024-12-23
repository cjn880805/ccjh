#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"

//murong Ä½ÈÝ
#include "../daemons/skill/high_skill/murong/canhe_zhi.h" 
#include "../daemons/skill/high_skill/murong/douzhuan_xingyi.h" 
#include "../daemons/skill/high_skill/murong/murong_daofa.h" 
#include "../daemons/skill/high_skill/murong/murong_jianfa.h" 
#include "../daemons/skill/high_skill/murong/shenyuan_gong.h" 
#include "../daemons/skill/high_skill/murong/xingyi_zhang.h" 
#include "../daemons/skill/high_skill/murong/yanling_shenfa.h" 

CSkill * LoadSkill_murong(string skill_name)
{
	CSkill * skill = NULL;

	//Ä½ÈÝ
	if(skill_name == "canhe_zhi")
		skill = new CScanhe_zhi();
	else if(skill_name == "douzhuan_xingyi")
		skill = new CSdouzhuan_xingyi();
	else if(skill_name == "murong_daofa")
		skill = new CSmurong_daofa();
	else if(skill_name == "murong_jianfa")
		skill = new CSmurong_jianfa();
	else if(skill_name == "shenyuan_gong")
		skill = new CSshenyuan_gong();
	else if(skill_name == "xingyi_zhang")
		skill = new CSxingyi_zhang();
	else if(skill_name == "yanling_shenfa")
		skill = new CSyanling_shenfa();

	return skill;
}