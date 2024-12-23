//xuedi1.h

//Sample for room: 雪地1
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_xuedi1);

virtual void create()			//Call it when Room Create
{
	set_name( "雪地1");

	add_npc("pub_yujiaofeng");
	add_npc("pub_xieyulun");

	set("resident", "关外宁远");

	add_door("关外宁远", "关外宁远", "关外雪地1");
	add_door("关外雪地2", "关外雪地2", "关外雪地1");

    set("long","这里是一片白茫茫的雪地，一眼望不到边际。四周一个人影也没有，厚厚的积雪踩起来发出咯吱的响声，大地上留下一串孤独的脚印。寒冷的北风呼啸而过，吹得脸生痛。暗淡的太阳低悬在天边，显得那么苍白。" );
    

/*****************************************************
	set("exits", ([
		"west"       : __DIR__"dongcheng",
		"northeast"  : __DIR__"xuedi2",
	]));
********************************************/
};

RESIDENT_END;
