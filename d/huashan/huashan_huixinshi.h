//huixinshi.h

//Sample for room: ��ɽ����ʯ
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_huixinshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ����ʯ");
	
	add_npc("huashan_teller");        //add by zdn 2001-07-20


	add_door("��ɽ���ƺ", "��ɽ���ƺ", "��ɽ����ʯ");
	add_door("��ɽǧ�ߴ�", "��ɽǧ�ߴ�", "��ɽ����ʯ");

	set("long", "�����ƺ��ʯ����ɽ��ɽ·���˶�����ǰ��ɽ���ն�ʯ�¼����խխ��ʯ������������������������б�������˲�������������ǰ�С������´�ʯ��·����ʯ��˽�������ʯ������ȥɽ�����գ��ο����ˣ��͸û�ͷ�ˡ�");  
    
 
/*****************************************************
        set("exits", ([  
            "westdown" : __DIR__"qingke",
            "eastup"   : __DIR__"qianchi",
        ]));
********************************************/
};


ROOM_END;
