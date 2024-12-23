//zhonglie.h

//Sample for room: 忠烈祠
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_zhonglie);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "忠烈祠");
	
	add_npc("xiangyang_ya");        //add by zdn 2001-07-20

	add_door("襄阳东北", "襄阳东北", "襄阳忠烈祠");

	set("long", "这里是襄阳城的忠烈祠，十余年来为保卫襄阳而牺牲的烈士遗骨都安葬在这里，每个有爱国心的好汉到这都会来祭奠一下忠魂。" );
	set("no_fight", 1);
	set("no_beg", 1);
	
/*****************************************************
	set("exits", ([
		"west" : __DIR__"eastroad2",
	]));
********************************************/
};


ROOM_END;
