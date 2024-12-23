#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"

//√ÿºÆ

#include "../daemons/skill/high_skill/special/miji/kuihua_xinfa.h" 
#include "../daemons/skill/high_skill/special/miji/pixie_jian.h" 
#include "../daemons/skill/high_skill/special/miji/pixie_sword.h" 
#include "../daemons/skill/high_skill/special/miji/jinshe_jian.h" 
#include "../daemons/skill/high_skill/special/miji/jinshe_zhang.h" 
#include "../daemons/skill/high_skill/special/miji/jinshe_zhui.h" 
#include "../daemons/skill/high_skill/special/miji/yihun_dafa.h" 
#include "../daemons/skill/high_skill/special/miji/taixuan_gong.h"
#include "../daemons/skill/high_skill/special/miji/jiuyin_baiguzhua.h"

CSkill * LoadSkill_miji(string skill_name)
{
	CSkill * skill = NULL;

	if(skill_name == "kuihua_xinfa")
		skill = new CSkuihua_xinfa();
	else if(skill_name == "pixie_jian")
		skill = new CSpixie_jian();
	else if(skill_name == "pixie_sword")
		skill = new CSpixie_sword();
	else if(skill_name == "jinshe_jian")
		skill = new CSjinshe_jian();
	else if(skill_name == "jinshe_zhang")
		skill = new CSjinshe_zhang();
	else if(skill_name == "jinshe_zhui")
		skill = new CSjinshe_zhui();
	else if(skill_name == "yihun_dafa")
		skill = new CSyihun_dafa();
	else if(skill_name == "taixuan_gong")
		skill = new CStaixuan_gong();
	else if(skill_name == "jiuyin_baiguzhua")
		skill = new CSjiuyin_baiguzhua();

	return skill;
}