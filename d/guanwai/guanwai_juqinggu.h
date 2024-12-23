//GuanWai_jueqinggu.h 绝情谷
//秦波 2002.3.8

ROOM_BEGIN(CRGuanWai_jueqinggu);

virtual void create()			
{
	set_name("绝情谷");
	set("monster_chance", 20);
	add_door("关外白头山天池1","关外白头山天池1","绝情谷");
    
};

virtual int do_look(CChar * me)
{
	if (me->query_temp("gumu/jq_gu"))
	{
		say("前边一个石门挡住了去路。你凑过去仔细查看这块居然，突然发现这块巨石上有着一个很小的孔。", me);
		AddMenuItem("使用钥匙", "$0useys $1", me);
	}
	else
		say("前边一个石门挡住了去路。", me);
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
		return notify_fail("你现在正忙着呢。");

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
		message_vision("$N拿出百晓生送给的钥匙，开了半天石门总算打开了。",me);
		message_vision("$N只听见轰隆隆的一阵机关响声，眼前的石门缓缓的升了上去。", me);
		message_vision("$N眼前顿时一亮，一条春意盎然的山道呈现在面前。", me);
		me->move(load_room("绝情谷山道"));
	}
	return 1;
}

ROOM_END;




