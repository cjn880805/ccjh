
// xiantian_gong.h ������
//code by Fisho
//date : 2000-12-07

FORCE_BEGIN(CSxiantian_gong);

virtual void create()
{
	CForce::create();

	set_name( "������");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "������";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("life_heal", do_life_heal);
	magic->name = "ҽ����";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("bidu", do_bidu);
	magic->name = "�ƶ�";
	magic->mp = 0;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMMON;
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force")  ;
}

virtual int valid_learn(CChar * me)
{
	int lvl =  me->query_skill("xiantian_gong", 1);
	int t = 1, j;
	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;
	if ( DIFFERSTR(me->querystr("family/master_id"), "wang chongyang"))
		return notify_fail("������ֻ�ܸ�������ʦѧϰ��");

	if ( EQUALSTR(me->querystr("gender"), "����") && lvl > 49)
		return notify_fail("���޸����ԣ���������������������������񹦡�");
	
	if ( EQUALSTR(me->querystr("class"), "bonze") )		
		return notify_fail("�����񹦽����������ϣ���Υ��������徻֮�⣬%s���޴˹������������",query_respect(me));
	
	if ( me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����");
	
	if(lvl<=100)
	{
		if (lvl > 10 &&  me->query("repute") < t * 100) 
			return notify_fail("�����������̫���ˡ�");
	}
	else
	{
		if ( me->query("repute") < (51200 + (lvl - 100) * 1000)) 
			return notify_fail("�����������̫���ˡ�");
	}
	
	if  (  me->query_skill("bibo_shengong",1)
		|| me->query_skill("beimin_shengong",1)
		|| me->query_skill("bahuang_gong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong_dafa",1)
		|| me->query_skill("huntian_qigong",1)
	//	|| me->query_skill("hunyuan_yiqi",1)
		|| me->query_skill("longxiang",1)
	//	|| me->query_skill("jiuyang_shengong",1)
	//	|| me->query_skill("taiji_shengong",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("yunlong_shengong",1)
		|| me->query_skill("zixia_shengong",1)
		|| me->query_skill("taiji_shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����񹦣���");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("������ֻ������̵������������ȡ�");
}

//perform 
static int do_bidu(CChar * me, CContainer * ob)
{
	char msg[255];

    if( me->is_fighting() )
		return notify_fail("ս���в��ܱƶ���");
	
    if ( me->query_skill("xiantian_gong", 1) < 40)
		return notify_fail("�����������Ϊ��������");

    if(  me->query("mp") <  me->query("max_mp")/15 ) 
		return notify_fail("�������������");

	if(DIFFERSTR(me->querystr("family/family_name"), "ȫ���") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
    tell_object(me,   "��ȫ����ɣ���������ʼ�˹��ƶ���"  );
	tell_room(me->environment(),snprintf(msg,255,"%s�������˹��ƶ���",me->name()),me);

	if ( me->query("condition/zm_poison") > 0 )
	{
		if ( me->query("condition/zm_poison") <  me->query_skill("xiantian_gong",1)/20 + 1 )
		{
			me->apply_condition("zm_poison", 0);
			message_vision( "$N ���ϵ� ��ĸ����֮�� ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else {
			me->apply_condition("zm_poison",  me->query("condition/zm_poison") - me->query_skill("xiantian_gong",1)/20 );
			message_vision( "$N ���ϵ� ��ĸ����֮�� ��ȥС�� ��ɫ��������������" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
		
	}

	if ( me->query("condition/ice_poison") > 0 )
	{
		if ( me->query("condition/ice_poison") <  me->query_skill("xiantian_gong",1)/20+1 )
		{
			me->apply_condition("ice_poison", 0);
			message_vision( "$N ���ϵ� �������� ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else 
		{
			me->apply_condition("ice_poison",  me->query("condition/ice_poison") - me->query_skill("xiantian_gong",1)/20);
			message_vision( "$N ���ϵ� �������� ��ȥС�� ��ɫ��������������" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
		
	}
	if ( me->query("condition/jy_poison") > 0 )
	{
		if ( me->query("condition/jy_poison") <  me->query_skill("xiantian_gong",1)/20+1 )
			
		{
			me->apply_condition("jy_poison", 0);
			message_vision( "$N ���ϵ� �����׹�צ�� ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else {
			me->apply_condition("jy_poison",  me->query("condition/jy_poison") - me->query_skill("xiantian_gong",1)/20);
			message_vision( "$N ���ϵ� �����׹�צ�� ��ȥС�� ��ɫ��������������" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	
    if ( me->query("condition/xx_poison") > 0 )
	{
		if ( me->query("condition/xx_poison") <  me->query_skill("xiantian_gong",1)/20+1 )
			
		{
			me->apply_condition("xx_poison", 0);
			message_vision( "$N ���ϵ� �����ƶ� ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else 
		{
			me->apply_condition("xx_poison",  me->query("condition/xx_poison") - me->query_skill("xiantian_gong",1)/20);
			message_vision( "$N ���ϵ� �����ƶ� ��ȥС�� ��ɫ��������������" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	
    if ( me->query("condition/ss_poison") > 0 )
	{
		if ( me->query("condition/ss_poison") <  me->query_skill("xiantian_gong",1)/8+1 )
			
		{
			me->apply_condition("ss_poison", 0);
			message_vision( "$N ���ϵ� ������ ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else {
			me->apply_condition("ss_poison",  me->query("condition/ss_poison") - me->query_skill("xiantian_gong",1)/8);
			message_vision( "$N ���ϵ� ������ ��ȥС�� ��ɫ��������������" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	
	if ( me->query("condition/rose_poison") > 0 )
	{
		if ( me->query("condition/rose_poison") <  me->query_skill("xiantian_gong",1)/20+1 )
		{
			me->apply_condition("rose_poison", 0);
			message_vision( "$N ���ϵ� ��õ�嶾 ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else
		{
			me->apply_condition("rose_poison",  me->query("condition/rose_poison") - me->query_skill("xiantian_gong",1)/20);
			message_vision( "$N ���ϵ� ��õ�嶾 ��ȥС�� ��ɫ��������������" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	
	if ( me->query("condition/zhua_poison") > 0 )
	{
		if ( me->query("condition/zhua_poison") <  me->query_skill("xiantian_gong",1)/20+1 )
		{
			me->apply_condition("zhua_poison", 0);
			message_vision( "$N ���ϵ� ��Ѫ��צ ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else 
		{
			me->apply_condition("zhua_poison",  me->query("condition/zhua_poison") - me->query_skill("xiantian_gong",1)/20);
			message_vision( "$N ���ϵ� ��Ѫ��צ ��ȥС�� ��ɫ��������������" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	
	if ( me->query("condition/snake_poison") > 0 )
	{
		if ( me->query("condition/snake_poison") <  me->query_skill("xiantian_gong",1)/20+1 )
			
		{
			me->apply_condition("snake_poison", 0);
			message_vision( "$N ���ϵ� �߶� ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else 
		{
			me->apply_condition("snake_poison",  me->query("condition/snake_poison") - me->query_skill("xiantian_gong",1)/20);
			message_vision( "$N ���ϵ� �߶� ��ȥС�� ��ɫ��������������" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}

    if ( me->query("condition/wudu_poison") > 0 )
	{
		if ( me->query("condition/wudu_poison") <  me->query_skill("xiantian_gong",1)/20+1 )
			
		{
			me->apply_condition("wudu_poison", 0);
			message_vision( "$N ���ϵ� �嶾�� ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else 
		{
			me->apply_condition("wudu_poison",  me->query("condition/wudu_poison") - me->query_skill("xiantian_gong",1)/20);
			message_vision( "$N ���ϵ� �嶾�� ��ȥС�� ��ɫ��������������" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}

	if ( me->query("condition/yufeng_poison") > 0 )
	{
		if ( me->query("condition/yufeng_poison") <  me->query_skill("xiantian_gong",1)/20+1 )
			
		{
			me->apply_condition("yufeng_poison", 0);
			message_vision( "$N ���ϵ� ����붾 ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else 
		{
			me->apply_condition("yufeng_poison",  me->query("condition/yufeng_poison") - me->query_skill("xiantian_gong",1)/20);
			message_vision( "$N ���ϵ� ����붾 ��ȥС�� ��ɫ��������������" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}

    if ( me->query("condition/bingpo_poison") > 0 )
	{
		if ( me->query("condition/bingpo_poison") <  me->query_skill("xiantian_gong",1)/20+1 )
			
		{
			me->apply_condition("bingpo_poison", 0);
			message_vision( "$N ���ϵ� �������붾 ���� ����ɫ����ȥ�ö��ˡ�" , me); 
		}
		else
		{
			me->apply_condition("bingpo_poison",  me->query("condition/bingpo_poison") - me->query_skill("xiantian_gong",1)/20);
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

static int do_life_heal(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target )
		return notify_fail("��Ҫ������Ϊ˭���ˣ�");
	
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�");
	
	if(target == me)
		return notify_fail("��û��Ϊ�Լ����˵�������");
	
	if(  me->query_skill("xiantian_gong",1) < 40 )
		return notify_fail("�����������Ϊ������");
	
	if(  me->query("max_mp") < 300 )
		return notify_fail("���������Ϊ������");
	
	if(  me->query("mp") < 150 )
		return notify_fail("�������������");
	
	if(  target->query("eff_hp") <  target->query("max_hp") / 5 )
		return notify_fail( "%s�Ѿ����˹��أ����ܲ�����������𵴣�",target->name() );

	if( target->query("eff_hp") >= target->query("max_hp"))
		return notify_fail("%sû�����ˡ�", target->name());
	
	message_vision("$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�"  ,	me, target );
	
	target->receive_curing("hp", 10 +  me->query_skill("force")/3 );
	target->add("hp", 10 +  me->query_skill("force")/3 );
	if(  target->query("hp") >  target->query("eff_hp") ) target->set("hp",  target->query("eff_hp"));
	
	me->add("mp", -150);
	me->set("mp_factor", 0l);
	//���˾��齱��    �ز� 2002��7��18
	char expmsg[80];
	int addexp = me->query("level") / 4 + 1;
	int addrpt = 10 - target->query("level");

	addexp = int(((addexp + random(addexp)) / 2) *0.5);
	if(addrpt < 1) addrpt = 1;
	addrpt = (addrpt + random(addrpt)) / 2;

	addexp=1;
	addrpt=1;
	me->add("combat_exp", addexp);
	me->add("repute", addrpt);
	
	tell_object(me, snprintf(expmsg, 80, "������������%ld�㣡���������%ld�㣡", addexp, addrpt));
	//���˾��齱��
	me->start_busy(5);
	target->start_busy(5);
	return 1;
	
}

/*
static int do_jing(CChar * me, CContainer * ob)
{
	if( me->is_fighting() )
		return notify_fail("ս�����ƾ���������");
	
	if ( me->query_skill("xiantian_gong", 1) < 50)
		return notify_fail("�����������Ϊ��������");
	if(  me->query("mp") < 50 ) 
		return notify_fail("�������������");
	
	if(  me->query_skill("xiantian_gong",1) < 30 )
		return notify_fail("�����������Ϊ������");
	
	if(  me->query("eff_hp") <  me->query("max_hp") / 2 )
		return notify_fail("��ľ�����̫�ֻ࣬��һ��������������Σ�գ�");
	
	tell_object(me,   "��ȫ����ɣ���������ʼ�����ƾ���"  );
	tell_room(me->environment(),snprintf(tmp,255,"%sͷ��ð���������������������ö��ˡ�"  ,me->name()),me);
	me->receive_curing("hp", 10 +  me->query_skill("taoism")/10 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
	me->start_busy(4);
	
	return 1;
	
}
*/

static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������");
	
	if ( me->query_skill("xiantian_gong", 1) < 20)
		return notify_fail("�����������Ϊ��������");
	if(  me->query("mp") < 50 ) 
		return notify_fail("�������������");
	
	if(  me->query("eff_hp") <  me->query("max_hp") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�");
	
	tell_object(me,   "��ȫ����ɣ���������ʼ�˹����ˡ�"  );
	tell_room(me->environment(),snprintf(msg,255, "%s�³�һ����Ѫ����ɫ�������ö��ˡ�"  ,me->name() ),me);
	
	me->receive_curing("hp", 10 +  me->query_skill("force")/5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
	me->start_busy(4);
	
	return 1;
	
}

FORCE_END;
