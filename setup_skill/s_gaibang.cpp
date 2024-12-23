#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"

//Ø¤°ï gaibang
#include "../daemons/skill/high_skill/gaibang/dagou_bang.h" 
#include "../daemons/skill/high_skill/gaibang/huntian_qigong.h" 
//#include "../daemons/skill/high_skill/gaibang/shexing_diaoshou.h" 
#include "../daemons/skill/high_skill/gaibang/xianglong_zhang.h" 
#include "../daemons/skill/high_skill/gaibang/xiaoyaoyou.h" 

CSkill * LoadSkill_gaibang(string skill_name)
{
	CSkill * skill = NULL;

	//Ø¤°ï
	if(skill_name == "dagou_bang")
		skill = new CSdagou_bang();
	else if(skill_name == "huntian_qigong")
		skill = new CShuntian_qigong();
/*	else if(skill_name == "shexing_diaoshou")
		skill = new CSshexing_diaoshou();*/
	else if(skill_name == "xianglong_zhang")
		skill = new CSxianglong_zhang();
	else if(skill_name == "xiaoyaoyou")
		skill = new CSxiaoyaoyou();

	return skill;
}
