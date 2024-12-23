//yuxuguan.h

//Sample for room: 玉虚观
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDaliEast_yuxuguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "玉虚观");

	add_npc("dali_daobaifeng");	

	add_door("大理城玉虚观前", "大理城玉虚观前", "大理城玉虚观");

	set("long", "玉虚观内十分清检，正中供着张果老、吕洞宾、何香姑等八仙的塑像，香火缭绕，供桌上摆着些蟠桃。正中放了几个蒲团。旁边一个小间里摆着桌椅，是玉虚散人休息和授徒的地方。" );

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
