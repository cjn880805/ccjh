// huashan_neigong.h ��ɽ�ڹ�
//code by Fisho
//date : 2000-12-06
FORCE_BEGIN(CShuashan_neigong);

virtual void create()
{
	CForce::create();

	set_name( "��ɽ�ڹ�");

	Magic_t * magic;

	magic = add_magic("powerup", do_powerup);
	magic->name = "������";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force")  ;
}

virtual int valid_learn(CChar * me)
{
	me->query_skill("huashan_neigong", 1);
    if ( me->query_skill("zixia_shengong", 1) < 10)
		return notify_fail("�����ϼ�񹦻�򻹲�����");
    return 1;
}

virtual int practice_skill(CChar * me)
{
    return notify_fail("��ɽ����ֻ������̵������������ȡ�");
}

//perform 
static int do_powerup(CChar * me, CContainer * ob)
{
    int skill;
    if( ob != me )
		return  notify_fail("��ֻ���û�ɽ�ڹ������Լ���ս������");
    if(  me->query("mp") < 100 )
		return    notify_fail("�������������");
    if(  me->querymap_temp("powerup") )
		return  notify_fail("���Ѿ����˹����ˡ�");
	
    skill = me->query_skill("force");
	
    me->add("force", -100);
    me->receive_damage("hp",0);
	
    message_vision("$N�������˿������������Ϣ���ϸ�������������������������������������"  , me);
	
    start_powerup(me, skill, skill/3, skill/3, "��Ļ�ɽ�ڹ�������ϣ��������ջص��");

    if( me->is_fighting() ) me->start_busy(3);
    return 1;
	
}

FORCE_END;
