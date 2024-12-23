#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"

//¹ÅÄ¹ gumu
#include "../daemons/skill/high_skill/gumu/anranxiaohun_zhang.h" 
#include "../daemons/skill/high_skill/gumu/meinv_quan.h" 
//#include "../daemons/skill/high_skill/gumu/meinv_quanfa.h" 
#include "../daemons/skill/high_skill/gumu/qufeng.h" 
#include "../daemons/skill/high_skill/gumu/tianluo_diwang.h" 
#include "../daemons/skill/high_skill/gumu/xianyun_bufa.h" 
#include "../daemons/skill/high_skill/gumu/yinsuo_jinling.h" 
//#include "../daemons/skill/high_skill/gumu/yufeng_shu.h" 
#include "../daemons/skill/high_skill/gumu/yunv_jian.h" 
#include "../daemons/skill/high_skill/gumu/yunv_shenfa.h" 
#include "../daemons/skill/high_skill/gumu/yunv_xinfa.h" 
#include "../daemons/skill/high_skill/gumu/yunv_xinjing.h" 
#include "../daemons/skill/high_skill/gumu/swsb_whip.h" 

#include "../daemons/skill/high_skill/gumu/seaforce.h" 
#include "../daemons/skill/high_skill/gumu/smithsword.h" 
#include "../daemons/skill/high_skill/gumu/wudu_shenzhang.h"

CSkill * LoadSkill_gumu(string skill_name)
{
	CSkill * skill = NULL;

	//¹ÅÄ¹
	if(skill_name == "anranxiaohun_zhang")
		skill = new CSanranxiaohun_zhang();
	else if(skill_name == "meinv_quan")
		skill = new CSmeinv_quan();
/*	else if(skill_name == "meinv_quanfa")
		skill = new CSmeinv_quanfa();*/
	else if(skill_name == "qufeng")
		skill = new CSqufeng();
	else if(skill_name == "tianluo_diwang")
		skill = new CStianluo_diwang();
	else if(skill_name == "xianyun_bufa")
		skill = new CSxianyun_bufa();
	else if(skill_name == "yinsuo_jinling")
		skill = new CSyinsuo_jinling();
/*	else if(skill_name == "yufeng_shu")
		skill = new CSyufeng_shu();*/
	else if(skill_name == "yunv_jian")
		skill = new CSyunv_jian();
	else if(skill_name == "yunv_shenfa")
		skill = new CSyunv_shenfa();
	else if(skill_name == "yunv_xinfa")
		skill = new CSyunv_xinfa();
	else if(skill_name == "yunv_xinjing")
		skill = new CSyunv_xinjing();
	else if(skill_name == "swsb_whip")
		skill = new CSswsb_whip();

	else if(skill_name == "seaforce")
		skill = new CSseaforce();
	else if(skill_name == "smithsword")
		skill = new CSsmithsword();
	else if(skill_name == "wudu_shenzhang")
		skill = new CSwudu_shenzhang();

	return skill;
}