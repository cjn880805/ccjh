#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"

//ȫ��
#include "../daemons/skill/high_skill/quanzhen/haotian_zhang.h" 
#include "../daemons/skill/high_skill/quanzhen/hubo.h" 
#include "../daemons/skill/high_skill/quanzhen/jinyan_gong.h" 
#include "../daemons/skill/high_skill/quanzhen/kongming_quan.h" 
#include "../daemons/skill/high_skill/quanzhen/quanzhen_jian.h" 
#include "../daemons/skill/high_skill/quanzhen/quanzhen_jianfa.h" 
#include "../daemons/skill/high_skill/quanzhen/xiantian_gong.h" 
#include "../daemons/skill/high_skill/quanzhen/xiantian_qigong.h" 

CSkill * LoadSkill_quanzhen(string skill_name)
{
	CSkill * skill = NULL;

	//ȫ��
	if(skill_name == "haotian_zhang")
		skill = new CShaotian_zhang();
	else if(skill_name == "hubo")			//˫�ֻ���֮�� lanwood 2000-12-28
		skill = new CShubo();
	else if(skill_name == "jinyan_gong")	//���㹦 lanwood 2000-12-28
		skill = new CSjinyan_gong();
	else if(skill_name == "kongming_quan")
		skill = new CSkongming_quan();
	else if(skill_name == "quanzhen_jian")
		skill = new CSquanzhen_jian();
	else if(skill_name == "quanzhen_jianfa")
		skill = new CSquanzhen_jianfa();
	else if(skill_name == "xiantian_gong")
		skill = new CSxiantian_gong();
	else if(skill_name == "xiantian_qigong")
		skill = new CSxiantian_qigong();

	return skill;
}