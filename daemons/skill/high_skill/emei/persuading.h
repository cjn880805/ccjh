
// persuading.h ��������
//code by Fisho
//date : 2000-12-02

SKILL_BEGIN(CSpersuading);

virtual void create()
{
	set_name( "��������");
	set("special", 1);

	Magic_t * magic;

	magic = add_magic("quanjia", do_quanjia);
	magic->name = "Ȱ��";
	magic->mp = 30;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual const char * type() { return "knowledge"; }

//����ѧ1����Ȼ��ʹ�÷���
virtual int valid_learn(CChar * me)
{
	if(me->query_skill("persuading", 1) > 1)
		return notify_fail("��������Ҫ��ʵ������ߡ�");

	return 1;
}

//perform 
static int do_quanjia(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if ( DIFFERSTR(me->querystr("family/family_name"), "������") )
        return notify_fail("ֻ�ж����ɲ����ö������ˣ�");

	if( me->query_temp("dushi") )
		return notify_fail("���Ѿ���Ȱ�˼Ұն��ˣ�");
	
	if(!target || !living(target))
		return notify_fail("��ҪȰ˭�ն���");

    if ( EQUALSTR(target->querystr("family/family_name"), "������") )
        return notify_fail("�㲻�����ɵ�ʹ�ö������ˣ�");

	if( !wizardp(me) && wizardp(target) )
		return notify_fail("��Ҳ���Ȱ��ʦ�ն���");

	if( me->is_fighting() )
        return notify_fail("һ�ߴ��һ��Ȱ���˰ն�����������α�����ˣ�");

	if(! target->is_fighting() )
		return notify_fail("�Է�û��ս����");

	if( me->query("mp") < 30)
		return notify_fail("��ķ������㣡");

	me->add("mp", -30);

	int sp = 2 + me->query_skill("persuading", 1) / 5;

	message_vision(snprintf(msg, 255, "$Nҡҡ��ͷ��$n�����߹�����˫�ֺ�ʮ��˵�����ҷ�ȱ��նȶ�����, ����%s�ն�, ���������� ...��",	query_respect(target)), me, target);
	me->set_temp("dushi", 1);
	
	me->call_out(compelete_dushi, 3, target->object_id(), sp);

	return 1;
	
}

static void compelete_dushi(CContainer * ob, LONG param1, LONG sp)
{
	CChar * me = (CChar *)ob;
	CContainer * where = me->environment();
	CChar * who = (CChar *)where->Present(param1);
	
	me->delete_temp("dushi");
	
	if(! where->Query(IS_FIGHTROOM))
		return;

	if(! who )
	{
		tell_object(me, "̫��ϧ�ˣ���Ҫ�ҵ����Ѿ����ˡ�");
		return;
	}

	int dp = who->query("level");

	if( living(who) && (random(sp + dp) > dp) ) 
	{
		message_vision("$n��ͷ����һ�ᣬ�ֿ��˿�$N��ҡҡͷ��̾�˿�����ֹͣ�˴򶷡�", me, who);
		
		((CFightRoom *)where)->Leave_Team(who);
		
		me->improve_skill("persuading", dp + random(dp));
		me->add("combat_exp", 1 );
		me->start_busy(3);
	} 
	else 
	{
		if( random(sp) > dp/2 ) 
		{
			message_vision("$n�ݺݵص���$Nһ�ۣ��ȵ����Ҷ������˸������ˣ��ܰն���! \n$N̾�˿���ת���߿��ˡ�", me, who);
			return;
		}
	
		message_vision("$nŤ��ͷȥ����$N������", me, who);
	}
}

SKILL_END;
