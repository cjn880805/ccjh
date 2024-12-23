//huanglongdong.h

//Sample for room: 杭州黄龙洞
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_huanglongdong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州黄龙洞");

	//add npcs into the room
	add_npc("animal_dushe");
	
	add_door("杭州山路8", "杭州山路8", "杭州黄龙洞");

	set("long"," 一进山门，松篁交翠，别有洞天。石壁陡削，苔痕常绿；回廊临之间有一小峰，上题：“有龙则灵”。");
    

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
