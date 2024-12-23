//yipinjieyin.h

//Sample for room: 接引堂
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_yipinjieyin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "接引堂");
	
	add_npc("lingzhou_nuerhai");             //add by zdn 2001-07-14


	add_door("灵州一品堂大厅", "灵州一品堂大厅", "灵州接引堂");

	set("long", "这里是西夏一品堂的接引堂，每个自愿加入一品堂的江湖高手，都需有人充当接引人，查清底细，方能入堂。入堂以后，才有资格由赫连主管分派任务，为一品堂效力。好在这里有个专职接引的汉子，为一品堂广开贤路，所以一品堂在江湖中也确实声名雀起。");  

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
