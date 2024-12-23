#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"

//Îå¶¾ wudu
#include "../daemons/skill/high_skill/wiz/wudu/guimei_shenfa.h"
#include "../daemons/skill/high_skill/wiz/wudu/wudu_bian.h"
#include "../daemons/skill/high_skill/wiz/wudu/wudu_shengong.h"
#include "../daemons/skill/high_skill/wiz/wudu/wudu_xinfa.h"
#include "../daemons/skill/high_skill/wiz/wudu/wudu_zhang.h"

CSkill * LoadSkill_wudu(string skill_name)
{
	CSkill * skill = NULL;

	//Îå¶¾
	if(skill_name == "guimei_shenfa")
		skill = new CSguimei_shenfa();
	else if(skill_name == "wudu_bian")
		skill = new CSwudu_bian();
	else if(skill_name == "wudu_shengong")
		skill = new CSwudu_shengong();
	else if(skill_name == "wudu_xinfa")
		skill = new CSwudu_xinfa();
	else if(skill_name == "wudu_zhang")
		skill = new CSwudu_zhang();

	return skill;
}