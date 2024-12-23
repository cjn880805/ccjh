
// count.h ��������
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CScount);

virtual void create()
{
	set_name( "��������");
	set("special", 1);

	Magic_t * magic;

	magic = add_magic("zhanbu", do_zhanbu);
	magic->name = "ռ��";
	magic->mp = 200;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual const char * type() { return "knowledge"; }

virtual int valid_learn(CChar * me)
{
	if(DIFFERSTR(me->querystr("family/family_name"), "�һ���")
		|| DIFFERSTR(me->querystr("family/master_id"), "huang laoguai"))
		return notify_fail("ֻ���һ��Ƶ����ĵ��Ӳ���ѧ�������ԡ�");
	
	if( me->query_skill("literate",1) < 50 )
		return notify_fail("��Ķ���д��̫�ͣ�û�а취ѧ�������ԡ�");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("��������ֻ������̵������������ȡ�");
}

//���Ų���
static int do_zhanbu(CChar * me, CContainer * ob)
{
	int i, l, skill;
	i = me->query_skill("bibo_shengong", 1); 
	l = me->query_skill("qimen_wuxing", 1);
	skill = (i + l);
	
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ) target = me;
	
	if(me->is_fighting())
		return notify_fail("������ս���У���������\n");

	if(me->query_skill("bibo_shengong",1) < 60 )
		return notify_fail("��ı̲��񹦲�����죡\n");

	if(DIFFERSTR(me->querystr("family/family_name"), "�һ���"))
		return notify_fail("ֻ���һ����ĵ��Ӳ���ѧ�������ԡ�");

	if(me->query_skill("count",1) < 100 )
		return notify_fail("����������Բ�����죡\n");     
	
	if(me->query("mp") < 300  ) 
		return notify_fail("�������������\n");

	if(me->query_temp("thd/qimenbg"))
		return notify_fail("�����ڡ�ռ������\n");
	
	me->add("mp", -200);
	
	message_vision("\n$GRN$Nָһ�㣬ֻ�����л�Ȼ���ʡ�\n", me);
	
	me->start_busy(2);
	me->add_temp("apply/int", me->query("int")*skill/500);
	me->set_temp("thd/qimenbg",me->query("int")*skill/500);  
	me->UpdateMe();
	me->call_out(remove_effect, skill);

	return 1;
}

static void remove_effect(CContainer * ob, LONG param1, LONG count)
{
	CChar * me = (CChar *)ob;
	me->add_temp("apply/int", -me->query_temp("thd/qimenbg"));
    me->delete_temp("thd/qimenbg");
    tell_object(me, "$HIY��������ˣ��Խ�Ҳ����ʹ�ˡ�\n");
}

SKILL_END;
