//mianguan.h

//Sample for room: 面馆
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_mianguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "面馆");

	//add npcs into the room
	add_npc("pub_xiaoer2");/////////////////////////
				

	add_door("北京西南", "北京西南", "北京面馆");

	set("long", "这是一家价钱低廉的面馆，生意非常兴隆。外地游客多选择这里落脚，你可以在这里打听到各地的风土人情。穷人们也都喜欢来这里。店小二里里外外忙得团团转，接待着南腔北调的客人。几张脏乎乎的小木桌旁，坐满了各种各样的食客。" );
	set("sleep_room",1);
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
