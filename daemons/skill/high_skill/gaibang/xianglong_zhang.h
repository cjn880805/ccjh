// xianglong_zhang.c ����ʮ����
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSxianglong_zhang);

virtual void create()
{
	set_name( "����ʮ����");
	set("valid_force", "huntian_qigong");
	
	set("diff",130);
	
	Magic_t * magic;
	
	magic = add_magic("leiting", do_leiting);
	magic->name = "����һ��";
	magic->mp = 350;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("xianglong", do_xianglong);
	magic->name = "������";
	magic->mp = 300;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
	
	magic = add_magic("wuhuei", do_wuhuei);
	magic->name = "�����޻�";
	magic->mp = 1500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  dodge,parry,force;
		char damage_type[5];
	}action[] = {
		{"$Nʹ����ͻ�������������ƴӲ����ܵĽǶ���$n��$l�Ƴ�",-10 ,10 , 220,"����",},
		{"$N����һ�С����������Ѹ���ޱȵ�����$n��$l", -20, -10, 240,"����",},
		{"$N˫��ʩ��һ�С��轥��½�����������ŷ�������$n��$l", -25, -10,260 ,"����",},
		{"$N���λ�����˫��ʹһ�С�˫��ȡˮ��һǰһ����$n��$l", -20,20 , 280,"����",},
		{"$NͻȻ���η���˫�ƾӸ�����һ�С��������졹����$n��$l", -25,-20 , 300,"����",},
		{"$N���ƾ۳�ȭ״������һ�С�Ǳ�����á���������$n��$l", -20, 10, 310,"����",},
		{"$Nʹ��������ެ����˫���������ϻ���$n��$l", -25, 40, 320,"����",},
		{"$Nʹ�������Ʋ��꡹�����Ʒ�ס$n����·������бб������$l", -25,20 , 330,"����",},
		{"$N���ƻ��أ�����ʹһ�С�������β�����»ζ��Ż���$n��$l", -20, 40, 340,"����",},
		{"$Nʹ������Ծ��Ԩ������$n��$l��������", -30, -20, 350,"����",},
		{"$Nʩ��һ�С�����󴨡������Ʋ�������������$n��$l", -30, 20, 360,"����",},
		{"$Nʹ������Ծ��Ԩ�������η���˫�Ʋ���һ����$n��$l����", -40, 30,370 ,"����",},
		{"$N˫������ʹ����ʱ����������$n��������", -40, 20, 390,"����",},
		{"$N���һ����˫��ʹ�����𾪰��������һ�а����$n", -45, -10, 420,"����",},
		{"$N�Ż��󿪣�һ�С���˪��������$n��$l��ȥ", -45, 1,440 ,"����",},
		{"$N����һת��ͻȻ�۵�$n��ǰ��һ�С���ս��Ұ������$n��$l", -40, 40, 450,"����",},
		{"$Nʹ�����������ڡ���˫�������������$n��$l", -45, 10, 470,"����",},
		{"$N˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ���������лڡ�����$n��$l", -50, 10, 650,"����",},
	};
	
	int level = 0;
	
	if( me->query_temp("xianglong") 
		&& ( me->query("mp") > 20 ) )
	{
		me->add_temp("apply/str", me->query_temp("str_count"));
		me->add("mp", -20);
		me->add_temp("str_no", 1);
		me->add_temp("display_no", 1);
		if( me->query_temp("display_no") == 2 )
		{
			message_vision( "$HIY$N������һ������ԽսԽ�£�", me);
			me->set_temp("display_no", 0l);
		}
	}
	
	level = random(18);
	if(me->query_temp("wuhei"))
	{
		switch(me->query_temp("wuhei"))
		{
		case 1:
			m_actions.set("action", "$HIC$N����һת��ͻȻ����$n��ǰ������бת��סȫ�������˾�һ�С���ս��Ұ������Ȼ����$n��$l��");
			break;
		case 2:
			m_actions.set("action", "$HIB$N������ǰ�ƶ���˫�Ʒ�ʹ��ʽ��˫��ȡˮ�����������Ʒ�һ��һ�ң���ȴ�����Ⱥ�ͬʱѹ��$n$l��");
			break;
		case 3:
			m_actions.set("action", "$HIY$Nһ��δ�꣬һ���������ƻ��գ��������Һ��ƣ�һ�С����������Ѹ���ޱȵ�����$n��$l��");
			break;
		case 4:
			m_actions.set("action", "$HIG$N���ƾ۳�ȭ״����$n�ֱۣ�����������ǰ�Ƴ���һ�С�Ǳ�����á����ۻ����������ѹ��$n��");
			break;
		case 5:
			m_actions.set("action", "$HIB����$N���ƻ��أ������ת������$n�����ƽ�����һ�ڣ�һ�С�������β����������$n��");
			break;
		case 6:
			m_actions.set("action", "$HIW$NͻȻһԾ�����գ�������ת��˫�ƾӸ����£�һ�С��������졹ֱ�����µ�$nѹȥ��");
			break;
		}
	}
	else
		m_actions.set("action", action[level].action);
	m_actions.set("force", (me->query("skill_pro/ؤ��/����ʮ����/force")+100) * action[level].force/100);
	m_actions.set("dodge", (me->query("skill_pro/ؤ��/����ʮ����/dodge")+100) * action[level].dodge/100);
	m_actions.set("parry", (me->query("skill_pro/ؤ��/����ʮ����/parry")+100) * action[level].parry/100);
	
	return &m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "unarmed") || (usage == "parry");
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/ؤ��/����ʮ����/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/ؤ��/����ʮ����/force"));
			if(me->query("skill_pro/ؤ��/����ʮ����/force_point")>=level_point)
			{
				me->add("skill_pro/ؤ��/����ʮ����/force",1);
				me->set("skill_pro/ؤ��/����ʮ����/force_point",1);
				tell_object(me,"\n$HIR��Ľ���ʮ��������ڹ������ڻ��ͨ�ˡ�\n");
			}
		}
		else if(victim->query("parry")) 
		{
			me->add("skill_pro/ؤ��/����ʮ����/parry_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/ؤ��/����ʮ����/parry"));
			if(me->query("skill_pro/ؤ��/����ʮ����/parry_point")>=level_point)
			{
				me->add("skill_pro/ؤ��/����ʮ����/parry",1);
				me->set("skill_pro/ؤ��/����ʮ����/parry_point",1);
				tell_object(me,"\n$HIR��������ʹ�ý���ʮ���ƣ�����������һ����ǿ�ˡ�\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/ؤ��/����ʮ����/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/ؤ��/����ʮ����/dodge"));
			if(me->query("skill_pro/ؤ��/����ʮ����/dodge_point")>=level_point)
			{
				me->add("skill_pro/ؤ��/����ʮ����/dodge",1);
				me->set("skill_pro/ؤ��/����ʮ����/dodge_point",1);
				tell_object(me,"\n$HIR��Ľ���ʮ����ʹ�õø��ӵ���Ӧ���ˡ�\n");
			}
		}
	}
	return "";
}

virtual int valid_learn(CChar * me)
{
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("���ʦ����ʱû��ָ�����书����");
	
	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("����ʱ�޷�ָ������µ��书����");
	
	if (me->query_weapon())
		return notify_fail("������ʮ���Ʊ�����֡�");
	if (me->query_skill("huntian_qigong", 1) < 20)
		return notify_fail("��Ļ���������򲻹����޷�������ʮ���ơ�");
	if (me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷�������ʮ���ơ�");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 40)
		return notify_fail("�������̫���ˡ�");
	if (me->query("mp") < 10)
		return notify_fail("�����������������ʮ���ơ�");
	me->receive_damage("hp", 30);
	me->add("mp", -5);
	return 1;
}

//perform 
static int do_leiting(CChar * me, CContainer * ob)
{
	int damage;
	CChar * target = NULL;
	string msg;
	char cmd[255];
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target || !me->is_fighting(target) )
		return notify_fail("������һ����ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "ؤ��") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( me->query_skill("huntian_qigong", 1) < 100 )
		return notify_fail("��Ļ���������򲻹���ʹ����������һ������");
	
	if( me->query_skill("xianglong_zhang", 1) < 100 )
		return notify_fail("��Ľ���ʮ���Ʋ�������������ʹ�á�����һ������");
	
	if( me->query("mp") < 500 )
		return notify_fail("���������Ϊ�������ߡ�");
	
	if (me->query_weapon() )
		return notify_fail("������һ����������ֲ���ʹ�á�");
	
	msg = "$NĬ�˻���������ʩչ��������һ������ȫ����ת��������Խ��Խ�죬������һ�����磬��Ȼ�䣬$N�Ѿ��������÷�����$n��\n";  
	
	if(random(me->query_combat_exp()) > target->query_combat_exp()/3) 
	{ 
		me->start_busy(3);
		target->start_busy(random(3));
		me->add("mp", -350);
		damage = me->query_skill("xianglong_zhang", 1)*6+me->query_skill("huntian_qigong",1)*2;
		
		damage = damage + random(damage);
		if(me->query("kill/guilt")>100)
		{
			damage = damage - me->query("kill/guilt")*20;
			if(damage<0)
			{
				damage=200;
			}
		}
		if(me->query("kill/guilt")< target->query("kill/guilt") && target->query("kill/guilt")>50)
		{
			damage = damage + target->query("kill/guilt")*20;
			if(target->query("kill/guilt")>150)
			{
				msg +=" $N��Ȼ��ȵ���$n����������ҽ���Ҫ�����е���\n";
			}
		}
		if(damage >=target->query("hp"))
		{
			damage=target->query("hp")-10;
		}
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/2);
		me->start_busy(1);
		msg += "$nֻ��һ������Ӱ�ж�Ȼ�ֳ�$N��˫ȭ��������������ܣ������ػ��У������������ڲ��ݣ�������Ѫ��������������";
		message_vision(msg.c_str(), me, target);
		snprintf(cmd,255,"$HIR��������%d����˺���$COM\n",damage);
		message_vision(cmd,me,target);
	}
	else
	{
		me->add("mp", -50);
		me->start_busy(1);
		msg += "����$p������$P����ͼ��������һ�ߡ�";
		message_vision(msg.c_str(), me, target);
	}
	
	
	if(!target->is_fighting(me)) target->kill_ob(me);
	return 1;
	
}

static int do_xianglong(CChar * me, CContainer * ob)
{
	int skill, count;
	
	if( me->query_temp("xianglong") ) 
		return notify_fail("���Ѿ����˹����ˡ�");
	
	if( !me->is_fighting() )
		return notify_fail("������ֻ����ս����ʹ�á�");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "ؤ��") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( me->query_skill("xianglong_zhang", 1) < 150 )
		return notify_fail("��Ľ���ʮ���Ʋ�������������ʹ�á������󷨡���");
	
	if( me->query("mp") < 300  ) 
		return notify_fail("�������������");
	
	count = me->query("str");
	skill = me->query_skill("xianglong_zhang",1);
	me->add("mp", -100);
	message_vision(  "$N����һ�������������󷨣����ԽսԽ�£�" , me);
	me->set_temp("xianglong", 1);
	me->set_temp("str_count", count/5);
	me->set_temp("str_no", 0l);
	me->set_temp("display_no", 0l);
	me->call_out(remove_effect, skill / 2 );
	return 1;
}

static void remove_effect(CContainer *ob, LONG amount, LONG param)
{
	CChar *me =(CChar *) ob;
	
	LONG dmount = me->query_temp("str_no") * me->query_temp("str_count");
	me->add_temp("apply/str", - dmount );
	me->delete_temp("xianglong");
	me->delete_temp("str_count");
	me->delete_temp("str_no");
	me->delete_temp("display_no");
	
	tell_object(me, "��Ľ�����������ϣ��������ջص��");
}

static int do_wuhuei(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	string msg;
	int extra = me->query("death_times");
	if (extra>50)	extra = 50;
	if(extra<1)		extra=1;
	if(wizardp(me))		extra=99;
	
	if( !target	||!me->is_fighting(target) )
		return notify_fail("��$HIY��$HIC��$HIW��$HIR��$COM��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	if (me->query_weapon() )
		return notify_fail("��������ʹ�á�$HIY��$HIC��$HIW��$HIR��$COM����\n");
	
	if( (int)me->query_skill("xianglong_zhang", 1) < 220 )
		return notify_fail("��Ľ���ʮ���Ʋ�����죬�޷�ʩչ����$HIY��$HIC��$HIW��$HIR��$COM����\n");
	
	if (me->query_skill("huntian_qigong", 1)<220)
		return notify_fail("��ı����ڹ����δ����\n");
	
	if(me->query_temp("gaibang/linglong"))
		return notify_fail("��Ľ�����������,�޷�����ʩչ��$HIY��$HIC��$HIW��$HIR��$COM����\n");
	
	if(!me->query("����/gaibang/wuhui"))
		return notify_fail("�㻹û����ᵽ����ʮ�������������书��\n"); 
	
	if(DIFFERSTR(me->querystr("family/family_name"), "ؤ��") && me->Query(CChar::IS_USER) )
		return notify_fail("����Ȼ��˵����$HIY��$HIC��$HIW��$HIR��$COM����һ�У�������������ʹ�õľ������ڡ�\n");
	
	if (DIFFERSTR(me->query_skill_mapped("unarmed"), "xianglong_zhang"))
		return notify_fail("��$HIY��$HIC��$HIW��$HIR��$COM���޷����м���ʹ�á�\n");
	
	if (me->query("max_mp") < 3000)
		return notify_fail("��������������޷�ʩչ����$HIY��$HIC��$HIW��$HIR��$COM����\n");
	
	if (me->query("mp") < 1500)
		return notify_fail("��������������޷�ʩչ����$HIY��$HIC��$HIW��$HIR��$COM����\n");
	
	me->add_temp("apply/str", extra);
	me->add_temp("apply/attack", extra*6);
	me->add_temp("apply/damage", extra);
	me->add("mp", -1500);
	
	char msg1[255],tmp[80];
	message_vision(snprintf(msg1, 255,
		"$HIR\n\n$N�����Լ�ƽ����������%s������Σ����\n\n�����ִ���������ͷ����������������\n\n$HIW˫��ƽƽ�ᵽ��ǰ��ʹ������ʮ���Ƶ�����ѧ��$HIY��$HIC��$HIW��$HIR��$HIW������ɽ����������$n��" ,
		chinese_number(me->query("death_times"),tmp)), me, target); 
	
	for(int i=0;i<6;i++)
	{
		me->add_temp("wuhei",1);
		if(me->is_fighting(target)) 
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	}
	me->delete_temp("wuhei");
	
	me->add_temp("apply/str", -extra);
	me->add_temp("apply/attack", -extra*6);
	me->add_temp("apply/damage", -extra);
	
	if( random(me->query("combat_exp")) > target->query("combat_exp")/4 && me->is_fighting(target))
		//&& me->query("xlz/hang")
	{
		msg = "$HIR\n\n$Nҧ�����أ�˫�ƻ�������Ĭ���ʮ���ƵĿھ�!    $HIY��  $HIC��  $HIW��  $HIR��$COM ";
		msg += "$RED\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n";
		target->receive_damage("hp",me->query_skill("strike")*5+random(me->query_skill("strike")));
		target->receive_wound("hp",me->query_skill("strike")*5);
		
		if (!target->is_busy()) target->start_busy(2);
		message_vision(msg.c_str(), me, target);
	}
	me->start_busy(6);
	me->set_temp("gaibang/wuhuei",1);
	
	if(EQUALSTR(target->querystr("family/family_name"), "ؤ��") && !target->query_weapon() 
		&&  (int)target->query_skill("xianglong_zhang", 1) > 220 && !target->query("����/gaibang/wuhui")
		&& EQUALSTR(target->query_skill_mapped("unarmed"), "xianglong_zhang")
		&& target->query("hp") > target->query("max_hp")/10)
	{
		target->add("����/gaibang/wuhui_imp",1);
		if(target->query("����/gaibang/wuhui_imp")>1000)
		{
			tell_object(target, "$HIR���Դ��˵�һ��ը�죬���ֵĸղ�ÿһ��������ͬ�����������Ժ������֣���һ�μ��ţ������Ѿ��������ᵽ�ˡ�$HIY��$HIC��$HIW��$HIR��$COM���ľ������ڡ�\n���������������������������ڴ����ж����˽���ʮ���Ƶ����Ͼ�ѧ��$HIY��$HIC��$HIW��$HIR��$COM����");
			target->set("����/gaibang/wuhui",1);
			target->del("����/gaibang/wuhui_imp");
			target->set("mp",0l);
			if(target->query("hp")>1)
			{
				target->set("hp",1);
				target->set("eff_hp",1);
			}
		}
		else
			tell_object(target, "$HIR�����ȥ��ǵ�Ѫ������ס������������������������һ�����������Ŷ��ֵ����Σ�������˼��");
	}
				
	int delay=100-extra;
	if(delay<1)
		delay=1;
	me->call_out(remove_effect1, delay);
	return 1;
}

static void remove_effect1(CContainer * ob, LONG param1, LONG count)
{
	CChar * me = (CChar *)ob;
	if(me->query_temp("gaibang/wuhuei"))
		me->delete_temp("gaibang/wuhuei");
}

SKILL_END;




