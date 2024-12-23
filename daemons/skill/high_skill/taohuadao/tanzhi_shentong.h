
// tanzhi_shentong.h ��ָ��ͨ
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CStanzhi_shentong);

virtual void create()
{
	set_name( "��ָ��ͨ");
	set("valid_force", "bibo_shengong");

	set("diff",110);

	Magic_t * magic;

	magic = add_magic("hui", do_hui);
	magic->name = "�ӳⷽ��";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("jinglei", do_jinglei);
	magic->name = "��ָ����";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("hua", do_hua);
	magic->name = "���컨��";
	magic->mp = 350;
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
		{"$N��ָ���˸���Ȧ��һʽ�������ѵء����϶��»���$n��ȫ��", 320, -5, 35, 20,"����",},
		{"$N���ƻ��أ�һ�С��������ơ�����ָ��������ָ��$n�Ķ�ͷ", 280, 20, 20, 0,"����",},
		{"$N˫�������һʽ��ǧ����ָ������ָ��$n��$l", 190, 15,15 , 0,"����",},
		{"$N����һ̾��һ�С���ָ��������˫�ֻó�����ָӰ������$n��$l", 380, -5, 40, 50,"����",},
		{"$Nһʽ��Цָ���ϡ���������ʽ����ָ����һ��ָ�����$n��$l", 240, 15, 10, 10,"����",},
		{"$N�ó�������һָ�����ȫ��������һָ����$n��$l", 420, -40, 30,80 ,"����",},
	};

	int level = me->query_skill("tanzhi_shentong", 1);
	
	for(int i=6; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
/*			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
*/
			m_actions.set("force", (me->query("skill_pro/��ָ��ͨ/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/��ָ��ͨ/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/��ָ��ͨ/damage")+100) * action[level].damage/100);
	
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "finger") || (usage == "parry");
}


virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/��ָ��ͨ/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/��ָ��ͨ/force"));
			if(me->query("skill_pro/��ָ��ͨ/force_point")>=level_point)
			{
				me->add("skill_pro/��ָ��ͨ/force",1);
				me->set("skill_pro/��ָ��ͨ/force_point",1);
				tell_object(me,"\n$HIR��ĵ�ָ��ͨ����ڹ������ڻ��ͨ�ˡ�\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/��ָ��ͨ/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/��ָ��ͨ/dodge"));
			if(me->query("skill_pro/��ָ��ͨ/dodge_point")>=level_point)
			{
				me->add("skill_pro/��ָ��ͨ/dodge",1);
				me->set("skill_pro/��ָ��ͨ/dodge_point",1);
				tell_object(me,"\n$HIR��ĵ�ָ��ͨʹ�õø��ӵ���Ӧ���ˡ�\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/��ָ��ͨ/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/��ָ��ͨ/damage"));
			if(me->query("skill_pro/��ָ��ͨ/damage_point")>=level_point)
			{
				me->add("skill_pro/��ָ��ͨ/damage",1);
				me->set("skill_pro/��ָ��ͨ/damage_point",1);
				tell_object(me,"\n$HIR��ĵ�ָ��ͨ���������ˡ�\n");
			}
		}
	}
	return "";
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon()  )
        return notify_fail("����ָ��ͨ������֡�");
    if ( me->query_skill("bibo_shengong", 1) < 20)
        return notify_fail("��ı̲��񹦻�򲻹����޷�ѧ��ָ��ͨ��");
	if ( me->query("max_mp") < 100)
        return notify_fail("�������̫�����޷�����ָ��ͨ��");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
        return notify_fail("���������������Ϣһ�������ɡ�");
	if ( me->query("mp") < 20)
        return notify_fail("���������������ָ��ͨ��");
    me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
	
}


//perform 
static int do_hui(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *) ob;

	int skill = me->query_skill("tanzhi_shentong",1);
	
	if( !target || ! me->is_fighting(target))
		return notify_fail("���ӳⷽ�١�ֻ����ս����ʹ�á�");

	if(DIFFERSTR(me->querystr("family/family_name"), "�һ���") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if ( me->query_weapon())
		return notify_fail("��ʹ����������");
	
	if( skill < 50)
		return notify_fail("��ĵ�ָ��ͨ�ȼ�����, ����ʹ�á��ӳⷽ�١���");
	
	if( me->query("mp") < 150 )
		return notify_fail("��������������޷����á��ӳⷽ�١���");
	
	msg =   "$Nʹ����ָ��֮ͨ���ӳⷽ�١�, ��ʱ���ھ��Ⱪ�䣬\n";
	
	int di = me->query_skill("tanzhi_shentong") / 15;
	int dp = target->query_skill("force") / 10;
	if( di < 1 )
		di = 1;
	if( dp < 1 )
		dp = 1;
	if( random(skill) > (dp - di) )
	{
		me->add("mp",-150);
		msg += "$nֻ������ǰһ��������Ѩ��΢΢һʹ��ȫ��������й������"  ;
		
		int wound = -(skill+random(200)*3);
		if( target->query("mp") < wound)
			wound = target->query("mp");
		target->add("mp", wound);
		target->add("hp", wound / 5);
		target->start_busy(2);
		me->start_busy(2);
	}
	else
	{
		msg += "����$n�Ŀ�����$N����ͼ�����̲�ȡ���ƣ�ʹ$P�ġ��ӳⷽ�١�û�������á�" ;
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);
	return 1;
}

static int do_jinglei(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *) ob;

	int skill = me->query_skill("tanzhi_shentong",1);
	
	if( !target || !me->is_fighting(target))
		return notify_fail("����ָ���ס�ֻ����ս����ʹ�á�");
	
	if ( me->query_weapon())
		return notify_fail("��ʹ����������");

	if(DIFFERSTR(me->querystr("family/family_name"), "�һ���") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( skill < 120)
		return notify_fail("��ĵ�ָ��ͨ�ȼ�����, ����ʹ�á���ָ���ס���");
	
	if( me->query("mp") < 150 )
		return notify_fail("��������������޷����á���ָ���ס���");
	
	msg =   "$Nʹ����ָ��֮ͨ����ָ���ס�, ��ʱ���ھ��Ⱪ�䣬\n";
		
	LONG dp = target->query_combat_exp();
	if( dp < 1 )
		dp = 2;
	if( random(me->query_combat_exp()) > dp/2)
	{
		me->add("mp",-150);
		msg += "$nֻ������ǰһ��������Ѩ��΢΢һʹ��ȫ��������й������" ;
		if (  (weapon = target->query_weapon()))
		{
			if(weapon->query("no_duo") && !random(3) )
				msg += "����$n�Ŀ�����$N����ͼ�����̲�ȡ���ƣ�ʹ$P�ġ���ָ���ס�û�������á�" ;
			else
			{
				msg += "ͬʱ����һ�飬����";
				msg += weapon->name();
				msg += "���ֶ�����"  ;
				weapon->move(me->environment());
			}
		}
		
		int wound = 300 + random(200);
		if( target->query("mp") < wound)
			wound = target->query("mp");
		target->add("mp", -wound);
		target->receive_wound("hp", wound/5);
		target->start_busy(5);
		me->start_busy(2);
	}
	else
	{
		msg += "����$n�Ŀ�����$N����ͼ�����̲�ȡ���ƣ�ʹ$P�ġ���ָ���ס�û�������á�" ;
		me->start_busy(3);
	}
	message_vision(msg.c_str(), me, target);
	
	//if(!target->is_fighting(me)) 		target->kill_ob(me);
	return 1;
}

static int do_hua(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	int damage, num;

	if(ob && ob->is_character())
		target = (CChar *) ob;

	if (!me->query("����/thd/hua"))
		return notify_fail("����Ȼ��˵�������컨�꡹��һ�У�����ȴδ���ڡ�\n");
	
	int skill = me->query_skill("tanzhi_shentong",1);
	
	if( !target || !me->is_fighting(target))
		return notify_fail("�����컨�꡹ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "throwing"))
		return notify_fail("�����컨�꡹����װ����������ʹ�á�\n��");

	if ((num = weapon->Query_Amount()) < skill / 20) 
		return notify_fail("�������ͱ��ң���������İ����Ѿ�����ʹ�á����컨�꡹��Ҫ���ˣ�\n");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "�һ���"))
		return notify_fail("�����컨�꡹��ʹ�ü���ֻ���ڸ��һ����ĵ��ӡ�");
	
	if( skill < 120)
		return notify_fail("��ĵ�ָ��ͨ������죬�޷�ʹ�á����컨�꡹��");
	
	if( me->query("mp") < 450 )
		return notify_fail("��������������޷����á����컨�꡹��");
	
	char msg[255],tmp[80];
	message_vision(snprintf(msg, 255, "$CYN$N˫���ڱ�����һץ��ץ��%s%s%s��������ָ������ص��˳�ȥ��$nֻ����ǰ�ƺ�����һ�������꣡",
		chinese_number(skill/20,tmp),weapon->querystr("base_unit") , weapon->querystr("name")),me,target);
	
	damage = skill * 4 + me->query_skill("bibo_shengong", 1)*2;
	damage += random(damage / 3);
	if (random(me->query("combat_exp")) > target->query("combat_exp") / 3)
	{
		message_vision("$HIR$n���������������ۡ��ؼ������������������У�\n", me, target);
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage / 3);
	} 
	else
	{
		message_vision("$HIW$n�ŵø�æ��ͷ��������Ǳ������Ա�һ�������ſ����ض��˹�ȥ��\n", me, target);
	}

	me->add("mp", -350);
	me->start_busy(3);
	if (num == skill / 20)
	{
		destruct(weapon);
		tell_object(me, snprintf(msg, 255,"\n���%s�����ˣ�\n" ,weapon->querystr("name")));
	}

	((CItem *)weapon)->add_amount(-(skill/20));
	
	return 1;
}

int valid_combine(string combo) { return combo=="lanhua_shou"; }

SKILL_END;
