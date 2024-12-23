//rouqing_zhi.h ����ָ
//�ز� 2002��1��16

SKILL_BEGIN(CSrouqing_zhi);


virtual void create()
{
	set_name( "����ָ");
	
	Magic_t * magic;
	set("diff",150);
	
	magic = add_magic("caiyue", do_caiyue);
	magic->name = "��¥����";
	magic->mp = 300;
	magic->ap=200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "bahuang_gong") )
		return 1;
	
	return notify_fail("����ָ���������ն����ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[4] = {
		{"$N����һ�ӣ�һ�С���̨���¡����ֵ���$n$l",100, -40, 220, 0,},
		{"$Nʹһ�С�ѩ����÷������Ӱ��ǰ����ͻȻһת��������$n��$l��ȥ",240, -50, 340,  39,},
		{"$N���Զ٣�����һ��ʹ������ͤ��������$n��$l��ȥ",410, -55, 450, 69,},
		{"ֻ��$N����һ�ڣ���Ȼ�������ߣ�����˳������һ�С��ҷ��˵�����$n��$l��ȥ",500, -70, 650, 121,},
	};
	
	int level = me->query_skill("rouqing_zhi", 1);
	for(int i = 4; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", (me->query("skill_pro/���չ�/����ָ/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/���չ�/����ָ/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/���չ�/����ָ/damage")+100) * action[level].damage/100);
			
			break;
		}
		
		return & m_actions;
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/���չ�/����ָ/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/���չ�/����ָ/force"));
			if(me->query("skill_pro/���չ�/����ָ/force_point")>=level_point)
			{
				me->add("skill_pro/���չ�/����ָ/force",1);
				me->set("skill_pro/���չ�/����ָ/force_point",1);
				tell_object(me,"\n$HIR�������ָ����ڹ������ڻ��ͨ�ˡ�\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/���չ�/����ָ/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/���չ�/����ָ/dodge"));
			if(me->query("skill_pro/���չ�/����ָ/dodge_point")>=level_point)
			{
				me->add("skill_pro/���չ�/����ָ/dodge",1);
				me->set("skill_pro/���չ�/����ָ/dodge_point",1);
				tell_object(me,"\n$HIR�������ָʹ�õø��ӵ���Ӧ���ˡ�\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/���չ�/����ָ/damage_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/���չ�/����ָ/damage"));
			if(me->query("skill_pro/���չ�/����ָ/damage_point")>=level_point)
			{
				me->add("skill_pro/���չ�/����ָ/damage",1);
				me->set("skill_pro/���չ�/����ָ/damage_point",1);
				tell_object(me,"\n$HIR�������ָ���������ˡ�\n");
			}
		}
	}
	return "";
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if ((int)me->query("mp") < 20)
		return notify_fail("�����������������ָ��");
	if (DIFFERSTR(me->querystr("gender"), "Ů��"))
		return notify_fail("����ָ��ֻ��Ů�Ӳ��������书��");
	if ( DIFFERSTR(me->querystr("family/family_name"), "���չ�"))
		return	notify_fail("����ָ���������չ����ӷ�������ϰ");
	if ((int) me->query_skill("rouqing_zhi", 1) > 99)
		return notify_fail("���Ѿ��޷�ͨ����������������������ָ��");
	if (me->query_skill("bahuang_gong", 1) < (40+me->query_skill("rouqing_zhi", 1)))
		return notify_fail("��İ˻�����Ψ�Ҷ��𹦻�򲻹����޷���ϰ����ָ��");
	if (me->query_skill("finger", 1) < me->query_skill("rouqing_zhi", 1))
		return notify_fail("��Ļ���ָ����򲻹����޷���ϰ����ָ��");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("������ָ������֡�");
	if (DIFFERSTR(me->querystr("gender"), "Ů��"))
		return notify_fail("����ָ��ֻ��Ů�Ӳ���ѧ���书��");
	if ( DIFFERSTR(me->querystr("family/family_name"), "���չ�"))
		return	notify_fail("����ָ���������չ����ӷ�����ѧϰ");
	if (me->query_skill("bahuang_gong", 1) < 80)
		return notify_fail("��İ˻�����Ψ�Ҷ��𹦻�򲻹����޷�ѧ����ָ��");
	if (me->query_skill("finger", 1) < 80)
		return notify_fail("��Ļ���ָ����򲻹����޷�ѧ����ָ��");
	if (me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷�������ָ��");
	if ((int) me->query_skill("rouqing_zhi", 1) > 300)
		return notify_fail("���Ѿ��޷�ͨ�����������������ָ��");
	return 1;
}

virtual int valid_enable(string usage) { return usage=="finger" || usage=="parry";  }

static int do_caiyue(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	int harm;
	string msg;
	char cmd[255];
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if(! target || ! me->is_fighting(target))		
		return notify_fail("ֻ�ܶ�ս���еĵ���ʹ�ã�");
	
	if(me->query_str() < 25)
		return notify_fail("���������,����ʹ����һ����!");
	
	if ( !wizardp(me) && (DIFFERSTR(me->querystr("family/family_name"), "���չ�")))
		return	notify_fail("�۾�¥���£ݱ��������չ����ӷ�����ʹ��");
	
	if(me->query_skill("bahuang_gong",1) < 100)
		return notify_fail("��İ˻�����Ψ�Ҷ��𹦹�������������ʹ�ã۾�¥���£�!");
	
	if (me->query_weapon())
		return notify_fail("�㲻��ʹ��������");
	
	if (me->query_skill("finger", 1)
		&& !EQUALSTR(me->query_skill_mapped("finger"), "rouqing_zhi"))
		return notify_fail("�۾�¥���£ݱ���Ҫװ��������ָ���ϲſ���ʹ����һ����");
	
	if(me->query_skill("finger") < 180)
		return notify_fail("���ָ����Ϊ����,Ŀǰ������ʹ�ã۾�¥���£ݾ���!");
	
	if(me->query("mp") < 500)
		return notify_fail("���������ڲ���, ����ʹ�ã۾�¥���£�! ");
	
	if( target->is_busy() )
		return notify_fail("%sĿǰ���Թ˲�Ͼ���ŵ������ɣ�", target->name());
	
	msg = "\n$HIY$N�����ָ�������㣬ָ��ֱ��$n�������Ѩ��\n";
	
	if( random(me->query_combat_exp()) > target->query_combat_exp() / 5 )
	{
		if(!EQUALSTR(target->query_skill_mapped("dodge"), "lingboweibu"))
		{
			msg +=  "\n$HIG$N���������ָ�罫$n�Ƶ����˼����� $COM";
			message_vision(msg.c_str(), me, target);
			if(random(me->query("dex"))>target->query("dex")/4)
			{
				if(me->query_skill("rouqing_zhi", 1)<351)
				{
					msg =  "\n$HIY$n�ƺ���һ�������������˿Ѫ˿�� $COM";
					harm=(random(me->query("age")/4+me->query("per")/3)+1)*(random(me->query_skill("rouqing_zhi", 1)/20)+25)*4;
				}
				else
				{
					msg =  "\n$HIY$nֻ��һ���ʹ,�ƺ���һ�������������˿Ѫ˿�� $COM";
					harm=(random(me->query("age")/3)+me->query("per")/2+1)*(random(me->query_skill("rouqing_zhi", 1)/10)+30)*4;
				}
				target->add("hp", -harm);
				if(target->query("hp")<1)target->set("hp",1);
				message_vision(msg.c_str(), me, target);
				snprintf(cmd ,255,"$HIY��������%d����˺���",harm);
				message_vision(cmd,me,target);
			}
			target->start_busy(6);
			me->add("mp", -300);
		}
		else
		{
			msg += "$HIM$p���Ī��Ĳ���������$P�����۾�����,���ȼ��ʱ��֪������\n$COM";
			message_vision(msg.c_str(), me, target);
			me->start_busy(6);
			me->add("mp", -300);
		}
	}
	else
	{
		msg += "$HIM����$p������$P����ͼ����û���ϵ���\n$COM";
		message_vision(msg.c_str(), me, target);
		me->start_busy(4);
		me->add("mp", -400);
	}
	
	return 1;
}

SKILL_END;




