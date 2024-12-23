//huntian_qigong.h  ��������
FORCE_BEGIN(CShuntian_qigong);

virtual void create()
{
	CForce::create();
	
	set_name( "��������");

	Magic_t * magic;

	magic = add_magic("life_heal", do_life_heal);
	magic->name = "ҽ����";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("powerup", do_powerup);
	magic->name = "������";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;	

	magic = add_magic("shengang", do_shengang);
	magic->name = "�������";
	magic->mp = 200;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;	
}

virtual int valid_enable(string usage) { return usage == "force"; }

virtual int valid_learn(CChar * me)
{
	int i = me->query_skill("huntian_qigong", 1);
	int t = 1, j;
	
	for (j = 1; j < i / 15; j++) t*= 2;
	
	if ( EQUALSTR(me->querystr("gender"), "����") && i > 49)
		return notify_fail("���޸����ԣ���������������������Ļ���������");
	
	if (i > 10 && (me->query("repute") > t * 100 || me->query("repute") < t * (-100)))
		return notify_fail("ѧ����������Ҫ������а��������а��������ò���ѽ��");
	
	if ( me->query_skill("bibo_shengong",1)
		|| me->query_skill("beiming_shengong",1)
		|| me->query_skill("bahuang_gong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong_dafa",1)
		//	|| me->query_skill("huntian_qigong",1)
		|| me->query_skill("hunyuan_yiqi",1)
		|| me->query_skill("longxiang",1)
		|| me->query_skill("jiuyang_shengong",1)
		|| me->query_skill("taiji_shengong",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("shenlong_xinfa",1)
		|| me->query_skill("seaforce",1)		
		|| me->query_skill("yunlong_shengong",1)
		|| me->query_skill("zixia_shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ������������");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("��������ֻ������̵������������ȡ�");
}

//exert heal
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
	
	if( me->query("max_mp") < 300 )
		return notify_fail("���������Ϊ������");
	
	if( me->query("mp") < 150 )
		return notify_fail("�������������");
	
	if( target->query("eff_hp") < target->query("max_hp") / 5 )
		return notify_fail( "%s�Ѿ����˹��أ����ܲ�����������𵴣�",target->name());

	if( target->query("eff_hp") >= target->query("max_hp"))
		return notify_fail("%sû�����ˡ�", target->name());
	
	message_vision("$N�������������ڹ�������������$n���ģ������ؽ���������$n����...."
		"���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�" ,
		me, target );
	
	target->receive_curing("hp", 10 + me->query_skill("force")/3 );
	target->add("hp", 10 + me->query_skill("force")/3 );
	if( target->query("hp") > target->query("eff_hp") ) target->set("hp", target->query("eff_hp"));
	
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

static int do_powerup(CChar * me, CContainer * ob)
{
	int skill;
	
	if( ob != me ) 
		return notify_fail("��ֻ���û��������������Լ���ս������");
	
	if( me->query("mp") < 100  ) 
		return notify_fail("�������������");
	if( me->querymap_temp("powerup") ) 
		return notify_fail("���Ѿ����˹����ˡ�");

	if(DIFFERSTR(me->querystr("family/family_name"), "ؤ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	skill = me->query_skill("force");
	me->add("mp", -100);
	me->receive_damage("hp", 0);
	
	message_vision("$N΢һ�����������������ȫ��ǽڷ���һ�󱬶�������� " , me);		
	start_powerup(me, skill, skill/2, skill/2, "��Ļ�������������ϣ��������ջص��");
	
	if( me->is_fighting() ) me->start_busy(3);
	
	return 1;
}

static int	do_shengang(CChar * me, CContainer * ob)
{
	string msg;
	int d_count, count, qi, maxqi, skill;
	
	if( me->query_temp("shengang") ) 
		return notify_fail("���Ѿ����˻�������ˡ�");

	if(DIFFERSTR(me->querystr("family/family_name"), "ؤ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( !me->is_fighting() )
		return notify_fail("���������ֻ����ս����ʹ�á�");
	
	if( me->query("mp") < 200 )
		return notify_fail("���������������");
	
	if( me->query_skill("force") < 150)
		return notify_fail("��Ļ�����������Ϊ����������ʹ�û������! ");
	//�����б������ӱ�������
	msg =  "$Nʹ�����������������������������ע�����ģ�" ;
	
	qi = me->query("hp");
	maxqi = me->query("max_hp");
	skill =  (me->query_skill("huntian_qigong",1) / 3);
	count = me->query_str();
	d_count = me->query_dex() / 2;
	
	if(qi > (maxqi * 0.4))
	{	
		me->add_temp("apply/damage", skill*2);
		me->set_temp("shengang", 1);
		me->call_out( shengang_remove_effect, skill, skill*2);
		
		me->add("mp", -150);
	}
	else
	{
		msg =  "$Nƴ�������������������������Լ�����̫�أ�û�ܳɹ�!" ;
	}

	message_vision(msg.c_str(), me); 
	return 1;
	
}

static void shengang_remove_effect(CContainer *ob,LONG amount,LONG param)
{
	CChar *me =(CChar *) ob;
	me->add_temp("apply/damage", - amount);
	me->delete_temp("shengang");

	me->SendState(me);
	tell_object(me,  "��Ļ������������ϣ��������ջص��" );
	me->start_busy(random(4));
}


FORCE_END;