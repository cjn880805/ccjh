//mojingtai.h

//Sample for room: 衡山磨镜台
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_mojingtai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山磨镜台");


	add_door("衡山山路6", "衡山山路6", "衡山磨镜台");
	add_door("衡山山路8", "衡山山路8", "衡山磨镜台");
	add_door("衡山山路7", "衡山山路7", "衡山磨镜台");

    set("long","磨镜台位于燕子岩下，与半山亭一沟相邻。台前峰回路转，台旁古松苍翠，环境清幽。相传南宗禅宗怀让在此宣扬 '顿悟法门' ，坐台高僧斗法，怀让磨镜，智服北宗道一，此台因而传名。 '磨镜台之幽' 是衡山大四绝之一。" );
    

/*****************************************************
        set("exits", ([ 
           "southdown"  : __DIR__"shanlu8",
           "westup"     : __DIR__"shanlu7",
           "northup"    : __DIR__"shanlu6",
        ]));
********************************************/
};


ROOM_END;
