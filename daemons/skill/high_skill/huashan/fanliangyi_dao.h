// fanliangyi_dao.h �����ǵ���
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CSfanliangyi_dao);

virtual void create()
{
	set_name( "�����ǵ���");
	set("valid_force", "zixia_shengong");

	Magic_t * magic;

	magic = add_magic("sanshen", do_sanshen);
	magic->name = "���������";
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
		{"$N����$wбָ��һ�С�����һ�ơ�������һ�٣�һ����$n��$l��ȥ", 120, -10, 100,0,"����",},
		{"$Nһ�С�̫�����ȡ�����������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",180 , -10, 105, 20,"����",},
		{"$Nչ���鲽������Ծ�䣬һ�С����Ǻϵ¡������滯������ն��$n", 220, -5, 115,40 ,"����",},
		{"$Nһ�С����»�������$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n", 260, 5, 125, 60,"����",},
		{"$N����$wһ����һ�С���ɫ���ࡹ��˫�ֳ����������У�����$n���ؿ�", 300,10 ,130 , 80,"����",},
		{"$N����$w��ʹ��һ�С���ٲ��������������ã����ҿ�����������$n", 340, 15,135 ,100 ,"����",},
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
		return notify_fail("�������������");
	if (me->query_skill("zixia_shengong", 1) < 10)
		return notify_fail("��ġ���ϼ�񹦡����̫ǳ��");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())
        || DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if (me->query("hp") < 50)
		return notify_fail("��������������������ǵ�������");
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
		return notify_fail("����������塹ֻ����ս����ʹ�á�");
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("��֪��������þ��У����������õ�Ҳ�����ǵ�����");

	if(DIFFERSTR(me->querystr("family/family_name"), "��ɽ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( me->query("mp") < 100 )
		return notify_fail("�������������");
	
	if( me->query_skill("blade") < 50 ||
		DIFFERSTR(me->query_skill_mapped("blade"), "fanliangyi_dao"))
		return notify_fail("��ġ������ǵ������������ң��޷�ʹ�á���������塹��");
	
	message_vision("$Nʹ����ɽ�ɾ�������������塹����ͻ�ر���쳣�鶯Ʈ����", me);
		
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
//makearray.c ˫���ͱ�

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
			  return notify_fail("�����ǵ��������ˣ���һ����һ�������С�");
		  
		  j=sizeof (member);
		  for (i=0;i<j;i++)
		  {
			  ob=member[i];
			  if (!ob||!living(ob)||!ob->is_character())
			  {
				  return notify_fail("�����˭ͬʹ�����ǵ���");
			  }
			  if (ob->query_temp("array/name"))
			  {
				  return notify_fail("�Ѿ���ɵ����ˡ�");
			  }
			  if (environment(leader)!=environment(ob))
			  {
				  return notify_fail("�����������ˡ�");
			  }
			  if (!ob->query_skill("fanliangyi-dao",1))
			  {
				  return notify_fail(ob->name()+"�����ᷴ���ǵ�����");
			  }
			  if (ob->is_ghost())
			  {
				  return notify_fail("ֻ��������˲����鵶��");
			  }
			  
			  if( ob->query("max_mp") < 50 )
				  return notify_fail(ob->query("name")+"������������");
			  
			  
			  if( !(weapon = ob->query_weapon())
				  ||       DIFFERSTR(weapon->querystr("skill_type"), "blade") )
				  return notify_fail(ob->query("name")+"�����ðѵ���������");
			  
			  if( ob->query_skill("fanliangyi-dao",1)<30)
				  return notify_fail(ob->query("name")+"�ķ����ǵ���������������");
			  
			  if(  ob->query_skill_mapped("blade")!="fanliangyi-dao")
				  return notify_fail(ob->query("name")+"����ʹ�÷����ǵ�����");
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
		  message_vision(   "$N����$Nվ�����Ƿ�λ����ʱ����֮���Եû�Ȼ��ɡ�����������"  , leader);
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
		tell_object(ob,"�����ɢ��");
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
