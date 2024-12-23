//road.h

//Sample for room: ����ٵ�
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_road);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ٵ�");

	set("resident", "������Զ");
	
	add_npc("pub_playboy");
	add_npc("pub_punk");    // add by zdn 2001-07-13  

	set("monster_chance", 50);

	add_door("����ɽ����", "����ɽ����", "����ٵ�");
	add_door("������Զ", "������Զ", "����ٵ�");

    set("long","������ͨ������Ĺٵ������׿�Ĵ����ȫ���ɻ����̳ɣ��ɲ�����������������ӵ���������ǽ����ؿڵıؾ�֮·��·��������Ⱥ�����˶�����������Ƥ����ҩ�ĵ������ˡ�ż�������Źٱ�����ɳ۶�����" );
	

/*****************************************************
	set("exits", ([
		"north"     : __DIR__"ningyuan",
		"southwest" : __DIR__"road2",
	]));
********************************************/
};


RESIDENT_END;
