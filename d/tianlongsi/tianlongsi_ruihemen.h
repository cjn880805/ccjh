//ruihemen.h

//Sample for room:  �����������
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_ruihemen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����������");


				
	add_door("���������Ҹ�", "���������Ҹ�", "�����������");
	add_door("�������޳���", "�������޳���", "�����������");

	set("long","����ͨ�������º��µ��Ż������ͷ�������ϣ�ֻ��ͭ�ż����ѱ���̤�����������������֮ʢ�ˡ�̧ͷ���Ͽ����������ɽ�������졣");
    

/******************************************************************************
	set("outdoors","tianlongsi");
        set("exits", ([
		"south": __DIR__"wuchangge",
		"north": __DIR__"wuwoge",
	]));
******************************************************************************/
};


ROOM_END;
