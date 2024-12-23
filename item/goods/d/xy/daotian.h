//daotian.h 逍遥任务特殊道具
ITEM_BEGIN(CIdaotian)

virtual void create(int nFlag = 0)		
{
	set_name("稻田", "dao tian");
	set("long",	"稻田里满种稻禾，和暖的阳光正照耀着这片肥沃的土地，希望会有个好收成吧。");
	set("unit", "支");
	set_weight(1000);
	set("value", 1);
	set("no_get", "你也太异想天开了吧。");
};

virtual int do_look(CChar * me)
{
	say("稻田里满种稻禾，和暖的阳光正照耀着这片肥沃的土地，希望会有个好收成吧。",me);
	if (me->PresentName("liandao",IS_ITEM))
	{
		AddMenuItem("割稻子","$0ge $1 0",me);
		AddMenuItem("等会再割","",me);
	}
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	
	if (strcmp(comm,"ge") == 0)
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
		
		if (!me->PresentName("liandao",IS_ITEM))	//如果玩家身上没有带柴刀
			return notify_fail("你没有镰刀怎么砍割稻子呢？该不是想用宝刀宝剑来砍吧？");
		
		me->add("hp",-50);
		message_vision("\n$HIC$N拿起镰刀，对着面前的稻田埋头砍了起来。", me);
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
			load_item("daohe")->move(me->environment());
			message_vision("$HIC你的身后很快就堆起了一簇稻禾，你满意的停了下来。",me);
			destruct(this);
		}
		else
		{
			message_vision("$HIC你累的满头大汗，手中的镰刀不右的停了下来。",me);
		}
		me->start_busy(3);
		return 1;

	}
	return CItem::handle_action(comm, me, arg);
}

ITEM_END;




