//yongdao.h

//Sample for room: 侠客岛甬道
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_yongdao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛甬道");
	
	add_npc("pub_dizi3"); 
	add_npc("pub_dizi3");        //add by zdn 2001-07-16

	add_door("侠客岛瀑布", "侠客岛瀑布", "侠客岛甬道");
	add_door("侠客岛石洞1", "侠客岛石洞1", "侠客岛甬道");

    set("long", "这里往来者甚多，多数是急匆匆武林人物，亦有不少青衣弟子。许多人都手持食物边走边吃，惟恐耽误了时间。几个衣衫褴褛的乞丐便在墙边鼾然入睡。一个小僮踮起脚尖，正在添加灯油。" );
    

/*****************************************************

********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp