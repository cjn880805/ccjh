//tidufu.h

//Sample for room: �ᶽ��
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_tidufu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ᶽ��");

	//add npcs into the room
	add_npc("pub_wutianliang");/////////////////////////
	add_npc("pub_shicong");
	add_npc("pub_shicong");
	add_npc("pub_qinbing");
	add_npc("pub_qinbing");
	add_npc("pub_qinbing");
	add_npc("pub_qinbing");

	add_door("�ɶ���", "�ɶ���", "�ɶ��ᶽ��");

	set("long",	"��������ᶽ���˰칫�µĵط�����ǰ�� (front)����ľ���������������ŵģ����ǳɶ��ᶽ����¡�����վ���Ʒ粻�����������ױ��̴ӣ�����ȥ��ʮ�ֱ뺷��"	);

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
                #    ��   ��   ��   ��    #
                #                         #
                ###########################
                            !~A~!
                      @~~~~~!(O)!~~~~~@
                           (.@ @.)
                            . ~ .
                         /   ~.�����̵�...�������...��������? ���ϵ���ү��? ...
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
