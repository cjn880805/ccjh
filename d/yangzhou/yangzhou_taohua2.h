//taohua2.h

//Sample for room: �һ�Ϫ
//coded by zwb
//data: 2000-12-1

RESIDENT_BEGIN(CRYangZhou_taohua2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�һ�Ϫ");

	set("resident", "�һ���");
	
	add_npc("pub_playboy");          //add by zdn 2001-07-16
	add_npc("guiyun_kezhene");             //zdd by zdn 2001-07-20


	add_door("�����һ���", "�����һ���", "�����һ�Ϫ");
	add_door("�����һ���", "�����һ���", "�����һ�Ϫ");

	set("long", "���һ������һ�Ϫ���һ�Ϫˮ����ϴ�����Ӹ��ƿ����գ���¸�Ů����ϡ������������һ�Ϫ������С�����һ����л���ʱ���һ���ʱ��ƬƬ�ɺ��׹Ϫ�У���ˮ��ȥ��������ϧ��������Ϫ�ϣ�����˼�ˣ��������ޡ� " );
	

/*****************************************************
	set("exits", ([
		"westup" : __DIR__"taohua3",
		"south"  : __DIR__"taohua1",
	]));
********************************************/
};


RESIDENT_END;
