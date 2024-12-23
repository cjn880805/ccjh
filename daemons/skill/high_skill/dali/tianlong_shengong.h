// tianlong_shengong.c ������

FORCE_BEGIN(CStianlong_shengong);

virtual void create()
{
	CForce::create();
	
	set_name( "������");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "������";
	magic->mp = 50;
	magic->valid_cast = CAST_IN_COMMON;

}

int valid_enable(string usage) { return usage == "force"; }

virtual int valid_learn(CChar * me)
{
	int lvl = me->query_skill("tianlong_shengong", 1);
	int t = 1, j;
	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;
		
		if ( EQUALSTR(me->querystr("gender"), "����") && lvl > 49)
			return notify_fail("���޸����ԣ���������������������������񹦡�");
		
		if (me->query_skill("force", 1) < 15)
			return notify_fail("��Ļ����ڹ���򻹲�����");
		
		if(lvl<=100)
		{
			if (lvl > 10 && me->query("repute") < t * 100) 
				return notify_fail("�����̫���ˡ�");
		}
		else
		{
			if (me->query("repute") < (51200 + (lvl - 100) * 1000)) 
				return notify_fail("�����̫���ˡ�");
		}
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("������ֻ������̵������������ȡ�");
}

static int do_heal(CChar * me, CContainer * target)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������");
		
	if (me->query_skill("tianlong_shengong", 1) < 20)
		return notify_fail("�����������Ϊ��������");

	if( me->query("mp") < 50 ) 
		return notify_fail("�������������");
		
	if( me->query("eff_hp") < me->query("max_hp") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�");
		
	tell_object( me, "��ȫ����ɣ���������ʼ�˹����ˡ�");
	tell_room(me->environment(), snprintf(msg, 255, "%s�³�һ����Ѫ����ɫ�������ö��ˡ�", me->name()), me);
	me->receive_curing("hp", 10 + me->query_skill("force")/5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
	me->start_busy(4);
		
	return 1;
}

FORCE_END;
