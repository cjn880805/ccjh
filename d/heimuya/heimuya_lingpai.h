//lingpai.h

//Sample for room: 黑木崖令牌堂
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_lingpai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黑木崖令牌堂");
	
	add_npc("heimuya_huangbailiu");       //add by zdn 2001-07-20


	add_door("黑木崖青龙堂大厅", "黑木崖青龙堂大厅", "黑木崖令牌堂");

	set("long", "这里是黑木崖的第二大堂白虎堂的令牌室。室内青砖铺地。桌上有一盒子(box1).");
      

/*****************************************************
        set("exits", ([	
	    "west"      : __DIR__"qing",
	]));
	set("item_desc", ([
            "box1": "这是个放令牌的盒子，不过以被人打开，空空如也 。\n",
       	]) );
********************************************/
};


ROOM_END;
