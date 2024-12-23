//daduhe.h

//Sample for room: 大理城大渡河边
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_daduhe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城大渡河边");

	set("resident", "乌弄城");
	
	add_npc("dali_shennongdizi");        //add by zdn 2001-07-20


	add_door("大理城乌弄城", "大理城乌弄城", "大理城大渡河边");

	set("long", "大渡河是蜀中名川，河谷狭窄，水流湍急，极难渡过，只有远方下游才有河面宽阔处，可行船渡河。此处是河谷转弯的浅滩，水流稍缓，不过仍可见滔滔河水汹涌而去，对岸可望而不可及。南边山上有座石城。");
	
};


RESIDENT_END;
