//path1.h

//Sample for room: 华山脚下
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_path1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山脚下");
	
	add_npc("pub_tiaofu");           //add by zdn 2001-07-17

	add_door("华山玉泉院", "华山玉泉院", "华山脚下");
	add_door("华山莎萝坪", "华山莎萝坪", "华山脚下");
	add_door("华山村", "华山村", "华山脚下");

	set("long", "西岳华山，巍然耸立于陕西省华阴县城南。它北瞰黄河，南连秦岭，五座山峰高低错落，各据一方，其间又有一段若断若续的山岭相连，疏密有度，神韵天成，远远望去，状若巨朵青莲，外围诸峰如莲瓣，中间三峰似莲蕊，因此山便因'花'得名，取名华山。又因其西临少华山，故华山又称太华。它素有「奇峰天下第一山」之称，西面是小村。北是玉泉院。");  
    
 
/*****************************************************
        set("exits", ([  
            "west" : "/d/village/eexit",
            "north" : __DIR__"yuquan",
            "southeast" : __DIR__"shaluo",
        ]));
********************************************/
};


ROOM_END;
