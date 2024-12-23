// taiji-jian.c ̫����

void remove_effect(CContainer * me, LONG amount1, LONG amount2)
{
	CChar * ob = (CChar * )me;
		
	ob->add_temp("apply/attack", - amount1);
	ob->add_temp("apply/dodge", - amount2);
	ob->delete_temp("tjj_sui");
	tell_object(ob, "������־�������ϣ��������ջص��");
}

SKILL_BEGIN(CStaiji_jian);

virtual void create()
{
	set_name( "̫����");
	set("valid_force", "taiji_shengong");

	Magic_t * magic;

	magic = add_magic("sui", do_sui);
	magic->name = "���־�";
	magic->mp = 300;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("lian", do_lian);
	magic->name = "���־�";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("chan", do_chan);
	magic->name = "���־�";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[] = {
		{"$N�鲽������һ�С����ѵ�ˮ��������$w���������һ��������$n��$l", 60,20,10,45,0,},
		{"$N��ǰ����һ�������ֽ���������$wʹ��һʽ��ָ���롹ֱ��$n��$l", 70,15,10,50,4,},
		{"$N��������һ�죬���ֽ���������$wʹ��һʽ������ǡ�����$n��$l", 80,15,10,50,9,},
		{"$N˫ϥ�³�������$wʹ��һʽ��̽��ʽ�������¶��ϼ���$n��$l", 90,15,10,50,14,},
		{"$Nһ�С������Ӳ�����$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ", 100,15,15,60,19,},
		{"$N���������һš��һ�С�������β��������$w������$n��$l��ȥ", 110,15,15,70,24},
		{"$Nһ�С�����ɨ����һ�С�����ɨ��������ƽָ��һ���ǳɺ�ɨ$n��$l", 120,10,15,70,29},
		{"$N������ϥ������$wбָ��һ�С�����Ͷ�֡�����$n��$l", 130,15,15,70,34,},
		{"$Nһ�С�������ˮ����$w���¶��ϻ���һ���󻡣�ƽƽ�ػ���$n��$l", 140,15,15,71,39,},
		{"$Nʹ�����������¡���$w��������ԲȦ������ֱ�������಻�ϻ���$n��$l",150,10,20,73,44},
		{"$Nһ�С�����Ҷ����$w����ػ�������Բ����Ѹ�ٵ���$n��$l��ȥ", 160,15,20,75,49},
		{"$Nһ�С�����ͷ����$w����һ������ҸߵĴ󻡣�бб��ն��$n��$l", 170,15,20,77,54,},
		{"$Nʹ����ʨ��ҡͷ����$w�������󻮳�һ�����֣���$nȦ������", 180,15,20,79,59,},
		{"$N���̤ʵ���ҽ���㣬һ�С�����ָ·��������$w����һ�Ž���������$n��$l", 190,5,20,81,64},
		{"$N����Ծ��һ�С�Ұ����������$w�ڰ���л�ΪһȦ��â������$n��$l", 200,15,20,83,69,},
		{"$N����ǰ���󹭣�һ�С�����ʽ��������$wֱ��$n��$l",210,20,20,85,74,},
		{"$Nһ�С�С���ǡ�����������һ�죬���ֽ���������$wƽƽ����$n��$l��ȥ", 220,40,20,87,79,},
		{"$N������ϣ�һ�С���Գ�׹���������$wбб����$n��$l��ȥ", 230,30,20,89,84,},
		{"$Nһ�С�ӭ�絧������$w���������һ�ӣ�$nȴ����һ�ɾ���ӭ��Ϯ����", 240,20,25,91,89,},
		{"$Nһ�С�˳ˮ���ۡ���$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ��", 250,45,25,93,94,},
		{"$Nһ�С����Ǹ��¡���$w����$n��$l", 260,35,25,95,99,},
		{"$NͻȻ�̶���������һ�С��������¡���$w���¶��ϵ���$n��$l��ȥ", 270,25,25,97,104,},
		{"$Nһ�С�����ʽ����$w���¶������컮��һ���󻡣�ƽƽ����$n��$l��ȥ", 200,35,25,99,109,},
		{"$Nһ�С��Ʒ��붴����$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ", 290,40,25,102,104,},
		{"$Nһ�С�����չ�᡹������Ծ������$w����$n��$l", 300,45,25,106,119,},
		{"$Nһ�С����ֽ�����$w����һƬ���̣�ƽƽ����$n��$l��ȥ", 310,45,25,120,124,},
		{"$N��������棬������ǰһ�ˣ�һ�С������пա���$w��$n��$l��ȥ", 320,45,30,125,129,},
		{"$Nһ�С���ɨ÷����������Ծ�ڰ�գ�����$wɨ��$n��$l", 330,45,30,130,90,},
		{"$Nһ�С�ȴ���齣�������Ծ����أ�$w�س飬���ֹ���$n��$l", 340,35,30,140,139,},
		{"$N���Ȱ�����ף�һ�С�����Ʊա���������ָ��ת������$n��$l", 350,25,30,150,144,},
		{"$N����š���������鱧��һ�С�����հ�ա���$w�й�ֱ��������$n��$l", 380,35,30,160,149,},
	};
	int level = me->query_skill("taiji_jian", 1);
	for(int i=31; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="sword" ||  usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("�������������");
	if (me->query_skill("taiji_shengong", 1) < 20)
		return notify_fail("���̫���񹦻��̫ǳ��");
	if (me->query_skill("taiji_quan", 1) < 20)
		return notify_fail("���̫��ȭ���̫ǳ��");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("$HIR���õ������ǽ�����ȷ�����õ�����ǽ����ѵ����õ�����ǽ���");
	
	if (me->query("hp") < 50)
		return notify_fail("$HIR��Ȼ����о��ĵ���̫����������������������ˡ�");
	me->receive_damage("hp", 30);
	return 1;
}

//perform 
static int do_sui(CChar * me, CContainer * ob)
{
	char msg[255];
	CContainer * weapon;

	if( ! me->is_fighting() )
		return notify_fail("���桹�־�ֻ����ս����ʹ�á�");
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��֪��������þ��У����������õ�Ҳ�����ǽ�����");
	
	if( me->query_skill("taiji_jian", 1) < 40 )
		return notify_fail("���̫������������죬����ʹ�á��桹�־���");

	if(DIFFERSTR(me->querystr("family/family_name"), "�䵱��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( me->query("mp") < 300  ) 
		return notify_fail("�������������");
	
	if( me->query_temp("tjj_sui") ) 
		return notify_fail("���Ѿ����˹����ˡ�");
	
	int skill = me->query_skill("taiji_jian");
	strncpy(msg, "$Nʹ��̫���������桹�־�����Ȧ����С������ס��", 255);
	message_vision(msg, me);

	if(!me->query_temp("tjj_sui") && !me->query_temp("qzj_tong") && !me->query_temp("hsj_wu") && !me->query_temp("hmg_dzjm"))
	{
		me->add_temp("apply/attack", -skill/4);
		me->add_temp("apply/dodge", skill/3);
		me->set_temp("tjj_sui", 1);
		me->call_out(remove_effect, skill, -skill/4, skill/3);
	}
	if( me->is_fighting() ) me->start_busy(3);
	return 1;
}

static void remove_effect(CContainer * ob, LONG amount1, LONG amount2)
{
	ob->add_temp("apply/attack", - amount1);
	ob->add_temp("apply/dodge", - amount2);
	ob->delete_temp("tjj_sui");
	tell_object(ob, "������־�������ϣ��������ջص��");
}

/*ԭ��������
static void remove_effect(CContainer * ob, LONG param1, LONG param2)
{
	ob->delete_temp("tjj_jie");
	tell_object(ob, "$HIY$N��һ�������ľ��������־�������Ҳʹ����ȥ��$COM");
}

*/
static int do_lian(CChar * me, CContainer * ob)
{
	char msg[255];
	CChar * target = NULL;
	string str;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	int extra;
	int i;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("�������־�ֻ�ܶ�ս���еĶ���ʹ�á�");

	if(DIFFERSTR(me->querystr("family/family_name"), "�䵱��") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��֪��������þ��У����������õ�Ҳ�����ǽ�������");

//	if( DIFFERSTR(me->query_skill_mapped("sword"), "taiji_jian") || EQUALSTR(me->query_skill_mapped("sword"), "liangyi_jian"))
	if( DIFFERSTR(me->query_skill_mapped("sword"), "taiji_jian") )
		return notify_fail("��������䵱�ɵĽ���ʹ�á�");	

	if( me->query_skill("taiji_jian", 1) < 40 )
		return notify_fail("���̫������������죬����ʹ�á������־���");

	if( me->query("mp") < 100)	//add by lanwood 2000-12-25
		return notify_fail("����������㡣");

	message_vision(snprintf(msg, 255, "$HIR$N����̫���񹦡���ͬʱʹ����̫�����С��ġ������־������е�%sһ������һ�л���Ȧ���������Ļ���$n��$COM", weapon->name()), me, target);

	if(target->query_temp("apply/no_���־�") && !random(2))
	{
		return notify_fail(snprintf(msg, 255,"����%s������%s����ͼ������������ס��%s���������С�\n",target->name(),me->name(),me->name()));
	}
	else
	{

		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK); 
		message_vision("$HIW����һ������ʧ��������$COM\n", me, target);
	
		extra = me->query_skill("taiji_jian",1) / 20;
		extra += me->query_skill("taiji_shengong",1) /20;	

		if(	random(me->query("combat_exp")) > target->query("combat_exp") / 20 )
		{
			i = extra/4;
			me->call_out(lianji, 1, target->object_id(), 1);
			me->add("mp", - 60 * i);
			me->start_busy(3);
		}
		return 10;
	}
}


char * hit_ob(CChar *me, CChar *victim, LONG & damage)
{
	CContainer * wp1;
	string msg;
	int p,j,skill, mp, mp1;
	
	wp1 = victim->query_weapon();
	skill = me->query_skill("taiji_quan", 1);
	mp = me->query("mp");
	mp1 = victim->query("mp");
	if(me->query_temp("tjj_jie"))
	{
		if(wp1) 
		{
			msg = "\n$N˫��������̫��������$n��";
			msg += wp1->name();
			msg += "��һ�ƣ�";
		}
		else msg = "\n$N˫�ֻ������������̫��������";
		
		if(random(me->query("str"))< victim->query("str")/3)
		{
			msg +="$n������$N�Ľ������������㷢��������\n";
			damage=damage*2+100;
			me->receive_damage("hp",damage);
			p=me->query("hp")*100/me->query("max_hp");
			
			if(damage<100)
				msg +="���$NӲ��$n��һ�����ƺ�һ����\n";
			
			else if(damage<200)
				msg +="���$NӲ��$n�������𣬡��١���һ������������\n";
			
			else if(damage<300)
				msg+="���$N��$n������һ���ؿ������ܵ�һ���ش�����������������\n";
			
			else msg+="���$N��$n������һ����ǰһ�ڣ�����������ߵķ������ɳ�������\n";
			
			msg += "( $N";
			msg += g_Combatd.eff_status_msg(p);
			msg += " )";
		}
		else if(mp >= mp1 + damage)
		{
			msg += "$n��������̫��ȭ��������������ȥ��\n",		
				victim->receive_damage("hp", 100 + damage/2 + victim->query("jiali")*2);
			p = victim->query("hp")*100/victim->query("max_hp");
			msg += g_Combatd.damage_msg(damage/2, "����");
			msg += "( $n";
			msg += g_Combatd.eff_status_msg(p);
			msg += " )";
			j=-8000; 
		}
		else if(mp >= mp1/2+random(mp1/2)+random(damage))
		{
			msg += "$n��������̫��ȭ��������ж��һ�ԣ�\n";
		}
		else if(mp > mp1/2+damage)
		{
			msg += "$n��������̫��ȭ��������ж����һ���֣�\n"; 
			me->receive_damage("hp",damage/3+random(damage));		 
			p=me->query("hp")*100/me->query("max_hp");
			msg += g_Combatd.damage_msg(damage/2, "����");
			msg += "( $N";
			msg += g_Combatd.eff_status_msg(p);
			msg += " )";
		}
		else
		{
			msg += "$N��������̫��ȭ��������ж����һС�룡\n"; 
			me->receive_damage("hp",damage/3); 
			p=me->query("hp")*100/me->query("max_hp");
			msg += g_Combatd.damage_msg(damage/2, "����");
			msg += "( $N";
			msg += g_Combatd.eff_status_msg(p);
			msg += " )";
		}	    
		
		message_vision(msg.c_str(), me, victim);
	}
	
	return 0;
}

static void lianji(CContainer * ob, LONG param1, LONG time)
{
	CContainer * weapon;
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);
	int extra;
	string str;
	extra = me->query_skill("taiji_jian",1) / 20;
	extra += me->query_skill("taiji_shengong",1) /20;

	if(! target || ! me->is_fighting(target)) return;
	
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_REGULAR);
	
	if(time < extra / 4  &&  EQUALSTR(me->query_skill_mapped("sword"), "taiji_jian") 
		&& ((weapon = me->query_weapon())&& EQUALSTR(weapon->querystr("skill_type"), "sword")))
	{
		str = "$HIY$N�ý�����һ��Ȧ��һ��������������$COM\n";
		message_vision(str.c_str(), me, target);
		me->call_out(lianji, 1, param1, time + 1);
	}
	else
	{
		str = "����$p������$P����ͼ������������ס��$P���������С�\n";
		message_vision(str.c_str(), me, target);
		me->start_busy(4);
	}
}

static int do_chan(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("ʦ�������ǣ�Ҫ�͵��������ش�");

	if(DIFFERSTR(me->querystr("family/family_name"), "�䵱��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��Ȼ�Һ����þ��У����������õ�Ҳ�����ǽ�������");

	if( target->is_busy() )
		return notify_fail("�Է�Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�");

	if( DIFFERSTR(me->query_skill_mapped("sword"), "taiji_jian") || EQUALSTR(me->query_skill_mapped("sword"), "liangyi_jian"))
		return notify_fail("��������䵱�ɵĽ���ʹ�á�");

	if( me->query_skill("taiji_jian", 1) < 40 )
		return notify_fail("���̫������������죬����ʹ�á������־���");

	if( me->query("mp") < 20)
		return notify_fail("����������㡣");
	
	msg = "$Nʹ��̫�������������־�����������������ͼ����$n�Ĺ��ơ�\n";
		
	if( random(me->query("combat_exp")) > target->query("combat_exp")/4 )
	{
		if(DIFFERSTR(me->querystr("family/family_name"), "�䵱��") ||target->query("bigboss"))
		{
			if(EQUALSTR(target->query_skill_mapped("unarmed"), "xianglong_zhang") &&(EQUALSTR(target->querystr("family/family_name"), "ؤ��") ||!userp(target))&& target->query("kill/guilt")<=150 )
			{
				msg+="$HIY$n�ۼ��ֿ죬�Ż��󿪣�һ�С���˪��������$N������ȥ����ʱ$N������ҡ�\n" ;
				me->start_busy(2);
			}
			else if(target->query("no_chan")||target->query_temp("no_chan")||target->query_temp("apply/no_���־�")&& !random(2))
			{
				msg += "����$p������$P����ͼ����û���ϵ���";
				me->start_busy(3);
			}
			else if(target->query_temp("apply/��_���־�")&& !random(3))
			{
				msg+="$HIY$n������ϣ������Ծ��$N��������$N�ı��󣬶�ʱ$N������ҡ�" ;
				me->start_busy(me->query_skill("taiji_jian", 1) / 20 + 1);
			}
			else
			{
				msg += "���$p��$P���˸����ֲ�����";
				target->start_busy( me->query_skill("taiji_jian", 1) / 20 + 1);
			}
		}
		else
		{
			if(target->query_temp("apply/��_���־�")&& !random(3))
			{
				msg+="$HIY$n������ϣ������Ծ��$N��������$N�ı��󣬶�ʱ$N������ҡ�" ;
				me->start_busy(me->query_skill("taiji_jian", 1) / 30 + 1);
			}
			else if(target->query_temp("apply/no_���־�")&& !random(4))
			{
				msg += "����$p������$P����ͼ����û���ϵ���";
				me->start_busy(2);
			}
			else
			{
			msg += "���$p��$P���˸����ֲ�����";
			target->start_busy( me->query_skill("taiji_jian", 1) / 20 + 1);
			}
		}
	}
	else
	{
		msg += "����$p������$P����ͼ����û���ϵ���";
		me->start_busy(2);
	}

	me->add("mp", -20);
	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;




