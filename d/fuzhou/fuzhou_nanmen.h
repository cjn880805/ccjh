//nanmen.h

//Sample for room: ��������
//coded by zouwenbin
//data: 2000-11-13

RESIDENT_BEGIN(CRfuzhou_nanmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	set("resident", "����");

	add_npc("pub_bing");   // add by zdn 2001-07-13

	add_door("������", "������", "��������");
	add_door("Ȫ��������", "Ȫ��������", "��������");

	set("long", "�����Ǹ������š�" );
    
};

RESIDENT_END;
