//nushe.h

//Sample for room: 地门女舍
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_nushe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "明教地门女舍");


	add_door("明教四门广场", "明教四门广场", "明教地门女舍");
	add_npc("mingjiao_dimen");

	set("long", "走进这间女舍，一阵脂粉淡香扑面，似有似无，似茉莉，似丁香，似玫瑰，似夜来香，让人心神荡漾。几位姑娘斜倚阑窗，吟诗作画，全不似武林中人，谁能想到，她们都是叱咤江湖的巾帼女杰呢？");
    
    set("sleep_room", 1);
    set("no_fight", 1);

/*****************************************************
    set("exits", ([
        "out" : __DIR__"mjdimen1",
    ]));
    set("item_desc",(["dui lian" : (: look_dui :),]));
********************************************/
};


ROOM_END;
