//yaodian.h

//Sample for room: 济世堂药店
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_yaodian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "济世堂药店");

	//add npcs into the room
	add_npc("pub_xiaohuoji");
	set("no_fight", 1);
	add_door("成都西", "成都西", "成都济世堂药店");

	set("long",	"济世堂药店卖很多中原买不到的药。托唐门的福，生意一直都很好。一走进这家药店，就闻到一股股浓烈刺鼻的药味。你正奇怪药店伙计怎麽能忍受，就看到药店里还有一些人正拿奇怪的眼光看你。他们的腰间鼓鼓囊囊的，显然不是好惹的。"	);
	

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
