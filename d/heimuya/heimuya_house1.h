//house.h

//Sample for room: 黑木崖内室
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_house);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黑木崖内室");
	
	add_npc("heimuya_zhang1");       //add by zdn 2001-07-20
	add_npc("pub_xiangke");


	add_door("黑木崖成德殿", "黑木崖成德殿", "黑木崖内室");

	set("long", "这是一个精雅的小舍，一进门便可闻到一阵浓冽的花香。房中挂着一幅五女向凤图，图中绘着五个宫装美女，美目盼兮，艳丽脱俗。屋里还有一张茶几，几张椅子，椅子上铺着绣花锦垫，西面有一扇洞形门通向后厅。 ");
    
    set("valid_startroom", 1);

/*****************************************************
  set("exits",([
      "west"      : __DIR__"huoting",
  ]));
//  set("objects", ([
//      __DIR__"npc/xifang" : 1,
//  ]));                                                    
  
********************************************/
};


ROOM_END;




