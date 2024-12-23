//hanguguan.h

//Sample for room: 函谷关
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_hanguguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "函谷关");
	
	add_npc("pub_playboy");  //2001-07-12 zdn add

	add_door("长安大官道2", "长安大官道2", "长安函谷关");
	add_door("长安关洛道", "长安关洛道", "长安函谷关");
	add_door("襄阳西北", "襄阳西北", "长安函谷关");

	set("long", "这里就是古函古关。它东起崤山，西接潼津，关设谷中。当年强秦一隅之地，制关东六国而不敢稍动，最后横扫天下，就是因为它据此，进可攻，退可守，乃天下形胜之处。老子西出化胡，也是在此留下两册道德经，千载以下，后人仍研读不尽。" );
	
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
