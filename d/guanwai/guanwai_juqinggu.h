//GuanWai_jueqinggu.h �����
//�ز� 2002.3.8

ROOM_BEGIN(CRGuanWai_jueqinggu);

virtual void create()			
{
	set_name("�����");
	set("monster_chance", 20);
	add_door("�����ͷɽ���1","�����ͷɽ���1","�����");
    
};

virtual int do_look(CChar * me)
{
	if (me->query_temp("gumu/jq_gu"))
	{
		say("ǰ��һ��ʯ�ŵ�ס��ȥ·����չ�ȥ��ϸ�鿴����Ȼ��ͻȻ��������ʯ������һ����С�Ŀס�", me);
		AddMenuItem("ʹ��Կ��", "$0useys $1", me);
	}
	else
		say("ǰ��һ��ʯ�ŵ�ס��ȥ·��", me);
	SendMenu(me);
	return 1;
}


virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (!me->query_temp("gumu/jq_gu"))
		return 0;
	if(strcmp(comm, "useys") == 0)
		return do_useys(me, arg);
	return 0;
}


int do_useys(CChar *me, char * arg)
{
//	char msg[255];
	CContainer * bot;

	if (me->is_busy())
		return notify_fail("��������æ���ء�");

   	DTItemList * list = me->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		
		if(obj->is_character()) continue; 
		if(userp(obj) )
		{
			me->set_temp("gumu/zuobi",1);
			me->delete_temp("gumu/goto");
			break;
		}
		bot = (CContainer *)obj;  
		if(!DIFFERSTR(bot->querystr("id"), "anjinmenkey") && bot->query("bz")==atoi(me->id(1)))
		{
			me->set_temp("gumu/goto",1);
			destruct(bot);
			break;
		}
	}		
	if(me->query_temp("gumu/goto") && !	me->query_temp("gumu/zuobi") )
	{
		me->delete_temp("gumu/goto");
		message_vision("$N�ó��������͸���Կ�ף����˰���ʯ��������ˡ�",me);
		message_vision("$Nֻ������¡¡��һ�������������ǰ��ʯ�Ż�����������ȥ��", me);
		message_vision("$N��ǰ��ʱһ����һ�����ⰻȻ��ɽ����������ǰ��", me);
		me->move(load_room("�����ɽ��"));
	}
	return 1;
}

ROOM_END;




