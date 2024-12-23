//xuedi2.h

//Sample for room: 雪地2
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_xuedi2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "雪地2");

	set("resident", "关外");
	
	add_npc("animal_dog");           // add by zdn 2001-07-14

	set("monster_chance", 50);

	add_door("关外雪地1", "关外雪地1", "关外雪地2");
	add_door("关外雪地3", "关外雪地3", "关外雪地2");

    set("long","这里是一片白茫茫的雪地，一眼望不到边际。四周一个人影也没有，厚厚的积雪踩起来发出咯吱的响声，大地上留下一串孤独的脚印。寒冷的北风呼啸而过，吹得脸生痛。暗淡的太阳低悬在天边，显得那么苍白。" );
    

/*****************************************************
	set("exits", ([
		"east"       : __DIR__"xuedi3",
		"southwest"  : __DIR__"xuedi1",
	]));
********************************************/
};


RESIDENT_END;
