//xiuxishi.h

//Sample for room: 华山小筑
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_xiuxishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山小筑");


	add_door("华山小山路", "华山小山路", "华山小筑");

	set("long", "这是间整洁的厢房，因门窗常闭着，光线很昏暗。房里别无他物，只有中间放着一张收拾得舒舒服服的大床，看着就让人想睡觉。");  
    set("sleep_room", 1);
    
    set("no_fight", 1);

/*****************************************************

********************************************/
};


ROOM_END;
