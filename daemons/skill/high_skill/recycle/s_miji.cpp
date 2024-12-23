#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"

//√ÿºÆ
#include "../daemons/skill/high_skill/wiz/miji/jinshe_jian.h" 
#include "../daemons/skill/high_skill/wiz/miji/jinshe_zhang.h" 
#include "../daemons/skill/high_skill/wiz/miji/jinshe_zhui.h" 
#include "../daemons/skill/high_skill/wiz/miji/yihun_dafa.h" 
#include "../daemons/skill/high_skill/wiz/miji/zhengqijue.h" 
#include "../daemons/skill/high_skill/wiz/miji/taixuan_gong.h" 

CSkill * LoadSkill_miji(string skill_name)
{
	CSkill * skill = NULL;

	//√ÿºÆ
	if(skill_name == "jinshe_jian")
		skill = new CSjinshe_jian();
	else if(skill_name == "jinshe_zhang")
		skill = new CSjinshe_zhang();
	else if(skill_name == "jinshe_zhui")
		skill = new CSjinshe_zhui();
	else if(skill_name == "yihun_dafa")
		skill = new CSyihun_dafa();
	else if(skill_name == "zhengqijue")
		skill = new CSzhengqijue();
	else if(skill_name == "taixuan_gong")
		skill = new CStaixuan_gong();

	return skill;
}