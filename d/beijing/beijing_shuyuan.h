//shuyuan.h

//Sample for room: 书院
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_shuyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "书院");



	add_door("北京西北", "北京西北", "北京书院");

	set("long", "这里是书院的讲堂，窗明几净，一尘不染。一位庄重严肃的老者坐在太师椅上讲学，那就是京城的大儒顾炎武了。在他的两侧坐满了求学的学生。一张古意盎然的书案放在顾先生的前面，案上摆着几本翻开了的线装书籍。顾先生的身后是一个书架(shujia)讲堂内多历代楹联石刻，足见书院历史的悠久。值得一提的是嵌在讲堂前左壁的学规(xuegui)。" );
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
