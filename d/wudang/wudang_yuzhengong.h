//yuzhengong.h

//Sample for room: 遇真宫
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRWuDang_yuzhengong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "遇真宫");

	add_npc("wudang_zhixiang");	
	
	add_door("武当玄岳门", "武当玄岳门", "武当遇真宫");
	add_door("武当柏林", "武当柏林", "武当遇真宫");

	set("long","这里是进入武当山的第一道宫宇遇真宫，宽敞无比，可容千人食宿，是进香客的一大歇脚处。三丰真人曾在此结庵修炼，因此宫中供着张三丰真人像。由于张真人闭关已久，外人不知其是否仍在人间，民间传说他已得道仙逝，立像膜拜。");

/*****************************************************
      set("objects", ([
           CLASS_D("wudang") +"/zhixiang": 1,
      ]));
      set("outdoors", "wudang");
      set("exits",([ 
          "northdown": __DIR__"shijie1",
          "southup"  : __DIR__"wdbl",
      ]));
*****************************************************/
};


ROOM_END;
