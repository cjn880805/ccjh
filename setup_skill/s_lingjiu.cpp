#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"

//ÁéðÕ
#include "../daemons/skill/high_skill/lingjiu/liuyang_zhang.h" 
#include "../daemons/skill/high_skill/lingjiu/tianyu_qijian.h"
#include "../daemons/skill/high_skill/lingjiu/yueying_wubu.h" 
#include "../daemons/skill/high_skill/lingjiu/zhemei_shou.h" 
#include "../daemons/skill/high_skill/lingjiu/bahuang_gong.h"
#include "../daemons/skill/high_skill/lingjiu/rouqing_zhi.h"//ÇØ²¨ 2002¡¢1¡¢16


CSkill * LoadSkill_lingjiu(string skill_name)
{
	CSkill * skill = NULL;

	if(skill_name == "liuyang_zhang")
		skill = new CSliuyang_zhang();
	else if(skill_name == "tianyu_qijian")	//Lanwood 2000-12-28
		skill = new CStianyu_qijian();
	else if(skill_name == "yueying_wubu")	//lanwood 2000-12-28
		skill = new CSyueying_wubu();
	else if(skill_name == "zhemei_shou")
		skill = new CSzhemei_shou();
	else if(skill_name == "bahuang_gong")
		skill = new CSbahuang_gong();
	else if(skill_name == "rouqing_zhi") //ÇØ²¨ 2002¡¢1¡¢16
		skill = new CSrouqing_zhi();
	
	return skill;
}




