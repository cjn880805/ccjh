//yuntai.h

//Sample for room: ��ɽ��̨��
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_yuntai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ��̨��");
	
	add_npc("huashan_liangfa");     //add by zdn 2001-07-20


	add_door("��ɽ������", "��ɽ������", "��ɽ��̨��");

	set("long", "̫������������̨�壬����������������һ����᫵ĳ��룬������һ����׵���ƵĵǷ����ݡ���¯������ŷ幰�����ң����أͻ����̨���涼�����¾��ڣ�ʮ���վ����嶥�������乬������ͨ��������ʯ��¥���������⡰���嶥�����֡�");  
    
 
/*****************************************************
        set("exits", ([  
            "southdown" : __DIR__"canglong",
        ]));
********************************************/
};


ROOM_END;
