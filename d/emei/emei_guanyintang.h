//guanyintang.h
//Sample for room:  峨嵋观音堂
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_guanyintang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋观音堂");
	add_npc("pub_girldizi");   // add yb zdn 2001-07-14

	CBox * box = Add_Box();
	box->add_object("coin", 60000);	//put 100 coind into box
	box->set_name( "终焉之印", "enchantment");
	box->Locked("结界", 18000);

	add_door("峨嵋解脱坡", "峨嵋解脱坡", "峨嵋观音堂");
	add_door("峨嵋归云阁", "峨嵋归云阁", "峨嵋观音堂");

	set("long","观音堂高踞坡岗，近临危崖，环境幽静，四周树木蓊郁，悦目赏心。传说入山于此，解脱尘凡；出山于此，解脱险阻，又故名解脱庵。进山的人在此焚香洗心，入山方可化险为夷，步步平安。这里东下可达伏虎寺，西上行约二里可到归云阁。");

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
