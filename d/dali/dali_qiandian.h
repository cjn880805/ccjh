//qiandian.h

//Sample for room: 前殿
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_qiandian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "前殿");

	//add npcs into the room
	add_npc("pub_taijian");
	
	add_door("大理城西", "大理城西", "大理城皇宫前殿");
	add_door("大理城皇宫正殿", "大理城皇宫正殿", "大理城皇宫前殿");
	add_door("大理城皇宫偏殿", "大理城皇宫偏殿", "大理城皇宫前殿");
	add_door("大理城皇宫御膳坊", "大理城皇宫御膳坊", "大理城皇宫前殿");

	set("long", "这里是大理国皇宫的前殿，红砖绿瓦建得十分精巧，大理历代国主勤政爱民，万几宸函，都在此殿。因此大理虽偏处西南的小国，百姓对当朝君臣的爱戴均出自肺腑，十分真诚。往北就到了御花园, 往南是皇宫大门。" );

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
