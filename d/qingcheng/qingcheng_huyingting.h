//huyingting.h

//Sample for room: 青城呼应亭
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_huyingting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "青城呼应亭");
	
	add_npc("pub_youke");         // add by zdn 2001-07-14
	add_npc("qingcheng_ji");     //add by zdn 2001-07-20


	add_door("青城上清宫", "青城上清宫", "青城呼应亭");

	set("long","呼应亭高居彭祖峰顶，是青城最高处。登临长啸，余音回荡，众山皆应。看雪岭光腾，红吞沧海，锦江春涨，绿到瀛洲。夏日夜分，有圣灯浮云，传说是神仙朝贺张天师所点仙灯，看来让人感叹不已。 '天下第五名山' 气势浑厚，很是壮观。");
    

/*****************************************************
    set("outdoors","qingcheng");
	set("exits", ([
		"eastdown" : __DIR__"shangqing",
	]));
	set("objects", ([
		__DIR__"npc/hou" : 1,
	]));
*****************************************************/
};


ROOM_END;
