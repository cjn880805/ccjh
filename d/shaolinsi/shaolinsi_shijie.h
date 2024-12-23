//shijie.h

//Sample for room: 少林寺石阶
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_shijie);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "少林寺石阶");
	
	add_npc("zm_shaolin");
	add_npc("helpnpc019");

	add_door("少林寺山门殿", "少林寺山门殿", "少林寺石阶");
	add_door("嵩山太室阙", "嵩山太室阙", "少林寺石阶");

	set("long", "石级继续向上延伸，瀑布在脚下越来越小，水声也渐行远去几位身着灰黄色僧衣的僧人擦肩而过，看他们下山的时後脚步沉稳，好象是个会家子。往上远眺，似乎可以看到石檐一角。" );

/*****************************************************

********************************************/
};


ROOM_END;
