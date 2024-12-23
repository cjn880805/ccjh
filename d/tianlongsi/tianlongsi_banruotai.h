//banruotai.h

//Sample for room:  天龙寺般若台
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_banruotai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天龙寺般若台");

	add_door("天龙寺兜率大士院", "天龙寺兜率大士院", "天龙寺般若台");
	add_door("天龙寺牟尼堂", "天龙寺牟尼堂", "天龙寺般若台");

	set("long","这是个普通的石台，相传当年佛祖曾降临此台传法。再往南去就是本寺重地——牟尼堂。江湖中传言天龙寺的镇寺之宝——六脉神剑谱就藏于此中，但你千万不要打什么主意。");
    

/******************************************************************************
	set("exits", ([
		"south" : __DIR__"munitang",
		"north" : __DIR__"doushuai",
	]));
******************************************************************************/
};


ROOM_END;
