//shishi.h

//Sample for room: 侠客岛石室
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_shishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛石室");
	
	add_npc("wudang_zhangsan");        //add by zdn 2001-07-20



	add_door("侠客岛迎宾馆", "侠客岛迎宾馆", "侠客岛石室");
	add_door("侠客岛武器库", "侠客岛武器库", "侠客岛石室");
	add_door("侠客岛书房", "侠客岛书房", "侠客岛石室");

    set("long", "这是一个石洞，此洞硕大无朋，四周点满了火把，把整个大厅照耀得十分明亮，中间放着很多石桌和石凳，有很多的江湖人物在石室在参悟武功之余，在这里休息一会。" );

/*****************************************************
         set("exits", ([
                "west" : __DIR__"dating"
        ]));
        set("objects", ([
                books[random(sizeof(books))] : 1,
        ]));
********************************************/
};


ROOM_END;
