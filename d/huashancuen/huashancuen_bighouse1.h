//bighouse1.h

//Sample for room: 财主家前厅
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRHuaShanCuen_bighouse1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "财主家前厅");
	
	add_npc("pub_boy");     //add by zdn 2001-07-14


	add_door("华山村", "华山村", "华山村财主家前厅");
	add_door("财主家内室", "华山村财主家内室", "华山村财主家前厅");

  	set("long","这是一间很普通的青砖瓦房，但在这个小村子里已是首屈一指的“豪宅”了。这里是前厅，厅里的摆设很简单，乡下土财主都很财迷，就算有几个钱儿，也是舍不得花。东边是个小门通向内室。" );
    

/*****************************************************
        set("exits", ([ 
            "west" :__DIR__"sroad4",
            "east" :__DIR__"bighouse2",
        ]));
*****************************************************/
};


ROOM_END;
