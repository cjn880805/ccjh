//qingke.h

//Sample for room: ��ɽ���ƺ
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_qingke);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ���ƺ");
	add_npc("pub_tumengping");

	add_door("��ɽ����", "��ɽ����", "��ɽ���ƺ");
	add_door("��ɽ����ʯ", "��ɽ����ʯ", "��ɽ���ƺ");

	set("long", "�߹���᫵�ʮ���̣��������ţ��͵������ƺ�����ƺ��һɽ����أ�������Ϊƽ̹�������￪ʼ����ɽ��·������ԭ�������ʯ�ס�ԶԶ����һ��ССʯͤ�����Ƕ���ͤ�ˡ��ഫ��̫���뻪�������������ڴˣ�����ɽ��Ϊ��ע����̫�����ˣ��Ӵ˻�ɽ�ϵ����ؾͲ������Ǯ����");  
    
 
/*****************************************************
        set("exits", ([  
            "northdown" : __DIR__"yunmen",
            "eastup"    : __DIR__"huixinshi",
        ]));
********************************************/
};


ROOM_END;
