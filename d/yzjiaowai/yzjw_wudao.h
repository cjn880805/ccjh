//wudao.h

//Sample for room:  扬州武道场
//coded by zwb
//data: 2000-11-22


ROOM_BEGIN(CRYZJW_wudao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州武道场");

	add_npc("pub3_gongpingzi");

	add_door("扬州西门大道","扬州西门大道","扬州武道场");

    set("long","这里是比武大会巫师席，高据擂台之上，雕梁琉瓦，花木游栏。四望青山迎爽，向下看擂台周围人头攒动。桌上放着一块小木牌 (pai)，后壁上贴着一张红纸告示(gaoshi)。");


/********************************************************
        set("outdoors", "city");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
		"pai"    : (: look_pai :),
	]));
	set("exits", ([
		"down"      : __DIR__"leitai",
	]));

  for more information look ../yangzhou/wudao.h
********************************************************/
 
};


ROOM_END;
