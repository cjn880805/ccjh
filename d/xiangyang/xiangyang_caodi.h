//caodi.h

//Sample for room: �����ݵ�
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_caodi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ݵ�");

	add_npc("pub_dinxiucai");

	add_door("��������", "��������", "�����ݵ�");
	add_door("��ң������", "��ң������", "�����ݵ�");
	add_door("�䵱����·2", "�䵱����·2", "�����ݵ�");

	set("long", "������������Ĳݵء��ɹű���������������İ���ȫ�����ˣ���Ȼ�ɹű�û�������ţ�����ɱ��Χ˿��������" );
	

/*****************************************************
        set("outdoors", "xiangyang");
	set("exits", ([
		"north"  : __DIR__"southgate2",
		"south"  : "/d/wudang/wdroad5",
	]));
********************************************/
};


ROOM_END;
