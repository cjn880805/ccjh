//shilin1.h

//Sample for room: 大理城李子箐石林
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiNorth_shilin1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城李子箐石林");

	add_npc("pub_nongfu");
	add_npc("pub_cunfu");   // add by zdn 2001-07-13

	add_door("大理城长湖", "大理城长湖", "大理城李子箐石林");

	set("long", "相传优人于隆冬遥见石上有李二株，结实鲜红，晚不及收，次日寻之不复见，故称李子箐。面积约一千二百亩，包括大石林，小石林，和外石林，是路南石林最精华者之一。千峰比肩，大小高矮，较为接近，远观但见一片密密簇簇，似缺少变化跃动，近赏则大不相同，那神奇的大自然的精雕细琢，使得顽石无论壮鸟，壮兽，或拟人，拟物，均表情逼肖，疑真还假。");
	
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
