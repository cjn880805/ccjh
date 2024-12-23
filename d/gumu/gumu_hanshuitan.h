//hanshuitan.h

//Sample for room: 古墓寒水潭
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuMu_hanshuitan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "古墓寒水潭");


	add_door("古墓草地2", "古墓草地2", "古墓寒水潭");

    set("long","这里是草地的边缘，青草已经很稀疏了，仍然有一二玉蜂来回地飞过寻觅食物。你的面前是一个清波荡漾的大水潭 (tan)，水很清，隐约可以见过水底的怪石嶙峋，一二游鱼倏地从水底游过，又不知道躲到哪块石头后面藏身去了。阳光映照下，水面泛起了一道七色彩虹，望着这般美景，你俗念尽消。" );

};

virtual int do_look(CChar * me)
{

	say("这里是草地的边缘，青草已经很稀疏了，仍然有一二玉蜂来回地飞过寻觅食物。你的面前是一个清波荡漾的大水潭 (tan)，水很清，隐约可以见过水底的怪石嶙峋，一二游鱼倏地从水底游过，又不知道躲到哪块石头后面藏身去了。阳光映照下，水面泛起了一道七色彩虹，望着这般美景，你俗念尽消。" ,me);
	if(me->query_temp("gumu/lin"))
	{
		say("一口很深的水潭，不知道可不可以潜(qian)下到这水底世界去？", me);
		AddMenuItem("试试", "$0qian", me);
		AddMenuItem("算了", "", me);
		
	}
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(me->query_temp("gumu/lin")&&strcmp(comm, "qian") == 0)
	{
		return do_qian(me);
	}
	return 0;
}

int do_qian(CChar * me)
{
	
	message_vision ("$N深深的吸了一口气，屏住呼吸，一个猛子扎到水中。只见水花翻溅之间，$N潜到了寒水潭底！", me);
	message_vision ("也不知$N游了多久，就在$N的呼吸逐渐急促的时候，猛然间$N看到眼前一亮，似乎前方到了尽头。", me);
	message_vision ("$N拖着疲惫的身体爬上了岸，抹了抹脸上的水珠，仔细开始打量着周围。。。", me);
	me->start_busy(5);
	if(random(me->query("age")+me->query("per"))>58)
	{
		me->delete_temp("gumu/lin");
		me->set_temp("gumu/tan",1);
		me->move(load_room("终南山太乙池"));
	}
	else
		me->move(load_room("终南山白马潭"));

	return 1;
}
ROOM_END;




