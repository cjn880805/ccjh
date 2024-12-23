//entrance.h

//Sample for room: 大森林
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_entrance);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大森林");


	add_door("万劫谷山路4", "万劫谷山路4", "万劫谷大森林");
	add_door("万劫谷草地", "万劫谷草地", "万劫谷大森林");

	set("long","这里是好大一座森林，黑压压的一片望不到边。最特别是左首一排并列着九株参天大松树，每颗树都高耸入云。树下草丛茂密，挡住了去路。");

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
