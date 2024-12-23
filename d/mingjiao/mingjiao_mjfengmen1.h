//mjfengmen.h

//Sample for room: 风门
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_mjfengmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "风门");


	add_door("明教青石阶4", "明教青石阶4", "明教风门");
	add_door("道家竹舍", "明教道家竹舍", "明教风门");
	add_door("佛家竹舍", "明教佛家竹舍", "明教风门");

	set("long", "这是竹林中的一间小院，竹影依依，经声入耳，其南北各有一间竹舍，乃是明教中释道和佛家弟子的修炼场所。" );
	

/*****************************************************
    set("exits", ([
        "northwest" : __DIR__"mjfengmen",
	"north" : __DIR__"foshe",
	"south" : __DIR__"daoshe",
    ]));
********************************************/
};


ROOM_END;
