//hebian.h

//Sample for room: 河边
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_hebian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "河边");

	//add npcs into the room
	add_npc("pub_wyshangfan");
	
	add_door("大理城山林", "大理城山林", "大理城河边");
	add_door("大理城河上", "大理城河上", "大理城河边");

	set("long", "你来到河边，两侧山壁几乎是直上直下，西面是一条大河自北滚滚而来，在此折向东奔腾而去，河水汹涌，巨浪滔天，发出一阵阵骇人的轰响。此处河谷稍窄，前面有三根粗藤条绑在一棵大树上，另一端跨河而过，似可攀援而过。此去向南乃是崇山峻岭。" );
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
