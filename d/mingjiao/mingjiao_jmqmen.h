//jmqmen.h
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_jmqmen);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "��ľ�����");

	add_npc("mingjiao_wensong");

	add_door("��΢��", "������΢��", "��ľ�����");
	add_door("��΢��", "������΢��", "��ľ�����");

	set("long", "���������̾�ľ��Ĵ��ţ�ׯ�Ϲ��ӣ���ǰ�Բ��������������졣���̵Ĵ��ų����ţ��ƺ��������к����������������ȥ��ֻ��һƬ�Դ�����֡�");;
    

/*****************************************************
	set("exits", ([
		"down" : __DIR__"jmqshenmu",
	]));
        set("objects",([
                __DIR__"npc/wensong":1,
	]));
********************************************/

};



ROOM_END;
