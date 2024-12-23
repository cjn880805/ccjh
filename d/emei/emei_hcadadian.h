//hcadadian.h

//Sample for room:  峨嵋华藏庵大雄宝殿
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_hcadadian);

virtual void create()			//Call it when Room Create
{
	set_name( "峨嵋华藏庵大雄宝殿");

	add_npc("emei_dao");
	add_npc("pub_ningfeng");
			

	add_door("峨嵋华藏庵广场", "峨嵋华藏庵广场", "峨嵋华藏庵大雄宝殿");
	add_door("峨嵋华藏庵斋堂", "峨嵋华藏庵斋堂", "峨嵋华藏庵大雄宝殿");
	add_door("峨嵋华藏庵禅房", "峨嵋华藏庵禅房", "峨嵋华藏庵大雄宝殿");
	add_door("峨嵋华藏庵后殿", "峨嵋华藏庵后殿", "峨嵋华藏庵大雄宝殿");

	set("long","这是峨嵋山华藏庵的大雄宝殿。正中供奉着普贤菩萨。一群青衣小师太正在地上诵经。后面有道小门通往后殿。");
    
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




