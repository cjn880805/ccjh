//qimen_wuxing.h ��������
//Code by Teapot
//2001.02.15


SKILL_BEGIN(CSqimen_wuxing);

virtual void create()
{
	set_name( "��������");

	set("special", 1);

	Magic_t * magic;

	magic = add_magic("escape", do_escape);
	magic->name = "���Ŷݼ�";
	magic->mp = 400;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
	
	magic = add_magic("mizheng", do_mizheng);
	magic->name = "��������";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual const char * type() { return "knowledge"; }

virtual int valid_learn(CChar * me)
{
	if(me->query_skill("qimen_wuxing", 1) > 5*me->query("int"))//�������ơ�
		return notify_fail("����������ֻ����ϰ�����");

	return 1;
}

static int do_escape(CChar * me, CContainer * ob)
{
	int i;
	CContainer * troom;
	troom=me->environment();
	
	i=me->query_skill("qimen_wuxing",1);
	if( i < 100)
		return notify_fail("����������е������㣡");	// �츳�������ϵ��˷���ʩչ��

	if( me->query("mp") < 400)
		return notify_fail("��ķ������㣡");
	me->add("mp", -400);

	me->start_busy(6);	// Busy.

	i=i/10;	// ÿ�ν�����Ϸ�����ʩչ������	һ���������Ϊ��������������������������

	message_vision("ֻ��$N����һ����ָ��ɲ�Ǽ䱬��һ�����̣�$N���������벻����",me);

	if (me->query_temp("teapot/escape")>i || me->query_temp("no_fei")|| me->query_temp("no_fei_1"))		//Fail.
	{
		message_vision("����ͻȻһ��紵����������ɢ������$N�����޴��վ�����С�",me);
		return 1;
	}

	if (!random(i+1))	// Fail:�ȼ�Խ�ߣ��ɹ���Խ��
	{
		message_vision("����ͻȻһ��紵����������ɢ������$N�����޴��վ�����С�",me);
		return 1;
	}

	me->add_temp("teapot/escape",1);

	message_vision("����������ɢ��$N��Ȼ��Ӱ���ۡ�",me);

	troom = load_room("�һ����һ���");
	me->move(troom);
	message_vision("һ��紵�����㷢����߷·�ͻȻ���˸���Ӱ�����ֺ����Ѿ�������վ�˺ܾ��ˡ�",me);

	if (!random(i+1))
	{
		tell_object(me,"���ӳ����죬���÷·�ȫ��ľ�������ɢ��һ�㡭��");
		me->unconcious();
	}

	return 1;
}

//���Ű�������
static int do_mizheng(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if(  me->query_skill("qimen_wuxing", 1) < 120 )
		return notify_fail("����������е������㣡");
	
	if (me->query_temp("thd/mazed")) 
		return notify_fail("������������˲��������С�");

	if(me->query("mp") <150 ) 
		return notify_fail("������������Բ�һ������");

	if(me->query_temp("thd/maze") ) 
		return notify_fail("���Ѿ�����һ�������ˡ�");

	if(DIFFERSTR(me->querystr("family/family_name"), "�һ���") )
		return notify_fail("����Ȼ��˵��������������һ�У�����ȴδ���ڡ�\n");
	
	if(random(me->query_int()) > target->query_int()/2 ||
		 random(me->query_skill("qimen_wuxing", 1))> target->query_skill("qimen_wuxing", 1)/2)
	{
		msg ="\n$HIY$Nһ����ս��һ��������Χ��ʯ�顢��֦�Ȳ���һ���򵥵���$n��ʱ�����޴롣\n"  ;
		
		int skill = me->query_skill("qimen_wuxing", 1);

		me->add_temp("apply/defense", skill/5);
		me->set_temp("thd/maze", 1);
		me->set_temp("thd/maze_id", target->object_id());
		me->UpdateMe();

		target->add_temp("apply/dodge",-(skill/10));
		target->set_temp("thd/mazed", 1);
		target->set_temp("thd/mazed_id", me->object_id());
		target->UpdateMe();

		me->call_out(remove_effect, 1, target->object_id(),skill/2);
	}
	else
	{
		msg ="\n$HIY$Nһ����ս��һ��������Χ��ʯ�顢��֦�Ȳ���һ���򵥵�����ͼ��ס$n��\n$n��˼Ƭ�̣�΢ȻһЦ������һ�����м�֮����һ�ţ���һ�ţ��ٽ��㲼�µ���������ȥ��"  ;
		me->start_busy(2);
	}
	message_vision(msg.c_str(), me, target);

	return 1;
}

static void remove_effect(CContainer * ob, LONG param1, LONG count)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);
	int skill = me->query_skill("qimen_wuxing", 1);
	if(me) 
	{
		if (!target) //��������뿪��ս�����򽫻ָ�˫����״̬
		{
			target=(CChar *)find_object(me->query_temp("thd/maze_id"), 1);
			if(target)
			{
				target->add_temp("apply/dodge",skill/10);
				target->delete_temp("thd/mazed");
				target->delete_temp("thd/mazed_id");
				target->UpdateMe();
				tell_object(target, "\n$HIY������������Ѿ�ʧЧ�ˡ�\n");
			}
			me->delete_temp("thd/maze");
			me->delete_temp("thd/maze_id");
			me->add_temp("apply/defense", - (skill/5));
			me->UpdateMe();
			tell_object(me, "\n$HIY�㲼�������Ѿ�ʧЧ�ˡ�\n");
			return;
		}
		if (count>0 && me->is_fighting(target))
		{
			me->call_out(remove_effect, 1, target->object_id(),count-1);
			return;
		}
		me->delete_temp("thd/maze");
		me->delete_temp("thd/maze_id");
		me->add_temp("apply/defense", - (skill/5));
		me->UpdateMe();

		target->add_temp("apply/dodge",skill/10);
		target->delete_temp("thd/mazed");
		target->delete_temp("thd/mazed_id");
		target->UpdateMe();

		char msg[255];
        if (target && me->is_fighting(target))
		{
			tell_object(me, snprintf(msg, 255, "\n$HIY�㲼�������Ѿ���%s�ƻ��ˡ�\n",target->name(1)));
			if (userp(target) && living(target))
				tell_object(target,snprintf(msg, 255, "\n$HIY%s���㲼�������Ѿ�����ʶ���ˡ�\n",me->name(1)));
		}
		else 
		{
			tell_object(me, "\n$HIY�㲼�������Ѿ�ʧЧ�ˡ�\n");
		}
	}
}

SKILL_END;

