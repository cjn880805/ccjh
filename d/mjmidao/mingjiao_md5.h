//mingjiao_md5.h



//Sample for room:  明教秘道5

//coded by cat
//data: 2001-3-20

ROOM_BEGIN(CRMingJiao_md5);


virtual void create()			//Call it when Room Create

{
	//set name of our room

	set_name( "明教秘道5");

	CDoor * door = add_door("明教秘道8", "明教秘道8", "明教秘道5");//上
	door->set_name( "秘道");

	door = add_door("明教秘道7", "明教秘道7", "明教秘道5");//下
	door->set_name( "秘道");

	door = add_door("明教秘道6", "明教秘道6", "明教秘道5");//左
	door->set_name( "秘道");

	door = add_door("明教秘道1", "明教秘道1", "明教秘道5");//右
	door->set_name( "秘道");
};

virtual int do_look(CChar * me)
{
	say("密道的墙上似乎有个机关，你一时间不知道该不该去扳动它。", me);
	AddMenuItem("试试", "$0tui", me);
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
	return 0;
}

int do_tui(CChar * me)
{
	CRoom * room = load_room("明教青石大道8");
	int hurt;
	hurt = me->query("max_hp")/8 * (random(5)+1);

	switch (random(3))
	{
	case 0://boring
		message_vision ("$N扳动机关，只听见沙沙一阵轻响，头上掉来了一把灰尘，就再没任何动静了。", me);
		return 0;

	case 1://unlucky
		message_vision ("$N扳动机关，只听哐当一声脚下露出一个大洞，$N在自己的惨叫声中掉了下去。", me);
		me->move(room);
		message_vision ("$N摔得伤痕累累痛不欲生，还是昏过去吧，昏了就不觉得痛了。", me);
		me->receive_damage("hp", hurt);
		me->FlushMyInfo();
		me->unconcious();
		return 0;

	case 2://very unlucky
		switch (random(5))
		{
		case 0://金
			message_vision ("$N犹豫了一下扳动机关。只听一阵“锵锵”的急响，四面八方有无数利箭飞射而出。", me);
			me->receive_damage("hp", hurt);
			me->receive_wound("hp", hurt);
			break;
			
		case 1://木
			message_vision ("$N犹豫了一下扳动机关。只听一阵“砰砰”的巨响，数十根巨木同时向你椿来。", me);
			me->receive_damage("hp", hurt);
			me->receive_wound("hp", hurt);
			break;
			
		case 2://水
			message_vision ("$N犹豫了一下扳动机关。只听一阵“嗤嗤”的轻响，一股毒水兜头淋下，滴在皮肤上直冒青烟。", me);
			me->receive_damage("hp", hurt);
			me->receive_wound("hp", hurt);
			break;
			
		case 3://火
			message_vision ("$N犹豫了一下扳动机关。只听一阵“呼呼”的风声，脚下突然冒出熊熊烈火，顿时把你烧成一个火人。", me);
			me->receive_damage("hp", hurt);
			me->receive_wound("hp", hurt);
			break;
			
		case 4://土
			message_vision ("$N犹豫了一下扳动机关。只听一阵“轰轰”的巨响，无数大石当头落下，把你砸了个七荤八素。", me);
			me->receive_damage("hp", hurt);
			me->receive_wound("hp", hurt);
			break;
		}
		me->FlushMyInfo();
		return 0;
	}
	return 0;
}

ROOM_END;
