//luoyan.h

//Sample for room: 华山落雁峰
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_luoyan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山落雁峰");

	add_npc("huashan_feng");	

	add_door("华山长空栈道", "华山长空栈道", "华山落雁峰");

	set("long", "南峰又名落雁峰，是华山最高峰。峰头题刻极多，如“太华峰头”、“竣极于天”、“袖拂天星”等，极言华岳之高。环顾四周，皆在足下。寇准诗赞曰：只有天在上，更无山与齐；举头红日近，回首白云低。传说五代时候的隐士陈抟就隐居在这里。宋太祖曾经下诏征他出山作官，他便在这里写下谢诏表说：“一片野心都被白云锁住，九重宠诏休教丹凤衔来”，表示不愿出山做官。");  
 
/*****************************************************
        set("objects", ([
//            CLASS_D("huashan") + "/feng-qingyang":1,
            CLASS_D("huashan") + "/feng" : 1,
        ]));
        set("exits", ([ 
           "northdown" : __DIR__"zhandao",
        ]));
********************************************/
};


ROOM_END;
