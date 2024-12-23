#include "stdafx.h"
#include "../server/Skill.h"

//ScriptEitor-DeclareSkillsBegin
CSkill * LoadSkill_common(string skill_name);
CSkill * LoadSkill_baituo(string skill_name);
CSkill * LoadSkill_dali(string skill_name);
CSkill * LoadSkill_emei(string skill_name);
CSkill * LoadSkill_gaibang(string skill_name);
CSkill * LoadSkill_gumu(string skill_name);
CSkill * LoadSkill_huashan(string skill_name);
CSkill * LoadSkill_lingjiu(string skill_name);
CSkill * LoadSkill_mingjiao(string skill_name);
CSkill * LoadSkill_wudang(string skill_name);
CSkill * LoadSkill_xiaoyao(string skill_name);
CSkill * LoadSkill_xingxiu(string skill_name);
CSkill * LoadSkill_xueshan(string skill_name);
CSkill * LoadSkill_yunlong(string skill_name);
CSkill * LoadSkill_quanzhen(string skill_name);
CSkill * LoadSkill_shenlong(string skill_name);
CSkill * LoadSkill_taohuadao(string skill_name);
CSkill * LoadSkill_shaolin(string skill_name);
//By Cat 2001-4-9
CSkill * LoadSkill_wiz(string skill_name);
CSkill * LoadSkill_others(string skill_name);
CSkill * LoadSkill_miji(string skill_name);
CSkill * LoadSkill_murong(string skill_name);

//ScriptEditor-DeclareSkillsEnd

CSkill * Create_Skill(string skill_name)
{
	CSkill * skill = NULL;

	skill = LoadSkill_common(skill_name);

	if(! skill) skill = LoadSkill_baituo(skill_name);
	if(! skill) skill = LoadSkill_dali(skill_name);
	if(! skill) skill = LoadSkill_emei(skill_name);
	if(! skill) skill = LoadSkill_gaibang(skill_name);
	if(! skill) skill = LoadSkill_gumu(skill_name);
	if(! skill) skill = LoadSkill_huashan(skill_name);
	if(! skill) skill = LoadSkill_lingjiu(skill_name);
	if(! skill) skill = LoadSkill_mingjiao(skill_name);
	if(! skill) skill = LoadSkill_wudang(skill_name);
	if(! skill) skill = LoadSkill_xiaoyao(skill_name);
	if(! skill) skill = LoadSkill_xingxiu(skill_name);
	if(! skill) skill = LoadSkill_xueshan(skill_name);
	if(! skill) skill = LoadSkill_yunlong(skill_name);
	if(! skill) skill = LoadSkill_quanzhen(skill_name);
	if(! skill) skill = LoadSkill_shenlong(skill_name);
	if(! skill) skill = LoadSkill_taohuadao(skill_name);
	if(! skill) skill = LoadSkill_shaolin(skill_name);
	if(! skill) skill = LoadSkill_wiz(skill_name);
	if(! skill) skill = LoadSkill_others(skill_name);
	if(! skill) skill = LoadSkill_miji(skill_name);
	if(! skill) skill = LoadSkill_murong(skill_name);
	
// code by Fisho form here 
	string msg;

	if(!skill)
	{
		output_error("Fail Skill:%s", skill_name.c_str());
		skill = new CSkill();
		
		msg = "fs-";
		msg+= skill_name;
		skill->set_name(msg.c_str());
		skill->set("fail_ob", 1);
	}

	//建立技能的enable类型
	//Designed by lanwood 2000-12-23
	char valid_types[22][10] = {
		"music",
		"axe",
		"leg",
		"unarmed",
		"sword",
		"blade",
		"staff",
		"club",
		"throwing",
		"force",
		"parry",
		"lingfa",
		"dodge",
		"whip",
		"magic",
		"finger",
		"hand",
		"cuff",
		"claw",
		"strike",
		"hammer",
		"dagger",
	};
	
	msg = "";

	for(int i=0; i<21; i++)
	{
		if(skill->valid_enable(valid_types[i]))
		{
			msg += valid_types[i];
			msg+=",";
		}
	}

	skill->set("base_skill", msg.c_str());		//设置可以enable的技能类型
	
	return skill;
}
