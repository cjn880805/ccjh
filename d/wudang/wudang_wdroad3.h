//wdroad3.h

//Sample for room: 武当黄土路3
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_wdroad3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当黄土路3");
	
//	add_npc("tiezhang_huiyi");             //zdd by zdn 2001-07-20


	add_door("武当松林", "武当松林", "武当黄土路3");
	add_door("武当黄土路2", "武当黄土路2", "武当黄土路3");

	set("long","你走在一条尘土飞扬的黄土路上，旁是阴森森的树林。这里是湖北境界，据说经常有土匪出没，不可久留。南边一条小道，通向密林深处。"); 
    
 
/*****************************************************

*****************************************************/
};


ROOM_END;
