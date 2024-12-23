ITEM_BEGIN(CIguanyin);

virtual void create(int nFlag = 0)		
{
	set_name( "金身彩妆　观音像");	
	set("no_get", "把观音像偷走？……你也太异想天开了吧。");
	set_weight(1);
};

virtual int do_look(CChar * me)
{
	say("金身彩妆的一尊观音像。", me);
	AddMenuItem("跪下磕头", "$0kneel $1", me);
	AddMenuItem("转身离开", "", me);
	SendMenu(me);

	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "kneel") == 0)
		return do_kneel(me, arg);
	return 0;
}

int do_kneel(CChar *me, char * arg)
{
	me->receive_damage("hp",50);	
	message_vision("$N恭恭敬敬的给观音娘娘磕了个头。", me);   
	
	me->add_temp("teapot/guanyin",1);

	if (me->query_temp("teapot/guanyin")==3)
	{
		me->set_temp("teapot/guanyin",0l);
		message_vision("香火烟雾缭绕中你似乎看见观音娘娘冲$N微微一笑。", me);   
		tell_object(me,"你只觉得心中一片清明，忘记已往江湖上的的恩恩怨怨。");
		me->remove_all_killer();
		me->delete_temp("teapot/bot");
		return 1;
	}

	return 1;
	

}

ITEM_END;
