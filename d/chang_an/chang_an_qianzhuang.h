//qianzhuang.h

//Sample for room: 长安相记钱庄
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_qianzhuang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "长安相记钱庄");

	//add npcs into the room
	//add_npc("tiesuanpan");
	
	add_door("长安", "长安", "长安相记钱庄");

	set("long", "这是一家老字号的钱庄，相老板是山西人，这家钱庄从他的爷爷的爷爷的爷爷的爷爷那辈开始办起，一直传到他手里，声誉非常好，在全国各地都有分店。它发行的银票通行全国。钱庄的门口挂有一块牌子(paizi)。" );
	set("no_fight", 1);

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}


CHANGAN_END;
