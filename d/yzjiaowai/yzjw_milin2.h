//milin2.h

//Sample for room:  扬州青竹林2
//coded by zwb
//data: 2000-11-22

ROOM_BEGIN(CRYZJW_milin2);

virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "青竹林");

	add_npc("pub_kanzhuren");          //add by zdn 2001-07-16

	add_door("扬州山路1","扬州山路1","扬州青竹林2");

    set("long","这是一片茂密的青竹林，一走进来，你仿佛迷失了方向。");

}
	
/*
	Add by wolfman
 edit date 2001-7-24
*/
virtual int do_look(CChar * me)
{
	say("这是扬州闻名的青竹林，所产的竹子比别处的要来得坚硬、厚重。一直以来，丐帮弟子的杖都是用这里的竹子做成的。",me);
	say("如果你有刀，可以考虑砍一根来做一把好的竹杖，或者做成一个盛水的竹筒。",me);
	AddMenuItem("砍竹子","$9kanzuzi 0 kan",me);
	AddMenuItem("等会再砍","",me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	
	char msg[255];

	if (strcmp(comm,"kanzuzi") == 0)
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
		
//error		if (EQUALSTR((me->query_weapon())->querystr("base_name"), "yuzhu_zhang"))		//如果玩家没有装备柴刀
		if (!me->PresentName("chaidao",IS_ITEM))	//如果玩家身上没有带柴刀
			return notify_fail("你没有柴刀怎么砍竹子呢？该不是想用宝刀宝剑来砍吧？");
		
		me->add("hp",-50);
		message_vision("$N打量了一会面前的竹林，瞅准一棵自认为是最好的竹子用力砍去……", me);
		
		if (me->PresentName("qingzugang",IS_ITEM))
		{
				message_vision("突然竹林中跳出一个丐帮长老对着$N喊道：想不到江湖上还有你这种贪心的家伙，给我滚。",me);
				message_vision("接着对准$N的屁股飞起一脚，把$N踢出青竹林。",me);
				me->move(load_room("扬州山路1"));
				tell_room(me->environment(), 
					snprintf(msg, 255, "只听“嘭”地一声，%s从青竹林里飞了出来，跌了个四脚朝天。", me->name()), me);
				return 1;
		}

		switch(random(15))
		{
		case 0:
			load_item("qingzugang")->move(me);
			me->start_busy(3);
			message_vision("只听“咔嚓”一声，一株竹子倒了下来。",me);
			message_vision("$N得到了一根竹子。",me);
			return 1;
			break;

		case 1:
			load_item("zhutong")->move(me);
			me->start_busy(3);
			message_vision("只听“咔嚓”一声，一株竹子倒了下来。",me);
			message_vision("你拿起柴刀，选择竹子最粗壮的一截砍去。",me);
			message_vision("$N得到了一个竹筒。",me);
			return 1;
			break;

		case 2:
			if( DIFFERSTR(me->querystr("family/family_name"), "丐帮"))
			{
				message_vision("突然竹林中跳出一个丐帮长老对着$N喊道：竟敢偷我丐帮宝竹，给我滚出去。",me);
				message_vision("接着对准$N的屁股飞起一脚，把$N踢出青竹林。",me);
				me->move(load_room("扬州山路1"));
				tell_room(me->environment(), 
					snprintf(msg, 255, "只听“嘭”地一声，%s从青竹林里飞了出来，跌了个四脚朝天。", me->name()), me);
				return 1;
			}
			
			load_item("qingzugang")->move(me);
			message_vision("结果砍偏了，什么也没砍到。\n这时走出一位丐帮长老，对着$N笑咪咪的说道：不用砍了，我这里有一根，你先拿去用吧。",me);
			message_vision("$N得到了一根竹子。",me);
			return 1;
			break;
		
		default:
			message_vision("$N你砍了老半天，什么也没砍着，心想：“怎么最近我的运气总是这么背？”",me);
			return 1;
			break;
		}
	}
	return 0;
}


ROOM_END;
