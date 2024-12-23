//lingwenge.h

//Sample for room:  峨嵋灵文阁
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_lingwenge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋灵文阁");

	add_npc("emei_zhao");
				
	add_door("峨嵋福寿庵", "峨嵋福寿庵", "峨嵋灵文阁");

	set("long","这里是福寿庵的灵文阁，是主持静照师太传授佛法的地方。两名青衣小尼随侍在旁，似乎在聆听师太的教晦。阁内布置简陋，靠墙放着几把竹椅，地上放着几个蒲团。东首有一禅房。西面是一个斋厅。");

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
