
// jiuyang_shengong.h ������
//code by Fisho
//date : 2000-12-07

FORCE_BEGIN(CSjiuyang_shengong);

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
	int lvl =  me->query_skill("jiuyang_shengong", 1);
	
	if ( EQUALSTR(me->querystr("gender"), "����") && lvl > 49)
		return notify_fail("���޸����ԣ���������������������ľ����񹦡�");
	
	if ( me->query_skill("force", 1) < 30)
		return notify_fail("��Ļ����ڹ���򻹲������޷��������񹦡�");
	
	return 1;
}

//perform 
static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������");
	
	if ( me->query_skill("jiuyang_shengong", 1) < 30)
		return notify_fail("��ľ�������Ϊ��������");
	if(  me->query("mp") < 50 ) 
		return notify_fail("�������������");
	if(  me->query("eff_hp") ==  me->query("max_hp"))
		return notify_fail("������û�����κ��ˡ�");
	
	if(  me->query("eff_hp") <  me->query("max_hp") / 7 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�");
	
	tell_object( me, "������ ������ ��ʼ���ˡ�" );
	tell_room(me->environment(),snprintf(msg,255,"%s���� ������ ��ʼ���ˡ�",me->name() ), me);
	
	me->receive_curing("hp", 10 +  me->query_skill("force")/5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
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
		return notify_fail("�㲻����Ϊ�Լ����ˡ�");
	
	if ( me->query_skill("jiuyang_shengong", 1) < 40)
		return notify_fail("��ľ�������Ϊ��������");
	
	if(  me->query("max_mp") < 300 )
		return notify_fail("���������Ϊ������");
	
	if(  me->query("mp") < 100 )
		return notify_fail("�������������");
	
	if(  target->query("eff_hp") <  target->query("max_hp") / 9 )
		return notify_fail("%s�Ѿ����˹��أ����ܲ�����������𵴣�",target->name());

	if( target->query("eff_hp") >= target->query("max_hp"))
		return notify_fail("%sû�����ˡ�", target->name());
	
	message_vision("$N��ϥ��������������񹦣���������������$n��ǰ����������������$n����...���ã�$N�ջ�˫�ƣ�$n�³�һ����Ѫ���о����ƺö��ˡ�"  ,	me, target );
	
	target->receive_curing("hp", 10 +  me->query_skill("force")/3 );
	target->add("hp", 10 +  me->query_skill("force")/3 );
	if(  target->query("hp") >  target->query("eff_hp") ) target->set("hp",  target->query("eff_hp"));
	
	me->add("mp", -100);
	me->set("mp_factor", 0l);

	//���˾��齱��    �ز� 2002��7��18
	char expmsg[80];
	int addexp = me->query("level") / 4 + 1;
	int addrpt = 10 - target->query("level");

	addexp = int(((addexp + random(addexp)) / 2) *0.5);
	if(addrpt < 1) addrpt = 1;
	addrpt = (addrpt + random(addrpt)) / 2;

	addexp=1;
	me->add("combat_exp", addexp);
	
	tell_object(me, snprintf(expmsg, 80, "������������%ld�㣡���������0�㣡", addexp));
	//���˾��齱��

	me->start_busy(5);
	target->start_busy(5);

	return 1;
}

/*
static int do_jingheal(CChar * me, CContainer * ob)
{
	if ( !wizardp(me) )
		return notify_fail("����Ȩ���о������ƣ�");
	
	if( !target )
		return notify_fail("��Ҫ������Ϊ˭���ˣ�");
	
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�");
	
	if(  me->query("max_mp") < 300 )
		return notify_fail("���������Ϊ������");
	
	if(  me->query("mp") < 150 )
		return notify_fail("�������������");
	
	message_vision("$N�������������ڹ�������������$n���ģ������ؽ���������$n����....���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�"  ,	me, target );
	
	target->receive_curing("hp", 10 +  me->query_skill("force")/3 );
	target->add("hp", 10 +  me->query_skill("force")/3 );
	if(  target->query("hp") >  target->query("eff_hp") )
		target->set("hp",  target->query("eff_hp"));
	
	me->add("mp", -10);
	me->set("mp_factor", 0l);
	
	return 1;
	
}
*/

static int do_powerup(CChar * me, CContainer * ob)
{
	int skill;
	
	if ( !wizardp(me) && (DIFFERSTR(me->querystr("family/family_name"), "����")))
		return notify_fail("�㲻�����̵��Ӳ���ʹ�þ�����.�����񹦲�����, �����ֵ��Ӳ���, �治֪��������ôѧ���!����, ����, �����ڵ��з����Ƿ���Ҫ�ٺú�ѧһѧ.");

	if( ob != me ) 
		return notify_fail("��ֻ���þ������������Լ���ս������");
	
	if(  me->query("mp") < 100  ) 
		return notify_fail("�������������");
	if(  me->querymap_temp("powerup") ) 
		return notify_fail("���Ѿ����˹����ˡ�");
	
	skill = me->query_skill("force");
	me->add("mp", -100);
	me->receive_damage("hp", 0);
	
	message_vision(	"$N΢һ������������񹦣�ȫ��ǽڷ���һ�󱬶��������, ��ȫ��Ǳ�ܾ������� "  , me);
		
	start_powerup(me, skill, skill/3, skill/3, "��ľ�����������ϣ��������ջص��");
	
	if( me->is_fighting() ) me->start_busy(3);
	
	return 1;
	
}

int practice_skill(CChar * me)
{
	return notify_fail("ֻ��ͨ����������!");
}

FORCE_END;
