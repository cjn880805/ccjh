// shenlong_bashi.h ������ʽ
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CSshenlong_bashi);

virtual void create()
{
	set_name( "������ʽ");
	set("valid_force", "shenlong_xinfa");

	Magic_t * magic;
	
	magic = add_magic("bada", do_bada);
	magic->name = "���ΰ˴�";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("tuzhu", do_tuzhu);
	magic->name = "��������";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("yingxiong", do_yingxiong);
	magic->name = "Ӣ����ʽ";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("meiren", do_meiren);
	magic->name = "��������";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
/*
	magic = add_magic("flower", do_flower);
	magic->name = "�ʵ��";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
*/
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  damage,dodge,parry,force;
		char damage_type[5];
	}action[] = {
		{"$Nʹһ�С���Ӱ��б��,��������һĨ����$n��$l��ȥ", 20, 0, 10, 100,"����",},		
		{"$N�������,˫��ʹһ�С��嶡��ɽ��������$n��$l", 30,0 , 30,0 ,"����",},		
		{"$N˳��ʹһ�С����в��ȡ����Ƽ�ת��,���ƻ���,����ֱ��$n", 40, 80, 20, 200,"����",},		
		{"$N�˺󼸲�,ͻȻ����һ��,һ�С�������β�����ޱȹ���ػ���$n", 50, 80, 20, 250,"����",},		
		{"$Nʹһʽ�������ơ���ȫ�������ת��˫��һǰһ���͵�����$n���ؿ�", 50, 10, 30,250 ,"����",},		
		{"$N����ʹ����Ǭ��������,����֧��,˫�ȷ�������$n", 60, -20 ,-20 , 250,"����",},		
		{"$N���һ����ʹ����ͬ���ھ���������һ�а�����$n", -25, -10, 60, 400,"����",},		
		{"$N����һ����,�����ǳ���״,��Ȼ���Ǹ��°�ֱײ��$n", 80, 70,-10 , 400,"����",},		
	};
		
	int level = 0;
	
	level = random(8);
	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("parry", action[level].parry);
	m_actions.set("damage", action[level].damage);
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "unarmed") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
//	if( DIFFERSTR(me->querystr("family/family_name"), "������"))
//		return	notify_fail("�����������̵��ӷ�����ѧϰ");

	if ( me->query_weapon()  )
		return notify_fail("��������ʽ������֡�");
	
	if ( me->query_skill("shenlong_xinfa", 1) < 50)
		return notify_fail("��������ķ���򲻹����޷�ѧ������ʽ.");
	
	if ( me->query_skill("force", 1) < 30)
		return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ������ʽ��");
	
	if ( me->query("max_mp") < 350)
		return notify_fail("�������̫�����޷���������ʽ��");
	
	if ( 2* me->query_skill("shenlong_xinfa",1) < me->query_skill("shenlong_bashi",1))
		return notify_fail("��������ķ���򲻹����޷�����ѧ������ʽ��");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if( DIFFERSTR(me->querystr("family/family_name"), "������"))
		return	notify_fail("�����������̵��ӷ�������ϰ");

	if ( me->query("hp") < 50)
		return notify_fail("�������̫���ˡ�");

	if ( me->query("mp") < 30)
		return notify_fail("�������������������ʽ��");

	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;	
}

int valid_combine(string combo) { return combo=="huagu_mianzhang"; }		//���Ժͻ����������

// bada ���ΰ˴�
static int do_bada(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	CContainer * weapon2;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target	||	!me->is_fighting(target))
		return notify_fail("$HIR���ΰ˴�$COMֻ�ܶ�ս���еĶ���ʹ�á�");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if ( me->query_weapon())
		return notify_fail("ֻ�п��ֲ���ʹ��$HIR���ΰ˴�$COM");
	
	if (! (weapon2 = target->query_weapon()))
		return notify_fail("�Է�û�б��У����ò������ΰ˴�");
	
	if (me->query_skill("shenlong_bashi", 1) < 60 )
		return notify_fail("���������ʽ�ȼ�����, �����ô˾��У�");
	
	if (me->query_skill("shenlong_xinfa", 1) < 60 )
        return notify_fail("$RED�������ķ���򲻹���ʹ���������ΰ˴򡹡�$COM");
	
	if( me->query("mp") < 50 )
		return notify_fail("��������������޷�ʹ�ô˾��У�");
	
	msg = "$HIY$NͻȻ������ǰ��ʹ��������ʽ�еľ��������˴�ֻ��$N��һ˫�ֹ��������á��С��ࡢ�ơ�����ˤ�����������Ӱ��$COM\n";
	
	me->add("mp",-50);

	if( random(me->query("combat_exp")) > (target->query("combat_exp") / 2) )
	{
		if(!weapon2->query("no_duo") || random(3))
		{
			if(userp(me))
				msg += "$HIR���$n���һ�������б������ɵ����ַɳ���$COM\n";
			
			if(weapon2->query("no_duo") )
			{
				char msg1[40];
				target->command(snprintf(msg1, 40, "unwield %ld", weapon2->object_id()));
			}
			else
			{
				weapon2->move(me->environment());
				if ( EQUALSTR(weapon2->querystr("owner"), target->id(1)) )
				{
					weapon2->move(target);
					msg += "$HIG�ǿ���$n������һ$n��һ�콫���������$COM\n";
				}
			}
		}
		me->start_busy(1);
	}
	if( random(me->query("combat_exp")) > (target->query("combat_exp") / 2) )
	{
		if(userp(me))
			msg += "$HIC���$n���һ����һ��æ�Ҳ�֪����!$COM\n";
		target->start_busy(random(6));
	}	
	else
	{
		msg += "$HIR��ϧ$n����ḻ����Ϊ������$N�Լ�ȴ������š�$COM\n";
		me->start_busy(4);
	}
	
	if(!target->is_fighting(me)) target->fight_ob(me);
	message_vision(msg.c_str(), me, target);
	return 1;
}

//	tuzhu	��������
static int do_tuzhu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

	int skill;
	int damage;

	skill = me->query_skill("shenlong_bashi", 1);

	if( !target	||	!me->is_fighting(target))
		return notify_fail("��������ֻ����ս����ʹ�á�");
	
	if ( me->query_weapon())
		return notify_fail("�������ֲ���ʹ���������飡");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
//	if( me->query_skill("zhaosheshu", 1) < 150 )
//		return notify_fail("���������������죬����ʹ���������顣");
	
	if( me->query_skill("shenlong_bashi", 1) < 150 )
		return notify_fail("���������ʽ������죬����ʹ���������顣");
	
	if (me->query_skill("shenlong_xinfa", 1) < 60 )
        return notify_fail("$RED�������ķ���򲻹���$COM");
	
	if( me->query("mp") < 300 )
		return notify_fail("�����������ˡ�");

	if( target->is_busy() )
		return notify_fail("%sĿǰ���Թ˲�Ͼ���ŵ������ɣ�", target->name());

	me->add("mp", -200);
	target->receive_damage("hp", skill/ 3);
	message_vision("$HIWֻ��һ����ɨҶ��������У�$N��һ�¿��ڣ�����ȫ����Ⱥ�����Ĺֽ�����$COM\n",me,target);
	if (random(me->query_skill("force")) > target->query_skill("force")/3
		&& random(me->query("combat_exp")) > target->query("combat_exp")/3 )
	{
		message_vision("$HIW������һ��������$n������ȥ���������顱��$n������ǰһ���ص������⣬$nɶҲ�������ˣ�$COM\n", me, target);
		target->set_temp("block_msg/all",1);
		damage = me->query_skill("zhaosheshu", 1);
		damage = damage + random(damage);
		target->receive_damage("hp", damage/2);
		target->receive_damage("hp", damage/2);
//		me->call_out(tuzhu_end,  skill/30, me, target);
		me->call_out(tuzhu_end,  skill/30);
		target->start_busy(me->query_skill("shenlong_bashi",1)/40 + 2 );
		me->start_busy(2);
//		return 1;
	} 
	else
	{
		message_vision("$HIW������һ��������$n������ȥ���������顱��$n������ǰһ���ص������⣬$nɶҲ�������ˣ�$COM\n", me, target);
			msg = "$HIY$p�鼱�������������ȿ���$P��������$COM\n";
		me->start_busy(2);
		message_vision(msg.c_str(), me, target);
	}
	if(!target->is_fighting(me)) target->fight_ob(me);
//	if(userp(target)) target->fight_ob(me);
//	else if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}

static void tuzhu_end(CContainer * ob, LONG nTarget, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(nTarget);

	if(! target) return;
	
	target->enable_player();
	message_vision("$NĨ��Ĩ������$HIR��Ѫ$COM�������������ۡ�", target);
	target->set_temp("block_msg/all", 0l);
	tell_object(me,"$HIR������Ĩ������������Ѫ����������Χ���龰��$COM");
	
	return;
}

//	yingxiong	Ӣ����ʽ
static int do_yingxiong(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

	int extra;
	CContainer * weapon;

	extra = me->query_skill("shenlong_bashi",1);

	if(me->is_busy())
		return notify_fail("������û�գ���");

	if( !target	||	!me->is_fighting(target))
		return notify_fail("��Ӣ����ʽ��ֻ����ս����ʹ�á�");
	
	if( DIFFERSTR(me->querystr("gender"), "����"))
		return notify_fail("�㲻�Ǵ���֮�壬������Ӣ����ʽ��");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if (me->query_weapon())
//	if( (weapon = me->query_weapon()) || (me->query_weapon())->querystr("base_name"), "secondary_weapon")
		return notify_fail("��Ӣ����ʽ��ֻ�ܿ���ʹ�á�");		
	
	if( me->query("mp") < 200 )
		return notify_fail("�������������");
	
	if( me->query_skill("shenlong_bashi",1) < 70 )
		return notify_fail("���������ʽ��򲻹����޷�ʹ�á�Ӣ����ʽ����");
	
	if( me->query_skill("shenlong_xinfa", 1) < 60 )
		return notify_fail("$RED�������ķ���򲻹���$COM");
	
	if( me->query_skill("force",1) < 60 )
		return notify_fail("����ڹ���Ϊ�������޷�ʹ�á�Ӣ����ʽ����");

	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",extra);
//	me->add_temp("apply/dexerity",extra);
//	me->add_temp("apply/dodge",extra);
	weapon = me->query_weapon();
	
	message_vision("$CYN$N����һ��������$n���һ��$HIY[Ӣ����ʽ]$CYN��$COM\n" ,me,target);
	if(target->query_temp("apply/no_Ӣ����ʽ") && random(me->query_combat_exp()) < target->query_combat_exp()/3 )
	{
		message_vision("����$n������$N����ͼ����û���ϵ���\n" ,me,target); 
	}
	else
	{
		message_vision("$RED-------------����������$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
		{                
			message_vision("$HIW��һ������$HIR����$n����$COM\n" ,me,target);
			target->apply_condition("snake_poison",10);
		}
		message_vision("$GRN-------------------����ٶ���$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		if (me->query("combat_exp")> target->query("combat_exp")/2 )
		{                
			message_vision("$HIC�ڶ�������$HIMɨ��$n������$COM\n" ,me,target);
		    target->apply_condition("wugong_poison",10);
		}
		message_vision("$MAG-------------------------³�������\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		if (random(me->query_skill("force")) > target->query_skill("force") / 2)
		{                
			message_vision("$MAG���һ������$HIBɨ��$n������!$COM\n" ,me,target);
			target->apply_condition("chanchu_poison",10);
		}
	}
	me->add_temp("apply/attack",-extra);
	me->add_temp("apply/damage",-extra);
//	me->add_temp("apply/dexerity",-extra);
//	me->add_temp("apply/dodge",-extra);
	me->add("mp", -150);
	me->start_busy(3);
	
	return 1;
}

//	meiren	��������
static int do_meiren(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
		
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
//	CContainer * weapon;

	if(me->is_busy())
		return notify_fail("������û�գ���");

	int extra = me->query_skill("shenlong_bashi", 1);

	if( !target	||	!me->is_fighting(target))
		return notify_fail("���������С�ֻ����ս����ʹ�á�");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if (DIFFERSTR(me->querystr("gender"), "Ů��"))
		return notify_fail("�㲻�Ǵ���֮�壬�������������У�");

	if (me->query_weapon())
//	if ( (weapon = me->query_weapon()) )
		return notify_fail("���������С�ֻ�ܿ���ʹ�á�");		
	
	if (me->query_skill("shenlong_xinfa", 1) < 60 )
        return notify_fail("$RED�������ķ���򲻹���$COM");
	
	if( me->query("mp") < 200 )
		return notify_fail("�������������");
	
	if( me->query_skill("shenlong_bashi",1) < 70 )
		return notify_fail("���������ʽ��򲻹����޷�ʹ�á��������С���");
	
	if( me->query_skill("force",1) < 60 )
		return notify_fail("����ڹ���Ϊ�������޷�ʹ�á��������С���");

	me->add_temp("apply/attack",  extra);
	me->add_temp("apply/damage", extra);
//	me->add_temp("apply/dex", extra);
//	me->add_temp("apply/dodge", extra);
	
	message_vision("$CYN$N�������ģ���$n΢΢һЦ$HIY[��������]$CYN��$COM\n" ,me,target);
	if(target->query_temp("apply/no_��������") && !random(2))
	{
		message_vision("����$n������$N����ͼ����û���ϵ���\n" ,me,target); 
	}
	else
	{
		message_vision("$RED-------------����������$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
		{                
			message_vision("$HIW��һ������$HIR����$n������$COM\n" ,me,target);
			target->apply_condition("snake_poison", 10);
		}
		message_vision("$GRN-------------------������裡$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		if (me->query("combat_exp")> target->query("combat_exp")/2 )
		{                
			message_vision("$HIC�ڶ�������$HIMɨ��$n������$COM\n" ,me,target);
		    target->apply_condition("wugong_poison", 10);
		}
		message_vision("$MAG-------------------------С����£�$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		if (random(me->query_skill("force")) > target->query_skill("force") / 2)
		{                
			message_vision("$MAG���һ������$HIBɨ��$n������!$COM\n" ,me,target);
			target->apply_condition("chanchu_poison", 10);
		}
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
//	me->add_temp("apply/dex", - extra);
//	me->add_temp("apply/dodge", - extra);
	me->add("mp", -150);
	me->start_busy(3);
	
	return 1;
}
/*
//	flower	�ʵ��
static int do_flower(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

	static char style_siqi[4][255] = {
		"$HIGСԷݺ��Ъ����$N����ᵯ����$w��ֱ��$n��$l��$COM",
			"$HIG���ŵ���࣭��$N����$w�������ƣ�Ʈ��$n��$l��$COM",
			"$HIG�ۿ�����ȥ����$N�����ڶ�������$w����ˮ��Ϯ��$n��$l��$COM",
			"$HIG��������������$N����$w������ǧ�����$n��$l��$COM" 
	};

//	static char style_qiusheng[3][255] = {
//		$HIR "��ɽ�续����$N����Ծ��ֱ�����죬����$w�������������϶��¹���$n��$l��\n" $COM,
//			$HIR "������������$N�����һ������������$w��Х��������$n��$l��\n" $COM,
//			$HIR "�������ڣ���$N����һ��������$wȦת��Х����ǿ������Х����Ȼһ�壬����$n��$l��\n" $COM
//	};

	static char style_mix[7][255] = {
		"$HIGСԷݺ��Ъ����$N����ᵯ����$w��ֱ��$n��$l��$COM" ,
			"$HIR��ɽ�续����$N����Ծ��ֱ�����죬����$w�������������϶��¹���$n��$l��$COM",
			"$HIG���ŵ���࣭��$N����$w�������ƣ�Ʈ��$n��$l��$COM",
			"$HIR������������$N�����һ������������$w��Х��������$n��$l��$COM",
			"$HIG�ۿ�����ȥ����$N�����ڶ�������$w����ˮ��Ϯ��$n��$l��$COM",
			"$HIR�������ڣ���$N����һ��������$wȦת��Х����ǿ������Х����Ȼһ�壬����$n��$l��$COM",
			"$HIG��������������$N����$w������ǧ�����$n��$l��$COM",
	};
	
	int skl_me, skl_you, extra_me, extra_you,i;
	int FLAG=0;
	object you,ob,*obs;
	CContainer * weapon;

	if( !target	||	!me->is_fighting(target))
		return notify_fail("$HIM�۲ʵ����ֻ�ܶ�ս���еĶ���ʹ�á�$COM");
	
	if( !(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("��ʹ�õ��������ǵ���");
	
	if( me->query_skill("zhaosheshu", 1) < 150 )
		return notify_fail("���������������졣");
	
	if( me->query_skill("shenlong_bashi", 1) < 250 )
		return notify_fail("���������ʽ������졣");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( me->query_skill("shedao_qigong", 1) < 150 )
		return notify_fail("��ı����ڹ�������졣");
	
	if( me->query("mp") < 300 )
		return notify_fail("�����������ˡ�");
	
	
	if(pointerp(obs=me->query_team()) )
	{
		FLAG=1;
		for(i=0;i<sizeof(obs);i++)
		{
			if(obs[i] == me) continue;
			if(!obs[i]) {FLAG=0; continue;}
			if(environment(obs[i]) != environment(me)) {FLAG=0; continue;}
			if(!obs[i]->query_skill("shenlong_bashi")) {FLAG=0; continue;}
			if(!objectp(ob=obs[i]->query_temp("weapon"))) {FLAG=0; continue;}
			if(ob->query("skill_type") != "parry"){FLAG=0; continue;}
			if(obs[i]->query_skill_mapped("parry") != "shenlong_bashi") {FLAG=0; continue;}
		}	
		if(sizeof(obs) !=2) FLAG=0;
	}
	skl_me=me->query_skill("parry");
	extra_me=me->query_temp("apply/damage")+me->query_str()*me->query_str()/30;
	if(FLAG)
	{
		if(obs[0]==me) you=obs[1]; else you=obs[0];
		skl_you=you->query_skill("parry",1);
		extra_you=you->query_temp("apply/damage")+you->query_str()*you->query_str()/30;
        me->add_temp("apply/attack",(skl_you+skl_me)/4);
        me->add_temp("apply/damage",(extra_you+extra_me)/2);
        you->add_temp("apply/attack",(skl_you+skl_me)/4);
        you->add_temp("apply/damage",(extra_you+extra_me)/2);
        you->kill_ob(target);
		for(i=0;i<sizeof(style_mix);i++)
			if(i%2) COMBAT_D->do_attack(you,target,you->query_temp("weapon"),TYPE_REGULAR,style_mix[i]);
			else    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,style_mix[i]);
			me->add_temp("apply/attack",-(skl_you+skl_me)/4);
			me->add_temp("apply/damage",-(extra_you+extra_me)/2);
			you->add_temp("apply/attack",-(skl_you+skl_me)/4);
			you->add_temp("apply/damage",-(extra_you+extra_me)/2);
	}
	else
	{
        me->add_temp("apply/attack",skl_me/10);
        me->add_temp("apply/damage",extra_me/3);
        for(i=0;i<sizeof(style_siqi);i++)
			COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,style_siqi[i]);
        me->add_temp("apply/attack",-skl_me/10);
        me->add_temp("apply/damage",-extra_me/3);
	}	
	if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
	{                
        msg = "$HIW��һ������$HIR����$n������$COM\n";   
        message_vision(msg.c_str(), me, target);
        target->apply_condition("snake_poison",10);
	}
	if (me->query("combat_exp")> target->query("combat_exp")/2 )
	{                
        msg += "$HIC�ڶ�������$HIMɨ��$n������$COM\n";   
		message_vision(msg.c_str(), me, target);
        target->apply_condition("wugong_poison",10);
	}
	if (random(me->query_skill("force")) > target->query_skill("force") / 2)
	{                
        msg += "$MAG���һ������$HIBɨ��$n������!$COM\n";   
        message_vision(msg.c_str(), me, target);
        target->apply_condition("chanchu_poison",10);
	}
	me->start_busy(2);
	return 1;
}
*/

SKILL_END;




