//taihu.h
//Sample for room: 燕子坞太湖
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_taihu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞太湖");
	
	add_npc("pub_youke");       //add by zdn 2001-07-16
	add_npc("pub_qinjinzhe");


	add_door("燕子坞泊舟坞", "燕子坞泊舟坞", "燕子坞太湖");
	add_door("苏州南门", "苏州南门", "燕子坞太湖");

    set("long", "绿衫少女脸带微笑，如春花般娇痴无瑕。两手划桨，不时采摘莲实戏耍。口中漫声唱道:  '菡萏香连十顷陂，小姑贪戏采莲迟。晚来弄水船头滩，笑脱红裙裹鸭儿。' 碧玉般湖面淡淡弥散着轻柔的曲调。" );
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query("wei/renwu1") && !me->query("wei/renwu5") 
		&& me->query_temp("wei/renwu5_5") && !me->query_temp("wei/renwu5_7"))
	{
		say("太湖湖面波光粼粼，在阳光的照射下，湖水清澈透明，可以看到许多白色的小鱼在水中悠然地游来游去。",me);
		AddMenuItem("潜下去", "$0jinru $1", me);
	}
		
	AddMenuItem("采荷花", "$0cai $1", me);
	AddMenuItem("摘荷叶", "$0zai $1", me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(!strcmp(comm, "jinru"))
	{
		return do_jinru(me, arg);
	}
	if(!strcmp(comm, "cai"))
	{
		return do_cai(me, arg);
	}
	if(!strcmp(comm, "zai"))
	{
		return do_zai(me, arg);
	}
	return 0;
}

int do_jinru(CChar *me, char * arg)
{
	if(me->query("wei/renwu1") && !me->query("wei/renwu5") && me->query_temp("wei/renwu5_5") && !me->query_temp("wei/renwu5_7"))
	{
		me->move(load_room("燕子坞太湖湖底"));
		me->set_temp("wei/renwu5_time",me->query("max_mp")/100);
		me->call_out(do_time, 10);
	}
	return 1;
}

int do_cai(CChar *me, char * arg)
{
	tell_object(me,"$HIR看着满湖盛开的荷花，你忍不住信手采下一朵赏玩起来。");
	load_item("hehua")->move(me);
	return 1;
}

int do_zai(CChar *me, char * arg)
{
	tell_object(me,"$HIR你漫步到湖边，随手摘下一片荷叶顶在头上冲着路人做起了鬼脸。");
	load_item("heye")->move(me);
	return 1;
}

static void do_time(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if((me->environment())->query("water"))//在太湖水底
	{
		me->add_temp("wei/renwu5_time",-10);
		if(me->query_temp("wei/renwu5_time")<0)
		{
			char msg[255];
			tell_object(me,snprintf(msg,255, "\n$HIR你感觉胸口越来越闷，不由得张嘴吞了口湖水，结果造成了%d点伤害。\n",me->query("max_hp")/20));
			me->add("hp",-me->query("max_hp")/20);
			if(me->query("hp")<1)
				me->set("hp",1);
		}
		me->call_out(do_time, 10);
	}
}

ROOM_END;
