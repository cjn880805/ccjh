// hamagong.c ��󡹦

// code by Fisho
// date : 2000-11-28

void reserve_remove_effect(CContainer * ob, LONG amount_one, LONG amount_two)
{
	CChar * me = (CChar *)ob;
	
	me->add_temp("apply/attack", - amount_one);
	me->add_temp("apply/dodge", - amount_two);
	me->delete_temp("hmg_dzjm");
	
	me->SendState(me);
	tell_object(me, "��˫��һ�ţ�һԾ���𣬽������ջص��");
}


FORCE_BEGIN(CShamagong);

virtual void create()
{
	CForce::create();
	
	set_name( "��󡹦");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "������";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("powerup", do_powerup);
	magic->name = "������";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("qudu", do_qudu);
	magic->name = "������";
	magic->mp = 200;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("reserve", do_reserve);
	magic ->name = "������ת";
	magic->mp = 300;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
}

int valid_enable(string usage) { return usage == "force"; }

virtual int valid_learn(CChar * me)
{
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("���ʦ����ʱû��ָ�����书����");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("����ʱ�޷�ָ������µ��书����");
	
	int i = me->query_skill("hamagong", 1);
	int t = 1, j;

	if( i <= 100)
		for (j = 1; j < i / 10; j++)
			t*= 2;

	if ( EQUALSTR(me->querystr("gender"), "����") && i > 49)
		return notify_fail("���޸����ԣ���������������������ĸ�󡹦��");
	if (me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ�����㣬����ѧ��󡹦��");

	if(i<=100)
	{
		if (i > 10 && -me->query("repute") < t * 100) 
			return notify_fail("ѧ��󡹦��Ҫ�ĺ���������������������ò���ѽ��");
	}
	else
	{
		if (-me->query("repute") < (51200 + (i - 100) * 1000)) 
			return notify_fail("ѧ��󡹦��Ҫ�ĺ���������������������ò���ѽ��");
	}

	if ( me->query_skill("bibo_shengong",1)
	|| me->query_skill("beiming_shengong",1)
	|| me->query_skill("bahuang_gong",1)
//	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong_dafa",1)
	|| me->query_skill("huntian_qigong",1)
	|| me->query_skill("hunyuan_yiqi",1)
	|| me->query_skill("longxiang",1)
	|| me->query_skill("jiuyang_shengong",1)
	|| me->query_skill("taiji_shengong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong_shengong",1)
	|| me->query_skill("zixia_shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��󡹦����");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("��󡹦ֻ������̵������������ȡ�");
}

static int do_heal(CChar * me, CContainer * target)
{
	char msg[255];

	if( me->is_fighting() )
			return notify_fail("ս�����˹����ˣ�������");
	
	if (me->query_skill("hamagong", 1) < 20)
		return notify_fail("��ĸ�󡹦��Ϊ��������");
	
	if( me->query("mp") < 50 )
		return notify_fail("�������������");

	if( me->query("eff_hp") < me->query("max_hp") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�");

	tell_object(me, "��ȫ����ɣ���������ʼ�˹����ˡ�");
	tell_room(me->environment(), snprintf(msg, 255, "%s�³�һ����Ѫ����ɫ�������ö��ˡ�", me->name()), me);
	
	me->receive_curing("hp", 10 + me->query_skill("force") / 3 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
	me->start_busy(4);
	return 1;
}

static int do_powerup(CChar * me, CContainer * target)
{
	int skill;

	if( target != me )
		return notify_fail("��ֻ���ø�󡹦�������Լ���ս������");

	if( me->query("mp") < 100  )
		return notify_fail("�������������");

	if( me->querymap_temp("powerup") )
		return notify_fail("���Ѿ����˹����ˡ�");
		
			if(DIFFERSTR(me->querystr("family/family_name"), "����ɽ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	skill = me->query_skill("force");
	me->add("mp", -90);
	me->receive_damage("hp", 0);
	message_vision("$N΢һ���������󡹦��ȫ��ǽڷ���һ�󱬶��������", me );
	
	start_powerup(me, skill, skill/3, skill/3, "��ĸ�󡹦������ϣ��������ջص��");

	if( me->is_fighting() ) me->start_busy(3);
	return 1;
}

static int do_qudu(CChar * me, CContainer * ob)
{
	char msg[255];

    if( me->is_fighting() )
		return notify_fail("ս���в��ܱƶ���");
		
			if(DIFFERSTR(me->querystr("family/family_name"), "����ɽ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
    if ( me->query_skill("hamagong", 1) < 40)
		return notify_fail("��ĸ�Ī����Ϊ��������");

    if(  me->query("mp") <  me->query("max_mp")/15 ) 
		return notify_fail("�������������");
	
    tell_object(me,   "��ȫ����ɣ���������ʼ�˹��ƶ���"  );
	tell_room(me->environment(),snprintf(msg,255,"%s�������˹��ƶ���",me->name()),me);

	if ( me->query("condition/zm_poison") > 0 )
	{
		if ( me->query("condition/zm_poison") <  me->query_skill("hamagong",1)/20 + 1 )
		{
			me->apply_condition("zm_poison", 0);
			message_vision( "$N ���ϵ� ��ĸ����֮�� ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else {
			me->apply_condition("zm_poison",  me->query("condition/zm_poison") - me->query_skill("hamagong",1)/20 );
			message_vision( "$N ���ϵ� ��ĸ����֮�� ��ȥС�� ��ɫ��������������" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
		
	}

	if ( me->query("condition/ice_poison") > 0 )
	{
		if ( me->query("condition/ice_poison") <  me->query_skill("hamagong",1)/20+1 )
		{
			me->apply_condition("ice_poison", 0);
			message_vision( "$N ���ϵ� �������� ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else 
		{
			me->apply_condition("ice_poison",  me->query("condition/ice_poison") - me->query_skill("hamagong",1)/20);
			message_vision( "$N ���ϵ� �������� ��ȥС�� ��ɫ��������������" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
		
	}
	if ( me->query("condition/jy_poison") > 0 )
	{
		if ( me->query("condition/jy_poison") <  me->query_skill("hamagong",1)/20+1 )
			
		{
			me->apply_condition("jy_poison", 0);
			message_vision( "$N ���ϵ� �����׹�צ�� ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else {
			me->apply_condition("jy_poison",  me->query("condition/jy_poison") - me->query_skill("hamagong",1)/20);
			message_vision( "$N ���ϵ� �����׹�צ�� ��ȥС�� ��ɫ��������������" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	
    if ( me->query("condition/xx_poison") > 0 )
	{
		if ( me->query("condition/xx_poison") <  me->query_skill("hamagong",1)/20+1 )
			
		{
			me->apply_condition("xx_poison", 0);
			message_vision( "$N ���ϵ� �����ƶ� ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else 
		{
			me->apply_condition("xx_poison",  me->query("condition/xx_poison") - me->query_skill("hamagong",1)/20);
			message_vision( "$N ���ϵ� �����ƶ� ��ȥС�� ��ɫ��������������" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	
    if ( me->query("condition/ss_poison") > 0 )
	{
		if ( me->query("condition/ss_poison") <  me->query_skill("hamagong",1)/8+1 )
			
		{
			me->apply_condition("ss_poison", 0);
			message_vision( "$N ���ϵ� ������ ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else {
			me->apply_condition("ss_poison",  me->query("condition/ss_poison") - me->query_skill("hamagong",1)/8);
			message_vision( "$N ���ϵ� ������ ��ȥС�� ��ɫ��������������" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	
	if ( me->query("condition/dog_poison") > 0 )
	{
		if ( me->query("condition/rose_poison") <  me->query_skill("hamagong",1)/20+1 )
		{
			me->apply_condition("dog_poison", 0);
			message_vision( "$N ���ϵ� ��õ�嶾 ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else
		{
			me->apply_condition("dog_poison",  me->query("condition/dog_poison") - me->query_skill("hamagong",1)/20);
			message_vision( "$N ���ϵ� ��õ�嶾 ��ȥС�� ��ɫ��������������" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	
	if ( me->query("condition/zhua_poison") > 0 )
	{
		if ( me->query("condition/zhua_poison") <  me->query_skill("hamagong",1)/20+1 )
		{
			me->apply_condition("zhua_poison", 0);
			message_vision( "$N ���ϵ� ��Ѫ��צ ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else 
		{
			me->apply_condition("zhua_poison",  me->query("condition/zhua_poison") - me->query_skill("hamagong",1)/20);
			message_vision( "$N ���ϵ� ��Ѫ��צ ��ȥС�� ��ɫ��������������" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	
	if ( me->query("condition/snake_poison") > 0 )
	{
		if ( me->query("condition/snake_poison") <  me->query_skill("hamagong",1)/20+1 )
			
		{
			me->apply_condition("snake_poison", 0);
			message_vision( "$N ���ϵ� �߶� ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else 
		{
			me->apply_condition("snake_poison",  me->query("condition/snake_poison") - me->query_skill("hamagong",1)/20);
			message_vision( "$N ���ϵ� �߶� ��ȥС�� ��ɫ��������������" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}

    if ( me->query("condition/wudu_poison") > 0 )
	{
		if ( me->query("condition/wudu_poison") <  me->query_skill("hamagong",1)/20+1 )
			
		{
			me->apply_condition("wudu_poison", 0);
			message_vision( "$N ���ϵ� �嶾�� ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else 
		{
			me->apply_condition("wudu_poison",  me->query("condition/wudu_poison") - me->query_skill("hamagong",1)/20);
			message_vision( "$N ���ϵ� �嶾�� ��ȥС�� ��ɫ��������������" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}

	if ( me->query("condition/yufeng_poison") > 0 )
	{
		if ( me->query("condition/yufeng_poison") <  me->query_skill("hamagong",1)/20+1 )
			
		{
			me->apply_condition("yufeng_poison", 0);
			message_vision( "$N ���ϵ� ����붾 ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else 
		{
			me->apply_condition("yufeng_poison",  me->query("condition/yufeng_poison") - me->query_skill("hamagong",1)/20);
			message_vision( "$N ���ϵ� ����붾 ��ȥС�� ��ɫ��������������" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}

    if ( me->query("condition/bingpo_poison") > 0 )
	{
		if ( me->query("condition/bingpo_poison") <  me->query_skill("hamagong",1)/20+1 )
			
		{
			me->apply_condition("bingpo_poison", 0);
			message_vision( "$N ���ϵ� �������붾 ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else
		{
			me->apply_condition("bingpo_poison",  me->query("condition/bingpo_poison") - me->query_skill("hamagong",1)/20);
			message_vision( "$N ���ϵ� �������붾 ��ȥС�� ��ɫ��������������" , me);
		}
		
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	else 
		tell_object(me, "������û���ж���"   );
	return 1;
	
}

static int do_reserve(CChar * me, CContainer * target)
{
	int skill;
	
	if( me->query_skill("hamagong", 1) < 40 )
		return notify_fail("��ĸ�󡹦������죬���ᾭ����ת��");
	
	if( me->query("mp") < 500  ) 
		return notify_fail("�������������");
	
	if( me->query_temp("hmg_dzjm") ) 
		return notify_fail("���Ѿ���ת�����ˡ�");
		
			if(DIFFERSTR(me->querystr("family/family_name"), "����ɽ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
		
	
	skill = me->query_skill("hamagong",1);

	message_vision("$N����˫�ֳŵص��������˾�������ʱ��Ϣ������������������", me);
	
	if(!me->query_temp("tjj_sui") && !me->query_temp("qzj_tong") && !me->query_temp("hsj_wu") && !me->query_temp("hmg_dzjm"))
	{
		me->add_temp("apply/attack", -skill/6);
		me->add_temp("apply/dodge", skill/2);
		me->set_temp("hmg_dzjm", 1);
		me->call_out(reserve_remove_effect, skill, -skill/6, skill/2);
	}
		
	me->add("mp", -300);
	if( me->is_fighting() ) me->start_busy(2);
		
	return 1;
}

FORCE_END;




