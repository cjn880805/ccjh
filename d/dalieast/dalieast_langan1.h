//langan1.h

//Sample for room: ����Ǹ���
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_langan1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǹ���");

	//add npcs into the room
//	add_npc("animal_shanyang");
        add_npc("dali_guigongzi");         //add by zdn 2001-07-20
	
	add_door("�����ũ��2", "�����ũ��2", "����Ǹ���");

	set("long", "��������������ľ�Ծ����ϣ����Ǹ�������������������̡��乹���������¥�����濪�ţ����ݿ����£��ϸ��糵��״���в�ס�ˣ��������²㣬һ��Ϊţ��Ȧ��" );
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
