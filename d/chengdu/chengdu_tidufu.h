//tidufu.h

//Sample for room: 提督府
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_tidufu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "提督府");

	//add npcs into the room
	add_npc("pub_wutianliang");/////////////////////////
	add_npc("pub_shicong");
	add_npc("pub_shicong");
	add_npc("pub_qinbing");
	add_npc("pub_qinbing");
	add_npc("pub_qinbing");
	add_npc("pub_qinbing");

	add_door("成都中", "成都中", "成都提督府");

	set("long",	"这里便是提督大人办公事的地方。正前方 (front)大红楠木案桌后正经端坐着的，就是成都提督吴天德。两边站立纹风不动的是他的亲兵侍从，看上去都十分彪悍。"	);

/*****************************************************
        set("exits", ([
            "south" : __DIR__"tidugate",
        ]));
        set("objects", ([ 
             __DIR__"npc/wutiande" : 1,
             __DIR__"npc/shicong"  : 2,
             __DIR__"npc/qinbing" : 4,
        ]));
        set("item_desc",([
            "front" : "
                ###########################
                #                         #
                #    民   安   境   靖    #
                #                         #
                ###########################
                            !~A~!
                      @~~~~~!(O)!~~~~~@
                           (.@ @.)
                            . ~ .
                         /   ~.你奶奶的...你这刁民...还瞧甚麽? 不认得老爷麽? ...
                        #           #
             HHHH     #               #
             HHHH   #    n         n    #
          |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
           ```````````````````````````````````````
                  ()                      ()
                 ()                        ()
                ()                          ()
               ()                            ()\n"
        ]));
//        
********************************************/

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}


ROOM_END;
