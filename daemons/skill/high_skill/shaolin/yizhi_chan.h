SKILL_BEGIN(CSyizhi_chan);

virtual void create()
{
	set_name( "һָ��");

	Magic_t * magic;

	magic = add_magic("dian", do_dian);
	magic->name = "���־�";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("jingmo", do_jingmo);
	magic->name = "��ħһָ";
	magic->mp = 800;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("һָ�����������ֶ����ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[4] = {
		{"$N˫ָ��£��һʽ�������������������ϣ�������һǰһ�����$n���ظ���",
			60, -5, -5, 10, 0,},
		{"$N���ƻ��أ�һʽ��������ա���������ָǰ���˸��뻡���͵�һ˦������$n��$l",
		120, 10, 15, 30, 20,},
		{"$N����������һʽ�����Ź�ɡ���˫��ʳָ�˲������һ������������$n��ȫ��ҪѨ",
		240, 20, 20, 60, 40,},
		{"$N��ϥ������һʽ�����ޱߡ���������ȭ���⣬����Ĵֱָ����ңң����$nһ��",
		480, 40, 30, 90, 60,},
	};

	int level = me->query_skill("yizhi_chan", 1);
	for(int i = 4; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);

			break;
		}
	
	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if (me->query("mp") < 20)
		return notify_fail("�������������һָ����");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("��һָ��������֡�");
	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧһָ����");
	if (me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷���һָ����");
	return 1;
}

virtual int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
virtual int valid_combine(string combo) {return combo=="banruo_zhang"; }

static int do_dian(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
//	char str[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target	||	!me->is_fighting(target) )
		return notify_fail("�������㡹�־�ָ��ֻ�ܶ�ս���еĶ���ʹ�á�");

	if (me->query_weapon())
			return notify_fail("�㲻��ʹ��������");

	if( me->query_skill("yizhi_chan", 1) < 150 )
		return notify_fail("���һָ��̫���裬����ʹ�á��㡹�־���");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if ( me->query("mp") < 500)
		return notify_fail("������������������޷�ʹ�á��㡹�־���");

	
	me->add("mp", -100);

	msg = "$HIY$N��������һ�����������ָ��ʹ�����ŷ�ħ���Ͼ���ָ������������$p���˹��ˡ�\n";
	
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
		CContainer * weapon = target->query_weapon();
		if( random( me->query_skill("force") ) > random( target->query_skill("force") ) )
		{
			me->start_busy(3);
			if (! weapon)	//����������
			{
				int damage = 0;
				
				if (target->query_skill("dodge") > 200 && random(2) == 0)
				{
					switch (random(2))
					{
					case 0:
						msg +="$p�������˼����ϳ���������û�ܶ����$N����ָ������$p��̴��Ѩ�ϣ�$pֻ����һ���������Ե�����ϣ���������˵���������ܡ�";
						damage = 3;
						break;
					case 1:
						msg+="$p����Ʈ�������鶯֮����������Ҫ�Ȳʣ������ۡ���һ��������ܸ$p��ɫɷ�ף�ҡҡ��׹��";
						damage = 5;
						break;
					}
				} 
				else if (target->query_skill("force") > 200 && random(2) == 0)
				{
					switch(random(2))
					{
					case 0:
						msg +="$p���һ�����Գ�������ǿ�����ֳ��У���࣡���һ�����죬��ָ�ཻ��$p����΢�Σ������ֽ��";
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
						msg +="$p�������У���Ȼ��֪��ܣ����͡���һ����$N����ָ������$p�Ĵ�׵Ѩ��,$pȫ������,�����ڵء�";
						//						target->unconcious();
						damage = 6;
						break;
					case 1:
						msg += "$pһת��Ѿ�����˾�ʮ���ֻ���İ취����δ���ü�ʩչ��ֻ�����͡���һ�����ѱ�$N���д�׵Ѩ,$pȫ������,�����ڵء�";
						//						target->unconcious();
						damage = 8;
						break;
					}
				}
				if (damage > 0)
				{
					int damage_hp=target->query("max_hp") * damage / 15;
					if(damage_hp>=target->query("hp"))
						damage_hp=target->query("hp")-50;
					target->receive_damage("hp", damage_hp);
				}
				
				message_vision(msg.c_str(), me, target);
				return 1;
			}
			else
			{
				if(weapon->query("no_duo") && !random(3) )
					msg += "����$n������$N����ͼ����û���ϵ���\n";
				else
				{
					msg += "$p��æ�мܣ�ֻ������ž����һ����$p���е�";
					msg += weapon->name();
					
					if(weapon->query("no_duo") )
					{
						msg += "���ֶ�����\n";
						char msg1[40];
						target->command(snprintf(msg1, 40, "unwield %ld", weapon->object_id()));
					}
					else
					{
						msg += "�����ѣ�ɢ��һ�أ�";
						weapon->move(target->environment());
						char new_name[40]; 
						weapon->set_name(snprintf(new_name, 40, "�ϵ���%s", weapon->name(1)) );
						weapon->set("value", 0l);
						weapon->del("apply");
						target->start_busy(2);
					}	
				}
			}
		} 
		else
		{
			int busy = 0;
			if (target->query_skill("dodge") > 200 && random(2) == 0)
			{
				switch (random(2))
				{
				case 0:
					msg += "$pһ����Ц�������仯�˼����������˶�Ŀ��һʱ��$N�޷�������\n";
					busy = 2;
					break;
				case 1:
					msg += "$pͻȻ���Ʈȥ���������磬��$N��һָ���еĺ�̱仯�޴�ʩչ��\n";
					busy = 1;
					break;
				}
			} 
			else if (target->query_skill("force") > 200 && random(2) == 0)
			{
				switch (random(2))
				{
				case 0:
					msg += "$p��ɫ���أ��������ƣ���׾��׾����Ȼ��$N�޴����֣�ֻ����ָ��\n";
					busy = 3;
					break;
				case 1:
					msg += "$p������м����Цһ����˫�����������ޱȣ���$Nֻ�ܻ����Ծȡ�\n";
					busy = 1;
					break;
				}
			} 
			else
			{
				switch (random(3))
				{
				case 0:
					msg += "$p��ҡ�һΣ�����ȥ�����·���ƫƫ�����$N��һ����\n";
					busy = 2;
					break;
				case 1:
					msg += "$pһָ���������ȥ����Ҳ�Ƿ��ž���ָ����$Nһ�������ƶٻ���\n";
					busy = 2;
					break;
				case 2:
					msg += "$p��ס����������ע��������ס��$N�Ľ�����\n";
					busy = 2;
					break;
				}
			}
			target->start_busy(busy);
			me->start_busy(4);
		}
	}
	message_vision(msg.c_str(), me, target);

	return 1;
}

static int do_jingmo(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||	!me->is_fighting(target) )
		return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�");

	if(me->query_str() < 30)
		return notify_fail("���������,����ʹ����һ����!");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if(me->query_skill("hunyuan_yiqi",1) < 100)
		return notify_fail("���Ԫһ�����Ĺ�����������ʹ�þ�ħһָ!");

    if(me->query_skill("finger") < 150)
		return notify_fail("���ָ����Ϊ����,Ŀǰ������ʹ�þ�ħһָ����!");

	if(me->query("mp") < 800)
		return notify_fail("���������ڲ���, ����ʹ�þ�ħһָ! ");

	if( target->is_busy() )
		return notify_fail("%sĿǰ���Թ˲�Ͼ���ŵ������ɣ�", target->name());

    msg = "$HIY$Nʹ���黨ָ��������ħһָ������ס��$n��ȫ��ҪѨ, ʹ$n�������á�\n";

	if( random(me->query_combat_exp()) > target->query_combat_exp() / 2 ) 
	{
		msg += "���$p��$P���˸����ֲ�����\n$COM";
		target->start_busy( me->query_skill("yizhi_chan",1) / 20 + 2);
		me->add("mp", -150);
	} else 
	{
		msg += "$HIG����$p������$P����ͼ����û���ϵ���$COM";
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);

	return 1;
}

SKILL_END;



