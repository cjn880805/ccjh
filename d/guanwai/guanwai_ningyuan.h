//ningyuan.h
//Sample for room: 关外宁远
//coded by zouwenbin
//data: 2000-11-17


RESIDENT_BEGIN(CRGuanWai_ningyuan);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "关外宁远");

	set("capacity", 5);
	set("price", 50);
	set("resident", "关外宁远");

	CBox * box = Add_Box();
	box->add_object("blade_book", 2);	
	box->set_name( "铁柜");	

	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_yinling");
	if (random(2)==0)
	{
	add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}

//	add_door("关外宁远马厩", "关外宁远马厩", "关外宁远");
	add_door("关外宁远土窑馆", "关外宁远土窑馆", "关外宁远");

	add_door("关外宁远香肉馆", "关外宁远香肉馆", "关外宁远");

	add_door("关外宁远小土屋", "关外宁远小土屋", "关外宁远");

	add_door("关外荒路1", "关外荒路1", "关外宁远");
	add_door("关外雪地1", "关外雪地1", "关外宁远");

	add_door("关外官道", "关外官道", "关外宁远");


};

RESIDENT_END;
