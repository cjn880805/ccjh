//xiaoyao_jianfa.h ��ң����

SKILL_BEGIN(CSxiaoyao_jianfa);

virtual void create()
{
	set_name( "��ң����");
	set("valid_force", "beiming_shengong");
	Magic_t * magic;
	set("diff",150);
	
	magic = add_magic("baji", do_baji);
	magic->name = "���ư˻�";
	magic->mp = 1300;
	magic->ap = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "beiming_shengong"))
		return 1;
	
	return notify_fail("��ң���������뱱ڤ�����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct{
			char action[100];
			int force,dodge, damage ;
			char damage_type[5];
	}action[16]={
		{"$N����$w������ɢ��һ�С����Ʊ��¡����������ƣ�������$n��$l�����˲�֪�����Ժη���",100,-30,200,"����"},
		{"$N���ΰεض�������$w�趯�����콣��ɭɭ��һ�С������ѩ������$n��$l��",140,-30,220,"����"},
		{"$N��Х������ʹһ�С������ϡ���˫����������$n��$l��",180,-30,180,"����"},
		{"$N������$w���μ������У�һ�С�է��է������$n��ȥ��",220,-40,160,"����"},
        {"$N�趯$w��һ�С���������������������������磬�˽���һ������$n��$l��",300,-30,250,"����"},
       	{"$Nһ�С�����δ�衹������Ʈ�������̣�������$n��$lһ����",330,-40,240,"����"},
		{"$Nʹ��һ�С���Σ������������������ˮ������$w���������ն��$n��$l��",350,-30,230,"����"},
		{"$N����Ծ������$w�����佣����һ�С���ֹ���ڡ���ס$n��ȫ��",400,-20,220,"����"},
		
		{"$HIW$NƮȻ�г���֮�⣬һ�С������貨������$n��$l��",100,-30,200,"����"},
		{"$HIW$N$w�������ó����콣Ӱ�����Ŵشأ�һ�С�������������$n$l��ȥ��",140,-20,220,"����"},
		{"$HIW$N����һ�Σ�һ�С���Ū���硹��$n$l�̳�һ����",180,-30,180,"����"},
		{"$HIW$Nʹһ�С�����ݺٱ��������$w��һ��һ�����$n��$l��",220,-20,260,"����"},
        {"$HIW$N��$wƾ��һָ��һ�С��������ס�����$n��$l��",300,-10,250,"����"},
       	{"$HIW$N���е�$wһ�С��������ࡹ������ϸ�꣬�޿ײ���Ĵ���$n��$l��",330,-10,240,"����"},
		{"$HIW$N����$w����һ�֣�ʹһ�С��ദ�ٳ������ֶ�׼$n$lһ����ȥ��",350,-20,230,"����"},
		{"$HIW$Nһ������$w��ʹ��������ַɡ������ɵð������ˣ�����Ԧ������$n��$l�̳�һ����",400,-10,220,"����"},
	};
		
	int level = random(8);

	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("damage", action[level].damage);

	if (me->query_temp("teapot/baji"))
	{
		level=me->query_temp("teapot/baji")+7;
		m_actions.set("action", action[level].action);
		m_actions.set("force", action[level].force);
		m_actions.set("dodge", action[level].dodge);
		m_actions.set("damage", action[level].damage);
	}

	if ( !wizardp(me) && (DIFFERSTR((me->environment())->querystr("area"), "��ң") ||!me->query("xy/save")))
	{
		m_actions.set("force", 0l);
		m_actions.set("dodge", 0l);
		m_actions.set("damage", 0l);
	}

	return & m_actions;
}

virtual int valid_enable(string usage) 
{ 
	return usage=="sword" ; 
}

virtual int valid_learn(CChar * me)
{
	return notify_fail("�������޻����٣����ղ�������ң��");
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("�������޻����٣����ղ�������ң��");
}


static int do_baji(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	
	CContainer * env=me->environment();
	CContainer * weapon;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if(! target || ! me->is_fighting(target))		
		return notify_fail("ֻ�ܶ�ս���еĵ���ʹ�ã�");
	
	if ( !wizardp(me) && (DIFFERSTR(env->querystr("area"), "��ң")))
		return	notify_fail("�����ư˻����޷�������ʹ�á�");

	if( !wizardp(me) && !me->query("xy/save"))
		return	notify_fail("�����ư˻����޷�������ʹ�á���");

	//if( !wizardp(me) && !me->query("xy/renwu5_1"))
	//	return	notify_fail("�����ư˻����޷�������ʹ�á���");

	if (! (weapon = me->query_weapon())|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if(me->query_skill("beiming_shengong",1) < 200)
		return notify_fail("��ı�ڤ�񹦹�������������ʹ�á����ư˻���!");

	if(me->query_skill("sword") < 250)
		return notify_fail("��Ļ���������Ϊ����,Ŀǰ������ʹ�á����ư˻�������!");
	
	if (me->query_skill("xiaoyao_jianfa", 1) < 300)
		return notify_fail("�����ң������Ϊ����,Ŀǰ������ʹ�á����ư˻�������!");
	
	if(me->query("mp") < 1300)
		return notify_fail("���������ڲ���, ����ʹ�á����ư˻���! ");

	if(me->query_temp("fight/ap") < 300)
		return notify_fail("���APֵ���ڲ���, ����ʹ�á����ư˻���! ");
	
	if( target->is_busy() )
		return notify_fail("%sĿǰ���Թ˲�Ͼ���ŵ������ɣ�", target->name());
	
	char cmd[255];
	snprintf(cmd, 255,"\n$HIY$N����%sһȦ����������ɳ����ͻȻ����һ���������������⣬һ�С����ư˻�����ס$n��",weapon->name(1));
	message_vision(cmd, me, target);

	me->add_temp("fight/ap",-300);
	
	if( random(me->query_combat_exp()) > target->query_combat_exp() / 4 )
	{
		if(!EQUALSTR(target->query_skill_mapped("dodge"), "lingboweibu"))
		{	
			for(int n = 0; n < 8; n++)
			{
				if( EQUALSTR(me->query_skill_mapped("sword"), "xiaoyao_jianfa") 
					&& ((weapon = me->query_weapon())&& EQUALSTR(weapon->querystr("skill_type"), "sword")))
				{
					me->set_temp("teapot/baji",n+1);
					g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
				}
				else
					break;
			}
			
			me->delete_temp("teapot/baji");
			me->start_busy(4);
			me->add("mp", -1300);
		}
		else
		{
			msg += "$HIM$p���Ī��Ĳ���������$P�����۾�����,���ȼ��ʱ��֪������\n$COM";
			message_vision(msg.c_str(), me, target);
			me->start_busy(6);
			me->add("mp", -1300);
		}
	}
	else
	{
		msg += "$HIM����$p������$P����ͼ����û���ϵ���\n$COM";
		message_vision(msg.c_str(), me, target);
		me->start_busy(4);
		me->add("mp", -1300);
	}
	
	return 1;
}

SKILL_END;