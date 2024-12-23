// falun_gong.h ���ִ�
//code by Teapot
//date : 2001-02-06

FORCE_BEGIN(CSfalun_gong);

virtual void create()
{
	CForce::create();

	set_name( "���ִ�");


	Magic_t * magic;

	magic = add_magic("suicide", do_suicide);
	magic->name = "�Է�";
	magic->mp = 0;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

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
	return notify_fail("���ִ�ֻ��ͨ�������־ѧϰ������");
}

//perform 
static int do_suicide(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("ս�����Է٣�����ʦ˵�����������졭��");
	
	tell_room(me->environment(), snprintf(msg,255, "%s�Ĺ��������ˣ��ͳ�һ������ƿ��������һ��������һ����������" , me->name() ),me);
	tell_room(me->environment(), snprintf(msg,255, "�飡����"),me);
	tell_room(me->environment(), snprintf(msg,255, "ֻ��һ�Ż��汬����%s����ð���������̡���" , me->name() ),me);
	tell_object( me, "ð���Ǻ��̣�������ĳ��ִ���Ϊ������" );
	tell_room(me->environment(), snprintf(msg,255, "ֻ��һ���������ҽУ�%s����Ŀ�Ѿ����յ�һƬ���ڡ�" , me->name() ),me);
	
	me->set("falun/burn", me->query("per"));
	me->set("per", 1);
	me->del("family");
	me->die();

	return 1;
}


FORCE_END;
