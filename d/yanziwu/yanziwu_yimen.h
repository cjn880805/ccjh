//yimen.h

//Sample for room: ����������
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_yimen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");
	add_npc("murong_bo");        //add by zdn 2001-07-20
	

	add_door("������������", "������������", "����������");
	add_door("������κϾ�", "������κϾ�", "����������");
	add_door("�������߷���", "�������߷���", "����������");
	add_door("�������Ŵ��", "�������Ŵ��", "����������");

    set("long", "һ������ĵ񻨴��ţ�һ����Ŀ�����ӹ������ϣ����Ժ�ɫС׭д�� '����' ���֣�����һ��ׯ������ĸо����������������������Ϣ�ĵط�����������Ľ�ݼ����÷����Ŵ����" );
    
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp