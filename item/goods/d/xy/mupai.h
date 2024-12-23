//anjinmenkey.h
ITEM_BEGIN(CImupai)

virtual void create(int nFlag = 0)		
{
	set_name("警示牌");
	set("no_get", "公共财产你也想拿走？……你也太过分了吧。");

};

virtual int do_look(CChar * me)
{
	say("敬告闯塔之冒险者：四象塔屹立数百年，始终无入可闯破。只因其中不仅有道行高深的上古守卫，尚有各式可怕可怕的机关阵法。", me);
	say("进入塔中，唯有触引正确的机关，方可进入更高一层。否则不仅难以前进，更会遭遇机关伤害。", me);
	say("谨以此警示，望入塔者善自珍重。", me);
	SendMenu(me);

	return 1;
}
ITEM_END;




