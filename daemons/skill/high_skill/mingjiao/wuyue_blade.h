
// wuyue_blade.h ���µ���
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSwuyue_blade);

virtual void create()
{
	set_name( "���µ���");

	Magic_t * magic;

	magic = add_magic("jiao", do_jiao);
	magic->name = "���־�";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenghuo_shengong") || EQUALSTR(arg, "jiuyang_shengong"))
		return 1;

	return notify_fail("���µ���������ʥ�������ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N����$w��ӣ�һ�С���ȥ������������һת��һ����$n��$l��ȥ",100 , -10, 0,0 ,"����",},
		{"$Nһ�С�������¥���������㣬$wһ��һ�ƣ�ƽ�л���$n������",130 , -10, 8, 10,"����",},
		{"$N�鲽����һ�С��ƴ����¡�������һ������ն��$n", 160, -5, 20, 20,"����",},
		{"$Nһ�С��ζ���ɽ����$w���϶��»���һ���󻡣���ֱ����$n", 190, 5, 35, 34,"����",},
		{"$N�ಽš��һ�С����Ƕ��ǡ����������У�$w����$n���ؿ�", 220, 10,50 ,45 ,"����",},
		{"$N����$w��ʹ��һ�С��¹����졹������ƬƬ��Ӱ����������$n", 240, 15, 60, 59,"����",},
		{"$Nһ�С����½��ԡ���ֻ�����쵶����˸�����ص�Ӱ��$n��ȫ��ӿȥ", 320, 20, 90, 80,"����",},
	};
 		
	int level = 0;
	
	for(int i=7; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("wuyue_blade", 1))
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
    if ( me->query("max_mp") < 80)
		return notify_fail("�������������");
	if ( me->query_skill("blade", 1) < 30)
		return notify_fail("��ĵ�������̫ǳ��");
    	if ( me->query_skill("shenghuo_shengong", 1) < 50)
		return notify_fail("���ʥ���񹦻��̫ǳ��");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("��ʹ�õ��������ԡ�");
    if ( me->query("hp") < 50)
		return notify_fail("����������������µ�����");
    me->receive_damage("hp", 25);
    return 1;
	
}

//perform 
static int do_jiao(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * my_w, * target_w;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || ! me->is_fighting(target) )
		return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á����־�����");

	if(! (my_w = me->query_weapon()) 
		|| DIFFERSTR(my_w->querystr("skill_type"), "blade"))
		return notify_fail("����������ԡ�");

	if(! (target_w = target->query_weapon()) )
		return notify_fail("%s�ǿ��֣������ʲô��", target->name());

	target_w = target->query_weapon();
	if( EQUALSTR(target_w->querystr("skill_type"), "throwing") )
		return notify_fail("%s�õ��ǰ�����������ô�ʣ�", target->name());

	if( target->is_busy() )
		return notify_fail("%sĿǰ��ƣ���мܣ��ӽ�������",target->name() );
	
	if(  me->query_skill("wuyue_blade", 1) < 50 )
		return notify_fail("������µ���������죬����ʹ�á��¡��־���");

	if(DIFFERSTR(me->querystr("family/family_name"), "����") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( me->query("mp") < 50)		//add by Lanwood 2000-12-26
		return notify_fail("����������㡣");

	me->add("mp", -50);

	msg =  "$N���һ����չ�����µ������¡��־�����������������ͼ����$n�ı��С�\n";
	me->start_busy(3);
	
	if(target_w->query("no_duo") && !random(3))
		msg += "����$n������$N����ͼ����û���ϵ���\n";
	else
	{
		char msg1[40];
		if( random(me->query_combat_exp()) > target->query_combat_exp()/2 ) 
		{
			if( target_w->weight() > random(my_w->weight()) ) 
			{
				msg += "���$p���еĵ��б�$Pǿ��һ�£���Ҳ���ղ�ס���������ַɳ���"  ;
				if(target_w->query("no_duo") )
				{
					target->command(snprintf(msg1, 40, "unwield %ld", target_w->object_id()));
				}
				else
				{
					target_w->move(target->environment());
					target->start_busy(  me->query_skill("wuyue_blade", 1) / 40 );
				}
			}
			else
			{
				if(target_w->query("no_duo") )
				{
					msg += "���$p���еĵ��б�$Pǿ��һ�£���Ҳ���ղ�ס���������ַɳ���"  ;
					target->command(snprintf(msg1, 40, "unwield %ld", target_w->object_id()));
				}
				else
				{
					msg += "���$p���еı��б�$P��ǿ��һ�����˸����飡"  ;
					target_w->move(target->environment());
					
					char tmp[40];
					target_w->set_name( snprintf(tmp, 40, "%s����Ƭ", target_w->name()) );
					target_w->set("value", 0l);
					target_w->del("apply");
					DESTRUCT_OB(target_w, "wuyun_blade::do_jiao");
					target->start_busy(  me->query_skill("wuyue_blade", 1) / 40 );
				}
			}
		} 
		else 
		{
			msg += "����$pͨ��������мܣ���û����$P�ļ�ı�óѡ�"  ;
		}
	}
	message_vision(msg.c_str(), me, target);

	return 1;
}

SKILL_END;




