//caoyuan.h

//Sample for room: 草原
//coded by zwb
//data: 2000-11-21

//Note: these two headers must be include
//use macro XIYU_BEGIN(room_name) to declare room
//and use macro XIYU_END end declare
XIYU_BEGIN(CRXiYu_caoyuan);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "草原");
	
//	add_npc("kunlun_gaozecheng");        //add by zdn 2001-07-20

	add_door("血刀门土路1", "血刀门土路1", "西域草原");
	add_door("西域丝绸之路1", "西域丝绸之路1", "西域草原");

};


XIYU_END;
