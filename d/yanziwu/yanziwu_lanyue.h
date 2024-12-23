//lanyue.h

//Sample for room: 揽月居
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_lanyue);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "揽月居");
	
	add_npc("murong_fu"); 
	add_npc("murong_azhu");      //add by zdn 2001-07-20

	add_door("燕子坞翰墨书屋", "燕子坞翰墨书屋", "燕子坞揽月居");
	add_door("燕子坞还施水阁", "燕子坞还施水阁", "燕子坞揽月居");

    set("long", "这是慕容公子的卧室，房中陈设普通，收拾得颇为整洁，屋角一架茂兰盆景长得很是旺盛。晚上月光从窗户射进来，满室银光，是燕子坞的一大美景。" );
    
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
