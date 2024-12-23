//wdroad2.h

//Sample for room: 武当黄土路2
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_wdroad2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当黄土路2");
	
//	add_npc("tiezhang_qqren");        //add by zdn 2001-07-20

	add_door("襄阳草地", "襄阳草地", "武当黄土路2");
	add_door("武当黄土路3", "武当黄土路3", "武当黄土路2");
	add_door("佛山南岭山口", "佛山南岭山口", "武当黄土路2");

    
 
/*****************************************************

*****************************************************/
};


ROOM_END;
