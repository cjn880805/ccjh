//neiyuan.h

//Sample for room:  ÷ׯ��Ժ
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_neiyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "÷ׯ��Ժ");
	
	add_npc("pub_shiwei");            // add by zdn 2001-07-14
	add_npc("pub_wuxing");
	add_item("meishu");

	add_door("÷ׯ��ľ԰", "÷ׯ��ľ԰", "÷ׯ��Ժ");
	add_door("÷ׯ����1", "÷ׯ����1", "÷ׯ��Ժ");
	
	set("long", "������÷ׯ����Ժ���������߹�ȥ�Ϳ����ҵ���λׯ���������ƺ��ǳ�����������������Ҷ���ص������������ƺ��ǳ����֣����������������ӵ����������������ֿ��Խ�������Ҵ��ң����治֪������ô��������ط�����һλ׳��ĺ��ӣ�������������Ժ�ſڡ�   " );
    

/******************************************************************************
        set("outdoors", "meizhuang");
        set("exits", ([  
            "south" : __DIR__"senlin1",
            "north" : __DIR__"zoulang1",
        ]));
        set("objects", ([  
            __DIR__"npc/huyuan.c" : 1,
        ]));
******************************************************************************/
};


ROOM_END;




