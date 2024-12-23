//shanlu.h

//Sample for room: ����ɽɽ·
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_shanlu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽɽ·");

	set("monster_chance", 1);

	add_door("����ɽ�㳡", "����ɽ�㳡", "����ɽɽ·");
	add_door("����ɽɽ·1", "����ɽɽ·1", "����ɽɽ·");

	set("long", "������ɽ�ϵ���·��");
	set("no_clean_up", 0l);

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
