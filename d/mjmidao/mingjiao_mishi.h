//mingjiao_mishi.h



//Sample for room:  明教密室

//coded by cat
//data: 2001-3-20

//MINGJIAOMIDAO_BEGIN(CRmingjiao_mishi);

ROOM_BEGIN(CRMingJiao_mishi);


virtual void create()			//Call it when Room Create

{
	//set name of our room

	set_name( "明教密室");

	add_npc("mingjiao_yangdingtian");

};

ROOM_END;
