//qinfang.h

//Sample for room: 燕子坞沁芳阁
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_qinfang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞沁芳阁");
	
	add_npc("murong_abi");        //add by zdn 2001-07-20
	

	add_door("燕子坞仪门", "燕子坞仪门", "燕子坞沁芳阁");

    set("long", "这里是供慕容世家的仆人小憩的地方，三面临水。微风拂过，送来缕缕的荷花叶香，沁人心脾，沁芳阁因此而名。一架墨绿色的竹梯通向楼上的休息室。" );
	
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
//last, register the room into ../server/RoomSetup.cpp