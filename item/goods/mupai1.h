//anjinmenkey.h
ITEM_BEGIN(CImupai1)

virtual void create(int nFlag = 0)		
{
	set_name("警示牌");
	set("no_get", "公共财产你也想拿走？……你也太过分了吧。");

};

virtual int do_look(CChar * me)
{
	say("飞凌九霄阁", me);
	say("要过此阁须解此题：", me);
	say("阁分九室，九宫排布，室内均有一秤，阁前取珠四十又五，分放诸室秤上，使得各室纵、横、斜排重量之和均为十五，则可触动机关，过得此阁。", me);
	say("如失败三次，则与此阁无缘，请君早回。", me);
	/*
	if(me->query("xy/renwu6") && me->query("xy/renwu6_1"))
	{
	}
	*/
	SendMenu(me);

	return 1;
}
ITEM_END;




