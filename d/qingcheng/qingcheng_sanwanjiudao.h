//sanwanjiudao.h

//Sample for room: 青城三弯九倒
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_sanwanjiudao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "三弯九倒");
	
	add_npc("pub_bing");          //add by zdn 2001-07-14


	add_door("青城上清宫", "青城上清宫", "青城三弯九倒");
	add_door("青城朝阳洞", "青城朝阳洞", "青城三弯九倒");


    

/*****************************************************

*****************************************************/
};


ROOM_END;
