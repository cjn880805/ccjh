//pigdie.h
ITEM_BEGIN(CIpigdie)

virtual void create(int nFlag = 0)		
{
	 set_name("死猪", "pig");
     set("long", "这是一只死去的野猪，头部、前腿、后腿都长得极为粗壮。");
     set_temp("zhutou", 1);
     set_temp("forleg", 1);
     set_temp("backleg", 1);
     set_weight(5000);
     set("unit", "只");
     set("value", 300);
};

int do_get(CChar * me)
{
    if( me->query("str")<25 )
    {
        tell_object(me, "这只野猪太沉了，你拿不动。");
        return 1;
    }
    
	message_vision("$N扛起一整只猪，太沉了，真是受不了。", me);
    move(me);
    return 0;
}

int do_ge(CChar * me, string arg)
{
    if( ! me->present("cut knife"))
    {
         tell_object(me, "你没有合适的东西来切。有把菜刀或柴刀之类的就好了。");
         return 1;
    }

    if(arg == "zhutou")
	{
		if( query_temp("zhutou")==1)
        {
             message_vision("$N砍下野猪的头。", me);
             load_item("zhutou")->move(me);
             set_temp("zhutou" , 0l);
        }
        else
        {
             tell_object(me, "这野猪的头已被人砍走了。");
             return 1;
        }
	}
	else if(arg == "forleg")
	{
		if( query_temp("forleg") == 1)
		{
			 message_vision("$N砍下野猪的前脚。", me);
			 load_item("forleg")->move(me);
			 set_temp("forleg", 0l);
		}
		else
		{
			 tell_object(me, "这野猪的前腿已被人砍走了。");
			 return 1;
		}
	}
	else if(arg == "backleg")
	{
		if( query_temp("backleg") == 1)
        {
             message_vision("$N砍下野猪的后脚。",me);
             load_item("backleg")->move(me);
             set_temp("backleg", 0l);
        }
        else
        {
             tell_object(me, "这野猪的后腿已被人砍走了。");
             return 1;
        }
   }

	if ((query_temp("zhutou")==0) && (query_temp("forleg")==0) && (query_temp("backleg")==0))
        destruct(this);
    
    return 1;
}

ITEM_END;
