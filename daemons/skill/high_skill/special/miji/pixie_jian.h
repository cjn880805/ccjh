// pixie_jian.h ��а����
//code by oho
//date : 2000-12-06

SKILL_BEGIN(CSpixie_jian);

virtual void create()
{
	set_name( "��а����");
	set("valid_force", "kuihua_xinfa");
	
	Magic_t * magic;

	magic = add_magic("cimu", do_cimu);
	magic->name = "��Ŀ";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("touzi", do_touzi);
	magic->name = "ƴ��";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][255] = {
		{"ͻȻ֮�䣬��Ӱ���ϣ�$n��󻬳����࣬��ʱ�ֻص���ԭ�أ������$N��һ�С�"},
		{"$n�ֱۻ�ת����$N������һ�ƣ�˳������һ�ԡ�"},
		{"$n�����������$N������Ѹ���ޱȵ�һ����˳������һ�ԡ�"},
		{"$n����Ʈ����������ȣ�ת�˼�ת���Ʋ���$N����󣬶����$N��һ�С�"},
		{"$Nֻ����ǰһ�����ƺ�����$n����һ�ϣ����漴�ּ�$n�ص�ԭ�أ�ȴ�ƴ�δ�뿪��"},
		{"$N�۾�һ����$n��û����Ӱ��ͻȻ$n���������һ��$N��ͷ������Ծ����"},
		{"$n��ȻһЦ������֮����$N����֪����Ǻã�ͣס�˹�����"},
	};
	return dodge_msg[random(7)];
}

virtual const char * query_parry_msg(CContainer * weapon)
{
	static char parry_msg[][255] = {
                {"$n��һ������һ������һ������һ������$N���������������������²����������ް��������"},
		{"$n��������������ʳָ��������$N����Ŀ���̣��������ܾ��˵Ĵ򷨡�"},
		{"$n�����������$N������Ѹ���ޱȵ�һ����˳������һ�ԡ�"},
		{"$n���ִ�Ĵָ��ʳָ��סһ���廨�룬����һ�٣���ס���ƣ�$N����ʽ��ʹ����ȥ��"},
		{"$Nֻ����ǰһ�����ƺ�����$n����һ�ϣ����漴�ּ�$n�ص�ԭ�أ�ȴ�ƴ�δ�뿪��"},
		{"$n���ҵ���أ�Ժ�����Ͼ��������$N���ޣ����ù��򣬺ù���"},
		{"$n�ӻ���ȡ��һ��ѩ�׵ĳ���������Ĩ��Ĩ������ֱ������Ϸ̨�ϵĻ�����$Nһ������ͣס���Լ�����ʽ��"},
	};
	return parry_msg[random(7)];
}


virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"ͻȻ֮�䣬��Ӱ���ϣ�$N��󻬳����࣬��ʱ�ֻص���ԭ��", 80, -40, 40, 0, "����",},
		{"$N�����������$n������Ѹ���ޱȵ�һ����$n��Щ�����Լ�С��", 90, -40, 50,0 , "����",},
		{"�����$N�����ϣ��ڵ�$n�������Ծ��ԭ��", 80, -40, 70, 25, "����",},
		{"$NͻȻ���з�һ�䣬$w�����������ʽ������ס�$n����֮�з������", 80, -40, 50, 5, "����",},
		{"$N����Ʈ����������ȣ�ת�˼�ת���Ʋ���$n�����", 90, -60, 90, 10, "����",},
		{"$Nһ����Ц������Ｒ����ǰ��һ˲֮�䣬��$n����Ѳ���һ�ߣ�$w�漴�ݳ�", 140, -60, 100, 10, "����",},
		{"$N�ȵ������ã������㼴�γ�$w�����ִ̳�������ת����ȥ", 80, -60, 50, 0, "����",},
		{"$nֻ����ǰһ�����ƺ�����$N����һ�ϣ����漴�ּ�$N�ص�ԭ�أ�ȴ�ƴ�δ�뿪", 140, -60, 100, 20, "����",},
		{"$N����ˣ�$n��׷������ͻȻ��$N����$n��ǰ������$wֱָ$n��$l", 60, -70, 40, 5, "����",},
		{"$N��س嵽$n��ǰ������$wֱ��$n���ۣ�$n��æ�мܣ�����$N��$wͻȻת��", 200, -70, 100, 45, "����",},
		{"$N����Ծ��$ņ��һ����������$N����ֱ����£�����$w����$n��$l", 340, -70, 105, 64, "����",},
		{"$N��֦�Ͱڣ�$n��ǰ�·�ͻȻ�������߰˸�$N���߰�ֻ$wһ�����$n",380 , -70, 130, 79, "����",},
	};
	
	int level = 0;
	
	for(int i=12; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("pixie_jian", 1))
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
    return usage == "sword" || usage == "dodge" || usage == "parry"; 
}

virtual int valid_learn(CChar * me)
{
	return notify_fail("��а����ֻ��ͨ����ϰ���������䡷��ѧϰ��");
}

//perform 
static int do_cimu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || !me->is_fighting(target))		//add by Lanwood 2000-12-26
		return notify_fail("ֻ�ܶ�ս���еĵ���ʹ�á�");

	if( me->query_dex() < 25)
		return notify_fail("�����ֲ�����,����ʹ����һ����!");
	
	if( me->query_skill("kuihua_xinfa",1) < 80)
		return notify_fail("������ķ��Ĺ�����������ʹ�ô�Ŀ!");

	if(DIFFERSTR(me->querystr("family/family_name"), "�������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( me->query_skill("pixie_jian", 1) < 80)
		return notify_fail("��ı�а����Ϊ����,Ŀǰ������ʹ�ô�Ŀ����!");
	
	if( me->query("mp") < 300)
		return notify_fail("���������ڲ���, ����ʹ�ô�Ŀ! ");
	
	if( target->is_busy() )
		return notify_fail("%sĿǰ���Թ˲�Ͼ������ɱ����������ʱ�� ",target->name() );
	
	msg =   "$N����һ�Σ�������Ȼͻ����Ȼ���˻�ԭ�ء�\n";
	
	if( random(me->query_combat_exp()) >  target->query_combat_exp() / 4 )
	{
		msg +=    "ֻ��$p�����Һ�����������ϸϸ��Ѫ���������� "  ;
		target->start_busy(me->query_temp("apply/pro_��Ŀ")+ me->query_skill("pixie_jian",1) / 20 + 2);
		me->add("mp", -100);
		if(random(4))
		{
			me->improve_skill("pixie_jian", 1);
		}
	}
	else
	{
		msg +=   "����$p������$P����ͼ������һԾ�����˿�ȥ��"  ;
		me->start_busy(4);
		me->add("mp", -50);		// add by lanwood 2000-12-26
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

static int do_touzi(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	CContainer * weapon;
	string msg;

	if( !target || !me->is_fighting(target) )
		return notify_fail("ƴ��ֻ�ܶ�ս���еĶ���ʹ�á�");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("װ��������ʹ��ƴ����");
		
	if( me->query_skill("pixie_jian", 1) < 100 )
		return notify_fail("���а����������죬ʹ����ƴ����");

	if(DIFFERSTR(me->querystr("family/family_name"), "�������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	                        
	if( me->query_skill("kuihua_xinfa", 1) < 100 )
		return notify_fail("������ķ���򲻹���ʹ����ƴ����");
			
	if( me->query("max_mp") < 600 )
		return notify_fail("��������Ϊ���㣬�޷�����������");

	if (me->query("mp") < 400)
        return notify_fail("����������������û�ܷ������У�");

	if(weapon->query("index"))
	{
		if(weapon->query("����")>0)
			me->add_temp("apply/damage", -weapon->query("����"));
		if(me->query_temp("apply/damage")<0)
			me->set_temp("apply/damage",0l);
	}
			
	msg = "$HIR$N��������Թ����ͻȻ����ָһ�������б�����$n�����ȥ��\n";
	if(target->query_temp("apply/no_ƴ��")&& (random(2)||target->query("bigboss")))
	{
		msg += "����$n����һЦ����������";
		me->start_busy(4);
	}
	else
	{
		
		if ( random(me->query_combat_exp()) > target->query_combat_exp()/3 )
		{
			me->start_busy(2);
			target->start_busy(random(3));
			int damage = target->query("hp");
			target->receive_damage("hp", damage - 10);
			target->receive_wound("hp", damage/2);
			msg += "$HIR$n��æ���������Ѿ��������ˣ�ֻ��һ���ʹ����Ѫ�ɽ���Ҳ��֪���������";
			me->set("mp", 100);
		} 
		else
		{
			me->start_busy(2);
			msg += "����$n����һЦ����������";
		}
	}
	
	weapon->move(me->environment());
	message_vision(msg.c_str(), me, target);
    
	return 1;
}

SKILL_END;




