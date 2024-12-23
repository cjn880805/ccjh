//caotang.h

//Sample for room: 杜甫草堂
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_caotang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杜甫草堂");

	//add npcs into the room
	add_npc("pub_chaboshi");
	add_npc("pub_duzongqi");
	
	add_door("成都溪岸小路", "成都溪岸小路", "成都杜甫草堂");

	set("long",	"这里是杜甫流寓成都的故居。草堂里流水回萦，小桥勾连，竹树	掩映，显得既庄严肃穆，古朴典雅，又不失幽深静谧，秀丽清朗。");

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
