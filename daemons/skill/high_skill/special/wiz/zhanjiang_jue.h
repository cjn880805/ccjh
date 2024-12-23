//zhanjiang_jue.h ն����

//coded by oho
//data: 2001-4-17

SKILL_BEGIN(CSzhanjiang_jue);

virtual void create()
{
	set_name( "ն����");
	Magic_t * magic;

	magic = add_magic("killyou", do_ding);
	magic->name = "ǧ��ն��";
	magic->mp = 550;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

const char * query_parry_msg(CContainer * weapon)
{
	static char parry_msg[][80] = {
		{"$n����һ�̣�����ʤ�ɣ����е�$W�ݺݿĿ���$N�Ĺ�����"},
		{"$n����һ��������ʤ�ɣ��ܿ���$N��$w��"},
		{"$n����һ������$N��$w������"},
		{"$nԾ����𣬽����ʹ̣���$NӲ�����˼�����"},
	};

	static char unarmed_parry_msg[][80] = {
		{"$n�Ӹ����£��͵���$NҪ��һ�̣�$Nֻ�û��з��ء�"},
		{"$nһ�İ�����������������������$N�Ĺ�����"},
		{"$n���˶Է������������ͳ壬��$NӲ����ײ��һ�ԣ����ļ�����վ�ȡ�"},
		{"$n�ӱ���γ�ն����������һ��������$N��"},
	};
	if( weapon )
		return parry_msg[random(4)];
	else
		return unarmed_parry_msg[random(4)];
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct{
			char action[100];
			int force,dodge, damage, lvl;		
	}action[]={
		{"$N�����ͳ壬$w����һ�����⻮��$n������", 380, -10, 342,0,},		
		{"$N˫��һ�У���������$nһԾ������$wҲͬʱ���������Ʋ��ɵ��ش���$n", 300, -3, 348,50,},
		{"$NԾ�������$n��ȥ������$w������$n���ʺ��ʹ�", 340, -5, 500,150 },
		{"$N������$n��ߣ���Ȼ$w�����֣����ְγ�ն���������ֱ������������ع���$n��", 420, -5, 550,300},
	};
		
	int level = 0;

	for(int i=4; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("zhanjiang_jue", 1))
		{
			//����װ���м���
			level = random(i);
			if( EQUALSTR(me->query_skill_mapped("parry"), "zhanjiang_jue") )
			{
				m_actions.set("action", action[level].action);
//				m_actions.set("force", action[level].force);
				m_actions.set("dodge", action[level].dodge);
				m_actions.set("damage", action[level].damage);
			}
			else
			{
				m_actions.set("action", action[level].action);
				m_actions.set("force", 1);
				m_actions.set("dodge", 1);
				m_actions.set("damage", 1);
			}
			break;
		}
	}		
	return & m_actions;
}


virtual int valid_enable(string usage) 
{ 
	return usage=="club" ||  usage=="parry" ||  usage=="sword"  ||  usage=="blade";
}

int valid_learn(CChar * me)
{	
	if(me->query_skill("zhanjiang_jue", 1) < 240)
		return notify_fail("�����Ϊ̫ǳ,�޷�������а���!");
	
	if (me->query("max_mp") < 70)
		return notify_fail("�������������");
	
	if(me->query("str") < 25 || me->query_str() < 40)
		return notify_fail("���������˵Ĳ�,��ն������ʲô�ã��ؼ�����ȥ�ɣ���");
	
	return notify_fail("׳־���ͺ�²�⣬Ц̸������ūѪ��");
}

int practice_skill(CChar * me)
{
	if(me->query_skill("zhanjiang_jue", 1) < 240)
		return notify_fail("�����Ϊ̫ǳ,�޷�������а���!");

	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())
		|| (DIFFERSTR(weapon->querystr("skill_type"), "club")
		 && DIFFERSTR(weapon->querystr("skill_type"), "sword")
		 && DIFFERSTR(weapon->querystr("skill_type"), "blade")) )
		return notify_fail("��ʹ�õ��������ԡ�");

			if ( me->query_skill("zhongpingqiang", 1) < 100)
		return notify_fail("�����ƽǹ�����������޷���ϰն������");
			if ( me->query_skill("wuhuduanmendao", 1) < 100)
		return notify_fail("����廢���ŵ������������޷���ϰն������");
		        if ( me->query_skill("changquan", 1) < 100)
		return notify_fail("��ĳ�ȭ�����������޷���ϰն������");
	if (me->query("hp") < 200)
		return notify_fail("���������˵Ĳ��ն������ʲô�ã��ؼ�����ȥ�ɣ�");
	me->receive_damage("hp", 50);
	return 1;
}

//perform 
static int do_ding(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if( !target || !me->is_fighting(target) )
		return notify_fail("ǧ��ն��ֻ�ܶ�ս���еĵо�ʹ�á�");

	if(me->query_skill("zhanjiang_jue", 1) < 300)
		return notify_fail("����似������죬����ʹ��ǧ��ն����");
	weapon = me->query_weapon();
    if (! weapon
		||  (DIFFERSTR(weapon->querystr("skill_type"), "club")
		&& DIFFERSTR(weapon->querystr("skill_type"), "sword")
		&& DIFFERSTR(weapon->querystr("skill_type"), "blade")))
		return notify_fail("��ʹ�õ��������ԡ�");
	
    if(  me->query_skill("zhongpingqiang", 1) < 100 &&
		me->query_skill("wuhuduanmendao", 1) < 100 )
		return notify_fail("����似������죬����ʹ��ǧ��ն����");

	if(EQUALSTR(weapon->querystr("skill_type"), "club") && DIFFERSTR(me->query_skill_mapped("club"), "zhanjiang_jue"))
		return notify_fail("�����е����������ڣ�");
	if(EQUALSTR(weapon->querystr("skill_type"), "sword") &&	DIFFERSTR(me->query_skill_mapped("sword"), "zhanjiang_jue"))
		return notify_fail("�����н����������ڣ�");
	if(EQUALSTR(weapon->querystr("skill_type"), "blade") &&	DIFFERSTR(me->query_skill_mapped("blade"), "zhanjiang_jue"))
		return notify_fail("������ǹ��ǹ�����ڣ�");

//	if( EQUALSTR(me->query_skill_mapped("parry"), "zhanjiang_jue") )
//		return notify_fail("һ��ֻ���мܣ�����չ�ֳ�ɱ������ǧ��ն���Ĳ������飿");

    if(  me->query("mp" ) < 200 )
		return notify_fail("����������̫��������ʹ��ǧ��ն����");
	
    msg =   "$N���һ���������һ����ս���·�һ���$n���������\n" ;
	
    if (random(me->query_skill("force")) > target->query_skill("force")/2 )
    {
		me->start_busy(2);
		
		int damage =  me->query_skill("zhongpingqiang", 2) +  me->query_skill("wuhuduanmendao",2);
		//(ȫ�潣������+�����ڹ�)
		
		damage = damage/3 + random(damage/2);
		
		target->receive_damage("hp", damage);
		target->start_busy(4);
		me->add("mp", -100);
		
		msg +=  "$n�߸߷��������߰����˺�ͬʱ��������߸ߵ���Ѫ���������һ�ɿ���" ;
    }
    else
    {
		me->start_busy(3);
		msg +=  "����$p������$P����ͼ��бԾ�ܿ���" ;
    }

    message_vision(msg.c_str(), me, target);
    return 1;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp

/**************************************
//zhongping-qiang.c ��ƽǹ��

//#include "ansi.h"

inherit SKILL;

mapping *action = ({
([	"action": "$N˫��һ�𣬾���ǰ�죬ʹ��һ�С���ƽ�޵С�������$wƽƽֱ��������$n��$l",
	"force" : 100,
	"dodge": -3,
	"damage": 280,
	"skill_name" : "��ƽ�޵�",
	"damage_type": "����"
]),
([	"action": "$N����$w������ת���������������¶ף�����һ�С�ҹ��̽����������$n��$l��ȥ",
	"force" : 140,
	"dodge": -5,
	"damage": 250,
	"skill_name" : "ҹ��̽��",
	"damage_type": "����"
]),
([	"action": "$N����$w������һ��ǹ����һ�С����߳�������$n������ȥ",
	"force" : 180,
	"dodge": -10,
	"damage": 220,
	"skill_name" : "���߳���",
	"damage_type": "����"
]),
([	"action": "$Nһ�С�������ǹ��������$w����СȦ��ȥ$n�ĺ��У�����$w΢̧��ָ��$n��$l",
	"force" : 220,
	"dodge": -5,
	"damage": 200,
	"skill_name" : "������ǹ",
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="club" ||  usage=="parry"; }

mapping query_action(object me, CContainer * weapon)
{
	return action[random(sizeof(action))];
}

int valid_learn(object me)
{
	if (me->query("max_mp") < 70)
		return notify_fail("�������������");
	return 1;
}

int practice_skill(object me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
	||  DIFFERSTR(weapon->querystr("skill_type"), "club"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if (me->query("hp") < 50)
		return notify_fail("���������������ƽǹ����");
	me->receive_damage("hp", 20);
	return 1;
}

*****************************/
