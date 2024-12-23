//chengdedian.h

//Sample for room: 成德殿
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_chengdedian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "成德殿");
	
	add_npc("heimuya_yang");        //add by zdn 2001-07-20
	add_npc("pub_xiangke");


	add_door("黑木崖日月坪", "黑木崖日月坪", "黑木崖成德殿");

	add_door("黑木崖后厅", "黑木崖后厅", "黑木崖成德殿");
	add_door("黑木崖内室", "黑木崖内室", "黑木崖成德殿");
	add_door("黑木崖休息室", "黑木崖休息室", "黑木崖成德殿");

	set("long", "这就是日月神教教主平日发号施令的地方，殿中无窗，殿口点着明晃晃的蜡烛，大殿彼端高设一座，坐着一个英俊的中年人，自是名震江湖的东方不败的姘头杨莲亭了！ ");
    set("valid_startroom", 1);

/*****************************************************
  set("exits",([
      "north" : __DIR__"huoting",
      "westdown":__DIR__"up4",
  ]));
  set("objects",([
      __DIR__"npc/dizi" : 2,
      __DIR__"npc/yang"    :1,
  ]));
//   
********************************************/
};


ROOM_END;




