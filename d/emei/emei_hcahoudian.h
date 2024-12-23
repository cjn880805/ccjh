//hcahoudian.h

//Sample for room:  峨嵋华藏庵后殿
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_hcahoudian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋华藏庵后殿");

	add_npc("emei_miejue");
	add_npc("emei_zhou");
	add_npc("zm_emei");

	add_door("峨嵋华藏庵大雄宝殿", "峨嵋华藏庵大雄宝殿", "峨嵋华藏庵后殿");

	set("long","这是峨嵋山华藏庵的后殿。是峨嵋派掌门人传教弟子功夫的地方。这里供有一尊普贤菩萨像。两旁靠墙放着几张太师椅，地上放着几个蒲团。掌门人正在向几个女弟子传授武功。");
    
    set("no_get_from", 1);
    set("no_get", 1);
    set("no_steal", 1);

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
