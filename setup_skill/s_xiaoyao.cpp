#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"

//хавЃ xiaoyao
#include "../daemons/skill/high_skill/xiaoyao/beiming_shengong.h"
#include "../daemons/skill/high_skill/xiaoyao/lingboweibu.h"
#include "../daemons/skill/high_skill/xiaoyao/xiaoyao_bu.h"
#include "../daemons/skill/high_skill/xiaoyao/xiaoyao_dao.h"
#include "../daemons/skill/high_skill/xiaoyao/xiaoyao_jian.h"
#include "../daemons/skill/high_skill/xiaoyao/lingxiao_kuaijian.h"
#include "../daemons/skill/high_skill/xiaoyao/xiaoyao_jianfa.h"

CSkill * LoadSkill_xiaoyao(string skill_name)
{
	CSkill * skill = NULL;

	//хавЃ
	if(skill_name == "beiming_shengong")
		skill = new CSbeiming_shengong();
	else if(skill_name == "lingboweibu")
		skill = new CSlingboweibu();
	else if(skill_name == "xiaoyao_bu")
		skill = new CSxiaoyao_bu();
	else if(skill_name == "xiaoyao_dao")
		skill = new CSxiaoyao_dao();
	else if(skill_name == "xiaoyao_jian")
		skill = new CSxiaoyao_jian();
	else if(skill_name == "lingxiao_kuaijian")
		skill = new CSlingxiao_kuaijian();
	else if(skill_name == "xiaoyao_jianfa")
		skill = new CSxiaoyao_jianfa();

	return skill;
}