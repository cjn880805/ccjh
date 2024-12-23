//xiuxishi.h

//Sample for room: 桃花轩
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_xiuxishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "桃花轩");
	
	add_npc("pub_puren");         //add by zdn 2001-07-16
        add_npc("taohua_shagu");        //add by zdn 2001-07-20


	add_door("桃花岛思过室", "桃花岛思过室", "桃花岛桃花轩");

	set("long", "这是间整洁的厢房，因门窗常闭着，光线很昏暗。房里别无他物，只有中间放着一张收拾得舒舒服服的大床，看着就让人想睡觉。");
    set("sleep_room", 1);
    set("no_fight", 1);
    

/*****************************************************
********************************************/
};


ROOM_END;
