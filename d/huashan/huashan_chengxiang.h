//chengxiang.h

//Sample for room: ��ɽ������ɽ��
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_chengxiang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ������ɽ��");
	
	add_npc("pub_girldizi");         //add by zdn 2001-07-17
	add_npc("pub_baixin");

	add_door("��ɽ������С·", "��ɽ������С·", "��ɽ������ɽ��");
	add_door("��ɽ������", "��ɽ������", "��ɽ������ɽ��");

	set("long", "��˵��ɽ��ʥĸ������һ�������������������Ϊ�򸾣����ֶ����񷴶����ǽ�ϣ�����ѹ�ڻ�ɽ�£����Ķ��ӳ��㳤����ø���������ɽ���ȳ���ĸ�ס��Ա���һ���м��ѿ��Ĵ�ʯ�����ø���������һ�㣬��������ʯ����˵���ǳ�����ɽ��ĸ�ĵط���");  
    
 
/*****************************************************
        set("exits", ([  
            "westup"   : __DIR__"lianhua",
            "eastdown" : __DIR__"lianpath2",
        ]));
********************************************/
};


ROOM_END;
