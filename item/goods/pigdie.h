//pigdie.h
ITEM_BEGIN(CIpigdie)

virtual void create(int nFlag = 0)		
{
	 set_name("����", "pig");
     set("long", "����һֻ��ȥ��Ұ��ͷ����ǰ�ȡ����ȶ����ü�Ϊ��׳��");
     set_temp("zhutou", 1);
     set_temp("forleg", 1);
     set_temp("backleg", 1);
     set_weight(5000);
     set("unit", "ֻ");
     set("value", 300);
};

int do_get(CChar * me)
{
    if( me->query("str")<25 )
    {
        tell_object(me, "��ֻҰ��̫���ˣ����ò�����");
        return 1;
    }
    
	message_vision("$N����һ��ֻ��̫���ˣ������ܲ��ˡ�", me);
    move(me);
    return 0;
}

int do_ge(CChar * me, string arg)
{
    if( ! me->present("cut knife"))
    {
         tell_object(me, "��û�к��ʵĶ������С��аѲ˵����֮��ľͺ��ˡ�");
         return 1;
    }

    if(arg == "zhutou")
	{
		if( query_temp("zhutou")==1)
        {
             message_vision("$N����Ұ���ͷ��", me);
             load_item("zhutou")->move(me);
             set_temp("zhutou" , 0l);
        }
        else
        {
             tell_object(me, "��Ұ���ͷ�ѱ��˿����ˡ�");
             return 1;
        }
	}
	else if(arg == "forleg")
	{
		if( query_temp("forleg") == 1)
		{
			 message_vision("$N����Ұ���ǰ�š�", me);
			 load_item("forleg")->move(me);
			 set_temp("forleg", 0l);
		}
		else
		{
			 tell_object(me, "��Ұ���ǰ���ѱ��˿����ˡ�");
			 return 1;
		}
	}
	else if(arg == "backleg")
	{
		if( query_temp("backleg") == 1)
        {
             message_vision("$N����Ұ��ĺ�š�",me);
             load_item("backleg")->move(me);
             set_temp("backleg", 0l);
        }
        else
        {
             tell_object(me, "��Ұ��ĺ����ѱ��˿����ˡ�");
             return 1;
        }
   }

	if ((query_temp("zhutou")==0) && (query_temp("forleg")==0) && (query_temp("backleg")==0))
        destruct(this);
    
    return 1;
}

ITEM_END;
