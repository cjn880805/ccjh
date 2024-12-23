//hsroad1.h

//Sample for room: 青石大道
//coded by zouwenbin
//data: 2000-11-18

RESIDENT_BEGIN(CRHuaShanCuen_hsroad1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "青石大道");
	
	set("resident", "华山村");

	add_npc("pub_daoke");
	add_npc("pub_playboy");     //add by zdn 2001-07-14


	add_door("华山村", "华山村", "华山村青石大道");
	add_door("黑木崖龙门渡口", "黑木崖龙门渡口", "华山村青石大道");
	add_door("长安大官道2", "长安大官道2", "华山村青石大道");

  	set("long","这是一间很普通的青砖瓦房，但在这个小村子里已是首屈一指的“豪宅”了。这里是前厅，厅里的摆设很简单，乡下土财主都很财迷，就算有几个钱儿，也是舍不得花。东边是个小门通向内室。" );
    

/*****************************************************
        set("exits", ([ 
            "west" :__DIR__"sroad4",
            "east" :__DIR__"bighouse2",
        ]));
*****************************************************/
};


RESIDENT_END;
