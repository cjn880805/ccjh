//bingqifang.h

//Sample for room: 兵器房
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_bingqifang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "兵器房");

	CBox * box = Add_Box();
	box->add_object("changjian", 4);	
	box->set_name( "木柜");	

	add_door("华山练武场", "华山练武场", "华山兵器房");

	set("long", "这里是华山派的兵器房，四周放这几个兵器架，上面是华山派各弟子平时练剑用的竹剑。");  
    set("no_fight", 1);

/*****************************************************
        set("exits", ([
                "west" : __DIR__"square",
        ]));
        set("objects", ([ 
            "/clone/weapon/zhujian" : 4
        ]));
//      
********************************************/
};


ROOM_END;
