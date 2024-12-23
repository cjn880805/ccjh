//datiewu.h

//Sample for room: 打铁屋
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXiaoYao_datiewu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "逍遥林打铁屋");

	CBox * box = Add_Box();
	box->add_object("blade_book", 1);	
	box->set_name( "铁柜");	

	add_item("xiaohuolu");

	add_door("逍遥林小道3", "逍遥林小道3", "逍遥林打铁屋");

	set("long", "这里是树林深处的一间小石屋，看来是打造兵器的，屋子中有个大火炉好烫的呢，屋中还有一张石几，上面放在一些已经打造好的兵器。");
	

/*****************************************************
	set("exits", ([
		"south" : __DIR__"xiaodao2",
	]));
	set("objects", ([
	       __DIR__"obj/blade": 2,
	]));
********************************************/
};


ROOM_END;
