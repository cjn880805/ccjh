//tingxiang.h

//Sample for room: ����������ˮ�
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_tingxiang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������ˮ�");
	
	add_npc("murong_youcao");        //add by zdn 2001-07-20

	add_door("�������Ŵ��", "�������Ŵ��", "����������ˮ�");

    set("long", "�����ӻ������а˾ż�é��������������ӳ���������£������Ľ�ݹ��ӵ��Ů�����ס���ˡ�" );
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