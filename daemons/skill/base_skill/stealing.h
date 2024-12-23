//stealing.h ͵��֮��

SKILL_BEGIN(CSstealing);

virtual void create()
{
	set_name( "͵����");

	set("special", 1);

	Magic_t * magic;

	magic = add_magic("steal", do_steal);
	magic->name = "͵��";
	magic->mp = 30;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;	
}

virtual const char * type() { return "knowledge"; }

//����ѧ1����Ȼ��ʹ�÷���
virtual int valid_learn(CChar * me)
{
	if(me->query_skill("stealing", 1) > 20)
		return notify_fail("͵����Ҫ��ʵ������ߡ�");

	return 1;
}

//perform 
static int do_steal(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( (me->environment())->query("no_fight") )
		return notify_fail("�����ֹ���ԡ�");

	if( me->query_temp("stealing") )
		return notify_fail("���Ѿ����һ��������ˣ�");

	if(!target || target == me )
		return notify_fail("����͵˭�Ķ�����");

	if( !wizardp(me) && wizardp(target) )
		return notify_fail("��Ҳ���͵��ʦ���ϵĶ�����");

	if(me->is_fighting() && target->is_fighting()
		&& me->query_team() == target->query_team())
		return notify_fail("����͵������Ա����Ʒ��");

	CContainer * obj = RandomGetItem(target, IS_ITEM);
	
	if(! obj)
		return notify_fail( "%s���Ͽ�����û��ʲ��ֵǮ�Ķ�����͵��", target->name());

	CMapping * m = obj->query_entire_dbase();
	if (! m->undefinedp("no_drop") 
		|| (! m->undefinedp("owner") && DIFFERSTR(obj->querystr("owner"), me->querystr("id"))) )
		return notify_fail("%s��%s������һ��͵������", obj->name(), target->name());

	if( me->query("mp") < 30)
		return notify_fail("��ķ������㣡");
	me->add("mp", -30);

	LONG sp = me->query("dex") * 2 + me->query_skill("stealing", 1) * 5 - me->query("thief") * 20;

	if ( EQUALSTR(me->querystr("family/family_name"), "ؤ��" ))
		sp = me->query_skill("stealing", 1) * 10 + me->query("dex") * 5 - me->query("thief") * 10;

	if( sp < 1 ) sp = 1;

	if( me->is_fighting()) 
	{
		sp /= 2;
		me->start_busy(3);
	}

	char msg[255];
	tell_object(me, snprintf(msg, 255, "�㲻����ɫ����������%s���ȴ��������� ...", target->name()));

	me->set_temp("stealing", obj->object_id());
	me->call_out( compelete_steal, 3, target->object_id(), sp);

	return 1;
}

static void compelete_steal(CContainer * ob, LONG param1, LONG sp)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);
	char msg[255];
	
	if(! target)
	{
		me->delete_temp("stealing");
		tell_object(me, "̫��ϧ�ˣ������ֵ�Ŀ���Ѿ����ˡ�");
		return;
	}

	CContainer * obj = target->Present(me->query_temp("stealing"));
	me->delete_temp("stealing");
	if(! obj)
	{
		tell_object(me, "̫��ϧ�ˣ������ֵ�Ŀ���Ѿ����ڶԷ������ˡ�");
		return;
	}

	LONG dp = target->query("hp") + obj->Query_Weight() / 20;
	if( target->is_fighting() ) dp *= 10;
	if( obj->query("equipped") ) dp *= 10;

	if( !living(target) || (random(sp + dp) > dp) ) 
	{
		if( ! obj->move(me) ) 
		{
			tell_object(me, snprintf(msg, 255, "������һ%s�����Ƕ������̫���ˣ����ò�������", obj->name()));
			return;
		}

		tell_object(me, "$HIW�����ˣ�$COM");
		tell_object(me, snprintf(msg, 255, "��ɹ���͵��%s��", obj->name()));

		if( living(target) ) 
		{
			me->improve_skill("stealing", random(me->query_int()));
		    if ( EQUALSTR(me->querystr("family/family_name"), "ؤ��" ) )
			{
				me->add("combat_exp", 1);
			}
		}

		if( random(sp) < dp/2 )
		{
			MessageVision(me, "chat", 
				snprintf(msg, 255, "�㿴��%s�������ش�%s����͵����%s����", me->name(), target->name(), obj->name()),
				me, target);
		} 
	}
	else 
	{
		if( random(sp) > dp/2 ) 
		{
			tell_object(me, snprintf(msg, 255, "%s�������һתͷ���㼱æ�������˻�ȥ��\n���ã�û�б����֡�", target->name()));
			return;
		}
			
		tell_object(me, "$HIR��⣡��ʧ���ˣ�$COM");
		message_vision(snprintf(msg, 255, "$Nһ��ͷ�����÷���$n������ץ��$P���ϵ�%s��\n\n$N�ȵ�������ʲô����\n", obj->name()),
			target, me);

		me->improve_skill("stealing", 1, 1);
		if(!userp(target))
		{
			target->kill_ob(me);			
			me->kill_ob(target);
		}
		else
		{
			me->add("hp",-(me->query("hp")/10));
		}

	}
		
	me->start_busy(3);
	me->add("thief", 1);	
}

SKILL_END;





