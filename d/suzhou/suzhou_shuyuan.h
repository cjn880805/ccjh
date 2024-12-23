//shuyuan.h

//Sample for room: 书院
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_shuyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "书院");

	//add npcs into the room
	add_npc("pub_jiaoxi");/////////////////////////
	add_npc("pub_marulong");

	add_door("苏州南", "苏州南", "苏州书院");

	set("long", "这里是书院的讲堂，窗明几净，一尘不染。一位老夫子坐在太师椅上讲学。在他的两侧坐满了求学的学生。一张古意盎然的书案放在他的前面，案上摆着几本翻开了的线装书籍。 " );
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
