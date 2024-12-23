//zhulin.h

//Sample for room: ����������
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_zhulin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");
	
	add_npc("murong_deng");        //add by zdn 2001-07-20

	add_door("�������ϼ��", "�������ϼ��", "����������");
	add_door("��������ڣ", "��������ڣ", "����������");

    set("long", "��βɭɭ������ϸϸ���͸������ݺύ���ڱ����ա������˼�������΢��������֣�����ɳɳ֮���������в����㷲�������������һ����ʯ���̳ɵ���С����ǰ���졣" );
    
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