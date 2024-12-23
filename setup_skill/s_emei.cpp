#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"
#include "../std/FightRoom.h"

//Жысв emei
#include "../daemons/skill/high_skill/emei/huifeng_jian.h" 
#include "../daemons/skill/high_skill/emei/jinding_zhang.h" 
//#include "../daemons/skill/high_skill/emei/jiuyin_baiguzhao.h" 
#include "../daemons/skill/high_skill/emei/jiuyin_zhua.h" 
#include "../daemons/skill/high_skill/emei/linji_zhuang.h" 
#include "../daemons/skill/high_skill/emei/mahayana.h" 
#include "../daemons/skill/high_skill/emei/persuading.h" 
#include "../daemons/skill/high_skill/emei/tiangang_zhi.h" 
#include "../daemons/skill/high_skill/emei/yanxing_dao.h" 
#include "../daemons/skill/high_skill/emei/zhutian_bu.h" 
#include "../daemons/skill/high_skill/emei/huifeng_qijue.h" 

CSkill * LoadSkill_emei(string skill_name)
{
	CSkill * skill = NULL;

	//Жысв
	if(skill_name == "huifeng_jian")
		skill = new CShuifeng_jian();
	else if(skill_name == "jinding_zhang")
		skill = new CSjinding_zhang();
/*	else if(skill_name == "jiuyin_baiguzhao")
		skill = new CSjiuyin_baiguzhao();
*/
	else if(skill_name == "jiuyin_zhua")
		skill = new CSjiuyin_zhua();
	else if(skill_name == "linji_zhuang")
		skill = new CSlinji_zhuang();
	else if(skill_name == "mahayana")
		skill = new CSmahayana();
	else if(skill_name == "persuading")
		skill = new CSpersuading();
	else if(skill_name == "tiangang_zhi")
		skill = new CStiangang_zhi();
	else if(skill_name == "yanxing_dao")
		skill = new CSyanxing_dao();
	else if(skill_name == "zhutian_bu")
		skill = new CSzhutian_bu();

	else if(skill_name == "huifeng_qijue")
		skill = new CShuifeng_qijue();

	return skill;
}
