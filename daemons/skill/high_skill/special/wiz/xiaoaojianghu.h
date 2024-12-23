//xiaoaojianghu.h Ц��������
//Ц��������֮�������

SKILL_BEGIN(CSxiaoaojianghu);

virtual void create()
{
	set_name( "Ц��������");

	Magic_t * magic;

	magic = add_magic("hezou", do_hezou);
	magic->name = "�������";
	magic->mp = 250;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char qin_action[255];
		char xiao_action[255];
		int  damage, force,  parry, dodge;
	}action[7] = {
		{"$N��ָ���ˣ�����$w����������СϪ�����ʹ�$n���ļ䡣",
		"$N�ֳ�$w�����ڴ��ߣ���������СϪ�����ʹ�$n���ļ䡣",
		5, 5, 5, 5},
		{"$N��ȻһЦ��������¶��ֱ����$n����һ��������Ҳ�·��������ϡ�",
		"$N��ȻһЦ��������¶��ֱ����$n����һ��������Ҳ�·��������ϡ�",
		8,8,8,8,},
		{"$N����һת����ָ�ֵ���$w����Ʈ��������ֱ����$n��Ѫ��ӿ���ѳֲ�ס��",
		"$N����һת��$w����Ʈ��������ֱ����$n��Ѫ��ӿ���ѳֲ�ס��",
		12,12,12,12,},
		{"$N��̾һ����$w����ת�ͣ�����������������������$n��ɫ��Ȼ��",
		"$N��̾һ����$w����ת�ͣ�����������������������$n��ɫ��Ȼ��",
		15, 15, 15, 15,},
		{"$N����΢̧������������$MAG���������Ψ����ǧ�С�$COM������$n�ε����顣",
		"$N����΢̧������������$MAG���������Ψ����ǧ�С�$COM������$n�ε����顣",
		16,16,16,16,},
		{"$NͻȻ��ɫ��Ȼ����ָһ����$w��Ȼ����һ������Ϯ��$n��",
		"$NͻȻ��ɫ��Ȼ�������������$wֱָ$n��",
		18,18,18,18,},
		{"$N����$w������ת��ת���ѵ���$n��ǰ��",
		"$N���$w������ת��ת���ѵ���$n��ǰ��",
		20,20,20,20,},
	};
 
  	int level = me->query_skill("string", 1);
	
	level = random(7);
	
	//�ж����������� qin or xiao
	CContainer * weapon = me->query_weapon();
	if(weapon && weapon->querystr("music_type") == "qin")
		m_actions.set("action", action[level].qin_action);
	else
		m_actions.set("action", action[level].xiao_action);

	m_actions.set("damage", action[level].damage);
	m_actions.set("force", action[level].force);
	m_actions.set("parry", action[level].parry);
	m_actions.set("dodge", action[level].dodge);
			
	return & m_actions;
};

const char * query_parry_msg(CContainer * weapon)
{
	if(! weapon) return 0;

	static char parry_msg[6][255] ={
		"$n��������������һ��$N��$N����һ���������˳��֡�",
		"$n��ƮƮ��Ծ�����ߣ���$N���˸��ա�",
		"���$N�Ĺ��ƣ�$n����һЦ������Ϊ�⣬�������Ʈ�����ߡ�",
		"$n�����������$n����ҡͷ��",
		"�����һ�������$n�Ѳ�������Ӱ��",
		"$n����������ɣ�����һ����Ӱ��ʧ�ˡ�",
	};

	return parry_msg[random(6)];
}

virtual int valid_enable(string usage) { return (usage == "music") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
	return 0;
}

virtual int practice_skill(CChar * me)
{
	return 0;
}

static int do_hezou(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *) ob;

	if( !me->is_fighting() )
		return notify_fail("��������ࡹֻ����ս����ʹ�á�");

	if(! target || ! target->is_fighting() || me->is_fighting(target) || target == me)
		return notify_fail("��������ࡹ��������˺��࣡");

	if(me->is_busy())
		return notify_fail("��������æ�ţ�");

	if (me->query_skill("music") < 100)		
		return notify_fail("������ɻ��������죡");

	if(target->query_skill("music") < 100)
		return notify_fail("�Է������ɻ��������죡");
	
	CContainer * qin = me->query_weapon();
	CContainer * xiao = target->query_weapon();
	
	if( ! qin || ! xiao)
		return notify_fail("û�������κ��࣡");

	int hezou = 0;
	if( EQUALSTR(qin->querystr("music_type"), "qin") && EQUALSTR(xiao->querystr("music_type"), "xiao"))
		hezou = 1;

	if( EQUALSTR(qin->querystr("music_type"), "xiao") && EQUALSTR(xiao->querystr("music_type"), "qin"))
		hezou = 2;

	if(! hezou)
		return notify_fail("û�������κ��࣡");

	if (me->query("mp") < 250)
		return notify_fail("�������������");

	if(target->query("mp") < 250)
		return notify_fail("�Է�������������");

	if(me->query_temp("music/tan") )
		return notify_fail("���Ѿ���ʼ���ࡸЦ�����������ˣ�");

	me->add("mp", -250);

	if(hezou == 1)		//��
		message_vision("\n\n\n             $MAG$N����̾�������䴦�����һ��$n$MAG����̧�ۣ����ֵ����⡣\n\n\n", me, qin);
	else				//��
		message_vision("\n\n\n             $HIY$N��ɷ����ת�����һ֧$n$HIY����̧�֣���������Ц�⡣\n\n\n", me, qin);

	me->start_busy(15);

	me->set_temp("music/tan", hezou);
		
	me->call_out(do_tan, 10, target->object_id(), hezou);
	return 1;	
}			

static void do_stop(CChar * me)
{
	CContainer * weapon = me->query_weapon();

	if(me->query_temp("music/tan") == 1)	//��
	{
		if(weapon )
			message_vision("\n\n\n             $MAGֻ�������һ�죬$n$MAG����һ�ң�$N��̾������ָ�Ͼ�����һ������Ѫ�ۣ�\n\n\n", me, weapon);
		else
			message_vision("\n\n\n             $MAG��̾��������̧��ʱ��ָ���Ѿ�����һ������Ѫ�ۣ�\n\n\n", me);
	}
	else		//��
	{
		if(weapon )
			message_vision("\n\n\n             $HIY$N���¿�����ת����ȥ����$n$HIY��Ȼ�ջ���ס�\n\n\n", me, weapon);
		else
			message_vision("\n\n\n             $HIY$N��̾��������̧��ʱ��ָ���Ѿ�����һ������Ѫ�ۣ�\n\n\n", me);
	}

	me->delete_temp("music");
}

static void do_tan(CContainer * ob, LONG param1, LONG hezou)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	//�����˲�����ڣ������Ѿ�ֹͣ�����ˡ�
	if( me->query_temp("music/tan") != hezou || ! target || ! me->is_fighting() || ! target->is_fighting() || target->is_fighting(me) ) 
	{
		do_stop(me);
		return;
	}

	if(! me->query_temp("music/hezou"))	//�����δ���࣬Ѱ�Һ�����
	{
		CContainer * qin = me->query_weapon();
		CContainer * xiao = target->query_weapon();

		if(! qin || !xiao)	//�ٻ��ﶪ��
		{
			do_stop(me);			
			return;
		}

		if( (hezou == 1 && target->query_temp("music/tan") != 2)
			|| (hezou == 2 && target->query_temp("music/tan") != 1))	//�Է�û�����
		{
			do_stop(me);
			return;
		}

		me->set_temp("music/hezou", 1);
		target->set_temp("music/hezou", 1);

		if(hezou == 1)	//��
		{
			message_vision("\n\n\n             $CYN$N�ḧ$n$CYN��һ�����ö�����������Ϫ��һ�㻺���ʹ�ÿ���˵��ĵס�", me, qin);
			message_vision("\n\n\n             $HIM$N����һЦ������̧��$n$HIM�����ڴ��ߣ�����������Ȼ���𣬺��ߺ��͡�\n\n\n", target, xiao);
		}
		else		//��
		{
			message_vision("\n\n\n             $HIM$N����һЦ������̧��$n$HIM�����ڴ��ߣ�����������Ȼ���𣬺��ߺ��͡�\n\n\n", target, xiao);
			message_vision("\n\n\n             $CYN$N�ḧ$n$CYN��һ�����ö�����������Ϫ��һ�㻺���ʹ�ÿ���˵��ĵס�", me, qin);			
		}
		
		me->start_busy(6);
		target->start_busy(6);

		//����������
		int times = ( me->query_skill("music") + target->query_skill("music")) / 25;
		me->call_out(do_repeat, 5, param1, times);
	}
	
	//�Ѿ��ں����ˣ�������
	me->call_out(do_tan, 1, param1, hezou);
	return;
}

//�ظ�
static void do_repeat(CContainer * ob, LONG param1, LONG times)
{
	static char desc[5][255] =
	{
		"$MAG\n             �����������������һ��ǿ��һ��������$N��Ѫ���ڡ�\n\n\n",
		"$HIC\n             ����ͻȻ���������Ȼ��ֹ��һ������ѹ�Ʋ�ס�������$N�۵Ŀ���һ����Ѫ��\n\n\n",
		"$HIG\n             �����ɸ�ת�ͣ������������࣬��ǿ������ֱ����$N��־��㱣�\n\n\n",
		"$HIB\n             ������������ת�ͣ�ʱ��ʱ�����������ͣ�$N��Ҳѹ�Ʋ�ס�ؼ�Ѫ����������Ѫ��\n\n\n",
		"$HIY\n             �����ߵ�ת�ߣ�������Ӱ���Σ�����$N��־���ң�������ӿ��\n\n\n"
	};

	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(! target) return;

	if(! times)
	{
		me->delete_temp("music");
		return;	//�ظ������ѵ�
	}

	if(! me->query_temp("music/hezou")) return;
	if(! target->query_temp("music/hezou")) return;

	//�ж���Ѫ
	if(me->query("hp") * 100 / me->query("max_hp") <= me->query("env/wimpy"))
		return;
	if(target->query("hp") * 100 / target->query("max_hp") <= target->query("env/wimpy"))
		return;

	message_vision("$HIR\n\n\n             $N��$n��ɫ��Ȼ�ĺ����š���\n\n\n", me, target);

	int skill = me->query_skill("music") + target->query_skill("music");

	//���������ڵ�ȫ����
	DTItemList search;
	POSITION p;
	CContainer * obj = NULL;
	CChar * who = NULL;
	
	CopyList(&search, (me->environment())->Get_ItemList());
	
	p = search.GetHeadPosition();
	while(p)
	{
		obj = search.GetNext(p);
		if( obj==me || obj == target)
			continue;
		if(! living(obj)) continue;
		
		who = (CChar *)obj;

		if( skill + random(skill) < who->query_skill("music") + who->query_skill("force") )
			continue;
					
		who->set_killer(me);
		me->set_killer(who);
		
		int damage = skill * 3 - (who->query("max_mp") / 5);
		if( damage > 0 )
		{
			who->receive_damage("mp", damage * 2);
			if( who->query("mp") < skill * 2 )
				who->receive_wound("hp", damage);
	
			message_vision(desc[random(5)], who);
		}
	}

	if(who)
		who->fight_ob(me);	//�����������˶�kill���ˡ�

	me->start_busy(6);
	target->start_busy(6);

	me->call_out(do_repeat, 5, param1, times - 1);
}

SKILL_END;

