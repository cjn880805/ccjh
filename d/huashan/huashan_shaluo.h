//shaluo.h

//Sample for room: ��ɽɯ��ƺ
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_shaluo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽɯ��ƺ");

	//add npcs into the room
	add_npc("pub_youke");

	add_door("��ɽ����", "��ɽ����", "��ɽɯ��ƺ");
	add_door("��ɽ����", "��ɽ����", "��ɽɯ��ƺ");
	add_door("��ɽɽ���ٲ�", "��ɽɽ���ٲ�", "��ɽɯ��ƺ");

	set("long", "������Ȫ��̤������ʯ������ɽ�����ζ��ϣ���������ɯ��ƺ��������ɽ·��ʼ���ͣ�����һ���ػ�������ɽ����������ʮ���̡���ͨ��ɽ�ϡ�");  
    
 
/*****************************************************
        set("exits", ([  
            "northwest" : __DIR__"path1",
            "northeast" : __DIR__"shanhongpb",
            "southup" : __DIR__"yunmen",
        ]));
        set("objects", ([
            __DIR__"npc/haoke": 2,
        ]));
********************************************/
};


ROOM_END;
