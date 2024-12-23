// fanliangyi_dao.h 反两仪刀法
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CSfanliangyi_dao);

virtual void create()
{
	set_name( "反两仪刀法");
	set("valid_force", "zixia_shengong");

	Magic_t * magic;

	magic = add_magic("sanshen", do_sanshen);
	magic->name = "华岳三神峰";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N手中$w斜指，一招「混沌一破」，反身一顿，一刀向$n的$l撩去", 120, -10, 100,0,"割伤",},
		{"$N一招「太乙生萌」，左右腿虚点，$w一提一收，平刃挥向$n的颈部",180 , -10, 105, 20,"割伤",},
		{"$N展身虚步，提腰跃落，一招「两仪合德」，刀锋化作两股斩向$n", 220, -5, 115,40 ,"割伤",},
		{"$N一招「日月晦明」，$w大开大阖，自上而下划出一个大弧，笔直劈向$n", 260, 5, 125, 60,"割伤",},
		{"$N手中$w一沉，一招「无色无相」，双手持刃拦腰反切，砍向$n的胸口", 300,10 ,130 , 80,"割伤",},
		{"$N挥舞$w，使出一招「万劫不复」，上劈下撩，左挡右开，齐齐罩向$n", 340, 15,135 ,100 ,"割伤",},
	};
	
	int level = 0;
	
	for(int i=6; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("fanliangyi_dao", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "blade") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 50)
		return notify_fail("你的内力不够。");
	if (me->query_skill("zixia_shengong", 1) < 10)
		return notify_fail("你的「紫霞神功」火候太浅。");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())
        || DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("你使用的武器不对。");
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练「反两仪刀法」。");
	me->receive_damage("hp", 25);
	return 1;
	
}

//perform 
static int do_sanshen(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(!target || !me->is_fighting(target) )
		return notify_fail("「华岳三神峰」只能在战斗中使用。");
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("我知道你很想用绝招，但你手里拿的也必须是刀啊！");

	if(DIFFERSTR(me->querystr("family/family_name"), "华山派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( me->query("mp") < 100 )
		return notify_fail("你的真气不够！");
	
	if( me->query_skill("blade") < 50 ||
		DIFFERSTR(me->query_skill_mapped("blade"), "fanliangyi_dao"))
		return notify_fail("你的「反两仪刀法」还不到家，无法使用「华岳三神峰」！");
	
	message_vision("$N使出华山派绝技「华岳三神峰」，身法突地变得异常灵动飘忽！", me);
		
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);
	
	me->add("mp", -100);
	me->start_busy(random(3));
	
	return 1;
	
}
/*
	else if (magic=="makearray")
	{
		return 1;
	}
	else return 0;
}
*/
SKILL_END;
/*******************
//makearray.c 双剑和壁

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

//int valid_enable(string usage) { return usage=="array"; }

//int form_array(object leader)
int perform(object leader, object target)
{
	object *member,ob, weapon;
	int i,j,n;
	int max,min,skill;
	
		  member = leader->query_team();
		  if( sizeof(member) != 2 )
			  return notify_fail("反两仪刀共需两人，少一个多一个都不行。");
		  
		  j=sizeof (member);
		  for (i=0;i<j;i++)
		  {
			  ob=member[i];
			  if (!ob||!living(ob)||!ob->is_character())
			  {
				  return notify_fail("你想和谁同使反两仪刀？");
			  }
			  if (ob->query_temp("array/name"))
			  {
				  return notify_fail("已经组成刀阵了。");
			  }
			  if (environment(leader)!=environment(ob))
			  {
				  return notify_fail("人数不够两人。");
			  }
			  if (!ob->query_skill("fanliangyi-dao",1))
			  {
				  return notify_fail(ob->name()+"还不会反两仪刀法。");
			  }
			  if (ob->is_ghost())
			  {
				  return notify_fail("只有阳间的人才能组刀阵。");
			  }
			  
			  if( ob->query("max_mp") < 50 )
				  return notify_fail(ob->query("name")+"的内力不够。");
			  
			  
			  if( !(weapon = ob->query_weapon())
				  ||       DIFFERSTR(weapon->querystr("skill_type"), "blade") )
				  return notify_fail(ob->query("name")+"必须拿把刀做武器。");
			  
			  if( ob->query_skill("fanliangyi-dao",1)<30)
				  return notify_fail(ob->query("name")+"的反两仪刀法还不够熟练。");
			  
			  if(  ob->query_skill_mapped("blade")!="fanliangyi-dao")
				  return notify_fail(ob->query("name")+"必须使用反两仪刀法。");
		  }
		  
		  //get the average array skill of the team
		  n=0;
		  for (i=0;i<j;i++)
		  {
			  ob=member[i];
			  n+=ob->query_skill("fanliangyi-dao",1);
		  }
		  n/=2;
		  
		  //get the difference of the array skill,
		  //first get the max and mix skill level of the array
		  max=member[0]->query_skill("fanliangyi-dao",1);
		  min=max;
		  for (i=0;i<j;i++)
		  {
			  skill=member[i]->query_skill("fanliangyi-dao",1);
			  if(skill>max)
				  max=skill;
			  else if(skill<min)
				  min=skill;
		  }
		  
		  //and the leader is important
		  n += leader->query_skill("fanliangyi-dao", 1) * 5;
		  n /= max - min + 1;
		  for (i=0;i<j;i++)
		  {
			  ob=member[i];
			  ob->set_temp("no_quit",1);
			  
			  ob->set_temp("array/name","fanliangyi-dao");
			  ob->set_temp("array/level",n);
			  
			  ob->add_temp("apply/attack",n);
			  ob->add_temp("apply/defense", n);
			  ob->add_temp("apply/damage",n);
			  ob->add_temp("apply/armor", n);
		  }
		  message_vision(   "$N率领$N站定两仪方位，顿时两人之间显得浑然天成、毫无破绽。"  , leader);
		  return 1;
}

int dismiss_array(object person)
{
	int i,j,n;
	object *member,ob;
	
	member=person->query_team();
	j=sizeof(member);
	n=person->query_temp("array/level");
	for (i=0;i<j;i++)
	{
		ob=member[i];
		ob->delete_temp("array");
		ob->add_temp("apply/attack",-n);
		ob->add_temp("apply/damage",-n);
		ob->add_temp("apply/defense",-n);
		ob->add_temp("apply/armor", -n);
		tell_object(ob,"剑阵解散了");
	}
}

//if the leader kills enemy, then all members in the array kill enemy
int array_kill(object leader, object enemy)
{
	object *member, ob;
	int i,j;
	member=leader->query_team();
	j=sizeof(member);
	
	for(i=0;i<j;i++) {
		ob=member[i];
		ob->kill_ob(enemy);
	}
	
	return 1;
}



int effective_level() { return 10;}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

*********************/
