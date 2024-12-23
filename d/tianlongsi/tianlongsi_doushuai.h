//doushuai.h

//Sample for room:  �����¶��ʴ�ʿԺ
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_doushuai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����¶��ʴ�ʿԺ");

	CBox * box = Add_Box();
	box->add_object("baixiang", 1);	
	box->set_name( "����");	
				
	add_door("�����¶�ĸ��", "�����¶�ĸ��", "�����¶��ʴ�ʿԺ");
	add_door("���������޹�", "���������޹�", "�����¶��ʴ�ʿԺ");
	add_door("���������ĸ�", "���������ĸ�", "�����¶��ʴ�ʿԺ");
	add_door("�����°���̨", "�����°���̨", "�����¶��ʴ�ʿԺ");

	set("long","����һ��ΰ������ܵ�����Զ�ĵط��������Ͼ���������������ɮ����֮������Ĳ���á����ǳ��˲������״���ĵط�������ò�Ҫ���Դ��롣������ȷ���ܸ���ɮ�Ǵ�ȥ����Ϣ��");
    
	set("sleep_room", 1);
    set("no_fight",1);
    set("no_steal",1);

/******************************************************************************
        set("exits", ([
                "north" : __DIR__"qingxinge",
		"south" : __DIR__"banruotai",
		"northeast" : __DIR__"doumugong",
		"northwest" : __DIR__"sanwugong",
	]));
	set("objects",([
                __DIR__"obj/xianglu" : 1,
        ]));
******************************************************************************/
};


ROOM_END;
