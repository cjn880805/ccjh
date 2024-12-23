//doangyangdaofa.h �廢���ŵ�

//coded by xiao wu
//data: 2000-3-28

SKILL_BEGIN(CSdongyangdaofa);

virtual void create()
{
	set_name( "���󵶷�");
}

virtual CMapping * query_action(CChar *me)
{
	struct{
			char action[255];
			int force,dodge, parry ,damage;
			char damage_type[5];
	}action[11]={
		{"$Nƽ������$w��һ�С���ͻ������$n��$l��Ȼ��ȥ",120 ,-10 , 5, 15, "����",},
		{"$N��ǰһ����$wб������Ȼһ�С��෵����������$n�ľ���", 130, -10, 10, 20, "����",},
		{"$N����$w��ʹ��һ�С��ٹ�ҹϮ�����������ã����ҿ�����������$n", 140, 15, 15, 45, "����",},
		{"$N�ȴ�$n��Ӱ�ӽ����Լ�������һ���ǣ���ȻԾ��һ�С��칷������$wһ����$n��ͷն��", 150, -5, 5, 25, "����",},
		{"$N����ϸ��$n����������$n���������ļ�Ъ��ͻȻ�ϲ���һ�С�ˮ�¡�������Ϣ������$n�ľ���", 160,5 , 5, 30, "����",},
		{"$N�ӵ����ʣ�����$n�������Է��Ķ�����ͻȻһ�С���̫ն�����ϲ�����Ť��ײ�������$wЮ�ŷ�����������$n��$l", 180, 10, 5, 35, "����",},
		{"$N$N�˺󼸲�����������$wһ����ͻȻһ�С���������˫�ֳ��лӳ�һ�����ε���������$n���ؿ�", 240, 5, 15, 50, "����",},
		{"$N�߾�$w��һ�С��������ӳ�һ�������ĵ�Ӱ����$n�ľ�����ȥ", 280, 20, 10, 60, "����",},
		{"$N˫�ֽ�$wһ�٣�����ͻȻ�������漴����$n������֣�һ�С����С�ֱն��$n�ĺ���", 320,20 , 20,70 , "����",},
		{"$N����һ����ӡ���ȵ����٣���ͻȻ�ֳ��ĸ���Ӱͬʱ��������$wֱ����$n", 320, 20, 20, 70, "����",},
		{"$NͻȻ��ʧ����$n������������������$wֱ��ȥ$n���ɲ�", 350, 30,30 , 80, "����",},
	};
 		
	int zhaoshu, level;
	
	zhaoshu = 11;
	level  = me->query_skill("dongyangdaofa",1);

	if (level < 60 )
		zhaoshu--;
	if (level < 50 )
		zhaoshu--;
	if (level < 40 )
		zhaoshu--;
	if (level < 30 )
		zhaoshu--;
	if (level < 20 )
		zhaoshu--;
	if (level < 10 )
		zhaoshu--;
	level = random(zhaoshu);

	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("parry", action[level].parry);
	m_actions.set("damage", action[level].damage);
	
	return & m_actions;
}


virtual int valid_enable(string usage)
{ 
	return (usage == "blade") || (usage == "parry"); 
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("�������������");

	if (me->query_skill("blade", 1) < 20)
		return notify_fail("��Ļ����������̫ǳ��");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon ;
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("��ʹ�õ��������ԡ�");

	if (me->query("hp") < 50)
		return notify_fail("����������������󵶷���");

	me->receive_damage("hp", 30);
	return 1;
}

protected:
	CMapping m_actions;

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp

/**************************************
// wuhu-duanmendao.c �廢���ŵ�

inherit SKILL;

mapping *action = ({
([	"action" : "$N����$wбָ��һ�С�ֱ��ֱȥ��������һ�٣�һ����$n��$l��ȥ",
	"force" : 120,
        "dodge" : -10,
        "parry" : 5,
	"damage" : 15,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�ͯ�ӹһ�������������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
	"force" : 130,
        "dodge" : -10,
        "parry" : 10,
	"damage" : 20,
	"damage_type" : "����"
]),
([	"action" : "$Nչ���鲽������Ծ�䣬һ�С��ƴ����¡�������һ������ն��$n",
	"force" : 140,
        "dodge" : -5,
        "parry" : 5,
	"damage" : 25,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�������ɽ����$w�󿪴��أ����϶��»���һ�����磬ֱ����$n",
	"force" : 160,
        "dodge" : 5,
        "parry" : 5,
	"damage" : 30,
	"damage_type" : "����"
]),
([	"action" : "$N����$wһ����һ�С���Ϫ���㡹��˫�ֳ����������У�����$n���ؿ�",
	"force" : 180,
        "dodge" : 10,
        "parry" : 5,
	"damage" : 35,
	"damage_type" : "����"
]),
([	"action" : "$N����$w��ʹ��һ�С��Ź����ġ����������ã����ҿ�����������$n",
	"force" : 210,
        "dodge" : 15,
        "parry" : 15,
	"damage" : 45,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С��������ۡ������Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
	"force" : 240,
        "dodge" : 5,
        "parry" : 15,
	"damage" : 50,
	"damage_type" : "����"
]),
([	"action" : "$N����פ�أ�һ�С�������Ϣ�����ӳ�һƬ�����ĵ�Ӱ����$n��ȫ��ӿȥ",
	"force" : 280,
        "dodge" : 20,
        "parry" : 10,
	"damage" : 60,
	"damage_type" : "����"
]),
([	"action" : "$N���ֺ󳷣�����һ����һ�С�׳ʿ���󡹣���ʱһ���׹�ֱն��$n���ֱ�",
	"force" : 320,
        "dodge" : 20,
        "parry" : 20,
	"damage" : 70,
	"damage_type" : "����"
]),
([	"action" : "$N�߸�Ծ��һ�С���ͷ��ء�������$wֱ����$n�ľ���",
	"force" : 320,
        "dodge" : 20,
        "parry" : 20,
	"damage" : 70,
	"damage_type" : "����"
]),
([	"action" : "$N���ػ��У�һ�С����Ӿ��������$wֱ��ȥ$n���ɲ�",
	"force" : 350,
        "dodge" : 30,
        "parry" : 30,
	"damage" : 80,
	"damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

int valid_learn(object me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("�������������");
	if (me->query_skill("blade", 1) < 20)
		return notify_fail("��Ļ����������̫ǳ��");
	return 1;
}

mapping query_action(object me, CContainer * weapon)
{
int zhaoshu, level;

zhaoshu = sizeof(action)-1;
level   =  me->query_skill("wuhu-duanmendao",1);

if (level < 60 )
zhaoshu--;
if (level < 50 )
zhaoshu--;
if (level < 40 )
zhaoshu--;
if (level < 30 )
zhaoshu--;
if (level < 20 )
zhaoshu--;
if (level < 10 )
zhaoshu--;
return action[random(zhaoshu)];
}

int practice_skill(object me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
	||  DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if (me->query("hp") < 50)
		return notify_fail("��������������廢���ŵ�����");
	me->receive_damage("hp", 30);
	return 1;
}
*****************************/

