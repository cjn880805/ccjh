//qsdadao8.h
//Sample for room: 刑堂
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_qsdadao8);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "明教青石大道8");
	add_npc("pub_zhenwanjian");

	add_door("明教青石大道7", "明教青石大道7", "明教青石大道8");
	add_door("明教青石大道9", "明教青石大道9", "明教青石大道8");
	add_door("明教巨木旗大厅", "明教巨木旗大厅", "明教青石大道8");

	set("long", "这里大道平坦，地势开阔，两旁树林中鸟语花香，一片和平安祥的气氛。");
    

/*****************************************************

********************************************/

};


virtual int do_look(CChar * me)
{
	say("大路旁边有块巨石，看起来十分怪异。你心中一动，不由得想过去推一推。", me);
	AddMenuItem("用力推啊!", "$0tui", me);
	AddMenuItem("算了", "", me);

	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(strcmp(comm, "tui") == 0)
	{
		return do_tui(me);
	}
	else if(strcmp(comm, "enter") == 0)
	{
		return do_enter(me);
	}
	return 0;
}

int do_tui(CChar * me)
{
	if(me->query_str() < 22)
	{
		message_vision ("$N使尽吃奶的力气推来推去，眼前的巨石纹丝不动。", me);
		return 0;
	}
	else
	{
		message_vision ("$N大喝一声：“开!”，奋力把巨石推开，露出一个黑森森的洞口。", me);

		AddMenuItem("进去看看", "$0enter", me);
		AddMenuItem("算了", "", me);
	
		SendMenu(me);
		return 0;
	}
}

int do_enter(CChar * me)
{
	int hurt;
	hurt = me->query("max_hp")/8 * (random(5)+1);
	switch (random(6))
	{
	case 0://金
		message_vision ("$N犹豫了一下，纵身跳入地洞中。只听一阵“锵锵”的急响，四面八方有无数利箭飞射而出。", me);
		me->receive_damage("hp", hurt);
		me->receive_wound("hp", hurt);
		break;

	case 1://木
		message_vision ("$N犹豫了一下，纵身跳入地洞中。只听一阵“砰砰”的巨响，数十根巨木同时向你椿来。", me);
		me->receive_damage("hp", hurt);
		me->receive_wound("hp", hurt);
		break;

	case 2://水
		message_vision ("$N犹豫了一下，纵身跳入地洞中。只听一阵“嗤嗤”的轻响，一股毒水兜头淋下，滴在皮肤上直冒青烟。", me);
		me->receive_damage("hp", hurt);
		me->receive_wound("hp", hurt);
		break;

	case 3://火
		message_vision ("$N犹豫了一下，纵身跳入地洞中。只听一阵“呼呼”的风声，脚下突然冒出熊熊烈火，顿时把你烧成一个火人。", me);
		me->receive_damage("hp", hurt);
		me->receive_wound("hp", hurt);
		break;

	case 4://土
		message_vision ("$N犹豫了一下，纵身跳入地洞中。只听一阵“轰轰”的巨响，无数大石当头落下，把你砸了个七荤八素。", me);
		me->receive_damage("hp", hurt);
		me->receive_wound("hp", hurt);
		break;

	case 5://lucky
		message_vision ("$N犹豫了一下，纵身跳入地洞中。", me);
		break;
	}

	CRoom * r = load_room("明教秘道4");
	me->move(r);
	return 0;
}

ROOM_END;
