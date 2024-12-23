//xiaoting.h

//Sample for room: 燕子坞晓寒厅
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_xiaoting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞晓寒厅");
	
	add_npc("murong_wang"); 
	add_npc("murong_wyy");          //add by zdn 2001-07-20

	add_door("燕子坞翠霞堂", "燕子坞翠霞堂", "燕子坞晓寒厅");
	add_door("燕子坞厨房", "燕子坞厨房", "燕子坞晓寒厅");
	add_door("燕子坞小径", "燕子坞小径", "燕子坞晓寒厅");

    set("long", "这是一间小厅,厅虽不大,布置倒也别致。满厅的芳香，沁人心脾。只见墙上挂着几幅条幅,笔致颇为潇洒,但掩不住几分柔弱之气。厅内四周精巧地摆着些桌子(table)和椅子(chair)。 " );
    
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