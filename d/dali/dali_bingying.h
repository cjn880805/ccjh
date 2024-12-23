//bingying.h

//Sample for room: 兵营
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_bingying);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "兵营");

	//add npcs into the room
	add_npc("pub_guanbing1");
	add_npc("pub_guanbing1");
	add_npc("pub_guanbing1");
	add_npc("pub_weishi1");

	add_door("大理城西", "大理城西", "大理城兵营");
//	add_door("大理城马厩", "大理城马厩", "大理城兵营");

	set("long", "大理国虽小，却重视精兵良将。然屈人必先屈志，兵戈乃下下之策，段氏大理先与北邻宋朝修和，再以姻亲拉拢当地人，多年无战事。这是城里的铁骑营，为皇族的嫡系，装备给养无不优于中原地方。军士们严缜以待，盔甲鲜明，刀剑锋利。" );

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
