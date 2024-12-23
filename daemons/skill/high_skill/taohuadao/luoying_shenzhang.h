
// luoying_shenzhang.h ��Ӣ����
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CSluoying_shenzhang);

virtual void create()
{
	set_name( "��Ӣ����");
	set("valid_force", "bibo_shengong");

	set("diff",100);

	Magic_t * magic;

	magic = add_magic("xuan", do_xuan);
	magic->name = "���־�";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("pikong", do_pikong);
	magic->name = "������";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("zhong", do_zhong);
	magic->name = "�ָ�����";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("ba", do_ba);
	magic->name = "�θ�����";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,lvl;
		char damage_type[5];
	}action[] = {
		{"$N������ָ����һ�գ�һʽ��������桹����ָ��Ȼңң����$n��$nֻ������ɼ���Ϯ���Լ��崦��Ѩ", 200, 10, 0, "����",},
		{"$NͻȻ����Ծ���գ�һʽ���仨���项��˫�����£�����$n��ͷ��", 210, 15, 10, "����",},
		{"$N������ֲ�£ʳָ��ָ�����������һʽ��Ѱ��̽������ֱָ$n������", 220, 20, 20, "����",},
		{"$NͻȻ������ˣ�����һʽ�������š���ƽ�����˫����$n��$l��������", 235, 35, 30, "����",},
		{"$Nʹһʽ������Ҷ����ȫ��ͻȻ������ת��˫�ƺ�ǰ�����͵�����$n���ؿ�", 250,30 , 40, "����",},
		{"$Nǰ��һ�࣬һʽ����ݲ�������˫���Ƴ�һ������֮��Ϯ��$n��$l", 325,35 , 50, "����",},
		{"$N˫��ʳָ����ָѸ�ٺ���һ��һʽ���ݻ���Ҷ����һ��ǿ�ҵ�����ӿ��$n��ȫ��", 375, 20, 60, "����",},
		{"$Nʹһʽ����Ůɢ������˫���������Ȧ������һ������$n��$l�ȥ", 400, 35, 70, "����",},
		{"$N��������ǰ��ʲ��ʩչ�����Ʋ���������˫����Ȼ�ֿ����������Ź�����ٹ���$n", 450, 10, 84, "����",},
		{"$Nһʽ����Ӣ�ͷס���˫������ǰ��ת��Ȧ����������������$n��$nֻ�������ƻ������Լ�������Ϊ�������۷���������֪��ܡ�", 510, -15, 99, "����",},
	};

	int level = me->query_skill("luoying_shenzhang", 1);
	
	for(int i=10; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
/*			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
*/
			m_actions.set("force", (me->query("skill_pro/�һ���/��Ӣ����/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/�һ���/��Ӣ����/dodge")+100) * action[level].dodge/100);

			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return usage == "unarmed" || usage == "parry" || usage == "strike";	//lanwood ��װ���������Ʒ�
}

virtual int valid_combine(string combo) { return combo=="xuanfeng_leg"; }	//add by lanwood �������������

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/�һ���/��Ӣ����/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/�һ���/��Ӣ����/force"));
			if(me->query("skill_pro/�һ���/��Ӣ����/force_point")>=level_point)
			{
				me->add("skill_pro/�һ���/��Ӣ����/force",1);
				me->set("skill_pro/�һ���/��Ӣ����/force_point",1);
				tell_object(me,"\n$HIR�����Ӣ��������ڹ������ڻ��ͨ�ˡ�\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/�һ���/��Ӣ����/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/�һ���/��Ӣ����/dodge"));
			if(me->query("skill_pro/�һ���/��Ӣ����/dodge_point")>=level_point)
			{
				me->add("skill_pro/�һ���/��Ӣ����/dodge",1);
				me->set("skill_pro/�һ���/��Ӣ����/dodge_point",1);
				tell_object(me,"\n$HIR�����Ӣ����ʹ�õø��ӵ���Ӧ���ˡ�\n");
			}
		}
	}
	return "";
}

virtual int valid_learn(CChar * me)
{
    if (me->query_weapon()  )
		return notify_fail("����Ӣ���Ʊ�����֡�");
    if ( me->query_skill("bibo_shengong", 1) < 15)
		return notify_fail("��ı̲��񹦻�򲻹����޷�ѧ��Ӣ���ơ�");
    if ( me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷�����Ӣ���ơ�");
    return 1;
	
}

virtual int practice_skill(CChar * me)
{
    if ( me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
    if ( me->query("mp") < 20)
		return notify_fail("���������������Ӣ���ơ�");
	me->receive_damage("hp", 20);
    me->add("mp", -1);
	return 1;
	
}

//perform 
static int do_xuan(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("����Ϯ��ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if(  me->query_skill("luoying_shenzhang", 1) < 30 )
		return notify_fail("�����Ӣ���Ʋ�����죬����ʹ�á������־���");

	if(DIFFERSTR(me->querystr("family/family_name"), "�һ���") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if(  me->query_skill("bibo_shengong", 1) < 30 )
		return notify_fail("��ı̲��񹦲����ߣ���������Ϯ�����ˡ�");

	if( me->query("mp") < 300)		//add by Lanwood 2000-12-26
		return notify_fail("����������㡣");
	
	msg =   "$NĬ����Ӣ�ķ���ʹ����Ӣ���ơ������־����Ӱ��������һƬ��Ӱ����$n��\n" ;
	
	if (random(me->query_skill("force")) > target->query_skill("force")/3 )
	{
		me->start_busy(2);
		target->start_busy(random(3));
		
		int damage =  me->query_skill("bibo_shengong", 1); 
		damage = damage/2 + random(damage);
		
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/3);
		me->add("mp", -damage/5);
		
		if ( damage < 40 ) 
			msg +=  "���$N�ܵ�$n������������Ȼ����$N���Լ�ȴ�ƺ�һ���������������" ;
		
		else if( damage < 80 ) 
			msg +=  "���$N��$n�����������ؿ������ܵ�һ���ش�����������������" ;
		
		else
			msg +=  "$nãȻ��֪���룬�����$Nһ�ƻ���ǰ�أ�$n��ǰһ�ڣ������ɳ�����������" ;
	} 
	else
	{
		me->add("mp", -50);	
		me->start_busy(1);
		msg +=  "����$p������$P����ͼ�����������һ�ߡ�" ;
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

static int do_pikong(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("�������ơ�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (me->query_weapon())
		return notify_fail("������������ô��ʹ�á������ơ���");
	
	if(  me->query_skill("luoying_shenzhang", 1) < 120 )
		return notify_fail("�����Ӣ���Ʋ�����죬�޷�����������ơ���\n");

	if(  me->query_skill("bibo_shengong", 1) < 150 )
		return notify_fail("��ı̲�����Ϊδ�����޷�����������ơ���\n");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "�һ���") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��\n");
	
	if( me->query("mp") < 400)		
		return notify_fail("����������̫�������ܴ���������ơ���\n");

	if(DIFFERSTR(me->querystr("family/family_name"), "�һ���") )
		return notify_fail("����Ȼ��˵���������ơ���һ�У�����ȴδ���ڡ�\n");
	
	msg =   "$HIB$N��Хһ����һʽ�������ơ���$n������Ю����������ӿ�ı̲��񹦣������ⲻ�ɵ���" ;
	
	if (random(me->query_skill("dodge")) > target->query_skill("dodge")/2 )
	{
		me->start_busy(1);
		target->start_busy(2);              
		int damage = me->query_skill("bibo_shengong", 1) +me->query_skill("luoying_shenzhang", 1);
		damage = damage*3-random(damage/2);
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/2);
		me->add("mp", -400);

		msg += "\n$HIG$n�����������һײ�����ܴ��˳����������Ѫ���磬������ͬ���߷��ݰ�ɳ���\n";
	}
	else
	{
		me->start_busy(2);
		me->add("mp",-250);
		msg += "\n$CYN$n���������ң���æ����һ�ã�$N��һ�Ʊ㼴��ա�\n";
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

static int do_zhong(CChar * me, CContainer * ob)
{
	if((me->environment())->query("no_fight"))
		return notify_fail("�����ֹս�����޷�ʹ�á����Ƕ�����");

	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target)
		return notify_fail("��Ҫ����˭��\n");

	if (me->query_weapon())
		return notify_fail("������������ô���֡����Ƕ�����");
	
	if(  me->query_skill("luoying_shenzhang", 1) < 150 )
		return notify_fail("�����Ӣ���Ʋ�����죬�޷�ʹ�á����Ƕ�����\n");

	if(  me->query_skill("bibo_shengong", 1) < 190 )
		return notify_fail("��ı̲�����Ϊδ�����޷�ʹ�á����Ƕ�����\n");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "�һ���") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��\n");
	
	if( me->query("mp") < 1000)		
		return notify_fail("����������̫��������ʹ�á����Ƕ�����\n");

	if(DIFFERSTR(me->querystr("family/family_name"), "�һ���") )
		return notify_fail("����Ȼ��˵�����ָ����롹��һ�У�����ȴδ���ڡ�\n");
	
	msg ="$HIY$N�������ߵ�$n���ᣬ���������\n" ;
	
	if (random(me->query_skill("dodge")) > target->query_skill("dodge")/2 )
	{
		target->add("����/thd/fugu",1);
        msg+= "$HIR$NͻȻ���������$n��������һ�£�$n���ú���ʲô����һ�¡�\n";
		me->start_busy(3);
	}
	else
	{
		me->start_busy(5);
		msg += "$CYN$n��$N��ɫ���죬�첽���˿�ȥ��\n";
	}
	me->add("mp",-1000);
	message_vision(msg.c_str(), me, target);
	return 1;
}

static int do_ba(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target)
		return notify_fail("����û������ˡ�\n");
	
	if(!target->query("����/thd/fugu"))
		return notify_fail("�����û���и��Ƕ���\n");

	if (me->query_weapon())
		return notify_fail("������������ô�ܰγ������Ƕ�����");
	
	if(  me->query_skill("luoying_shenzhang", 1) < 180 )
		return notify_fail("�����Ӣ���Ʋ�����죬�޷��γ������Ƕ�����\n");

	if(  me->query_skill("bibo_shengong", 1) < 200 )
		return notify_fail("��ı̲�����Ϊδ�����޷��γ������Ƕ�����\n");
	
	if( me->query("mp") < 1000)		
		return notify_fail("����������̫�������ܰγ������Ƕ�����\n");

	if(DIFFERSTR(me->querystr("family/family_name"), "�һ���") )
		return notify_fail("����Ȼ��˵�����θ����롹��һ�У�����ȴδ���ڡ�\n");
	
	me->add("mp",-1000);

	msg ="$HIY$N�ߵ�$n���ᣬ���������\n" ;
	msg+="$HIW$N����̲��񹦣������Ľ�$n���и��Ƕ��γ���\n";
	msg+= "$HIR$n�ҽ�һ�������˹�ȥ��\n";
	target->add("����/thd/fugu",-1);
	
	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;
