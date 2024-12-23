//tianran.h

//Sample for room: 青城天然图画
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_tianran);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "青城天然图画");
	
	add_npc("qingcheng_hai");    //add by zdn 2001-07-20


	add_door("青城山路2", "青城山路2", "青城天然图画");
	add_door("青城驻鹤庄", "青城驻鹤庄", "青城天然图画");
	add_door("青城盘山磴道", "青城盘山磴道", "青城天然图画");


    

/*****************************************************
	set("exits", ([
		"eastdown" : __DIR__"path1",
		"westup"   : __DIR__"path2",
		"north"    : __DIR__"zhuhezhuang",
	]));
*****************************************************/
};


ROOM_END;
