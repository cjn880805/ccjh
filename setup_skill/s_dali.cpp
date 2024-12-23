#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"


//大理 dali
#include "../daemons/skill/high_skill/dali/lm_shaoze.h"
#include "../daemons/skill/high_skill/dali/feifeng_whip.h"
#include "../daemons/skill/high_skill/dali/jinyu_quan.h"
#include "../daemons/skill/high_skill/dali/kurong_changong.h"
#include "../daemons/skill/high_skill/dali/kurong_shengong.h"
#include "../daemons/skill/high_skill/dali/liumai_shenjian.h"
#include "../daemons/skill/high_skill/dali/lm_guanchong.h"
#include "../daemons/skill/high_skill/dali/lm_shangyang.h"
#include "../daemons/skill/high_skill/dali/lm_shaochong.h"
#include "../daemons/skill/high_skill/dali/lm_shaoshang.h"
#include "../daemons/skill/high_skill/dali/duanjia_sword.h"
#include "../daemons/skill/high_skill/dali/lm_zhongchong.h"
#include "../daemons/skill/high_skill/dali/six_finger.h"
#include "../daemons/skill/high_skill/dali/sun_finger.h"
#include "../daemons/skill/high_skill/dali/tianlong_shengong.h"
#include "../daemons/skill/high_skill/dali/tiannan_step.h"
#include "../daemons/skill/high_skill/dali/wuluo_zhang.h"
#include "../daemons/skill/high_skill/dali/yiyang_zhi.h"
#include "../daemons/skill/high_skill/dali/qingdie_shenfa.h"

CSkill * LoadSkill_dali(string skill_name)
{
	CSkill * skill = NULL;

	//大理
	if(skill_name == "lm_shaoze")
		skill = new CSlm_shaoze();
	else if(skill_name == "feifeng_whip")
		skill = new CSfeifeng_whip();
	else if(skill_name == "jinyu_quan")
		skill = new CSjinyu_quan();
	else if(skill_name == "kurong_changong")
		skill = new CSkurong_changong();
	else if(skill_name == "kurong_shengong")
		skill = new CSkurong_shengong();
	else if(skill_name == "liumai_shenjian")
		skill = new CSliumai_shenjian();
	else if(skill_name == "lm_guanchong")
		skill = new CSlm_guanchong();
	else if(skill_name == "lm_shangyang")
		skill = new CSlm_shangyang();
	else if(skill_name == "lm_shaochong")
		skill = new CSlm_shaochong();
	else if(skill_name == "lm_shaoshang")
		skill = new CSlm_shaoshang();
	else if(skill_name == "duanjia_sword")
		skill = new CSduanjia_sword();
	else if(skill_name == "lm_zhongchong")
		skill = new CSlm_zhongchong();
	else if(skill_name == "sun_finger")
		skill = new CSsun_finger();
	else if(skill_name == "six_finger")					//lanwood 2001-01-04
		skill = new CSsix_finger();
	else if(skill_name == "tianlong_shengong")
		skill = new CStianlong_shengong();
	else if(skill_name == "tiannan_step")
		skill = new CStiannan_step();
	else if(skill_name == "wuluo_zhang")
		skill = new CSwuluo_zhang();
	else if(skill_name == "yiyang_zhi")
		skill = new CSyiyang_zhi();
	else if(skill_name == "qingdie_shenfa")
		skill = new CSqingdie_shenfa();

	return skill;
}