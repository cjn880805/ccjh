// kuihua_xinfa.h �����ķ�
//code by Fisho
//date : 2000-12-06

FORCE_BEGIN(CSkuihua_xinfa);

virtual void create()
{
	CForce::create();

	set_name( "�����ķ�");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "������";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force")  ;
}

virtual int valid_learn(CChar * me)
{
	int i =  me->query_skill("kuihua_xinfa", 1);
	int t = 1, j;
	for (j = 1; j < i / 10; j++) t*= 2;
	if ( me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ�����㣬����ѧ�����ķ���");
	if (i > 10 &&  me->query("repute") > t * 100)
		return notify_fail("ѧ�����ķ���Ҫ�ĺ���������������������ò���ѽ��");
	if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) )
		return notify_fail("������ͺ¿ţ�����ǵ��ķ�����ѧ�����ķ���ʲ�ᣡ");
	if ( me->query_skill("hunyuan_yiqi",1)
		|| me->query_skill("huntian_qigong",1)
		|| me->query_skill("taiji_shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����ķ�����");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("�����ķ�ֻ������̵������������ȡ�");
}

//perform 
static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������");
	
	if ( me->query_skill("kuihua_xinfa", 1) < 20)
		return notify_fail("��Ŀ����ķ���Ϊ��������");
	if(  me->query("mp") < 50 )
		return notify_fail("�������������");
	
	if(  me->query("eff_hp") <  me->query("max_hp") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�");
	
	tell_object(me, "��ȫ����ɣ���������ʼ�˹����ˡ�"  );
	tell_room(me->environment(),snprintf(msg,255,"%s�³�һ����Ѫ����ɫ�������ö��ˡ�" ,me->name() ), me);
	
	me->receive_curing("hp", 10 +  me->query_skill("force")/5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
	me->start_busy(4);
	
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
	
	message_vision( "$N�������������ڹ�������������$n���ģ������ؽ���������$n����...."
		"���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�"  ,
		me, target );
	
	target->receive_curing("hp", 10 +  me->query_skill("force")/3 );
	target->add("hp", 10 +  me->query_skill("force")/3 );
	if(  target->query("hp") >  target->query("eff_hp") )
		target->set("hp",  target->query("eff_hp"));
	
	me->add("mp", -10);
	me->set("mp_factor", 0l);
	
	return 1;
	
}
*/

FORCE_END;
