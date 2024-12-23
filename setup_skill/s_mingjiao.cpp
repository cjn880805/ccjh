#include "stdafx.h"
#include "../server/Skill.h"
#include "../std/Force.h"

//����
#include "../daemons/skill/high_skill/mingjiao/shenghuo_xinfa.h" 
#include "../daemons/skill/high_skill/mingjiao/fenglei_dao.h" 
#include "../daemons/skill/high_skill/mingjiao/hanbing_strike.h" 
#include "../daemons/skill/high_skill/mingjiao/hanbing_mianzhang.h" 
#include "../daemons/skill/high_skill/mingjiao/houquan.h" 
#include "../daemons/skill/high_skill/mingjiao/jiuyang_shengong.h" 
#include "../daemons/skill/high_skill/mingjiao/piaoyibu.h" 
#include "../daemons/skill/high_skill/mingjiao/qiankun_danuoyi.h" 
#include "../daemons/skill/high_skill/mingjiao/qingfu_shenfa.h" 
#include "../daemons/skill/high_skill/mingjiao/qishang_quan.h" 
//#include "../daemons/skill/high_skill/mingjiao/shenghuo_ling.h" 
#include "../daemons/skill/high_skill/mingjiao/shenghuo_lingfa.h" 
#include "../daemons/skill/high_skill/mingjiao/shenghuo_shengong.h" 
#include "../daemons/skill/high_skill/mingjiao/duoming_jinhua.h" 
#include "../daemons/skill/high_skill/mingjiao/sougu.h" 
#include "../daemons/skill/high_skill/mingjiao/shigu_bifa.h" 
#include "../daemons/skill/high_skill/mingjiao/wuyue_blade.h" 
#include "../daemons/skill/high_skill/mingjiao/wuyun_jianfa.h" 
#include "../daemons/skill/high_skill/mingjiao/wuzheng_xinfa.h" 
#include "../daemons/skill/high_skill/mingjiao/xuantian_shengong.h" 
#include "../daemons/skill/high_skill/mingjiao/xuantian_zhi.h" 
#include "../daemons/skill/high_skill/mingjiao/xuanyuan_arrow.h" 
#include "../daemons/skill/high_skill/mingjiao/yingzhua_shou.h" 
#include "../daemons/skill/high_skill/mingjiao/youlong_staff.h" 
#include "../daemons/skill/high_skill/mingjiao/bianfu_dao.h" 

CSkill * LoadSkill_mingjiao(string skill_name)
{
	CSkill * skill = NULL;

	//����
	if(skill_name == "shenghuo_xinfa")		//ʥ���ķ� cat 2001-3-20
		skill = new CSshenghuo_xinfa();
	else if(skill_name == "fenglei_dao")	//���׵� lanwood 2001-02-02
		skill = new CSfenglei_dao();
	else if(skill_name == "hanbing_strike")	//���溮���� cat 2001-3-20
		skill = new CShanbing_strike();
	else if(skill_name == "hanbing_mianzhang")//�������� cat 2001-3-20
		skill = new CShanbing_mianzhang();		
	else if(skill_name == "houquan")		//��ȭ lanwood 2000-12-29
		skill = new CShouquan();
	else if(skill_name == "jiuyang_shengong")	//������ cat 2001-3-20
		skill = new CSjiuyang_shengong();
	else if(skill_name == "piaoyibu")		//÷��Ʈ�ݲ��� lanwood 2000-12-28
		skill = new CSpiaoyibu();
	else if(skill_name == "qiankun_danuoyi")	//Ǭ����Ų�� cat 2001-3-20
		skill = new CSqiankun_danuoyi();
	else if(skill_name == "qingfu_shenfa")		//������ cat 2001-3-20
		skill = new CSqingfu_shenfa();
	else if(skill_name == "qishang_quan")		//����ȭ cat 2001-3-20
		skill = new CSqishang_quan();
//	else if(skill_name == "shenghuo_ling")		//ʥ��� cat 2001-3-20
//		skill = new CSshenghuo_ling();
	else if(skill_name == "shenghuo_lingfa")
		skill = new CSshenghuo_lingfa();
	else if(skill_name == "shenghuo_shengong")	//ʥ���� cat 2001-3-20
		skill = new CSshenghuo_shengong();
	else if(skill_name == "shigu_bifa")			//÷��ʯ�ĵ�Ѩ�ʷ� lanwood 2000-12-28
		skill = new CSshigu_bifa();
	else if(skill_name == "duoming_jinhua")		//������ cat 2001-3-20
		skill = new CSduoming_jinhua();
	else if(skill_name == "sougu")				//�ѹ�ӥצ�� cat 2001-3-20
		skill = new CSsougu();
	else if(skill_name == "wuyue_blade")		//���µ��� cat 2001-3-20
		skill = new CSwuyue_blade();
	else if(skill_name == "wuyun_jianfa")		//�������ҽ� cat 2001-3-20
		skill = new CSwuyun_jianfa();
	else if(skill_name == "wuzheng_xinfa")		//�����ķ� cat 2001-3-20
		skill = new CSwuzheng_xinfa();
	else if(skill_name == "xuantian_shengong")	//������ cat 2001-3-20
		skill = new CSxuantian_shengong();
	else if(skill_name == "xuantian_zhi")		//����ָ cat 2001-3-20
		skill = new CSxuantian_zhi();
	else if(skill_name == "xuanyuan_arrow")		//��������ԯ�� lanwood 2000-12-29
		skill = new CSxuanyuan_arrow();
	else if(skill_name == "yingzhua_shou")		//ӥצ�� cat 2001-3-20
		skill = new CSyingzhua_shou();
	else if(skill_name == "youlong_staff")		//��ɼ�����������ȷ� 
		skill = new CSyoulong_staff();
	else if(skill_name == "bianfu_dao")			//�������������𵶷� 
		skill = new CSbianfu_dao();
	
	return skill;
}



