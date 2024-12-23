#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"

//Œ‰µ± wudang
#include "../daemons/skill/high_skill/wudang/liangyi_jian.h"
#include "../daemons/skill/high_skill/wudang/taiji_dao.h"
#include "../daemons/skill/high_skill/wudang/taiji_jian.h"
#include "../daemons/skill/high_skill/wudang/taiji_quan.h"
#include "../daemons/skill/high_skill/wudang/taiji_shengong.h"
#include "../daemons/skill/high_skill/wudang/tiyunzong.h"
#include "../daemons/skill/high_skill/wudang/wudang_jian.h"

CSkill * LoadSkill_wudang(string skill_name)
{
	CSkill * skill = NULL;

	//Œ‰µ±
	if(skill_name == "liangyi_jian")
		skill = new CSliangyi_jian();
	else if(skill_name == "taiji_dao")
		skill = new CStaiji_dao();
	else if(skill_name == "taiji_jian")
		skill = new CStaiji_jian();
	else if(skill_name == "taiji_quan")
		skill = new CStaiji_quan();
	else if(skill_name == "taiji_shengong")
		skill = new CStaiji_shengong();
	else if(skill_name == "tiyunzong")
		skill = new CStiyunzong();
	else if(skill_name == "wudang_jian")
		skill = new CSwudang_jian();

	return skill;
}