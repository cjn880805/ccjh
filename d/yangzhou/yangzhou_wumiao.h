//wumiao.h

//Sample for room: ����
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRYangZhou_wumiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");


				
	CBox * box = Add_Box();
	box->add_object("coin", 100);	//put 100 coind into box
	box->set_name( "����");	
	
	add_door("��������", "��������", "��������");

	set("long", "�����������������������������Ϸ������������顰���Һ�ɽ���ĺ��ҡ����������Ƕ�š����ұ������ĸ����֡����˵��ˣ��������������Ϲ��Ͼ���������ݡ��Ա��ƺ���һ�����š�(paizi)����̨���������ϰ壬һ˫�������������´������㡣�ݽַ���˵���浱�̸��ļۻ�����������ҴӲ��ʻ������������˻���ʲô���գ���������ܲ���" );
	set("no_fight", "1");
	set("no_steal", "1");
	set("sleep_room", "1");
    set("valid_startroom","1");
/*****************************************************
	set("objects", ([
		__DIR__"obj/box" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"beidajie2",
		"up"   : __DIR__"wumiao2",
		"northwest": "/d/wizard/guest_room",
	]));
        create_door("northwest", "����", "southeast", DOOR_CLOSED);
********************************************/
};


ROOM_END;
