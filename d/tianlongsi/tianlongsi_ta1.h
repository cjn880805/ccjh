//ta1.h



//Sample for room:  天龙寺舍利塔1

//coded by zouwenbin

//data: 2000-11-30



//Note: these two headers must be include

//use macro ROOM_BEGIN(room_name) to declare room

//and use macro ROOM_END end declare

ROOM_BEGIN(CRTianLongSi_ta1);



virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "天龙寺舍利塔1");

	add_door("天龙寺塔林", "天龙寺塔林", "天龙寺舍利塔1");

	add_door("天龙寺无净阁", "天龙寺无净阁", "天龙寺舍利塔1");

	add_door("天龙寺无我阁", "天龙寺无我阁", "天龙寺舍利塔1");

	add_door("天龙寺崇圣宝殿", "天龙寺崇圣宝殿", "天龙寺舍利塔1");



	set("long","这是天龙三塔中最高的一座，高约三百余尺，共有十六级。相传塔顶原本供奉着一颗前代高僧的舍利子，但在当年奸臣杨义贞弑上德帝篡位以至天下大乱时，舍利子不知何因而失踪了，这也成为天龙寺历代主持的心腹大事。这个传言也不知是真是假。");




};


ROOM_END;
