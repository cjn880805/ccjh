// yinsuo_jinling.h ��������
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSyinsuo_jinling);

virtual void create()
{
	set_name( "��������");
	
	Magic_t * magic;
	
	magic = add_magic("dian", do_dian);
	magic->name = "��Ѩ";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("feng", do_feng);
	magic->name = "��Ѩ";
	magic->mp = 800;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "yunv_xinjing") || EQUALSTR(arg, "yunv_xinfa"))
		return 1;
	
	return notify_fail("�����������͹�Ĺ���ڹ�����ϡ�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"����$w,ͻȻ֮��,˿������,��һ����������$n",45 , 40, 20, 0, "��Ѩ",},
		{"$N���ϵ�$w�ܳ�����$n������Ѹ���ޱȵ�һ�㣬", 55, 30, 25, 10, "��Ѩ",},
		{"�����$N�����ϣ�$w�Ƶ�$n����󣬼���$n��$l", 70, 60, 35, 20, "��Ѩ",},
		{"$NͻȻ���з�һ�䣬$w�����������ʽ������ס�$n����֮�з������", 90, 40, 50, 30, "��Ѩ",},
		{"$N����Ʈ����������ȣ�ת�˼�ת����Ȼ$w����$n��$lѨ��", 115, 40, 70, 60, "��Ѩ",},
		{"$Nһ����Ц�������Ծ,����$w������Ȱ����$n��$l", 145, 50, 95, 75, "��Ѩ",},
		{"$N����$nת�˼���Ȧ,����$w�����ͳ�,����$n��$l", 180, 30, 125, 90, "��Ѩ",},
		{"$nֻ����ǰһ�����ƺ�����$N����һ�ϣ���$Nȴ�ƴ�δ�뿪,��$w�ѵ���$n��ǰ", 190, 80, 110,100 , "��Ѩ",},
		{"$N����ˣ�$n��׷������ͻȻ������һ̧������$wֱ��$n��$l", 200, 40, 100, 120, "��Ѩ",},
		{"$n��Ҫ�嵽$N��ǰ��$N����$wֱ��$n�ؿ�̴��Ѩ��$n��æ�мܣ�����$N��$wͻȻת�����$l", 215, 4, 145, 140, "��Ѩ",},
		{"$N����$w���裬$n��ǰ�·�ͻȻ�������߰���$wһ�����$n", 220, 60, 195, 150, "��Ѩ",},
	};
	int level = 0;
	
	for(int i=11; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("yinsuo_jinling", 1))
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
	return (usage == "whip") ;
}

virtual int valid_learn(CChar * me)
{
	CContainer * weapon;
	if( me->query("max_mp") < 500 )
		return notify_fail("����������㣬û�а취����������, ����Щ���������ɡ�");
	
	if (me->query_skill("yunv_xinjing", 1) < 50)
		return notify_fail("�����Ů�ľ����̫ǳ��");
	
	if ( !(weapon = me->query_weapon())
        || DIFFERSTR(weapon->querystr("skill_type"), "whip") )
		return notify_fail("�������һ��������������������塣");
	
	if (me->query_skill("tianluo_diwang",1)< 50)
		return notify_fail("������޵����ƻ���������.��������������.");
	
	return 1;
}

//lanwood ���ӡ�ԭ����ϰ������������ 2001-06-30
int practice_skill(CChar * me)
{
	CContainer * weapon;
	
    if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "whip"))
        return notify_fail("��ʹ�õ��������ԡ�");
    if (me->query("hp") < 30)
        return notify_fail("��������������������塣");
    me->receive_damage("hp", 25);
    return 1;
}

//perform 
static int do_dian(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target	||	!me->is_fighting(target) )
		return notify_fail("��Ѩֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if (!(weapon = me->query_weapon()) 
		|| DIFFERSTR(weapon->querystr("base_name"), "ring_whip"))
		return notify_fail("������û�н��������޷�ʩչ��һ������");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( me->query_skill("yinsuo_jinling", 1) < 120 )
		return notify_fail("����������岻�����죬��������Ѩ");
	
	if( me->query_skill("tianluo_diwang",1)<100)
		return notify_fail("������޵����ƻ���㣬�ַ����������");
	if( me->query_skill("yunv_xinjing",1)< 135)
		return notify_fail("����ڹ���Ϊ̫������޷����Ѩ��");
	
	if( me->query("max_mp")<1000)
		return notify_fail("�������������ʩչ��Ѩ����.");
	
	if ( me->query("mp") < 300 )
		return notify_fail("�������������Ѩ��");
	me->add("mp", - 500);
	
	msg = "$N���Ͻ���ɳ�,ʹ������������ϳ˵�Ѩ����,ֱȡ$p�Ĵ�׵Ѩ��\n";
	
	if(target->query_temp("apply/no_���־�")&& (random(2)||target->query("bigboss")))
	{
		switch(random(9))
		{
		case 0:
			msg +="$p���һ�����Գ�������ǿ�����ֳ��У���࣡���һ�����죬��ָ�ཻ��$p����΢�Σ������ֽ��";
			break;
		case 1:
			msg +="$pһ����Х��˫�ֻû���������Ӱ����ס��ǰ��ֻ�����͡���һ������Ӱ������$p�Ѿ������ɫ�Ұס�";
			break;
		case 2:
			msg += "$pһ����Ц�������仯�˼����������˶�Ŀ��һʱ��$N�޷�������\n";
			break;
		case 3:
			msg += "$pͻȻ���Ʈȥ���������磬��$N��һָ���еĺ�̱仯�޴�ʩչ��\n";
			break;
		case 4:
			msg += "$p��ɫ���أ��������ƣ���׾��׾����Ȼ��$N�޴����֣�ֻ����ָ��\n";
			break;
		case 5:
			msg += "$p������м����Цһ����˫�����������ޱȣ���$Nֻ�ܻ����Ծȡ�\n";
			break;
		case 6:
			msg += "$p��ҡ�һΣ�����ȥ�����·���ƫƫ�����$N��һ����\n";
			break;
		case 7:
			msg += "$pһָ���������ȥ����Ҳ�Ƿ��ž���ָ����$Nһ�������ƶٻ���\n";
			break;
		case 8:
			msg += "$p��ס����������ע��������ס��$N�Ľ�����\n";
			break;
		}
		me->start_busy(4);
	}
	else
	{
		ob = target->query_weapon();
		if( random( me->query_skill("force") ) > random( target->query_skill("force") ) )
		{
			me->start_busy(3);
			if (! ob)
			{
				int damage = 0;
				
				if (target->query_skill("dodge") > 200 && random(2) == 0)
				{
					switch (random(2))
					{
					case 0:
						msg +="$p�������˼����ϳ���������û�ܶ����$N�Ľ���������$p��̴��Ѩ�ϣ�$pֻ����һ���������Ե�����ϣ���������˵���������ܡ�";
						damage = 3;
						break;
					case 1:
						msg+="$p����Ʈ�������鶯֮����������Ҫ�Ȳʣ������ۡ���һ��������ܸ$p��ɫɷ�ף�ҡҡ��׹��";
						damage = 5;
						break;
					}
				} 
				else
					if (target->query_skill("force") > 200 && random(2) == 0)
					{
						switch(random(2))
						{
						case 0:
							msg +="$p���һ�����Գ�������ǿ�����ֳ��У���࣡���һ�����죬�����ཻ��$p����΢�Σ������ֽ��";
							damage = 3;
							break;
						case 1:
							msg +="$pһ����Х��˫�ֻû���������Ӱ����ס��ǰ��ֻ�����͡���һ������Ӱ������$p�Ѿ������ɫ�Ұס�";
							damage = 4;
							break;
						}
					} 
					else
					{
						switch(random(2))
						{
						case 0:
							msg +="$p�������У���Ȼ��֪��ܣ����͡���һ����$N�Ľ���������$p�Ĵ�׵Ѩ��,$pȫ������,�����ڵء�";
							//						target->unconcious();
							damage = 5;
							break;
						case 1:
							msg += "$pһת��Ѿ�����˾�ʮ���ֻ���İ취����δ���ü�ʩչ��ֻ�����͡���һ�����ѱ�$N���д�׵Ѩ,$pȫ������,�����ڵء�";
							//						target->unconcious();
							damage = 6;
							break;
						}
					}
					if (damage > 0)
						target->receive_damage("hp", target->query("max_hp") * damage / 24);
					
					message_vision(msg.c_str(), me, target);
					return 1;
			}
			/*		
			if (ob->query("item_make"))
			{
			msg += "$pæ��";
			msg += ob->name();
			msg += "�мܣ�ֻ���û��ھ������ұ����������";
			} 
			else
			{
			msg += "$p��æ�мܣ�ֻ������ž����һ����$p���е�";
			msg += ob->name();
			msg += "�����ѣ�ɢ��һ�أ�";
			ob->move(target->environment());
			string new_name;
			new_name = "�ϵ���";
			new_name += ob->name();
			ob->set_name( new_name.c_str());
			ob->set("value", 0l);
			ob->del("apply");
			}
			target->start_busy(2);
			*/
		} 
		else
		{
			int busy = 0;
			if (target->query_skill("dodge") > 200 && random(2) == 0)
			{
				switch (random(2))
				{
				case 0:
					msg += "$pһ����Ц�������仯�˼����������˶�Ŀ��һʱ��$N�޷�������";
					busy = 2;
					break;
				case 1:
					msg += "$pͻȻ���Ʈȥ���������磬��$N���еĺ�̱仯�޴�ʩչ��";
					busy = 1;
					break;
				}
			} 
			else
				if (target->query_skill("force") > 200 && random(2) == 0)
				{
					switch (random(2))
					{
					case 0:
						msg += "$p��ɫ���أ��ӿ��ܣ����ɶ��ɣ���$N�޴����֣�ֻ���ջؽ��塣";
						busy = 3;
						break;
					case 1:
						msg += "$p������м����Цһ����˫�����������ޱȣ���$Nֻ�ܻ����Ծȡ�";
						busy = 1;
						break;
					}
				}
				else
				{
					switch (random(3))
					{
					case 0:
						msg += "$p��ҡ�һΣ�����ȥ�����·���ƫƫ�����$N��һ����";
						busy = 2;
						break;
					case 1:
						msg += "$p��Ӱ����������ȥ�鶯���$Nһ�������ƶٻ���";
						busy = 2;
						break;
					case 2:
						msg += "$p��ס����������ע������ס��$N�Ľ�����";
						busy = 2;
						break;
					}
				}
				target->start_busy(busy);
				me->start_busy(4);
		}
	}
	message_vision(msg.c_str() , me, target);
	
	return 1;
	
}

static int do_feng(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target	||	!me->is_fighting(target) )
		return notify_fail("��Ѩֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if (!(weapon = me->query_weapon()) 
		|| DIFFERSTR(weapon->querystr("skill_type"), "whip"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if(me->query_skill("yunv_xinjing",1) < 100)
		return notify_fail("����Ů�ľ��Ĺ����������ܷ�ס����Ѩ��!");
	
	if(me->query_skill("yinsuo_jinling",1) < 150)
		return notify_fail("�������������Ϊ����,Ŀǰ�����ܷ�ס����Ѩ��!");
	
	if(me->query_skill("tianluo_diwang")< 100)
		return notify_fail("������޵����ƻ��������죬��Ѩ�����ϲ�׼��");
	
	if(me->query("mp") < 800)
		return notify_fail("���������ڲ���, ���ܷ�Ѩ! ");
	
	if( target->is_busy() )
		return notify_fail( "%s��Ѩ���Ѿ������ס�ˣ��㻹��ʲô",target->name());
	
	msg = "$Nʹ������������ϳ˷�Ѩ��������";
	msg += weapon->name();
	msg += "��ס��$n��ȫ��ҪѨ, ʹ$n�������á�\n";
	
	if( random(me->query("combat_exp")) > target->query("combat_exp")/2 )
	{
		msg += "���$p��̴�д�Ѩ���㣬���ܶ�����";
		target->start_busy( me->query_skill("yinsuo_jinling",1) / 20 - 2);
		me->add("mp", -150);
	} 
	else 
	{
		msg += "����$p�����������ڶ����$P�Ĺ�����";
		me->start_busy(4);
	}
	
	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;
