#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"


//华山 huashan
#include "../daemons/skill/high_skill/huashan/fanliangyi_dao.h" 
//#include "../daemons/skill/high_skill/huashan/huashan_jianfa.h" 
#include "../daemons/skill/high_skill/huashan/huashan_ken.h" 
//#include "../daemons/skill/high_skill/huashan/huashan_neigong.h" 
#include "../daemons/skill/high_skill/huashan/huashan_shenfa.h" 
#include "../daemons/skill/high_skill/huashan/huashan_sword.h" 
#include "../daemons/skill/high_skill/huashan/huashan_zhangfa.h" 
#include "../daemons/skill/high_skill/huashan/hunyuan_zhang.h" 
#include "../daemons/skill/high_skill/huashan/kuangfeng_jian.h" 
#include "../daemons/skill/high_skill/huashan/lonely_sword.h" 
#include "../daemons/skill/high_skill/huashan/poyu_quan.h" 
#include "../daemons/skill/high_skill/huashan/zixia_shengong.h"
#include "../daemons/skill/high_skill/huashan/yunv_swords.h" 
#include "../daemons/skill/high_skill/huashan/zhengqijue.h"

//add by lanwood 2000-12-28 令狐冲的技能
#include "../daemons/skill/high_skill/huashan/feiyan_huixiang.h"

CSkill * LoadSkill_huashan(string skill_name)
{
	CSkill * skill = NULL;

	//华山
	if(skill_name == "fanliangyi_dao")
		skill = new CSfanliangyi_dao();
	else if(skill_name == "feiyan_huixiang")
		skill = new CSfeiyan_huixiang();
	else if(skill_name == "huashan_ken")
		skill = new CShuashan_ken();
/*	else if(skill_name == "huashan_neigong")
		skill = new CShuashan_neigong();*/
	else if(skill_name == "huashan_shenfa")
		skill = new CShuashan_shenfa();
	else if(skill_name == "huashan_sword")
		skill = new CShuashan_sword();
	else if(skill_name == "huashan_zhangfa")
		skill = new CShuashan_zhangfa();
	else if(skill_name == "hunyuan_zhang")
		skill = new CShunyuan_zhang();
	else if(skill_name == "kuangfeng_jian")
		skill = new CSkuangfeng_jian();
	else if(skill_name == "lonely_sword")
		skill = new CSlonely_sword();
	else if(skill_name == "poyu_quan")
		skill = new CSpoyu_quan();
	else if(skill_name == "zixia_shengong")
		skill = new CSzixia_shengong();
	else if(skill_name == "yunv_swords")
		skill = new CSyunv_swords();
	else if(skill_name == "zhengqijue")
		skill = new CSzhengqijue();

	return skill;
}