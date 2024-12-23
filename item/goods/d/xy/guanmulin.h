//xueduei.h 逍遥任务特殊道具
ITEM_BEGIN(CIguanmulin)

virtual void create(int nFlag = 0)		
{
	set_name("灌木林", "guan mu lin");
	set("long",	"眼前是一片葱葱的灌木林，只有一条用阔斧开凿出来的依稀可见的小径向前伸延。");
	set("unit", "片");
	set_weight(1000);
	set("value", 1);
	set("no_get"," ");
};


virtual int do_look(CChar * me)
{
	say("眼前是一片葱葱的灌木林，只有一条用阔斧开凿出来的依稀可见的小径向前伸延。",me);
	say("如果你有柴刀，可以考虑砍下一些用做烧火生炉的柴禾。",me);
	AddMenuItem("砍灌木","$0kancai $1 0",me);
	AddMenuItem("等会再砍","",me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	
	if (strcmp(comm,"kancai") == 0)
	{
		if (me->is_busy())
		{
			switch(random(10))
			{
			case 0:
			case 1:
				return notify_fail("我在忙着呢，你少给我乱发指令……。");
				break;

			case 3:
				return notify_fail("我都快累死了，你有完没完？");
				break;

			case 7:
			case 8:
				return notify_fail("太累了，让我先歇会吧……");
				break;

			default:
				return notify_fail("唉呀，先等等，我的刀拔不出来了……");
				break;
			}
		}

		if (me->query("hp") < 60)
			return notify_fail("你的体力太低了，还是先睡一觉吧。");
		
		if (!me->PresentName("chaidao",IS_ITEM))	//如果玩家身上没有带柴刀
			return notify_fail("你没有柴刀怎么砍灌木呢？该不是想用宝刀宝剑来砍吧？");
		
		me->add("hp",-50);
		message_vision("\n$HIC$N拿起柴刀，对着面前的灌木林埋头砍了起来。", me);
		int lvl=me->query_skill("parry",1);
		int jump;
		if(lvl>=300)
			jump=1;
		else if(lvl>=200 )
		{
			if(random(100)>20)	jump=1;
		}
		else if(lvl>=100 )
		{
			if(random(100)>30)	jump=1;
		}
		else if(lvl>=50 )
		{
			if(random(100)>50)	jump=1;
		}
		if(jump==1)
		{
			load_item("chaihe")->move(me->environment());
			message_vision("$HIC你的身后很快就堆起了一簇柴禾，你满意的停了下来。",me);
			destruct(this);
		}
		else
		{
			message_vision("$HIC你累的满头大汗，手中的柴刀不右的停了下来。",me);
		}
		me->start_busy(3);
	
		return 1;

	}
	return CItem::handle_action(comm, me, arg);
}

ITEM_END;




