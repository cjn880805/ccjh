#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"


//少林
#include "../daemons/skill/high_skill/shaolin/wuchang_zhang.h"
#include "../daemons/skill/high_skill/shaolin/cibei_dao.h"
#include "../daemons/skill/high_skill/shaolin/damo_jian.h"
#include "../daemons/skill/high_skill/shaolin/fengyun_shou.h"
#include "../daemons/skill/high_skill/shaolin/fumo_jian.h"
#include "../daemons/skill/high_skill/shaolin/hunyuan_yiqi.h"
#include "../daemons/skill/high_skill/shaolin/jingang_quan.h"
#include "../daemons/skill/high_skill/shaolin/jiuyang_shengong.h"
#include "../daemons/skill/high_skill/shaolin/longzhua_gong.h"
#include "../daemons/skill/high_skill/shaolin/luohan_quan.h"
#include "../daemons/skill/high_skill/shaolin/mantian_xing.h"
#include "../daemons/skill/high_skill/shaolin/nianhua_zhi.h"
#include "../daemons/skill/high_skill/shaolin/pudu_zhang.h"
#include "../daemons/skill/high_skill/shaolin/qianye_shou.h"
#include "../daemons/skill/high_skill/shaolin/riyue_bian.h"
#include "../daemons/skill/high_skill/shaolin/sanhua_zhang.h"
#include "../daemons/skill/high_skill/shaolin/shaolin_shenfa.h"
#include "../daemons/skill/high_skill/shaolin/weituo_gun.h"
#include "../daemons/skill/high_skill/shaolin/banruo_zhang.h"
#include "../daemons/skill/high_skill/shaolin/wuying_jian.h"
#include "../daemons/skill/high_skill/shaolin/zui_gun.h"
#include "../daemons/skill/high_skill/shaolin/xiaowuxiang.h"
#include "../daemons/skill/high_skill/shaolin/xiuluo_dao.h"
#include "../daemons/skill/high_skill/shaolin/yijinjing.h"
#include "../daemons/skill/high_skill/shaolin/yingzhua_gong.h"
#include "../daemons/skill/high_skill/shaolin/yizhi_chan.h"
#include "../daemons/skill/high_skill/shaolin/xiangmo_chu.h"

CSkill * LoadSkill_shaolin(string skill_name)
{
	CSkill * skill = NULL;

	//少林
	if(skill_name == "longzhua_gong")
		skill = new CSlongzhua_gong();
	else if(skill_name == "cibei_dao")
		skill = new CScibei_dao();
	else if(skill_name == "damo_jian")
		skill = new CSdamo_jian();
	else if(skill_name == "fengyun_shou")
		skill = new CSfengyun_shou();
	else if(skill_name == "fumo_jian")
		skill = new CSfumo_jian();
	else if(skill_name == "hunyuan_yiqi")
		skill = new CShunyuan_yiqi();
	else if(skill_name == "jingang_quan")
		skill = new CSjingang_quan();
	else if(skill_name == "jiuyang_shengong")
		skill = new CSjiuyang_shengong();
	else if(skill_name == "banruo_zhang")
		skill = new CSbanruo_zhang();
	else if(skill_name == "luohan_quan")
		skill = new CSluohan_quan();
	else if(skill_name == "mantian_xing")
		skill = new CSmantian_xing();
	else if(skill_name == "nianhua_zhi")
		skill = new CSnianhua_zhi();
	else if(skill_name == "pudu_zhang")
		skill = new CSpudu_zhang();
	else if(skill_name == "qianye_shou")
		skill = new CSqianye_shou();
	else if(skill_name == "riyue_bian")
		skill = new CSriyue_bian();
	else if(skill_name == "sanhua_zhang")
		skill = new CSsanhua_zhang();
	else if(skill_name == "shaolin_shenfa")
		skill = new CSshaolin_shenfa();
	else if(skill_name == "weituo_gun")
		skill = new CSweituo_gun();
	else if(skill_name == "wuchang_zhang")
		skill = new CSwuchang_zhang();
	else if(skill_name == "wuying_jian")
		skill = new CSwuying_jian();
	else if(skill_name == "xiangmo_chu")
		skill = new CSxiangmo_chu();
	else if(skill_name == "xiaowuxiang")
		skill = new CSxiaowuxiang();
	else if(skill_name == "xiuluo_dao")
		skill = new CSxiuluo_dao();
	else if(skill_name == "yijinjing")
		skill = new CSyijinjing();
	else if(skill_name == "yingzhua_gong")
		skill = new CSyingzhua_gong();
	else if(skill_name == "yizhi_chan")
		skill = new CSyizhi_chan();
	else if(skill_name == "zui_gun")
		skill = new CSzui_gun();
	
	return skill;
}