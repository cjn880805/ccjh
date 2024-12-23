//dannuo.h

//Sample for room: 燕子坞啖糯厅
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_dannuo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞啖糯厅");

	add_door("燕子坞仪门", "燕子坞仪门", "燕子坞啖糯厅");
	add_door("燕子坞听香水榭", "燕子坞听香水榭", "燕子坞啖糯厅");

    set("long", "这是一间雅致的大厅，厅上摆着几张紫檀木大桌。桌上银制餐具一应俱全，桌边一溜犁花木椅。每日慕容世家很多人都在此用餐。" );
    
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