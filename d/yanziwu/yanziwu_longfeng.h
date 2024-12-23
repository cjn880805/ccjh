//longfeng.h

//Sample for room: 燕子坞龙凤厅
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_longfeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞龙凤厅");

	add_door("燕子坞品笛庭", "燕子坞品笛庭", "燕子坞龙凤厅");
	add_door("燕子坞仪门", "燕子坞仪门", "燕子坞龙凤厅");
	add_door("燕子坞梨香苑", "燕子坞梨香苑", "燕子坞龙凤厅");

    set("long", "这是一座气势巍峨，构造宏大的大厅堂，大门前一对大石狮子张牙舞爪，厅门上 '龙凤厅' 三个大字遒劲有力，气度不凡。厅中墙上挂满名人字画，一张大八仙桌上茶具齐整，四周围着一圈檀香木大椅。" );
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