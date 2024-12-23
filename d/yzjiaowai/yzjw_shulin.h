//yzjw_shulin.h



//Sample for room:  扬州树林
//coded by zwb
//data: 2000-11-20

ROOM_BEGIN(CRYZJW_shulin);

virtual void create()			//Call it when Room Create

{

	set_name( "扬州树林");

	add_npc("gaibang_kuai_huosan");
	add_npc("gaibang_qiu_wanjia");
	add_npc("gaibang_mo_bu");

	add_door("扬州田地","扬州田地","扬州树林");
	add_door("扬州山路2","扬州山路2","扬州树林");
	add_door("扬州山路1","扬州山路1","扬州树林");
	add_door("扬州密林5","扬州密林5","扬州树林");

};





ROOM_END;
