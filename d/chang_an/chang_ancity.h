//chang_ancity.h

//Sample for room:  长安
//coded by Fisho
//data: 2000-11-3

RESIDENT_BEGIN(CRchang_ancity);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "长安");

	set("resident", "长安");
	set("capacity", 10);

	add_npc("pub_playboy");
	add_npc("pub_renzhennv");
	add_npc("pub_chezhongnv");
	add_npc("helpnpc014");		//add by qzj 2001-08-13

	add_door("长安大官道4", "长安大官道4", "长安");
	add_door("西域嘉峪关", "西域嘉峪关", "长安");

	add_door("长安乐坊", "长安乐坊", "长安");
	add_door("长安相记钱庄", "长安相记钱庄", "长安");

};


RESIDENT_END;
