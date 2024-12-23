//tingyu.h

//Sample for room: 听雨轩
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_tingyu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "听雨轩");
	
	add_npc("pub_shutong");        //add by zdn 2001-07-16


	add_door("苏州南", "苏州南", "苏州听雨轩");

	set("long", "听雨轩是苏州城内的一处唯一的一家书店了。这里有着各种各样的书籍，什么小说啦、风光旅游啦、手艺制作啦、基本武功啦，等等等等。只须花几两银子就可买到你想要的书。 " );
 	
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
