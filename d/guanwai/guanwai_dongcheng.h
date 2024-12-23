//dongcheng.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_dongcheng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	set("resident", "������Զ");

	set("monster_chance", 50);

	add_npc("pub_yangzong");      // add by zdn 2001-07-13 
	add_npc("guanwai_xiaoyuanshan");       //add by zdn 2001-07-20

	add_door("������Զ", "������Զ", "������Զ����");
	add_door("�����·1", "�����·1", "������Զ����");
	add_door("����ѩ��1", "����ѩ��1", "������Զ����");

    set("long","�������û����̾͵Ľֵ������ϵ����˲��࣬�����������塣ż���м�������������ε������߹��������������壬����ľ������洫�����ӵĽ�������������һ�Ż����ݳɵ���������������Ц��������" );
	

/*****************************************************
	set("exits", ([
		"west"      : __DIR__"jishi",
		"south"     : __DIR__"tuyaoguan",
		"east"      : __DIR__"xuedi1",
		"northeast" : __DIR__"huandi1",
	]));
********************************************/
};


RESIDENT_END;
