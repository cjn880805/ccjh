#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"


//ѩɽ xueshan
#include "../daemons/skill/high_skill/xueshan/yujiamu_quan.h" 
#include "../daemons/skill/high_skill/xueshan/huoyan_dao.h" 
#include "../daemons/skill/high_skill/xueshan/lamaism.h" 
#include "../daemons/skill/high_skill/xueshan/longxiang.h" 
#include "../daemons/skill/high_skill/xueshan/mingwang_jian.h" 
#include "../daemons/skill/high_skill/xueshan/mizong_xinfa.h" 
#include "../daemons/skill/high_skill/xueshan/riyue_lun.h" 
#include "../daemons/skill/high_skill/xueshan/shenkong_xing.h" 
#include "../daemons/skill/high_skill/xueshan/xiaowuxiang.h" 
#include "../daemons/skill/high_skill/xueshan/xue_dao.h" 
#include "../daemons/skill/high_skill/xueshan/xuedao_xinfa.h" 
#include "../daemons/skill/high_skill/xueshan/dashou_yin.h" 

CSkill * LoadSkill_xueshan(string skill_name)
{
	CSkill * skill = NULL;

	//ѩɽ
	if(skill_name == "yujiamu_quan")
		skill = new CSyujiamu_quan();
	else if(skill_name == "huoyan_dao")
		skill = new CShuoyan_dao();
	else if(skill_name == "lamaism")
		skill = new CSlamaism();
	else if(skill_name == "longxiang")
		skill = new CSlongxiang();
	else if(skill_name == "mingwang_jian")
		skill = new CSmingwang_jian();
	else if(skill_name == "mizong_xinfa")
		skill = new CSmizong_xinfa();
	else if(skill_name == "riyue_lun")
		skill = new CSriyue_lun();
	else if(skill_name == "shenkong_xing")
		skill = new CSshenkong_xing();
	else if(skill_name == "xiaowuxiang")
		skill = new CSxiaowuxiang();
	else if(skill_name == "xue_dao")
		skill = new CSxue_dao();
	else if(skill_name == "xuedao_xinfa")
		skill = new CSxuedao_xinfa();
	else if(skill_name == "dashou_yin")
		skill = new CSdashou_yin();

	return skill;
}