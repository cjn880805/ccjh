//dalidong.h

//Sample for room:  大理城东
//coded by zouwenbin
//data: 2000-11-15

RESIDENT_BEGIN(CRDaLidong);

virtual void create()			
{
	set_name( "大理城东");

	set("resident", "大理");

	add_npc("pub_girl1");
	add_npc("pub_playboy");
	add_npc("pub_playboy");        //zdn 2001-07-12 add
	add_npc("helpnpc_jhlz");

	add_door("大理城西", "大理城西", "大理城东");

	add_door("大理城石铺", "大理城石铺", "大理城东");
	add_door("大理城药铺", "大理城药铺", "大理城东");
	add_door("大理城太和居", "大理城太和居", "大理城东");
	add_door("大理城王府大厅", "大理城王府大厅", "大理城东");
	add_door("大理城薛记成衣铺", "大理城薛记成衣铺", "大理城东");
};


RESIDENT_END;
