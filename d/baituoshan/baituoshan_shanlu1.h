//shanlu1.h

//Sample for room: ����ɽɽ·1
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_shanlu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽɽ·1");

	set("monster_chance", 1);

	//add npcs into the room
	add_npc("pub_qiaofu");
	
	add_door("����ɽɽ·", "����ɽɽ·", "����ɽɽ·1");
	add_door("����ɽ����", "����ɽ����", "����ɽɽ·1");

	set("long", "������ɽ�ϵ���·��");

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
