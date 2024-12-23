//taohua2.h

//Sample for room: 桃花溪
//coded by zwb
//data: 2000-12-1

RESIDENT_BEGIN(CRYangZhou_taohua2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "桃花溪");

	set("resident", "桃花村");
	
	add_npc("pub_playboy");          //add by zdn 2001-07-16
	add_npc("guiyun_kezhene");             //zdd by zdn 2001-07-20


	add_door("扬州桃花林", "扬州桃花林", "扬州桃花溪");
	add_door("扬州桃花谷", "扬州桃花谷", "扬州桃花溪");

	set("long", "“桃花林畔桃花溪，桃花溪水清如洗。浪子浮云空相照，浣衣歌女梦依稀。”这里就是桃花溪岸长草小径。桃花开有花落时，桃花落时，片片飞红空坠溪中，流水送去，决无怜惜。你伶立溪上，睹物思人，伤情无限。 " );
	

/*****************************************************
	set("exits", ([
		"westup" : __DIR__"taohua3",
		"south"  : __DIR__"taohua1",
	]));
********************************************/
};


RESIDENT_END;
