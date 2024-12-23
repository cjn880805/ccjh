//kedian.h

//Sample for room: 襄阳客栈
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRXiangYang_kedian);

virtual void create()			//Call it when Room Create
{
	set_name( "襄阳客栈");

	add_npc("pub_xiaoer2");

	add_door("襄阳西北", "襄阳西北", "襄阳客栈");

	set("long", "这是一家对江湖人士来说很有名气的客栈。人们到襄阳来一般都住在这里，一是便宜，二能听到江湖上的许多事情。近年来，襄阳退敌数十次，南来北往的人们经过襄阳更是打尖在这儿，顺便拜访一下郭靖等侠衣之士。" );
	set("sleep_room",1);
	
	set("no_fight", 1);
	set("valid_startroom", 1);

};


ROOM_END;
