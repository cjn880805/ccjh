//wfdating.h

//Sample for room: 王府大厅
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_wfdating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "王府大厅");

	//add npcs into the room
	add_npc("dali_jiading");
	add_npc("dali_gaoshengtai");
	add_npc("dali_zhuwanli");
	add_npc("dali_duanwuwei");
	add_npc("dali_duanyu");       //add by zdn 2001-07-20
	
	add_door("大理城东", "大理城东", "大理城王府大厅");
	add_door("大理城王府内厅", "大理城王府内厅", "大理城王府大厅");
	add_door("大理城王府帐房", "大理城王府帐房", "大理城王府大厅");
	add_door("大理城王府总理处", "大理城王府总理处", "大理城王府大厅");
	add_door("大理城王府兵器房", "大理城王府兵器房", "大理城王府大厅");
	add_door("大理城王府下人居室", "大理城王府下人居室", "大理城王府大厅");

	set("long", "进了大厅，放眼看那大厅，只见正中一块，横匾，写着‘邦国柱石’四个大字，下首署着‘丁卯御笔’四个小字，楹柱中堂悬满了字画，一时也看不了这许多。向北是镇南王总理国务见人办公之处，西边是帐房往东，是一条石径通往内宅。" );

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
