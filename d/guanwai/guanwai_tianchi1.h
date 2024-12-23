//tianchi1.h

//Sample for room: ��ͷɽ���1
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_tianchi1);

virtual void create()			
{
	set_name( "��ͷɽ���1");
	
	add_npc("pub_playboy");   

	set("monster_chance", 2);

	add_door("�������ŷ�", "�������ŷ�", "�����ͷɽ���1");
	add_door("������Ʒ�", "������Ʒ�", "�����ͷɽ���1");
	add_door("���⻪�Ƿ�", "���⻪�Ƿ�", "�����ͷɽ���1");
	add_door("�����ͷɽ���2", "�����ͷɽ���2", "�����ͷɽ���1");

	set("long","������ڳ���ɽ�����ĵ㣬Ⱥ�廷������ظ�Լ��ʮ�������ء�����ر̲�ӯӯ���峺տ��������Χ�ͱڰ��ɣ���Ӱ��Ӱ��ӳ���У�����ɽɫ���Ӱ����ʮ�����ˡ��������ⷼ�����𣬰ٻ����ޡ�����ʫ�ƣ������İ�ʮ��ͱ����رߡ�ˮ������أ��Ƶͱ����졣��ɽ��������¹���ǰԵ���買Я����������ο���ꡣ��" );
    
};

virtual int do_look(CChar * me)
{
	say("������ڳ���ɽ�����ĵ㣬Ⱥ�廷������ظ�Լ��ʮ�������ء�����ر̲�ӯӯ���峺տ��������Χ�ͱڰ��ɣ���Ӱ��Ӱ��ӳ���У�����ɽɫ���Ӱ����ʮ�����ˡ��������ⷼ�����𣬰ٻ����ޡ�", me);
	say("����ʫ�ƣ������İ�ʮ��ͱ����رߡ�ˮ������أ��Ƶͱ����졣��ɽ��������¹���ǰԵ���買Я����������ο���ꡣ��", me);
	if (me->query_temp("gumu/jq_gu") && !me->query_temp("gumu/read"))
	{
		say("������صĲ�Զ����һ���Ե���Щ��ͬ�ľ��������Ӳ��ڶ࣬���Ӳݴ���������һ��ɽ��������ף���֪�������ǲ��Ǿ����������������ԥ�С�",me);
		AddMenuItem("���ȥ�ˣ�����ɽ��", "$0jump $1", me);
		AddMenuItem("�����һ����Ӵ���������˰�", "$0no $1", me);
	}
	SendMenu(me);
	return 1;
}


virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (!me->query_temp("gumu/jq_gu"))
		return 0;
	if(strcmp(comm, "jump") == 0)
		return do_ssb(me, arg);
	if(strcmp(comm, "no") == 0)
		return do_no(me, arg);
	return 0;
}


int do_ssb(CChar *me, char * arg)
{
	if (me->is_busy())
		return notify_fail("��������æ���ء�");
	
   	message_vision("$N��ԥ��һ�»���������ȥ", me);
	if(random(2)||me->query_temp("gumu/read"))
	{
		message_vision( "$Nһ�Ų��˸��գ�ˤ�ı������ˡ�", me);
		me->set("hp",me->query("hp")/4);
		me->start_busy(3);
		message_vision("$HIR$N��������Χ����Ȼ�����ƺ��ص���һ����Ϥ�ĵط���",me);
		me->move(load_room("��Ĺ��Ϣ��"));
	}
	else
	{
		DTItemList * list = me->Get_ItemList();
		POSITION p = list->GetHeadPosition();
		CContainer * obj;
		while(p)
		{
			obj = list->GetNext(p);
			if(userp(obj) )
			{
				me->set_temp("gumu/zuobi",1);
				break;
			}
		}
		if(!me->query_temp("gumu/zuobi"))
		{
			message_vision( "$HIR$N����ȥƨ���������ڻ����ϣ��۵����˹�ȥ��", me);
			me->start_busy(15);
			me->move(load_room("�����"));
		}
		else
		{
			message_vision( "$Nһ�Ų��˸��գ�ˤ�ı������ˡ�", me);
			me->set("hp",me->query("hp")/4);
			me->start_busy(3);
			message_vision("$HIR$N��������Χ����Ȼ�����ƺ��ص���һ����Ϥ�ĵط���",me);
			me->move(load_room("��Ĺ��Ϣ��"));
			me->delete_temp("gumu/zuobi");
		}
	}
	return 1;
}

int do_no(CChar *me, char * arg)
{
	me->delete_temp("gumu/jq_gu");
	return 1;
}

ROOM_END;




