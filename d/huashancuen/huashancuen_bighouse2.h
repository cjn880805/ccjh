//bighouse2.h

//Sample for room: 华山村财主家内室
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRHuaShanCuen_bighouse2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山村财主家内室");
	
	add_npc("pub_lady3");       //add by zdn 2001-07-14

	add_door("财主家前厅", "华山村财主家前厅", "华山村财主家内室");

  	set("long","这里是一间寝室，屋子中间有一张大床，床上的被褥居然是绸缎的，看来这个土财主对自己并不是十分刻薄。屋里摆着几只木箱子，墙角里有一只大柜子(cabinet)。" );
    

/*****************************************************
        set("exits", ([
            "west" :"/d/village/bighouse1",
        ]));
*****************************************************/
};


ROOM_END;
