// Skill.cpp: implementation of the CSkill class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Skill.h"
#include "Globle.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
int CheckAP(int nAp, CChar * me);
void ResumeAP(int nAP, CChar * me);

//加载技能
CSkill::CSkill()
{
}

CSkill::~CSkill()
{
	//清空法术列表
	CastList_t::iterator p;

	for(p = m_MagicList.begin(); p!=m_MagicList.end(); p++)
		delete p->second;

	m_MagicList.clear();
}


int CSkill::valid_learn(CChar *me)
{
	return 1;
}

CMapping * CSkill::query_action(CChar * me)
{
	return 0;
}

LONG CSkill::Query(int nAttr)
{
	switch(nAttr)
	{
	case IS_SKILL:
		return 1;
	default:
		return CMudObject::Query(nAttr);
	}

	return 1;
}

//下载 C=DOWNSKILL S=skill N=skill_name P=picture E=valid_enable T=target
void CSkill::DownLoad(CChar * me)
{
	char str[255];

	snprintf(str, 255, "&C=%d&S=%s&N=%s&P=%d&E=%s&", DOWNSKILL, 
		querystr("base_name"), name(1), 
		query("icon"),
		querystr("base_skill"));
	
	if(query("special"))
		strcat(str, "s=1&");

	me->SendCommand(str, 1);

	//传送该技能支持的法术 C=DOWNMAGIC S=skill M=magic N=name R=mp A=ap a=animate, V=valid_cast
	CastList_t::iterator p;

	for(p = m_MagicList.begin(); p != m_MagicList.end(); p++)
	{
		Magic_t * magic = p->second;
		snprintf(str, 255, "&C=%d&S=%s&M=%s&N=%s&R=%ld&A=%ld&T=%d&V=%d&",
			DOWNMAGIC, querystr("base_name"),
			p->first.c_str(), 
			magic->name.c_str(),
			magic->mp, 
			magic->ap,
			magic->target,
			magic->valid_cast);

		me->SendCommand(str, 1);
	}
}

char * CSkill::hit_ob(CChar *me, CChar *victim, LONG & damage)
{
	return 0;
}

void CSkill::create()
{

}

void CSkill::skill_improved(CChar *me)
{

}

static void remove_no_cast(CContainer * ob, LONG param1, LONG param2)
{
	ob->delete_temp("no_cast");
}

int CSkill::Cast(string magic, CChar *me, CContainer * target)
{
	CastList_t::iterator p;
	LONG object_id = 0;

	//增加内功对法术的限制
	if(! valid_force(me->query_skill_mapped("force")) )
		return 0;

	if(target) object_id = target->object_id();
		
	for(p = m_MagicList.begin(); p != m_MagicList.end(); p++)
		if(p->first == magic)
		{
			Magic_t * pMagic = p->second;

			//先判断AP是否足够！
			LONG ap = pMagic->ap * (120 - me->query_skill(_M.querystr("base_name"), 1) / 4 - me->query("level") / 2) / 100;

			if(ap < 0) ap = 1;

			if(! CheckAP(ap, me)) return 0;

			int bSubAp = 0;
			if(me->is_fighting()) bSubAp = 1;

			int ret;
			if( (ret = (* pMagic->pFunc)( me, target)) )
			{
				me->set_temp("no_cast", 1);
				me->call_out(remove_no_cast, ret);

				if(object_id == g_LastDestructObject)
					target = NULL;
				
				if(bSubAp)	ResumeAP(ap, me);		

				//如果是为人疗伤，有奖励！
				if(magic == "lifeheal")
					lifehealeffect(me, (CChar *)target);

				//传输状态
				if(target && pMagic->target == CAST_TO_OTHER)
					((CChar *)target)->SendState();
				me->SendState();
				return 1;
			}
		}

	return 0;
}


int CSkill::valid_effect(CChar *me, CContainer *weapon, char *action_name, int skill)
{
	return 1;
}

const char * CSkill::type()
{
	return "martial";
}

const char * CSkill::query_dodge_msg(CChar * me)
{
	return 0;
}

const char * CSkill::query_parry_msg(CContainer *weapon)
{
	return 0;
}

int CSkill::valid_enable(string usage)
{
	return 0;
}

int CSkill::practice_skill(CChar *me)
{
	return 1;
}

int CSkill::valid_combine(string combo)
{
	return 0;
}

CSkill::Magic_t * CSkill::add_magic(string magic, MAGICFUNCTIONP * pFunc)
{
	Magic_t * pMagic = new Magic_t;

	pMagic->pFunc = pFunc;
	m_MagicList[magic] = pMagic;

	return pMagic;
}

//给为人疗伤的增加经验。
void CSkill::lifehealeffect(CChar *me, CChar *target)
{
	char expmsg[80];
	int addexp = me->query("level") / 4 + 1;
	int addrpt = 10 - target->query("level");

	addexp = (addexp + random(addexp)) / 2;
	if(addrpt < 1) addrpt = 1;
	addrpt = (addrpt + random(addrpt)) / 2;
	addexp=1;
	
	me->add("combat_exp", addexp);
	//me->add("repute", addrpt);
	
	tell_object(me, snprintf(expmsg, 80, "你的修行提高了%ld点！声望提高了0点！", addexp));
}

int CSkill::valid_force(const char * arg)
{
	const char * valid_force = querystr("valid_force");
	if(valid_force[0] && DIFFERSTR(valid_force, arg) )
		return notify_fail("%s必须与%s配合使用。", name(1), load_skill(valid_force)->name(1));

	return 1;
}

//开始激励
void CSkill::start_powerup(CChar *me, int duration, int attack, int dodge, const char *msg)
{
	me->add_temp("apply/attack", attack);
    me->add_temp("apply/dodge", dodge);
    me->set_temp("powerup/attack", attack);
	me->set_temp("powerup/dodge", dodge);
	me->set_temp("powerup/msg", msg);

	me->call_out(remove_powerup, duration, 0);	
}

//消除激励
void CSkill::remove_powerup(CContainer *ob, LONG silence, LONG param2)
{
	CChar * me = (CChar *)ob;

	if(! me->querymap_temp("powerup")) return;

	me->add_temp("apply/attack", - me->query_temp("powerup/attack"));
	me->add_temp("apply/dodge", - me->query_temp("powerup/dodge"));
	
	me->SendState(me);

	if(! silence)
		tell_object(me, me->querystr_temp("powerup/msg"));

	me->delete_temp("powerup");
}
