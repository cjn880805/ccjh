//xuedi3.h

//Sample for room: 雪地3
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_xuedi3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "雪地3");

	set("resident", "关外");

	set("monster_chance", 50);

	add_door("关外雪地2", "关外雪地2", "关外雪地3");
	add_door("关外船厂", "关外船厂", "关外雪地3");

    set("long","这里是一片白茫茫的雪地，一眼望不到边际。四周一个人影也没有，厚厚的积雪踩起来发出咯吱的响声，大地上留下一串孤独的脚印。寒冷的北风呼啸而过，吹得脸生痛。暗淡的太阳低悬在天边，显得那么苍白。" );
    

/*****************************************************
	set("exits", ([
		"north"  : __DIR__"chuanchang",
		"west"   : __DIR__"xuedi2",
	]));
********************************************/
};


RESIDENT_END;
