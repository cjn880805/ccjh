//wuchangge.h

//Sample for room:  天龙寺无常阁
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_wuchangge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天龙寺无常阁");

	add_door("天龙寺瑞鹤门", "天龙寺瑞鹤门", "天龙寺无常阁");
	add_door("天龙寺晃天门", "天龙寺晃天门", "天龙寺无常阁");

	set("long","这是历代大理王侯前来进香还愿时休息的地方。阁内檀象宝炉，软榻矮几，一应俱全，清静之中隐然透出一丝富贵之象。");

/******************************************************************************
  
******************************************************************************/
};


ROOM_END;
