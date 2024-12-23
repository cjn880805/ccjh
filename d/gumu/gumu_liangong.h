//liangong.h

//Sample for room: 古墓练功室
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuMu_liangong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "古墓练功室");

	add_door("古墓休息室", "古墓休息室", "古墓练功室");
	add_door("古墓正厅", "古墓正厅", "古墓练功室");

    set("long","这座石室形状甚是奇特，前窄後宽，成为梯形，东边半圆，西边却作三角形状，原来这是以前重阳祖师的练功室，前窄练掌，後宽使拳，东圆研剑，西角发镖。" );
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
