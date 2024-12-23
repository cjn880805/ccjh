//fengwu.h

//Sample for room: 古墓蜂屋
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuMu_fengwu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "古墓蜂屋");


	add_door("古墓小厅", "古墓小厅", "古墓蜂屋");
	add_door("古墓孙婆婆小屋", "古墓孙婆婆小屋", "古墓蜂屋");

    set("long","这里是小龙女喂养训练玉蜂的蜂屋，屋角上挂着很多个六角形的蜂巢，还未进门，就闻得到一阵蜂蜜的甜香。" );
	set("have_honey", 1);
};

static void do_reset(CContainer * ob, LONG param1, LONG param2)
{
	ob->set("have_honey", 1);
}

virtual int do_look(CChar * me)
{
	say("这里是小龙女喂养训练玉蜂的蜂屋，屋角上挂着很多个六角形的蜂巢，还未进门，就闻得到一阵蜂蜜的甜香。", me);
	say("这里有不少玉蜂在飞舞着。看来可以到蜂巢去采点蜂蜜。", me);
	AddMenuItem("试试", "$0caimi", me);
	AddMenuItem("算了", "", me);

	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(strcmp(comm, "caimi") == 0)
	{
		return do_caimi(me);
	}
	return 0;
}

int do_caimi(CChar * me)
{
	int level = me->query_skill("qufeng",1);
	int rate;
	rate = random(100);

	if(level == 0 && rate <= 20)
	{
		if(query("have_honey") == 1)
		{
			message_vision ("$N不顾一切从蜂巢里抓出一罐蜂蜜，结果被玉蜂叮得满头是疱。", me);
			load_item("fengmi")->move(me);
			del("have_honey");
		}
		else
		{
			message_vision ("$N不顾一切伸手掏蜜，结果蜜没捞到却被玉蜂叮得满头是疱。", me);
			call_out(do_reset, 900);
		}
		if (rate == 0)
			rate = 5;
		me->apply_condition("yufeng_poison", rate * 3);
		return 0;
	}
	if(rate < level)
	{
		if(query("have_honey") == 1)
		{
			message_vision ("$N施展驱蜂术慢慢引开玉蜂，成功从蜂巢里采集出一罐蜂蜜。", me);
			load_item("fengmi")->move(me);
			del("have_honey");
		}
		else
		{
			message_vision ("$N施展驱蜂术慢慢引开玉蜂，却发现蜂巢里的蜜已被采光。", me);
			call_out(do_reset, 900);
		}
		return 0;
	}
	else
	{
		message_vision ("$N试图采集蜂密，结果蜜没捞到却被玉蜂叮得满头是疱。", me);
		me->apply_condition("yufeng_poison", rate * 3);
	}
	return 0;
}

ROOM_END;
