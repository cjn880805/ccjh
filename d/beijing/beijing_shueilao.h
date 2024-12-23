//shueilao.h 水牢

ROOM_BEGIN(CRBeiJing_shueilao);

virtual void create()
{
	set_name( "水牢");
	set("no_fight",1);
	set("no_cast",1);

	set("long", "这是一间阴暗的地下水牢。你正站在水牢正中一块仅够立足的岩石上。数丈高的牢房顶上，一个碗口大小的方洞透下一束细细的光柱。" );

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		double value = 480;		//8分钟
		time_t t;
		time(&t);
		t += (time_t)value;	
		me->set_temp("wei/endtime",t);
		me->call_out(do_jianshi, 480);
	}
}

int handle_action(char *comm, CChar *me, char * arg, char * target)
{
	if(me->query_temp("wei/renwu2_1"))
	{
		double value = 480;		//8分钟
		time_t t;
		time(&t);
		t += (time_t)value;	
		me->set_temp("wei/endtime",t);
	}
	
	return CRoom::handle_action(comm, me, arg, target);
}

static void do_jianshi(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	time_t t;
	time(&t);
	if(me->query_temp("wei/renwu2_1") && EQUALSTR((me->environment())->querystr("base_name"),"北京万宝楼水牢" ))
	{
		tell_object(me, "\n$YEL从水牢顶的方洞处隐约传来说话的声音。");
		if(t>=me->query_temp("wei/endtime"))
		{
			tell_object(me, "$YEL牢顶方洞处一个人往下看了一眼，惊叫了一声：“不好，怎么一点动静也没有，是不是死了！”");
			tell_object(me, "$YEL只听得水牢顶上轰隆隆一阵世响，似乎是一块巨石被移开去，露出了一个两尺见方的大洞。");
			tell_object(me, "$YEL从大洞处垂下几根带勾的绳索，把你勾了出去。");
			me->delete_temp("wei/endtime");
			me->set_temp("wei/renwu2_2",1);//从地牢中出来
			me->move(load_room("北京万宝楼"));
		}
		else
		{
			tell_object(me, "$YEL牢顶方洞处一个人往下看了一眼，说道：“没事，跑不了！”");
			me->call_out(do_jianshi, 480);
		}
	}
}
ROOM_END;
