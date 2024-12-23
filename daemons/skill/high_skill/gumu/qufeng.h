// qufeng.h ����֮��
//�ز� 2002��1��17�޸�

SKILL_BEGIN(CSqufeng);

virtual void create()
{
	set_name( "����֮��");

	Magic_t * magic;

	magic = add_magic("wanfengsiyue", do_wanfengsiyue);
	magic->name = "����ɹ�";
	magic->mp = 300;
	magic->ap= 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  dodge, force,damage,lvl;
		char damage_type[5];
	}action[] = {
			{"$N����������$n�·�����һ�����˵�������Զ������ͻȻ�������л�Ӱ�������ɳ�һȺ��䣬��$nͷ��������",
			 -60, 120,100, 0, "����",},
			{"$N˫��һ�����е�˿����ֻ����Ⱥͻ��Ϊ����һȺ������������һȺȴ�Ӻ���$n������",
			 -50, 240, 140,39, "����",},
			{"$N�������裬�����������䣬Ⱥ���ʱɢ�˿������������ҡ�����˷�����$n�˻���",
		     -55, 300, 180,69, "����",},
			{"$N������Ȼһת,���ֱ���Ϊ�������з���һ�����͵�������������������һ���������������Ż�Ӱ�϶���һȺ��ɫ���Ӵ���Ҷ��ɳ�����$n��ǰ������",
			 -55, 380,220,121, "����",},
			{"$N��ָ�ᵯ����ֻ�����͵شӿ�϶�з��˽�ȥ����$n�Ҽ��ϸ����һ�롣Ƭ��֮�䣬$nֻ�������ѵ����ƺ���������Ҳ�ڷ�����",
			 -40, 500,400,250, "����",}
	};

	int level = 0;
	
	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("qufeng", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	if (me->query_temp("teapot/qufeng"))
	{
			level=me->query_temp("teapot/qufeng")-1;
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
	}
	return & m_actions;
}

virtual int valid_enable(string usage) { return usage=="music";}


virtual int valid_learn(CChar * me)
{
	if( DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��")|| DIFFERSTR(me->querystr("family/master_id"), "long er"))
		return notify_fail("����֮��ֻ����С��Ůѧϰ��");

	if (DIFFERSTR(me->querystr("gender"), "Ů��")) 
		return notify_fail("һ��������������з����������ðɣ���");	

	if ( me->query_skill("wudu_shenzhang",1)
		|| me->query_skill("chousui_zhang",1)
		|| me->query_skill("shexing_diaoshou",1)
		|| me->query_skill("jiuyin_zhua",1)
		|| me->query_skill("huagu_mianzhang",1)
		|| me->query_skill("dashou_yin",1) 
		|| me->query_skill("hanbing_mianzhang",1))
		return notify_fail("������а���书���Ҳ��ܽ��㣡");

	if(me->query("repute") < 50000)
	{
		return notify_fail("���Ʒ�в��ã�����书�Ҳ��ܽ��㣡");
	}

	if(me->query("dex") < 20)
		return notify_fail("�����������̫��,������������֮����");

	if(me->query_int() < 35)
		return notify_fail("�������̫��,������������֮����");

	if (me->query_skill("yunv_shenfa", 1) < 100)
		return notify_fail("�����Ů����򻹲���,������������֮����");

	if (me->query_skill("music", 1) < 100)
		return notify_fail("�������֮����򻹲���,������������֮����");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("û������ʦ����ָ�㣬����ô������ĸ����أ�");
}


static int do_wanfengsiyue(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char cmd[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(!target || !me->is_fighting(target) )
		return notify_fail("������ɹǡ�ֻ����ս����ʹ�á�");

	if( DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��") ||DIFFERSTR(me->querystr("gender"), "Ů��"))
		return notify_fail("��Ĺ��Ů���Ӳſ���ʹ�á�����ɹǡ����С�");

	if( me->query("mp") < 600 )
		return notify_fail("�������������");

	if( me->query_skill("yunv_shenfa",1) < 200 )
		return notify_fail("�����Ů����򲻹����޷�ʹ�á�����ɹǡ���");

	if (me->query_skill("music", 1) < 180)
		return notify_fail("�������֮����򻹲���,�޷�ʹ�á�����ɹǡ���");

	if(me->query("dex") < 25 || me->query_dex() < 40)
		return notify_fail("�����������̫��,�޷�ʹ�á�����ɹǡ���");

	if (me->query_skill("qufeng", 1) < 200)
		return notify_fail("�������֮����򻹲���,�޷�ʹ�á�����ɹǡ���");

	if(!EQUALSTR(me->query_skill_mapped("music"), "qufeng"))
		return notify_fail("��ġ�����ɹǡ�����װ��������֮���ϲ���ʹ�á�");

	if(me->query_int() < 40)
		return notify_fail("�������̫��,�޷�ʹ�á�����ɹǡ���");

	message_vision("\n$HIM$N��ӳ��䣬΢��һ�����������˵�����ɲ�Ǽ䣬$n��߳�������������������䡣$COM\n" ,me,target); 

	if (random(me->query("combat_exp"))> target->query("combat_exp")/3 )
	{
		if(target->query_temp("apply/��_����ɹ�")&& (!random(3)||wizardp(me)))
		{
			message_vision("$HIY$n���￿�ڴ��ߣ����ޱ��ۺ����������һ�������ɡ��������Ⱥ��ȫ��Ϊ�������ᣬ�׷���$NϮ������$COM\n" ,me,target); 	
			me->add("mp",-300);	
			int m= (target->query_skill("dodge",1)/2+target->query_skill("music",1)/2)*(random(target->query("age")/4)+1);
			me->add("hp",-m);
			snprintf(cmd ,255,"$HIY���$N�ܵ���%d����˺���",m);
			if(random(3))
			{
				me->apply_condition("yufeng_poison", 5);
			}
			message_vision(cmd,me,target);
			me->start_busy(5);
		}
		else if(!EQUALSTR(target->query_skill_mapped("strike"), "haotian_zhang") && !EQUALSTR(target->query_skill_mapped("strike"), "luoying_shenzhang") && ! EQUALSTR(target->query_skill_mapped("unarmed"), "xianglong_zhang"))
		{
			me->start_busy(1);
			int m;
			if( me->querymap("couple") || me->query("max_atman")|| me->query("wench/sleep"))
			{
				m=3;
			}
			else
			{
				m=5;
			}
			for(int n = 0; n <	m; n++)
			{
				me->set_temp("teapot/qufeng",n+1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			}
			if(random(2))
			{
				target->apply_condition("yufeng_poison", 5);
			}
			me->delete_temp("teapot/qufeng");
			me->add("mp",-300);	
			message_vision("\n$HIR$n�������ϴ�ʹ������������ֻ��������ɫ���������ܷ�����ȥ�����������ľ�������֮����" ,me,target); 
			message_vision("$HIR����ȫ��������ǣ���ǰ��ãã��һƬ����֪�����ǻã������˹�ȥ��$COM" ,me,target); 
			me->start_busy(random(1)+2);
		}
		else
		{
			if(EQUALSTR(target->query_skill_mapped("strike"), "haotian_zhang") )
			{
				message_vision("$HIY$n˫���������У�˫�����ɨ�����ܣ�ȴ��һ�С�������ˮ������̬������" ,me,target); 
			}
			else if(EQUALSTR(target->query_skill_mapped("strike"), "luoying_shenzhang") )
			{
				message_vision("$HIY��ֻ��$nʹһʽ������Ҷ����ȫ��ͻȻ������ת��˫�ƺ�ǰ�����͵��������ܡ�" ,me,target); 
				
			}
			else
			{
				message_vision("$HIY$n˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ���������лڡ������Ⱥ��" ,me,target); 	
			
			}
			message_vision("$HIY��ʱ$n��Χ��Ⱥ��һƬ���ң���ǿ�ҵ��Ʒ����$N,һ��$N������$COM\n" ,me,target); 	
			message_vision("$HIR$N��ǰ��ãã��һƬ����֪�����ǻã�$n������һ�ƴ�����ţ�$N���ɵ����˹�ȥ��$COM" ,me,target); 	
			me->add("mp",-300);	
			int m= (target->query_skill("parry",1)/2+1)*(random(target->query("age")/4)+1);
			me->add("hp",-m);
			snprintf(cmd ,255,"$HIY���$N�ܵ���%d����˺���",m);
			if(random(3))
			{
				me->apply_condition("yufeng_poison", 5);
			}
			message_vision(cmd,me,target);
			me->start_busy(5);
		}
	} 
	else 
	{ 
		message_vision("$HIC����$n������$N����ʽ,�û�����������$COM\n" ,me,target);
		me->add("mp",-200);	
		me->start_busy(3);
	}  
	return 1;
}

SKILL_END;
