
// luoying_xinfa.h ��Ӣ�ķ�
//code by Fisho
//date : 2000-12-08
FORCE_BEGIN(CSluoying_xinfa);

virtual void create()
{
	CForce::create();

	set("name", "��Ӣ�ķ�");

	Magic_t * magic;

	magic = add_magic("life_heal", do_life_heal);
	magic->name = "ҽ����";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("powerup", do_powerup);
	magic->name = "������";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force") ;
}

virtual int valid_learn(CChar * me)
{
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("��Ӣ�ķ�ֻ������̵������������ȡ�");
}

//perform 
static int do_life_heal(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if (!target || target == me)
		return notify_fail("��Ҫ������Ϊ˭���ˣ�");
	
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�");
	
	if(  me->query("max_mp") < 300 )
		return notify_fail("���������Ϊ������");
	
	if(  me->query("mp") < 100)
		return notify_fail("�������������");
	
	if(  target->query("eff_hp") <  target->query("max_hp") / 5 )
		return notify_fail( "%s�Ѿ����˹��أ����ܲ�����������𵴣�",target->name() );

	if( target->query("eff_hp") >= target->query("max_hp"))
		return notify_fail("%sû�����ˡ�", target->name());
	
	message_vision("$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�",me, target );
	
	target->receive_curing("hp", 10 +  me->query_skill("force")/2 );
	target->add("hp", 10 +  me->query_skill("force")/3 );
	
	if(  target->query("hp") >  target->query("eff_hp") ) 
		target->set("hp",  target->query("eff_hp"));
	
	me->add("mp", -100);
	me->set("mp_factor", 0);
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
	if( ob != me ) 
		return	notify_fail("��ֻ������Ӣ�ķ������Լ���ս������");
	
	if(  me->query("mp") < 100 ) 
		return	notify_fail("�������������");
	if(  me->querymap_temp("powerup") ) 
		return notify_fail("���Ѿ����˹����ˡ�");

	if(DIFFERSTR(me->querystr("family/family_name"), "�һ���") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	int skill = me->query_skill("force");
	
	me->add("mp", -45);
	me->receive_damage("hp",0);
	message_vision( "$N΢һ����������Ӣ�ķ���ȫ�������������죬���о������䣬�������ˡ�"  , me );
	
	start_powerup(me, skill, skill/3, skill/3, "�����Ӣ�ķ�������ϣ��������ջص��");
	
	if( me->is_fighting() )
		me->start_busy(3);
	return 1;
}

FORCE_END;
