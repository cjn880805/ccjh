//taohua5.h

//Sample for room: �һ�ƺ
//coded by zwb
//data: 2000-12-1

RESIDENT_BEGIN(CRYangZhou_taohua5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�һ�ƺ");

	set("resident", "�һ���");
	
	add_npc("pub_flowerg");         //add by zdn 2001-07-16
	add_npc("guiyun_hanbaoju"); 
	add_npc("guiyun_nanxiren");             //zdd by zdn 2001-07-20


	add_door("�����һ���", "�����һ���", "�����һ�ƺ");

	set("long", "�һ�ƺ�Ǹ�С��ء��˴����滷ɽ��ɽ��������ƣ�ɽ�����ֲ�����������ϡ�����СϪ�����������峺��͸��������������ӻԾ�����������������ǧ��ƺ�д��СС���߱�����ɽҰ֮������ζ��" );
	

/*****************************************************
	set("exits", ([
		"south"     : __DIR__"taohua4",
	]));
********************************************/
};


RESIDENT_END;
