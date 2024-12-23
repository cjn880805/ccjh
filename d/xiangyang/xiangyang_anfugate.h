//anfugate.h

//Sample for room: 安抚使衙门
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_anfugate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "安抚使衙门");

	add_npc("pub_xiexunfu"); 
	add_npc("pub_yuguangqi");
	add_npc("pub_xyqinbing");

	add_door("襄阳西北", "襄阳西北", "襄阳安抚使衙门");

	set("long", "这是安抚使衙门的大门，铜皮包门似乎极为沉重，上面有两个明晃晃的铜环；大门紧闭，里面却传出一阵阵嬉笑声，和门口的肃杀很不协调。想来这个安抚使大人的日子还是过得蛮滋润的。" );
	set("outdoors", "xiangyang");
	
/*****************************************************
	set("exits", ([
		"south" : __DIR__"anfupailou",
	]));
********************************************/
};


ROOM_END;
