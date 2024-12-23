//xiuxishi.h

//Sample for room:  梅庄休息室
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRMeiZhuang_xiuxishi);

virtual void create()			//Call it when Room Create
{
	set_name( "梅庄休息室");

	add_door("梅庄走廊2", "梅庄走廊2", "梅庄休息室");

	set("sleep_room", 1);
    set("no_fight", 1);

	set("valid_startroom", 1);

};

virtual int do_look(CChar * me)
{
	CContainer * yaosi;
	yaosi=me->present("yao si");
	if(yaosi && yaosi->query("ry/yaosi") && EQUALSTR(yaosi->querystr("owner1"), me->id(1)) && me->query_temp("ry/renwu1_2") && !me->query_temp("ry/renwu1_3"))
	{
		tell_object(me,"\n$HIR你仔细打量休息室，眼光四处摸索着。猛然你看到不远处的地面上有一个小小的缝隙，似乎是一个锁孔。");
		tell_object(me,"$HIR你掏出怀中的钥匙，塞进缝隙中。");
		tell_object(me,"$HIR从看似平滑无奇的石头地面竟缓缓列开一道缝隙，露出一条通道。没想到梅庄底下机关制作如此精密，若不是亲眼所见真不敢相信在古代中国已经有了这么好的石匠技术！");
		me->move(load_room("梅庄水下石牢"));
		me->set_temp("ry/renwu1_3",1);//进入水下石牢
		destruct(yaosi);
	}
	else
	{
		say("这里没有什么特别的。",me);
		SendMenu(me);
	}
	return 1;
}

ROOM_END;
