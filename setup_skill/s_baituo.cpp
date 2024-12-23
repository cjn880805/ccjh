#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"

//ฐือี baituo
#include "../daemons/skill/high_skill/baituo/chanchu_bufa.h"
#include "../daemons/skill/high_skill/baituo/hamagong.h"
#include "../daemons/skill/high_skill/baituo/lingshe_zhangfa.h"
#include "../daemons/skill/high_skill/baituo/shexing_diaoshou.h"

CSkill * LoadSkill_baituo(string skill_name)
{
	CSkill * skill = NULL;

	// ฐือี
	if(skill_name == "chanchu_bufa")
		skill = new CSchanchu_bufa();
	else if(skill_name == "hamagong")
		skill = new CShamagong();
	else if(skill_name == "lingshe_zhangfa")
		skill = new CSlingshe_zhangfa();
	else if(skill_name == "shexing_diaoshou")
		skill = new CSshexing_diaoshou();

	return skill;
}