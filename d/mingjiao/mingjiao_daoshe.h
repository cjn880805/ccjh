//daoshe.h

//Sample for room: 道家竹舍
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_daoshe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "明教道家竹舍");


	add_door("明教四门广场", "明教四门广场", "明教道家竹舍");
	add_npc("mingjiao_tuoba");

	set("long", "走进这间竹舍，一阵清香飘来，只见几为青衣僧人端坐于莆团之上，正低声咏念“金刚经”。室中香烟清绕，竹影流芳，一白眉老僧端坐正中，手持菩提念珠，念念有词。身后墙壁之上，高悬一条幅(tiao fu)，纸已发黄,但笔力遒劲，一见可知是件古物。");
    
    set("sleep_room", 1);
    set("no_fight", 1);

/*****************************************************
    set("exits", ([
        "south" : __DIR__"mjfengmen1",
    ]));
    set("item_desc",(["tiao fu" : (: look_fu :),]));
********************************************/
};


ROOM_END;
