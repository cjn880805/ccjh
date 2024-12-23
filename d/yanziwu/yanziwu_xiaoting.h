//xiaoting.h

//Sample for room: ������������
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_xiaoting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������������");
	
	add_npc("murong_wang"); 
	add_npc("murong_wyy");          //add by zdn 2001-07-20

	add_door("�������ϼ��", "�������ϼ��", "������������");
	add_door("���������", "���������", "������������");
	add_door("������С��", "������С��", "������������");

    set("long", "����һ��С��,���䲻��,���õ�Ҳ���¡������ķ��㣬������Ƣ��ֻ��ǽ�Ϲ��ż�������,������Ϊ����,���ڲ�ס��������֮�����������ܾ��ɵذ���Щ����(table)������(chair)�� " );
    
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