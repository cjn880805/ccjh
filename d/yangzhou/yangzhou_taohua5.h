//taohua5.h

//Sample for room: 桃花坪
//coded by zwb
//data: 2000-12-1

RESIDENT_BEGIN(CRYangZhou_taohua5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "桃花坪");

	set("resident", "桃花村");
	
	add_npc("pub_flowerg");         //add by zdn 2001-07-16
	add_npc("guiyun_hanbaoju"); 
	add_npc("guiyun_nanxiren");             //zdd by zdn 2001-07-20


	add_door("扬州桃花村", "扬州桃花村", "扬州桃花坪");

	set("long", "桃花坪是个小盆地。此处四面环山，山间白云缭绕，山上桃林层叠，如列屏障。中有小溪潺潺流过，清澈碧透。春鸟娇鸣，游鱼踊跃，春岚气动，景象万千。坪中大大小小琉瓦别墅，山野之中诸多风味。" );
	

/*****************************************************
	set("exits", ([
		"south"     : __DIR__"taohua4",
	]));
********************************************/
};


RESIDENT_END;
