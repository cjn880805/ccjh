//begging.h ����֮��

SKILL_BEGIN(CSbegging);

void create()
{
	set_name( "������");
	set("special", 1);

	Magic_t * magic;

	magic = add_magic("begmoney", do_beg);
	magic->name = "����";
	magic->mp = 30;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMMON;	
}

const char * type() { return "knowledge"; }

//����ѧ1����Ȼ��ʹ�÷���
int valid_learn(CChar * me)
{
	if(me->query_skill("begging", 1) > 1)
		return notify_fail("������Ҫ��ʵ������ߡ�");

	return 1;
}

//perform 
static int do_beg(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if ( DIFFERSTR(me->querystr("family/family_name"), "ؤ��") )
          return notify_fail("ֻ����ؤ�������֣�");

	CContainer * where = me->environment();
	if( where->query("no_beg") || where->query("no_fight"))
		return notify_fail("���ﲻ����л��������ַ��ĵط���");

	if( me->query_temp("begging") )
		return notify_fail("���Ѿ������˼������ˣ�");

	if(!target || target == me || !living(target) )
		return notify_fail("������˭���֣�");

	//����һ����npc����beg��no_beg_from����
	if( target->query("no_beg_from"))
		return notify_fail("%süͷһ�壡��ŭ����%s��������", target->name(), query_rude(me));

    if ( EQUALSTR(target->querystr("family/family_name"), "ؤ��") )
        return notify_fail("�㲻������ؤ���֣�");

	if( !wizardp(me) && wizardp(target) )
		return notify_fail("��Ҳ�������ʦ���֡�");

	if( me->is_fighting() )
        return notify_fail("һ�ߴ��һ��Ҫ���������ǻ����ˣ�");

	if( target->is_fighting() ) 
        return notify_fail("�Է����ڴ�ܣ�û�����㣡");

	if( me->query("mp") < 30)
		return notify_fail("��ķ������㣡");

	CContainer * obj = RandomGetItem(target, IS_ITEM);
	
	if(! obj)
		return notify_fail( "%s���Ͽ�����û��ʲ���������Ȥ�Ķ�����", target->name());

	CMapping * m = obj->query_entire_dbase();
	if (obj->query("equipped") || ! m->undefinedp("no_drop") 
		|| (! m->undefinedp("owner") && DIFFERSTR(obj->querystr("owner"), me->querystr("id"))) )
	{
		if(random(6)==1)
		{
			me->improve_skill("begging", 1);
			me->add("mp",-30);
		}
		return notify_fail("%süͷһ�壬�������Ҫ���ģ�����", target->name());
	}

	

	me->add("mp", -30);
	int sp = 2 + me->query_skill("begging", 1) / 5;

	message_vision(snprintf(msg, 255, "$Nװ�������Ͱ͵����ӣ���������$n�߹�ȥ������֣�˵����%s���кã����������� ...��",
		query_respect(target)), me, target);
	
	me->set_temp("begging", obj->object_id());
	me->call_out( compelete_beg, 3, target->object_id(), sp);

	return 1;
}

static void compelete_beg(CContainer * ob, LONG param1, LONG sp)
{
	char msg[255];
	CChar * me = (CChar *)ob;
	CContainer * where = me->environment();
	CChar * who = (CChar *)where->Present(param1);

	if( ! who )
	{
		me->delete_temp("begging");
		tell_object(me, "̫��ϧ�ˣ���Ҫ���ֵ����Ѿ����ˡ�");
		return;
	}

	CContainer * obj = who->Present(me->query_temp("begging"));
	me->delete_temp("begging");

	if(! obj)
	{
		tell_object(me, "̫��ϧ���Է��ı����⣬������ʩ�����ˡ�");
		if(random(3)==1)
		{
			me->improve_skill("begging", 1);
			me->add("mp",-30);
		}
		return;
	}

	if( random(who->query_temp("last_beg_time")) > 8)
	{
		tell_object(me, snprintf(msg, 255, "%süͷһ���������Ҫ���ģ���������û�꣡", who->name()));
		return;
	}

	int dp = who->query("level");
	if( living(who) && (random(sp + dp) > dp) ) 
	{
		LONG amount = obj->Query_Amount();
		if( amount > 1)
		{
			if( EQUALSTR(obj->querystr("base_name"), "coin") )
				amount /= 5;
			else
				amount = 1;
			
			obj = ((CItem *)obj)->Split(amount);

			if( !obj )
			{
				tell_object(me, "���������߰ɣ���һ������Ѿ�û�ж�����ˮ��ե�ˡ�");
				return;
			}			
		}
		
		if(!obj->move(me) ) 
		{
			obj->move(where);
			tell_object(me, snprintf(msg, 255, "���ֵ�%s�����Ƕ������̫���ˣ����ò����ڵ��¡�", obj->name()));
			me->improve_skill("begging", random(2)+1);
			me->add("mp",-30);
			me->add("combat_exp",1);
			return;
		}

		message_vision(snprintf(msg, 255, "$n��ͷ����һ�ᣬ�ֿ��˿�$N�Ŀ�������̾�˿���������$P����%ld��%s��",
			amount, obj->name()), me, who);
			
//		me->improve_skill("begging", random(3)+1);
		me->improve_skill("begging", dp + random(dp));
		me->add("mp",-30);
		me->add("combat_exp",1);
		
		who->add_temp("last_beg_time", 1);		
		me->start_busy(6);
	} 
	else 
	{
		if( random(sp) > dp/2 ) 
		{
			message_vision("$n�ݺݵص���$Nһ�ۣ��ȵ������� $N����һ������æŤͷ��������߿��ˡ�", me, who);
			if(random(3)==1)
			{
				me->improve_skill("begging", 1);
				me->add("mp",-30);
			}
			who->add_temp("last_beg_time", 1);
			return;
		}
	
		message_vision("$nŤ��ͷȥ����$N������", me, who);
		me->improve_skill("begging", random(3)+1);
		me->add("mp",-30);
		me->start_busy(3);
	}
}

SKILL_END;





