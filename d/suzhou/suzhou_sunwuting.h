//sunwuting.h

//Sample for room: 孙武亭
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_sunwuting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "孙武亭");
	
	add_npc("pub_youke");        //add by zdn 2001-07-16


	add_door("苏州试剑石", "苏州试剑石", "苏州孙武亭");

	set("long", "在真娘幕后的土丘上，有一座小亭子，名为孙武亭。相传春秋时，兵家孙武曾在此训练两队宫女，由吴王的两个宠姬分别担任队长，由于宠姬与宫女们不听军令，虽三令五申，仍置若罔闻，孙武遂下令，先斩两姬于军前以整军纪。后人遂筑此亭。" );
	

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
