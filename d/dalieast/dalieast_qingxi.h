//qingxi.h

//Sample for room: 大理城清溪三潭
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_qingxi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城清溪三潭");

	set("resident", "碧鸡山");

	//add npcs into the room
	add_npc("pub_biaotou");
	add_npc("xy_licanghai");
	add_npc("pub_liushengshibingwei");
	
	add_door("大理城碧鸡山顶", "大理城碧鸡山顶", "大理城清溪三潭");
	add_door("大理城林间小道1", "大理城林间小道1", "大理城清溪三潭");
	add_door("大理城大叠水瀑布", "大理城大叠水瀑布", "大理城清溪三潭");

	set("long", "清溪三潭，又名翠盆水，隐藏在苍山马龙峰与圣应峰之间幽深的峡谷中。山泉岩根涌出，喷珠泻玉，岩溪汇池，壮若大盆，分三叠，水清石丽，翠碧交加，故俗称清碧溪。" );
};


RESIDENT_END;




