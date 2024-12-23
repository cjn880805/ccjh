#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"

//ÐÇËÞ xingxiu
#include "../daemons/skill/high_skill/xingxiu/chousui_zhang.h"
#include "../daemons/skill/high_skill/xingxiu/feixing_shu.h" 
#include "../daemons/skill/high_skill/xingxiu/huagong_dafa.h" 
#include "../daemons/skill/high_skill/xingxiu/poison.h" 
#include "../daemons/skill/high_skill/xingxiu/sanyin_wugongzhao.h" 
#include "../daemons/skill/high_skill/xingxiu/tianshan_zhang.h" 
#include "../daemons/skill/high_skill/xingxiu/xingxiu_duzhang.h" 
#include "../daemons/skill/high_skill/xingxiu/zhaixinggong.h" 
#include "../daemons/skill/high_skill/xingxiu/xixing_dafa.h" 

CSkill * LoadSkill_xingxiu(string skill_name)
{
	CSkill * skill = NULL;

	//ÐÇËÞ
	if(skill_name == "chousui_zhang")
		skill = new CSchousui_zhang();
	else if(skill_name == "feixing_shu")
		skill = new CSfeixing_shu();
	else if(skill_name == "huagong_dafa")
		skill = new CShuagong_dafa();
	else if(skill_name == "poison")
		skill = new CSpoison();
	else if(skill_name == "sanyin_wugongzhao")
		skill = new CSsanyin_wugongzhao();
	else if(skill_name == "tianshan_zhang")
		skill = new CStianshan_zhang();
	else if(skill_name == "xingxiu_duzhang")
		skill = new CSxingxiu_duzhang();
	else if(skill_name == "zhaixinggong")
		skill = new CSzhaixinggong();
	else if(skill_name == "xixing_dafa")
		skill = new CSxixing_dafa();

	return skill;
}